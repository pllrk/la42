#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <sys/time.h>

static double timestampUs(void)
{
    timeval tv;
    gettimeofday(&tv, NULL);            // fills tv with the current system time
    return (tv.tv_sec * 1000000.0 + tv.tv_usec);
}

// One argument -> one positive integer. Rejects "12abc", "-1", "", overflow.
static bool parseArg(const std::string& arg, int& out)
{
    if (arg.empty())
        return (false);

    for (std::string::size_type i = 0; i < arg.size(); ++i)
    {
        if (arg[i] < '0' || arg[i] > '9')   // no sign, no letters, no spaces
            return (false);
    }

    std::stringstream ss(arg);
    long value;
    ss >> value;
    if (ss.fail() || !ss.eof())
        return (false);
    if (value > 2147483647L)                // would not fit in an int
        return (false);

    out = static_cast<int>(value);
    return (true);
}

template <typename T>
static void printSequence(const std::string& label, const T& container)
{
    std::cout << label;
    for (size_t i = 0; i < container.size(); ++i)
        std::cout << " " << container[i];
    std::cout << std::endl;
}

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cerr << "Error" << std::endl;
        return (1);
    }

    // --- validate first, so nothing is printed before a bad argument ------
    std::vector<int> parsed;
    for (int i = 1; i < argc; ++i)
    {
        int value;
        if (!parseArg(argv[i], value))
        {
            std::cerr << "Error" << std::endl;
            return (1);
        }
        parsed.push_back(value);
    }

    printSequence("Before:", parsed);

    PmergeMe pm;

    // --- vector: time the data management AND the sort --------------------
    double startVec = timestampUs();
    std::vector<int> vec(parsed.begin(), parsed.end());
    pm.sortVector(vec);
    double endVec = timestampUs();

    // --- deque: same work, different container ----------------------------
    double startDeq = timestampUs();
    std::deque<int> deq(parsed.begin(), parsed.end());
    pm.sortDeque(deq);
    double endDeq = timestampUs();

    printSequence("After: ", vec);

    std::cout << "Time to process a range of " << vec.size()
              << " elements with std::vector : "
              << (endVec - startVec) << " us" << std::endl;

    std::cout << "Time to process a range of " << deq.size()
              << " elements with std::deque  : "
              << (endDeq - startDeq) << " us" << std::endl;

    return (0);
}
