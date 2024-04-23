#include "ClapTrap.hpp"

int main() {
    ClapTrap CT1;
    ClapTrap CT2("CT2");
    ClapTrap CT3(CT2);
    
    CT1 = ClapTrap("CT1");

    CT2.attack(CT1.getName());
    CT1.takeDamage(CT2.getAttackDamage());
    
    std::cout << std::endl;
    CT1.takeDamage(5);
    CT1.beRepaired(5);
    std::cout << std::endl;

    return 0;
}
