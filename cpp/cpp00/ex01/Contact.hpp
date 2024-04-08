#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact
{
public:
    Contact();
    ~Contact();
    void SetFirstName(std::string mFirstName);
    void SetLastName(std::string mLastName);
    void SetNickName(std::string mNickname);
    void SetPhoneNumber(std::string mPhoneNumber);
    void SetDarkestSecret(std::string mDarkestSecret);
    const std::string GetFirstName() const;
    const std::string GetLastName() const;
    const std::string GetNickName() const;
    const std::string GetPhoneNumber() const;
    const std::string GetDarkestSecret() const;

private:
    std::string mFirstName;
    std::string mLastName;
    std::string mNickname;
    std::string mPhoneNumber;
    std::string mDarkestSecret;
};

#endif
