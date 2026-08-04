#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("Usage: %s <input>", av[0]);
		return 1;
	}
	ScalarConverter::convert(av[1]);
}