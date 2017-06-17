/* Assignment: 2
Campus: Beer Sheva
Author: Freddy Gorenshtein, ID: 310017280
*/

// This is the .h of the game. Here I built the private and public functions.

#include "Battleship.h"
#ifndef GAME_H
#define GAME_H
#define N 10

class Game
{
	char board[N][N];
	Battleship *Ships;
	static int sumOfShips;
	int getInt(char) const;
	char getChar(int) const;
	bool CheckPlace(const char, const int, const int, const int);
	void CheckHit(char, int);
	bool CheckSunk(const char, const int) const;
	void BuildBoard(int);
	void ClearBoard();
public:
	Game(int);
	~Game();
	void PrintBoard() const;
	void PrintOriginalBoard() const;
	void Play(int);
};
#endif
