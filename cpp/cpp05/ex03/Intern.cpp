#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other)
{
    *this = other;
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}

AForm *Intern::makeForm(const std::string &name, const std::string &target)
{
    AForm *form = NULL;
    int i;

    std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"};

    for (i = 0; i < 3; i++)
    {
        if (name == formNames[i])
        {
            break;
        }
    }
    switch (i)
    {
    case 0:
        form = new ShrubberyCreationForm(target);
        break;
    case 1:
        form = new RobotomyRequestForm(target);
        break;
    case 2:
        form = new PresidentialPardonForm(target);
        break;
    }
    if (form)
    {
        std::cout << "Intern creates " << form->getName() << std::endl;
        return form;
    } else
    {
        throw FormNotFoundException();
    }
}

const char *Intern::FormNotFoundException::what() const throw()
{
    return "Intern couldn't find the form. Now Intern making coffee.";
}
