/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleixo- <aaleixo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:50:29 by aaleixo-          #+#    #+#             */
/*   Updated: 2025/11/24 11:21:40 by aaleixo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("N/A"), _grade(150)
{
}

Bureaucrat::Bureaucrat(int grade) : _name("N/A")
{
	try
	{
		if(grade < 1)
			throw(1);
		else if(grade > 150)
			throw(2);
		else
			this->_grade = grade;
	}
	catch(int err)
	{
		if(err == 1)
			GradeTooHighException();
		else if(err == 2)
			GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	try
	{
		if(grade < 1)
			throw(1);
		else if(grade > 150)
			throw(2);
		else
			this->_grade = grade;
	}
	catch(int err)
	{
		if(err == 1)
			GradeTooHighException();
		else if(err == 2)
			GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	*this = copy;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& a)
{
	std::cout << "Copy Bureaucrat assignment operator called" << std::endl;
	if(this != &a)
		this->_grade = a._grade;
	return *this;
}

void Bureaucrat::GradeTooHighException()
{
	std::cout << "New grade is too high!" << std::endl;
}

void Bureaucrat::GradeTooLowException()
{
	std::cout << "New grade is too low!" << std::endl;
}

std::string Bureaucrat::getName()
{
	return this->_name;
}

int Bureaucrat::getGrade()
{
	return this->_grade;
}

void Bureaucrat::incGrade(int grade)
{
	try
	{
		if(this->_grade - grade < 1)
			throw 1;
		else
			this->_grade -= grade;
	}
	catch(int exp)
	{
		GradeTooHighException();
	}
}

void Bureaucrat::decGrade(int grade)
{
	try
	{
		if(this->_grade + grade > 150)
			throw 2;
		else
			this->_grade += grade;
	}
	catch(int exp)
	{
		GradeTooLowException();
	}
}