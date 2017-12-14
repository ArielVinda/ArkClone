#ifndef BASESCENE_H
#define BASESCENE_H

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include <vector>
#include "Global.h"
using namespace std;

class BaseScene {
public:
	BaseScene();
	
	virtual void update(float delta);
	virtual void draw(sf::RenderWindow &window);
	
	void add(Entity* e);
	void remove(Entity* e);
private:
	vector<Entity*> entities;
	vector<Entity*> to_delete;
};

#endif
