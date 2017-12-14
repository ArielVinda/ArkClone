#include "Game.h"
#include <iostream>
using namespace std;

Game *Game::instance = nullptr;

Game::Game(){
	Loader* loader = new Loader();
	for(size_t i = 0; i < loader->levels.size(); i++){
		sf::Image* level = new sf::Image(loader->getImage(i));
		levels.push_back(level);
	}
	levelID = 0;
}

Game &Game::create(const sf::VideoMode &videoMode, BaseScene *scene, const string &name){
	if(instance){
		cerr<<"ERROR: juego ya instanciado."<<endl;
	}else{
		Game &g = getInstance();
		g.window.create(videoMode, name, sf::Style::Close);
		g.nextScene = nullptr;
		g.currentScene = scene;
		g.clock.restart();
	}
	return getInstance();
}

Game &Game::getInstance(){
	if(!instance)
		instance = new Game();
	return *instance;
}

void Game::run(){
	while(window.isOpen() && currentScene!= nullptr){
		sf::Event e;
		while(window.pollEvent(e)){
			if(e.type == sf::Event::Closed)
				window.close();
		}
		
		update();
		draw();
		if(nextScene != nullptr){
			delete currentScene;
			currentScene = nextScene;
			nextScene = nullptr;
		}
	}
}

void Game::update(){
	currentScene->update(clock.getElapsedTime().asSeconds());
	clock.restart();
}
void Game::draw(){
	window.clear();
	currentScene->draw(window);
	window.display();
}

void Game::switchScene(BaseScene* scene){
	nextScene = scene;
}
