#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
    std::cout << "ClapTrap default constructor called" << std::endl;
    _name = "default";
    _hitPoints = 10;
    _energyPoints = 10;
    _attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name) : _name(name) {
    std::cout << "ClapTrap " << _name << " created" << std::endl;
    _hitPoints = 10;
    _energyPoints = 10;
    _attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
    std::cout << "ClapTrap Copy constructor called" << std::endl;
    *this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
    std::cout << "ClapTrap Assignation operator called" << std::endl;
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;

    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << _name << " destroyed" << std::endl;
}

void ClapTrap::attack(std::string const &target) {
    if (!_energyPoints || !_hitPoints) {
        std::cout << "No response from " << _name << std::endl;
        return;
    }

    _energyPoints -= 1;

    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (!_energyPoints || !_hitPoints) {
        std::cout << "No response from " << _name << std::endl;
        return;
    }

    std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
    if (_hitPoints < amount) {
        _hitPoints = 0;
        std::cout << "ClapTrap " << _name << " disabled" << std::endl;
    } else {
        _hitPoints -= amount;
        std::cout << "ClapTrap " << _name << " has " << _hitPoints << " hit points" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (!_energyPoints || !_hitPoints) {
        std::cout << "No response from " << _name << std::endl;
        return;
    }

    std::cout << "ClapTrap " << _name << " is repaired for " << amount << " points!" << std::endl;
    _hitPoints += amount;
    std::cout << "ClapTrap " << _name << " has " << _hitPoints << " hit points" << std::endl;
    _energyPoints -= 1;
}

const std::string ClapTrap::getName() const {
    return _name;
}

unsigned int ClapTrap::getAttackDamage() const {
    return _attackDamage;
}