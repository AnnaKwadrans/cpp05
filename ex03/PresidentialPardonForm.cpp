#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
    : AForm("Presidential Pardon Form", 25, 5),
    _target("default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("Presidential Pardon Form", 25, 5),
    _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
    : AForm(src),
    _target(src._target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm    &PresidentialPardonForm::operator=(const PresidentialPardonForm &src) {
    if (this != &src) {
        AForm::operator=(src);
        //this->_target = src._target; // no se puede pq _target es const
    }
    return (*this);
}

void    PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    if (!this->getIsSigned())
        throw   FormNotSignedException();
    else if (this->getGradeReqToExec() < executor.getGrade())
        throw   GradeTooLowException();
    else
        std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::string     PresidentialPardonForm::getTarget() const {
    return (this->_target);
}

std::ostream    &operator<<(std::ostream &os, const PresidentialPardonForm &form) {
    os << form.getName() << " form is ";
        if (!form.getIsSigned())
            os << "not ";
        os << "signed; gradeReqToSign: " << form.getGradeReqToSign()
            << ", gradeReqToExec: " << form.getGradeReqToExec()
            << ". Form's target is " << form.getTarget();
    return (os);
}
