#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

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
