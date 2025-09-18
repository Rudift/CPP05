/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin-deliere <valentin-deliere@student.42.fr>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-18 07:31:15 by valentin-deliere  #+#    #+#             */
/*   Updated: 2025-09-18 07:31:15 by valentin-deliere ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//Default constructor
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade){
	
	if (_grade < 1){

	}
	else if (_grade > 150){
		
	}
	std::cout
		<< _name
		<< " is hired in the Company"
		<< std::endl;
}

//Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade){
	
}

//Assignement operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){
	if (this != &other)
		_grade = other._grade;
	return (*this);
}

//Destructor
Bureaucrat::~Bureaucrat(){
	std::cout
		<< _name
		<< " is fired"
		<< std::endl;
}

//Getters
const std::string& Bureaucrat::getName() const{
	return (_name);
}

int Bureaucrat::getGrade() const{
	return (_grade);
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat obj){
	os << obj.getName() <<", bureaucrat grade " << obj.getGrade();
	return (os);
}
