#pragma once
#include "SFMLObj.hpp"

class MovingDecor : public SFMLObj {

private:
	//Vecteurs des directions prises par un objet qu'on veut mouvant
	std::vector<std::string> movements;
	//Indice de la liste movements pour garder le compte du nombre d'inputs d�j� effectu�s
	int idMov;
public:
	


	MovingDecor(float size, sf::Color color, float posx, float posy, std::vector<std::string> movements, int ms);
	std::vector<std::string> getMovements();
	int getIdMov();
	void move(std::string) override;
	void reset() override;

};










