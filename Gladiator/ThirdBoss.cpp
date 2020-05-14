#include "ThirdBoss.h"

ThirdBoss::ThirdBoss()
{
	myCharacterType = CharacterType::BossType;
	myMaxHealth = 100;
	myHealth = myMaxHealth;
	myPlayer = gameInfo::getPlayer();
	mySpeed = 150;
	myPosition = Vector2(800, 500);
	myLayer = 12;
	myTexture.loadFromFile("Textures/Boss/lion.png");
	//myVisual = Visual(myTexture, myRotation, myScale, myOrigin);
	myVisual = Visual(myTexture, 0, { 5, 5 }, { 0.5f * myTexture.getSize().x, 0.5f * myTexture.getSize().y });
	myHitRadius = 30;
	myIsInvincible = true;
}

ThirdBoss::~ThirdBoss()
{
	delete(myPlayer);
	myPlayer = NULL;
}

void ThirdBoss::Update(const float& someDelta) 
{

}

void ThirdBoss::Draw(sf::RenderWindow& aWindow)
{
	myVisual.Draw(aWindow, myPosition);
}
