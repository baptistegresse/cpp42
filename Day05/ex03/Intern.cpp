#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <map>

// Définition des fonctions de création pour chaque type de formulaire
AForm *createShrubberyForm(const std::string &target) {
    return new ShrubberyCreationForm(target);
}

AForm *createRobotomyForm(const std::string &target) {
    return new RobotomyRequestForm(target);
}

AForm *createPresidentialPardonForm(const std::string &target) {
    return new PresidentialPardonForm(target);
}

// Utilisation d'un std::map pour associer les noms de formulaires aux pointeurs de fonction
std::map<std::string, AForm *(*)(const std::string &)> formCreators;

// Initialisation de la map dans le constructeur
Intern::Intern() {
    formCreators["shrubbery creation"] = createShrubberyForm;
    formCreators["robotomy request"] = createRobotomyForm;
    formCreators["presidential pardon"] = createPresidentialPardonForm;
}

Intern::Intern(const Intern &original) {
    *this = original;
}

Intern::~Intern() {}


Intern &Intern::operator=(const Intern &original) {
    (void)original;
    return *this;
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) {
    AForm *newForm = NULL;

    std::map<std::string, AForm *(*)(const std::string &)>::const_iterator it = formCreators.find(formName);
    if (it != formCreators.end()) {
        newForm = (it->second)(target);
        std::cout << "Intern creates " << formName << std::endl;
    } else {
        std::cout << "Intern does not recognize the form name: " << formName << std::endl;
    }

    return newForm;
}

