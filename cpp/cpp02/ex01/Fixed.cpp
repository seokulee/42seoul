#include "Fixed.hpp"

Fixed::Fixed(void) : mValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(int const value) : mValue(value << mFractionalBits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const value) : mValue(static_cast<int>(roundf(value * (1 << mFractionalBits))))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    mValue = fixed.getRawBits();
    return *this;
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
