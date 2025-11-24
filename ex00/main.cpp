/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleixo- <aaleixo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 16:03:52 by aaleixo-          #+#    #+#             */
/*   Updated: 2025/11/24 11:22:19 by aaleixo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat a("Joao", 12);

	std::cout << "Const name: " << a.getName() << std::endl;
	std::cout << "Old grade: " << a.getGrade() << std::endl;
	a.decGrade(100);
	std::cout << "New grade: " << a.getGrade() << std::endl;
	a.incGrade(50);
	std::cout << "Final grade: " << a.getGrade() << std::endl;

	std::cout << "\n===== Exception tests =====\n" << std::endl;

	Bureaucrat toohigh;
	Bureaucrat toolow;

	toohigh.incGrade(200);
	toolow.decGrade(200);

	Bureaucrat high("high", 0);
	Bureaucrat low(200);
}