#include "PlayScene.h"
#include "TestScene.h"
#include <iostream>
#include "Loader.h"
using namespace std;

PlayScene::PlayScene(sf::Image *level) {
	
	player = new Player(sf::Vector2f(SCREEN_WIDTH/2, SCREEN_HEIGHT - 20));
	add(player);
	ball = new Ball(sf::Vector2f(SCREEN_WIDTH/2, SCREEN_HEIGHT/2));
	add(ball);
	
	for(int i = 0; i < 16; i++){
		for(int j = 0; j < 16; j++){
			if(!level->getPixel(i, j).a == 0){
				Block* block= new Block(sf::Vector2f(i*40, j*20), level->getPixel(i, j));
				blocks.push_back(block);
				add(block);
			}
		}
	}
	Global::score = 0;
}

void PlayScene::update(float delta){
	BaseScene::update(delta);
	ball->checkCollision(player);
	for(auto &block: blocks){
		if(ball->checkCollision(block)){
			Global::score += 100;
			cout<<Global::score<<endl;
			//cout<<"collide"<<endl;
			block->recieveDamage();
			if(block->checkHealth() <= 0){
				remove(block);
				removeBlock(block);
			}
		}
	}
	for(auto td: td_blocks){
		auto it = find(blocks.begin(), blocks.end(), td);
		if(it!=blocks.end())
			blocks.erase(it);
	}
	td_blocks.clear();
	
	if(blocks.size() == 0){
		unsigned int levelID = Game::getInstance().levelID;
		Game::getInstance().switchScene(new PlayScene(Game::getInstance().getLevel(levelID)));
	}
	if(player->health == 0){
		Global::writeScore();
		Game::getInstance().switchScene(new MainScene());
		Game::getInstance().levelID = 0;
	}
	if(ball->down() >= SCREEN_HEIGHT){
		player->health--;
	}
}

void PlayScene::draw (sf::RenderWindow & window) {
	BaseScene::draw(window);
}
