#include "Player.h"

Player::Player() : Character()
{
	myIsPlayer = true;

	myHelmetLv = abilityInfo::getPlayerHelmetLevel();
	myArmorLv = abilityInfo::getPlayerArmorLevel();
	mySwordLv = abilityInfo::getPlayerSwordLevel();

	mySpeed = 250;
	mySwordSwingSpeed = 0.2f;
	myLayer = 10;
	myPosition = { 1000, 500 };
	myHitRadius = 10;
	myMaxHealth = 30 * (myArmorLv + myHelmetLv);
	myHealth = myMaxHealth;
	myDamage = 10 * (mySwordLv);
	myOriginalSpearTimer = 1.5f;
	mySpearTimer = myOriginalSpearTimer;
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

	myHealthBarTexture.loadFromFile("Textures/White.png");

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

	sf::Texture tempHelmet = myHelmetLv == 1 ? myNoHelmet : (myHelmetLv == 2 ? myIronHelmet : myDiamondHelmet );
	sf::Texture tempArmor = myArmorLv == 1 ? myNoArmor : (myArmorLv == 2 ? myIronArmor : myDiamondArmor);
	sf::Texture tempSword = mySwordLv == 1 ? myStoneSword : (mySwordLv == 2 ? myIronSword : myDiamondSword);

	myHeadVisual = Visual(tempHelmet, tempRotation, { tempScale, tempScale }, { tempXOrigin * tempHelmet.getSize().x, tempYOrigin * tempHelmet.getSize().y });
	myBodyVisual = Visual(tempArmor, tempRotation, { tempScale, tempScale }, { tempXOrigin * tempArmor.getSize().x, tempYOrigin * tempArmor.getSize().y });
	myWeaponVisual = Visual(tempSword, tempRotation, { tempScale, tempScale }, { tempXOrigin * tempSword.getSize().x, tempYOrigin * tempSword.getSize().y });
}

Player::~Player()
{
	for (int i = 0; i < mySpears.size(); i++)
	{
		mySpears[i] = NULL;
		delete(mySpears[i]);
	}
}

void Player::Update(const float& someDelta)
{

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
		}

		if (myDodgeTimer >= myDodgeTime)
		{
			myIsDodging = false;
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
		RequestHit(myIsPlayer);

		myHeadVisual.PlayAnimationOnce(Animation(myHelmetLv == 1 ? myNoHelmetSwing : (myHelmetLv == 2 ? myIronHelmetSwing : myDiamondHelmetSwing), 3, mySwordSwingSpeed));
		myBodyVisual.PlayAnimationOnce(Animation(myArmorLv == 1 ? myNoArmorSwing : (myArmorLv == 2 ? myIronArmorSwing : myDiamondArmorSwing), 3, mySwordSwingSpeed));
		myWeaponVisual.PlayAnimationOnce(Animation(mySwordLv == 1 ? myStoneSwordSwing : (mySwordLv == 2 ? myIronSwordSwing : myDiamondSwordSwing), 3, mySwordSwingSpeed));
	}

	// Throw spear
	if (in::getM2Pressed() && !myBodyVisual.GetAnimationOn() && mySpearTimer <= 0) 
	{
		mySpears.push_back(new Spear(true, (in::getMousePos() - myPosition), myPosition));
		myHeadVisual.PlayAnimationOnce(Animation(myHelmetLv == 1 ? myNoHelmetThrow : (myHelmetLv == 2 ? myIronHelmetThrow : myDiamondHelmetThrow), 3, 0.2f));
		myBodyVisual.PlayAnimationOnce(Animation(myArmorLv == 1 ? myNoArmorThrow : (myArmorLv == 2 ? myIronArmorThrow : myDiamondArmorThrow), 3, 0.2f));
		myWeaponVisual.PlayAnimationOnce(Animation(sf::Texture(), 1, 0.2f));
		mySpearTimer = myOriginalSpearTimer;
	}
	mySpearTimer -= 1 * someDelta;

#pragma region Rotate player

	Vector2 tempPlayerToMouse = in::getMousePos() - myPosition;
	float tempRotation = atan2(tempPlayerToMouse.y, tempPlayerToMouse.x) * 180 / M_PI;
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
	myHeadVisual.SetColor(sf::Color(myVisual.GetColor().r, myVisual.GetColor().g, myVisual.GetColor().b, myIsDodging ? myInvincibilityAlpha : 255));
	myBodyVisual.SetColor(sf::Color(myVisual.GetColor().r, myVisual.GetColor().g, myVisual.GetColor().b, myIsDodging ? myInvincibilityAlpha : 255));
	myWeaponVisual.SetColor(sf::Color(myVisual.GetColor().r, myVisual.GetColor().g, myVisual.GetColor().b, myIsDodging ? myInvincibilityAlpha : 255));
	myBodyVisual.Draw(aWindow, myPosition);
	myHeadVisual.Draw(aWindow, myPosition);
	myWeaponVisual.Draw(aWindow, myPosition);


	for (int i = 0; i < mySpears.size(); i++)
	{
		mySpears[i]->Draw(aWindow);
	}


	sf::Sprite tempSprite;
	sf::Texture tempTexture;

	// Red bar
	tempTexture = myHealthBarTexture;
	tempSprite.setTexture(tempTexture);
	tempSprite.setRotation(0);
	tempSprite.setOrigin({ myHealthBarTexture.getSize().x * 0.5f, myHealthBarTexture.getSize().y * 0.5f });
	tempSprite.setScale(40, 6);
	tempSprite.setPosition(aWindow.getSize().x * 0.5f, aWindow.getSize().y * 0.9f);
	tempSprite.setColor(sf::Color(255, 0, 0, 255));
	tempSprite.setTextureRect(sf::IntRect(0, 0, myHealthBarTexture.getSize().x, myHealthBarTexture.getSize().y));
	aWindow.draw(tempSprite);

	// Green bar
	tempTexture = myHealthBarTexture;
	tempSprite.setTexture(tempTexture);
	tempSprite.setRotation(0);
	tempSprite.setOrigin( { myHealthBarTexture.getSize().x * 0.5f, myHealthBarTexture.getSize().y * 0.5f } );
	tempSprite.setScale(40 * ((float)myHealth / (float)myMaxHealth), 6);
	tempSprite.setPosition(aWindow.getSize().x * 0.5f, aWindow.getSize().y * 0.9f);
	tempSprite.setColor(sf::Color(0, 255, 0, 255));
	tempSprite.setTextureRect(sf::IntRect(0, 0, myHealthBarTexture.getSize().x, myHealthBarTexture.getSize().y));
	aWindow.draw(tempSprite);
}