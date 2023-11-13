/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 23:48:27 by ubuntu            #+#    #+#             */
/*   Updated: 2023/10/21 16:17:28 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat pawn("pawn", 2);
		std::cout << pawn << std::endl;
		pawn.incrementGrade();
		std::cout << pawn << std::endl;
		pawn.incrementGrade();
		std::cout << pawn << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return 0;
}