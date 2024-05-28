#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>

class Span
{
private:
    unsigned int mN;
    std::vector<int> mVec;

    Span();
public:
    Span(unsigned int n);
    Span(Span const &other);
    ~Span();
    Span &operator=(Span const &other);

    void addNumber(int n);
    int shortestSpan();
    int longestSpan();

    void addNumbers(int s, int step, int e);
};

#endif
