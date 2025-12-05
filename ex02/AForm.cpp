/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleixo- <aaleixo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:23:37 by aaleixo-          #+#    #+#             */
/*   Updated: 2025/11/26 16:23:37 by aaleixo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("AForm N/A"), _signGrade(100), _execGrade(50), _signed(0)
{
}

AForm::AForm(std::string name) : _name(name), _signGrade(100), _execGrade(50), _signed(0)
{
}

AForm::AForm(std::string name, int sign, int exec) : _name(name), _signGrade(sign), _execGrade(exec), _signed(0)
{
	if (sign < 1 || exec < 1)
		throw(AForm::GradeTooHighException());
	else if (sign > 150 || exec > 150)
		throw(AForm::GradeTooLowException());
}

AForm::AForm(const AForm &copy) : _name(copy._name), _signGrade(copy._signGrade), _execGrade(copy._execGrade), _signed(copy._signed)
{
	*this = copy;
}

AForm::~AForm()
{
}

AForm &AForm::operator=(AForm const &a)
{
	if (this == &a)
		return *this;
	return *this;
}

std::string AForm::getName()
{
	return (this->_name);
}

int AForm::getSignGrade()
{
	return (this->_signGrade);
}

int AForm::getExecGrade()
{
	return (this->_execGrade);
}

bool AForm::getSigned()
{
	return (this->_signed);
}

bool AForm::beSigned(Bureaucrat a)
{
	if (this->_signed == 0)
	{
		if (a.getGrade() <= this->_signGrade)
			this->_signed = 1;
		else if (a.getGrade() > this->_signGrade)
			throw(AForm::GradeTooLowException());
	}
	return (this->_signed);
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
};

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
};
