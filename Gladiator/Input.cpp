#include "Input.h"

namespace in
{
	namespace
	{
		bool myWWasDownLastFrame = false;
		bool myAWasDownLastFrame = false;
		bool mySWasDownLastFrame = false;
		bool myDWasDownLastFrame = false;
		bool mySpaceWasDownLastFrame = false;
		bool myM1WasDownLastFrame = false;
		bool myM2WasDownLastFrame = false;
	}

	void update()
	{
		if (getWDown()) { myWWasDownLastFrame = true; }
		else { myWWasDownLastFrame = false; }
		if (getADown()) { myAWasDownLastFrame = true; }
		else { myAWasDownLastFrame = false; }
		if (getSDown()) { mySWasDownLastFrame = true; }
		else { mySWasDownLastFrame = false; }
		if (getDDown()) { myDWasDownLastFrame = true; }
		else { myDWasDownLastFrame = false; }
		if (getSpaceDown()) { mySpaceWasDownLastFrame = true; }
		else { mySpaceWasDownLastFrame = false; }
		if (getM1Down()) { myM1WasDownLastFrame = true; }
		else { myM1WasDownLastFrame = false; }
		if (getM2Down()) { myM2WasDownLastFrame = true; }
		else { myM2WasDownLastFrame = false; }
	}

	bool getWDown() { return sf::Keyboard::isKeyPressed(sf::Keyboard::W); }
	bool getWPressed() { return (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !myWWasDownLastFrame); }
	bool getWReleased() { return (myWWasDownLastFrame && !sf::Keyboard::isKeyPressed(sf::Keyboard::W)); }
	bool getADown() { return sf::Keyboard::isKeyPressed(sf::Keyboard::A); }
	bool getAPressed() { return (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !myAWasDownLastFrame); }
	bool getAReleased() { return (myAWasDownLastFrame && !sf::Keyboard::isKeyPressed(sf::Keyboard::A)); }
	bool getSDown() { return sf::Keyboard::isKeyPressed(sf::Keyboard::S); }
	bool getSPressed() { return (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !mySWasDownLastFrame); }
	bool getSReleased() { return (mySWasDownLastFrame && !sf::Keyboard::isKeyPressed(sf::Keyboard::S)); }
	bool getDDown() { return sf::Keyboard::isKeyPressed(sf::Keyboard::D); }
	bool getDPressed() { return (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !myDWasDownLastFrame); }
	bool getDReleased() { return (myDWasDownLastFrame && !sf::Keyboard::isKeyPressed(sf::Keyboard::D)); }
	bool getSpaceDown() { return sf::Keyboard::isKeyPressed(sf::Keyboard::Space); }
	bool getSpacePressed() { return (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !mySpaceWasDownLastFrame); }
	bool getSpaceReleased() { return (mySpaceWasDownLastFrame && !sf::Keyboard::isKeyPressed(sf::Keyboard::Space)); }
	bool getM1Down() { return sf::Mouse::isButtonPressed(sf::Mouse::Left); }
	bool getM1Pressed() { return (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !myM1WasDownLastFrame); }
	bool getM1Released() { return (myM1WasDownLastFrame && !sf::Mouse::isButtonPressed(sf::Mouse::Left)); }
	bool getM2Down() { return sf::Mouse::isButtonPressed(sf::Mouse::Right); }
	bool getM2Pressed() { return (sf::Mouse::isButtonPressed(sf::Mouse::Right) && !myM2WasDownLastFrame); }
	bool getM2Released() { return (myM2WasDownLastFrame && !sf::Mouse::isButtonPressed(sf::Mouse::Right)); }
}

/*Key::Key(sf::Keyboard::Key aKey)
{
	myKey = aKey;
}

Key::~Key()
{

}

void Key::Update()
{
	if (GetDown())
	{
		myWasDownLastFrame = true;
	}
}

bool Key::GetDown()
{
	return sf::Keyboard::isKeyPressed(myKey);
}

bool Key::GetPressed()
{
	return (!myWasDownLastFrame && sf::Keyboard::isKeyPressed(myKey));
}

bool Key::GetReleased()
{
	return (myWasDownLastFrame && !sf::Keyboard::isKeyPressed(myKey));
}*/