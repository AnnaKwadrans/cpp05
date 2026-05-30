#include "Bureaucrat.hpp"

int     main (void)
{

Bureaucrat obj("imie", 1);
std::cout << obj.getName() << obj.getGrade() <<std::endl;
std::cout << obj;

try
{
        std::cout << "try: " << obj.getName().at(1) << std::endl;
        obj.decrementGrade();
        std::cout << obj;
        obj.incrementGrade();
        std::cout << obj;
        obj.incrementGrade();
        std::cout << obj;
        //throw Bureaucrat::myException("Grade out of range");
}
catch(const std::exception& e)
{
        std::cout << "ex caught" << std::endl;
        std::cerr << e.what() << '\n';
}


return 0;

}