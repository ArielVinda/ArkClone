#include "BaseScene.h"

BaseScene::BaseScene(){}

void BaseScene::update(float delta){
	// Actualizar todas las entidades en escena
	for(auto e:entities){
		e->update(delta);
	}
	
	// Remover entidades en la cola to_delete
	for(auto td: to_delete){
		auto it = find(entities.begin(), entities.end(), td);
		if (it!=entities.end())
			entities.erase(it);
	}
	
	// Limpiar cola to_delete
	to_delete.clear();
}

void BaseScene::draw(sf::RenderWindow &window){
	for(auto e: entities)
		e->draw(window);
}

void BaseScene::add(Entity* e){
	// Agregar entidad
	entities.push_back(e);
}

void BaseScene::remove(Entity* e){
	// Enviar entidad a to_delete
	to_delete.push_back(e);
}
