#include "FragTrap.hpp"

FragTrap::FragTrap() {
    std::cout << "FragTrap default constructor called" << std::endl;
    _name = "default";
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
}

FragTrap::FragTrap(std::string name) {
    std::cout << "FragTrap " << name << " created" << std::endl;
    _name = name;
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &other) {
    std::cout << "FragTrap Copy constructor called" << std::endl;
    *this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
    std::cout << "FragTrap Assignation operator called" << std::endl;
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;

    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << _name << " destroyed" << std::endl;
}

void FragTrap::highFivesGuys(void) {
    if (!_hitPoints | !_energyPoints) {
        std::cout << "No response from " << _name << std::endl;
        return;
    }
    _energyPoints -= 1;

    std::cout << "FragTrap " << _name << " requests a high five!" << std::endl;
}

void FragTrap::attack(std::string const &target) {
    if (!_energyPoints || !_hitPoints) {
        std::cout << "No response from " << _name << std::endl;
        return;
    }

    std::cout << "FragTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
    _energyPoints -= 1;
}

void FragTrap::takeDamage(unsigned int amount) {
    if (!_energyPoints || !_hitPoints) {
        std::cout << "No response from " << _name << std::endl;
        return;
    }

    std::cout << "FragTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
    if (_hitPoints < amount) {
        _hitPoints = 0;
        std::cout << "FragTrap " << _name << " disabled" << std::endl;
    } else {
        _hitPoints -= amount;
        std::cout << "FragTrap " << _name << " has " << _hitPoints << " hit points" << std::endl;
    }
}