#include "Player.h"

Player::Player()
{
	mySpeed = 250;
	mySwordSwingSpeed = 0.2f;

	sf::Texture tempTexture;
	tempTexture.loadFromFile("Textures/NoArmor_NoHelmet_NoSword.png");
	myNoArmorNoHelmetNoSword = tempTexture;
	tempTexture.loadFromFile("Textures/NoArmor_NoHelmet_BasicSword.png");
	myNoArmorNoHelmetBasicSword = tempTexture;

	tempTexture.loadFromFile("Textures/NoArmor_NoHelmet_BasicSword_Swing.png");
	mySwingNoArmorNoHelmetBasicSword = Animation(tempTexture, 3, mySwordSwingSpeed);

	myAppearance = Appearance(myNoArmorNoHelmetBasicSword, 0, { 5, 5 }, { 0.5f * myNoArmorNoHelmetBasicSword.getSize().x, 0.5f * myNoArmorNoHelmetBasicSword.getSize().y });
}

Player::~Player()
{

}

void Player::Update(const float& someDelta)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		myPosition += Vector2(-mySpeed * someDelta, 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		myPosition += Vector2(mySpeed * someDelta, 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		myPosition += Vector2(0, -mySpeed * someDelta);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		myPosition += Vector2(0, mySpeed * someDelta);
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		myAppearance.PlayAnimationOnce(mySwingNoArmorNoHelmetBasicSword);
	}

	Vector2 tempMousePos = Vector2(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
	Vector2 tempPlayerToMouse = tempMousePos - myPosition;
	myAppearance.SetRotation(90 + atan2(tempPlayerToMouse.y, tempPlayerToMouse.x) * 180 / M_PI);

	myAppearance.Update(someDelta);
}