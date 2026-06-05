#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include <cstdlib>
# include "AForm.hpp"

/* RobotomyRequestForm: Required grades: sign 72, exec 45
Makes some drilling noises, then informs that <target> has been robotomized
successfully 50% of the time. Otherwise, it informs that the robotomy failed. */

class RobotomyRequestForm : public AForm
{
    private:
        const std::string     _target;

    public:

        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &src);

        ~RobotomyRequestForm();

        RobotomyRequestForm &operator=(const RobotomyRequestForm &src);

        void    execute(Bureaucrat const & executor) const;

        std::string     getTarget() const;



};


std::ostream    &operator<<(std::ostream &os, const RobotomyRequestForm &form);



#endif
