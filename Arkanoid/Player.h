#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"
#include <vector>
using namespace std;

class Player : public Entity {
public:
	Player(sf::Vector2f pos);
	void update(float delta);
	void draw(sf::RenderWindow &window);
	
	float left(){return sprite.getPosition().x - (texture.getSize().x / 2);}
	float right(){return sprite.getPosition().x + (texture.getSize().x / 2);}
	float up(){return sprite.getPosition().y - (texture.getSize().y / 2);}
	float down(){return sprite.getPosition().y + (texture.getSize().y / 2);}
	
	int health;
private:
	sf::Texture texture;
	sf::Sprite sprite;
	vector<sf::Sprite> mini;
	
	sf::Vector2f velocity;
};

#endif

