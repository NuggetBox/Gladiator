#include <SFML/Graphics.hpp>
#include "App.h"

int main()
{
	App tempApp;
	sf::RenderWindow window(sf::VideoMode(1280, 1024), "DeepDive");				  //Här sätter vi storleken och namnet på vårt fönster.

	sf::Clock tempClock;														  //Här skapar vi en klocka, denna kommer användas för Delta Time.
	sf::Time tempDelta;															  //Här skapar vi en Time, detta är den som kommer ge oss delta time.

	while (window.isOpen())
	{
		tempDelta = tempClock.restart();										  //Här start vi om klockan och sparar ner tiden den hade, detta kommer göras varje frame och därför kommer vi få ut vår Delta Time.

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (tempApp.Update(tempDelta.asSeconds()) == false)						  //Här uppdaterar vi vår App och skickar in Delta Time som sekunder.
		{
			return 0;
		}

		window.clear();

		tempApp.Draw(window);													  //Här skickar vi in vår RenderWindow som kommer rita ut spelaren.

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