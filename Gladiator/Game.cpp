#include <SFML/Graphics.hpp>
#include "Game.h"

Game::Game()
{
	gameInfo::setGameObjects(&myGameObjects);

	// Player
	/*Player* tempPlayer = new Player();
	gameInfo::setPlayer(tempPlayer);
	myGameObjects.push_back(tempPlayer);

	// Second boss
	SecondBoss* tempBoss = new SecondBoss();
	myGameObjects.push_back(tempBoss);

	// Third boss
	ThirdBoss* tempThird = new ThirdBoss();
	myGameObjects.push_back(tempThird);

	// Sand ground
	sf::Texture tempTexture;
	tempTexture.loadFromFile("Textures/Sand.png");
	myGameObjects.push_back(new GameObject({ 1000, 500 }, tempTexture, 0, 5, 0, 0));

	// Gay button
	tempTexture.loadFromFile("Textures/gmod.png");
	myGUI.push_back(new GUI(tempTexture, { 900, 320 }, { 10,5 }, "You have to win in the gladiator tournament\n				to get the gay vaccine.", 40, { 400, 200 }, true));*/

	sf::Texture tempTexture;

	tempTexture.loadFromFile("Textures/Player/IronHelmet.png");
	myIronHelmetButton = GUI(tempTexture, { 480, 280 }, { 5, 5 }, "", 0, { 0,0 }, conditionsInfo::accessIronHelmet());
	tempTexture.loadFromFile("Textures/Player/IronArmor.png");
	myIronArmorButton = GUI(tempTexture, { 960, 280 }, { 5, 5 }, "", 0, { 0,0 }, conditionsInfo::accessIronArmor());
	tempTexture.loadFromFile("Textures/Player/IronSword.png");
	myIronSwordButton = GUI(tempTexture, { 1440, 280 }, { 5, 5 }, "", 0, { 0,0 }, conditionsInfo::accessIronSword());
	tempTexture.loadFromFile("Textures/Player/DiamondHelmet.png");
	myDiamondHelmetButton = GUI(tempTexture, { 480, 560 }, { 5, 5 }, "", 0, { 0,0 }, conditionsInfo::accessDiamondHelmet());
	tempTexture.loadFromFile("Textures/Player/DiamondArmor.png");
	myDiamondArmorButton = GUI(tempTexture, { 960, 560 }, { 5, 5 }, "", 0, { 0,0 }, conditionsInfo::accessDiamondArmor());
	tempTexture.loadFromFile("Textures/Player/DiamondSword.png");
	myDiamondSwordButton = GUI(tempTexture, { 1440, 560 }, { 5, 5 }, "", 0, { 0,0 }, conditionsInfo::accessDiamondSword());
	tempTexture.loadFromFile("Textures/Ok.png");
	myDoneBuyingButton = GUI(tempTexture, { 960, 840 }, { 3, 3 }, "", 0, { 0,0 }, conditionsInfo::accessDoneBuying());

	myChooseBossText = GUI(sf::Texture(), { 0,0 }, { 0,0 }, "Which boss would you like to face next?", 16, { 700, 500 });
	myChariotButton = GUI(tempTexture, { 640, 700 }, { 3, 3 }, "Chariot", 10, { 640, 650 }, conditionsInfo::accessFacingChariotFirst());
	myRetiariusButton = GUI(tempTexture, { 1280, 700 }, { 3, 3 }, "Retiarius", 10, { 1280, 650 }, conditionsInfo::accessFacingRetiariusFirst());

	myLevel = 1;
	BattleBossOne();
}

Game::~Game()
{
	
}

