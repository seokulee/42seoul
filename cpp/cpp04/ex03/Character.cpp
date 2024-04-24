#include "Character.hpp"

Character::Character() : _name("default") {
	for (int i = 0; i < 4; i++) {
		_materia[i] = NULL;
	}
}

Character::Character(std::string const & name) : _name(name) {
	for (int i = 0; i < 4; i++) {
		_materia[i] = NULL;
	}
}

#include "AMateria.hpp" // AMateria.hpp is included here to avoid circular inclusion

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (_materia[i]) {
			delete _materia[i];
		}
	}
}

Character::Character(Character const & src) : _name(src._name) {
	for (int i = 0; i < 4; i++) {
		if (_materia[i]) {
			delete _materia[i];
		}
		if (src._materia[i]) {
			_materia[i] = src._materia[i]->clone();
		} else {
			_materia[i] = 0;
		}
	}
}

Character & Character::operator=(Character const & rhs) {
	if (this != &rhs) {
		_name = rhs._name;
		for (int i = 0; i < 4; i++) {
			if (_materia[i]) {
				delete _materia[i];
			}
			if (rhs._materia[i]) {
				_materia[i] = rhs._materia[i]->clone();
			} else {
				_materia[i] = 0;
			}
		}
	}
	return *this;
}

std::string const & Character::getName() const {
	return _name;
}

void Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (!_materia[i]) {
			_materia[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4) {
		_materia[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < 4 && _materia[idx]) {
		_materia[idx]->use(target);
	}
}

AMateria* Character::getMateria(int idx) const {
	if (idx >= 0 && idx < 4) {
		return _materia[idx];
	}
	return NULL;
}