#include "Point.hpp"

int main(void)
{
	Point a(0, 0);
	Point b(10, 0);
	Point c(5, 10);
	Point inside(5, 5);
	Point outside(15, 15);
	Point onVertex(0, 0); // Point exactly on vertex A
	Point onEdge(5, 0);	  // Point exactly on edge AB

	std::cout << "Inside: " << bsp(a, b, c, inside) << std::endl;
	std::cout << "Outside: " << bsp(a, b, c, outside) << std::endl;
	std::cout << "On vertex: " << bsp(a, b, c, onVertex) << std::endl;
	std::cout << "On edge: " << bsp(a, b, c, onEdge) << std::endl;

	return 0;
}
