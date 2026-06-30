
#include <iostream>
#include <string>
#include "Array.hpp"

static void showHeader(const std::string &title)
{
    std::cout << "\n== " << title << " ==" << std::endl;
}

static void printIntArray(const Array<int> &values)
{
    for (unsigned int i = 0; i < values.size(); ++i)
        std::cout << values[i] << ' ';
    std::cout << std::endl;
}

static void printStringArray(const Array<std::string> &values)
{
    for (unsigned int i = 0; i < values.size(); ++i)
        std::cout << values[i] << ' ';
    std::cout << std::endl;
}

int main()
{
    Array<int> blank;
    std::cout << "blank.size() -> " << blank.size() << std::endl;

    Array<int> spare(2);
    std::cout << "spare.size() -> " << spare.size() << std::endl;

    showHeader("numbers in place");
    Array<int> source(6);
    for (unsigned int i = 0; i < source.size(); ++i)
        source[i] = static_cast<int>((i + 1) * 4);
    printIntArray(source);

    showHeader("copy constructor check");
    Array<int> cloned(source);
    cloned[2] = -42;
    std::cout << "source[2] = " << source[2] << " | cloned[2] = " << cloned[2] << std::endl;

    showHeader("assignment check");
    Array<int> assigned;
    assigned = source;
    assigned[4] = 12345;
    std::cout << "source[4] = " << source[4] << " | assigned[4] = " << assigned[4] << std::endl;

    showHeader("bounds failure");
    try
    {
        std::cout << source[999] << std::endl;
    }
    catch (const std::exception &error)
    {
        std::cout << "exception caught: " << error.what() << std::endl;
    }

    showHeader("string array");
    Array<std::string> words(4);
    words[0] = "red";
    words[1] = "green";
    words[2] = "blue";
    words[3] = "gold";
    printStringArray(words);

    showHeader("const access");
    const Array<std::string> frozen(words);
    std::cout << frozen[1] << std::endl;

    return 0;
}

