#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : mName("noName"), mGrade(150) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : mName(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    mGrade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : mName(other.mName), mGrade(other.mGrade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this == &other)
        return *this;
    throw std::logic_error("This class has const members");
}

Bureaucrat::~Bureaucrat() {}

const std::string &Bureaucrat::getName() const
{
    return mName;
}

int Bureaucrat::getGrade() const
{
    return mGrade;
}

void Bureaucrat::incrementGrade()
{
    if (mGrade == 1)
        throw Bureaucrat::GradeTooHighException();
    mGrade--;
}

void Bureaucrat::decrementGrade()
{
    if (mGrade == 150)
        throw Bureaucrat::GradeTooLowException();
    mGrade++;
}

void Bureaucrat::signForm(Form &form) const
{
    try
    {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat's grade is too high !!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat's grade is too low !!";
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return out;
}
