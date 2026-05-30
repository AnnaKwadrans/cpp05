#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("default"), _grade(150) {
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
        if (this->_grade < 1)
                throw GradeTooHighException();
        if (this->_grade > 150)
                throw GradeTooLowException(); 
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) {
        *this = src;
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) {
        if (this != &src)
                this->_grade = src.getGrade();
        return (*this);
}

std::string     Bureaucrat::getName() const {
        return (this->_name);
}

int             Bureaucrat::getGrade() const {
        return (this->_grade);
}
        
void            Bureaucrat::incrementGrade(void) {
        this->_grade--;
        if (this->_grade < 1)
                throw GradeTooHighException();
}

void            Bureaucrat::decrementGrade(void) {
        this->_grade++;
        if (this->_grade > 150)
                throw GradeTooLowException(); 
}

void            Bureaucrat::signForm(Form &form) {
        form.beSigned(*this);
        // TO DO
}

const char     *Bureaucrat::GradeTooHighException::what() const throw() {
        return ("Grade too high");
}

const char     *Bureaucrat::GradeTooLowException::what() const throw() {
        return ("Grade too low");
}

std::ostream    &operator<<(std::ostream &os, const Bureaucrat &b) {
        os << b.getName() << ", bureaucrat grade " << b.getGrade() <<std::endl;
        return (os);
}
