#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <iostream>
# include <string>

class Bureaucrat
{
private:
        const std::string       _name;
        int                     _grade;

public:
        Bureaucrat(void); // default constructor
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &src); // copy constructor

        ~Bureaucrat(); // destructor

        Bureaucrat &operator=(const Bureaucrat &src); // copy assign operator

        const std::string     &getName() const;  // getter
        int             getGrade() const; // getter

        void            incrementGrade(void);
        void            decrementGrade(void);

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
