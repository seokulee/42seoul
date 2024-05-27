#include "iter.hpp"

template <typename T>
void print(T &elem)
{
    std::cout << elem << std::endl;
}

int main()
{
    int tab[] = {0, 1, 2, 3, 4};
    ::iter<int>(tab, 5, print);
    return 0;
}
