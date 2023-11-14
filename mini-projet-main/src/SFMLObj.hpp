#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class SFMLObj {
	

protected :
	sf::CircleShape shape;
	float OrX;
	float OrY;
	int MoveSpeed;
	bool isMoving;
public:
	

	SFMLObj(float posx, float posy, int ms) : OrX(posx), OrY(posy), MoveSpeed(ms) { isMoving = false; };

	sf::CircleShape getShape();
	float getOrX();
	float getOrY();
	int getMoveSpeed();
	bool getIsMoving();
	void setIsMoving(bool im);
	void draw(sf::RenderWindow& window) const;
	virtual void move(string) =0;
	virtual void reset() ;



};