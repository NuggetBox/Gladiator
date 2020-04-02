#include "Player.h"

Player::Player() : Character()
{
	myCharacterType = PlayerType;

	mySpeed = 250;
	mySwordSwingSpeed = 0.2f;
	myLayer = 10;
	myPosition = { 1000, 500 };
	myHitRadius = 10;
	myMaxHealth = 30;
	myHealth = myMaxHealth;
	myDamage = 10;

	myDodgeTime = 0.1f;
	myDodgeInvincibilityTime = 0.08f;
	myDodgeTimer = 0;
	myDodgeSpeed = 1000;
	myIsDodging = false;
	myDodgeDirection = { 0, 0 };
	myIsInvincible = false;
	myInvincibilityAlpha = 100;
	imFuckingDead = false;

	float tempXOrigin = 0.5f;
	float tempYOrigin = 0.7f;
	float tempScale = 5;
	float tempRotation = 0;

	myDodgeSound.loadFromFile("Dodge.wav");

#pragma region Load textures
	myNoHelmetIdle.loadFromFile("Textures/Player/NoHelmetIdle.png");
	myIronHelmetIdle.loadFromFile("Textures/Player/IronHelmetIdle.png");
	myDiamondHelmetIdle.loadFromFile("Textures/Player/DiamondHelmetIdle.png");
	myNoArmorIdle.loadFromFile("Textures/Player/NoArmorIdle.png");
	myIronArmorIdle.loadFromFile("Textures/Player/IronArmorIdle.png");
	myDiamonArmorIdle.loadFromFile("Textures/Player/DiamondArmorIdle.png");
	myNoHelmet.loadFromFile("Textures/Player/NoHelmet.png");
	myIronHelmet.loadFromFile("Textures/Player/IronHelmet.png");
	myDiamondHelmet.loadFromFile("Textures/Player/DiamondHelmet.png");
	myNoArmor.loadFromFile("Textures/Player/NoArmor.png");
	myIronArmor.loadFromFile("Textures/Player/IronArmor.png");
	myDiamondArmor.loadFromFile("Textures/Player/DiamondArmor.png");
	myStoneSword.loadFromFile("Textures/Player/StoneSword.png");
	myIronSword.loadFromFile("Textures/Player/IronSword.png");
	myDiamondSword.loadFromFile("Textures/Player/DiamondSword.png");
	myNoHelmetSwing.loadFromFile("Textures/Player/NoHelmetSwing.png");
	myIronHelmetSwing.loadFromFile("Textures/Player/IronHelmetSwing.png");
	myDiamondHelmetSwing.loadFromFile("Textures/Player/DiamondHelmetSwing.png");
	myNoArmorSwing.loadFromFile("Textures/Player/NoArmorSwing.png");
	myIronArmorSwing.loadFromFile("Textures/Player/IronArmorSwing.png");
	myDiamondArmorSwing.loadFromFile("Textures/Player/DiamondArmorSwing.png");
	myStoneSwordSwing.loadFromFile("Textures/Player/StoneSwordSwing.png");
	myIronSwordSwing.loadFromFile("Textures/Player/IronSwordSwing.png");
	myDiamondSwordSwing.loadFromFile("Textures/Player/DiamondSwordSwing.png");
	myNoHelmetThrow.loadFromFile("Textures/Player/NoHelmetThrow.png");
	myIronHelmetThrow.loadFromFile("Textures/Player/IronHelmetThrow.png");
	myDiamondHelmetThrow.loadFromFile("Textures/Player/DiamondHelmetThrow.png");
	myNoArmorThrow.loadFromFile("Textures/Player/NoArmorThrow.png");
	myIronArmorThrow.loadFromFile("Textures/Player/IronArmorThrow.png");
	myDiamondArmorThrow.loadFromFile("Textures/Player/DiamondArmorThrow.png");
#pragma endregion

	myBodyVisual = Visual(myNoArmor, tempRotation, { tempScale, tempScale }, { tempXOrigin * myNoArmor.getSize().x, tempYOrigin * myNoArmor.getSize().y });
	myHeadVisual = Visual(myNoHelmet, tempRotation, { tempScale, tempScale }, { tempXOrigin * myNoHelmet.getSize().x, tempYOrigin * myNoHelmet.getSize().y });
	myWeaponVisual = Visual(myStoneSword, tempRotation, { tempScale, tempScale }, { tempXOrigin * myStoneSword.getSize().x, tempYOrigin * myStoneSword.getSize().y });
}

