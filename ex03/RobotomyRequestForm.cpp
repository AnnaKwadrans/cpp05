#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
    : AForm("Robotomy Request Form", 72, 45),
    _target("default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("Robotomy Request Form", 72, 45),
    _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
    : AForm(src),
    _target(src._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm    &RobotomyRequestForm::operator=(const RobotomyRequestForm &src) {
    if (this != &src) {
        AForm::operator=(src);
        //this->_target = src._target; // no se puede pq _target es const
    }
    return (*this);
}

void    RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (!this->getIsSigned())
        throw   FormNotSignedException();
    else if (this->getGradeReqToExec() < executor.getGrade())
        throw   GradeTooLowException();
    else {
        std::cout << "*** DrIlLiNg NoIsEs ***" << std::endl;
        int num = std::rand();
        //std::cout << num << std::endl;
        if (num % 2 == 0)
                std::cout << this->getTarget() << " has been robotomized." << std::endl;
        else
                std::cout << "Robotomy failed." << std::endl;
    }
}

std::string     RobotomyRequestForm::getTarget() const {
    return (this->_target);
}

std::ostream    &operator<<(std::ostream &os, const RobotomyRequestForm &form) {
    os << form.getName() << " form is ";
        if (!form.getIsSigned())
            os << "not ";
        os << "signed; gradeReqToSign: " << form.getGradeReqToSign()
            << ", gradeReqToExec: " << form.getGradeReqToExec()
            << ". Form's target is " << form.getTarget();
    return (os);
}
