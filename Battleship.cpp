/* Assignment: 2
Campus: Beer Sheva
Author: Freddy Gorenshtein, ID: 310017280
*/

// This is the .cpp of a battleship. Here I use the functions which I described at the .h file.

#include "Battleship.h"

// This is the ctor of the battleship. I check how many battleships I have with the static and what length each one has.
Battleship::Battleship() {
	numOfShips++;
	if (this->numOfShips == 1)
		this->ShipLength = 5;
	if (this->numOfShips == 2)
		this->ShipLength = 4;
	if ((this->numOfShips == 3) || (this->numOfShips == 5))
		this->ShipLength = 3;
	if (this->numOfShips == 4)
		this->ShipLength = 2;
}