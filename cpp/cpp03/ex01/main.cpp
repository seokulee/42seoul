#include "ScavTrap.hpp"

int main() {
    ScavTrap ST1("ST1");
    ScavTrap ST2("ST2");

    ST1.attack("ST2");
    ST2.attack("ST1");

    ST1.guardGate();
    ST2.guardGate();

    return 0;
}
