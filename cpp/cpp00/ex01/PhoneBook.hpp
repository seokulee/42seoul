#ifndef PHONEBOOK_HPP_
# define PHONEBOOK_HPP_

# include "Contact.hpp"

class PhoneBook {
	private:
		Contact contacts[8];
		int totalContacts;
		int index;

	public:
		PhoneBook();
		~PhoneBook();
		void addContact(Contact contact);
		void displayList();
		int displayContact(int index);
};

#endif
