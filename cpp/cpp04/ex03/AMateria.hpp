#ifndef AMATERA_HPP
#define AMATERA_HPP

#include <iostream>
#include "ICharacter.hpp"

class AMateria {
	protected:
		std::string _type;
	public:
		AMateria();
		AMateria(std::string const & type);
		virtual ~AMateria();
		AMateria(AMateria const & src);
		AMateria & operator=(AMateria const & rhs);

		std::string const & getType() const; // Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
