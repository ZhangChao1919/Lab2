//The file's name: Game.cpp
//Chao Zhang  zcvictory0329@gmail.com
//Function: The source file defines member function and initializes a class object.
//Then I achieve the program in the main() function.

//JZ: program would not compile until this line was added
#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include "Game.h"
using namespace std;

//This is an operator<<() function. Through the function we can write cout<<object correctly.
ostream &operator<<(ostream &out, const NineAlmondsGame& object)
{
	//JZ: hard-coded constants
	for (int j = 4; j >= 0; j--)
	{
		out << j << " ";
		for (int i = 0; i<5; i++)
		{
			out << object.arr[i][j] << " ";
		}
		out << endl;
	}
	out << "X 0 1 2 3 4" << endl;
	return out;
}

//This is a default constructor function.
NineAlmondsGame::NineAlmondsGame() {}

//This is another constructor function.
NineAlmondsGame::NineAlmondsGame(char arr1[5][5])
{
	for (int i = 0; i<5; i++)
	{
		for (int j = 0; j<5; j++)
		{
			arr[i][j] = arr1[i][j];
		}
	}
}

//This is a deconstructor function. 
//JZ: adding this deconstructor was unnecessary particularly since 
//compiler would've supplied one anyways.
NineAlmondsGame::~NineAlmondsGame() {}

//This is a done() function. It will give the definition that the final condition if we move many times successfully.
//Namyly there is only a game piece in the center of the game board.
bool NineAlmondsGame::done()
{
	for (int i = 0; i<2; i++)
	{
		for (int j = 0; j<5; j++)
		{
			//JZ: use positive logic where possible:
			//if it /isn't/ ' ', return false; then the continue becomes implicit
			if (arr[i][j] == ' ')
				continue;
			else
				return false;
		}
	}

	for (int i = 3; i<5; i++)
	{
		for (int j = 0; j<5; j++)
		{
			//JZ: use positive logic
			if (arr[i][j] == ' ')
				continue;
			else
				return false;
		}
	}

	for (int j = 0, i = 2; j<5; j++)
	{
		if (j != 2 && arr[2][j] == ' ') continue;
		else if (arr[2][2] == 'A') continue;
		else return false;
	}
	return true;
}

//This is a stalemate() function. It tells us that if there is only one game piece left in the center of the game board or
//there is another valid move left on the game board, it will return false, otherwise it will return true namely there is
//no valid moves.
bool NineAlmondsGame::stalemate()
{
	//JZ: hard-coding
	for (int i = 0; i<5; i++)
	{
		for (int j = 0; j<5; j++)
		{
			if (done() || (arr[i][j] == 'A' && ((arr[i - 1][j] == 'A'&& arr[i - 2][j] == ' ')
				|| (arr[i - 1][j - 1] == 'A'&& arr[i - 2][j - 2] == ' ')
				|| (arr[i - 1][j + 1] == 'A'&& arr[i - 2][j + 2] == ' ')
				|| (arr[i][j - 1] == 'A'&& arr[i][j - 2] == ' ')
				|| (arr[i][j + 1] == 'A'&& arr[i][j + 2] == ' ')
				|| (arr[i + 1][j - 1] == 'A'&& arr[i + 2][j - 2] == ' ')
				|| (arr[i + 1][j] == 'A'&& arr[i + 2][j] == ' ')
				|| (arr[i + 1][j + 1] == 'A'&& arr[i + 2][j + 2] == ' '))))
			{
				return false;
				break;
			}

		}
	}
	return true;
}

