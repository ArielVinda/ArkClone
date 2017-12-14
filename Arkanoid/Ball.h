#ifndef BALL_H
#define BALL_H
#include "Entity.h"
#include "Block.h"
#include <cmath>

class Ball : public Entity {
public:
	Ball(sf::Vector2f pos);
	void update(float delta);
	void draw(sf::RenderWindow &window);
	
	float left(){return sprite.getPosition().x - (texture.getSize().x / 2);}
	float right(){return sprite.getPosition().x + (texture.getSize().x / 2);}
	float up(){return sprite.getPosition().y - (texture.getSize().y / 2);}
	float down(){return sprite.getPosition().y + (texture.getSize().y / 2);}
	
	bool checkCollision(Entity* b);
	
//======================================
//	void invertX(){velocity.x*= -1;}
//	void invertY(){velocity.y*= -1;}
//======================================
private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f velocity;
//	float velX;
//	float velY;
	
};

#endif

