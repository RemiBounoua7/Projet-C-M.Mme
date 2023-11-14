#include "MovingDecor.hpp"


MovingDecor::MovingDecor(float size, sf::Color color, float posx, float posy, vector<string> mov, int ms)
	: SFMLObj(posx, posy, ms)
{
	
	movements = mov;
	idMov = 0;


	shape.setRadius(size);
	shape.setFillColor(color);
	shape.setPointCount(4);
	shape.setRotation(45);
	shape.setPosition(OrX, OrY);
	
}

std::vector<std::string> MovingDecor::getMovements()
{
	return movements;
}

int MovingDecor::getIdMov()
{
	return idMov;
}

void MovingDecor::move(std::string str) // Déplace l'objet
{
	cout << movements[idMov] << std::endl;
	string str2 = movements[idMov];
	if (str2 == "Z") {
		shape.move(0, -MoveSpeed);
	}
	else if (str2 == "Q") {
		shape.move(-MoveSpeed, 0);
	}
	else if (str2 == "S") {
		shape.move(0, MoveSpeed);
	}
	else if (str2 == "D") {
		shape.move(MoveSpeed, 0);
	}
	MovingDecor::idMov += 1;
}

void MovingDecor::reset() // Remet l'objet à sa position d'origine
{
	shape.setPosition(OrX, OrY);
	idMov = 0;
}






