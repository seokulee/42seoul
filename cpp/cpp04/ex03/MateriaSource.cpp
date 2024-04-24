#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++) {
		_materia[i] = NULL;
	}
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (_materia[i]) {
			delete _materia[i];
		}
	}
}

MateriaSource::MateriaSource(MateriaSource const & src) {
	for (int i = 0; i < 4; i++) {
		if (_materia[i]) {
			delete _materia[i];
		}
		if (src._materia[i]) {
			_materia[i] = src._materia[i]->clone();
		} else {
			_materia[i] = NULL;
		}
	}
}

MateriaSource & MateriaSource::operator=(MateriaSource const & rhs) {
	if (this != &rhs) {
		for (int i = 0; i < 4; i++) {
			if (_materia[i]) {
				delete _materia[i];
			}
			if (rhs._materia[i]) {
				_materia[i] = rhs._materia[i]->clone();
			} else {
				_materia[i] = NULL;
			}
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (!_materia[i]) {
			_materia[i] = m;
			break;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (_materia[i] && _materia[i]->getType() == type) {
			return _materia[i]->clone();
		}
	}
	return NULL;
}
