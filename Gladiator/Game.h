#ifndef GAME_HEADER
#define GAME_HEADER

#include "GameInfo.h"
#include "Player.h"
#include "StartingBoss.h"
#include "SecondBoss.h"
#include "ThirdBoss.h"
#include "GUI.h"
#include "ConditionsInfo.h"
#include "AbilityInfo.h"

class Game
{
public:
	Game();
	~Game();

	bool Update(const float& someDelta, sf::RenderWindow &aRenderWindow);
	void Draw(sf::RenderWindow& aWindow);

private:

	int myLevel;
	int myItemPointsLeft;
	bool myFacedChariotFirst = false;

	GUI myIronHelmetButton, myIronArmorButton, myIronSwordButton, myDiamondHelmetButton, myDiamondArmorButton, myDiamondSwordButton, myDoneBuyingButton;

	GUI myChooseBossText, myChariotButton, myRetiariusButton;

	void BattleBossOne();
	void BattleBossTwo();
	void BattleBossThree();

	void OpenSkillAndEquipmentMenu();
	void OpenChooseBossMenu();

	std::vector<GameObject*> myGameObjects;

	std::vector<GUI*> myGUI;

	std::vector<GameObject*> SortByLayer(std::vector<GameObject*> someGameObjects);

	std::vector<GUI*> SortByLayer(std::vector<GUI*> someGUI);

	void SpawnSand();
};

#endif