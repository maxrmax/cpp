#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
//#include <exception>

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeSign;
		const int			_gradeExec;

	public:
		AForm();
		AForm(const AForm& other);
		AForm(std::string name, int gradeSign, int gradeExec);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		const std::string	getName() const;
		bool				getSigned() const;
		int					getGradeExec() const;
		int					getGradeSign() const;

		void				beSigned(const Bureaucrat& bureaucrat);
		
		virtual void		execute(Bureaucrat const & executor) const = 0;
		
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class FormNotSignedException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream &output, AForm const &other);

#endif