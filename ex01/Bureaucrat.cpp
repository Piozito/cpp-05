/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleixo- <aaleixo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:50:29 by aaleixo-          #+#    #+#             */
/*   Updated: 2025/11/26 18:38:48 by aaleixo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("N/A"), _grade(150)
{
	
}

Bureaucrat::Bureaucrat(int grade) : _name("N/A")
{
	if(grade < 1)
		throw(Bureaucrat::GradeTooHighException());
	else if(grade > 150)
		throw(Bureaucrat::GradeTooLowException());
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if(grade < 1)
		throw(Bureaucrat::GradeTooHighException());
	else if(grade > 150)
		throw(Bureaucrat::GradeTooLowException());
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade)
{
	*this = copy;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& a)
{
	if(this != &a)
		this->_grade = a._grade;
	return *this;
}

std::string Bureaucrat::getName()
{
	return this->_name;
}

int Bureaucrat::getGrade()
{
	return this->_grade;
}

void Bureaucrat::incGrade()
{
	if(this->_grade - 1 < 1)
		throw(Bureaucrat::GradeTooHighException());
	else if(this->_grade - 1 > 150)
		throw(Bureaucrat::GradeTooLowException());
	this->_grade--;
}

void Bureaucrat::decGrade()
{
	if(this->_grade + 1 < 1)
		throw(Bureaucrat::GradeTooHighException());
	else if(this->_grade + 1 > 150)
		throw(Bureaucrat::GradeTooLowException());
	this->_grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("New grade is too high!");
};

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("New grade is too low!");
};

std::ostream	&operator<<(std::ostream &out, Bureaucrat bur)
{
	out << bur.getName() << ", bureaucrat grade " << bur.getGrade() << "." << std::endl;
	return out;
}

void	Bureaucrat::signForm(Form &form)
{
	form.beSigned(this);
}
