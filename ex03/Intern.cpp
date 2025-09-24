/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <vdeliere@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-24 12:41:05 by vdeliere          #+#    #+#             */
/*   Updated: 2025-09-24 12:41:05 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

//Default constructor
Intern::Intern(){
	std::cout << GREEN <<"An intern is hired" << RESET << std::endl;
}

//Copy constructor
Intern::Intern(const Intern& other){
	(void)other;
}

//Assignement operator
Intern&	Intern::operator=(const Intern& other){
	(void)other;
	return (*this);
}

//Destructor
Intern::~Intern(){
	std::cout << RED <<"The boss threw an intern throught the window" << RESET << std::endl;
}

//Member fonctions
AForm*	Intern::makeForm(std::string name, std::string target){
	std::string	form_names[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	int	i = 0;
	while (i < 3){
		if (form_names[i] == name){
			std::cout << CYAN << "Intern creates " << YELLOW << name << RESET << std::endl;
			break;
		}
		i++;
	}
	switch (i){
		case 0 : {
			AForm* form = new PresidentialPardonForm(target);
			return (form);
		}
		case 1 : {
			AForm* form = new RobotomyRequestForm(target);
			return (form);
		}
		case 2 : {
			AForm* form = new ShrubberyCreationForm(target);
			return (form);
		}
		default :
			std::cout << RED << "The intern can't make a " << YELLOW << name << RESET << std::endl;
			return (NULL);
	}
}