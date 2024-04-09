#include "Weapon.hpp"

Weapon::Weapon(std::string type) : mType(type) {}

Weapon::~Weapon() {}

const std::string& Weapon::getType() const
{
    return this->mType;
}

void Weapon::setType(std::string type)
{
    this->mType = type;
}
