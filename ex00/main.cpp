/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleixo- <aaleixo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 18:26:24 by aaleixo-          #+#    #+#             */
/*   Updated: 2025/11/28 18:26:30 by aaleixo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	std::cout << "\n===== Exception tests =====\n"
			  << std::endl;

	Bureaucrat a("Joao", 12);
	Bureaucrat b(24);
	Bureaucrat c("Felipe");
	Bureaucrat d;

	std::cout << a;
	std::cout << b;
	std::cout << c;
	std::cout << d;

	std::cout << "\n===== Declaration Exception tests =====\n"
			  << std::endl;

	try
	{
		Bureaucrat high("h", -1);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat low("l", 200);
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n===== Inc/Dec Exception tests =====\n"
			  << std::endl;

	try
	{
		Bureaucrat high(1);

		high.incGrade();
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat low; // grade is 150 by default

		low.decGrade();
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