bool Game::Update(const float& someDelta, sf::RenderWindow &aRenderWindow)
{
	// Player has been killed
	if (*conditionsInfo::accessPlayerIsDead())
	{
		*conditionsInfo::accessPlayerIsDead() = false;

		sf::Texture tempTexture;
		tempTexture.loadFromFile("Textures/Ok.png");
		myGUI.push_back(new GUI(tempTexture, { 900, 500 }, { 5, 5 }, "Game Over", 60, { 800, 300 }, conditionsInfo::accessLoseButton(), true));
	}

	// Lose button pressed
	if (*conditionsInfo::accessLoseButton())
	{
		*conditionsInfo::accessLoseButton() = false;

		aRenderWindow.close();
	}

	// Boss has been killed
	if (*conditionsInfo::accessBossIsDead())
	{
		*conditionsInfo::accessBossIsDead() = false;

		sf::Texture tempTexture;
		tempTexture.loadFromFile("Textures/Ok.png");

		if (myLevel < 3)
		{
			myGUI.push_back(new GUI(tempTexture, { 900, 500 }, { 5, 5 }, "			Congratulations! You Win! \nYou earned enough gold to buy two items.", 40, { 500, 300 }, conditionsInfo::accessWinButton(), true));
		}
		else
		{
			myGUI.push_back(new GUI(tempTexture, { 900, 500 }, { 5, 5 }, "Victory!", 40, { 750, 350 }, conditionsInfo::accessVictory(), true));
		}
	}

	// Win button pressed
	if (*conditionsInfo::accessWinButton())
	{
		*conditionsInfo::accessWinButton() = false;

		myGameObjects.clear();

		OpenSkillAndEquipmentMenu();
	}

	// Iron helmet pressed
	if (*conditionsInfo::accessIronHelmet())
	{
		*conditionsInfo::accessIronHelmet() = false;

		if (myItemPointsLeft > 0)
		{
			myItemPointsLeft--;
			abilityInfo::upgradePlayerHelmetLevel();

			myIronHelmetButton.Kill();
		}
	}

	// Diamond helmet pressed
	if (*conditionsInfo::accessDiamondHelmet())
	{
		*conditionsInfo::accessDiamondHelmet() = false;

		if (myItemPointsLeft > 0 && abilityInfo::getPlayerHelmetLevel() == 2)
		{
			myItemPointsLeft--;
			abilityInfo::upgradePlayerHelmetLevel();

			myDiamondHelmetButton.Kill();
		}
	}

	// Iron armor pressed
	if (*conditionsInfo::accessIronArmor())
	{
		*conditionsInfo::accessIronArmor() = false;

		if (myItemPointsLeft > 0)
		{
			myItemPointsLeft--;
			abilityInfo::upgradePlayerArmorLevel();

			myIronArmorButton.Kill();
		}
	}

	// Diamond armor pressed
	if (*conditionsInfo::accessDiamondArmor())
	{
		*conditionsInfo::accessDiamondArmor() = false;

		if (myItemPointsLeft > 0 && abilityInfo::getPlayerArmorLevel() == 2)
		{
			myItemPointsLeft--;
			abilityInfo::upgradePlayerArmorLevel();

			myDiamondArmorButton.Kill();
		}
	}

	// Iron sword pressed
	if (*conditionsInfo::accessIronSword())
	{
		*conditionsInfo::accessIronSword() = false;

		if (myItemPointsLeft > 0)
		{
			myItemPointsLeft--;
			abilityInfo::upgradePlayerSwordLevel();

			myIronSwordButton.Kill();
		}
	}

	// Diamond sword pressed
	if (*conditionsInfo::accessDiamondSword())
	{
		*conditionsInfo::accessDiamondSword() = false;

		if (myItemPointsLeft > 0 && abilityInfo::getPlayerSwordLevel() == 2)
		{
			myItemPointsLeft--;
			abilityInfo::upgradePlayerSwordLevel();

			myDiamondSwordButton.Kill();
		}
	}

	// Done buying button pressed
	if (*conditionsInfo::accessDoneBuying())
	{
		*conditionsInfo::accessDoneBuying() = false;

		myGUI.clear();

		if (myLevel == 1)
		{
			OpenChooseBossMenu();
		}
		else
		{
			if (myFacedChariotFirst)
			{
				BattleBossThree();
			}
			else
			{
				BattleBossTwo();
			}
		}

		myLevel++;
	}

	// Chariot or Retiarius button pressed
	if (*conditionsInfo::accessFacingChariotFirst() || *conditionsInfo::accessFacingRetiariusFirst())
	{
		myGUI.clear();

		if (*conditionsInfo::accessFacingChariotFirst())
		{
			myFacedChariotFirst = true;
			BattleBossTwo();
		}
		else
		{
			BattleBossThree();
		}

		*conditionsInfo::accessFacingChariotFirst() = false;
		*conditionsInfo::accessFacingRetiariusFirst() = false;
	}

	// Victory button pressed
	if (*conditionsInfo::accessVictory())
	{
		*conditionsInfo::accessVictory() = false;

		aRenderWindow.close();
	}



	for (int i = 0; i < myGameObjects.size(); ++i)
	{
		if (myGameObjects[i]->myIsDead)
		{
			myGameObjects.erase(myGameObjects.begin() + i);
		}
		else
		{
			myGameObjects[i]->Update(someDelta);

			if (myGameObjects[i]->GetIsCharacter())
			{
				Character* tempCharacter = (Character*)myGameObjects[i];

				tempCharacter->CharacterUpdate(someDelta);
			}
		}
	}

	for (int i = 0; i < myGUI.size(); ++i)
	{
		if (myGUI[i]->GetDead())
		{
			myGUI.erase(myGUI.begin() + i);
		}
		else
		{
			myGUI[i]->Update(someDelta);
		}
	}

	in::update(aRenderWindow);

	return true;
}

