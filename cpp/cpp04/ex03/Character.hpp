#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"

class Character : public ICharacter {
	private:
		std::string _name;
		AMateria* _materia[4];
	public:
		Character();
		Character(std::string const & name);
		virtual ~Character();
		Character(Character const & src);
		Character & operator=(Character const & rhs);

		std::string const & getName() const;
		AMateria* getMateria(int idx) const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

};

#endif
