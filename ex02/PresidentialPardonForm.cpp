/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <vdeliere@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-22 14:06:30 by vdeliere          #+#    #+#             */
/*   Updated: 2025-09-22 14:06:30 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

//Default constructor
PresidentialPardonForm::PresidentialPardonForm(const std::string target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target){}

//Copy constructor
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& other)
	: AForm(other), _target(other._target){}

//Assignement operator
PresidentialPardonForm&	 PresidentialPardonForm::operator=(const PresidentialPardonForm& other){
	if (this != &other){
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

//Destructor
PresidentialPardonForm::~PresidentialPardonForm(){}

//Member fonctions
void	PresidentialPardonForm::execute(Bureaucrat const &executor) const{
	if(executor.getGrade() > this->getExecGrade()){
		throw GradeTooLowException();
	}else if(!this->getSigned()){
		throw NotSignedException();
	}else{
		std::cout
			<< YELLOW << _target
			<< BLUE << " has been pardoned by Zaphod Beeblebrox"
			<< RESET << std::endl;
	}
}