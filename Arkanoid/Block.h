#ifndef BLOCK_H
#define BLOCK_H
#include "Entity.h"

class Block : public Entity {
public:
	Block(sf::Vector2f pos);
	Block(sf::Vector2f pos, sf::Color color);
	void update(float delta);
	void draw(sf::RenderWindow &window);
	
	void recieveDamage();
	unsigned int checkHealth(){return health;}
	
	float left(){return sprite.getPosition().x;}
	float right(){return sprite.getPosition().x + (sprite.getTextureRect().width);}
	float up(){return sprite.getPosition().y;}
	float down(){return sprite.getPosition().y + (sprite.getTextureRect().height);}
private:
	sf::Texture texture;
	sf::Sprite sprite;
	
	unsigned int health;
};

#endif

