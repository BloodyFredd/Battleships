/* Assignment: 2
Campus: Beer Sheva
Author: Freddy Gorenshtein, ID: 310017280
*/

// This is the .cpp of the game. Here I use all the functions I named in the .h file.

#include "Game.h"
#include <ctime> 
#include <string>
int Battleship::numOfShips = 0;
int Game::sumOfShips = 0;

// This is my ctor of the game.
Game::Game(int num) {
	int tmp;
	if ((num > 5) || (num < 1)) { // If the user pressed something different than 1-5 ships, build only one.
		Ships = new Battleship;
		tmp = 1;
	}
	else { // Build ships according to num.
		Ships = new Battleship[num];
		tmp = num;
	}

	while (tmp > 0) { // sum how many length of ships.
		sumOfShips += Ships[tmp - 1].getShipLength();
		tmp--;
	}
}

// This is the dtor of the game.
Game::~Game() {
	delete[] Ships;
}

// This function clears the board with '_'.
void Game::ClearBoard() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			this->board[i][j] = '_';
		}
	}
}

// This function checks if a given place is okay to build a ship in, according to its place on the board and length.
bool Game::CheckPlace(const char index, const int i, const int state, const int place) {
	int j = getInt(index), length = Ships[place].getShipLength();
	if (board[i - 1][j - 1] == 'S') // If the place has a part of a ship on the index, false.
		return false;
	if (state == 1) { // If vertical, go in.
		if ((length + i) > N) // If the total length is higher than 10, false.
			return false;
		else
		{
			if ((i != 1) && (j != 1) && (i != 10) && (j != 10)) { // Check if not at either side.
																  // Check at all the places near the sides of the ship.
				if (board[i - 2][j - 1] == 'S')
					return false;
				if (board[i - 2][j - 2] == 'S')
					return false;
				if (board[i + length][j - 2] == 'S')
					return false;
				if (board[i - 2][j] == 'S')
					return false;
				if (board[i + length][j] == 'S')
					return false;
				if (board[i + length][j - 1] == 'S')
					return false;
				while (length >= 0) { // Check along the sides of the ship.
					if (board[i + length - 1][j - 2] == 'S')
						return false;
					if (board[i + length - 1][j] == 'S')
						return false;
					if (board[i + length - 1][j - 1] == 'S')
						return false;
					length--;
				}
			}
			length = Ships[place].getShipLength();
			if (j == 10) { // If the ship will be built at one of the sides.
				if (i != 1) { // If not at the corner.
					if (board[i - 2][j - 1] == 'S')
						return false;
					if (board[i - 2][j - 2] == 'S')
						return false;
				} // If the corner.
				if (board[i + length][j - 1] == 'S')
					return false;
				if (board[i + length][j - 2] == 'S')
					return false;
				while (length >= 0) { // Check the sides along the ship.
					if (board[i + length - 1][j - 2] == 'S')
						return false;
					if (board[i + length - 1][j - 1] == 'S')
						return false;
					length--;
				}
			}
			length = Ships[place].getShipLength();
			if (j == 1) { // If the ship will be built at one of the sides.
				if (i != 1) { // If not at the corner.
					if (board[i - 2][j - 1] == 'S')
						return false;
					if (board[i - 2][j] == 'S')
						return false;
				} // If the corner.
				if (board[i + length][j - 1] == 'S')
					return false;
				if (board[i + length][j] == 'S')
					return false;
				while (length >= 0) { // Check the sides along the ship.
					if (board[i + length - 1][j] == 'S')
						return false;
					if (board[i + length - 1][j - 1] == 'S')
						return false;
					length--;
				}
			}
			length = Ships[place].getShipLength();
			if (i == 1) { // If the ship will be built at one of the sides.
				if (j != 1) { // If not at the corner.
					if (board[i + length][j - 2] == 'S')
						return false;
					if (board[i][j - 2] == 'S')
						return false;
				} // If the corner.
				if (board[i + length][j] == 'S')
					return false;
				if (j != 10) {
					if (board[i + length][j + 1] == 'S')
						return false;
				}
				while (length >= 0) { // Check the sides along the ship.
					if (board[i + length - 1][j] == 'S')
						return false;
					if (board[i + length - 1][j - 2] == 'S')
						return false;
					length--;
				}
			}
		}
	}
	length = Ships[place].getShipLength();
	if (state == 0) { // If the ship will be built at the width.
		if ((length + j) > N) // If the total length is higher than 10, false.
			return false;
		else
		{
			if ((i != 1) && (j != 1) && (i != 10) && (j != 10)) { // If not at the corners.
																  // Check at all the places near the sides of the ship.
				if (board[i - 1][j - 2] == 'S')
					return false;
				if (board[i - 1][j + length] == 'S')
					return false;
				if (board[i - 2][j - 2] == 'S')
					return false;
				if (board[i][j - 2] == 'S')
					return false;
				if (board[i - 2][j + length] == 'S')
					return false;
				if (board[i][j + length] == 'S')
					return false;
				while (length >= 0) { // Check along the length of the ship.
					if (board[i - 2][j + length - 1] == 'S')
						return false;
					if (board[i][j + length - 1] == 'S')
						return false;
					if (board[i - 1][j + length - 1] == 'S')
						return false;
					length--;
				}
			}
			length = Ships[place].getShipLength();
			if (i == 10) { // If the ship will be built at one of the sides.
				if (j != 1) { // If not at the corner.
					if (board[i - 1][j - 2] == 'S')
						return false;
					if (board[i - 2][j - 2] == 'S')
						return false;
				} // If the corner.
				if (board[i - 1][j + length] == 'S')
					return false;
				if (board[i - 2][j + length] == 'S')
					return false;
				while (length >= 0) { // Check the sides along the ship.
					if (board[i - 2][j + length - 1] == 'S')
						return false;
					if (board[i - 1][j + length - 1] == 'S')
						return false;
					length--;
				}
			}
			length = Ships[place].getShipLength();
			if (i == 1) { // If the ship will be built at one of the sides.
				if (j != 1) { // If not at the corner.
					if (board[i - 1][j - 2] == 'S')
						return false;
					if (board[i][j - 2] == 'S')
						return false;
				} // If the corner.
				if (board[i - 1][j + length] == 'S')
					return false;
				if (board[i][j + length] == 'S')
					return false;
				while (length >= 0) { // Check the sides along the ship.
					if (board[i][j + length - 1] == 'S')
						return false;
					if (board[i - 1][j + length - 1] == 'S')
						return false;
					length--;
				}
			}
			length = Ships[place].getShipLength();
			if (j == 1) { // If the ship will be built at one of the sides.
				if (i != 1) { // If not at the corner.
					if (board[i - 2][j - 1] == 'S')
						return false;
					if (board[i - 2][j + length - 1] == 'S')
						return false;
				} // If the corner.
				if (board[i - 1][j + length - 1] == 'S')
					return false;
				if (board[i - 2][j + length - 1] == 'S')
					return false;
				if (board[i][j + length - 1] == 'S')
					return false;
				while (length >= 0) { // Check the sides along the ship.
					if (board[i][j + length - 1] == 'S')
						return false;
					if (board[i - 2][j + length - 1] == 'S')
						return false;
					length--;
				}
			}
		}
	} // If all is okay, return true.
	return true;
}

