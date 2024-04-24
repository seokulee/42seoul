#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

// basic test
int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	return 0;
}


// void foo(){
// 	system("leaks character");
// }

// int main()
// {
// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());

// 	ICharacter* me = new Character("me");

// 	AMateria* tmp;
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);

// 	// add more materia than the inventory can hold
// 	// in this case we have to delete the tmp materia
// 	// because the paper said 'don't do anything' in equip function
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);
// 	delete tmp;

// 	ICharacter* bob = new Character("bob");

// 	me->use(0, *bob);
// 	me->use(1, *bob);

// 	delete bob;
// 	delete me;
// 	delete src;

// 	atexit(foo);

// 	return 0;
// }

// const int MAX_MATERIA = 10;
// int main() {
// 		// Constructors
// 	std::cout << std::endl;
// 	std::cout << "CONSTRUCTORS:" << std::endl;
// 	std::cout << "-----------------------" << std::endl;
// 	IMateriaSource* src = new MateriaSource();
// 	AMateria* materiaList[MAX_MATERIA] = {NULL};
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
// 	ICharacter* me = new Character("me");
// 	std::cout << std::endl;

// 	// Create Materia
// 	std::cout << "CREATE MATERIA:" << std::endl;
// 	std::cout << "-----------------------" << std::endl;
// 	AMateria	*tmp;
// 	AMateria	*tmp1;
// 	AMateria	*tmp2;
// 	AMateria	*tmp3;

// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp1 = src->createMateria("cure");
// 	me->equip(tmp1);
// 	tmp = src->createMateria("fire"); // null
// 	me->equip(tmp);
// 	std::cout << std::endl;

// 	// Use on a new character
// 	std::cout << "USE ON A NEW CHARACTER:" << std::endl;
// 	std::cout << "-----------------------" << std::endl;
// 	ICharacter* bob = new Character("bob");
// 	me->use(0, *bob);
// 	me->use(1, *bob);
// 	std::cout << std::endl;
// 	me->use(2, *bob); // Use an empty / non existing slot in inventory
// 	me->use(-4, *bob);
// 	me->use(18, *bob);
// 	std::cout << std::endl;

// 	// Deep copy character
// 	std::cout << "DEEP COPY CHARACTER:" << std::endl;
// 	std::cout << "-----------------------" << std::endl;
// 	Character	*charles = new Character("Charles");
// 	tmp2 = src->createMateria("cure");
// 	charles->equip(tmp2);
// 	tmp3 = src->createMateria("ice");
// 	charles->equip(tmp3);
// 	tmp = src->createMateria("earth");
// 	charles->equip(tmp);
// 	Character	*charles_copy = new Character(*charles);
// 	std::cout << std::endl;

// 	// Deep copy vs its source character
// 	std::cout << "DEEP COPY VS SOURCE:" << std::endl;
// 	std::cout << "-----------------------" << std::endl;
// 	materiaList[0] = charles->getMateria(0);
// 	charles->unequip(0); // this shows that they have different materia pointers equipped
// 	materiaList[1] = charles_copy->getMateria(1);
// 	charles_copy->unequip(1); //this will produce a leak if we don't store the address somewhere else before
// 	tmp = src->createMateria("cure");
// 	charles_copy->equip(tmp);
// 	tmp = src->createMateria("ice");
// 	charles_copy->equip(tmp);
// 	std::cout << std::endl;

// 	charles->use(0, *bob);
// 	charles->use(1, *bob);
// 	charles->use(2, *bob);
// 	charles->use(3, *bob);
// 	std::cout << std::endl;
// 	charles_copy->use(0, *bob);
// 	charles_copy->use(1, *bob);
// 	charles_copy->use(2, *bob);
// 	charles_copy->use(3, *bob);
// 	std::cout << std::endl;

// 	// Unequip tests:
// 	std::cout << "UNEQUIP:" << std::endl;
// 	std::cout << "-----------------------" << std::endl;
// 	me->unequip(-1); // unequip an empty / non existing slot in inventory
// 	me->unequip(18);
// 	me->unequip(3);
// 	std::cout << std::endl;
// 	me->use(1, *charles);
// 	me->unequip(1); // Unequip a valid slot in inventory (cure unequipped)
// 	delete tmp1;
// 	me->use(1, *charles); // try to use it
// 	std::cout << std::endl;

// 	// Destructors
// 	std::cout << "DESTRUCTORS:" << std::endl;
// 	std::cout << "-----------------------" << std::endl;
// 	for (int i = 0; i < MAX_MATERIA; i++) {
// 		if (materiaList[i]) {
// 			delete materiaList[i];
// 		}
// 	}
// 	std::cout << "Deleting bob" << std::endl;
// 	delete bob;
// 	std::cout << "Deleting me" << std::endl;
// 	delete me;
// 	std::cout << "Deleting src" << std::endl;
// 	delete src;
// 	std::cout << "Deleting charles" << std::endl;
// 	delete charles;
// 	std::cout << "Deleting charles_copy" << std::endl;
// 	delete charles_copy;
// 	std::cout << std::endl;
// 	atexit(foo);
	
// 	return 0;
// }