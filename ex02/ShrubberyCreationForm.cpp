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

//Default constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
	: AForm("ShrubberyCreationForm", 25, 5), _target(target){}

//Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& other)
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