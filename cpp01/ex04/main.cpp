#include <iostream>
#include <string>
#include <fstream>

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Usage: " << av[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	std::string filename = av[1];
	std::string s1 = av[2];
	if (s1.empty())
		return (std::cerr << "Error: s1 cannot be empty" << std::endl, 1);
	std::string s2 = av[3];

	// std::cout << filename << " " << s1 << " " << s2 << std::endl; /// debug

	std::ifstream istrm(filename.c_str(), std::ios::in); // c_str expected before c++11, explicit text mode
	if (!istrm.is_open())
		return (std::cout << "failed to open " << filename << '\n', 1);
	// read file to memory
	std::string content((std::istreambuf_iterator<char>(istrm)),
						std::istreambuf_iterator<char>());
	// then edit memory
	std::string result;
	size_t found, pos = 0;
	while ((found = content.find(s1, pos)) != std::string::npos)
	{
		result += content.substr(pos, found - pos);
		result += s2;
		pos = found + s1.length();
	}
	result += content.substr(pos);
	content = result;

	std::ofstream ostrm((filename + ".replace").c_str());
	if (!ostrm.is_open())
		return (std::cout << "failed to create " << filename + ".replace" << '\n', 1);
	ostrm << content;
	if (ostrm.fail())
		return (std::cerr << "Error: failed to write to output file" << std::endl, 1);
}

/*
test cases:

./Sed\ is\ for\ losers test.txt this that
./Sed\ is\ for\ losers test1.txt " " _ 
./Sed\ is\ for\ losers test2.txt this ""

*/
/*

Create a program that takes three parameters in the following order:
a filename and two strings, s1 and s2.

It must open the file <filename> and copy its content into a new file
<filename>.replace, replacing every occurrence of s1 with s2.

Using C file manipulation functions is forbidden and will be considered cheating.
All the member functions of the class std::string are allowed, except replace.
Use them wisely!
Of course, handle unexpected inputs and errors.
You must create and turn in your own tests to ensure that your program works as expected.

*/