#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>
//#include <exception>

class AForm;

class Intern
{
	private:
		AForm* createShrubbery(const std::string target);
		AForm* createRobotomy(const std::string target);
		AForm* createPardon(const std::string target);

	public:
		Intern();									// default constructor
		~Intern();									// destructor
		Intern(const Intern& other);				//
		Intern& operator=(const Intern& other);		// copy assignment constructor

		AForm*	makeForm(std::string form, std::string target);


		class NotValidFormException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

#endif