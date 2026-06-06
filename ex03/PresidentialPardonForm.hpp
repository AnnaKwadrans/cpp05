#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include "AForm.hpp"

/* PresidentialPardonForm: Required grades: sign 25, exec 5
Informs that <target> has been pardoned by Zaphod Beeblebrox. */

class PresidentialPardonForm : public AForm
{
    private:
        std::string     _target;

    public:

        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &src);

        ~PresidentialPardonForm();

        PresidentialPardonForm &operator=(const PresidentialPardonForm &src);

        void    execute(Bureaucrat const & executor) const;

        std::string     getTarget() const;

};

std::ostream    &operator<<(std::ostream &os, const PresidentialPardonForm &form);






#endif
