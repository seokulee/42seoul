#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
    public:
        Brain();
        Brain(const Brain &other);
        Brain &operator=(const Brain &other);
        ~Brain();
        std::string getIdea(int i) const;
        void setIdea(int i, std::string idea);
    private:
        std::string _ideas[100];
};

#endif
