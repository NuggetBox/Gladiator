#pragma once
#include "SFML/Graphics.hpp"
class GameObject
{
public:
	sf::Vector2f Position;
	virtual void Update();
	virtual void Draw();

	GameObject();
	virtual ~GameObject();
};

