/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin-deliere <valentin-deliere@student.42.fr>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-18 07:30:01 by valentin-deliere  #+#    #+#             */
/*   Updated: 2025-09-18 07:30:01 by valentin-deliere ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#  include <string>
#  include <iostream>
#  include "Colors.hpp"

// Forward declaration
class AForm;

    class Bureaucrat
    {
        private:
            const   std::string   _name;
            int                 _grade;
            
		public:
            //Canonical
			Bureaucrat(const std::string& name, int grade);
			Bureaucrat(const Bureaucrat& other);
			Bureaucrat& operator=(const Bureaucrat& other);
			~Bureaucrat();

            //Member fonctions
            const   std::string& getName() const;
            int     getGrade() const;
            void    incrementGrade();
            void    decrementGrade();
            void    signForm(AForm& form);

            //Exceptions classes
            class GradeTooHighException : public std::exception{
                const char* what() const throw();
            };
            class GradeTooLowException : public std::exception{
                const char* what() const throw();
            };
    };
	//Insertion overload
	std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj);
    
#endif