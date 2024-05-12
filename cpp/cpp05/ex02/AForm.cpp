#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : mName("noName"), mSigned(false), mGradeToSign(150), mGradeToExecute(150) {}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute) : mName(name), mSigned(false), mGradeToSign(gradeToSign), mGradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other) : mName(other.mName), mSigned(other.mSigned), mGradeToSign(other.mGradeToSign), mGradeToExecute(other.mGradeToExecute) {}

AForm &AForm::operator=(const AForm &other)
{
    if (this == &other)
        return *this;
    throw std::logic_error("This class has const members");
}

AForm::~AForm() {}

const std::string &AForm::getName() const
{
    return mName;
}

bool AForm::isSigned() const
{
    return mSigned;
}

int AForm::getGradeToSign() const
{
    return mGradeToSign;
}

int AForm::getGradeToExecute() const
{
    return mGradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > mGradeToSign)
        throw AForm::GradeTooLowException();
    mSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "grade is too low";
}

std::ostream &operator<<(std::ostream &out, AForm const &form)
{
    out << "Form name : " << form.getName() << std::endl;
    out << "Form is ";
    if (form.isSigned())
        out << "signed" << std::endl;
    else
        out << "not signed" << std::endl;
    out << "Grade to sign : " << form.getGradeToSign() << std::endl;
    out <<  "Grade to execute : " << form.getGradeToExecute();
    return out;
}


