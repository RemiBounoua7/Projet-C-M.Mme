#include"SFMLObj.hpp"
	


sf::CircleShape SFMLObj::getShape()
{
	return shape;
}

float SFMLObj::getOrX()
{
	return OrX;
}

float SFMLObj::getOrY()
{
	return OrY;
}

int SFMLObj::getMoveSpeed()
{
	return MoveSpeed;
}

bool SFMLObj::getIsMoving()
{
	return isMoving;
}

void SFMLObj::setIsMoving(bool im) {
	isMoving = im;
}


void SFMLObj::draw(sf::RenderWindow& window) const // draw l'objet 
{
	window.draw(shape);
}

void SFMLObj::reset() {  // Remet l'objet à sa position d'origine
	shape.setPosition(sf::Vector2f(OrX, OrY));
	isMoving = false;
}
