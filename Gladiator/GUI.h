#ifndef GUI_HEADER
#define GUI_HEADER

#include "Vector2.h"
#include "Input.h"

class GUI
{
public:
	GUI();
	~GUI();

	void Update(const float& someDelta);

	void Draw(sf::RenderWindow& aWindow);

	int GetLayer();

	Vector2 GetPosition();

private:
	bool* myBoolToChange;

	bool myImageVisible;
	bool myTextVisible;
	
	bool myIsClickable;

	int myLayer;

	sf::Texture myTexture;
	Vector2 myPosition;
	float myRotation;
	Vector2 myOrigin;
	Vector2 myScale;
	sf::Color myColor;
	sf::IntRect myTextureRect;

	sf::String myTextString;
	int myTextCharacterSize;
	sf::Font myTextFont;
	sf::Uint32 myTextStyle;
	sf::Color myTextFillColor;
	sf::Color myTextOutlineColor;
	float myTextOutlineThickness;
	float myTextLetterSpacing;
	float myTextLineSpacing;
	Vector2 myTextPosition;
	float myTextRotation;
	Vector2 myTextOrigin;
	Vector2 myTextScale;
	sf::Color myTextColor;
};

#endif
