/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleixo- <aaleixo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 16:03:52 by aaleixo-          #+#    #+#             */
/*   Updated: 2025/11/26 18:42:38 by aaleixo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	std::cout << "\n===== Form output test =====\n" << std::endl;

	Form test("A normal form", 50, 10);
	Bureaucrat testsuccess("Succeeding", 40);
	Bureaucrat testfail("Failing", 100);

	std::cout << test;

	std::cout << "\n===== Form Exception tests =====\n" << std::endl;

	try
	{
		testfail.signForm(test);
	}
	catch(const Form::GradeTooLowException & e)
	{
		std::cout << testfail.getName() << " couldn't sign " << test.getName() << " because " << e.what() << std::endl;
	}

	try
	{
		Form fail("fail", 200 , 10);
	}
	catch(const Form::GradeTooLowException & e)
	{
		std::cout << e.what() << std::endl;
	}
}
