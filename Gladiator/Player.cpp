#include "Player.h"

Player::Player()
{
	mySpeed = 250;
}


Player::~Player()
{

}

void Player::Init(const sf::Texture& aTexture)
{
	mySprite.setTexture(aTexture);									//H�r s�tter vi texturen till v�r Sprite
	//mySprite.setTextureRect(sf::IntRect(0, 0, 64, 64));			//Denna anv�nds om vi endast vill visa en del av texturen, eller om vi t.ex. vill animera den
	mySprite.setColor(sf::Color(255, 255, 255, 200));				//H�r s�tter vi f�rgen
	mySprite.setPosition(100, 25);									//Och h�r s�tter vi positionen
}

bool Player::Update(const float& someDelta)							//Delta Time kommer in fr�n App-klassen.
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))				//H�r kollar vi spelarens input, om spelaren trycker A s� kommer vi flytta v�r sprite i X-led.
	{
		mySprite.move(-mySpeed * someDelta, 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		mySprite.move(mySpeed * someDelta, 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		mySprite.move(0, -mySpeed * someDelta);						//Och h�r flyttar vi i Y-led ist�llet.
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		mySprite.move(0, mySpeed * someDelta);
	}

	return true;
}

void Player::Draw(sf::RenderWindow& aWindow)
{
	aWindow.draw(mySprite);											//H�r ritar vi ut v�r sprite, notera att det �r en referens som vi tar emot.
}