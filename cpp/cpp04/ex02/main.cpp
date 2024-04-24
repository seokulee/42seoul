#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	// const Animal* k = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;//should not create a leak
	delete i;

	return 0;

}

// int main()
// {
//     std::string str;

// 	Dog *d = new Dog();
// 	Dog *d2 = new Dog();
// 	std::cout << std::endl;

// 	str = d->getBrain()->getIdea(0);
// 	std::cout << "Dog1's first idea is "<< str << std::endl;

// 	d->getBrain()->setIdea(0, "something");
// 	str = d->getBrain()->getIdea(0);
// 	std::cout << "Dog1's first idea is "<< str << std::endl;

// 	*d2 = *d;
// 	str = d2->getBrain()->getIdea(0);
// 	std::cout << "Dog2's first idea is "<< str << std::endl;

// 	std::cout << std::endl;
// 	delete d;
// 	d = NULL;
// 	delete d2;
// 	d2 = NULL;

// 	return 0;
// }

// int main()
// {
// const Animal* j = new Dog();
// const Animal* i = new Cat();

// delete j;//should not create a leak
// delete i;

// return 0;
// }


// int main() {
//     Animal *animals[10];

//     for (int i = 0; i < 10; i++) {
//         if (i % 2 == 0) {
//             animals[i] = new Dog();
//         } else {
//             animals[i] = new Cat();
//         }
//     }

//     std::cout << std::endl;

//     for (int i = 0; i < 10; i++) {
//         delete animals[i];
//     }

//     std::cout << std::endl;

//     return 0;
// }
