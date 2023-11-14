#include "Input.hpp"


Input::Input(int inputsmax)
{
	ListDir.clear();
	NbInputsMax = inputsmax;
}

void Input::drawlist(sf::RenderWindow& window) { // Affiche la liste des inputs rentrés par le joueur
	sf::Font font;
	if (!font.loadFromFile("resources/Lato-Bold.ttf"))
	{
		cout << "Pas de font, essayez de tout regénérer" << endl;
	}

	if (!Input::ListDir.empty()) {
		for (int i = 0; i < Input::ListDir.size(); i++) {
			sf::Text Textes;
			Textes.setString(Input::ListDir[i]);
			float pos = 15.0f + i * 15.0f;

			Textes.setCharacterSize(12);
			Textes.setFillColor(sf::Color::White);
			Textes.setFont(font);
			Textes.setPosition(sf::Vector2f(pos, 0.0f));
			window.draw(Textes);
		}
	}
}

void Input::drawtxt(sf::RenderWindow& window, string str, sf::Color couleur, sf::Vector2f Pos, int size) { // Affiche un caractère
	sf::Font font;
	if (!font.loadFromFile("resources/Lato-Bold.ttf"))
	{
		cout << "Pas de font" << endl;
	}
	sf::Text texte;
	texte.setString(str);
	texte.setCharacterSize(size);
	texte.setFillColor(couleur);
	texte.setOutlineColor(sf::Color::Black);
	texte.setOutlineThickness(.5);
	texte.setFont(font);
	texte.setPosition(Pos);
	window.draw(texte);
}


void Input::InputHandler(sf::Event event, sf::RenderWindow& window, Perso& perso, Maps map) {
	//Close window sur la croix
	if (event.type == sf::Event::Closed) {
		window.close();
	}
		

	//Reset à la position d'origine et list.clear() si on press R.
	if (event.type == event.KeyReleased && event.key.code == sf::Keyboard::R)
	{
		perso.reset();
		ListDir.clear();
	}
	
	if (ListDir.size() == NbInputsMax) {
			perso.setIsMoving(true);
	}

	//ZQSD si liste pas remplie
	if (perso.getIsMoving() == false && event.type == sf::Event::KeyReleased) {
		switch (event.key.code)
		{
		case sf::Keyboard::Z:
			ListDir.emplace_back("Z");
			break;
		case sf::Keyboard::Q:
			ListDir.emplace_back("Q");
			break;
		case sf::Keyboard::S:
			ListDir.emplace_back("S");
			break;
		case sf::Keyboard::D:
			ListDir.emplace_back("D");
			break;
		case sf::Keyboard::A:
			ListDir.emplace_back("A");
			break;
		default:
			break;

		}
		
		cout << ListDir.size() << endl;
	}

	//Press space : move si liste a été remplie et pas encore vide
	else if (perso.getIsMoving() == true && event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space && !ListDir.empty())
	{
		sf::RectangleShape rect[120]; // Ces rectangles représenteront les limites du décor
		int i = 0;
		for (auto j : map.getDecor()) {
			rect[i].setSize(sf::Vector2f(16, 16));
			rect[i].setPosition(j);
	
			i++;
		}
		
		if (map.getIce() == 0)
		{
			perso.move(ListDir.front());
	
			for (int i = 0; i < 120; i++) {
				if (perso.getShape().getGlobalBounds().intersects(rect[i].getGlobalBounds())) {
					perso.move(ListDirReverse());
				}
			}
			
			ListDir.erase(ListDir.begin());
			
		}

		else
		{
			int touche = 0;
			while (touche == 0)
			{
				perso.move(ListDir.front());
				for (int i = 0; i < 120; i++) {
					if (perso.getShape().getGlobalBounds().intersects(rect[i].getGlobalBounds())) {
						perso.move(ListDirReverse());
						touche = 1;
					}						
								
				}
				
			}
			ListDir.erase(ListDir.begin());
		}
	}

	
}
void Input::clear() {
	ListDir.clear();
}
void Input::InputHandler(sf::Event event, sf::RenderWindow& window, MovingDecor& voiture, Maps map)
{
	if (ListDir.size() == NbInputsMax) {
		voiture.setIsMoving(true);
	}
	
	if (voiture.getIsMoving() == true && event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space && !ListDir.empty()) {
		if (voiture.getIdMov() < voiture.getMovements().size()) {
			voiture.move(ListDir.front());
		}
		
	}
	
	if (event.type == event.KeyReleased && event.key.code == sf::Keyboard::R)
	{
		voiture.reset();
		ListDir.clear();
		
	}
}


int Input::GameOver(sf::RenderWindow& window, SFMLObj& perso, int curMap) {
	
	//Si le perso est arrivé à un point final, GG
	sf::RectangleShape rect;
	rect.setSize(sf::Vector2f(16, 16));
	rect.setPosition(sf::Vector2f(224, 112));
	if (perso.getShape().getGlobalBounds().intersects(rect.getGlobalBounds())) {
		drawtxt(window, "GG", sf::Color::Green, sf::Vector2f(95, 20), 35);
		return (curMap + 1);
	}
	//Sinon, Game Over et retourne au point de départ.
	else if (perso.getIsMoving() && ListDir.empty()) {
		drawtxt(window, "GAME OVER ", sf::Color::Red, sf::Vector2f(20,20), 34);
		drawtxt(window, "Press R to restart", sf::Color::Red, sf::Vector2f(30, 50), 20);
	
	}
	return curMap;
	
}

vector<string> Input::getListDir()
{
	return ListDir;
}
int Input::getNbInputsMax()
{
	return NbInputsMax;
}

string Input::ListDirReverse() { // permet de bouger à l'envers
	if (ListDir.front() == "Z") {
		return "S";
	}
	else if (ListDir.front() == "Q") {
		return "D";
	}
	else if (ListDir.front() == "S") {
		return "Z";
	}
	else if (ListDir.front() == "D") {
		return "Q";
	}
}



