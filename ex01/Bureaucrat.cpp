#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("default"), _grade(150) {
}

Bureaucrat::Bureaucrat(std::string name, int grade)
        : _name(name),
        _grade(grade) {

        if (this->_grade < 1)
                throw GradeTooHighException();
        if (this->_grade > 150)
                throw GradeTooLowException(); 
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
        : _name(src._name),
        _grade(src._grade) {

        if (this->_grade < 1)
                throw GradeTooHighException();
        if (this->_grade > 150)
                throw GradeTooLowException(); 
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) {
        if (this != &src)
                this->_grade = src.getGrade();
        return (*this);
}

const std::string     &Bureaucrat::getName() const {
        return (this->_name);
}

int             Bureaucrat::getGrade() const {
        return (this->_grade);
}
        
void            Bureaucrat::incrementGrade(void) {
        if ((this->_grade - 1) < 1)
                throw GradeTooHighException();
        else
                this->_grade--;
}

void            Bureaucrat::decrementGrade(void) {
        if ((this->_grade + 1) > 150)
                throw GradeTooLowException();
        else
                this->_grade++;
}

void            Bureaucrat::signForm(Form &form) {
        //form.beSigned(*this);
        try {
                form.beSigned(*this);
                std::cout << this->getName() << " signed " << form.getName() << std::endl;
        }
        catch (std::exception &e) {
                std::cerr << this->getName() << " couldn’t sign " << form.getName()
                << " because " << e.what() << "." << std::endl;
        }
}

const char     *Bureaucrat::GradeTooHighException::what() const throw() {
        return ("Grade too high");
}

const char     *Bureaucrat::GradeTooLowException::what() const throw() {
        return ("Grade too low");
}

std::ostream    &operator<<(std::ostream &os, const Bureaucrat &b) {
        os << b.getName() << ", bureaucrat grade " << b.getGrade();
        return (os);
}
