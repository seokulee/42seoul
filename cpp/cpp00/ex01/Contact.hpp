#ifndef CONTACT_HPP_
# define CONTACT_HPP_

# include <iostream>
# include <iomanip>

class Contact {
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;

	public:
		Contact();
		~Contact();
		void makeNewContact(Contact *contact);
		void displayInline(int index);
		void displayInformation();
};

#endif
