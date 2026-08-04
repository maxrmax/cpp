#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <random>


Base* generate()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dist(0, 2);

    switch (dist(gen))
    {
        case 0: return new A;
        case 1: return new B;
        default: return new C;
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A";
    }
    else if (dynamic_cast<B*>(p)) {
        std::cout << "B";
    }
    else if (dynamic_cast<C*>(p)) {
        std::cout << "C";
    }
    else {
        std::cout << "Unknown";
    }
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A";
        return ;
    }
    catch (std::bad_cast&) {}
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B";
        return ;
    }
    catch (std::bad_cast&) {}
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C";
        return ;
    }
    catch (std::bad_cast&) {}

    std::cout << "Unknown";
}

int main() {
    constexpr int NUM_OBJECTS = 10;
    std::vector<Base*> objects;

    objects.reserve(NUM_OBJECTS);
    for (int i = 0; i < NUM_OBJECTS; ++i)
	{
        objects.push_back(generate());
    }

    std::cout << "Identifying objects: Pointer - Reference\n";
    for (Base* obj : objects) {
        std::cout << "P: ";
        identify(obj);
        std::cout << "  -  R: ";
        identify(*obj);
		std::cout << std::endl;
    }

    for (const Base* obj : objects) {
        delete obj;
    }
    return 0;
}