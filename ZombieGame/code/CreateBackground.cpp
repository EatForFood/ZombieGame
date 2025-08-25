#include <SFML/Graphics.hpp>
#include "ZombieArena.h"

int createBackground(VertexArray& rVA, IntRect arena)
{
	// Anything we do to rVA we are actually doing to background (in the main function)

	// How big is each tile/texture
	const int TILE_SIZE = 32;
	const int TILE_TYPES = 3;
	const int VERTS_IN_QUAD = 4;

	int worldWidth = arena.width / TILE_SIZE;  // 20
	int worldHeight = arena.height / TILE_SIZE; // 20
	//worldHeight = 80;
	//worldWidth = 80;


	// What type of primitive are we using?
	rVA.setPrimitiveType(Quads);

	// Set the size of the vertex array
	rVA.resize(800 * 800 * VERTS_IN_QUAD);

	// Start at the beginning of the vertex array
	int currentVertex = 0;

	for (int w = 0; w < 400; w++) // create grass
	{
		for (int h = 0; h < 400; h++)
		{
			// Position each vertex in the current quad
			rVA[currentVertex + 0].position = Vector2f(w * TILE_SIZE, h * TILE_SIZE);
			rVA[currentVertex + 1].position = Vector2f((w * TILE_SIZE) + TILE_SIZE, h * TILE_SIZE);
			rVA[currentVertex + 2].position = Vector2f((w * TILE_SIZE) + TILE_SIZE, (h * TILE_SIZE) + TILE_SIZE);
			rVA[currentVertex + 3].position = Vector2f((w * TILE_SIZE), (h * TILE_SIZE) + TILE_SIZE);

			rVA[currentVertex + 0].texCoords = Vector2f(0, 0 + 5 * TILE_SIZE);
			rVA[currentVertex + 1].texCoords = Vector2f(TILE_SIZE, 0 + 5 * TILE_SIZE);
			rVA[currentVertex + 2].texCoords = Vector2f(TILE_SIZE, TILE_SIZE + 5 * TILE_SIZE);
			rVA[currentVertex + 3].texCoords = Vector2f(0, TILE_SIZE + 5 * TILE_SIZE);

			currentVertex = currentVertex + VERTS_IN_QUAD;
		}
	}


	for (int w = 50; w < 70; w++) // create room 1
	{
		for (int h = 50; h < 70; h++)
		{
			// Position each vertex in the current quad
			rVA[currentVertex + 0].position = Vector2f(w * TILE_SIZE, h * TILE_SIZE);
			rVA[currentVertex + 1].position = Vector2f((w * TILE_SIZE) + TILE_SIZE, h * TILE_SIZE);
			rVA[currentVertex + 2].position = Vector2f((w * TILE_SIZE) + TILE_SIZE, (h * TILE_SIZE) + TILE_SIZE);
			rVA[currentVertex + 3].position = Vector2f((w * TILE_SIZE), (h * TILE_SIZE) + TILE_SIZE);

			if (h >= 59 && h <= 60 && w == 69) // create opening in wall for door
			{
				rVA[currentVertex + 0].texCoords = Vector2f(0, 0 + 0 * TILE_SIZE);
				rVA[currentVertex + 1].texCoords = Vector2f(TILE_SIZE, 0 + 0 * TILE_SIZE);
				rVA[currentVertex + 2].texCoords = Vector2f(TILE_SIZE, TILE_SIZE + 0 * TILE_SIZE);
				rVA[currentVertex + 3].texCoords = Vector2f(0, TILE_SIZE + 0 * TILE_SIZE);
			}
			else if (h == 50 || h == 51 || h == 70 - 1 || w == 50 || w == 51 || w == 70 - 1) // create walls
			{
				rVA[currentVertex + 0].texCoords = Vector2f(0, 0 + 1 * TILE_SIZE);
				rVA[currentVertex + 1].texCoords = Vector2f(TILE_SIZE, 0 + 1 * TILE_SIZE);
				rVA[currentVertex + 2].texCoords = Vector2f(TILE_SIZE, TILE_SIZE + 1 * TILE_SIZE);
				rVA[currentVertex + 3].texCoords = Vector2f(0, TILE_SIZE + 1 * TILE_SIZE);
			}
			else // create floors
			{
				rVA[currentVertex + 0].texCoords = Vector2f(0, 0 + 0 * TILE_SIZE);
				rVA[currentVertex + 1].texCoords = Vector2f(TILE_SIZE, 0 + 0 * TILE_SIZE);
				rVA[currentVertex + 2].texCoords = Vector2f(TILE_SIZE, TILE_SIZE + 0 * TILE_SIZE);
				rVA[currentVertex + 3].texCoords = Vector2f(0, TILE_SIZE + 0 * TILE_SIZE);

			}

			// Position ready for the next for vertices
			currentVertex = currentVertex + VERTS_IN_QUAD;
		}
	}

	
	for (int w = 70; w < 79; w++) // create room 2
	{
		for (int h = 50; h <= 90; h++)
		{
			// Position each vertex in the current quad
			rVA[currentVertex + 0].position = Vector2f(w * TILE_SIZE, h * TILE_SIZE);
			rVA[currentVertex + 1].position = Vector2f((w * TILE_SIZE) + TILE_SIZE, h * TILE_SIZE);
			rVA[currentVertex + 2].position = Vector2f((w * TILE_SIZE) + TILE_SIZE, (h * TILE_SIZE) + TILE_SIZE);
			rVA[currentVertex + 3].position = Vector2f((w * TILE_SIZE), (h * TILE_SIZE) + TILE_SIZE);

			if (h >= 59 && h <= 60 && w == 70 || h >= 79 && h <= 80 && w == 70 || h >= 68 && h <= 72 && w == 78) // create opening in wall for door
			{
				rVA[currentVertex + 0].texCoords = Vector2f(0, 0 + 3 * TILE_SIZE);
				rVA[currentVertex + 1].texCoords = Vector2f(TILE_SIZE, 0 + 3 * TILE_SIZE);
				rVA[currentVertex + 2].texCoords = Vector2f(TILE_SIZE, TILE_SIZE + 3 * TILE_SIZE);
				rVA[currentVertex + 3].texCoords = Vector2f(0, TILE_SIZE + 3 * TILE_SIZE);
			}
	        else if (h == 50 || h == 51 || h == 90 || h == 89 || w == 78 || w == 70)
			{
				
				rVA[currentVertex + 0].texCoords = Vector2f(0, 0 + 1 * TILE_SIZE);
				rVA[currentVertex + 1].texCoords = Vector2f(TILE_SIZE, 0 + 1 * TILE_SIZE);
				rVA[currentVertex + 2].texCoords = Vector2f(TILE_SIZE, TILE_SIZE + 1 * TILE_SIZE);
				rVA[currentVertex + 3].texCoords = Vector2f(0, TILE_SIZE + 1 * TILE_SIZE);
			}
			else
			{
				
				rVA[currentVertex + 0].texCoords = Vector2f(0, 0 + 3 * TILE_SIZE);
				rVA[currentVertex + 1].texCoords = Vector2f(TILE_SIZE, 0 + 3 * TILE_SIZE);
				rVA[currentVertex + 2].texCoords = Vector2f(TILE_SIZE, TILE_SIZE + 3 * TILE_SIZE);
				rVA[currentVertex + 3].texCoords = Vector2f(0, TILE_SIZE + 3 * TILE_SIZE);

			}

			// Position ready for the next for vertices
			currentVertex = currentVertex + VERTS_IN_QUAD;
		}
	}

	for (int w = 50; w < 70; w++) // create room 3
	{
		for (int h = 70; h <= 90; h++)
		{
			// Position each vertex in the current quad
			rVA[currentVertex + 0].position = Vector2f(w * TILE_SIZE, h * TILE_SIZE);
			rVA[currentVertex + 1].position = Vector2f((w * TILE_SIZE) + TILE_SIZE, h * TILE_SIZE);
			rVA[currentVertex + 2].position = Vector2f((w * TILE_SIZE) + TILE_SIZE, (h * TILE_SIZE) + TILE_SIZE);
			rVA[currentVertex + 3].position = Vector2f((w * TILE_SIZE), (h * TILE_SIZE) + TILE_SIZE);

			if (h >= 79 && h <= 80 && w == 69 ) // create opening in wall for door
			{
				rVA[currentVertex + 0].texCoords = Vector2f(0, 0 + 0 * TILE_SIZE);
				rVA[currentVertex + 1].texCoords = Vector2f(TILE_SIZE, 0 + 0 * TILE_SIZE);
				rVA[currentVertex + 2].texCoords = Vector2f(TILE_SIZE, TILE_SIZE + 0 * TILE_SIZE);
				rVA[currentVertex + 3].texCoords = Vector2f(0, TILE_SIZE + 0 * TILE_SIZE);
			}
			else if (h == 70 || h == 90 || h == 89 || w == 50 || w == 51 || w == 69 || w == 70)
			{
				rVA[currentVertex + 0].texCoords = Vector2f(0, 0 + 1 * TILE_SIZE);
				rVA[currentVertex + 1].texCoords = Vector2f(TILE_SIZE, 0 + 1 * TILE_SIZE);
				rVA[currentVertex + 2].texCoords = Vector2f(TILE_SIZE, TILE_SIZE + 1 * TILE_SIZE);
				rVA[currentVertex + 3].texCoords = Vector2f(0, TILE_SIZE + 1 * TILE_SIZE);
			}
			else
			{
				rVA[currentVertex + 0].texCoords = Vector2f(0, 0 + 0 * TILE_SIZE);
				rVA[currentVertex + 1].texCoords = Vector2f(TILE_SIZE, 0 + 0 * TILE_SIZE);
				rVA[currentVertex + 2].texCoords = Vector2f(TILE_SIZE, TILE_SIZE + 0 * TILE_SIZE);
				rVA[currentVertex + 3].texCoords = Vector2f(0, TILE_SIZE + 0 * TILE_SIZE);

			}

			// Position ready for the next for vertices
			currentVertex = currentVertex + VERTS_IN_QUAD;
		}
	}

	for (int w = 79; w <= 120; w++) // create room 4
	{
		for (int h = 50; h <= 90; h++)
		{
			// Position each vertex in the current quad
			rVA[currentVertex + 0].position = Vector2f(w * TILE_SIZE, h * TILE_SIZE);
			rVA[currentVertex + 1].position = Vector2f((w * TILE_SIZE) + TILE_SIZE, h * TILE_SIZE);
			rVA[currentVertex + 2].position = Vector2f((w * TILE_SIZE) + TILE_SIZE, (h * TILE_SIZE) + TILE_SIZE);
			rVA[currentVertex + 3].position = Vector2f((w * TILE_SIZE), (h * TILE_SIZE) + TILE_SIZE);

			if (h >= 68 && h <= 72 && w == 79) // create opening in wall for door
			{
				rVA[currentVertex + 0].texCoords = Vector2f(0, 0 + 0 * TILE_SIZE);
				rVA[currentVertex + 1].texCoords = Vector2f(TILE_SIZE, 0 + 0 * TILE_SIZE);
				rVA[currentVertex + 2].texCoords = Vector2f(TILE_SIZE, TILE_SIZE + 0 * TILE_SIZE);
				rVA[currentVertex + 3].texCoords = Vector2f(0, TILE_SIZE + 0 * TILE_SIZE);
			}
			else if (h == 50 || h == 90 || h == 89 || w == 79 || w == 120 || w == 119 || h == 51)
			{
				rVA[currentVertex + 0].texCoords = Vector2f(0, 0 + 1 * TILE_SIZE);
				rVA[currentVertex + 1].texCoords = Vector2f(TILE_SIZE, 0 + 1 * TILE_SIZE);
				rVA[currentVertex + 2].texCoords = Vector2f(TILE_SIZE, TILE_SIZE + 1 * TILE_SIZE);
				rVA[currentVertex + 3].texCoords = Vector2f(0, TILE_SIZE + 1 * TILE_SIZE);
			}
			else
			{
				rVA[currentVertex + 0].texCoords = Vector2f(0, 0 + 0 * TILE_SIZE);
				rVA[currentVertex + 1].texCoords = Vector2f(TILE_SIZE, 0 + 0 * TILE_SIZE);
				rVA[currentVertex + 2].texCoords = Vector2f(TILE_SIZE, TILE_SIZE + 0 * TILE_SIZE);
				rVA[currentVertex + 3].texCoords = Vector2f(0, TILE_SIZE + 0 * TILE_SIZE);

			}

			// Position ready for the next for vertices
			currentVertex = currentVertex + VERTS_IN_QUAD;
		}
	}


	return TILE_SIZE;
}
