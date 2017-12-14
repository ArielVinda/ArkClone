#ifndef TESTSCENE_H
#define TESTSCENE_H
#include "BaseScene.h"
#include "Player.h"
#include "Ball.h"
#include "Block.h"

class TestScene : public BaseScene {
public:
	TestScene();
	void update(float delta);
	void draw(sf::RenderWindow & window);
private:
	Player* player;
	Ball* ball;
	vector<Block*> blocks;
	vector<Block*> td_blocks;
	void removeBlock(Block* b){td_blocks.push_back(b);}
};

#endif

