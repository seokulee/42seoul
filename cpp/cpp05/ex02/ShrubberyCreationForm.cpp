#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
    throw std::logic_error("This class need target information to construct");
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", target, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this == &other)
        return *this;
    throw std::logic_error("This class has const members");
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    AForm::execute(executor);
    std::fstream fs;

    fs.open(this->getTarget() + "_shrubbery", std::fstream::out | std::fstream::trunc);
    if (!fs.good())
        std::cerr << "<<ERROR>> File Open ERROR" << std::endl;

    fs <<
    "    *\n"
    "   /.\\\n"
    "  /o..\\\n"
    "  /..o\\\n"
    " /.o..o\\\n"
    " /...o.\\\n"
    "/..o....\\\n"
    "^^^[_]^^^\n";

    fs.close();
}
