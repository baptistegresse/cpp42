/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:59:53 by ubuntu            #+#    #+#             */
/*   Updated: 2023/10/30 15:00:04 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
    std::srand(std::time(0));
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::srand(std::time(0));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &original) : AForm(original), _target(original._target)
{
    std::srand(std::time(0));
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &original)
{
    if (this != &original)
    {
        AForm::operator=(original);
        this->_target = original._target;
    }
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!getIsSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getReqToExec())
        throw AForm::GradeTooLowException();

    int random = std::rand() % 2; // Générer un nombre aléatoire entre 0 et 1

    if (random == 0)
    {
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    }
    else
    {
        std::cout << "Robotomy of " << _target << " failed." << std::endl;
    }
}
