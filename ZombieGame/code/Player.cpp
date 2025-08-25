#include "player.h"
#include "Map.h"
#include "TextureHolder.h"

Player::Player()
{
	m_Speed = START_SPEED;
	m_Health = START_HEALTH;
	m_MaxHealth = START_HEALTH;

	// Associate a texture with the sprite
	// !!Watch this space!!
	m_Sprite = Sprite(TextureHolder::GetTexture(
		"graphics/player_pistol.png"));

	// Set the origin of the sprite to the centre, 
	// for smooth rotation
	m_Sprite.setOrigin(18, 18);

	m_Room = 1; // set start room
	m_Gun = 0;

	// room 1 bounds
	room1.left = 1664;
	room1.width = 544;
	room1.top = 1664;
	room1.height = 544;

	// room 2 bounds
	room2.left = 2272;
	room2.width = 32*7;
	room2.top = 1664;
	room2.height = 1344-32*5;

	// room 3 bounds
	room3.left = 1664;
	room3.width = 544;
	room3.top = 2372;
	room3.height = 544;

	// room 4 bounds
	room4.left = 2784-224;
	room4.width = 640*2-32;
	room4.top = 1664;
	room4.height = 1344;

	// door 1 bounds
	door1.left = 1664+544;
	door1.width = 64;
	door1.top = 1664+32*7;
	door1.height = 64;

	// door 2 bounds
	door2.left = 1664 + 544;
	door2.width = 64;
	door2.top = 1664+27*32;
	door2.height = 64;

	// door 3 bounds
	door3.left = 2272+32*7;
	door3.width = 64;
	door3.top = 1664+16*32;
	door3.height = 64*3;

}

void Player::resetPlayerStats()
{
	m_Speed = START_SPEED;
	m_Health = START_HEALTH;
	m_MaxHealth = START_HEALTH;
}

void Player::spawn(IntRect arena, Vector2f resolution, int tileSize, Map map)
{
	// Place the player in the middle of the arena
	m_Position.x = 1772;
	m_Position.y = 1772;

	m_Hitbox.left = m_Position.x - 20;
	m_Hitbox.width = 40;
	m_Hitbox.top = m_Position.y - 20;
	m_Hitbox.height = 40;

	// Copy the details of the arena to the player's m_Arena
	m_Arena.left = arena.left;
	m_Arena.width = arena.width;
	m_Arena.top = arena.top;
	m_Arena.height = arena.height;

	// Remember how big the tiles are in this arena
	m_TileSize = tileSize;

	// Strore the resolution for future use
	m_Resolution.x = resolution.x;
	m_Resolution.y = resolution.y;

}

Time Player::getLastHitTime()
{
	return m_LastHit;
}

bool Player::hit(Time timeHit)
{
	if (timeHit.asMilliseconds() - m_LastHit.asMilliseconds() > 200)// 2 tenths of second
	{
		m_LastHit = timeHit;
		m_Health -= 10;
		return true;
	}
	else
	{
		return false;
	}

}

FloatRect Player::getPosition()
{
	return m_Sprite.getGlobalBounds();
}

Vector2f Player::getCenter()
{
	return m_Position;
}

Vector2f Player::getOrigin()
{
	return m_Sprite.getOrigin();
}

float Player::getRotation()
{
	return m_Sprite.getRotation();
}

Sprite Player::getSprite()
{
	return m_Sprite;
}

int Player::getHealth()
{
	return m_Health;
}

int Player::getRoom()
{
	return m_Room;
}

void Player::moveLeft()
{
	m_LeftPressed = true;
}

void Player::moveRight()
{
	m_RightPressed = true;
}

void Player::moveUp()
{
	m_UpPressed = true;
}

void Player::moveDown()
{
	m_DownPressed = true;
}

void Player::stopLeft()
{
	m_LeftPressed = false;
}

void Player::stopRight()
{
	m_RightPressed = false;
}

void Player::stopUp()
{
	m_UpPressed = false;
}

void Player::stopDown()
{
	m_DownPressed = false;
}

