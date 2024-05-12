#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : mName("noName"), mSigned(false), mGradeToSign(150), mGradeToExecute(150) {}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute) : mName(name), mSigned(false), mGradeToSign(gradeToSign), mGradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &other) : mName(other.mName), mSigned(other.mSigned), mGradeToSign(other.mGradeToSign), mGradeToExecute(other.mGradeToExecute) {}

Form &Form::operator=(const Form &other)
{
    if (this == &other)
        return *this;
    throw std::logic_error("This class has const members");
}

Form::~Form() {}

const std::string &Form::getName() const
{
    return mName;
}

bool Form::isSigned() const
{
    return mSigned;
}

int Form::getGradeToSign() const
{
    return mGradeToSign;
}

int Form::getGradeToExecute() const
{
    return mGradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > mGradeToSign)
        throw Form::GradeTooLowException();
    mSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "grade is too low";
}

std::ostream &operator<<(std::ostream &out, Form const &form)
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


