#ifndef FORM_H
# define FORM_H

# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
        const std::string       _name;
        bool                    _isSigned;
        const int               _gradeReqToSign;
        const int               _gradeReqToExec;

public:
        Form(void);
        Form(std::string name, int gradeReqToSign, int gradeReqToExec);
        Form(const Form &src);

        ~Form();

        Form    &operator=(const Form &src);

        const std::string     &getName(void) const;
        bool            getIsSigned(void) const;
        int             getGradeReqToSign(void) const;
        int             getGradeReqToExec(void) const;

        void            setIsSigned(void);

        void            beSigned(const Bureaucrat &b);


        class GradeTooHighException : public std::exception
        {
                public:
                        const char      *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
                public:
                        const char      *what() const throw();
        };
};

std::ostream    &operator<<(std::ostream &os, const Form &form);

#endif
