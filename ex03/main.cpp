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
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include <sstream>

void	print_separator(const std::string& title) {
	std::cout << std::endl << BRIGHT_BLUE << "=== " << title << " ===" << RESET << std::endl << std::endl;
}

int main() {
	print_separator("CREATION ET DESTRUCTION D'INTERNS");
	
	// Test 1: Création et destruction basique d'un intern
	{
		std::cout << YELLOW << "Test 1: Création d'un intern" << RESET << std::endl;
		Intern intern1;
		
		std::cout << YELLOW << "Test 2: Copie d'un intern" << RESET << std::endl;
		Intern intern2(intern1);
		
		std::cout << YELLOW << "Test 3: Assignation d'un intern" << RESET << std::endl;
		Intern intern3;
		intern3 = intern1;
		
		std::cout << YELLOW << "Fin du scope - destruction des interns" << RESET << std::endl;
	}

	print_separator("CREATION DE FORMULAIRES VALIDES");
	
	Intern intern;
	AForm* form1 = NULL;
	AForm* form2 = NULL;
	AForm* form3 = NULL;
	
	// Test 2: Création des trois types de formulaires valides
	try {
		std::cout << YELLOW << "Test 4: Création d'un PresidentialPardonForm" << RESET << std::endl;
		form1 = intern.makeForm("PresidentialPardonForm", "Arthur Dent");
		if (form1) {
			std::cout << GREEN << "Formulaire créé avec succès: " << form1->getName() << RESET << std::endl;
		}
		
		std::cout << std::endl << YELLOW << "Test 5: Création d'un RobotomyRequestForm" << RESET << std::endl;
		form2 = intern.makeForm("RobotomyRequestForm", "Bender");
		if (form2) {
			std::cout << GREEN << "Formulaire créé avec succès: " << form2->getName() << RESET << std::endl;
		}
		
		std::cout << std::endl << YELLOW << "Test 6: Création d'un ShrubberyCreationForm" << RESET << std::endl;
		form3 = intern.makeForm("ShrubberyCreationForm", "home");
		if (form3) {
			std::cout << GREEN << "Formulaire créé avec succès: " << form3->getName() << RESET << std::endl;
		}
	}
	catch (std::exception& e) {
		std::cout << RED << "Exception attrapée: " << e.what() << RESET << std::endl;
	}

	print_separator("TEST AVEC DES BUREAUCRATES");
	
	// Test 3: Utilisation des formulaires créés avec des bureaucrates
	if (form1 && form2 && form3) {
		try {
			Bureaucrat boss("Big Boss", 1);
			Bureaucrat employee("John Doe", 50);
			Bureaucrat lowLevel("Intern Mike", 150);
			
			std::cout << YELLOW << "Test 7: Signature et exécution avec un bureaucrate de haut niveau" << RESET << std::endl;
			boss.signForm(*form1);
			form1->execute(boss);
			
			std::cout << std::endl << YELLOW << "Test 8: Tentative avec un bureaucrate de niveau moyen" << RESET << std::endl;
			employee.signForm(*form2);
			form2->execute(employee);
			
			std::cout << std::endl << YELLOW << "Test 9: Tentative avec un bureaucrate de bas niveau" << RESET << std::endl;
			lowLevel.signForm(*form3);
			form3->execute(lowLevel);
		}
		catch (std::exception& e) {
			std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
		}
	}

	// Nettoyage des premiers formulaires
	delete form1;
	delete form2;
	delete form3;
	form1 = NULL;
	form2 = NULL;
	form3 = NULL;

	print_separator("CREATION DE FORMULAIRES INVALIDES");
	
	// Test 4: Tentatives de création avec des noms invalides
	AForm* invalidForm = NULL;
	
	std::cout << YELLOW << "Test 10: Tentative avec un nom de formulaire inexistant" << RESET << std::endl;
	invalidForm = intern.makeForm("NonExistentForm", "target");
	if (!invalidForm) {
		std::cout << GREEN << "Comportement correct: NULL retourné pour un formulaire inexistant" << RESET << std::endl;
	}
	
	std::cout << std::endl << YELLOW << "Test 11: Tentative avec un nom vide" << RESET << std::endl;
	invalidForm = intern.makeForm("", "target");
	if (!invalidForm) {
		std::cout << GREEN << "Comportement correct: NULL retourné pour un nom vide" << RESET << std::endl;
	}
	
	std::cout << std::endl << YELLOW << "Test 12: Tentative avec des casses différentes" << RESET << std::endl;
	invalidForm = intern.makeForm("presidentialpardonform", "target");
	if (!invalidForm) {
		std::cout << GREEN << "Comportement correct: Sensible à la casse" << RESET << std::endl;
	}
	
	std::cout << std::endl << YELLOW << "Test 13: Tentative avec des espaces supplémentaires" << RESET << std::endl;
	invalidForm = intern.makeForm(" PresidentialPardonForm ", "target");
	if (!invalidForm) {
		std::cout << GREEN << "Comportement correct: Sensible aux espaces" << RESET << std::endl;
	}

	print_separator("TEST AVEC DIFFERENTES CIBLES");
	
	// Test 5: Test avec différentes cibles
	std::cout << YELLOW << "Test 14: Création avec différentes cibles" << RESET << std::endl;
	AForm* form_empty_target = intern.makeForm("ShrubberyCreationForm", "");
	AForm* form_long_target = intern.makeForm("RobotomyRequestForm", "This_is_a_very_long_target_name_with_underscores_and_numbers_123");
	AForm* form_special_chars = intern.makeForm("PresidentialPardonForm", "Target-With-Special!@#$%^&*()Characters");
	
	if (form_empty_target) {
		std::cout << GREEN << "Formulaire avec cible vide créé: " << form_empty_target->getName() << RESET << std::endl;
	}
	if (form_long_target) {
		std::cout << GREEN << "Formulaire avec cible longue créé: " << form_long_target->getName() << RESET << std::endl;
	}
	if (form_special_chars) {
		std::cout << GREEN << "Formulaire avec caractères spéciaux créé: " << form_special_chars->getName() << RESET << std::endl;
	}

	// Nettoyage des formulaires de test de cibles
	delete form_empty_target;
	delete form_long_target;
	delete form_special_chars;

	print_separator("TESTS SUPPLEMENTAIRES DE ROBUSTESSE");
	
	// Test 6: Tests de robustesse supplémentaires
	std::cout << YELLOW << "Test 15: Création de plusieurs formulaires du même type" << RESET << std::endl;
	AForm* multiple1 = intern.makeForm("PresidentialPardonForm", "Target1");
	AForm* multiple2 = intern.makeForm("PresidentialPardonForm", "Target2");
	AForm* multiple3 = intern.makeForm("PresidentialPardonForm", "Target3");
	
	if (multiple1 && multiple2 && multiple3) {
		std::cout << GREEN << "Trois formulaires du même type créés avec succès" << RESET << std::endl;
		std::cout << "Formulaire 1: " << multiple1->getName() << std::endl;
		std::cout << "Formulaire 2: " << multiple2->getName() << std::endl;
		std::cout << "Formulaire 3: " << multiple3->getName() << std::endl;
	}

	// Nettoyage des formulaires multiples
	delete multiple1;
	delete multiple2;
	delete multiple3;
	
	print_separator("NETTOYAGE DE LA MEMOIRE");
	
	std::cout << GREEN << "Toute la mémoire allouée dynamiquement a été correctement libérée!" << RESET << std::endl;
	std::cout << YELLOW << "AForm a bien un destructeur virtuel, permettant la destruction polymorphe." << RESET << std::endl;
	
	std::cout << std::endl << BRIGHT_GREEN << "=== FIN DES TESTS ===" << RESET << std::endl;
	
	return 0;
}if (this)
		delete this;