#include "Zombie.hpp"

int main()
{
    Zombie stackZombie;
    Zombie* heapZombie = newZombie("Heap");
    heapZombie->announce();
    delete heapZombie;
    randomChump("Random");

    return 0;
}
