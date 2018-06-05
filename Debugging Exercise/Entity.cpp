#include "Entity.h"



Entity::Entity() :health(100), maxHealth(100) {}



Entity::~Entity() = default;

int Entity::attack()
{
	return 10;
}


void Entity::takeDamage(int damage)
{
	
}

bool Entity::isAlive()
{
	return health = 0;
}

int Entity::getHealth()
{
	return health;
}

void Entity::setHealth(int x)
{
	health += x;
	if (x = 0) { health = 0; }
}

