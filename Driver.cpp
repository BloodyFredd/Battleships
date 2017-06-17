/* Assignment: 2
Campus: Beer Sheva
Author: Freddy Gorenshtein, ID: 310017280
*/

// This is the main program, from here the user plays the game.
#include "Game.h"

int main()
{ // Ask the user how many ships he would like to have.
	cout << "How many battleships do you want to place on the board? (1 - 5)" << endl;
	int num;
	cin >> num;
	Game game1(num); // Make a new game and call the function.
	if ((num > 5) || (num < 1)) // If higher than 5 or lower than 1, try again.
		num = 1;
	game1.Play(num);
	return 0;
}