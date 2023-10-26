#ifndef HUMANB_HPP_
# define HUMANB_HPP_

#include "Weapon.hpp"

class HumanB {
	private:
		std::string name;
		Weapon* weapon;
	public:
		HumanB(std::string name);
		~HumanB();
		void setWeapon(Weapon& new_weapon);
		void attack() const;
};

#endif
