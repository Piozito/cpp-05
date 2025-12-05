/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleixo- <aaleixo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:56:13 by aaleixo-          #+#    #+#             */
/*   Updated: 2025/11/26 15:56:13 by aaleixo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
protected:
	AForm();
	AForm(std::string name);
	AForm(std::string name, int sign, int exec);
	AForm(const AForm &copy);

	AForm &operator=(AForm const &a);
	virtual bool beSigned(Bureaucrat a);

private:
	std::string _name;
	const int _signGrade;
	const int _execGrade;
	bool _signed;

public:
	virtual ~AForm();
	std::string getName();
	int getSignGrade();
	int getExecGrade();
	virtual bool getSigned();
	virtual void sign(Bureaucrat a) = 0;
	virtual void execute(Bureaucrat a) = 0;

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

#endif