#include "SecondBoss.h"

SecondBoss::SecondBoss() 
{
	myMove = Vector2(1,0);
	myCharacterType = CharacterType::BossType;
	myPhase = Phases::Chariot;
	mySpeed = 300;
	myRotation = 0;
	myMaxHealth = 240;
	myHealth = myMaxHealth;
	myLayer = 11;
	myRotateTimer = 0;
	myPlayer = gameInfo::getPlayer();
	myPosition = Vector2(960, 150);
	myHitRadius = 10;
	myTexture.loadFromFile("Textures/Boss/hastavagn.png");
	myVisual = Visual(myTexture, myRotation, { 0.3f, 0.3f }, { 0.5f * myTexture.getSize().x, 0.5f * myTexture.getSize().y });
}

SecondBoss::~SecondBoss() 
{
	myPlayer = NULL;
	delete(myPlayer);
}

void SecondBoss::Update(const float& someDelta) 
{
	myVisual.SetRotation(myRotation);

	if (myPhase == Phases::Chariot) 
	{
		myMove.Normalize();
		myMove.Rotate(0.2f);
		myMove.Normalize();
		myRotation = myMove.Angle();
		myMove *= (mySpeed * someDelta);
		RequestMove(myMove);		
	}
	else
	{

	}
}

void SecondBoss::Draw(sf::RenderWindow& aWindow) 
{
	myVisual.Draw(aWindow, myPosition);
}

void SecondBoss::Attack(const float& someDelta) 
{

}

void SecondBoss::Idle(const float& someDelta)
{

}