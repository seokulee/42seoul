#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    this->mContactCount = 0;
}

PhoneBook::~PhoneBook() {}

void PhoneBook::AddContact()
{
    int index;
    std::string input;
    std::string info[] = {"first name", "last name", "nickname", "phone number", "darkest secret"};

    if (this->mContactCount == INT_MAX)
        this->mContactCount = 8;

    index = this->mContactCount % 8;
    this->mContactCount++;

    std::cout << "### Add Contact ###" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Enter " << info[i] << ": ";
        std::getline(std::cin >> std::ws, input);

        if (std::cin.eof())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            clearerr(stdin);
            return;
        }

        if (i == 0)
            this->mContacts[index].SetFirstName(input);
        else if (i == 1)
            this->mContacts[index].SetLastName(input);
        else if (i == 2)
            this->mContacts[index].SetNickName(input);
        else if (i == 3)
            this->mContacts[index].SetPhoneNumber(input);
        else if (i == 4)
            this->mContacts[index].SetDarkestSecret(input);
    }
}

void PhoneBook::SearchContact()
{
    if (this->mContactCount == 0)
        std::cout << "### Empty PhoneBook ###" << std::endl;
    else
    {
        int availableRange;
        int index;

        availableRange = mContactCount < 8 ? mContactCount - 1  : 7;

        std::cout << "###########       PhoneBook       ###########" << std::endl;
        std::cout << "     index|first name| last name|  nickname" << std::endl;
        for (int i = 0; i <= availableRange; i++)
        {
            std::cout << std::setw(10) << i + 1 << "|";
            if (this->mContacts[i].GetFirstName().size() > 10)
                std::cout << std::setw(9) << this->mContacts[i].GetFirstName().substr(0, 9) << ".|";
            else
                std::cout << std::setw(10) << this->mContacts[i].GetFirstName().substr(0, 10) << "|";
            if (this->mContacts[i].GetLastName().size() > 10)
                std::cout << std::setw(9) << this->mContacts[i].GetLastName().substr(0, 9) << ".|";
            else
                std::cout << std::setw(10) << this->mContacts[i].GetLastName().substr(0, 10) << "|";
            if (this->mContacts[i].GetNickName().size() > 10)
                std::cout << std::setw(9) << this->mContacts[i].GetNickName().substr(0, 9) << ".|";
            else
                std::cout << std::setw(10) << this->mContacts[i].GetNickName().substr(0, 10) << "|";
            std::cout << std::endl;
        }
        std::cout << "Enter the index for details: " << std::endl;
        std::cin >> index;
        index--;
        if (index < 0 || index > availableRange)
        {
            std::cout << "--------------" << std::endl;
            std::cout << "Invalid index." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return;
        }
        else
        {
            std::cout << "### Contact Details ###" << std::endl;
            std::cout << "First name: " << this->mContacts[index].GetFirstName() << std::endl;
            std::cout << "Last name: " << this->mContacts[index].GetLastName() << std::endl;
            std::cout << "Nickname: " << this->mContacts[index].GetNickName() << std::endl;
            std::cout << "Phone number: " << this->mContacts[index].GetPhoneNumber() << std::endl;
            std::cout << "Darkest secret: " << this->mContacts[index].GetDarkestSecret() << std::endl;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}
