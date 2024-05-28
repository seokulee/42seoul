#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack() : std::stack<T>() {}
    MutantStack(MutantStack const &other) : std::stack<T>(other) {}
    ~MutantStack() {}
    MutantStack &operator=(MutantStack const &other)
    {
        if (this != &other)
            std::stack<T>::operator=(other);
        return *this;
    }

    typedef typename std::stack<T>::container_type::iterator iterator;
    iterator begin() { return std::stack<T>::c.begin(); }
    iterator end() { return std::stack<T>::c.end(); }

    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    const_iterator cbegin() { return std::stack<T>::c.cbegin(); };
    const_iterator cend() { return std::stack<T>::c.cend(); };

    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    reverse_iterator rbegin() { return std::stack<T>::c.rbegin(); };
    reverse_iterator rend() { return std::stack<T>::c.rend(); };

    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
    const_reverse_iterator crbegin() { return std::stack<T>::c.crbegin(); };
    const_reverse_iterator crend() { return std::stack<T>::c.crend(); };
};

#endif
