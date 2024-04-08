#include "Contact.hpp"

Contact::Contact()
{
    this->mFirstName = "";
    this->mLastName = "";
    this->mNickname = "";
    this->mPhoneNumber = "";
    this->mDarkestSecret = "";
}

Contact::~Contact() {}

void Contact::SetFirstName(std::string mFirstName)
{
    this->mFirstName = mFirstName;
}

void Contact::SetLastName(std::string mLastName)
{
    this->mLastName = mLastName;
}

void Contact::SetNickName(std::string mNickname)
{
    this->mNickname = mNickname;
}

void Contact::SetPhoneNumber(std::string mPhoneNumber)
{
    this->mPhoneNumber = mPhoneNumber;
}

void Contact::SetDarkestSecret(std::string mDarkestSecret)
{
    this->mDarkestSecret = mDarkestSecret;
}

const std::string Contact::GetFirstName() const
{
    return this->mFirstName;
}

const std::string Contact::GetLastName() const
{
    return this->mLastName;
}

const std::string Contact::GetNickName() const
{
    return this->mNickname;
}

const std::string Contact::GetPhoneNumber() const
{
    return this->mPhoneNumber;
}

const std::string Contact::GetDarkestSecret() const
{
    return this->mDarkestSecret;
}
