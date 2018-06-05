#include "Marine.h"



Marine::Marine()
{
	setHealth(50);
}


Marine::~Marine()
{
}

//int Marine::attack()
//{
//	return 10;
//}

void Marine::takeDamage(int damage)
{
	int temp = 0;
	setHealth((temp -= damage));
	if (getHealth() < 0)
		setHealth(0);
}
