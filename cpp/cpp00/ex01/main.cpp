#include <iostream>
#include "PhoneBook.hpp"

int main()
{
    PhoneBook phoneBook;
    bool isRunning = true;

    while (isRunning)
    {
        std::string input;

        std::cout << "### PhoneBook ###" << std::endl;
        std::cout << "Please enter a command\n- ADD\n- SEARCH\n- EXIT" << std::endl;
        std::cout << "#################" << std::endl;
        std::getline(std::cin, input);

        if (std::cin.eof())
        {
            std::cin.clear();
            clearerr(stdin);
            continue;
        }
        if (input == "ADD")
            phoneBook.AddContact();
        else if (input == "SEARCH")
            phoneBook.SearchContact();
        else if (input == "EXIT")
            isRunning = false;
        else
        {
            std::cout << "#################" << std::endl;
            std::cout << "Invalid command" << std::endl;
            std::cout << "#################" << std::endl;
        }

        std::cout << std::endl;
    }
}
