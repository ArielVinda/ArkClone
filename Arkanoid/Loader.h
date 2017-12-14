#ifndef LOADER_H
#define LOADER_H

#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


class Loader {
public:
	Loader();
	sf::Image getImage(int i);
	vector<string> levels;
private:
};

#endif

