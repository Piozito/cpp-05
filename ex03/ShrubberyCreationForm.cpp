/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleixo- <aaleixo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 10:05:11 by aaleixo-          #+#    #+#             */
/*   Updated: 2025/12/09 09:46:01 by aaleixo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), _target(copy._target)
{
    *this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &a)
{
    if (this == &a)
        return *this;
    return *this;
}

void ShrubberyCreationForm::sign(Bureaucrat a)
{
    if (this->getSigned() == false)
    {
        if (this->beSigned(a) == true)
            std::cout << "Bureaucrat " << a.getName() << " signed the shrubbery creation form for " << this->getName() << " successfully!" << std::endl;
    }
    else
        std::cout << "shrubbery creation form \"" << this->getName() << "\" is already signed." << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (this->getSigned() == true && executor.getGrade() <= this->getExecGrade())
    {
        std::ofstream shrubFile(this->getName().append("_shrubbery").c_str());
        shrubFile << "                                                 ." << std::endl;
        shrubFile << "                                      .         ;  " << std::endl;
        shrubFile << "         .              .              ;%     ;;   " << std::endl;
        shrubFile << "           ,           ,                :;%  %;   " << std::endl;
        shrubFile << "            :         ;                   :;%;'     .," << std::endl;
        shrubFile << "   ,.        %;     %;            ;        %;'    ,;" << std::endl;
        shrubFile << "     ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
        shrubFile << "      %;       %;%;      ,  ;       %;  ;%;   ,%;' " << std::endl;
        shrubFile << "       ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
        shrubFile << "        `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
        shrubFile << "         `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
        shrubFile << "            `:%;.  :;bd%;          %;@%;'" << std::endl;
        shrubFile << "              `@%:.  :;%.         ;@@%;'" << std::endl;
        shrubFile << "                `@%.  `;@%.      ;@@%;" << std::endl;
        shrubFile << "                  `@%%. `@%%    ;@@%;" << std::endl;
        shrubFile << "                    ;@%. :@%%  %@@%;" << std::endl;
        shrubFile << "                      %@bd%%%bd%%:;" << std::endl;
        shrubFile << "                        #@%%%%%:;;" << std::endl;
        shrubFile << "                        %@@%%%::;" << std::endl;
        shrubFile << "                        %@@@%(o);  . '" << std::endl;
        shrubFile << "                        %@@@o%;:(.,'" << std::endl;
        shrubFile << "                    `.. %@@@o%::;" << std::endl;
        shrubFile << "                       `)@@@o%::;" << std::endl;
        shrubFile << "                        %@@(o)::;" << std::endl;
        shrubFile << "                       .%@@@@%::;" << std::endl;
        shrubFile << "                       ;%@@@@%::;." << std::endl;
        shrubFile << "                      ;%@@@@%%:;;;. " << std::endl;
        shrubFile << "                  ...;%@@@@@%%:;;;;,.." << std::endl;
        shrubFile.close();
        std::cout << executor.getName() << " created Shubbery " << this->getName() << " in the working directory with the name " << this->getName().append("_shrubbery") << std::endl;
    }
    else if (executor.getGrade() > this->getExecGrade())
        throw(AForm::GradeTooLowException());
    else
        throw(AForm::NoSignExecuteException());
}