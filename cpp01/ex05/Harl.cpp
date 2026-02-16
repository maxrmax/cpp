#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::debug(void)
{
	std::cout << "It is hard to not consume. It is easy to access." << std::endl;
}

void Harl::info(void)
{
	std::cout << "Once you realize you don't want to do something anymore, thats when it is the hardest to not do it anymore." << std::endl;
}

void Harl::warning(void)
{
	std::cout << "Don't force yourself to go against your brain. Trick it into compliance." << std::endl;
}

void Harl::error(void)
{
	std::cout << "You are not your body. You are not your brain. You are a pilot in this prison of flesh." << std::endl;
}

void Harl::complain(std::string level)
{
	void (Harl::*functions[])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error};

	std::string levels[] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*functions[i])();
			return;
		}
	}
}

/*

// different ways of implementing Harl::complain
// with and without pointer to member function
//

// array + loop
void Harl::complain(std::string level)
{
	void (Harl::*functions[])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*functions[i])();
			return;
		}
	}
}


// manual if/else with function pointer
void Harl::complain(std::string level)
{
	void (Harl::*func)(void) = NULL;

	if (level == "DEBUG") func = &Harl::debug;
	else if (level == "INFO") func = &Harl::info;
	else if (level == "WARNING") func = &Harl::warning;
	else if (level == "ERROR") func = &Harl::error;

	if (func)
		(this->*func)();
}


// ternary operator chain
void Harl::complain(std::string level)
{
	void (Harl::*func)(void) =
		level == "DEBUG" ? &Harl::debug :
		level == "INFO" ? &Harl::info :
		level == "WARNING" ? &Harl::warning :
		level == "ERROR" ? &Harl::error : NULL;

	if (func)
		(this->*func)();
}


// using struct for pairing
void Harl::complain(std::string level)
{
	struct LevelMap {
		std::string name;
		void (Harl::*func)(void);
	};

	LevelMap map[] = {
		{"DEBUG", &Harl::debug},
		{"INFO", &Harl::info},
		{"WARNING", &Harl::warning},
		{"ERROR", &Harl::error}
	};

	for (int i = 0; i < 4; i++)
	{
		if (map[i].name == level)
		{
			(this->*map[i].func)();
			return;
		}
	}
}


// switch with enum conversion
void Harl::complain(std::string level)
{
	void (Harl::*functions[])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			switch (i)
			{
				case 0: (this->*functions[0])(); break;
				case 1: (this->*functions[1])(); break;
				case 2: (this->*functions[2])(); break;
				case 3: (this->*functions[3])(); break;
			}
			return;
		}
	}
}


// separate function pointer variable
void Harl::complain(std::string level)
{
	typedef void (Harl::*HarlFunc)(void);
	HarlFunc functions[] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };

	for (int i = 0; i < 4; i++)
		if (levels[i] == level)
			(this->*functions[i])();
}
*/
