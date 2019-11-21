#include "App.h"

App::App()
{
	myTexture.loadFromFile("Agent.png");			  //H�r laddar vi in texturen, notera att om texturen inte �r en medlem s� kommer den tas bort ur minnet och vi kommer endast se en vit fyrkant.
	myPlayer.Init(myTexture);							  //Vi and�nder Init f�r att vi m�ste ladda texturen innan vi skickar in den till spelaren.
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