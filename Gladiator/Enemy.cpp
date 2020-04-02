#include "Enemy.h"


Enemy::Enemy()
{
	myCharacterType = EnemyType;
	myHealth = 10;
	myDamage = 10;
	mySpeed = 120;
	myHitAngle = 0;
	myHitRange = 0;
	
	myPosition = Vector2(1000, 250);
	myLayer = 9;
	myHitRadius = 10;
	myIsCharacter = true;
	
	sf::Texture tempTex;
	tempTex.loadFromFile("Textures/gmod.png");

	myVisual = Visual(tempTex, 0, Vector2(10, 10), Vector2(0, 0));
}

void Enemy::Attack(bool aNear)
{

}

void Enemy::Idle()
{

}

Enemy::~Enemy()
{

}