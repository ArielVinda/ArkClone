#include "Game.h"
#include "Loader.h"
#include "PlayScene.h"
#include "MainScene.h"

int main(int argc, char *argv[]){
	
	BaseScene *scene = new MainScene(); 
	Game &g = Game::create(sf::VideoMode(640,640), scene, "Arkanoid - pero mas trucho");
	g.run();
	
	return 0;
}

