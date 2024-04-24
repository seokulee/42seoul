#include "Cat.hpp"

Cat::Cat() : Animal() {
    _type = "Cat";
    _brain = new Brain();
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &other) {
    std::cout << "Cat copy constructor called" << std::endl;
    _type = other._type;
    if (_brain) {
        delete _brain;
    }
    _brain = new Brain(*other._brain);
}

Cat &Cat::operator=(const Cat &other) {
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

Cat::~Cat() {
    delete _brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Ya Ong" << std::endl;
}

Brain *Cat::getBrain() {
    return _brain;
}
