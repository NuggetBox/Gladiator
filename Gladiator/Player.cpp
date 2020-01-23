#include "Player.h"

Player::Player()
{
	mySpeed = 250;
	mySwordSwingSpeed = 0.2f;
	myLayer = 10;
	myPosition = { 1000, 500 };

	float tempXOrigin = 0.5f;
	float tempYOrigin = 0.7f;
	float tempScale = 5;
	float tempRotation = 0;

	myNoArmor.loadFromFile("Textures/NoArmor.png");
	myNoHelmet.loadFromFile("Textures/NoHelmet.png");
	myBasicSword.loadFromFile("Textures/BasicSword.png");
	myNoArmorSwing.loadFromFile("Textures/NoArmorSwing.png");
	myNoHelmetSwing.loadFromFile("Textures/NoHelmetSwing.png");
	myBasicSwordSwing.loadFromFile("Textures/BasicSwordSwing.png");

	myBodyVisual = Visual(myNoArmor, tempRotation, { tempScale, tempScale }, { tempXOrigin * myNoArmor.getSize().x, tempYOrigin * myNoArmor.getSize().y });
	myHeadVisual = Visual(myNoHelmet, tempRotation, { tempScale, tempScale }, { tempXOrigin * myNoHelmet.getSize().x, tempYOrigin* myNoHelmet.getSize().y });
	myWeaponVisual = Visual(myBasicSword, tempRotation, { tempScale, tempScale }, { tempXOrigin * myBasicSword.getSize().x, tempYOrigin * myBasicSword.getSize().y });
}

Player::~Player()
{

}

void Player::Update(const float& someDelta)
{
	Vector2 tempMove;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		tempMove += Vector2(-mySpeed * someDelta, 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		tempMove += Vector2(mySpeed * someDelta, 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		tempMove += Vector2(0, -mySpeed * someDelta);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		tempMove += Vector2(0, mySpeed * someDelta);
	}

	if (!gameInfo::getOutOfBounds(myPosition + tempMove))
	{
		myPosition += tempMove;
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		myBodyVisual.PlayAnimationOnce(Animation(myNoArmorSwing, 3, mySwordSwingSpeed));
		myHeadVisual.PlayAnimationOnce(Animation(myNoHelmetSwing, 3, mySwordSwingSpeed));
		myWeaponVisual.PlayAnimationOnce(Animation(myBasicSwordSwing, 3, mySwordSwingSpeed));
	}

	Vector2 tempPlayerToMouse = Vector2(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y) - myPosition;
	float tempRotation = 90 + atan2(tempPlayerToMouse.y, tempPlayerToMouse.x) * 180 / M_PI;
	myBodyVisual.SetRotation(tempRotation);
	myHeadVisual.SetRotation(tempRotation);
	myWeaponVisual.SetRotation(tempRotation);

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