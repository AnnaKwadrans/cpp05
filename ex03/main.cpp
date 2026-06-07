#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int     main (void)
{
        Bureaucrat *jim = new Bureaucrat("Jim", 12);
        Bureaucrat *ben = new Bureaucrat("Ben", 140);
        Bureaucrat *tom = new Bureaucrat("Tom", 60);
        Bureaucrat *max = new Bureaucrat("Max", 2);

        Intern *intern = new Intern();

        AForm *forms[4];

        try {
                forms[0] = intern->makeForm("ShrubberyCreationForm", "home");
                std::cout << *forms[0] << std::endl;
        }
        catch (std::exception &e) {
                std::cout << "Exception caught: " << e.what() << std::endl;
        }

        try {
                forms[1] = intern->makeForm("RobotomyRequestForm", "cat");
                std::cout << *forms[1] << std::endl;
        }
        catch (std::exception &e) {
                std::cout << "Exception caught: " << e.what() << std::endl;
        }

        try {
                forms[2] = intern->makeForm("PresidentialPardonForm", "criminal");
                std::cout << *forms[2] << std::endl;
        }
        catch (std::exception &e) {
                std::cout << "Exception caught: " << e.what() << std::endl;
        }

        try {
                forms[3] = intern->makeForm("SomeOtherForm", "someTarget");
                std::cout << *forms[3] << std::endl;
        }
        catch (std::exception &e) {
                std::cout << "Exception caught: " << e.what() << std::endl;
        }

        delete jim;
        delete ben;
        delete tom;
        delete max;

        delete intern;

        for (int i = 0; i < 3; i++) {
                std::cout << "iteration " << i << std::endl;
                if (forms[i])
                        delete forms[i];
                std::cout << "iteration " << i << std::endl;
        }

        return (0);
}
