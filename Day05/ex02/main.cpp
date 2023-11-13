/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:06:37 by diogmart          #+#    #+#             */
/*   Updated: 2023/10/30 15:45:48 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat bureaucrat("John", 25);

        ShrubberyCreationForm shrubberyForm("Garden");
        RobotomyRequestForm robotomyForm("Patient");
        PresidentialPardonForm pardonForm("Criminal");

        std::cout << shrubberyForm << std::endl;
        std::cout << robotomyForm << std::endl;
        std::cout << pardonForm << std::endl;

        std::cout << std::endl;

        shrubberyForm.beSigned(bureaucrat);
        robotomyForm.beSigned(bureaucrat);
        pardonForm.beSigned(bureaucrat);

        std::cout << std::endl;
        
        bureaucrat.executeForm(shrubberyForm);
        bureaucrat.executeForm(robotomyForm);
        bureaucrat.executeForm(pardonForm);

    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
