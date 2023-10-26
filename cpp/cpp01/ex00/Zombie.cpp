#include "Zombie.hpp"

Zombie::Zombie() {
	std::cout << "Zombie created!" << std::endl;
}

Zombie::~Zombie() {
	std::cout << "Zombie [" << name << "] is dead!" << std::endl;
}

void Zombie::announce(void) {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
	this->name = name;
}
