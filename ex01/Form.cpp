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

#include "Form.hpp"

Form::Form() : _name("Form N/A"), _signGrade(100), _execGrade(50), _signed(0)
{
}

Form::Form(std::string name) : _name(name), _signGrade(100), _execGrade(50), _signed(0)
{
}

Form::Form(std::string name, int sign, int exec) : _name(name), _signGrade(sign), _execGrade(exec), _signed(0)
{
	if(sign < 1 || exec < 1)
		throw(Form::GradeTooHighException());
	else if(sign > 150 || exec > 150)
		throw(Form::GradeTooLowException());
}

Form::Form(const Form &copy) : _name(copy._name), _signGrade(copy._signGrade), _execGrade(copy._execGrade), _signed(copy._signed)
{
	*this = copy;
}

Form::~Form()
{
}

Form& Form::operator=(Form const& a)
{
	if(this == &a)
		return *this;
	return *this;
}

std::string Form::getName()
{
	return (this->_name);
}

int Form::getSignGrade()
{
	return (this->_signGrade);
}

int Form::getExecGrade()
{
	return (this->_execGrade);
}

bool Form::getSigned()
{
	return (this->_signed);
}

bool Form::beSigned(Bureaucrat *a)
{
	if(this->_signed == 0)
	{
			if(a->getGrade() <= this->_signGrade)
			{
				std::cout << a->getName() << " signed " << this->getName() << std::endl;
				this->_signed = 1;
			}
			else if(a->getGrade() > this->_signGrade)
				throw(Form::GradeTooLowException());
	}
	else
		std::cout << "Form \"" << this->getName() << "\" is already signed." << std::endl;
	return (this->_signed);
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Form grade is too high!");
};

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Form grade is too low!");
};

std::ostream	&operator<<(std::ostream &out, Form form)
{
	out << form.getName() << ", Form grade " << form.getSignGrade() << "." << std::endl;
	return out;
}