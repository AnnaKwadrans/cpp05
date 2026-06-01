#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void);
ShrubberyCreationForm::ShrubberyCreationForm(std::string name, int gradeReqToSign, int gradeReqToExec);
ShrubberyCreationForm::ShrubberyCreationForm(const Form &src);

ShrubberyCreationForm::~ShrubberyCreationForm();

ShrubberyCreationForm    &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src);

