#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
public:
    Zombie();
    ~Zombie();
    void announce(void) const;
    void setName(std::string name);

private:
    std::string mName;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
