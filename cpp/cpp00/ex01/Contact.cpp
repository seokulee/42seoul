#include "Contact.hpp"

	Contact::Contact() {}
	Contact::~Contact() {}
	void Contact::makeNewContact(Contact *contact) {
		std::string input;

		std::cout << "Firts name? " << std::endl;
		while (input.length() < 1)
			std::getline(std::cin, input);
		contact->firstName = input;
		input.erase();
		std::cout << "Last name? " << std::endl;
		while (input.length() < 1)
			std::getline(std::cin, input);
		contact->lastName = input;
		input.erase();
		std::cout << "Nickname? " << std::endl;
		while (input.length() < 1)
			std::getline(std::cin, input);
		contact->nickName = input;
		input.erase();
		std::cout << "Phone number " << std::endl;
		while (input.length() < 1)
			std::getline(std::cin, input);
		contact->phoneNumber = input;
		input.erase();
		std::cout << "Darkest secret? " << std::endl;
		while (input.length() < 1)
			std::getline(std::cin, input);
		contact->darkestSecret = input;
		input.erase();
	}

	void Contact::displayInline(int index) {
	std::cout << std::right << std::setw(10) << (index + 1) << "|";
	if (firstName.size() > 10)
		std::cout << std::right << std::setw(9) << firstName.substr(0, 9) << "." << "|";
	else
		std::cout << std::right << std::setw(10) << firstName.substr(0, 10) << "|";
	if (lastName.size() > 10)
		std::cout << std::right << std::setw(9) << lastName.substr(0, 9) << "." << "|";
	else
		std::cout << std::right << std::setw(10) << lastName.substr(0, 10) << "|";
	if (nickName.size() > 10)
		std::cout << std::right << std::setw(9) << nickName.substr(0, 9) << "." << std::endl;
	else
		std::cout << std::right << std::setw(10) << nickName.substr(0, 10) << std::endl;
	}

	void Contact::displayInformation() {
		std::cout << "#### INFORMATION DETAILS ####" << std::endl;
		std::cout << "First Name : " << firstName << std::endl;
		std::cout << "Last Name : " << lastName << std::endl;
		std::cout << "Nickname : " << nickName << std::endl;
		std::cout << "Phone Number : " << phoneNumber << std::endl;
		std::cout << "Darkest Secret : " << darkestSecret << std::endl;
		std::cout << "#### INFORMATION DETAILS ####" << std::endl;
	}
