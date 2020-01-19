#include "Game.h"

Game::Game()
{
	myTexture.loadFromFile("Agent.png");			  //Här laddar vi in texturen, notera att om texturen inte är en medlem så kommer den tas bort ur minnet och vi kommer endast se en vit fyrkant.
	myPlayer.Init(myTexture);							  //Vi andänder Init för att vi måste ladda texturen innan vi skickar in den till spelaren.
}


Game::~Game()
{

}

bool Game::Update(const float& someDelta)
{
	myPlayer.Update(someDelta);

	return true;
}

void Game::Draw(sf::RenderWindow& aWindow)
{
	myPlayer.Draw(aWindow);
}