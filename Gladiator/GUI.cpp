#include "GUI.h"

GUI::GUI(sf::Texture aTexture, Vector2 aPosition, Vector2 aScale, sf::String aTextString, int aTextSize, Vector2 aTextPosition)
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

GUI::GUI()
{
	myTexture.loadFromFile("Textures/gmod.png");
	myTextureRect = sf::IntRect(0, 0, myTexture.getSize().x, myTexture.getSize().y);
	myTextFont.loadFromFile("Gameplay.ttf");
}


GUI::~GUI()
{
}

void GUI::Update(const float& someDelta)
{

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