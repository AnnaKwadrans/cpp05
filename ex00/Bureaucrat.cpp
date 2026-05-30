#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("default"), _grade(150) {
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
        // compr rango?
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) {
        *this = src;
}

Bureaucrat::~Bureaucrat() {
}


Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) {
        if (this != &src) {
                // this->_name = src.getName(); // no se puede pg name es const
                this->_grade = src.getGrade();
        }
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
        if (this->_grade < 1 || this->_grade > 150)
                throw myException("Grade out of range (1-150)");
}

void            Bureaucrat::decrementGrade(void) {
        this->_grade++;
        if (this->_grade < 1 || this->_grade > 150)
                throw myException("Grade out of range (1-150)");
}

std::ostream    &operator<<(std::ostream &os, const Bureaucrat &b) {
        os << b.getName() << ", bureaucrat grade " << b.getGrade() <<std::endl;
        return (os);
}
