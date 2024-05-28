#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

// stack은 typename 으로 deque 추가 가능 
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

    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    reverse_iterator rbegin() { return std::stack<T>::c.rbegin(); };
    reverse_iterator rend() { return std::stack<T>::c.rend(); };
};

#endif
