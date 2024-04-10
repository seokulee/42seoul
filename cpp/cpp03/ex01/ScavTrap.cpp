#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
    _name = "default";
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;

    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name){
    _name = name;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;

    std::cout << "ScavTrap " << _name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) {
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;

    std::cout << "ScavTrap Copy " << _name << " created" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;

    std::cout << "ScavTrap " << _name << " assigned" << std::endl;

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

void ScavTrap::guardGate() {
    if (!_energyPoints || !_hitPoints) {
        std::cout << "No response from " << _name << std::endl;
        return;
    }

    std::cout << "ScavTrap " << _name << " has entered in Gate keeper mode" << std::endl;
    _energyPoints -= 1;
}
