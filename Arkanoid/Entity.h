#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include "Global.h"

class Entity{
public:
	virtual void update(float delta) = 0;
	virtual void draw(sf::RenderWindow &window) = 0;
	
	virtual float left() = 0;
	virtual float right() = 0;
	virtual float up() = 0;
	virtual float down() = 0;
private:
};

#endif
