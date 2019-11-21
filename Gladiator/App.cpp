#include "App.h"

App::App()
{
	myTexture.loadFromFile("Agent.png");			  //Här laddar vi in texturen, notera att om texturen inte är en medlem så kommer den tas bort ur minnet och vi kommer endast se en vit fyrkant.
	myPlayer.Init(myTexture);							  //Vi andänder Init för att vi måste ladda texturen innan vi skickar in den till spelaren.
}


App::~App()
{
}

bool App::Update(const float& someDelta)
{
	return myPlayer.Update(someDelta);
}

void App::Draw(sf::RenderWindow& aWindow)
{
	myPlayer.Draw(aWindow);
}