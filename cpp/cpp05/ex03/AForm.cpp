#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : mName("noName"), mSigned(false), mGradeToSign(150), mGradeToExecute(150) {}

AForm::AForm(const std::string &name, const std::string &target, int gradeToSign, int gradeToExecute) : mName(name), mTarget(target), mSigned(false), mGradeToSign(gradeToSign), mGradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other) : mName(other.mName), mTarget(other.mTarget), mSigned(other.mSigned), mGradeToSign(other.mGradeToSign), mGradeToExecute(other.mGradeToExecute) {}

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

const std::string &AForm::getTarget() const
{
    return mTarget;
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

void AForm::execute(const Bureaucrat &executor) const
{
    if (!this->isSigned())
        throw AForm::UnsignedException();
    else if (executor.getGrade() > mGradeToExecute)
        throw AForm::GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "grade is too low";
}

const char *AForm::UnsignedException::what() const throw()
{
    return "this form is unsigned form";
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


