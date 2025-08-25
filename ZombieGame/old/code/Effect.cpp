#include "Effect.h"
#include "TextureHolder.h"
using namespace sf;

Effect::Effect()
{
	// Store the type of this pickup
	//m_Type = type;

	// Associate the texture with the sprite
	/*
	if (m_Type == "bloodImpact")
	{
		m_Sprite = Sprite(TextureHolder::GetTexture(
			"graphics/bloodImpact.png"));

		// How much is pickup worth
		

	}
	else
	{
		m_Sprite = Sprite(TextureHolder::GetTexture(
			"graphics/ammo_pickup.png"));

		// How much is pickup worth
		
	}

	m_Sprite.setOrigin(25, 25);

	*/

	m_SecondsToLive = START_SECONDS_TO_LIVE;
	m_SecondsToWait = START_WAIT_TIME;
}

void Effect::setArena(IntRect arena)
{

	// Copy the details of the arena to the pickup's m_Arena
	m_Arena.left = arena.left + 50;
	m_Arena.width = arena.width - 50;
	m_Arena.top = arena.top + 50;
	m_Arena.height = arena.height - 50;

	//spawn();
}

void Effect::spawn(String type, float x, float y)
{

	if (type == "bloodImpact")
	{
		m_Sprite = Sprite(TextureHolder::GetTexture(
			"graphics/bloodImpact.png"));

		


	}
	else
	{
		m_Sprite = Sprite(TextureHolder::GetTexture(
			"graphics/bloodImpat.png"));

		

	}
	// Spawn on zombie


	// Not currently spawned
	//m_Spawned = false;
	m_SecondsSinceSpawn = 0;
	m_Spawned = true;

	m_Sprite.setPosition(x,y);
}

FloatRect Effect::getPosition()
{
	return m_Sprite.getGlobalBounds();
}

Sprite Effect::getSprite()
{
	return m_Sprite;
}

bool Effect::isSpawned()
{
	return m_Spawned;
}

int Effect::gotIt()
{
	m_Spawned = false;
	m_SecondsSinceDeSpawn = 0;
	return m_Value;
}

void Effect::update(float elapsedTime)
{
	if (m_Spawned)
	{
		m_SecondsSinceSpawn += elapsedTime;
	}
	else
	{
		m_SecondsSinceDeSpawn += elapsedTime;
	}


	// Do we need to hide a pickup?
	if (m_SecondsSinceSpawn > m_SecondsToLive && m_Spawned)
	{
		// Revove the pickup and put it somewhere else
		m_Spawned = false;
		m_SecondsSinceDeSpawn = 0;
	}



}

void Effect::upgrade()
{
	if (m_Type == "bloodImpact")
	{
		
	}
	else
	{
		
	}

	// Make them more frequent and last longer
	m_SecondsToLive += (START_SECONDS_TO_LIVE / 10);
	m_SecondsToWait -= (START_WAIT_TIME / 10);
}
