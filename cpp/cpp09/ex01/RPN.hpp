#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <exception>

// stack numbers and operators from argument (split by space)
// pop numbers and operators from stack
// calculate numbers and operators
// if errors, throw exception (order, division by zero, decimal, not a digit, etc.)
class RPN
{
private:
    std::stack<char> mStack;
    std::stack<double> mNumbers;
    double mResult;

    void fillStack(const std::string &expression);
    bool isAvailable(char c) const;
    void calculate();
public:
    RPN();
    ~RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);

    void run(const std::string &expression);
};

#endif
