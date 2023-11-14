#pragma once
#include <SFML/Graphics.hpp>
#include <tmxlite/Map.hpp>
#include <iostream>
#include <tmxlite/Map.hpp>
#include <SFML/System/Vector2.hpp>

class Maps {

private :
	std::string map;

	std::vector<sf::Vector2f> decor;

	int Ice;
public :

	Maps(std::string map, std::vector<sf::Vector2f> decor, int Ice);
	
	std::string getMap();
	std::vector<sf::Vector2f> getDecor();
	
	int getIce();
};


