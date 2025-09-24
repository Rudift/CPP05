/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <vdeliere@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-22 14:05:49 by vdeliere          #+#    #+#             */
/*   Updated: 2025-09-22 14:05:49 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

//Default constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target){}

//Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), _target(other._target){}

//Assignement operator
RobotomyRequestForm&	 RobotomyRequestForm::operator=(const RobotomyRequestForm& other){
	if (this != &other){
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

//Destructor
RobotomyRequestForm::~RobotomyRequestForm(){}

//Member fonction
void	RobotomyRequestForm::execute(Bureaucrat const &executor) const{
	if(executor.getGrade() > this->getExecGrade()){
		throw GradeTooLowException();
	}else if(!this->getSigned()){
		throw NotSignedException();
	}else{
		robotomy();
	}
}

void	RobotomyRequestForm::robotomy() const{
	static bool	init = false;
	if (!init){
		srand(static_cast<unsigned int>(time(0)));
		init = true;
	}
	int r = rand() % 2;
	
	if (r ==0){
		std::cout
			<< YELLOW << _target
			<< GREEN << " has been robotomized successfully"
			<< RESET << std::endl;
	}else{
		std::cout
			<< RED << "Robotomy has failed" << RESET << std::endl;
	}

}