#include "PmergeMe.hpp"
#include <algorithm>

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& src) { *this = src; }
PmergeMe::~PmergeMe() {}
PmergeMe& PmergeMe::operator=(const PmergeMe& src)
{
    (void)src;
    return *this;
}

/* ================= Comparator functors (OCF) ================= */

VectorIndexLess::VectorIndexLess() : _values(0) {}
VectorIndexLess::VectorIndexLess(const std::vector<int>& v) : _values(&v) {}
VectorIndexLess::VectorIndexLess(const VectorIndexLess& src) : _values(src._values) {}
VectorIndexLess& VectorIndexLess::operator=(const VectorIndexLess& src)
{
    if (this != &src)
        _values = src._values;
    return *this;
}
VectorIndexLess::~VectorIndexLess() {}

bool VectorIndexLess::operator()(size_t a, size_t b) const
{
    return ((*_values)[a] < (*_values)[b]);
}

DequeIndexLess::DequeIndexLess() : _values(0) {}
DequeIndexLess::DequeIndexLess(const std::deque<int>& v) : _values(&v) {}
DequeIndexLess::DequeIndexLess(const DequeIndexLess& src) : _values(src._values) {}
DequeIndexLess& DequeIndexLess::operator=(const DequeIndexLess& src)
{
    if (this != &src)
        _values = src._values;
    return *this;
}
DequeIndexLess::~DequeIndexLess() {}

bool DequeIndexLess::operator()(size_t a, size_t b) const
{
    return ((*_values)[a] < (*_values)[b]);
}

/* ================= Jacobsthal ================= */

// J(0)=0, J(1)=1, J(n) = J(n-1) + 2*J(n-2)  ->  0, 1, 1, 3, 5, 11, 21, 43 ...
//
// The pending elements are inserted in this order because it is the ordering
// that keeps every binary-search range at exactly 2^k - 1 elements, the size
// at which binary search wastes no comparison. Inserting 1,2,3,4... instead
// would leave ranges of size 4 or 8, each costing a full extra comparison.
size_t PmergeMe::jacobsthal(size_t n)
{
    if (n == 0)
        return (0);
    if (n == 1)
        return (1);

    size_t prev = 0;
    size_t cur = 1;
    for (size_t i = 2; i <= n; ++i)
    {
        size_t next = cur + 2 * prev;
        prev = cur;
        cur = next;
    }
    return (cur);
}

/* ================= VECTOR ================= */

void PmergeMe::fordJohnsonVector(std::vector<size_t>& idx, const std::vector<int>& val)
{
    if (idx.size() <= 1)
        return ;

    VectorIndexLess less(val);

    // --- step 0: set the odd element aside --------------------------------
    bool   hasStraggler = (idx.size() % 2 == 1);
    size_t straggler = 0;
    if (hasStraggler)
    {
        straggler = idx.back();
        idx.pop_back();
    }

    // --- step 1: pair up, one comparison per pair -------------------------
    // winners hold the larger of each pair, losers the smaller.
    std::vector<size_t> winners;
    std::vector<size_t> losers;
    winners.reserve(idx.size() / 2);
    losers.reserve(idx.size() / 2);

    for (size_t i = 0; i + 1 < idx.size(); i += 2)
    {
        if (less(idx[i + 1], idx[i]))       // val[idx[i+1]] < val[idx[i]]
        {
            winners.push_back(idx[i]);
            losers.push_back(idx[i + 1]);
        }
        else
        {
            winners.push_back(idx[i + 1]);
            losers.push_back(idx[i]);
        }
    }

    // The partner link, recorded BEFORE the recursion shuffles the winners.
    // Keyed by index, so it survives any reordering and duplicate values
    // can never claim the same partner twice.
    std::vector<size_t> partnerOf(val.size(), 0);
    for (size_t i = 0; i < winners.size(); ++i)
        partnerOf[winners[i]] = losers[i];

    // --- step 2: recursively sort the winners -----------------------------
    fordJohnsonVector(winners, val);

    // --- step 2b: read each winner's partner back, in the new order -------
    std::vector<size_t> pend;
    pend.reserve(winners.size());
    for (size_t i = 0; i < winners.size(); ++i)
        pend.push_back(partnerOf[winners[i]]);

    // --- step 3: seed the chain with pend[0], for free --------------------
    // pend[0] partners the smallest winner, so it is smaller than the whole
    // chain. No comparison needed.
    std::vector<size_t> chain;
    chain.reserve(idx.size() + 1);
    chain.push_back(pend[0]);
    chain.insert(chain.end(), winners.begin(), winners.end());

    // Where each winner sits in the chain. Locating it with a search would
    // burn O(log n) comparisons per insertion, and comparisons are exactly
    // what this algorithm minimises -- so it is tracked instead.
    // isWinner lets the positions be rebuilt in one pass per Jacobsthal block.
    std::vector<bool> isWinner(val.size(), false);
    for (size_t i = 0; i < winners.size(); ++i)
        isWinner[winners[i]] = true;
    std::vector<size_t> winnerPos(winners.size(), 0);

    // --- step 4: insert the rest in Jacobsthal order ----------------------
    size_t inserted = 1;                // pend[0] is already in
    size_t k = 3;                       // J(2) == 1 is already consumed
    size_t prevJacob = 1;

    while (inserted < pend.size())
    {
        size_t curJacob = jacobsthal(k);
        if (curJacob > pend.size())
            curJacob = pend.size();

        // One O(n) pass per block refreshes every winner position exactly.
        // The chain is sorted and the winners keep their relative order, so
        // walking it left to right hands them back in rank order.
        size_t seen = 0;
        for (size_t c = 0; c < chain.size(); ++c)
        {
            if (isWinner[chain[c]])
                winnerPos[seen++] = c;
        }
        size_t insertedInBlock = 0;

        // descending inside each Jacobsthal block: b3 before b2, b5 before b4
        for (size_t i = curJacob; i > prevJacob; --i)
        {
            size_t p = i - 1;           // pend is 0-based, the b-numbering is 1-based

            // pend[p] is known to be smaller than its partner winners[p], which
            // is already in the chain, so search only the part BELOW it.
            // That is the comparison Ford-Johnson gets for free.
            // Each insertion in this block can push the winner right by at
            // most one, so this is a guaranteed upper bound on its position.
            // Too-large would only cost comparisons; too-small would be wrong.
            size_t limitPos = winnerPos[p] + insertedInBlock;
            std::vector<size_t>::iterator limit = chain.begin() + limitPos;
            std::vector<size_t>::iterator pos =
                std::lower_bound(chain.begin(), limit, pend[p], less);

            chain.insert(pos, pend[p]);
            ++inserted;
            ++insertedInBlock;
        }
        prevJacob = curJacob;
        ++k;
    }

    // --- step 5: the straggler has no partner, so search the whole chain ---
    if (hasStraggler)
    {
        std::vector<size_t>::iterator pos =
            std::lower_bound(chain.begin(), chain.end(), straggler, less);
        chain.insert(pos, straggler);
    }

    idx.swap(chain);
}

