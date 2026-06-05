#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int     main (void)
{

        // CONSTRUCTORES + ASSIGN OP
        ShrubberyCreationForm f1;
        std::cout << f1 << std::endl;

        ShrubberyCreationForm f2("home");
        std::cout  << f2 << std::endl;

        f1 = f2;
        std::cout << f1 << std::endl;

        ShrubberyCreationForm f3(f2);
        std::cout << f3 << std::endl;

        // EXECUTE
        Bureaucrat b1("Darek", 1);
        b1.signForm(f1);
        b1.executeForm(f1);
        //f1.execute(b1);
        std::cout << f1 << std::endl;

        Bureaucrat b2("Zbyszek", 150);
        b2.signForm(f2);
        b2.executeForm(f2);
        //f2.execute(b2);
        std::cout << f2 << std::endl; 


        // CONSTRUCTORES + ASSIGN OP
        RobotomyRequestForm f4;
        std::cout << f4 << std::endl;

        RobotomyRequestForm f5("Pepe");
        std::cout  << f5 << std::endl;

        f4 = f5;
        std::cout << f4 << std::endl;

        RobotomyRequestForm f6(f5);
        std::cout << f6 << std::endl;

        // EXECUTE
        std::srand(std::time(NULL)); // para rand() de exectute RobotomyRequestForm

        Bureaucrat b3("Darek", 1);
        b3.signForm(f4);
        for (int i = 0; i < 8; i++)
                b3.executeForm(f4);
        //f1.execute(b1);
        std::cout << f4 << std::endl;

        Bureaucrat b4("Zbyszek", 150);
        b4.signForm(f5);
        b4.executeForm(f5);
        //f2.execute(b2);
        std::cout << f5 << std::endl; 






        // CONSTRUCTORES + ASSIGN OP
        PresidentialPardonForm f7;
        std::cout << f7 << std::endl;

        PresidentialPardonForm f8("Pepe");
        std::cout  << f8 << std::endl;

        f7 = f8;
        std::cout << f7 << std::endl;

        PresidentialPardonForm f9(f8);
        std::cout << f9 << std::endl;

        // EXECUTE
        Bureaucrat b5("Darek", 1);
        b5.signForm(f7);
        b5.executeForm(f7);
        //f1.execute(b1);
        std::cout << f7 << std::endl;

        Bureaucrat b6("Zbyszek", 150);
        b6.signForm(f8);
        b6.executeForm(f8);
        //f2.execute(b2);
        std::cout << f8 << std::endl; 


        /*
        try {
                AForm    f1;
                std::cout << f1 << std::endl;
                Form    f2("C28", 31, 80);
                std::cout << f2 << std::endl;
                Form    f3("R15", -6, 240);
                std::cout << f3 << std::endl;
        }
        catch (std::exception &e) {
                std::cout << "Exception caught: " << e.what() << std::endl;
        }

        try {
                Bureaucrat      obj("Damian", 30);
                std::cout << obj << std::endl;

                Form    f1;
                std::cout << f1 << std::endl;

                Form    f2("C28", 31, 80);
                std::cout << f2 << std::endl;

                obj.signForm(f1);
                std::cout << f1 << std::endl;

                obj.signForm(f2);
                std::cout << f2 << std::endl;

                Form    f3(f2);
                std::cout << f3 << std::endl;
                Bureaucrat      b;
                std::cout << b << std::endl;
                b.signForm(f3);
                std::cout << f3 << std::endl;
        }
        catch (std::exception &e) {
                std::cout << "Exception caught: " << e.what() << std::endl;
        }
        */
        return (0);
}
