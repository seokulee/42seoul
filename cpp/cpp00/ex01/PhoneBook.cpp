#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {};
PhoneBook::~PhoneBook() {};

void PhoneBook::addContact(Contact contact) {
	index = (totalContacts % 8);
	contact.makeNewContact(&contacts[index]);
	index++;
	if (totalContacts < 8)
		totalContacts++;
	if (index > 7)
		index -= 8;
};

void PhoneBook::displayList() {
	if (totalContacts == 0)
		std::cout << "### Enpty Phonebook ###" << std::endl;
	else {
		std::cout << "|    Index|First Name| Last Name| Nickname|" << std::endl;
		for (int i = 0; i < totalContacts; i++) {
			contacts[i].displayInline(i);
		}
	}
};

int PhoneBook::displayContact(int index) {
	if (index < -1 || index >= totalContacts) {
		std::cout << "Wrong Index! Try 0 ~ " << totalContacts <<std::endl;
		return (1);
	}
	else if (index == -1)
		;
	else {
		contacts[index].displayInformation();
	}
	return (0);
};
