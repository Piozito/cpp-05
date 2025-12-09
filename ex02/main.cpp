/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleixo- <aaleixo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 16:03:52 by aaleixo-          #+#    #+#             */
/*   Updated: 2025/12/09 09:49:34 by aaleixo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	std::cout << "\nShruberry Creation tests:\n"
			  << std::endl;

	try
	{
		Bureaucrat gardener("Gardener", 100);
		ShrubberyCreationForm home("home");

		home.sign(gardener);
		home.execute(gardener);
	}
	catch (std::exception &e)
	{
		std::cout << "Failed, reason: " << e.what() << std::endl;
	}

	std::cout << "\nRobotomy Form tests:\n"
			  << std::endl;

	try
	{
		Bureaucrat doctor("doctor", 20);
		RobotomyRequestForm jorge("Jorge");

		jorge.sign(doctor);
		jorge.execute(doctor);
	}
	catch (std::exception &e)
	{
		std::cout << "Failed, reason: " << e.what() << std::endl;
	}

	std::cout << "\nPresidental Pardon tests:\n"
			  << std::endl;

	try
	{
		Bureaucrat president("President", 5);
		Bureaucrat vice("Vice President", 10);
		PresidentialPardonForm a("Roberto");

		a.sign(president);
		a.sign(president);
		a.execute(president);
		a.execute(vice);

		PresidentialPardonForm b("Francisco");
		b.execute(president);
	}
	catch (std::exception &e)
	{
		std::cout << "Failed, reason: " << e.what() << std::endl;
	}

	std::cout << "\nException tests\n"
			  << std::endl;

	try
	{
		Bureaucrat president("President", 1);
		PresidentialPardonForm b("Francisco");
		b.execute(president);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Failed, reason: " << e.what() << std::endl;
	}

	std::cout << "\nexecuteForm tests\n"
			  << std::endl;

	try
	{
		Bureaucrat good("Good", 1);
		Bureaucrat garderner("gardener", 150);
		ShrubberyCreationForm home("home");

		good.signForm(home);
		good.executeForm(home);
		garderner.executeForm(home);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Failed, reason: " << e.what() << std::endl;
	}
}
