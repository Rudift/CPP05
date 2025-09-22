/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <vdeliere@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-19 13:35:02 by vdeliere          #+#    #+#             */
/*   Updated: 2025-09-19 13:35:02 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
#include "Colors.hpp"

// Forward declaration
class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;

	public:
		//Canonical
		Form(const std::string name, const int signGrade, const int execGrade);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		//Getters
		const std::string	getName()const;
		bool				getSigned()const;
		int			getSignGrade()const;
		int			getExecGrade()const;

		//Member fonctions
		void	beSigned(Bureaucrat& bureaucrat);

		//Exception classes
		class GradeTooHighException : public std::exception{
			const char* what() const throw();
		};
		class GradeTooLowException : public std::exception{
			const char* what() const throw();
		};

};

//Insertion overload
std::ostream&	operator<<(std::ostream& os, const Form& obj);

#endif