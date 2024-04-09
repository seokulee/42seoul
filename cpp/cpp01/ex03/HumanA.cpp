#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : mName(name), mWeapon(weapon) {}

HumanA::~HumanA() {}

void HumanA::attack() const
{
	std::cout << mName << " attacks with their " << mWeapon.getType() << std::endl;
}
