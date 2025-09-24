/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <vdeliere@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-22 14:01:46 by vdeliere          #+#    #+#             */
/*   Updated: 2025-09-22 14:01:46 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

//Default constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target){}

//Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target){}

//Assignement operator
ShrubberyCreationForm&	 ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other){
	if (this != &other){
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

//Destructor
ShrubberyCreationForm::~ShrubberyCreationForm(){}

//Member fonctions
void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const{
	if(executor.getGrade() > this->getExecGrade()){
		throw AForm::GradeTooLowException();
	}else if(!this->getSigned()){
		throw AForm::NotSignedException();
	}else
		createTree();
}

void	ShrubberyCreationForm::createTree() const{
	std::string		file_name = _target + "_shrubbery";
	std::ofstream	file(file_name.c_str());

	if (file.is_open()){
		file << "       ^" << std::endl;
		file << "      ^^^" << std::endl;
		file << "     ^^^^^" << std::endl;
		file << "    ^^^^^^^" << std::endl;
		file << "   ^^^^^^^^^" << std::endl;
		file << "  ^^^^^^^^^^^" << std::endl;
		file << " ^^^^^^^^^^^^^" << std::endl;
		file << "^^^^^^^^^^^^^^^" << std::endl;
		file << "      |||" << std::endl;
		file << "      |||" << std::endl;
		file << "      |||" << std::endl;
		file.close();
	}else
		std::cerr << "impossible de creer ou ouvrir le fichier" << std::endl;
}