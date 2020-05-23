#ifndef GUI_HEADER
#define GUI_HEADER

#include "Vector2.h"
#include "Input.h"

class GUI
{
public:
	GUI(sf::Texture aTexture, Vector2 aPosition, Vector2 aScale, sf::String aTextString, int aTextSize, Vector2 aTextPosition);
	GUI(sf::Texture aTexture, Vector2 aPosition, Vector2 aScale, sf::String aTextString, int aTextSize, Vector2 aTextPosition, bool aSelfDestruct);
	GUI(sf::Texture aTexture, Vector2 aPosition, Vector2 aScale, sf::String aTextString, int aTextSize, Vector2 aTextPosition, bool* aBoolToChange);
	GUI(sf::Texture aTexture, Vector2 aPosition, Vector2 aScale, sf::String aTextString, int aTextSize, Vector2 aTextPosition, bool* aBoolToChange, bool aSelfDestruct);
	GUI();
	~GUI();

	void Update(const float& someDelta);

	void Draw(sf::RenderWindow& aWindow);

	int GetLayer();
	bool GetDead();

	void Kill();

	void SetPosition(Vector2 aPosition);
	void SetOrigin(Vector2 anOrigin);
	void SetScale(Vector2 aScale);
	void SetText(sf::String aTextString);

private:
	void Init(sf::Texture aTexture, Vector2 aPosition, Vector2 aScale, sf::String aTextString, int aTextSize, Vector2 aTextPosition);

	bool MouseAbove();

	bool* myBoolToChange;
	bool myHasEffect = false;
	
	bool mySelfDestruct = false;

	int myLayer = 100;

	bool myIsDead = false;

	sf::Texture myTexture;
	Vector2 myPosition = { 0,0 };
	float myRotation = 0;
	Vector2 myOrigin = { 0,0 };
	Vector2 myScale = { 1,1 };
	sf::Color myColor = sf::Color(255, 255, 255, 255);
	sf::IntRect myTextureRect;

	sf::String myTextString = "Sample Text";
	int myTextCharacterSize = 12;
	sf::Font myTextFont;
	sf::Uint32 myTextStyle = sf::Text::Regular;
	sf::Color myTextFillColor = sf::Color(255, 255, 255, 255);
	sf::Color myTextOutlineColor = sf::Color(255, 255, 255, 255);
	float myTextOutlineThickness = 0;
	float myTextLetterSpacing = 1;
	float myTextLineSpacing = 1;
	Vector2 myTextPosition = { 0,0 };
	float myTextRotation = 0;
	Vector2 myTextOrigin = { 0,0 };
	Vector2 myTextScale = { 1,1 };
	//sf::Color myTextColor = sf::Color(255, 255, 255, 255);
};

#endif
