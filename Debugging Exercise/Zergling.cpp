#include "Zergling.h"



Zergling::Zergling()
{
	
}


Zergling::~Zergling() = default;


//int Zergling::attack()
//{
//	return 10;
//}

void Zergling::takeDamage(int damage)
{
	int temp = 0;
	setHealth((temp-= damage));
	if (getHealth() < 0)
		setHealth(0);
}
