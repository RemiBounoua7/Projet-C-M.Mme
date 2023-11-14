#include <iostream>
#include <map>
#include "myMain.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>
#include <tmxlite/Map.hpp>
#include "SFMLOrthogonalLayer.h"
#include "SFMLObj.hpp"
#include "Perso.hpp"
#include "MovingDecor.hpp"
#include "Input.hpp"
#include "Maps.hpp"


using namespace sf;
// Ces vecteurs contiennent les positions de chacun des rectangles pour chaque map
const std::vector<Vector2f> decor1 ={ Vector2f(0, 0), Vector2f(0, 16), Vector2f(0, 32),  Vector2f(0, 48), Vector2f(0, 64), Vector2f(16,0), Vector2f(16, 16), Vector2f(16, 32), Vector2f(16, 48), Vector2f(32, 0), Vector2f(32, 16), Vector2f(32, 32), Vector2f(48, 0), Vector2f(48, 16), Vector2f(64, 0), Vector2f(0, 160),
Vector2f(0, 176), Vector2f(0, 192), Vector2f(0, 208), Vector2f(0, 224), Vector2f(16, 176), Vector2f(16, 192), Vector2f(16, 208), Vector2f(16, 224), Vector2f(32, 192), Vector2f(32, 208), Vector2f(32, 224), Vector2f(48, 208), Vector2f(48, 224), Vector2f(64, 224), Vector2f(160, 0), Vector2f(176, 0), Vector2f(176, 16),
Vector2f(192, 0), Vector2f(192, 16), Vector2f(192, 32), Vector2f(208, 0), Vector2f(208, 16), Vector2f(208, 32), Vector2f(208, 48), Vector2f(224, 0), Vector2f(224, 16), Vector2f(224, 32), Vector2f(224, 48), Vector2f(224, 64), Vector2f(224, 160), Vector2f(224, 176), Vector2f(224, 192),
Vector2f(224, 208), Vector2f(224, 224), Vector2f(208, 176), Vector2f(208, 192), Vector2f(208, 208), Vector2f(208, 224), Vector2f(192, 192), Vector2f(192, 208), Vector2f(192, 224), Vector2f(176, 208), Vector2f(176, 224), Vector2f(160, 224)
, Vector2f(80,0), Vector2f(80, 16), Vector2f(80, 32),
Vector2f(80, 48), Vector2f(80, 64), Vector2f(80, 160), Vector2f(80, 176), Vector2f(80, 192), Vector2f(80, 208), Vector2f(80, 224), Vector2f(144, 0), Vector2f(144, 16), Vector2f(144, 32), Vector2f(144, 48), Vector2f(144, 64), Vector2f(144, 160), Vector2f(144, 176), Vector2f(144, 192), Vector2f(144, 208), Vector2f(144, 224),
 Vector2f(-16, 80), Vector2f(-16, 96), Vector2f(-16, 112), Vector2f(-16, 128), Vector2f(-16, 144), Vector2f(80, -16), Vector2f(96, -16), Vector2f(112, 16), Vector2f(128, -16), Vector2f(144,-16), Vector2f(240, 80), Vector2f(240, 96), Vector2f(240, 112), Vector2f(240, 128),
 Vector2f(240, 144), Vector2f(80, 240), Vector2f(96, 240), Vector2f(112, 240), Vector2f(128, 240), Vector2f(144, 240) };
const std::vector<Vector2f> decor2 = { Vector2f(0, 0), Vector2f(0, 16), Vector2f(0, 32),  Vector2f(0, 48), Vector2f(0, 64), Vector2f(16,0), Vector2f(16, 16), Vector2f(16, 32), Vector2f(16, 48), Vector2f(32, 0), Vector2f(32, 16), Vector2f(32, 32), Vector2f(48, 0), Vector2f(48, 16), Vector2f(64, 0), Vector2f(0, 160),
Vector2f(0, 176), Vector2f(0, 192), Vector2f(0, 208), Vector2f(0, 224), Vector2f(16, 176), Vector2f(16, 192), Vector2f(16, 208), Vector2f(16, 224), Vector2f(32, 192), Vector2f(32, 208), Vector2f(32, 224), Vector2f(48, 208), Vector2f(48, 224), Vector2f(64, 224), Vector2f(160, 0), Vector2f(176, 0), Vector2f(176, 16),
Vector2f(192, 0), Vector2f(192, 16), Vector2f(192, 32), Vector2f(208, 0), Vector2f(208, 16), Vector2f(208, 32), Vector2f(208, 48), Vector2f(224, 0), Vector2f(224, 16), Vector2f(224, 32), Vector2f(224, 48), Vector2f(224, 64), Vector2f(224, 160), Vector2f(224, 176), Vector2f(224, 192),
Vector2f(224, 208), Vector2f(224, 224), Vector2f(208, 176), Vector2f(208, 192), Vector2f(208, 208), Vector2f(208, 224), Vector2f(192, 192), Vector2f(192, 208), Vector2f(192, 224), Vector2f(176, 208), Vector2f(176, 224), Vector2f(160, 224)
, Vector2f(80, 0), Vector2f(96, 0), Vector2f(112,0), Vector2f(128, 0), Vector2f(144, 0), Vector2f(0, 80), Vector2f(0, 96), Vector2f(0, 128), Vector2f(0, 112), Vector2f(0, 144), Vector2f(80, 224), Vector2f(96, 224), Vector2f(112,224), Vector2f(128, 224)
, Vector2f(144, 224), Vector2f(224, 80), Vector2f(224, 96), Vector2f(224, 128), Vector2f(224, 144), Vector2f(16, 80), Vector2f(32, 64), Vector2f(64, 32), Vector2f(80, 16), Vector2f(16, 160), Vector2f(208, 80)
, Vector2f(208, 144), Vector2f(192, 64), Vector2f(144, 192), Vector2f(96, 176), Vector2f(144, 48), Vector2f(64, 128), Vector2f(80, 112), Vector2f(96, 128), Vector2f(112, 144), Vector2f(144, 144), Vector2f(160, 112), Vector2f(176, 128), Vector2f(112, -16), Vector2f(112, 240), Vector2f(-16, 112), Vector2f(240, 112) };

