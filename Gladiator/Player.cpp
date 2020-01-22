#include "Player.h"
#include "Vector2.h"

Player::Player()
{
	mySpeed = 250;
}


Player::~Player()
{

}

void Player::Init(const sf::Texture& aTexture)
{
	mySprite.setTexture(aTexture);									//Här sätter vi texturen till vår Sprite
	//mySprite.setTextureRect(sf::IntRect(0, 0, 64, 64));			//Denna används om vi endast vill visa en del av texturen, eller om vi t.ex. vill animera den
	mySprite.setColor(sf::Color(255, 255, 255, 200));				//Här sätter vi färgen
	mySprite.setPosition(100, 25);									//Och här sätter vi positionen
}

bool Player::Update(const float& someDelta)							//Delta Time kommer in från App-klassen.
{
	Vector2 tempMove = Vector2(0, 0);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))				//Här kollar vi spelarens input, om spelaren trycker A så kommer vi flytta vår sprite i X-led.
	{
		tempMove += Vector2(-mySpeed * someDelta, 0);
		mySprite.move(-mySpeed * someDelta, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		tempMove += Vector2(mySpeed * someDelta, 0);
		mySprite.move(mySpeed * someDelta, 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		tempMove += Vector2(0, -mySpeed * someDelta);
		mySprite.move(0, -mySpeed * someDelta);						//Och här flyttar vi i Y-led istället.
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		tempMove += Vector2(0, mySpeed * someDelta);
		mySprite.move(0, mySpeed * someDelta);
	}

	return true;
}

void Player::Draw(sf::RenderWindow& aWindow)
{
	aWindow.draw(mySprite);											//Här ritar vi ut vår sprite, notera att det är en referens som vi tar emot.
}