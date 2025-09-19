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
	_signed = false;
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

const std::string	Form::getName()const{
	return (_name);
}

bool	Form::getSigned()const{
	return (_signed);
}

const int			Form::getSignGrade()const{
	return (_signGrade);
}

const int			Form::getExecGrade()const{
	return (_execGrade);
}