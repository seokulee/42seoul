#include <iostream>

int	main(void){
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	// Address
	std::cout << std::endl;
	std::cout << "The memory address of the string variable : " << &str << std::endl;
	std::cout << "The memory address held by stringPTR : " << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF : " << &stringREF << std::endl;

	// Value
	std::cout << std::endl;
	std::cout << "The value of the string variable : " << str << std::endl;
	std::cout << "The value of the stringPTR : " << *stringPTR << std::endl;
	std::cout << "The value of the stringREF : " << stringREF << std::endl;
	return (0);
}
