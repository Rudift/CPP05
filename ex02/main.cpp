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
#include <sstream>

void testBureaucratCreation() {
	std::cout << YELLOW << "\n========== TEST BUREAUCRAT CREATION ==========" << RESET << std::endl;
	
	// Test 1: Création normale
	std::cout << CYAN << "\nTest 1: Création normale" << RESET << std::endl;
	try {
		Bureaucrat bob("Bob", 75);
		std::cout << GREEN << "✓ " << bob << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << RED << "✗ Error: " << e.what() << RESET << std::endl;
	}

	// Test 2: Grade trop haut
	std::cout << CYAN << "\nTest 2: Grade trop haut (0)" << RESET << std::endl;
	try {
		Bureaucrat alice("Alice", 0);
		std::cout << RED << "✗ Should have thrown exception" << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << GREEN << "✓ Caught exception: " << e.what() << RESET << std::endl;
	}

	// Test 3: Grade trop bas
	std::cout << CYAN << "\nTest 3: Grade trop bas (151)" << RESET << std::endl;
	try {
		Bureaucrat charlie("Charlie", 151);
		std::cout << RED << "✗ Should have thrown exception" << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << GREEN << "✓ Caught exception: " << e.what() << RESET << std::endl;
	}

	// Test 4: Grades limites
	std::cout << CYAN << "\nTest 4: Grades limites (1 et 150)" << RESET << std::endl;
	try {
		Bureaucrat president("President", 1);
		Bureaucrat intern("Intern", 150);
		std::cout << GREEN << "✓ " << president << RESET << std::endl;
		std::cout << GREEN << "✓ " << intern << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << RED << "✗ Error: " << e.what() << RESET << std::endl;
	}
}

void testBureaucratGradeManipulation() {
	std::cout << YELLOW << "\n========== TEST BUREAUCRAT GRADE MANIPULATION ==========" << RESET << std::endl;
	
	// Test increment/decrement normal
	std::cout << CYAN << "\nTest 1: Increment/Decrement normal" << RESET << std::endl;
	try {
		Bureaucrat bob("Bob", 75);
		std::cout << "Initial: " << bob << std::endl;
		
		bob.incrementGrade(); // 75 -> 74
		std::cout << "After increment: " << bob << std::endl;
		
		bob.decrementGrade(); // 74 -> 75
		std::cout << GREEN << "✓ After decrement: " << bob << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << RED << "✗ Error: " << e.what() << RESET << std::endl;
	}

	// Test increment au delà de 1
	std::cout << CYAN << "\nTest 2: Increment au delà de 1" << RESET << std::endl;
	try {
		Bureaucrat president("President", 1);
		std::cout << "Before increment: " << president << std::endl;
		president.incrementGrade(); // Should throw
		std::cout << RED << "✗ Should have thrown exception" << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << GREEN << "✓ Caught exception: " << e.what() << RESET << std::endl;
	}

	// Test decrement au delà de 150
	std::cout << CYAN << "\nTest 3: Decrement au delà de 150" << RESET << std::endl;
	try {
		Bureaucrat intern("Intern", 150);
		std::cout << "Before decrement: " << intern << std::endl;
		intern.decrementGrade(); // Should throw
		std::cout << RED << "✗ Should have thrown exception" << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << GREEN << "✓ Caught exception: " << e.what() << RESET << std::endl;
	}
}

void testFormCreation() {
	std::cout << YELLOW << "\n========== TEST FORM CREATION ==========" << RESET << std::endl;
	
	// Test création normale de chaque formulaire
	std::cout << CYAN << "\nTest 1: Création normale des formulaires" << RESET << std::endl;
	try {
		ShrubberyCreationForm shrub("garden");
		RobotomyRequestForm robot("Bender");
		PresidentialPardonForm pardon("Arthur Dent");
		
		std::cout << GREEN << "✓ " << shrub << RESET << std::endl;
		std::cout << GREEN << "✓ " << robot << RESET << std::endl;
		std::cout << GREEN << "✓ " << pardon << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << RED << "✗ Error: " << e.what() << RESET << std::endl;
	}
}

