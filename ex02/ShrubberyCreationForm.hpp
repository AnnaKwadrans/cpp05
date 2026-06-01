#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
        private:

        public:
                ShrubberyCreationForm(void);
                ShrubberyCreationForm(std::string name, int gradeReqToSign, int gradeReqToExec);
                ShrubberyCreationForm(const Form &src);

                ~ShrubberyCreationForm();

                ShrubberyCreationForm    &operator=(const ShrubberyCreationForm &src);

};

#endif
