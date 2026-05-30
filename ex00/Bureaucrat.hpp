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

        std::string     getName() const;  // getter
        int             getGrade() const; // getter

        void            incrementGrade(void);
        void            decrementGrade(void);

        class   GradeTooHighException : public std::exception
        {
                public:
                        const char *what() const throw() {
                                return ("Grade too high");
                        }
        };
        
        class   GradeTooLowException : public std::exception
        {
                public:
                        const char *what() const throw() {
                                return ("Grade too low");
                        }
        };
        
        /*
        class   GradeTooHighException : public std::exception
        {
                private:
                        std::string     _msg;
                public:
                        GradeTooHighException(const char* msg) :
                                _msg(msg) {}
                        
                        const char *what() const throw() {
                                return (_msg.c_str());
                        }
        }
        *//*
        class myException : public std::exception
        {
        private:
                std::string  message;
        public:
                
                // Constructor accepting const char*
                myException(const char* msg) :
                        message(msg) {}
                //myException(void) :
                //        message("Grade out of range") {}

                // Override what() method, marked
                // noexcept for modern C++, not C++ 98
                virtual const char* what() const throw()  {
                        return message.c_str();
                }

                virtual ~myException() throw() {}; // no destructor?
        };
        */

};

std::ostream    &operator<<(std::ostream &os, const Bureaucrat &b);




#endif
