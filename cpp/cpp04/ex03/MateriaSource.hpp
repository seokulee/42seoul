#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
    public:
        MateriaSource();
        MateriaSource(const MateriaSource &other);
        MateriaSource &operator=(const MateriaSource &other);
        virtual ~MateriaSource();

        virtual void learnMateria(AMateria *materia);
        virtual AMateria *createMateria(std::string const &type);
    private:
        AMateria *_materias[4];
};

#endif
