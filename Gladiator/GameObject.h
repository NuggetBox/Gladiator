#ifndef GAMEOBJECT_HEADER
#define GAMEOBJECT_HEADER

#include <SFML/Graphics.hpp>
#include "Vector2.h"

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

	virtual void Update() = 0;

	virtual void Draw();

protected:
	Vector2 myPosition;

};

#endif