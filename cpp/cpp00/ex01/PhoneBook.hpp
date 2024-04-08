#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
private:
    Contact mContacts[8];
    int mContactCount;
public:
    PhoneBook();
    ~PhoneBook();
    void AddContact();
    void SearchContact();
};

#endif

