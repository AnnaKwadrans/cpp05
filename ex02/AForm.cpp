#include "AForm.hpp"
# include "Bureaucrat.hpp"

AForm::AForm(void)
        : _name("default"),
        _isSigned(false),
        _gradeReqToSign(150),
        _gradeReqToExec(150) {
}

AForm::AForm(std::string name, int gradeReqToSign, int gradeReqToExec)
        : _name(name),
        _isSigned(false),
        _gradeReqToSign(gradeReqToSign),
        _gradeReqToExec(gradeReqToExec) {

        if (this->_gradeReqToExec < 1 || this->_gradeReqToSign < 1)
                throw GradeTooHighException();
        if (this->_gradeReqToExec > 150 || this->_gradeReqToSign > 150)
                throw GradeTooLowException();
}

AForm::AForm(const AForm &src)
        : _name(src._name),
        _isSigned(false),
        _gradeReqToSign(src._gradeReqToSign),
        _gradeReqToExec(src._gradeReqToExec) {
}

AForm::~AForm() {
}

AForm    &AForm::operator=(const AForm &src) {
        if (this != &src)
                this->_isSigned = src.getIsSigned();
        return (*this);
}

const std::string     &AForm::getName(void) const {
        return (this->_name);
}

bool            AForm::getIsSigned(void) const {
        return (this->_isSigned);
}

int             AForm::getGradeReqToSign(void) const {
        return (this->_gradeReqToSign);
}

int             AForm::getGradeReqToExec(void) const {
        return (this->_gradeReqToExec);
}

void            AForm::beSigned(const Bureaucrat &b) {
        if (this->_gradeReqToSign >= b.getGrade())
                this->_isSigned = true;
        else
                throw GradeTooLowException();
}

const char      *AForm::GradeTooHighException::what() const throw() {
        return ("Grade too high");
}

const char      *AForm::GradeTooLowException::what() const throw() {
        return ("Grade too low");
}

const char      *AForm::FormNotSignedException::what() const throw() {
        return ("Form not signed");
}

std::ostream    &operator<<(std::ostream &os, const AForm &form) {
        os << form.getName() << " form is ";
        if (!form.getIsSigned())
                os << "not ";
        os << "signed; gradeReqToSign: " << form.getGradeReqToSign()
                << ", gradeReqToExec: " << form.getGradeReqToExec();
        return (os);
}
