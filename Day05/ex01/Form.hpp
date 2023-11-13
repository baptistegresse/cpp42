/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:14:04 by ubuntu            #+#    #+#             */
/*   Updated: 2023/10/30 15:17:49 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    public:
        
        Form();
        Form(const std::string &name, int reqToSign, int reqToExec);
        Form(const Form &original);
        ~Form();
        Form &operator=(const Form &original);
    
        const std::string   getName(void) const;
        bool                getIsSigned(void) const;
        int                 getReqToExec(void) const;
        int                 getReqToSign(void) const;

        void    beSigned(Bureaucrat &bur);

        class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

    private:

        const std::string   _name;
        bool                _isSigned;
        int                 _reqToExec;
        int                 _reqToSign;
        
};

std::ostream& operator<<(std::ostream& os, Form& src);