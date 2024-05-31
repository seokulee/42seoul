#include "RPN.hpp"

RPN::RPN() : mStack() {}

RPN::RPN(const RPN &other) : mStack(other.mStack) {}

RPN::~RPN() {}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
    {
        mStack = other.mStack;
    }
    return *this;
}

void RPN::run(const std::string &expression)
{
    fillStack(expression);
    calculate();
    std::cout << mResult << std::endl;
}

void RPN::fillStack(const std::string &expression)
{
    if (expression.empty())
    {
        throw std::runtime_error("Empty expression");
    }
    for (int i = expression.size() - 1; i >= 0; --i)
    {
        if (i % 2 == 1)
        {
            if (expression[i] != ' ')
                throw std::runtime_error("Invalid expression");
            else
                continue ;
        } else {
            if (!isAvailable(expression[i]))
                throw std::runtime_error("Invalid expression");
        }
        mStack.push(expression[i]);
    }
    if (mStack.size() < 3 || mStack.size() % 2 == 0)
        throw std::runtime_error("Invalid expression");
}

bool RPN::isAvailable(char c) const
{
    return (c >= '0' && c <= '9') || c == '+' || c == '-' || c == '*' || c == '/';
}

void RPN::calculate()
{
    size_t size;
    char tmp;

    size = mStack.size();
    for (size_t i = 0; i < size; ++i)
    {
        tmp = mStack.top();
        mStack.pop();

        if (tmp >= '0' && tmp <= '9')
        {
            mNumbers.push(tmp - '0');
        }
        else if (tmp == '+' || tmp == '-' || tmp == '*' || tmp == '/')
        {
            if (mNumbers.size() < 2)
                throw std::runtime_error("Invalid expression");
            double a = mNumbers.top();
            mNumbers.pop();
            double b = mNumbers.top();
            mNumbers.pop();
            if (tmp == '+')
                mNumbers.push(b + a);
            else if (tmp == '-')
                mNumbers.push(b - a);
            else if (tmp == '*')
                mNumbers.push(b * a);
            else if (tmp == '/')
            {
                if (a == 0)
                    throw std::runtime_error("Division by zero");
                mNumbers.push(b / a);
            }
        }
    }
    if (mNumbers.size() != 1)
        throw std::runtime_error("Invalid expression");
    mResult = mNumbers.top();
    mNumbers.pop();
}
