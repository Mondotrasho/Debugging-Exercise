// A Debugging Exercise by Marc Chee (marcc@aie.edu.au)
// 18/12/2016

// Marines are trying to "de-bug" an area (haha . . . haha)
// However something's up with this code . . . figure out what's going wrong
// When you're finished, there should be no compiler errors or warnings
// The encounter should also run and finish correctly as per the rules in the comments

// In many cases there are differences between what's in otherwise identical sections
// for Marines and Zerglings. It's good to be able to tell what the differences are
// and why they might be important.

// What's efficient and inefficient? Why?
// What uses more memory and what doesn't? Why?

#include <iostream>
#include <vector>
#include "Marine.h"
#include "Zergling.h"

using std::vector;
using std::cout;
using std::endl;

// Is there a Marine Alive?
bool marineAlive(const vector<Marine> &squad)
{
	return !squad.empty();
}

// Is there a zergling Alive
bool zerglingAlive(const vector<Zergling> &swarm)
{
	return !swarm.empty();
}


int main()
{
	vector<Marine> squad;
	vector<Zergling> swarm;

	const int squadSize = 10;
	const int swarmSize = 20;

	// Set up the Squad and the Swarm at their initial sizes listed above

	Marine m;
	for (size_t i = 0; i < squadSize; i++)
	{
		squad.push_back(m);
	}

	for (size_t i = 0; i < swarmSize; i++)
	{
		Zergling z;
		swarm.push_back(z);
	}

	cout << "A squad of marines approaches a swarm of Zerglings and opens fire! The Zerglings charge!" << endl;
	// Attack each other until only one team is left alive
	while (marineAlive(squad) && zerglingAlive(swarm)) // If anyone is left alive to fight . . .
	{
		if (marineAlive(squad) && !swarm.empty()) // if there's at least one marine alive
		{
			for (size_t i = 0; i < squadSize; i++) // go through the squad
			{

				if (swarm.empty()) break;
				// each marine will attack the first zergling in the swarm
				cout << "A marine fires for " << squad[i].attack() << " damage. " << endl;

				const auto damage = squad[i].attack(); 
				swarm[0].takeDamage(damage); 
				if (!swarm[0].isAlive()) // if the zergling dies, it is removed from the swarm
				{
					cout << "The zergling target dies" << endl;
					swarm.erase(swarm.begin());
				}
			}
		}
		if (zerglingAlive(swarm) && !squad.empty()) // if there's at least one zergling alive
		{


			for (auto i = swarm.begin(); i != swarm.end(); ++i) // loop through zerglings //removed vector<Zergling>::iterator replaced with auto
			{
				if (squad.empty()) break;
				cout << "A zergling attacks for " << i->attack() << " damage." << endl;


				squad.begin()->takeDamage(i->attack());
				if (squad.begin()->isAlive())
				{

				}
				else
					squad.erase(squad.begin());
					cout << "The marine succumbs to his wounds." << endl;

			}
		}
	}

	// Once one team is completely eliminated, the fight ends and one team wins
	cout << "The fight is over. ";
	if (marineAlive(squad))
	{
		cout << "The Marines win." << endl;
	} else 
	{
		cout << "The Zerg win." << endl;
	}
}


