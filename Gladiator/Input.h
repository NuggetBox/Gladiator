#ifndef INPUT_HEADER
#define INPUT_HEADER

#include <SFML/Graphics.hpp>

namespace in
{
	void update();

	bool getWDown();
	bool getWPressed();
	bool getWReleased();
	bool getADown();
	bool getAPressed();
	bool getAReleased();
	bool getSDown();
	bool getSPressed();
	bool getSReleased();
	bool getDDown();
	bool getDPressed();
	bool getDReleased();
	bool getSpaceDown();
	bool getSpacePressed();
	bool getSpaceReleased();
	bool getM1Down();
	bool getM1Pressed();
	bool getM1Released();
	bool getM2Down();
	bool getM2Pressed();
	bool getM2Released();
}

#endif

/*#ifndef KEY_HEADER
#define KEY_HEADER

class Key
{
public:
	Key(sf::Keyboard::Key aKey);
	~Key();

	void Update();

	bool GetDown();
	bool GetPressed();
	bool GetReleased();

private:
	sf::Keyboard::Key myKey;
	bool myWasDownLastFrame = false;
};

#endif*/