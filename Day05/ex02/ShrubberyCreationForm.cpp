/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:34:55 by ubuntu            #+#    #+#             */
/*   Updated: 2023/10/30 14:55:20 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &original) : AForm(original), _target(original._target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &original)
{
    if (this != &original)
    {
        AForm::operator=(original);
        this->_target = original._target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    if (!this->getIsSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getReqToExec())
        throw AForm::GradeTooLowException();

    std::ofstream file((_target + "_shrubbery").c_str());

    if (file.is_open())
    {
        file << "     *     \n" <<
                "     ^     \n" <<
                "    ^^^    \n" <<
                "   ^^^^^   \n" << 
                "  ^^^^^^^  \n" <<
                " ^^^^^^^^^ \n" << 
                "^^^^^^^^^^^\n" <<
                "     ||     ";
        file.close();
    }
    else
    {
        throw AForm::FormWriteErrorException();
    }
}
