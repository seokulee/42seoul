#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
    std::cout << "Wrong Animal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
    *this = other;
    std::cout << "Wrong Animal copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
    _type = other._type;
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "Wrong Animal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout << "Wrong Animal sound undefined" << std::endl;
}

std::string WrongAnimal::getType() const {
    return _type;
}