// This is the function that prints the board without the 'S' symbol, for the player.
void Game::PrintBoard() const {
	cout << "/" << "  ";
	char tav = 'a';
	for (int i = 0; i < N; i++) { // First print the alphabet.
		cout << tav << "  ";
		tav++;
	}
	cout << endl;
	int num = 1;
	for (int i = 0; i < N; i++) { // Now for the rest.
		for (int j = 0; j < N + 1; j++) {
			if (j == 0) { // Print the numbers at the side. 
				if (i == 9) { // If you got to 10, give it less space, so it would look more aesthetic.
					cout << num << " ";
					num++;
				}
				else
				{
					cout << num << "  ";
					num++;
				}
			}
			else
			{ // If found a ship, change it to '_'.
				if (board[i][j - 1] != 'S')
					cout << board[i][j - 1] << "  ";
				else cout << '_' << "  ";
			}
		}
		cout << endl << endl;
	}
}

// This function prints the original board, with the ships. This is the hint for the user.
void Game::PrintOriginalBoard() const {
	cout << "/" << "  ";
	char tav = 'a';
	for (int i = 0; i < N; i++) { // First print the alphabet.
		cout << tav << "  ";
		tav++;
	}
	cout << endl;
	int num = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N + 1; j++) {
			if (j == 0) { // Print the numbers at the side.
				if (i == 9) { // If you got to 10, give it less space, so it would look more aesthetic.
					cout << num << " ";
					num++;
				}
				else
				{
					cout << num << "  ";
					num++;
				}
			}
			else
				cout << board[i][j - 1] << "  ";
		}
		cout << endl << endl;
	}
}

