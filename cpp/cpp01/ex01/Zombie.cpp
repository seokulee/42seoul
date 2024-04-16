#include "Zombie.hpp"

Zombie::Zombie()
{
    std::cout << "Zombie is born" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << this->mName << " is dead" << std::endl;
}

void Zombie::announce()
{
    std::cout << this->mName << " : " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
    this->mName = name;
}
