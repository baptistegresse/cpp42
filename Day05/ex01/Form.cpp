/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:15:49 by ubuntu            #+#    #+#             */
/*   Updated: 2023/10/30 15:40:07 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
: _name("default"), _isSigned(false), _reqToExec(150), _reqToSign(150)
{
}

Form::Form(const std::string &name, int reqToSign, int reqToExec) : _name(name), _reqToExec(reqToExec), _reqToSign(reqToSign)
{
    this->_isSigned = false;
    if (reqToExec > 150 || reqToSign > 150)
        throw Form::GradeTooLowException();
    if (reqToExec < 1 || reqToSign < 1)
        throw Form::GradeTooHighException();
}

Form::Form(const Form &original)
: _name(original._name), _isSigned(original._isSigned),_reqToExec(original._reqToExec), _reqToSign(original._reqToSign)
{
}

Form::~Form()
{
}

Form &Form::operator=(const Form &original)
{
    if (this != &original)
        this->_isSigned = original._isSigned;
    return *this;
}

const std::string Form::getName() const
{
    return this->_name;
}

bool Form::getIsSigned() const
{
    return this->_isSigned;
}

int Form::getReqToExec() const
{
    return this->_reqToExec;
}

int Form::getReqToSign() const
{
    return this->_reqToSign;
}

void Form::beSigned(Bureaucrat &bur)
{
    if (bur.getGrade() <= this->_reqToSign)
    {
        std::cout << bur.getName() << " signed " << this->getName() << std::endl;
        this->_isSigned = true;
    }
    else
        throw Form::GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw() {
	return ("Form exception: grade too high.");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("Form exception: grade too low.");
}

std::ostream& operator<<(std::ostream& os, Form& src) {
    os << "Form " << src.getName() << ", requires grade " << src.getReqToSign() << " to be signed and grade " << src.getReqToExec() << " to be executed. ";
    return (os);
}