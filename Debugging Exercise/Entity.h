#pragma once
class Entity
{
public:
	Entity();
	virtual ~Entity();

	int attack();
	virtual void takeDamage(int damage);
	bool isAlive();
	int getHealth(); //added a get health function
	void setHealth(int); //added a get health function
private:
	int health;
	int maxHealth;
//	friend class Marine;
//	friend class Zergling;
};

