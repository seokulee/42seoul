#include "PhoneBook.hpp"

int main() {
	PhoneBook phoneBook;
	std::string input;

	while (true)
	{
		std::cout << "=PhoneBook=" << std::endl;
		std::cout << "|* ADD    |" << std::endl;
		std::cout << "|* SEARCH |" << std::endl;
		std::cout << "|* EXIT   |" << std::endl;
		std::cout << "===========" << std::endl;
		input.erase();
		while (input.length() < 1)
		{
			input.erase();
			std::getline(std::cin, input);
		}
		if (input == "ADD") {
			Contact contact;
			phoneBook.addContact(contact);
		}
		else if (input == "SEARCH") {
			int index, valid;
			phoneBook.displayList();
			do {
				std::cout << "Index for details? (MAIN : 0)" << std::endl;
				std::cin >> index;
				valid = phoneBook.displayContact(index - 1);
			} while (valid);
			std::cin.ignore();
		}
		else if (input == "EXIT")
			break ;
		else
			std::cout << "Please enter proper command (ADD, SEARCH, EXIT)" << std::endl;
	}
}
