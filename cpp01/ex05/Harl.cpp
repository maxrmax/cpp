#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::debug ( void )
{
	std::cout << "It is hard to not consume. It is easy to access." << std::endl;
}

void Harl::info ( void )
{
	std::cout << "Once you realize you don't want to do something anymore, thats when it is the hardest to not do it anymore." << std::endl;
}

void Harl::warning ( void )
{
	std::cout << "Don't force yourself to go against your brain. Trick it into compliance." << std::endl;
}

void Harl::error ( void )
{
	std::cout << "You are not your body. You are not your brain. You are a pilot in this prison of flesh." << std::endl;
}

void Harl::complain( std::string level )
{
	if (level == "DEBUG")
		debug();
	else if (level == "INFO")
		info();
	else if (level == "WARNING")
		warning();
	else if (level == "ERROR")
		error();
}

// figure out how to do it without else if