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

	std::cout << YELLOW + "\n/------Test 3 : incrementation too high------/" + RESET << std::endl;
	try{
		Bureaucrat tim("Tim", 1);
		tim.incrementGrade();
	}
	catch (std::exception &e){
		std::cerr << RED + "Test 3 failed: " << e.what() << RESET << std::endl;
	}

	std::cout << YELLOW + "\n/------Test 4 : decrementation too low------/" + RESET << std::endl;
	try{
		Bureaucrat bob("Bob", 149);
		bob.decrementGrade();
		std::cout << bob << std::endl;
		bob.decrementGrade();

	}
	catch (std::exception &e){
		std::cerr << RED + "Test 4 failed: " << e.what() << RESET << std::endl;
	}

	std::cout << YELLOW + "\n/------Test 5 : Good case------/" + RESET << std::endl;
	try{
		Bureaucrat eddie("Eddie", 45);
		std::cout << eddie << std::endl;
		eddie.decrementGrade();
		std::cout << eddie << std::endl;
		eddie.incrementGrade();
		std::cout << eddie << std::endl;

	}
	catch (std::exception &e){
		std::cerr << RED + "Test 5 failed: " << e.what() << RESET << std::endl;
	}
	std::cout << GREEN << "Test 5 succeed !" << std::endl;
}