// This is my function that gets a char and returns int accordingly.
int Game::getInt(char tav) const {
	if (tav == 'a')
		return 1;
	if (tav == 'b')
		return 2;
	if (tav == 'c')
		return 3;
	if (tav == 'd')
		return 4;
	if (tav == 'e')
		return 5;
	if (tav == 'f')
		return 6;
	if (tav == 'g')
		return 7;
	if (tav == 'h')
		return 8;
	if (tav == 'i')
		return 9;
	if (tav == 'j')
		return 10;
	return 0;
}

// This is my function that gets a int and returns char accordingly.
char Game::getChar(int x) const {
	if (x == 1)
		return 'a';
	if (x == 2)
		return 'b';
	if (x == 3)
		return 'c';
	if (x == 4)
		return 'd';
	if (x == 5)
		return 'e';
	if (x == 6)
		return 'f';
	if (x == 7)
		return 'g';
	if (x == 8)
		return 'h';
	if (x == 9)
		return 'i';
	if (x == 10)
		return 'j';
	return 'X';
}

// This is the function that checks a hit at the board.
void Game::CheckHit(char tav, int i) {
	int j = getInt(tav);
	if ((board[i - 1][j - 1] == '@') || (board[i - 1][j - 1] == 'X')) // Check if already tried this place.
		cout << "You already tried this place." << endl;
	if (board[i - 1][j - 1] == '_') { // If nothing found, change to 'X'.
		cout << "Sorry, you just missed." << endl;
		board[i - 1][j - 1] = 'X';
	}
	if (board[i - 1][j - 1] == 'S') { // if found, change to '@'.
		cout << "You got a hit!!!!" << endl;
		board[i - 1][j - 1] = '@';
	}
}

// This is the function that checks if a ship, in a given place, is sunk.
bool Game::CheckSunk(const char tav, const int i) const {
	int j = getInt(tav), count = 0;
	bool flag = true;
	int n = i, m = j;
	if ((board[i - 1][j - 1] == 'X') || (board[i - 1][j - 1] == '_'))
		return false; // If the place has 'X' or '_', return false.
	if (i != 1) { // If not at corner.
		while ((n > 1) && (flag)) { // Check up.
			if ((board[n - 1][m - 1] == 'X') || (board[n - 1][m - 1] == '_'))
				flag = false;
			if (board[n - 1][m - 1] == 'S')
				return false;
			n--;
		}
	}
	n = i, flag = true;
	if (i != 10) { // If not at corner.
		while ((n < 10) && (flag)) { // Check down.
			if ((board[n - 1][m - 1] == 'X') || (board[n - 1][m - 1] == '_'))
				flag = false;
			if (board[n - 1][m - 1] == 'S')
				return false;
			n++;
		}
	}
	n = i, flag = true;
	if (j != 1) { // If not at corner.
		while ((m > 1) && (flag)) { // Check to the left.
			if ((board[n - 1][m - 1] == 'X') || (board[n - 1][m - 1] == '_'))
				flag = false;
			if (board[n - 1][m - 1] == 'S')
				return false;
			m--;
		}
	}
	m = j, flag = true;
	if (j != 10) { // If not at corner.
		while ((m < 10) && (flag)) { // Check to the right.
			if ((board[n - 1][m - 1] == 'X') || (board[n - 1][m - 1] == '_'))
				flag = false;
			if (board[n - 1][m - 1] == 'S')
				return false;
			m++;
		}
	} // If all is okay, return true.
	return true;
}

