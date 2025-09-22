/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin-deliere <valentin-deliere@student.42.fr>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-18 07:29:42 by valentin-deliere  #+#    #+#             */
/*   Updated: 2025-09-18 07:29:42 by valentin-deliere ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){

	std::cout << YELLOW + "\n/------Test 1 : creation of form with too high grade requirement ------/" + RESET << std::endl;
	try{
		Form	ip53("ip53", -50, 3);
	}
	catch (std::exception &e){
		std::cerr << RED + "Test 1 failed: " << e.what() << RESET << std::endl;
	}

	std::cout << YELLOW + "\n/------Test 2 : creation of form with too low grade requirement ------/" + RESET << std::endl;
	try{
		Form	ip53("ip53", 153, 3);
	}
	catch (std::exception &e){
		std::cerr << RED + "Test 2 failed: " << e.what() << RESET << std::endl;
	}

}