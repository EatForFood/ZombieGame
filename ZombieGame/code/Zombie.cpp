#include "zombie.h"
#include "TextureHolder.h"
#include "Decal.h"
#include <cstdlib>
#include <ctime>
#include "Map.h"

using namespace std;


void Zombie::spawn(float startX, float startY, int type, int seed, Map map, float difficulty)
{

	switch (type)
	{
	case 0:
		// Bloater
		m_Sprite = Sprite(TextureHolder::GetTexture(
			"graphics/bloater.png"));

		m_Speed = 40 * difficulty; // zombies get faster and stronger as difficulty increases
		m_Health = 5 * difficulty;
		break;

	case 1:
		// Chaser
		m_Sprite = Sprite(TextureHolder::GetTexture(
			"graphics/chaser.png"));

		m_Speed = 70 * difficulty;
		m_Health = 1 * difficulty;
		break;

	case 2:
		// Crawler
		m_Sprite = Sprite(TextureHolder::GetTexture(
			"graphics/crawler.png"));

		m_Speed = 20 * difficulty;
		m_Health = 3 * difficulty;
		break;
	}

	// Modify the speed to make the zombie unique
	// Every zombie is unique. Create a speed modifier
	srand((int)time(0) * seed);
	// Somewhere between 80 an 100
	float modifier = (rand() % MAX_VARRIANCE) + OFFSET;
	// Express as a fraction of 1
	modifier /= 100; // Now equals between .7 and 1
	m_Speed *= modifier;

	m_Position.x = startX;
	m_Position.y = startY;

	m_Room = 1;

	m_Sprite.setOrigin(25, 25);
	m_Sprite.setPosition(m_Position);

	m_Spawned = false;
}

bool Zombie::hit()
{

	m_Health--;
	/*
	Effect effect("bloodImpact");
	effect.spawn(zGetX(),zGetY());
	*/

	if (m_Health < 0)
	{
		// dead
		m_Alive = false;
		m_Spawned = false;
		m_Sprite.setTexture(TextureHolder::GetTexture(
			"graphics/blood.png"));

		return true;
	}

	

	// injured but not dead yet
	return false;
}

bool Zombie::isAlive()
{
	return m_Alive;
}

bool Zombie::isSpawned()
{
	return m_Spawned;
}

void Zombie::setSpawned(bool spawned) // CRASHES
{
	if (spawned)
	{
		m_Spawned = true;
	}
	else
	{
		m_Spawned = false;
	}
}

FloatRect Zombie::getPosition()
{
	return m_Sprite.getGlobalBounds();
}


Sprite Zombie::getSprite()
{
	return m_Sprite;
}

void Zombie::update(float elapsedTime,
	Vector2f playerLocation, int playerRoom)
{
	float playerX = playerLocation.x;
	float playerY = playerLocation.y;

	int pRoom = playerRoom;

	// updates zombies room
	if (map.getBounds("room", 1).contains(m_Position.x, m_Position.y))
	{
		m_Room = 1;
	}
	else if (map.getBounds("room", 2).contains(m_Position.x, m_Position.y))
	{
		m_Room = 2;
	}
	else if (map.getBounds("room", 3).contains(m_Position.x, m_Position.y))
	{
		m_Room = 3;
	}
	else if (map.getBounds("room", 4).contains(m_Position.x, m_Position.y))
	{
		m_Room = 4;
	}

	if (m_Spawned)
	{
		if (m_Room == playerRoom) // move to player if in the same room
		{
			moveTo(playerLocation, elapsedTime);
		}

		if (m_Room == 1 && playerRoom != 1)
		{
			moveTo(map.node(1, 2), elapsedTime);
		}

		if (m_Room == 2 && playerRoom == 1)
		{
			moveTo(map.node(1, 1), elapsedTime);
		}

		if (m_Room == 2 && playerRoom == 4)
		{
			moveTo(map.node(3, 2), elapsedTime);
		}

		if (m_Room == 2 && playerRoom == 3)
		{
			moveTo(map.node(2, 1), elapsedTime);
		}

		if (m_Room == 3 && playerRoom != 3)
		{
			moveTo(map.node(2, 2), elapsedTime);
		}

		if (m_Room == 4 && playerRoom != 4)
		{
			moveTo(map.node(3, 1), elapsedTime);
		}
		
	}
	
}

void Zombie::moveTo(Vector2f position, float elapsedTime)
{
	// Update the zombie position variables
	if (position.x > m_Position.x)
	{
		m_Position.x = m_Position.x +
			m_Speed * elapsedTime;
	}

	if (position.y > m_Position.y)
	{
		m_Position.y = m_Position.y +
			m_Speed * elapsedTime;
	}

	if (position.x < m_Position.x)
	{
		m_Position.x = m_Position.x -
			m_Speed * elapsedTime;
	}

	if (position.y < m_Position.y)
	{
		m_Position.y = m_Position.y -
			m_Speed * elapsedTime;
	}

	// Move the sprite
	m_Sprite.setPosition(m_Position);

	// Face the sprite in the correct direction
	float angle = (atan2(position.y - m_Position.y,
		position.x - m_Position.x)
		* 180) / 3.141;

	m_Sprite.setRotation(angle);
}

float Zombie::zGetX()
{
	return m_Position.x;
}

float Zombie::zGetY()
{
	return m_Position.y;
}
