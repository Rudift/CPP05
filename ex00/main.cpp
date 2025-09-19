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

int main(){

	std::cout << YELLOW + "\n/------Test 1 : creation of too low graded bureaucrat------/" + RESET << std::endl;
	try{
		Bureaucrat tim("Tim", 157);
	}
	catch (std::exception &e){
		std::cerr << RED + "Test 1 failed: " << e.what() << RESET << std::endl;
	}

	std::cout << YELLOW + "\n/------Test 1 : creation of too high graded bureaucrat------/" + RESET << std::endl;
	try{
		Bureaucrat tim("Tim", 0);
	}
	catch (std::exception &e){
		std::cerr << RED + "Test 2 failed: " << e.what() << RESET << std::endl;
	}
}