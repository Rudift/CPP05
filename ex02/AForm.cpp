/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <vdeliere@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-19 13:37:04 by vdeliere          #+#    #+#             */
/*   Updated: 2025-09-19 13:37:04 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

//Default constructor
AForm::AForm(const std::string name, const int signGrade, const int execGrade): _name(name), _signGrade(signGrade), _execGrade(execGrade){
	if (_signGrade < 1 || _execGrade < 1){
		throw GradeTooHighException();
	}else if (_signGrade > 150 || _execGrade > 150){
		throw GradeTooLowException();
	}else{
		_signed = false;
		std::cout
			<< "AForm "
			<< _name
			<< "is created"
			<< std::endl;
	}
	
}

//Copy constructor
AForm::AForm(const AForm& other) : _name(other._name), _signGrade(other._signGrade), _execGrade(other._execGrade){
	
}

//Assignement operator
AForm& AForm::operator=(const AForm& other){
	if (this != &other)
		_signed = other._signed;
	return(*this);
}

//Destructor
AForm::~AForm(){
	std::cout
		<< RED
		<< _name
		<< " AForm was burned"
		<< "\xF0\x9F\x94\xA5"
		<< RESET
		<< std::endl;
}

//Getters
const std::string	AForm::getName()const{
	return (_name);
}

bool	AForm::getSigned()const{
	return (_signed);
}

int			AForm::getSignGrade()const{
	return (_signGrade);
}

int			AForm::getExecGrade()const{
	return (_execGrade);
}

//Member fonctions
void	AForm::beSigned(Bureaucrat& bureaucrat){
	if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowException();
	else
		_signed = true;
}

//Exceptions
const char* AForm::GradeTooHighException::what() const throw(){
	return ("Grade too high");
}

const char* AForm::GradeTooLowException::what() const throw(){
	return ("Grade too low");
}

const char* AForm::NotSignedException::what() const throw(){
	return ("Form not signed");
}

//Insertion overload
std::ostream&	operator<<(std::ostream& os, const AForm& obj){
	os 	<< "AForm " << obj.getName() << "\n"
		<< "Grade required to sign: " << obj.getSignGrade() << "\n"
		<< "Grade required to execute: " << obj.getExecGrade() << "\n";
	if (obj.getSigned())
		os << GREEN + "Signed" + RESET;
	else
		os << RED + "Non signed" + RESET;
	return (os);
}
