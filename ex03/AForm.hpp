#ifndef AFORM_H
# define AFORM_H

# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
        const std::string       _name;
        bool                    _isSigned;
        const int               _gradeReqToSign;
        const int               _gradeReqToExec;

public:
        AForm(void);
        AForm(std::string name, int gradeReqToSign, int gradeReqToExec);
        AForm(const AForm &src);

        virtual ~AForm();

        AForm    &operator=(const AForm &src);

        const std::string     &getName(void) const;
        bool            getIsSigned(void) const;
        int             getGradeReqToSign(void) const;
        int             getGradeReqToExec(void) const;

        void            setIsSigned(void);

        void            beSigned(const Bureaucrat &b);

        virtual void    execute(Bureaucrat const & executor) const = 0;


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

        class FormNotSignedException : public std::exception
        {
                public:
                        const char      *what() const throw();
        };
};

std::ostream    &operator<<(std::ostream &os, const AForm &form);

#endif
