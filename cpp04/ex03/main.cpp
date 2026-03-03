#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	std::cout << "Standard Test" << std::endl;
	{
		IMateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter *me = new Character("me");
		AMateria *tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter *bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}
	// additional tests:

	std::cout << "\nInventory Test: full inventory (5th equip should be ignored)" << std::endl;
	{
		ICharacter *hero = new Character("hero");
		IMateriaSource *src2 = new MateriaSource();
		src2->learnMateria(new Ice());
		src2->learnMateria(new Cure());
		hero->equip(src2->createMateria("ice"));
		hero->equip(src2->createMateria("ice"));
		hero->equip(src2->createMateria("cure"));
		hero->equip(src2->createMateria("cure"));
		AMateria *overflow = src2->createMateria("ice");
		hero->equip(overflow); // should do nothing
		hero->use(0, *hero);   // should still work
		delete overflow;
		delete hero;
		delete src2;
	}

	std::cout << "\nunequip and re-equip" << std::endl;
	{
		ICharacter *hero = new Character("hero");
		IMateriaSource *src2 = new MateriaSource();
		src2->learnMateria(new Ice());
		AMateria *ice1 = src2->createMateria("ice");
		hero->equip(ice1);
		hero->use(0, *hero);
		hero->unequip(0); // slot 0 free, ice1 on floor
		AMateria *ice2 = src2->createMateria("ice");
		hero->equip(ice2); // re-equip into slot 0
		hero->use(0, *hero);
		delete hero; // deletes ice2 (inventory) + ice1 (floor)
		delete src2;
	}

	std::cout << "\nuse/unequip out of bounds (nothing should happen)" << std::endl;
	{
		ICharacter *hero = new Character("hero");
		hero->use(-1, *hero);
		hero->use(4, *hero);
		hero->unequip(-1);
		hero->unequip(4);
		hero->use(0, *hero); // slot 0 is NULL, nothing happens
		delete hero;
	}

	std::cout << "\ncreateMateria unknown type returns 0" << std::endl;
	{
		IMateriaSource *src2 = new MateriaSource();
		src2->learnMateria(new Ice());
		AMateria *unknown = src2->createMateria("fire");
		if (!unknown)
			std::cout << "correctly returned NULL for unknown type" << std::endl;
		delete src2;
	}

	std::cout << "\ndeep copy of Character" << std::endl;
	{
		IMateriaSource *src2 = new MateriaSource();
		src2->learnMateria(new Ice());
		src2->learnMateria(new Cure());
		Character *a = new Character("a");
		a->equip(src2->createMateria("ice"));
		a->equip(src2->createMateria("cure"));
		Character *b = new Character(*a); // copy constructor
		a->use(0, *b);
		b->use(1, *a);
		delete a;	   // deletes a's materias, b's are independent
		b->use(0, *b); // should still work
		delete b;
		delete src2;
	}

	std::cout << "\nMateriaSource copy" << std::endl;
	{
		MateriaSource *src2 = new MateriaSource();
		src2->learnMateria(new Ice());
		MateriaSource *src3 = new MateriaSource(*src2); // copy constructor
		AMateria *m = src3->createMateria("ice");
		ICharacter *hero = new Character("hero");
		hero->equip(m);
		hero->use(0, *hero);
		delete hero;
		delete src2;
		delete src3;
	}
}
