#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
private:
    T* mArray;
    std::size_t mSize;
public:
    Array();
    Array(unsigned int n);
    Array(const Array &other);
    Array &operator=(const Array &other);
    ~Array();

    T &operator[](unsigned int i);
    const T &operator[](unsigned int i) const;
    std::size_t size() const;
};

template <typename T>
Array<T>::Array() : mArray(NULL), mSize(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : mArray(new T[n]), mSize(n) {}

# include "Array.tpp"
#endif
