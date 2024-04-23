#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
    protected:
        std::string _name;
        unsigned int _hitPoints;
        unsigned int _energyPoints;
        unsigned int _attackDamage;

    public:
        ClapTrap(void);
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &other);
        ClapTrap &operator=(const ClapTrap &other);
        virtual ~ClapTrap(void);

        virtual void attack(std::string const &target);
        virtual void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        const std::string getName(void) const;
        unsigned int getAttackDamage(void) const;
};

#endif
