/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:06:37 by diogmart          #+#    #+#             */
/*   Updated: 2023/10/30 16:15:24 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


int main() {
	try {
		Bureaucrat bur("pawn", 10);
		Intern randomIntern;
		AForm *form;

		form = randomIntern.makeForm("shrubbery creation", "target");
		if (form == NULL)
			return 1;

		bur.signForm(*form);
		bur.executeForm(*form);
		delete form;
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
    return 0;
}

