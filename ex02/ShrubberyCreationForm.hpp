#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include <fstream>
# include <iostream>
# include "AForm.hpp"

/* ShrubberyCreationForm: Required grades: sign 145, exec 137
Creates a file <target>_shrubbery in the working directory and writes ASCII trees
inside it. */

class ShrubberyCreationForm : public AForm
{
        private:
                const std::string     _target;

        public:
                ShrubberyCreationForm(void);
                ShrubberyCreationForm(std::string target);
                ShrubberyCreationForm(const ShrubberyCreationForm &src);

                ~ShrubberyCreationForm();

                ShrubberyCreationForm    &operator=(const ShrubberyCreationForm &src);

                void    execute(Bureaucrat const & executor) const;

                std::string     getTarget() const;

};

std::ostream    &operator<<(std::ostream &os, const ShrubberyCreationForm &form);

#endif
