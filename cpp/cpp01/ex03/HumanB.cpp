#include "HumanB.hpp"

HumanB::HumanB(std::string name) : mName(name)
{
	this->mWeapon = NULL;
}

HumanB::~HumanB() {}

void HumanB::attack() const
{
	if (mWeapon)
		std::cout << mName << " attacks with their " << (*mWeapon).getType() << std::endl;
	else
		std::cout << mName << " has no weapon" << std::endl;
}

void HumanB::setWeapon(Weapon& new_weapon)
{
	mWeapon = &new_weapon;
}
