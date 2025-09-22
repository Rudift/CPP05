/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <vdeliere@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-19 13:37:04 by vdeliere          #+#    #+#             */
/*   Updated: 2025-09-19 13:37:04 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

//Default constructor
Form::Form(const std::string name, const int signGrade, const int execGrade): _name(name), _signGrade(signGrade), _execGrade(execGrade){
	if (_signGrade < 1 || _execGrade < 1){
		throw GradeTooHighException();
	}else if (_signGrade > 150 || _execGrade > 150){
		throw GradeTooLowException();
	}else{
		_signed = false;
		std::cout
			<< "Form "
			<< _name
			<< "is created"
			<< std::endl;
	}
	
}

//Copy constructor
Form::Form(const Form& other) : _name(other._name), _signGrade(other._signGrade), _execGrade(other._execGrade){

}

//Assignement operator
Form& Form::operator=(const Form& other){
	if (this != &other)
		_signed = other._signed;
	return(*this);
}

//Destructor
Form::~Form(){
	std::cout
		<< RED
		<< _name
		<< " formular was burned"
		<< "\xF0\x9F\x94\xA5"
		<< RESET
		<< std::endl;
}

//Getters
const std::string	Form::getName()const{
	return (_name);
}

bool	Form::getSigned()const{
	return (_signed);
}

int			Form::getSignGrade()const{
	return (_signGrade);
}

int			Form::getExecGrade()const{
	return (_execGrade);
}

//Exceptions
const char* Form::GradeTooHighException::what() const throw(){
	return ("Grade too high");
}

const char* Form::GradeTooLowException::what() const throw(){
	return ("Grade too low");
}

//Insertion overload
std::ostream&	operator<<(std::ostream& os, const Form& obj){
	os 	<< "Form " << obj.getName() << "\n"
		<< "Grade required to sign: " << obj.getSignGrade() << "\n"
		<< "Grade required to execute: " << obj.getExecGrade() << "\n";
	if (obj.getSigned())
		os << GREEN + "Signed" + RESET;
	else
		os << RED + "Non signed" + RESET;
	return (os);
}
