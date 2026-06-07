#include "Intern.hpp"

Intern::Intern() {}
//Intern::Intern(/*args*/) {}
Intern::Intern(const Intern &src) {
        (void)src;
}

Intern::~Intern() {}

Intern  &Intern::operator=(const Intern &src) {
        if (this != &src) {
                (void)src;
        }
        return (*this);
}

static AForm    *makeShrubberyCreationForm(std::string target) {

        AForm *newForm;

        newForm = new ShrubberyCreationForm(target);
        return (newForm);
}

static AForm    *makeRobotomyRequestForm(std::string target) {

        AForm *newForm;

        newForm = new RobotomyRequestForm(target);
        return (newForm);
}

static AForm    *makePresidentialPardonForm(std::string target) {

        AForm *newForm;

        newForm = new PresidentialPardonForm(target);
        return (newForm);
}

AForm   *Intern::makeForm(std::string name, std::string target) {

        /* create a form depending on a string */
        AForm *(*newForm[])(std::string) = {
                makeShrubberyCreationForm,
                makeRobotomyRequestForm,
                makePresidentialPardonForm
        };

        std::string formNames[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

        for (int i = 0; i < 3; i++) {
                if (name == formNames[i]) {
                        std::cout << "Intern creates " << name << "." << std::endl;
                        return (newForm[i](target));
                }
        }
        throw AForm::InvalidFormNameException();
        return (NULL);
}
