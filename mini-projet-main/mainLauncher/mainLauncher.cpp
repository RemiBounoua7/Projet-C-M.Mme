#include "myMain.h"
#include "SFML/Graphics.hpp"
#include "Input.hpp"



int main()
{
	int curMap = 0; // cette entier determinera la carte actuelle

	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!"); // création de la cinématique de début de jeu
	Input input(0);

	sf::CircleShape mmeER(200);

	mmeER.setFillColor(sf::Color::Red);
	mmeER.setPosition(sf::Vector2f(600, 80));
	mmeER.setOutlineColor(sf::Color::White);
	mmeER.setOutlineThickness(1);
	mmeER.setPointCount(100);
	

	sf::CircleShape mmemagie(200);

	mmemagie.setFillColor(sf::Color::Magenta);
	mmemagie.setPosition(sf::Vector2f(-150, 80));
	mmemagie.setOutlineColor(sf::Color::White);
	mmemagie.setOutlineThickness(1);
	mmemagie.setPointCount(100);
	while (window.isOpen())
	{
		window.draw(mmeER);

		input.drawtxt(window, "Mme. EnRetard : M.Curieux est encore introuvable !", sf::Color::White, sf::Vector2f(200, 500), 18);

		window.display();
		sleep(sf::seconds(3));
		window.clear();

		window.draw(mmemagie);

		input.drawtxt(window, "Mme. Magie : Allez le retrouver Mme. EnRetard, \n vous auriez dû le faire plus tôt!", sf::Color::White, sf::Vector2f(200, 100), 18);
		window.display();

		sleep(sf::seconds(3));
		window.clear();

		input.drawtxt(window, "Mme. EnRetard : Et allez, c'est encore pour ma pomme \nil va falloir que je réflechisse à l'avance à chacun de mes pas \npour ne pas perdre plus de temps!", sf::Color::White, sf::Vector2f(200, 500), 18);
		window.draw(mmeER);
		window.display();
		sleep(sf::seconds(3));
		window.clear();
		window.close();
	}
	while (curMap < 2) { // tant que la map 2 n'est pas terminée, on lance la boucle du jeu avec le numéro de la carte en argument
		curMap = myMain(curMap);
	}
	return 0;
}