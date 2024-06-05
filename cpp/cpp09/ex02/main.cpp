#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
    try
    {
        if (argc < 2)
        {
            throw std::runtime_error("No Input");
        }
        PmergeMe pmergeMe(argc, argv);
        pmergeMe.run();
        return 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}
