#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void foo() {
	system("leaks animal");
}

// int main()
// {
// 	const Animal* meta = new Animal();
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();

// 	std::cout << j->getType() << " " << std::endl;
// 	j->makeSound();
// 	std::cout << i->getType() << " " << std::endl;
// 	i->makeSound(); //will output the cat sound!
// 	std::cout << meta->getType() << " " << std::endl;
// 	meta->makeSound();

// 	std::cout << std::endl;

// 	delete meta;
// 	delete j;
// 	delete i;

// 	return 0;
// }

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	j->makeSound();
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	std::cout << meta->getType() << " " << std::endl;
	meta->makeSound();

	std::cout << std::endl;
	const WrongAnimal* wrong_meta = new WrongAnimal();
	const WrongAnimal* wrong_j = new WrongCat();

	std::cout << wrong_j->getType() << " " << std::endl;
	wrong_j->makeSound();
	std::cout << wrong_meta->getType() << " " << std::endl;
	wrong_meta->makeSound();

	delete meta;
	delete j;
	delete i;
	delete wrong_meta;
	delete wrong_j;

	atexit(foo);
	return 0;
}
