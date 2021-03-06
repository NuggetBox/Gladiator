#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Vector2.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Gladiator");				  //H�r s�tter vi storleken och namnet p� v�rt f�nster.
	Game tempGame;

	sf::Clock tempClock;														  //H�r skapar vi en klocka, denna kommer anv�ndas f�r Delta Time.
	sf::Time tempDelta;
															  //H�r skapar vi en Time, detta �r den som kommer ge oss delta time.

	while (window.isOpen())
	{
		tempDelta = tempClock.restart();										  //H�r start vi om klockan och sparar ner tiden den hade, detta kommer g�ras varje frame och d�rf�r kommer vi f� ut v�r Delta Time.

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		float tempDeltaTime = tempDelta.asSeconds();

		//if (tempDeltaTime == 0) 
		//{
		//	tempDeltaTime = 1;
		//}

		if (tempGame.Update(tempDeltaTime, window) == false)					  //H�r uppdaterar vi v�r App och skickar in Delta Time som sekunder.
		{
			return 0;
		}

		window.clear();

		tempGame.Draw(window);													  //H�r skickar vi in v�r RenderWindow som kommer rita ut spelaren.

		window.display();
	}

	return 0;
}

//int main()
//{
//	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
//	sf::CircleShape shape(100.f);
//	shape.setFillColor(sf::Color::Green);
//
//	while (window.isOpen())
//	{
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				window.close();
//		}
//
//		window.clear();
//		window.draw(shape);
//		window.display();
//	}
//
//	return 0;
//}