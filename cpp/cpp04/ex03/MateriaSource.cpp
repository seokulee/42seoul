#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++) {
        _materias[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource &other) {
    *this = other;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
    if (this != &other) {
        for (int i = 0; i < 4; i++) {
            _materias[i] = other._materias[i];
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) {
        if (_materias[i]) {
            delete _materias[i];
        }
    }
}

void MateriaSource::learnMateria(AMateria *materia) {
    for (int i = 0; i < 4; i++) {
        if (!_materias[i]) {
            _materias[i] = materia;
            break;
        }
    }
}

AMateria *MateriaSource::createMateria(std::string const &type) {
    for (int i = 0; i < 4; i++) {
        if (_materias[i] && _materias[i]->getType() == type) {
            return _materias[i]->clone();
        }
    }
    return NULL;
}
