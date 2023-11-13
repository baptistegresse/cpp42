/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:12:30 by ubuntu            #+#    #+#             */
/*   Updated: 2023/10/30 15:35:17 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    public:

		Bureaucrat();
	    Bureaucrat(std::string const & name, int const & grade);
	    Bureaucrat(Bureaucrat const & src);
	    ~Bureaucrat();
	    Bureaucrat &operator=(Bureaucrat const & rhs);

	    std::string getName() const;
	    int 		getGrade() const;

	    void 		incrementGrade();
	    void 		decrementGrade();

		void		signForm(AForm &form);

		void		executeForm(const AForm &form) const;

		class GradeTooHighException: public std::exception
		{
			public:
				const char * what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			public:
				const char * what() const throw();
		};

    private:
	    const std::string	_name;
	    int 				_grade;
};

std::ostream & operator<<(std::ostream & out, const Bureaucrat & src);