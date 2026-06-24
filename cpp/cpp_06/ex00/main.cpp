
#include <iostream>
#include "Convertor.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "To use correctly: ./convert <literal>" << std::endl;
        return (1);
    }

    Convertor::convert(argv[1]);
    return (0);
}