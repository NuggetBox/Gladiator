#include "SecondBoss.h"

SecondBoss::SecondBoss() 
{
	myMove = Vector2(1,0);
	myIsPlayer = false;
	mySpeed = 300;
	myRotation = 0;
	myMaxHealth = 240;
	myHealth = myMaxHealth;
	myLayer = 11;
	myPlayer = gameInfo::getPlayer();
	myAttackOriginalValueTimer = 1.3f;
	myAttackTimer = myAttackOriginalValueTimer;
	myPosition = Vector2(960, 150);
	myHitRadius = 10;
	myTexture.loadFromFile("Textures/Boss/hastavagn.png");
	myVisual = Visual(myTexture, myRotation, { 0.3f, 0.3f }, { 0.5f * myTexture.getSize().x, 0.5f * myTexture.getSize().y });

	mySpears.push_back(new Spear(false, Vector2(1,0), myPosition));
}

SecondBoss::~SecondBoss() 
{
	myPlayer = NULL;
	delete(myPlayer);
	for (int i = 0; i < mySpears.size(); i++)
	{
		mySpears[i] = NULL;
		delete(mySpears[i]);
	}
}

void SecondBoss::Update(const float& someDelta) 
{
	myVisual.SetRotation(myRotation);
	if (myMove == Vector2(0,0)) 
	{
		myMove = Vector2(1,0);
	}

	if (myAttackTimer <= 0) 
	{
		mySpears.push_back(new Spear(false, (myPlayer->GetPosition() - myPosition), myPosition));
		myAttackTimer = myAttackOriginalValueTimer;
	}

	myAttackTimer -= 1 * someDelta;

	for (int i = 0; i < mySpears.size(); i++)
	{
		if (mySpears[i]->imFuckingDead == true)
		{
			mySpears.erase(mySpears.begin() + i);
		}
		else 
		{
			mySpears[i]->Update(someDelta);
		}
	}

	myMove.Normalize();
	myMove.Rotate(0.2f);
	myMove.Normalize();
	myRotation = myMove.Angle();
	myMove *= (mySpeed * someDelta);
	RequestMove(myMove);
}

void SecondBoss::Draw(sf::RenderWindow& aWindow) 
{
	myVisual.Draw(aWindow, myPosition);
	for (int i = 0; i < mySpears.size(); i++)
	{
		mySpears[i]->Draw(aWindow);
	}

}

void SecondBoss::Attack(const float& someDelta) 
{

}

void SecondBoss::Idle(const float& someDelta)
{

}

