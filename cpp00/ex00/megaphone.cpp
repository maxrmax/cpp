#include <iostream>

int main(int ac, char **av)
{
	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOUSE *";
	int i = 1;
	while (av[i]) // loop over each input/word
	{
		int j = 0;
		while (av[i][j]) // over each char
		{
			std::cout << (char)std::toupper(av[i][j]);
			j++;
		}
		i++;
	}
	std::cout << std::endl;
}