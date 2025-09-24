/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <vdeliere@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-19 13:35:02 by vdeliere          #+#    #+#             */
/*   Updated: 2025-09-19 13:35:02 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
# define AForm_HPP

#include <string>
#include <iostream>
#include "Colors.hpp"

// Forward declaration
class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;

	public:
		//Canonical
		AForm(const std::string name, const int signGrade, const int execGrade);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		//Getters
		const std::string	getName()const;
		bool				getSigned()const;
		int			getSignGrade()const;
		int			getExecGrade()const;

		//Member fonctions
		void			beSigned(Bureaucrat& bureaucrat);
		virtual void	execute(Bureaucrat const &executor) const = 0;

		//Exception classes
		class GradeTooHighException : public std::exception{
			const char* what() const throw();
		};
		class GradeTooLowException : public std::exception{
			const char* what() const throw();
		};
		class NotSignedException : public std::exception{
			const char* what() const throw();
		};

};

//Insertion overload
std::ostream&	operator<<(std::ostream& os, const AForm& obj);

#endif