#include "MainScene.h"
#include <iostream>
#include "Game.h"
#include <sstream>
using namespace std;

MainScene::MainScene(){
	if(!titleFont.loadFromFile("assets/fonts/ARKANOID.TTF"))
	   cerr<<"No se econtro la fuente ARKANOID.TTF"<<endl;
	
	if(!scoreFont.loadFromFile("assets/fonts/Cave-Story.ttf"))
		cerr<<"No se econtro la fuente Cave-Story.ttf"<<endl;
	
	cout<<Global::readLastScore()<<endl;
	cout<<Global::readHighScore()<<endl;
	
	titleText.setFont(titleFont);
	titleText.setColor(sf::Color::White);
	titleText.setString("Arkanoid");
	titleText.setCharacterSize(70);
	// centra el texto
	titleText.setPosition(sf::Vector2f((SCREEN_WIDTH-titleText.getLocalBounds().width)/2.0, SCREEN_HEIGHT/2 - 100));
	
	pressStartText.setFont(titleFont);
	pressStartText.setColor(sf::Color::White);
	pressStartText.setString("Presione ENTER para comenzar");
	pressStartText.setCharacterSize(30);
	pressStartText.setPosition(sf::Vector2f((SCREEN_WIDTH-pressStartText.getLocalBounds().width)/2.0, (SCREEN_HEIGHT/2)));
	
	lastScore.setFont(scoreFont);
	lastScore.setColor(sf::Color::White);
	stringstream s;
	s<<"Last Score: "<<Global::readLastScore()<<endl;
	lastScore.setString(s.str());
	lastScore.setCharacterSize(20);
	lastScore.setPosition(sf::Vector2f((SCREEN_WIDTH-lastScore.getLocalBounds().width)/2.0, (SCREEN_HEIGHT/2) + 55));
	
	highScore.setFont(scoreFont);
	highScore.setColor(sf::Color::White);
	stringstream ss;
	ss<<"High Score: "<<Global::readHighScore()<<endl;
	highScore.setString(ss.str());
	highScore.setCharacterSize(20);
	highScore.setPosition(sf::Vector2f((SCREEN_WIDTH-highScore.getLocalBounds().width)/2.0, (SCREEN_HEIGHT/2) + 100));
}

void MainScene::update(float delta){
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
			unsigned int levelID = Game::getInstance().levelID;
			Game::getInstance().switchScene(new PlayScene(Game::getInstance().getLevel(levelID)));
		}
}

void MainScene::draw(sf::RenderWindow &window){
	BaseScene::draw(window);
	window.draw(titleText);
	window.draw(pressStartText);
	window.draw(lastScore);
	window.draw(highScore);
}

