#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int     main (void)
{
        Bureaucrat jim = Bureaucrat("Jim", 12);
        Bureaucrat ben = Bureaucrat("Ben", 140);
        Bureaucrat tom = Bureaucrat("Tom", 60);
        Bureaucrat max = Bureaucrat("Max", 2);

        Intern intern;

        AForm *forms[4];

        std::cout << "SRUBBERY CREATION FORM" << std::endl;
        try {
                forms[0] = intern.makeForm("ShrubberyCreationForm", "home");
                std::cout << *forms[0] << std::endl;
                jim.signForm(*forms[0]);
                tom.executeForm(*forms[0]);
                delete forms[0];
        }
        catch (std::exception &e) {
                std::cout << "Exception caught: " << e.what() << std::endl;
        }

        std::cout << std::endl << "ROBOTOMY REQUEST FORM" << std::endl;

        try {
                forms[1] = intern.makeForm("RobotomyRequestForm", "cat");
                std::cout << *forms[1] << std::endl;
                ben.signForm(*forms[1]);
                tom.signForm(*forms[1]);
                ben.executeForm(*forms[1]);
                for (int i = 0; i < 6; i++)
                        max.executeForm(*forms[1]);
                delete forms[1];
        }
        catch (std::exception &e) {
                std::cout << "Exception caught: " << e.what() << std::endl;
        }

        std::cout << std::endl << "PRESIDENTIAL PARDON FORM" << std::endl;

        try {
                forms[2] = intern.makeForm("PresidentialPardonForm", "criminal");
                std::cout << *forms[2] << std::endl;
                tom.signForm(*forms[2]);
                max.executeForm(*forms[2]);
                jim.signForm(*forms[2]);
                max.executeForm(*forms[2]);
                delete forms[2];
        }
        catch (std::exception &e) {
                std::cout << "Exception caught: " << e.what() << std::endl;
        }

        std::cout << std::endl << "NOT EXISTING FORM" << std::endl;

        try {
                forms[3] = intern.makeForm("SomeOtherForm", "someTarget");
                std::cout << *forms[3] << std::endl;
                delete forms[3];
        }
        catch (std::exception &e) {
                std::cout << "Exception caught: " << e.what() << std::endl;
        }



        return (0);
}
