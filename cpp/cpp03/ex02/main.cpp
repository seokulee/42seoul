#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    FragTrap FT1("FT1");
    FragTrap FT2("FT2");

    std::cout << std::endl;

    FT1.attack(FT2.getName());
    FT2.takeDamage(FT1.getAttackDamage());
    FT2.attack(FT1.getName());
    FT1.takeDamage(FT2.getAttackDamage());
    FT2.attack(FT1.getName());
    FT1.takeDamage(FT2.getAttackDamage());

    std::cout << std::endl;

    FT1.highFivesGuys();
    FT2.highFivesGuys();

    return 0;
}