void isGameOver(sf::RenderWindow& window, Input input) {
			
		input.drawtxt(window, "GAME OVER ", sf::Color::Red, sf::Vector2f(20, 20), 34);
		input.drawtxt(window, "Press R to restart", sf::Color::Red, sf::Vector2f(30, 50), 20);
}

int myMain(int curMap)
{
	sf::RenderWindow window(sf::VideoMode(240, 240), "SFML works!");
	window.setVerticalSyncEnabled(true);
	
	if (curMap == 0) // On vérfie quel est la carte actuelle
	{
		Input input(15);
		
		Perso perso(4.0F, sf::Color::Red, 5, 118, 20); // création du personnage
		Perso pnj(5.0F, sf::Color::Blue, 225, 135, 0);
		
		MovingDecor voiture1(10.0F, sf::Color::Black, 130, 200, { "Z","Z","Z","Z","Z","Z","Z","Z","Z","Z","Z","Z","Z","Z" }, 20); // création des obstacles avec leurs mouvements
		MovingDecor voiture2(10.0F, sf::Color::Yellow, 110, 25, { "A","S","S","S","S","S","S","S","S","S","S","S","S","S" }, 20);
		MovingDecor voiture3(10.0F, sf::Color::Blue, 130, 250, { "Z","Z","Z","Z","Z","Z","Z","Z","Z","Z","Z","Z","Z","Z" }, 20); // création des obstacles avec leurs mouvements

	
		auto map1 = Maps("voiture.tmx", decor1, 0); // création de la carte

		int go = 0; // on vérifie si le perso se fait rouler dessus

		tmx::Map map;
		std::string path = "resources/" + map1.getMap(); // on récupère le chemin de la tilemap
		if (!map.load(path)) {
			cout << "PAS de map";
		}
		
		MapLayer layer1(map, 0);
		MapLayer layer2(map, 1);
		MapLayer layer3(map, 2);
		
		while (window.isOpen())
		{

			sf::Event event;
			while (window.pollEvent(event))
			{
				input.InputHandler(event, window, perso, map1);
				input.InputHandler(event, window, voiture1, map1);
				input.InputHandler(event, window, voiture2, map1);
				input.InputHandler(event, window, voiture3, map1);

				if (perso.getShape().getGlobalBounds().intersects(voiture1.getShape().getGlobalBounds())) { // on vérifie si les voiture roulent sur le joueur
					go = 1;
				}
				if (perso.getShape().getGlobalBounds().intersects(voiture2.getShape().getGlobalBounds())) { // on vérifie si les voiture roulent sur le joueur
					go = 1;
				}
				if (perso.getShape().getGlobalBounds().intersects(voiture3.getShape().getGlobalBounds())) { // on vérifie si les voiture roulent sur le joueur
					go = 1;
				}
				if (event.type == event.KeyReleased && event.key.code == sf::Keyboard::R)
				{
					go = 0;
				}
				
			}
			
			window.clear();
			
			window.draw(layer1);
			window.draw(layer2);
			window.draw(layer3);

			perso.draw(window);
			pnj.draw(window);
			voiture1.draw(window);
			voiture2.draw(window);
			voiture3.draw(window);

			if (go == 1) {
				input.clear();
				isGameOver(window, input);
			}
			if (event.type == sf::Event::Closed) {
				curMap = 5;
				window.close();

			}
			input.drawlist(window);
			input.drawtxt(window, "Il est parti\npar ici !", sf::Color::White, { 180,150 }, 12);

			curMap = input.GameOver(window, perso, curMap); // cette fonction permet de savoir si le joueur échoue->message d'erreur ou réussi -> prochaine carte

			window.display();
			if (curMap != 0) {
				window.close();
			}

		}
		return curMap;
	}
	if (curMap == 1)
	{
		Input input(15);

		Perso perso(4.0F, sf::Color::Red, 4, 118, 16);

		

		auto map2 = Maps("ice.tmx", decor2, 1);

		tmx::Map map;
		std::string path = "resources/" + map2.getMap();
		if (!map.load("resources/" + map2.getMap())) {
			cout << "PAS de map";
		}

		MapLayer layer1(map, 0);
		MapLayer layer2(map, 1);
		MapLayer layer3(map, 2);

		while (window.isOpen())
		{

			sf::Event event;
			while (window.pollEvent(event))
			{
				input.InputHandler(event, window, perso, map2);
			}
			window.clear();
			window.draw(layer1);
			window.draw(layer2);
			window.draw(layer3);

			perso.draw(window);

			input.drawlist(window);
			curMap = input.GameOver(window, perso, curMap);
			if (event.type == sf::Event::Closed) {
				curMap = 5;
				window.close();

			}
			window.display();
			if (curMap != 1) {
				window.close();
			}

		}
		return curMap;
	}
    return 3;
}


