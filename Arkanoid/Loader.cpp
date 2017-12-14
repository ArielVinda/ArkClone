#include "Loader.h"
#include <iostream>
#include <sstream>
using namespace std;

Loader::Loader() {
	cout<<"loader created"<<endl;
	ifstream registry("assets/images/levels/Registry.txt");
	if(!registry.is_open())
		cout<<"file not opened"<<endl;
	string aux;
	while(registry>>aux){
		levels.push_back(aux);
		cout<<aux<<endl;
	}
}

sf::Image Loader::getImage(int i){
	string path = "assets/images/levels/";
	stringstream s;
	s<<path<<levels[i];
	string fullpath = s.str();
	sf::Image level;
	level.loadFromFile(fullpath);
	return level;
}

