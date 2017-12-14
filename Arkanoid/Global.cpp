#include "Global.h"
#include <algorithm>
#include <iostream>
using namespace std;

int Global::score = 0;
float Global::velocity = 300;

void Global::writeScore(){
	ofstream file("scores.txt", ios::app);
	if(!file.is_open()){
		file.open("scores.txt", ios::trunc);
	}
	file<<score<<endl;
	file.close();
}

int Global::readLastScore(){
	ifstream file("scores.txt");
	if(!file.is_open()){
		cout<<"scores.txt not open"<<endl;
		return 0;
	}
	int aux;
	vector<int> scores;
	while(file>>aux){
		scores.push_back(aux);
	}
	file.close();
	if(scores.size() == 0){
		return 0;
	}
	auto it = scores.end();
	it--;
	return *it;
}

int Global::readHighScore(){
	ifstream file("scores.txt");
	int aux;
	vector<int> scores;
	while(file>>aux){
		scores.push_back(aux);
	}
	file.close();
	if (scores.size() == 0)
		return 0;
	sort(scores.begin(), scores.end());
	auto it = scores.end();
	it--;
	return *it;
}
