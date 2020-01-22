#include "Player.h"

Player::Player()
{
	mySpeed = 250;
	mySwordSwingSpeed = 0.2f;
	myXOrigin = 0.5f;
	myYOrigin = 0.7f;
	myScale = 5;
	myLayer = 10;

	sf::Texture tempTexture;
	tempTexture.loadFromFile("Textures/NoArmor.png");
	myNoArmor = tempTexture;
	tempTexture.loadFromFile("Textures/NoHelmet.png");
	myNoHelmet = tempTexture;
	tempTexture.loadFromFile("Textures/BasicSword.png");
	myBasicSword = tempTexture;
	tempTexture.loadFromFile("Textures/NoArmorSwing.png");
	myNoArmorSwing = tempTexture;
	tempTexture.loadFromFile("Textures/NoHelmetSwing.png");
	myNoHelmetSwing = tempTexture;
	tempTexture.loadFromFile("Textures/BasicSwordSwing.png");
	myBasicSwordSwing = tempTexture;

	myBodyAppearance = Appearance(myNoArmor, 0, { myScale, myScale }, { myXOrigin * myNoArmor.getSize().x, myYOrigin * myNoArmor.getSize().y });
	myHeadAppearance = Appearance(myNoHelmet, 0, { myScale, myScale }, { myXOrigin * myNoHelmet.getSize().x, myYOrigin* myNoHelmet.getSize().y });
	myWeaponAppearance = Appearance(myBasicSword, 0, { myScale, myScale }, { myXOrigin * myBasicSword.getSize().x, myYOrigin * myBasicSword.getSize().y });
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
		myBodyAppearance.PlayAnimationOnce(Animation(myNoArmorSwing, 3, mySwordSwingSpeed));
		myHeadAppearance.PlayAnimationOnce(Animation(myNoHelmetSwing, 3, mySwordSwingSpeed));
		myWeaponAppearance.PlayAnimationOnce(Animation(myBasicSwordSwing, 3, mySwordSwingSpeed));
	}

	Vector2 tempPlayerToMouse = Vector2(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y) - myPosition;
	float tempRotation = 90 + atan2(tempPlayerToMouse.y, tempPlayerToMouse.x) * 180 / M_PI;
	myBodyAppearance.SetRotation(tempRotation);
	myHeadAppearance.SetRotation(tempRotation);
	myWeaponAppearance.SetRotation(tempRotation);

	myBodyAppearance.Update(someDelta);
	myHeadAppearance.Update(someDelta);
	myWeaponAppearance.Update(someDelta);
}

void Player::Draw(sf::RenderWindow& aWindow)
{
	myBodyAppearance.Draw(aWindow, myPosition);
	myHeadAppearance.Draw(aWindow, myPosition);
	myWeaponAppearance.Draw(aWindow, myPosition);
}