void Game::BattleBossOne()
{
	// Sand ground
	sf::Texture tempTexture;
	tempTexture.loadFromFile("Textures/Sand.png");
	myGameObjects.push_back(new GameObject({ 1000, 500 }, tempTexture, 0, 5, 0, 0));

	// Player
	Player* tempPlayer = new Player();
	playerInfo::setPlayer(tempPlayer);
	myGameObjects.push_back(tempPlayer);

	// First boss
	StartingBoss* tempStartingBoss = new StartingBoss();
	myGameObjects.push_back(tempStartingBoss);
}

void Game::BattleBossTwo()
{
	// Sand ground
	sf::Texture tempTexture;
	tempTexture.loadFromFile("Textures/Sand.png");
	myGameObjects.push_back(new GameObject({ 1000, 500 }, tempTexture, 0, 5, 0, 0));

	// Player
	Player* tempPlayer = new Player();
	playerInfo::setPlayer(tempPlayer);
	myGameObjects.push_back(tempPlayer);

	// Second boss
	SecondBoss* tempBoss = new SecondBoss();
	myGameObjects.push_back(tempBoss);
}

void Game::BattleBossThree()
{
	// Sand ground
	sf::Texture tempTexture;
	tempTexture.loadFromFile("Textures/Sand.png");
	myGameObjects.push_back(new GameObject({ 1000, 500 }, tempTexture, 0, 5, 0, 0));

	// Player
	Player* tempPlayer = new Player();
	playerInfo::setPlayer(tempPlayer);
	myGameObjects.push_back(tempPlayer);

	// Third boss
	ThirdBoss* tempThird = new ThirdBoss();
	myGameObjects.push_back(tempThird);
}

void Game::OpenSkillAndEquipmentMenu()
{
	myItemPointsLeft = 2;

	if (abilityInfo::getPlayerHelmetLevel() <= 2)
	{
		myGUI.push_back(&myDiamondHelmetButton);

		if (abilityInfo::getPlayerHelmetLevel() == 1)
		{
			myGUI.push_back(&myIronHelmetButton);
		}
	}

	if (abilityInfo::getPlayerArmorLevel() <= 2)
	{
		myGUI.push_back(&myDiamondArmorButton);

		if (abilityInfo::getPlayerArmorLevel() == 1)
		{
			myGUI.push_back(&myIronArmorButton);
		}
	}

	if (abilityInfo::getPlayerSwordLevel() <= 2)
	{
		myGUI.push_back(&myDiamondSwordButton);

		if (abilityInfo::getPlayerSwordLevel() == 1)
		{
			myGUI.push_back(&myIronSwordButton);
		}
	}

	myGUI.push_back(&myDoneBuyingButton);
}

void Game::OpenChooseBossMenu()
{
	myGUI.push_back(&myChooseBossText);
	myGUI.push_back(&myChariotButton);
	myGUI.push_back(&myRetiariusButton);
}

void Game::Draw(sf::RenderWindow& aWindow)
{
	myGameObjects = SortByLayer(myGameObjects);

	for (int i = 0; i < myGameObjects.size(); ++i)
	{
		myGameObjects[i]->Draw(aWindow);
	}

	myGUI = SortByLayer(myGUI);

	for (int i = 0; i < myGUI.size(); ++i)
	{
		myGUI[i]->Draw(aWindow);
	}
}

std::vector<GameObject*> Game::SortByLayer(std::vector<GameObject*> someGameObjects)
{
	bool tempFinished = false;
	bool tempNoErrors;

	while (!tempFinished)
	{
		tempNoErrors = true;

		for (int i = 0; (size_t)i + (size_t)1 < someGameObjects.size(); ++i)
		{
			if (someGameObjects[i]->GetLayer() > someGameObjects[(size_t)i + (size_t)1]->GetLayer())
			{
				tempNoErrors = false;

				GameObject* tempGameObject = someGameObjects[(size_t)i + (size_t)1];
				someGameObjects[(size_t)i + (size_t)1] = someGameObjects[i];
				someGameObjects[i] = tempGameObject;
			}
		}

		if (tempNoErrors)
		{
			tempFinished = true;
		}
	}

	return someGameObjects;
}

std::vector<GUI*> Game::SortByLayer(std::vector<GUI*> someGUI)
{
	bool tempFinished = false;
	bool tempNoErrors;

	while (!tempFinished)
	{
		tempNoErrors = true;

		for (int i = 0; (size_t)i + (size_t)1 < someGUI.size(); ++i)
		{
			if (someGUI[i]->GetLayer() > someGUI[(size_t)i + (size_t)1]->GetLayer())
			{
				tempNoErrors = false;

				GUI* tempGUI = someGUI[(size_t)i + (size_t)1];
				someGUI[(size_t)i + (size_t)1] = someGUI[i];
				someGUI[i] = tempGUI;
			}
		}

		if (tempNoErrors)
		{
			tempFinished = true;
		}
	}

	return someGUI;
}