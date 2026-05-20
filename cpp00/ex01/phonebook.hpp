#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "contacts.hpp"

# define PHONEBOOK_SIZE 8

class Phonebook
{
private:
	Contact contacts[PHONEBOOK_SIZE];
	size_t contact_count;
	size_t index;
public:
	Phonebook();
	~Phonebook();

	void add_contact();
	void search_contact();
};

#endif