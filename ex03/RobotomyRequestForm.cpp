/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleixo- <aaleixo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:25:10 by aaleixo-          #+#    #+#             */
/*   Updated: 2025/12/09 09:35:25 by aaleixo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), _target(copy._target)
{
    *this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &a)
{
    if (this == &a)
        return *this;
    return *this;
}

void RobotomyRequestForm::sign(Bureaucrat a)
{
    if (this->getSigned() == false)
    {
        if (this->beSigned(a) == true)
            std::cout << "Bureaucrat " << a.getName() << " signed the robotomy form for " << this->getName() << " successfully!" << std::endl;
    }
    else
        std::cout << "Robotomy form \"" << this->getName() << "\" is already signed." << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    std::srand(time(0));
    if (this->getSigned() == true && executor.getGrade() <= this->getExecGrade())
    {
        std::cout << "** Rhhhh Rhhh Zssshhh **" << std::endl;
        if (std::rand() % 2 == 0)
            std::cout << executor.getName() << " executed a robotomy on " << this->getName() << " successfully!" << std::endl;
        else
            std::cout << executor.getName() << " failed a robotomy on " << this->getName() << "..." << std::endl;
    }
    else if (executor.getGrade() > this->getExecGrade())
        throw(AForm::GradeTooLowException());
    else
        throw(AForm::NoSignExecuteException());
}