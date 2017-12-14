#include "Player.h"
//#include <iostream>
//using namespace std;

Player::Player(sf::Vector2f pos) {
	texture.loadFromFile("assets/images/Paddle.png");
	sprite.setTexture(texture);
	sprite.setOrigin(((sf::Vector2f)texture.getSize())/2.0f);
	sprite.setPosition(pos);
	
	health = 3;
	
	for(int i = 0; i < health; i++){
		sf::Sprite aux;
		aux.setTexture(texture);
		aux.setPosition(25*i, SCREEN_HEIGHT - 10);
		aux.setScale(0.4f,0.4f);
		mini.push_back(aux);
	}
	
	velocity = sf::Vector2f(0.0f,0.0f);
}

void Player::update(float delta){
	// Player velo = 3/2 Global velo
	float velo = Global::velocity * 1.5;
	//Leer Izquierda / Derecha
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)||
	   sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		velocity.x = -velo;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)||
	   sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		velocity.x = velo;
	//Mover Sprite
	sprite.move(velocity*delta);
	//No pasar bordes de pantalla
	//Si posicion < 0, posicion = 0 + offset
	//Si posicion > pantalla, posicion = pantalla - offset
	//Offset = ancho player / 2
	if(left()<0)
		sprite.setPosition(30,sprite.getPosition().y);
	if(right()>SCREEN_WIDTH)
		sprite.setPosition(SCREEN_WIDTH - 30, sprite.getPosition().y);
	//Frenar personaje al soltar teclado
	velocity = sf::Vector2f(0.0f,0.0f);	
}

void Player::draw(sf::RenderWindow &window) {
	window.draw(sprite);
	for(auto &l:mini){
		window.draw(l);
	}
}

