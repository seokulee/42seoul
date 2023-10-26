#ifndef WEAPON_HPP_
# define WEAPON_HPP_

# include <iostream>

class Weapon {
	private:
		std::string type;
	public:
		Weapon(std::string weapon_type);
		~Weapon();
		const std::string& getType() const;
		void setType(std::string new_type);
};

#endif
