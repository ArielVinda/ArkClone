#ifndef TIMER_H
#define TIMER_H

#include <SFML/Graphics.hpp>

class Timer{
public:
	enum STATE{
		RUNNING,
		PAUSED,
		STOP
	};
	static void startTimer(){
		state = RUNNING;
	}
	static void pauseTimer(){
		state = PAUSED;
	}
	static void stopTimer(){
		state = STOP;
		time.seconds(0.0f); 
	}
	
	static int getTime(){
		return (int)time.asSeconds();
	}
private:
	unsigned int state;
	sf::Clock counter;
	sf::Time time;
};

#endif
