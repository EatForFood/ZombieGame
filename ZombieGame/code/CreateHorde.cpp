#include "ZombieArena.h"
#include "Zombie.h"
#include "Map.h"

Zombie* createHorde(int numZombies, IntRect arena, Map map, float difficulty)
{
	Zombie* zombies = new Zombie[numZombies];

	int maxY = arena.top + arena.height;
	int minY = arena.top + 32;
	int maxX = arena.left + arena.width;
	int minX = arena.left + 32;

	for (int i = 0; i < numZombies; i++)
	{

		// Which side should the zombie spawn
		srand((int)time(0) * i);
		int side = (rand() % 4);
		float x, y;

		switch (side)
		{
		case 0:
			// left
			x = minX;
			y = (rand() % maxY) + minY;
			break;

		case 1:
			// right
			x = maxX;
			y = (rand() % maxY) + minY;
			break;

		case 2:
			// top
			x = (rand() % maxX) + minX;
			y = minY;
			break;

		case 3:
			// bottom
			x = (rand() % maxX) + minX;
			y = maxY;
			break;
		}

		// Bloater, crawler or runner
		srand((int)time(0) * i * 2);
		int type = (rand() % 3);

		// Spawn the new zombie into the array
		zombies[i].spawn(x, y, type, i, map, difficulty);

	}
	return zombies;
}