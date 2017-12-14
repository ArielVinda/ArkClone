#ifndef GAME_H
#define GAME_H

#include "TestScene.h"
#include <SFML/Graphics.hpp>
#include "Global.h"
#include "Loader.h"
#include "BaseScene.h"
#include "PlayScene.h"
#include "MainScene.h"
#include <vector>
using namespace std;

class Game {
public:
	//Comenzar bucle de juego
	void run();
	//Cambiar escena de juego
	void switchScene(BaseScene *scene);
	//Obtener instancia de juego
	static Game &getInstance();
	//Crear juego especificando modo de video y escena principal
	static Game &create(const sf::VideoMode &videoMode, BaseScene *scene, const string &name = "");
	//Retornar imagenes de niveles
	sf::Image* getLevel(unsigned int ID){
		sf::Image* level = levels[ID];
		levelID++;
		if(levelID >= levels.size())
			levelID = 0;
		return level;
	}
	//ID nivel
	unsigned int levelID;
private:
	void update();
	void draw();
	static Game *instance;
	
	BaseScene* currentScene;
	BaseScene* nextScene;
	
	vector<sf::Image*> levels;
	
	sf::Clock clock;
	
	sf::RenderWindow window;
	
	Game();
};

#endif
