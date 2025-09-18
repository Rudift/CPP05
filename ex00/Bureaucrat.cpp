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