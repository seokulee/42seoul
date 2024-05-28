#include "Span.hpp"

Span::Span(unsigned int n) : mN(n) {}

Span::Span(Span const &other) : mN(other.mN), mVec(other.mVec) {}

Span::~Span() {}

Span &Span::operator=(Span const &other)
{
    if (this != &other)
    {
        mN = other.mN;
        mVec = other.mVec;
    }
    return *this;
}

void Span::addNumber(int n)
{
    if (mVec.size() >= mN)
        throw std::out_of_range("Span is full");
    mVec.push_back(n);
}

void Span::addNumbers(int s, int step, int n)
{
    //iterator로 구현 가능
    if (mVec.size() + n > mN)
        throw std::out_of_range("Out of range");
    for (int i = 0; i < n; i++)
        mVec.push_back(s + i * step);
}

int Span::shortestSpan()
{
    if (mVec.size() <= 1)
        throw std::logic_error("Span is too short");
    std::vector<int> sorted(mVec);
    std::sort(sorted.begin(), sorted.end());
    int min = sorted[1] - sorted[0];
    for (size_t i = 2; i < sorted.size(); i++)
    {
        int diff = sorted[i] - sorted[i - 1];
        if (diff < min)
            min = diff;
    }
    return min;
}

int Span::longestSpan()
{
    if (mVec.size() <= 1)
        throw std::logic_error("Span is too short");
    std::vector<int> sorted(mVec);
    std::sort(sorted.begin(), sorted.end());
    return sorted.back() - sorted.front();
}
