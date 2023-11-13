/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:06:37 by diogmart          #+#    #+#             */
/*   Updated: 2023/10/30 15:20:14 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat bureaucrat("John", 51);
        Form form("Tax Form", 50, 20);

        std::cout << bureaucrat << std::endl;
        std::cout << form << std::endl;

        bureaucrat.signForm(form);

        bureaucrat.incrementGrade();
        std::cout << bureaucrat << std::endl;

        bureaucrat.signForm(form);
        bureaucrat.signForm(form);

    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
