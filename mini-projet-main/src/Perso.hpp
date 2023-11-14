#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "SFMLObj.hpp"


class Perso : public SFMLObj{


public:

	Perso(float size, sf::Color color, float posx, float posy, int ms);

	void move(std::string) override;

	

};


