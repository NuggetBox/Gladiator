#include "GUI.h"

GUI::GUI(sf::Texture aTexture, Vector2 aPosition, Vector2 aScale, sf::String aTextString, int aTextSize, Vector2 aTextPosition)
{
	Init(aTexture, aPosition, aScale, aTextString, aTextSize, aTextPosition);
}

GUI::GUI(sf::Texture aTexture, Vector2 aPosition, Vector2 aScale, sf::String aTextString, int aTextSize, Vector2 aTextPosition, bool aSelfDestruct)
{
	Init(aTexture, aPosition, aScale, aTextString, aTextSize, aTextPosition);

	mySelfDestruct = aSelfDestruct;
}

GUI::GUI(sf::Texture aTexture, Vector2 aPosition, Vector2 aScale, sf::String aTextString, int aTextSize, Vector2 aTextPosition, bool* aBoolToChange)
{
	Init(aTexture, aPosition, aScale, aTextString, aTextSize, aTextPosition);

	myBoolToChange = aBoolToChange;
	myHasEffect = true;
}

GUI::GUI(sf::Texture aTexture, Vector2 aPosition, Vector2 aScale, sf::String aTextString, int aTextSize, Vector2 aTextPosition, bool* aBoolToChange, bool aSelfDestruct)
{
	Init(aTexture, aPosition, aScale, aTextString, aTextSize, aTextPosition);

	myBoolToChange = aBoolToChange;
	myHasEffect = true;
	mySelfDestruct = aSelfDestruct;
}

GUI::GUI()
{
	myTexture.loadFromFile("Textures/gmod.png");
	myTextureRect = sf::IntRect(0, 0, myTexture.getSize().x, myTexture.getSize().y);
	myTextFont.loadFromFile("Gameplay.ttf");
}

void GUI::Init(sf::Texture aTexture, Vector2 aPosition, Vector2 aScale, sf::String aTextString, int aTextSize, Vector2 aTextPosition)
{
	myTexture = aTexture;
	myPosition = aPosition;
	myScale = aScale;
	myTextureRect = sf::IntRect(0, 0, myTexture.getSize().x, myTexture.getSize().y);
	myTextString = aTextString;
	myTextCharacterSize = aTextSize;
	myTextPosition = aTextPosition;
	myTextFont.loadFromFile("Gameplay.ttf");
}

GUI::~GUI()
{
}

void GUI::SetPosition(Vector2 aPosition)
{
	myPosition = aPosition;
}

void GUI::SetOrigin(Vector2 anOrigin)
{
	myOrigin = anOrigin;
}

void GUI::SetScale(Vector2 aScale)
{
	myScale = aScale;
}

void GUI::SetText(sf::String aTextString)
{
	myTextString = aTextString;
}

void GUI::Update(const float& someDelta)
{
	if (MouseAbove())
	{
		if (myHasEffect && in::getM1Released())
		{
			if (*myBoolToChange) { *myBoolToChange = false; }
			else { *myBoolToChange = true; }

			if (mySelfDestruct) { myIsDead = true; }

			myColor = sf::Color(255, 100, 100, 255);
		}
		else if (in::getM1Down())
		{
			myColor = sf::Color(255, 50, 50, 255);
		}
		else
		{
			myColor = sf::Color(255, 175, 175, 255);
		}
	}
	else
	{
		myColor = sf::Color(255, 255, 255, 255);
	}
}

bool GUI::MouseAbove()
{
	return in::getMousePos().x > myPosition.x&& in::getMousePos().x < myPosition.x + myTexture.getSize().x * myScale.x && in::getMousePos().y > myPosition.y && in::getMousePos().y < myPosition.y + myTexture.getSize().y * myScale.y;
}

void GUI::Draw(sf::RenderWindow& aWindow)
{
	sf::Sprite tempSprite;
	sf::Texture tempTexture = myTexture;
	tempSprite.setTexture(tempTexture);
	tempSprite.setRotation(myRotation);
	tempSprite.setOrigin(myOrigin.x, myOrigin.y);
	tempSprite.setScale(myScale.x, myScale.y);
	tempSprite.setPosition(myPosition.x, myPosition.y);
	tempSprite.setColor(myColor);
	tempSprite.setTextureRect(myTextureRect);
	aWindow.draw(tempSprite);

	sf::Text tempText;
	tempText.setCharacterSize(myTextCharacterSize);
	//tempText.setColor(myTextColor);
	tempText.setFillColor(myTextFillColor);
	tempText.setFont(myTextFont);
	tempText.setLetterSpacing(myTextLetterSpacing);
	tempText.setLineSpacing(myTextLineSpacing);
	tempText.setOrigin(myTextOrigin.x, myTextOrigin.y);
	tempText.setOutlineColor(myTextOutlineColor);
	tempText.setOutlineThickness(myTextOutlineThickness);
	tempText.setPosition(myTextPosition.x, myTextPosition.y);
	tempText.setRotation(myTextRotation);
	tempText.setScale(myTextScale.x, myTextScale.y);
	tempText.setString(myTextString);
	tempText.setStyle(myTextStyle);
	aWindow.draw(tempText);
}

int GUI::GetLayer()
{
	return myLayer;
}

bool GUI::GetDead()
{
	return myIsDead;
}