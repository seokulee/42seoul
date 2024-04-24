#include "AMateria.hpp"

AMateria::AMateria() : _type("default") {}

AMateria::AMateria(std::string const & type) : _type(type) {}

AMateria::~AMateria() {}

AMateria::AMateria(AMateria const & src) : _type(src._type) {}

AMateria & AMateria::operator=(AMateria const & rhs) {
	if (this != &rhs) {
		_type = rhs._type;
	}
	return *this;
}

std::string const & AMateria::getType() const {
	return _type;
}

void AMateria::use(ICharacter& target) {
	(void)target;
}