#include "Form.hpp"
# include "Bureaucrat.hpp"

Form::Form(void)
        : _name("default"),
        _isSigned(false),
        _gradeReqToSign(150),
        _gradeReqToExec(150) {
}

Form::Form(std::string name, int gradeReqToSign, int gradeReqToExec)
        : _name(name),
        _isSigned(false),
        _gradeReqToSign(gradeReqToSign),
        _gradeReqToExec(gradeReqToExec) {

        if (this->_gradeReqToExec < 1 || this->_gradeReqToSign < 1)
                throw GradeTooHighException();
        if (this->_gradeReqToExec > 150 || this->_gradeReqToSign > 150)
                throw GradeTooLowException();
}

Form::Form(const Form &src)
        : _name(src._name),
        _isSigned(false),
        _gradeReqToSign(src._gradeReqToSign),
        _gradeReqToExec(src._gradeReqToExec) {
}

Form::~Form() {
}

Form    &Form::operator=(const Form &src) {
        if (this != &src)
                this->_isSigned = src.getIsSigned();
        return (*this);
}

std::string     Form::getName(void) const {
        return (this->_name);
}

bool            Form::getIsSigned(void) const {
        return (this->_isSigned);
}

int             Form::getGradeReqToSign(void) const {
        return (this->_gradeReqToSign);
}

int             Form::getGradeReqToExec(void) const {
        return (this->_gradeReqToExec);
}

void            Form::beSigned(const Bureaucrat &b) {
        if (this->_gradeReqToSign >= b.getGrade())
        {
                this->_isSigned = true;
                std::cout << b.getName() << " signed " << this->getName() << std::endl;
        }
        else
        {
                std::cout << b.getName() << " couldn’t sign " << this->getName() << " because his grade is too low" << std::endl;
                throw GradeTooLowException();
        }
}

const char      *Form::GradeTooHighException::what() const throw() {
        return ("Grade too high");
}

const char      *Form::GradeTooLowException::what() const throw() {
        return ("Grade too low");
}

std::ostream    &operator<<(std::ostream &os, const Form &form) {
        os << form.getName() << " form is ";
        if (!form.getIsSigned())
                os << "not ";
        os << "signed; gradeReqToSign: " << form.getGradeReqToSign()
                << ", gradeReqToExec: " << form.getGradeReqToExec();
        return (os);
}
