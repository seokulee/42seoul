#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
    std::cout << "ScavTrap default constructor called" << std::endl;
    _name = "default";
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) {
    std::cout << "ScavTrap " << name << " constructor called" << std::endl;
    _name = name;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) {
    std::cout << "ScavTrap Copy constructor called" << std::endl;
    *this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
    std::cout << "ScavTrap Assignation operator called" << std::endl;
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;

    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << _name << " destructor called" << std::endl;
}

void ScavTrap::attack(std::string const &target) {
    if (!_energyPoints || !_hitPoints) {
        std::cout << "No response from " << _name << std::endl;
        return;
    }

    std::cout << "ScavTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
    _energyPoints -= 1;
}

void ScavTrap::takeDamage(unsigned int amount) {
    if (!_energyPoints || !_hitPoints) {
        std::cout << "No response from " << _name << std::endl;
        return;
    }

    std::cout << "ScavTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
    if (_hitPoints < amount) {
        _hitPoints = 0;
        std::cout << "ScavTrap " << _name << " disabled" << std::endl;
    } else {
        _hitPoints -= amount;
        std::cout << "ScavTrap " << _name << " has " << _hitPoints << " hit points" << std::endl;
    }
}

void ScavTrap::guardGate() {
    if (!_energyPoints || !_hitPoints) {
        std::cout << "No response from " << _name << std::endl;
        return;
    }

    std::cout << "ScavTrap " << _name << " has entered in Gate keeper mode" << std::endl;
    _energyPoints -= 1;
}
