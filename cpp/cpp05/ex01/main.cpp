#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        // Test 1 : Form grade high exception
        try
        {
            std::cout << std::endl;
            std::cout << "Test 1 : Form grade high exception" << std::endl;
            Form f1("f1", 0, 0);
            std::cout << f1 << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }

        // Test 2 : Form grade low exception
        try
        {
            std::cout << std::endl;
            std::cout << "Test 2 : Form grade low exception" << std::endl;
            Form f2("f2", 151, 151);
            std::cout << f2 << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }

        // Test 3 : Sign exception
        try
        {
            std::cout << std::endl;
            std::cout << "Test 3 : Sign exception" << std::endl;
            Form f3("f3", 50, 50);
            Bureaucrat b1 ("b1", 100);

            std::cout << f3 << std::endl;
            std::cout << b1 << std::endl;

            b1.signForm(f3);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }

        // Test 4 : no exception
        try
        {
            std::cout << std::endl;
            std::cout << "Test 4" << std::endl;
            Form f4("f4", 100, 100);
            Bureaucrat b2 ("b2", 1);

            std::cout << f4 << std::endl;
            std::cout << b2 << std::endl;

            b2.signForm(f4);

            std::cout << f4 << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }

        // Test 5 : assignment operator (member variables are const)
        try
        {
            std::cout << std::endl;
            std::cout << "Test 5" << std::endl;

            Form f5("f5", 100, 100);
            Form f6(f5);
            Form f7 = f5;
            Form f8;
            f8 = f5;

            std::cout << f5 << std::endl;
            std::cout << f6 << std::endl;
            std::cout << f7 << std::endl;
            std::cout << f8 << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