Player::~Player()
{

}

void Player::Update(const float& someDelta)
{

#pragma region Movement

	Vector2 tempMove;

	if (in::getWDown())
	{
		tempMove += Vector2(0, -1);
	}

	if (in::getADown())
	{
		tempMove += Vector2(-1, 0);
	}

	if (in::getSDown())
	{
		tempMove += Vector2(0, 1);
	}

	if (in::getDDown())
	{
		tempMove += Vector2(1, 0);
	}

	tempMove.Normalize();

	if (in::getSpacePressed() && !myIsDodging && tempMove != Vector2(0,0))
	{
		myIsDodging = true;
		myDodgeTimer = 0;
		myDodgeDirection = tempMove;
		myIsInvincible = true;
		myHeadVisual.SetColor(sf::Color(255, 255, 255, 100));
		myBodyVisual.SetColor(sf::Color(255, 255, 255, 100));
		myWeaponVisual.SetColor(sf::Color(255, 255, 255, 100));

		mySound.setBuffer(myDodgeSound);
		mySound.play();
	}

	if (myIsDodging)
	{
		tempMove = myDodgeDirection * myDodgeSpeed * someDelta;

		myDodgeTimer += someDelta;

		if (myDodgeTimer >= myDodgeInvincibilityTime)
		{
			myIsInvincible = false;
			myHeadVisual.SetColor(sf::Color(255, 255, 255, 255));
			myBodyVisual.SetColor(sf::Color(255, 255, 255, 255));
			myWeaponVisual.SetColor(sf::Color(255, 255, 255, 255));
		}

		if (myDodgeTimer >= myDodgeTime)
		{
			myIsDodging = false;
			myHeadVisual.SetColor(sf::Color(255, 255, 255, 255));
			myBodyVisual.SetColor(sf::Color(255, 255, 255, 255));
			myWeaponVisual.SetColor(sf::Color(255, 255, 255, 255));
		}
	}
	else
	{
		tempMove *= (mySpeed * someDelta);
	}

	RequestMove(tempMove);

#pragma endregion

	// Swing
	if (in::getM1Pressed() && !myBodyVisual.GetAnimationOn())
	{
		RequestHit(PlayerType);

		myBodyVisual.PlayAnimationOnce(Animation(myNoArmorSwing, 3, mySwordSwingSpeed));
		myHeadVisual.PlayAnimationOnce(Animation(myNoHelmetSwing, 3, mySwordSwingSpeed));
		myWeaponVisual.PlayAnimationOnce(Animation(myStoneSwordSwing, 3, mySwordSwingSpeed));
	}

#pragma region Rotate player

	Vector2 tempPlayerToMouse = in::getMousePos() - myPosition;
	float tempRotation = 90 + atan2(tempPlayerToMouse.y, tempPlayerToMouse.x) * 180 / M_PI;
	myBodyVisual.SetRotation(tempRotation);
	myHeadVisual.SetRotation(tempRotation);
	myWeaponVisual.SetRotation(tempRotation);
	myVisual.SetRotation(tempRotation);

#pragma endregion

	myBodyVisual.Update(someDelta);
	myHeadVisual.Update(someDelta);
	myWeaponVisual.Update(someDelta);
}

void Player::Draw(sf::RenderWindow& aWindow)
{
	myBodyVisual.Draw(aWindow, myPosition);
	myHeadVisual.Draw(aWindow, myPosition);
	myWeaponVisual.Draw(aWindow, myPosition);
}