void PmergeMe::sortVector(std::vector<int>& v)
{
    if (v.size() <= 1)
        return ;

    std::vector<size_t> idx;
    idx.reserve(v.size());
    for (size_t i = 0; i < v.size(); ++i)
        idx.push_back(i);

    fordJohnsonVector(idx, v);

    std::vector<int> sorted;
    sorted.reserve(v.size());
    for (size_t i = 0; i < idx.size(); ++i)
        sorted.push_back(v[idx[i]]);

    v.swap(sorted);
}

/* ================= DEQUE ================= */

void PmergeMe::fordJohnsonDeque(std::deque<size_t>& idx, const std::deque<int>& val)
{
    if (idx.size() <= 1)
        return ;

    DequeIndexLess less(val);

    bool   hasStraggler = (idx.size() % 2 == 1);
    size_t straggler = 0;
    if (hasStraggler)
    {
        straggler = idx.back();
        idx.pop_back();
    }

    std::deque<size_t> winners;
    std::deque<size_t> losers;

    for (size_t i = 0; i + 1 < idx.size(); i += 2)
    {
        if (less(idx[i + 1], idx[i]))
        {
            winners.push_back(idx[i]);
            losers.push_back(idx[i + 1]);
        }
        else
        {
            winners.push_back(idx[i + 1]);
            losers.push_back(idx[i]);
        }
    }

    std::deque<size_t> partnerOf(val.size(), 0);
    for (size_t i = 0; i < winners.size(); ++i)
        partnerOf[winners[i]] = losers[i];

    fordJohnsonDeque(winners, val);

    std::deque<size_t> pend;
    for (size_t i = 0; i < winners.size(); ++i)
        pend.push_back(partnerOf[winners[i]]);

    std::deque<size_t> chain;
    chain.push_back(pend[0]);
    chain.insert(chain.end(), winners.begin(), winners.end());

    // Where each winner sits in the chain. Locating it with a search would
    // burn O(log n) comparisons per insertion, and comparisons are exactly
    // what this algorithm minimises -- so it is tracked instead.
    // isWinner lets the positions be rebuilt in one pass per Jacobsthal block.
    std::deque<bool> isWinner(val.size(), false);
    for (size_t i = 0; i < winners.size(); ++i)
        isWinner[winners[i]] = true;
    std::deque<size_t> winnerPos(winners.size(), 0);

    size_t inserted = 1;
    size_t k = 3;
    size_t prevJacob = 1;

    while (inserted < pend.size())
    {
        size_t curJacob = jacobsthal(k);
        if (curJacob > pend.size())
            curJacob = pend.size();

        // One O(n) pass per block refreshes every winner position exactly.
        // The chain is sorted and the winners keep their relative order, so
        // walking it left to right hands them back in rank order.
        size_t seen = 0;
        for (size_t c = 0; c < chain.size(); ++c)
        {
            if (isWinner[chain[c]])
                winnerPos[seen++] = c;
        }
        size_t insertedInBlock = 0;

        for (size_t i = curJacob; i > prevJacob; --i)
        {
            size_t p = i - 1;

            // Each insertion in this block can push the winner right by at
            // most one, so this is a guaranteed upper bound on its position.
            // Too-large would only cost comparisons; too-small would be wrong.
            size_t limitPos = winnerPos[p] + insertedInBlock;
            std::deque<size_t>::iterator limit = chain.begin() + limitPos;
            std::deque<size_t>::iterator pos =
                std::lower_bound(chain.begin(), limit, pend[p], less);

            chain.insert(pos, pend[p]);
            ++inserted;
            ++insertedInBlock;
        }
        prevJacob = curJacob;
        ++k;
    }

    if (hasStraggler)
    {
        std::deque<size_t>::iterator pos =
            std::lower_bound(chain.begin(), chain.end(), straggler, less);
        chain.insert(pos, straggler);
    }

    idx.swap(chain);
}

void PmergeMe::sortDeque(std::deque<int>& d)
{
    if (d.size() <= 1)
        return ;

    std::deque<size_t> idx;
    for (size_t i = 0; i < d.size(); ++i)
        idx.push_back(i);

    fordJohnsonDeque(idx, d);

    std::deque<int> sorted;
    for (size_t i = 0; i < idx.size(); ++i)
        sorted.push_back(d[idx[i]]);

    d.swap(sorted);
}
