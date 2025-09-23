/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <vdeliere@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-22 14:06:16 by vdeliere          #+#    #+#             */
/*   Updated: 2025-09-22 14:06:16 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#  include "AForm.hpp"

class PresidentialPardonForm : public AForm{
	private:
		std::string	_target;
	
	public :
		//Canonical
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(PresidentialPardonForm& other);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& other);
		~PresidentialPardonForm();

		//Member fonctions
		void	execute(Bureaucrat const &executor) const;
};


#endif