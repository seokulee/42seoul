#include "Zombie.hpp"

int main()
{
    Zombie stackZombie;
    stackZombie.announce();
    stackZombie.setName("Stack");
    stackZombie.announce();

    randomChump("Random");

    Zombie* heapZombie = newZombie("Heap");
    heapZombie->announce();
    delete heapZombie;

    return 0;
}
