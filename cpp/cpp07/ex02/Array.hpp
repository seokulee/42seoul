#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
private:
    T* mArray;
    unsigned int mSize;
public:
    Array() : mArray(NULL), mSize(0) {};
    Array(unsigned int n) : mSize(n)
    {
        mArray = new T[n];
        for (unsigned int i = 0; i < n; ++i)
            mArray[i] = T();
    };
    Array(const Array<T> &other)
    {
        mSize = other.mSize;
        mArray = new T[mSize];
        for (unsigned int i = 0; i < mSize; ++i)
            mArray[i] = other.mArray[i];
    };
    Array<T> &operator=(const Array &other)
    {
        if (this != &other)
        {
            delete[] mArray;
            mSize = other.mSize;
            mArray = new T[mSize];
            for (unsigned int i = 0; i < mSize; ++i)
                mArray[i] = other.mArray[i];
        }
        return *this;

    };
    ~Array()
    {
        delete[] mArray;
    }

    T &operator[](unsigned int i)
    {
        if (i >= mSize)
            throw std::out_of_range("Index out of range");
        return mArray[i];

    };
    const T &operator[](unsigned int i) const
    {
        if (i >= mSize)
            throw std::out_of_range("Index out of range");
        return mArray[i];

    };
    unsigned int size() const
    {
        return mSize;
    };
};

#endif
