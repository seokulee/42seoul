#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
public:
    Weapon(std::string type);
    ~Weapon();
    const std::string& getType() const;
    void setType(std::string type);

private:
    std::string mType;
};

#endif
