#include "Zombie.hpp"

// void	leaks(void)
// {
// 	system("leaks zombiehorde");
// }

int main(void) {
	Zombie* horde = zombieHorde(10, "Seoul");

	// atexit(leaks);
	for (int i = 0; i < 10; i++) {
		horde[i].announce();
	}
	delete[] horde;
	return (0);
}
