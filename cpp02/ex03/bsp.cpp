#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed AB_x = b.getX() - a.getX();
	Fixed AB_y = b.getY() - a.getY();
	Fixed AP_x = point.getX() - a.getX();
	Fixed AP_y = point.getY() - a.getY();
	Fixed cross1 = (AB_x * AP_y) - (AP_x * AB_y);

	Fixed BC_x = c.getX() - b.getX();
	Fixed BC_y = c.getY() - b.getY();
	Fixed BP_x = point.getX() - b.getX();
	Fixed BP_y = point.getY() - b.getY();
	Fixed cross2 = (BC_x * BP_y) - (BP_x * BC_y);

	Fixed AC_x = a.getX() - c.getX();
	Fixed AC_y = a.getY() - c.getY();
	Fixed CP_x = point.getX() - c.getX();
	Fixed CP_y = point.getY() - c.getY();
	Fixed cross3 = (AC_x * CP_y) - (CP_x * AC_y);

	if ((cross1 > 0 && cross2 > 0 && cross3 > 0) || (cross1 < 0 && cross2 < 0 && cross3 < 0))
		return  true;
	else
		return false;
}