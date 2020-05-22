#ifndef GAME_HEADER
#define GAME_HEADER

#include "GameInfo.h"
#include "Enemy.h"
#include "Player.h"
#include "StartingBoss.h"
#include "SecondBoss.h"
#include "ThirdBoss.h"
#include "GUI.h"

class Game
{
public:
	Game();
	~Game();

	bool Update(const float& someDelta, sf::RenderWindow &aRenderWindow);
	void Draw(sf::RenderWindow& aWindow);

private:

	void BattleBossOne();
	void BattleBossTwo();
	void BattleBossThree();

	void OpenSkillAndEquipmentMenu();

	std::vector<GameObject*> myGameObjects;

	std::vector<GUI*> myGUI;

	std::vector<GameObject*> SortByLayer(std::vector<GameObject*> someGameObjects);

	std::vector<GUI*> SortByLayer(std::vector<GUI*> someGUI);

	float myDelayTime = 2;
	float myDelayTimer;

	//GUI* myCrosshair;
};

#endif