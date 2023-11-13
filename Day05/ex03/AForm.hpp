/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:14:04 by ubuntu            #+#    #+#             */
/*   Updated: 2023/10/30 16:15:52 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    public:
        
        AForm();
        AForm(const std::string &name, int reqToSign, int reqToExec);
        AForm(const AForm &original);
        virtual ~AForm();
        AForm &operator=(const AForm &original);
    
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

        class FormNotSignedException : public std::exception {
            public:
				virtual const char *what() const throw();
        };

        class FormWriteErrorException : public std::exception {
            public:
				virtual const char *what() const throw();
        };

        virtual void execute(Bureaucrat const & executor) const = 0;

    private:

        const std::string   _name;
        bool                _isSigned;
        int                 _reqToExec;
        int                 _reqToSign;
        
};

std::ostream& operator<<(std::ostream& os, AForm& src);