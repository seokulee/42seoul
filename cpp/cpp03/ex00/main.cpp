#include "ClapTrap.hpp"

int main() {
    ClapTrap CT1("CT1");
    ClapTrap CT2("CT2");

    CT1.attack("CT2");
    CT2.takeDamage(5);
    CT2.beRepaired(5);

    return 0;
}
