#include "Map.h"
#include "TextureHolder.h"
#include "random"

Map::Map()
{

	// room 1 bounds
	room1.left = 1664;
	room1.width = 544;
	room1.top = 1664;
	room1.height = 544;

	// room 2 bounds
	room2.left = 2272;
	room2.width = 224;
	room2.top = 1664;
	room2.height = 1184;

	// room 3 bounds
	room3.left = 1664;
	room3.width = 544;
	room3.top = 2272;
	room3.height = 544;

	// room 4 bounds
	room4.left = 2560;
	room4.width = 1248;
	room4.top = 1664;
	room4.height = 1188;

	// door 1 bounds
	door1.left = 2208;
	door1.width = 64;
	door1.top = 1888;
	door1.height = 64;

	door1node1.x = 2206;
	door1node1.y = 1920;
	door1node2.x = 2274;
	door1node2.y = 1920;

	// door 2 bounds
	door2.left = 2208;
	door2.width = 64;
	door2.top = 2528;
	door2.height = 64;

	door2node1.x = 2206;
	door2node1.y = 2560;
	door2node2.x = 2274;
	door2node2.y = 2560;

	// door 3 bounds
	door3.left = 2496;
	door3.width = 64;
	door3.top = 2176;
	door3.height = 160;

	door3node1.x = 2497;
	door3node1.y = 2220;
	door3node2.x = 2562 + 66;
	door3node2.y = 2220;

	rifleWall = Sprite(TextureHolder::GetTexture(
		"graphics/rifleWall.png"));

	std::random_device rd; // obtain a random number from hardware
	std::mt19937 gen(rd()); // seed the generator (A Mersenne Twister pseudo-random generator of 32-bit numbers with a state size of 19937 bits)
	std::uniform_int_distribution<> distr(room1.left, room1.left + room1.width+room2.width+room4.width);// define the range

	rifleWall.setPosition(distr(gen),room1.top - 64); // randomly set positions for wall weapons

	shotgunWall = Sprite(TextureHolder::GetTexture(
		"graphics/shotgunWall.png"));

	std::uniform_int_distribution<> distr1(room1.top,room1.top + room1.height + room3.height);// define the range

	shotgunWall.setPosition(room1.left - 64, distr1(gen));
}

IntRect Map::getBounds(String type, int number) //return bounds of room or doorway when called
{
	if (type == "room" && number == 1)
	{
		return room1;
	}

	if (type == "room" && number == 2)
	{
		return room2;
	}

	if (type == "room" && number == 3)
	{
		return room3;
	}

	if (type == "room" && number == 4)
	{
		return room4;
	}

	if (type == "door" && number == 1)
	{
		return door1;
	}

	if (type == "door" && number == 2)
	{
		return door2;
	}

	if (type == "door" && number == 3)
	{
		return door3;
	}
}

Vector2f Map::node(int door, int num) // return node position for zombie pathdinfing
{
	if (door == 1 && num == 1)
	{
		return door1node1;
	}

	if (door == 1 && num == 2)
	{
		return door1node2;
	}

	if (door == 2 && num == 1)
	{
		return door2node1;
	}

	if (door == 2 && num == 2)
	{
		return door2node2;
	}

	if (door == 3 && num == 1)
	{
		return door3node1;
	}

	if (door == 3 && num == 2)
	{
		return door3node2;
	}
}

Sprite Map::getSprite(String type) // return weapon sprite
{
	if (type == "shotgun")
	{
		return shotgunWall;
	}
	else if (type == "rifle")
	{
		return rifleWall;
	}
}

void Map::spawn()
{
	
}

void Map::setArena(IntRect arena)
{
	spawn();
}





