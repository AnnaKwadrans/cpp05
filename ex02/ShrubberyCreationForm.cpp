#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
    : AForm("Shrubbey Creation Form", 145, 137),
    _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("Shrubbey Creation Form", 145, 137),
    _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
    : AForm(src),
    _target(src._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm    &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src) {
    if (this != &src) {
        AForm::operator=(src);
        //this->_target = src._target; // no se puede pq _target es const
    }
    return (*this);
}

void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (!this->getIsSigned())
        throw   FormNotSignedException();
    else if (this->getGradeReqToExec() < executor.getGrade())
        throw   GradeTooLowException();
    else {
        std::cout << "Creates a file <target>_shrubbery in the working directory and writes ASCII "
            << "trees inside it." << std::endl << "Executor: " << executor.getName() << std::endl;
        std::ofstream    tree((this->getTarget() + "_shrubbery").c_str());

        tree << "                                               |" << std::endl
                << "                                              -x-" << std::endl
                << "                                               |" << std::endl
                << "              v .   ._, |_  .," << std::endl
                << "           `-._\\/  .  \\ /    |/_" << std::endl
                << "               \\\\  _\\, y | \\//" << std::endl
                << "         _\\_.___\\\\, \\\\/ -.\\||" << std::endl
                << "           `7-,--.`._||  / / ," << std::endl
                << "           /'     `-. `./ / |/_.'" << std::endl
                << "                     |    |//" << std::endl
                << "                     |_    /" << std::endl
                << "                     |-   |" << std::endl
                << "                     |   =|" << std::endl
                << "                     |    |" << std::endl
                << "--------------------/ ,  . \\--------._" << std::endl;
    }
}

std::string     ShrubberyCreationForm::getTarget() const {
    return (this->_target);
}

std::ostream    &operator<<(std::ostream &os, const ShrubberyCreationForm &form) {
    os << form.getName() << " form is ";
        if (!form.getIsSigned())
            os << "not ";
        os << "signed; gradeReqToSign: " << form.getGradeReqToSign()
            << ", gradeReqToExec: " << form.getGradeReqToExec()
            << ". Form's target is " << form.getTarget();
    return (os);
}
