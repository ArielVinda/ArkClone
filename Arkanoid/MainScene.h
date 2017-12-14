#ifndef MAINSCENE_H
#define MAINSCENE_H
#include "BaseScene.h"

class MainScene : public BaseScene {
public:
	MainScene();
	void update(float delta);
	void draw(sf::RenderWindow &window);
private:
	sf::Text titleText;
	sf::Text pressStartText;
	sf::Text lastScore;
	sf::Text highScore;
	sf::Font titleFont;
	sf::Font scoreFont;
};

#endif

