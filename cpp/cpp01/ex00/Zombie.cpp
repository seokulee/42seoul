#include "Zombie.hpp"

Zombie::Zombie()
{
    mName = "NoName";
    std::cout << "Zombie(NoName) is born" << std::endl;
}

Zombie::Zombie(std::string name)
{
    this->mName = name;
    std::cout << "Zombie " << this->mName << " is born" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << this->mName << " is dead" << std::endl;
}

void Zombie::announce()
{
    std::cout << this->mName << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
    this->mName = name;
}
