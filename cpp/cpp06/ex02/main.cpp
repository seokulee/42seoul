#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>

Base *generate(void)
{
    srand(time(0));
    size_t randomNumber = rand();

    switch (randomNumber % 3)
    {
        case 0:
            return new A;
            break ;
        case 1:
            return new B;
            break ;
        case 2:
            return new C;
            break ;
    }
    return nullptr;
}

// nullptr when dynamic_cast fails
void identify(Base* p)
{
    std::cout << "The actual type of the object pointed to by p: ";
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown" << std::endl;
}

// throw exception when dynamic_cast fails
void identify(Base& p)
{
    for (size_t i = 0; i < 3; ++i) {
        try {
            switch (i)
            {
                case 0: {
                    A a = dynamic_cast<A&>(p);
                    std::cout << "& Actual type object is A" << std::endl;
                    break ;
                }
                case 1: {
                    B b = dynamic_cast<B&>(p);
                    std::cout << "& Actual type object is B" << std::endl;
                    break ;
                }
                case 2: {
                    C c = dynamic_cast<C&>(p);
                    std::cout << "& Actual type object is C" << std::endl;\
                    break ;
                }
                default:
                    std::cout << "& Unknown" << std::endl;
                    break ;
            }
        } catch (std::exception &e) {}
    }
}

int main()
{
    Base* b = generate();

    identify(b);
    identify(*b);

    delete b;
    return 0;
}
