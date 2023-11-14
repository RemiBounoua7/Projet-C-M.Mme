#ifndef INPUT_H
#define INPUT_H
#include "Perso.hpp"
#include "MovingDecor.hpp"
#include "Maps.hpp"
#include <iostream>

class Input
{
private :
	vector<string> ListDir;
	int NbInputsMax;
public :
	explicit Input(int inputsmax);
	
	void InputHandler(sf::Event event, sf::RenderWindow& window, Perso& perso, Maps map);
	void InputHandler(sf::Event event, sf::RenderWindow& window, MovingDecor& voiture, Maps map);
	void clear();
	void drawlist(sf::RenderWindow& window);
	void drawtxt(sf::RenderWindow& window, string str, sf::Color couleur, sf::Vector2f Pos, int size);
	int GameOver(sf::RenderWindow& window, SFMLObj& perso, int curMap);
	vector<string> getListDir();
	int getNbInputsMax();
	string ListDirReverse();
};
#endif