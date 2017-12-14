#include "TestScene.h"
#include <iostream>
#include "Loader.h"
using namespace std;

TestScene::TestScene() {
	Loader* loader = new Loader();
	player = new Player(sf::Vector2f(SCREEN_WIDTH/2, SCREEN_HEIGHT - 20));
	add(player);
	ball = new Ball(sf::Vector2f(SCREEN_WIDTH/2, SCREEN_HEIGHT/2));
	add(ball);
	for(int i = 40; i < SCREEN_WIDTH - 40; i += 40){
		for(int j = 20; j <= 20 * 10; j += 20){
			Block* block= new Block(sf::Vector2f(i, j));
			blocks.push_back(block);
			add(block);
		}
	}
}

void TestScene::update(float delta){
	BaseScene::update(delta);
	ball->checkCollision(player);
	for(auto &block: blocks){
		if(ball->checkCollision(block)){
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
}

void TestScene::draw (sf::RenderWindow & window) {
	BaseScene::draw(window);
}

