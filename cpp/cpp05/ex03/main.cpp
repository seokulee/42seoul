#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		try
		{
			Intern someRandomIntern;
			AForm* rrf;

			rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
			std::cout << *rrf << std::endl;
			delete rrf;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		try
		{
			Intern someRandomIntern;
			AForm* rrf;

			rrf = someRandomIntern.makeForm("robotomy request", "Bender");
			std::cout << *rrf << std::endl;
			delete rrf;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		try
		{
			Intern someRandomIntern;
			AForm* rrf;

			rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
			std::cout << *rrf << std::endl;
			delete rrf;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}
