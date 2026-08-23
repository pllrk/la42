#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <cstddef>

class PmergeMe
{
public:
    PmergeMe();
    PmergeMe(const PmergeMe& src);
    ~PmergeMe();
    PmergeMe& operator=(const PmergeMe& src);

    void sortVector(std::vector<int>& v);
    void sortDeque(std::deque<int>& d);

private:
    // Ford-Johnson, written once per container: the subject explicitly
    // discourages a single generic function.
    //
    // Both work on INDICES into the original values rather than on the values
    // themselves. An index is unique, so each loser stays attached to its
    // winner through the recursive sort even when two values are equal.
    void fordJohnsonVector(std::vector<size_t>& idx, const std::vector<int>& val);
    void fordJohnsonDeque(std::deque<size_t>& idx, const std::deque<int>& val);

    // Jacobsthal numbers: J(0)=0, J(1)=1, J(n) = J(n-1) + 2*J(n-2)
    // -> 0, 1, 1, 3, 5, 11, 21, 43, 85 ...
    static size_t jacobsthal(size_t n);
};

// Compares two INDICES by the values they point at. The algorithm sorts
// indices, but ordering must follow the values, so std::lower_bound needs a
// custom comparison. C++98 has no lambdas, hence a functor: an object with
// operator() that can be called like a function.
// Both are in Orthodox Canonical Form.
class VectorIndexLess
{
public:
    VectorIndexLess();
    explicit VectorIndexLess(const std::vector<int>& v);
    VectorIndexLess(const VectorIndexLess& src);
    VectorIndexLess& operator=(const VectorIndexLess& src);
    ~VectorIndexLess();

    bool operator()(size_t a, size_t b) const;

private:
    // A pointer, not a reference, so the functor stays assignable -- which the
    // STL requires of comparators.
    const std::vector<int>* _values;
};

class DequeIndexLess
{
public:
    DequeIndexLess();
    explicit DequeIndexLess(const std::deque<int>& v);
    DequeIndexLess(const DequeIndexLess& src);
    DequeIndexLess& operator=(const DequeIndexLess& src);
    ~DequeIndexLess();

    bool operator()(size_t a, size_t b) const;

private:
    const std::deque<int>* _values;
};

#endif
