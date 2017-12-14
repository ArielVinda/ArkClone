#include "Block.h"
#include <iostream>
using namespace std;

Block::Block(sf::Vector2f pos){
	sf::IntRect area(0,0,40,20);
	texture.loadFromFile("assets/images/Block-sheet.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(area);
	sprite.setPosition(pos);
	
	health = 3;
}

Block::Block(sf::Vector2f pos, sf::Color color) : Block(pos){
//	sf::IntRect area(0,0,40,20);
//	texture.loadFromFile("assets/images/Block-sheet.png");
//	sprite.setTexture(texture);
//	sprite.setTextureRect(area);
//	sprite.setPosition(pos);
	sprite.setColor(color);
	if(sprite.getColor() == sf::Color::Red)
		health = 3;
	else if (sprite.getColor() == sf::Color::Green)
		health = 2;
	else
		health = 1;
}

void Block::update(float delta){
	
}

void Block::draw(sf::RenderWindow &window){
	window.draw(sprite);
}

void Block::recieveDamage(){
	health--;
	int shuff = sprite.getTextureRect().left + 40;
	sprite.setTextureRect(sf::IntRect(shuff,0,40,20));
	//sprite.setColor(sf::Color::Red);
	//cout<<health<<endl;
}