void testFormSigning() {
	std::cout << YELLOW << "\n========== TEST FORM SIGNING ==========" << RESET << std::endl;
	
	// Test signature réussie
	std::cout << CYAN << "\nTest 1: Signature réussie" << RESET << std::endl;
	try {
		Bureaucrat president("President", 1);
		ShrubberyCreationForm shrub("home");
		
		std::cout << "Before signing: " << shrub << std::endl;
		president.signForm(shrub);
		std::cout << GREEN << "✓ After signing: " << shrub << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << RED << "✗ Error: " << e.what() << RESET << std::endl;
	}

	// Test signature échouée - grade trop bas
	std::cout << CYAN << "\nTest 2: Signature échouée - grade trop bas" << RESET << std::endl;
	try {
		Bureaucrat intern("Intern", 150);
		PresidentialPardonForm pardon("Someone");
		
		std::cout << "Bureaucrat: " << intern << std::endl;
		std::cout << "Form before: " << pardon << std::endl;
		intern.signForm(pardon);
		std::cout << "Form after: " << pardon << std::endl;
		if (!pardon.getSigned()) {
			std::cout << GREEN << "✓ Signature correctly failed (form not signed)" << RESET << std::endl;
		} else {
			std::cout << RED << "✗ Form should not have been signed" << RESET << std::endl;
		}
	} catch (std::exception &e) {
		std::cout << GREEN << "✓ Signature failed as expected: " << e.what() << RESET << std::endl;
	}

	// Test signature de chaque formulaire avec grade limite
	std::cout << CYAN << "\nTest 3: Signature avec grades limites" << RESET << std::endl;
	
	// ShrubberyCreationForm (sign: 145)
	try {
		Bureaucrat mid("Mid", 145);
		ShrubberyCreationForm shrub("test");
		mid.signForm(shrub);
		std::cout << GREEN << "✓ Shrub signed with grade 145" << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << RED << "✗ Error signing shrub: " << e.what() << RESET << std::endl;
	}
	
	// RobotomyRequestForm (sign: 72)
	try {
		Bureaucrat good("Good", 72);
		RobotomyRequestForm robot("Target");
		good.signForm(robot);
		std::cout << GREEN << "✓ Robot signed with grade 72" << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << RED << "✗ Error signing robot: " << e.what() << RESET << std::endl;
	}
	
	// PresidentialPardonForm (sign: 25)
	try {
		Bureaucrat high("High", 25);
		PresidentialPardonForm pardon("VIP");
		high.signForm(pardon);
		std::cout << GREEN << "✓ Pardon signed with grade 25" << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << RED << "✗ Error signing pardon: " << e.what() << RESET << std::endl;
	}
}

void testFormExecution() {
	std::cout << YELLOW << "\n========== TEST FORM EXECUTION ==========" << RESET << std::endl;
	
	// Test exécution réussie
	std::cout << CYAN << "\nTest 1: Exécution réussie" << RESET << std::endl;
	try {
		Bureaucrat president("President", 1);
		ShrubberyCreationForm shrub("test_tree");
		
		president.signForm(shrub);
		shrub.execute(president);
		std::cout << GREEN << "✓ Shrub executed successfully" << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << RED << "✗ Error: " << e.what() << RESET << std::endl;
	}

	// Test exécution sans signature
	std::cout << CYAN << "\nTest 2: Exécution sans signature" << RESET << std::endl;
	try {
		Bureaucrat president("President", 1);
		RobotomyRequestForm robot("Target");
		
		robot.execute(president); // Should fail - not signed
		std::cout << RED << "✗ Should have failed" << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << GREEN << "✓ Execution failed as expected: " << e.what() << RESET << std::endl;
	}

	// Test exécution avec grade insuffisant
	std::cout << CYAN << "\nTest 3: Exécution avec grade insuffisant" << RESET << std::endl;
	try {
		Bureaucrat signer("Signer", 1);
		Bureaucrat executor("Executor", 150);
		PresidentialPardonForm pardon("Someone");
		
		signer.signForm(pardon);
		pardon.execute(executor); // Should fail - grade too low for execution
		std::cout << RED << "✗ Should have failed" << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << GREEN << "✓ Execution failed as expected: " << e.what() << RESET << std::endl;
	}

	// Test exécution de tous les formulaires avec grades corrects
	std::cout << CYAN << "\nTest 4: Exécution avec grades corrects" << RESET << std::endl;
	
	// ShrubberyCreationForm (exec: 137)
	try {
		Bureaucrat exec_shrub("ExecShrub", 1);
		ShrubberyCreationForm shrub("garden");
		exec_shrub.signForm(shrub);
		shrub.execute(exec_shrub);
		std::cout << GREEN << "✓ Shrub executed" << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << RED << "✗ Error executing shrub: " << e.what() << RESET << std::endl;
	}
	
	// RobotomyRequestForm (exec: 45)
	try {
		Bureaucrat exec_robot("ExecRobot", 1);
		RobotomyRequestForm robot("Android");
		exec_robot.signForm(robot);
		robot.execute(exec_robot);
		std::cout << GREEN << "✓ Robot executed" << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << RED << "✗ Error executing robot: " << e.what() << RESET << std::endl;
	}
	
	// PresidentialPardonForm (exec: 5)
	try {
		Bureaucrat exec_pardon("ExecPardon", 1);
		PresidentialPardonForm pardon("Criminal");
		exec_pardon.signForm(pardon);
		pardon.execute(exec_pardon);
		std::cout << GREEN << "✓ Pardon executed" << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << RED << "✗ Error executing pardon: " << e.what() << RESET << std::endl;
	}
}

