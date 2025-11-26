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

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string _name;
		const int	_signGrade;
		const int	_execGrade;
		bool		_signed;

	public:
		Form();
		Form(std::string name);
		Form(std::string name, int sign, int exec);
		Form(const Form &copy);
		~Form();
		Form& operator=(Form const& a);

		std::string	getName();
		int			getSignGrade();
		int			getExecGrade();
		bool		getSigned();
		bool		beSigned(Bureaucrat *a);

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

std::ostream	&operator<<(std::ostream &out, Form form);

#endif