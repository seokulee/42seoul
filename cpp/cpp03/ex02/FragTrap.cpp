#include "FragTrap.hpp"

FragTrap::FragTrap() {
    _name = "default";
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;

    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) {
    _name = name;
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;

    std::cout << "FragTrap " << _name << " created" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) {
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;

    std::cout << "FragTrap Copy " << _name << " created" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;

    std::cout << "FragTrap Assignation operator called" << std::endl;
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
    std::cout << "FragTrap " << _name << " requests a high five!" << std::endl;
}
