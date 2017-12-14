#include "Ball.h"
//#include <iostream>
using namespace std;

Ball::Ball(sf::Vector2f pos){
	texture.loadFromFile("assets/images/Ball.png");
	sprite.setTexture(texture);
	sprite.setOrigin(((sf::Vector2f)texture.getSize())/2.0f);
	sprite.setPosition(pos);
	
	velocity = sf::Vector2f(Global::velocity,-Global::velocity - 20);
//	cout<<"left:"<<left()<<" right:"<<right()<<" up:"<<up()<<" down:"<<down()<<endl;
}

void Ball::update(float delta){
	sprite.move(velocity*delta);
//======================================
//	if(left()<0 || right()>SCREEN_WIDTH)
//		invertX();
//	if(up()<0 || down()>SCREEN_HEIGHT)
//		invertY();
//======================================
	if(left()<0)
		velocity.x = Global::velocity;
	if(right()>SCREEN_WIDTH)
		velocity.x = -Global::velocity;
	if(up() < 0)
		velocity.y = Global::velocity;
	if(down() > SCREEN_HEIGHT)
		velocity.y = -Global::velocity;
}

void Ball::draw(sf::RenderWindow &window){
	window.draw(sprite);
}

bool Ball::checkCollision(Entity* e){
	if(e->left() < right() && e->right() > left() &&
	   e->up() < down() && e->down() > up()){
		float overlapLeft(right() - e->left());
		float overlapRight(e->right() - left());
		float overlapTop(down() - e->up());
		float overlapBottom(e->down() - up());
		
		bool FromLeft(abs(overlapLeft)<abs(overlapRight));
		bool FromTop(abs(overlapTop)<abs(overlapBottom));
		
		float minOverlapX(FromLeft ? overlapLeft : overlapRight);
		float minOverlapY(FromTop ? overlapTop : overlapBottom);
		
		if(abs(minOverlapX)< abs(minOverlapY)){
//=============================================================================================================
//			float posx = FromLeft ? e->left() - texture.getSize().x / 2: e->right() + texture.getSize().x / 2;
//			sprite.setPosition(posx, sprite.getPosition().y);
//			invertX();
//=============================================================================================================
			velocity.x = FromLeft ? -Global::velocity : Global::velocity;
		}
		else{
//=============================================================================================================
//			float posy = FromTop ? e->up() - texture.getSize().y / 2: e->down() + texture.getSize().y / 2;
//			sprite.setPosition(sprite.getPosition().x, posy);
//			invertY();
//=============================================================================================================
			velocity.y = FromTop ? -Global::velocity : Global::velocity;
		}
		return true;
	}
	return false;
}

