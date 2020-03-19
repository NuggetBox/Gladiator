#ifndef CHARACTER_HEADER
#define CHARACTER_HEADER

#include "GameObject.h"

class Character :
	public GameObject
{
public:
	Character();
	~Character();

private:
	int myHealth;
	
	float myHitAngle;
	float myHitRange;
};

#endif