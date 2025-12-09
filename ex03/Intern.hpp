/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleixo- <aaleixo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:47:06 by aaleixo-          #+#    #+#             */
/*   Updated: 2025/12/09 15:24:01 by aaleixo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
private:
    std::string _name;

public:
    Intern();
    ~Intern();
    Intern(const Intern &copy);
    Intern &operator=(Intern const &a);
    AForm *makeForm(std::string name, std::string target);

    class InvalidFormException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

#endif