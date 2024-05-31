#include "RPN.hpp"

int main(int argc, char **argv)
{
    try
    {
        if (argc != 2)
        {
            throw std::runtime_error("Usage: ./RPN \"inverted Polish mathematical expression\"");
        }
        RPN rpn;
        rpn.run(argv[1]);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