// This is the function that builds the board with ships, according to the num of ships the user wants.
void Game::BuildBoard(int num) {
	ClearBoard(); // Call a function to place '_' at the board.
	srand((unsigned)time(0));
	char tav = 'a';
	int i = 0, j = 0, state = 0, index = 0, length;
	while (num > 0) { // Build ships according to num.
		do
		{ // Randomize 3 numbers, two for the place and one for the position.
			i = rand() % 10 + 1;
			tav = getChar(i);
			j = rand() % 10 + 1;
			state = rand() % 2;
			// Run until the place is okay.
		} while (!CheckPlace(tav, j, state, index));
		length = Ships[index].getShipLength(); // Get the length of the ship.
		if (state == 0) { // If width, print accordingly on the board.
			while (length > 0) {
				board[j - 1][i - 1] = 'S';
				i++;
				length--;
			}
		}
		length = Ships[index].getShipLength();
		if (state == 1) { // If vertical, print accordingly on the board.
			while (length > 0) {
				board[j - 1][i - 1] = 'S';
				j++;
				length--;
			}
		}
		index++;
		num--;
	}
}

// This is the main function for the game, which uses all the other.
void Game::Play(int num) {
	BuildBoard(num);
	int count = 0, j; // Check if the user wants a hint.
	cout << "Do you want a hint? [y/n]" << endl;
	char tav;
	string str;
	cin >> tav;
	bool flag2 = false;
	while ((tav != 'y') && (tav != 'n')) { // Check if the user entered correctly.
		cout << "Try again." << endl;
		fflush(stdin);
		cin >> tav;
	} // If yes, print the hint once.
	if (tav == 'y') {
		PrintOriginalBoard();
		cout << "Memorize the board and press enter to start." << endl;
	}
	do
	{ // Run until the user sunk all the battleships.
		system("pause");
		system("cls"); // The user should enter only <char num>.
		cout << "Please enter your guess: one char and one number. <x y> only. To exit press 0." << endl;
		bool flag;
		do
		{ // Run until the user presses correctly.
			flag = false;
			fflush(stdin);
			getline(cin, str);
			if (str != "") {
				j = atoi(&str[1]); // Check if the first one is a fine letter, than space and than a fine number.
				if (str[0] == '0') {
					flag2 = true;
					break;
				}
				if ((j > 0) && (j < 11) && (str[0] >= 'a') && (str[0] <= 'j') && (str[1] == ' '))
					flag = true;
				if (!flag)
					cout << "Wrong choise, try again." << endl;
			}
			fflush(stdin);
		} while (!flag);
		if (flag2 == true)
			break;
		CheckHit(str[0], j); // Check if you hit a ship.
		if (CheckSunk(str[0], j)) { // If sunk a ship.
			cout << "Hit!!" << endl << "Battleship sunk!!" << endl;
			count++; // Count the sunked ships.
		}
		PrintBoard(); // Print the board each time.
	} while (count != num);
	if (num == count)
		cout << "You won!!" << endl << "The game has ended!!" << endl; // The end game.
	else cout << "Thanks for playing." << endl;
}