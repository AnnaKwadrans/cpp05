#include "Bureaucrat.hpp"
#include "Form.hpp"

int     main (void)
{
        try {
                Form    f1;
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

        return (0);
}
