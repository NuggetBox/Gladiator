#ifndef INPUT_HEADER
#define INPUT_HEADER

#include <SFML/Graphics.hpp>
#include "Vector2.h"

namespace in
{
	void update(sf::RenderWindow &aRenderWindow);

	Vector2 getMousePos();

	bool getWDown();
	bool getWPressed();
	bool getWReleased();
	bool getADown();
	bool getAPressed();
	bool getAReleased();
	bool getSDown();
	bool getSPressed();
	bool getSReleased();
	bool getDDown();
	bool getDPressed();
	bool getDReleased();
	bool getSpaceDown();
	bool getSpacePressed();
	bool getSpaceReleased();
	bool getM1Down();
	bool getM1Pressed();
	bool getM1Released();
	bool getM2Down();
	bool getM2Pressed();
	bool getM2Released();
}

#endif