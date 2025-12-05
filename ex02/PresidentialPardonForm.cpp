/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleixo- <aaleixo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:28:10 by aaleixo-          #+#    #+#             */
/*   Updated: 2025/12/05 13:15:18 by aaleixo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy), _target(copy._target)
{
    *this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &a)
{
    if (this == &a)
        return *this;
    return *this;
}

void PresidentialPardonForm::sign(Bureaucrat a)
{
    if (this->getSigned() == false)
    {
        if (this->beSigned(a) == true)
            std::cout << "Bureaucrat " << a.getName() << " signed the presidential pardon for " << this->getName() << " successfully!" << std::endl;
    }
    else
        std::cout << "Presidential form \"" << this->getName() << "\" is already signed." << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat a)
{
    if (this->getSigned() == true && a.getGrade() <= this->getExecGrade())
    {
        std::cout << this->getName() << " has been pardoned by Zaphod Beeblebox." << std::endl;
    }
    else if (a.getGrade() > this->getExecGrade())
        std::cout << a.getName() << "'s grade too low to execute a pardon..." << std::endl;
    else
        std::cout << "Presidential pardon not signed yet" << std::endl;
}