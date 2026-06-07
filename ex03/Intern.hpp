#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include <iostream>
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "AForm.hpp"

class AForm;

class Intern
{
        private:


        public:
                Intern();
                /* Intern();*/
                Intern(const Intern &src);

                ~Intern();

                Intern  &operator=(const Intern &src);

                AForm   *makeForm(std::string name, std::string target);


};



#endif
