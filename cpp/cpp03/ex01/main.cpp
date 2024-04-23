#include "ScavTrap.hpp"

int main() {
    ScavTrap ST1("ST1");
    ScavTrap ST2("ST2");

    std::cout << std::endl;

    ST1.attack(ST2.getName());
    ST2.takeDamage(ST1.getAttackDamage());
    ST2.attack(ST1.getName());
    ST1.takeDamage(ST2.getAttackDamage());
    ST2.attack(ST1.getName());
    ST1.takeDamage(ST2.getAttackDamage());

    std::cout << std::endl;

    ST1.guardGate();
    ST2.guardGate();

    return 0;
}
