#include "Bureaucrat.hpp"

int     main (void)
{

try
{
        std::cout << "TEST 1" << std::endl;
        Bureaucrat      obj("Maria", 1);
        std::cout << "Created: " << obj;
        obj.decrementGrade();
        std::cout << "Decremented: " << obj;
        obj.incrementGrade();
        std::cout << "Incremented: " << obj;
        obj.incrementGrade();
        std::cout << "Incremented: " << obj;
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
        std::cout << "Created: " << obj2;
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
        std::cout << "Created: " << obj3;
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
        std::cout << "Created: " << obj4;
        for (int i = 0; i < 6; i++) {
                obj4.decrementGrade();
                std::cout << "Decremented: " << obj4;
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
        std::cout << "Created: " << obj5;
        for (int i = 0; i < 3; i++) {
                obj5.incrementGrade();
                std::cout << "Incremented: " << obj5;
        }
}
catch(const std::exception& e)
{
        std::cout << "Exception caught:" << std::endl;
        std::cerr << e.what() << '\n';
}

return (0);
}