#include "ClapTrap.hpp"

int main() {
    ClapTrap clapTrap("CT1");

    clapTrap.attack("target");
    clapTrap.takeDamage(5);
    clapTrap.beRepaired(5);

    return 0;
}
