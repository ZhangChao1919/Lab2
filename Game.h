//The file's name: Game.h
//Chao Zhang  zcvictory0329@gmail.com
//Function: The header file declare a class NineAlmondsGame and some necessary enum type variables.

#ifndef GAME_H
#define GAME_H
#include <string>
#include <iostream>

using namespace std;

enum en { good, quit, no_valid };
enum en1{ success, failure };

class NineAlmondsGame
{
private:
	//JZ: hard-coded constants...
	char arr[5][5];

public:
	NineAlmondsGame();
	NineAlmondsGame(char arr1[5][5]);
	~NineAlmondsGame();
	bool done();
	bool stalemate();
	bool prompt(size_t &x, size_t &y);
	bool turn();
	bool play();
	friend ostream &operator<<(ostream &out, const NineAlmondsGame &object);
};

#endif
