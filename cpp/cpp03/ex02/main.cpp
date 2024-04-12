#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    FragTrap fragTrap("FragTrap");
    ScavTrap scavTrap("ScavTrap");

    fragTrap.highFivesGuys();
    scavTrap.guardGate();

    return 0;
}
