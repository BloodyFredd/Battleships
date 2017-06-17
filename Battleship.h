/* Assignment: 2
Campus: Beer Sheva
Author: Freddy Gorenshtein, ID: 310017280
*/

// This is the .h of a battleship. Here I built the private and public functions.

#define _CRT_SECURE_NO_WARNINGS
#ifndef BATTLESHIP_H
#define BATTLESHIP_H
#include <iostream>
using namespace std;
class Battleship
{
	int ShipLength;
	static int numOfShips;
public:
	
	Battleship();
	int getShipLength() const { return ShipLength; }
};
#endif
