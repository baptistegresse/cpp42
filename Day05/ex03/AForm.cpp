/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:15:49 by ubuntu            #+#    #+#             */
/*   Updated: 2023/10/30 14:12:55 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm()
: _name("default"), _isSigned(false), _reqToExec(150), _reqToSign(150)
{
}

AForm::AForm(const std::string &name, int reqToSign, int reqToExec) : _name(name), _reqToExec(reqToExec), _reqToSign(reqToSign)
{
    this->_isSigned = false;
    if (reqToExec > 150 || reqToSign > 150)
        throw AForm::GradeTooLowException();
    if (reqToExec < 1 || reqToSign < 1)
        throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm &original)
: _name(original._name), _isSigned(original._isSigned),_reqToExec(original._reqToExec), _reqToSign(original._reqToSign)
{
}

AForm::~AForm()
{
}

AForm &AForm::operator=(const AForm &original)
{
    if (this != &original)
        this->_isSigned = original._isSigned;
    return *this;
}

const std::string AForm::getName() const
{
    return this->_name;
}

bool AForm::getIsSigned() const
{
    return this->_isSigned;
}

int AForm::getReqToExec() const
{
    return this->_reqToExec;
}

int AForm::getReqToSign() const
{
    return this->_reqToSign;
}

void AForm::beSigned(Bureaucrat &bur)
{
    if (bur.getGrade() <= this->_reqToSign)
    {
        std::cout << bur.getName() << " signed " << this->getName() << std::endl;
        this->_isSigned = true;
    }
    else
        throw AForm::GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw() {
	return ("AForm exception: grade too high.");
}

const char *AForm::GradeTooLowException::what() const throw() {
	return ("AForm exception: grade too low.");
}

const char *AForm::FormNotSignedException::what() const throw() {
    return ("AForm exception: form not signed.");
}

const char *AForm::FormWriteErrorException::what() const throw() {
    return ("Aform exception: form write error.");
}

std::ostream& operator<<(std::ostream& os, AForm& src) {
    os << "AForm " << src.getName() << ", requires grade " << src.getReqToSign() << " to be signed and grade " << src.getReqToExec() << " to be executed. ";
    return (os);
}