//This is a prompt() function. It prompts us to input two pairs of coordinates. Then I will test whether these coordiantes 
//are valid. If it is quit, I will stop the game. If it is not a valid coordinate, I can reenter. If it is valid, I will
//change the string to size_t type.
bool NineAlmondsGame::prompt(size_t &x, size_t &y)
{
	cout << "Please enter quit or a valid string: ";
	string str;
	while (cin >> str)
	{
		if (str == "quit")
		{
			cout << "The user asks to quit." << endl;
			break;
		}
		else
		{
			if (str.length() != 3 || (str[0]<'0' || str[0]>'4' || str[2]<'0' || str[2]>'4'))
			{
				cout << "Please enter quit or a valid string again: ";
				continue;
			}
			else
			{
				str[1] = ' ';
				istringstream ss(str);
				ss >> x >> y;

			}
		}
		return good;
	}
	return quit;
}

//This is a turn() function. It will make some moves according input coordinates. Then I can test whether I will continue 
//inputing coordinates or not.
bool NineAlmondsGame::turn()
{
	size_t x1, y1, x2, y2;
	size_t startx, starty;
	//This part means we can at least make one move on the game board.
	if (!prompt(x1, y1))
	{
		prompt(x2, y2);
		arr[x1][y1] = ' ';
		arr[x2][y2] = 'A';
		arr[(x1 + x2) / 2][(y1 + y2) / 2] = ' ';
		cout << (*this);
		cout << endl;
		cout << x1 << "," << y1 << " to " << x2 << "," << y2 << endl;
		cout << "Continue this turn (YyNn)? ";
		startx = x2; starty = y2;
		//Then I test whether I will continue inputting or not.
		char ch;
		while (cin >> ch)
		{
			if (ch == 'N' || ch == 'n')
				break;
			else
			{
				cout << "Please enter an additional square." << endl;
				size_t endx, endy;
				size_t x3, y3;
				prompt(x3, y3);
				endx = x3; endy = y3;
				arr[startx][starty] = ' ';
				arr[endx][endy] = 'A';
				arr[(startx + endx) / 2][(starty + endy) / 2] = ' ';
				cout << (*this);
				cout << endl;
				cout << startx << "," << starty << " to " << endx << "," << endy << endl;
				startx = endx; starty = endy;
				cout << "Continue this turn (YyNn)? ";
			}
		}
		return good;
	}
	else
		return quit;
}

//This is a play() function. It saves the final turns we need. I also give three conditions that I will face.
bool NineAlmondsGame::play()
{
	cout << (*this);
	int times = 0;
	while (!turn())
	{
		times++;
		if (done())
		{
			cout << times << " turns were played to complete the game successfully." << endl;
			return good;
		}
		else if (stalemate())
		{
			cout << times << " turns were played and no valid movies remain." << endl;
			return bool(no_valid);
		}
	}
	cout << times << " turns were played and the user quit." << endl;
	return quit;
}

//This is a usage_message() function. It tell readers how to do when they do not input game name in the command line.
int usage_message(string& str, string str1)
{
	cout << "You should enter another string(NineAlmonds) in the command line. Then you should input different coordinates." << endl;
	return failure;
}

//This is main() function to achieve the whole program.
int main(int argc, char* argv[])
{
	//If I do not input game name, It will call usage_message() function to prompt readers how to do.
	//JZ: magic numbers, also does not treat too many args as an error case
	if (argc == 1)
	{
		string str, str1;
		str = argv[0];
		str1 = "NineAlmonds";
		return usage_message(str, str1);
	}
	else
	{
		//If we input a wrong game name, it will also prompt reader how to do. 
		string str2 = "NineAlmonds";
		if (argv[1] != str2)
		{
			cout << "The game name is wrong. Please enter NineAlmonds." << endl;
			return false;
		}
		else
		{
			//I initialize the class object. Then calling play() function to achieve the whole program.
			char ch[5][5] = { { ' ', ' ', ' ', ' ', ' ' }, { ' ', 'A', 'A', 'A', ' ' },
			{ ' ', 'A', 'A', 'A', ' ' }, { ' ', 'A', 'A', 'A', ' ' }, { ' ', ' ', ' ', ' ', ' ' } };
			NineAlmondsGame obj = NineAlmondsGame(ch);
			return obj.play();
		}
	}
}