void testRobotomyRandomness() {
	std::cout << YELLOW << "\n========== TEST ROBOTOMY RANDOMNESS ==========" << RESET << std::endl;
	std::cout << CYAN << "\nExécution multiple du RobotomyRequestForm pour tester l'aléatoire:" << RESET << std::endl;
	
	try {
		Bureaucrat doctor("Doctor", 1);
		
		for (int i = 0; i < 10; i++) {
			std::ostringstream oss;
			oss << "Patient_" << (i + 1);
			RobotomyRequestForm robot(oss.str());
			doctor.signForm(robot);
			std::cout << "Attempt " << (i + 1) << ": ";
			robot.execute(doctor);
		}
	} catch (std::exception &e) {
		std::cout << RED << "✗ Error: " << e.what() << RESET << std::endl;
	}
}

void testCopyAndAssignment() {
	std::cout << YELLOW << "\n========== TEST COPY AND ASSIGNMENT ==========" << RESET << std::endl;
	
	// Test copie de Bureaucrat
	std::cout << CYAN << "\nTest 1: Copie de Bureaucrat" << RESET << std::endl;
	try {
		Bureaucrat original("Original", 50);
		Bureaucrat copy(original);
		Bureaucrat assigned("Temp", 100);
		assigned = original;
		
		std::cout << "Original: " << original << std::endl;
		std::cout << "Copy: " << copy << std::endl;
		std::cout << GREEN << "✓ Assigned: " << assigned << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << RED << "✗ Error: " << e.what() << RESET << std::endl;
	}

	// Test copie de formulaires
	std::cout << CYAN << "\nTest 2: Copie de formulaires" << RESET << std::endl;
	try {
		ShrubberyCreationForm original("original_target");
		ShrubberyCreationForm copy(original);
		
		std::cout << "Original: " << original << std::endl;
		std::cout << GREEN << "✓ Copy: " << copy << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << RED << "✗ Error: " << e.what() << RESET << std::endl;
	}
}

int main() {
	std::cout << BRIGHT_MAGENTA << "╔════════════════════════════════════════════════════════════════╗" << std::endl;
	std::cout << "║                    CPP05 EX02 - COMPLETE TESTS                ║" << std::endl;
	std::cout << "╚════════════════════════════════════════════════════════════════╝" << RESET << std::endl;

	testBureaucratCreation();
	testBureaucratGradeManipulation();
	testFormCreation();
	testFormSigning();
	testFormExecution();
	testRobotomyRandomness();
	testCopyAndAssignment();

	std::cout << BRIGHT_MAGENTA << "\n╔════════════════════════════════════════════════════════════════╗" << std::endl;
	std::cout << "║                         TESTS COMPLETED                       ║" << std::endl;
	std::cout << "╚════════════════════════════════════════════════════════════════╝" << RESET << std::endl;

	return 0;
}