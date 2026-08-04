#include "serial.hpp"

int main(void)
{
	Data user{69, "420"};

    const uintptr_t raw = Serializer::serialize(&user);
    const Data* ptr = Serializer::deserialize(raw);

	std::cout << "Original pointer: " << &user << std::endl;
    std::cout << "Deserialized pointer: " << ptr << std::endl;
    if (ptr == &user) {
        std::cout << "Serialization and deserialization successful!" << std::endl;
        std::cout << "Data: int=" << ptr->integer << ", string=" << ptr->string << std::endl;
    } else {
        std::cerr << "Something went wrong!" << std::endl;
    }
}
