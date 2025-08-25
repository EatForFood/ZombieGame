#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Map
{
private:
	//room and door bounds
	IntRect room1;
	IntRect room2;
	IntRect room3;
	IntRect room4;

	//sprites for wall weapons
	Sprite shotgunWall;
	Sprite rifleWall;

	IntRect door1;
	Vector2f door1node1; // nodes for zombies
	Vector2f door1node2;

	IntRect door2;
	Vector2f door2node1;
	Vector2f door2node2;

	IntRect door3;
	Vector2f door3node1;
	Vector2f door3node2;

public:

	Map();

	void setArena(IntRect arena);

	IntRect getBounds(String type, int number);

	Vector2f node(int door, int num);

	void spawn();

	Sprite getSprite(String type);

	FloatRect getPosition();

};



