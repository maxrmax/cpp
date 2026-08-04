#ifndef	SERIAL_HPP
# define SERIAL_HPP

#include <iostream>

struct Data {
    int         integer;
    std::string string;
};

class Serializer
{
public:
	Serializer(void) = delete;
	~Serializer(void) = delete;
    Serializer(const Serializer&) = delete;
    Serializer& operator=(const Serializer&) = delete;

	static uintptr_t	serialize(Data *ptr);
	static Data*		deserialize(uintptr_t raw);

};

# endif
