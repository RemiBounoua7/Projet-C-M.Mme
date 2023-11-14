#include "Maps.hpp"

Maps::Maps(std::string map, std::vector<sf::Vector2f> decor , int Ice)
	: map{ map }
	, decor { decor }
	, Ice { Ice }
{}

/* Getters pour les 
attributs de map :
*/
std::string Maps::getMap() 
{
	return Maps::map;
}

std::vector<sf::Vector2f> Maps::getDecor()
{
	return Maps::decor;
}


int Maps::getIce()
{
	return Ice;
}
