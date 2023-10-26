#include "Zombie.hpp"

int main(void) {
	Zombie stackZombie;
	Zombie* heapZombie = newZombie("Heap");
	randomChump("Random Zombie");
	delete heapZombie;
	return (0);
}
