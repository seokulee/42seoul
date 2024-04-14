#include "Character.hpp"

Character::Character() : _name("default") {
    for (int i = 0; i < 4; i++) {
        _materias[i] = 0;
    }
}

Character::Character(std::string const &name) : _name(name) {
    for (int i = 0; i < 4; i++) {
        _materias[i] = 0;
    }
}

Character::Character(const Character &other) {
    *this = other;
}

Character &Character::operator=(const Character &other) {
    if (this != &other) {
        _name = other._name;
        for (int i = 0; i < 4; i++) {
            _materias[i] = other._materias[i];
        }
    }
    return *this;
}

#include "AMateria.hpp" // Include the header file for "AMateria"

Character::~Character() {
    for (int i = 0; i < 4; i++) {
        if (_materias[i]) {
            delete _materias[i];
        }
    }
}

std::string const &Character::getName() const {
    return _name;
}

void Character::equip(AMateria *materia) {
    for (int i = 0; i < 4; i++) {
        if (!_materias[i]) {
            _materias[i] = materia;
            break;
        }
    }
}


void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4) {
        _materias[idx] = 0;
    }
}

void Character::use(int idx, ICharacter &target) {
    if (idx >= 0 && idx < 4 && _materias[idx]) {
        _materias[idx]->use(target);
    }
}