void Player::update(float elapsedTime, Vector2i mousePosition)
{
	

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
	

	if (m_UpPressed)
	{
		m_PositionLast = m_Position;
		m_Position.y -= m_Speed * elapsedTime;
	}

	if (!map.getBounds("room", 1).contains(m_Position.x, m_Position.y) && !map.getBounds("room", 2).contains(m_Position.x, m_Position.y) && !map.getBounds("room", 3).contains(m_Position.x, m_Position.y) && !map.getBounds("room", 4).contains(m_Position.x, m_Position.y)
		&& !map.getBounds("door", 1).contains(m_Position.x, m_Position.y) && !map.getBounds("door", 2).contains(m_Position.x, m_Position.y) && !map.getBounds("door", 3).contains(m_Position.x, m_Position.y))
	{
		m_Sprite.setPosition(m_PositionLast);
		m_Position = m_PositionLast;
	}

	if (m_DownPressed)
	{
		m_PositionLast = m_Position;
		m_Position.y += m_Speed * elapsedTime;
	}

	if (!map.getBounds("room", 1).contains(m_Position.x, m_Position.y) && 
		!map.getBounds("room", 2).contains(m_Position.x, m_Position.y) && 
		!map.getBounds("room", 3).contains(m_Position.x, m_Position.y) && 
		!map.getBounds("room", 4).contains(m_Position.x, m_Position.y) && 
		!map.getBounds("door", 1).contains(m_Position.x, m_Position.y) && 
		!map.getBounds("door", 2).contains(m_Position.x, m_Position.y) && 
		!map.getBounds("door", 3).contains(m_Position.x, m_Position.y))
	{
		m_Sprite.setPosition(m_PositionLast);
		m_Position = m_PositionLast;
	}

	if (m_RightPressed)
	{
		m_PositionLast = m_Position;
		m_Position.x += m_Speed * elapsedTime;
	}

	if (!map.getBounds("room", 1).contains(m_Position.x, m_Position.y) && !map.getBounds("room", 2).contains(m_Position.x, m_Position.y) && !map.getBounds("room", 3).contains(m_Position.x, m_Position.y) && !map.getBounds("room", 4).contains(m_Position.x, m_Position.y)
		&& !map.getBounds("door", 1).contains(m_Position.x, m_Position.y) && !map.getBounds("door", 2).contains(m_Position.x, m_Position.y) && !map.getBounds("door", 3).contains(m_Position.x, m_Position.y))
	{
		m_Sprite.setPosition(m_PositionLast);
		m_Position = m_PositionLast;
	}

	if (m_LeftPressed)
	{
		m_PositionLast = m_Position;
		m_Position.x -= m_Speed * elapsedTime;
	}

	if (!map.getBounds("room", 1).contains(m_Position.x, m_Position.y) && !map.getBounds("room", 2).contains(m_Position.x, m_Position.y) && !map.getBounds("room", 3).contains(m_Position.x, m_Position.y) && !map.getBounds("room", 4).contains(m_Position.x, m_Position.y)
		&& !map.getBounds("door", 1).contains(m_Position.x, m_Position.y) && !map.getBounds("door", 2).contains(m_Position.x, m_Position.y) && !map.getBounds("door", 3).contains(m_Position.x, m_Position.y))
	{
		m_Sprite.setPosition(m_PositionLast);
		m_Position = m_PositionLast;
	}

	m_Sprite.setPosition(m_Position);

	// Calculate the angle the player is facing
	float angle = (atan2(mousePosition.y - m_Resolution.y / 2,
		mousePosition.x - m_Resolution.x / 2)
		* 180) / 3.141;

	m_Sprite.setRotation(angle);
}

void Player::upgradeSpeed()
{
	// 20% speed upgrade
	m_Speed += (START_SPEED * .2);
}

void Player::upgradeHealth()
{
	// 20% max health upgrade
	m_MaxHealth += (START_HEALTH * .2);

}

void Player::increaseHealthLevel(int amount)
{
	m_Health += amount;

	// But not beyond the maximum
	if (m_Health > m_MaxHealth)
	{
		m_Health = m_MaxHealth;
	}
}

void Player::changeGun(String gun)
{
	if (gun == "shotgun")
	{
		m_Sprite = Sprite(TextureHolder::GetTexture(
			"graphics/player_shotgun.png"));
		m_Sprite.setOrigin(31, 18);
		m_Gun = 1;
	}
	else if (gun == "rifle")
	{
		m_Sprite = Sprite(TextureHolder::GetTexture(
			"graphics/player_rifle.png"));
		m_Sprite.setOrigin(27, 18);
		m_Gun = 2;
	}
	else
	{
		m_Sprite = Sprite(TextureHolder::GetTexture(
			"graphics/player_pistol.png"));
		m_Sprite.setOrigin(18, 18);
		m_Gun = 0;
	}
}

int Player::getGun()
{
	return m_Gun;
}

