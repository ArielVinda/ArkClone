#ifndef GLOBAL_H
#define GLOBAL_H

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 640

#include <fstream>
#include <vector>
using namespace std;

class Global{
public:
	static int score;
	static float velocity;
	static void writeScore();
	static int readLastScore();
	static int readHighScore();
	static vector<int> scores;
private:
};

#endif
