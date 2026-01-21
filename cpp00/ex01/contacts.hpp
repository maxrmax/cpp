#ifndef CONTACTS_HPP
# define CONTACTS_HPP
# include <iostream>
# include <algorithm>

class Contact
{
private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string number;
	std::string secret;

public:
	Contact();
	~Contact();

	int set_first_name(std::string first_name);
	std::string get_first_name();
	int set_last_name(std::string last_name);
	std::string get_last_name();
	int set_nickname(std::string nickname);
	std::string get_nickname();
	int set_number(std::string number);
	std::string get_number();
	int set_secret(std::string secret);
	std::string get_secret();
	void print_contact();
};

#endif