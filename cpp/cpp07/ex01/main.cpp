#include "iter.hpp"

int main()
{
    int tab[] = {0, 1, 2, 3, 4};
    ::iter<int>(tab, 5);
    return 0;
}
