#include "Brain.hpp"

Brain::Brain() {
    for (int i = 0; i < 100; i++) {
        _ideas[i] = "";
    }

    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &other) {
    *this = other;

    std::cout << "Brain copy constructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &other) {
    for (int i = 0; i < 100; i++) {
        _ideas[i] = other._ideas[i];
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}

std::string Brain::getIdea(int i) const {
    return _ideas[i];
}

void Brain::setIdea(int i, std::string idea) {
    _ideas[i] = idea;
}
