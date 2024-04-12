#include "Cat.hpp"

Cat::Cat() : Animal() {
    _type = "Cat";
    _brain = new Brain();
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &other) {
    *this = other;
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
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
