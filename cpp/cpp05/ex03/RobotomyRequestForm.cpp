#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{
    throw std::logic_error("This class need target information to construct");
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", target, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this == &other)
        return *this;
    throw std::logic_error("This class has const members");
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    AForm::execute(executor);
    std::cout << "* BZzzzzzzz *" << std::endl;
    srand(time(NULL));
        if (rand() % 2)
            std::cout << this->getTarget() << " has been successfully robotimized!" << std::endl;
        else
            std::cout << this->getTarget() << " failed to be robotomized!" << std::endl;

}
