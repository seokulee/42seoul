#include "Fixed.hpp"

Fixed::Fixed(void) : mValue(0) {}

Fixed::~Fixed(void) {}

Fixed::Fixed(int const value) : mValue(value << mFractionalBits) {}

Fixed::Fixed(float const value) : mValue(static_cast<int>(roundf(value * (1 << mFractionalBits)))) {}

Fixed::Fixed(const Fixed &fixed)
{
    *this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
    mValue = fixed.getRawBits();
    return *this;
}

bool Fixed::operator>(const Fixed &fixed) const
{
    return mValue > fixed.getRawBits() ? true : false;
}

bool Fixed::operator<(const Fixed &fixed) const
{
    return mValue < fixed.getRawBits() ? true : false;
}

bool Fixed::operator>=(const Fixed &fixed) const
{
    return mValue >= fixed.getRawBits() ? true : false;
}

bool Fixed::operator<=(const Fixed &fixed) const
{
    return mValue <= fixed.getRawBits() ? true : false;
}

bool Fixed::operator==(const Fixed &fixed) const
{
    return mValue == fixed.getRawBits() ? true : false;
}

bool Fixed::operator!=(const Fixed &fixed) const
{
    return mValue != fixed.getRawBits() ? true : false;
}

Fixed Fixed::operator+(const Fixed &fixed) const
{
    return Fixed(toFloat() + fixed.toFloat());
}

const Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    mValue++;
    return tmp;
}

Fixed &Fixed::operator++()
{
    mValue++;
    return *this;
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
    return Fixed(toFloat() - fixed.toFloat());
}

Fixed &Fixed::operator--()
{
    mValue--;
    return *this;
}

const Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    mValue--;
    return tmp;
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
    return Fixed(toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
    return Fixed(toFloat() / fixed.toFloat());
}

std::ostream &operator<<(std::ostream &out, Fixed const &fixed)
{
    out << fixed.toFloat();
    return out;
}

int Fixed::getRawBits(void) const
{
    return mValue;
}

void Fixed::setRawBits(int const raw)
{
    mValue = raw;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(mValue) / (1 << mFractionalBits);
}

int Fixed::toInt(void) const
{
    return mValue >> mFractionalBits;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return a < b ? a : b;
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b)
{
    return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return a > b ? a : b;
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b)
{
    return a > b ? a : b;
}
