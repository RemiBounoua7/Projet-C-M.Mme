#include "Perso.hpp"


Perso::Perso(float size, sf::Color color, float posx, float posy, int ms)
	: SFMLObj(posx, posy, ms) 
{
	shape.setRadius(size);
	shape.setFillColor(color);
	shape.setPointCount(30);
	shape.setOutlineThickness(1);
	shape.setPosition(sf::Vector2f(OrX, OrY));
}

void Perso::move(std::string str) // Permet de déplacer le personnage
{
	if (str == "Z") {
		shape.move(0, -MoveSpeed);
	}
	else if (str == "Q") {
		shape.move(-MoveSpeed, 0);
	}
	else if (str == "S") {
		shape.move(0, MoveSpeed);
	}
	else if (str == "D") {
		shape.move(MoveSpeed, 0);
	}
}









