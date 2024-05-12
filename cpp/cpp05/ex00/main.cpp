#include "Bureaucrat.hpp"

int main()
{
    try
    {
        // Test 1 : Grade too low exception when creating a bureaucrat
        try
        {
            std::cout << "Test 1" << std::endl;
            Bureaucrat a("a", 0);
            std::cout << a << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }

        // Test 2 : Grade too high exception when creating a bureaucrat
        try
        {
            std::cout << "Test 2" << std::endl;
            Bureaucrat b("b", 151);
            std::cout << b << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }

        // Test 3 : Increment grade to 0
        try
        {
            std::cout << "Test 3" << std::endl;
            Bureaucrat c("c", 1);
            std::cout << c << std::endl;
            c.incrementGrade();
            std::cout << c << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }

        // Test 4 : Decrement grade to 151
        try
        {
            std::cout << "Test 4" << std::endl;
            Bureaucrat d("d", 150);
            std::cout << d << std::endl;
            d.decrementGrade();
            std::cout << d << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }

        // Test 5 : No exception
        try
        {
            std::cout << "Test 5" << std::endl;
            Bureaucrat e("e", 50);
            std::cout << e << std::endl;
            e.incrementGrade();
            std::cout << e << std::endl;
            e.decrementGrade();
            std::cout << e << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
