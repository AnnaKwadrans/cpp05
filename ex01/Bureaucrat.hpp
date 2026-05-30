#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <iostream>
# include <string>
# include "Form.hpp"

class Form;

class Bureaucrat
{
private:
        const std::string       _name;
        int                     _grade;

public:
        Bureaucrat(void);
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &src);

        ~Bureaucrat();

        Bureaucrat &operator=(const Bureaucrat &src);

        std::string     getName() const;
        int             getGrade() const;

        void            incrementGrade(void);
        void            decrementGrade(void);
        void            signForm(Form &form); // TO DO

        class   GradeTooHighException : public std::exception
        {
                public:
                        const char *what() const throw();
        };
        
        class   GradeTooLowException : public std::exception
        {
                public:
                        const char *what() const throw();
        };
};

std::ostream    &operator<<(std::ostream &os, const Bureaucrat &b);

#endif
