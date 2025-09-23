/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <vdeliere@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-22 14:04:37 by vdeliere          #+#    #+#             */
/*   Updated: 2025-09-22 14:04:37 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#  include "AForm.hpp"

class	RobotomyRequestForm : public AForm{
	private :
		std::string	_target;

	public :
		//Canonical
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(RobotomyRequestForm& other);
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm();

		//Member fonctions
		void	execute(Bureaucrat const &executor) const;
		void	robotomy(Bureaucrat const &executor) const;

};

#endif