/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleixo- <aaleixo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:46:47 by aaleixo-          #+#    #+#             */
/*   Updated: 2025/12/09 15:24:46 by aaleixo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &copy)
{
    *this = copy;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(Intern const &a)
{
    (void)a;
    return *this;
}

static AForm *createForm(AForm *form)
{
    std::cout << "Intern creates " << form->getName() << std::endl;
    return form;
}

AForm *Intern::makeForm(std::string name, std::string target)
{
    int i = 0;
    std::string forms[] = {"Presidential Pardon", "Robotomy Request", "Shruberry Creation"};

    while (i < 3 && name != forms[i])
        i++;
    switch (i)
    {
    case 0:
        return (createForm(new PresidentialPardonForm(target)));

    case 1:
        return (createForm(new RobotomyRequestForm(target)));

    case 2:
        return (createForm(new ShrubberyCreationForm(target)));
    default:
        break;
    }
    std::cout << "Invalid form..." << std::endl;
    return NULL;
}