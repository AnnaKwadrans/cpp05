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

        std::string     getName(void) const;
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


/*
The grades of the Form follow the same rules as those of the Bureaucrat. Thus, the
following exceptions will be thrown if a form’s grade is out of bounds:
Form::GradeTooHighException and Form::GradeTooLowException.
As before, write getters for all attributes and overload the insertion («) operator to
print all the form’s information.

Also, add a beSigned() member function to the Form that takes a Bureaucrat as a
parameter. It changes the form’s status to signed if the bureaucrat’s grade is high enough
(greater than or equal to the required one). Remember, grade 1 is higher than grade 2.
If the grade is too low, throw a Form::GradeTooLowException.

Then, add a signForm() member function in the Bureaucrat class. This function must
call Form::beSigned() to attempt to sign the form. If the form is signed successfully, it
will print something like:
<bureaucrat> signed <form>
Otherwise, it will print something like:
<bureaucrat> couldn’t sign <form> because <reason>.
*/




#endif
