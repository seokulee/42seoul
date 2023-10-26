#include "Weapon.hpp"

Weapon::Weapon(std::string weapon_type) : type(weapon_type) {}
Weapon::~Weapon() {}

const std::string& Weapon::getType() const {
	return (type);
}

void Weapon::setType(std::string new_type) {
	type = new_type;
}
