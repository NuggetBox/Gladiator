#include "Enemy.h"


Enemy::Enemy()
{
	myIsPlayer = false;
	myHealth = 10;
	myDamage = 10;
	mySpeed = 120;
	myHitAngle = 0;
	myHitRange = 0;
	
	myPosition = Vector2(300 + rand() % 1500, 100 + rand() % 800);
	myLayer = 9;
	myHitRadius = 10;
	myIsCharacter = true;
	imFuckingDead = false;
	
	sf::Texture tempTex;
	tempTex.loadFromFile("Textures/gmod.png");
	myIsInvincible = false;
	//myVisual = Visual(tempTex, 0, Vector2(10, 10), Vector2(0, 0));

	myVisual = Visual(tempTex, -90, { 10, 10 }, { 0.5f * tempTex.getSize().x, 0.5f * tempTex.getSize().y });
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