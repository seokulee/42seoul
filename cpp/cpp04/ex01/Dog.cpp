#include "Dog.hpp"

Dog::Dog() : Animal() {
    std::cout << "Dog constructor called" << std::endl;
    _type = "Dog";
    _brain = new Brain();
}

Dog::Dog(const Dog &other) {
    std::cout << "Dog copy constructor called" << std::endl;
    _type = other._type;
    if (_brain) {
        delete _brain;
    }
    _brain = new Brain(*other._brain);
}

Dog &Dog::operator=(const Dog &other) {
    if (this == &other) {
        return *this;
    }
    _type = other._type;
    if (_brain) {
        delete _brain;
    }
    _brain = new Brain(*other._brain);
    return *this;
}

Dog::~Dog() {
    delete _brain;
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Mung Mung" << std::endl;
}

Brain *Dog::getBrain() {
    return _brain;
}
