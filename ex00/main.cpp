#include "Bureaucrat.hpp"

int     main (void)
{

try
{
        std::cout << "TEST 1" << std::endl;
        Bureaucrat      obj("Maria", 1);
        std::cout << "Created: " << obj << std::endl;
        obj.decrementGrade();
        std::cout << "Decremented: " << obj << std::endl;
        obj.incrementGrade();
        std::cout << "Incremented: " << obj << std::endl;
        obj.incrementGrade();
        std::cout << "Incremented: " << obj << std::endl;
}
catch(const std::exception& e)
{
        std::cout << "Exception caught:" << std::endl;
        std::cerr << e.what() << '\n';
}

try
{
        std::cout << "TEST 2" << std::endl;
        Bureaucrat      obj2("Bogdan", -3);
        std::cout << "Created: " << obj2 << std::endl;
}
catch(const std::exception& e)
{
        std::cout << "Exception caught:" << std::endl;
        std::cerr << e.what() << '\n';
}

try
{
        std::cout << "TEST 3" << std::endl;
        Bureaucrat      obj3("Bogdan", 151);
        std::cout << "Created: " << obj3 << std::endl;
}
catch(const std::exception& e)
{
        std::cout << "Exception caught:" << std::endl;
        std::cerr << e.what() << '\n';
}

try
{
        std::cout << "TEST 4" << std::endl;
        Bureaucrat      obj4("Bogdan", 145);
        std::cout << "Created: " << obj4 << std::endl;
        for (int i = 0; i < 6; i++) {
                obj4.decrementGrade();
                std::cout << "Decremented: " << obj4 << std::endl;
        }
}
catch(const std::exception& e)
{
        std::cout << "Exception caught:" << std::endl;
        std::cerr << e.what() << '\n';
}

try
{
        std::cout << "TEST 5" << std::endl;
        Bureaucrat      obj5("Bogdan", 3);
        std::cout << "Created: " << obj5 << std::endl;
        for (int i = 0; i < 3; i++) {
                obj5.incrementGrade();
                std::cout << "Incremented: " << obj5 << std::endl;
        }
}
catch(const std::exception& e)
{
        std::cout << "Exception caught:" << std::endl;
        std::cerr << e.what() << '\n';
}

return (0);
}
