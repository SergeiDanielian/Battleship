/*
Programmer: Sergei Danielian
Title: Lab 7
Date: November 5th, 2015
Filename: lab7.cpp
Purpose: To simulate a ship warfare game on a 10x10 grid using 2 dimensional arrays.
*/
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

string ocean = "-", miss = "x ", enemy = "E ", friendly = "F "; // Global Declarations that are needed throughout the program
bool gameMode;
int direction;

// function prototypes
int randomDirectionGenerator();
int randomCords(string actualOcean[][10]);
int getRow();
int getColumn();
char getGameMode();
void initializeBoard(string userOcean[][10]);
void enemyPositioning(string actualOcean[][10], int &, int &, int &, int &, int &, int &);
void enemyPositioning2(string actualOcean[][10], int &, int &, int &, int &, int &, int &);
void friendlyPositioning(string actualOcean[][10], int &, int &, int &, int &, int &, int &);
void friendlyPositioning2(string actualOcean[][10], int &, int &, int &, int &, int &, int &);
void tempVariables(int &, int &, int &, int &, int &, int &, int, int, int, int, int, int);
void temp2Variables(int &, int &, int &, int &, int &, int &, int, int, int, int, int, int);
void temp3Variables(int &, int &, int &, int &, int &, int &, int, int, int, int, int, int);

int main()
{
	string userOcean[10][10] = { { "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- " },
	{ "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- " },
	{ "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- " },
	{ "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- " },
	{ "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- " },
	{ "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- " },
	{ "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- " },
	{ "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- " },
	{ "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- " },
	{ "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- " }, };
	bool flag = true, outcome = false; // conditional bools 
	char mode; // type of game mode
	int x1 = 0, x2 = 0, x3 = 0, y1 = 0, y2 = 0, y3 = 0, ammunition = 0, inputRow, inputColumn, randomDirection;
	int enemy1x1 = x1, enemy1y1 = y1, enemy1x2 = x2, enemy1y2 = y2, enemy1x3 = x3, enemy1y3 = y3, enemy2x1 = x1, enemy2y1 = y1, enemy2x2 = x2, enemy2y2 = y2, enemy2x3 = x3, enemy2y3 = y3;
	int friendly1x1 = x1, friendly1y1 = y1, friendly1x2 = x2, friendly1y2 = y2, friendly1x3 = x3, friendly1y3 = y3;
	string actualOcean[10][10] = { { "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- " },
	{ "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- " },
	{ "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- " },
	{ "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- " },
	{ "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- " },
	{ "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- " },
	{ "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- " },
	{ "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- " },
	{ "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- " },
	{ "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- ", "- " }, };

	mode = getGameMode(); // calls a function in which it decides the game to be played in easy or hard difficulty

	if (mode == 'E' || mode == 'e')
		gameMode = false;
	else if (mode == 'H' || mode == 'h')
		gameMode = true;

	cout << "Please wait while this program very efficiently executes. " << endl << "Do not end the program, this should not take more than several seconds." << endl;

	randomDirection = randomDirectionGenerator(); // decides where to execute the game with enemies sailing east and friendly sailing south OR the other way around

	if (randomDirection == 0)
	{
		enemyPositioning(actualOcean, x1, y1, x2, y2, x3, y3); // inputs the coordinates of ship 1 into the array
		tempVariables(enemy1x1, enemy1y1, enemy1x2, enemy1y2, enemy1x3, enemy1y3, x1, y1, x2, y2, x3, y3); // stores x-y values from being over-written

		friendlyPositioning2(actualOcean, x1, y1, x2, y2, x3, y3); // inputs the coordinates of ship 3 into the array
		temp3Variables(friendly1x1, friendly1y1, friendly1x2, friendly1y2, friendly1x3, friendly1y3, x1, y1, x2, y2, x3, y3);

		enemyPositioning2(actualOcean, x1, y1, x2, y2, x3, y3); // inputs the coordinates of ship 2 into the array
		temp2Variables(enemy2x1, enemy2y1, enemy2x2, enemy2y2, enemy2x3, enemy2y3, x1, y1, x2, y2, x3, y3); // stores x-y values from being over-written

		friendlyPositioning(actualOcean, x1, y1, x2, y2, x3, y3);
	}
	else if (randomDirection == 1)
	{
		enemyPositioning2(actualOcean, x1, y1, x2, y2, x3, y3); // inputs the coordinates of ship 1 into the array
		tempVariables(enemy1x1, enemy1y1, enemy1x2, enemy1y2, enemy1x3, enemy1y3, x1, y1, x2, y2, x3, y3); // stores x-y values from being over-written

		friendlyPositioning2(actualOcean, x1, y1, x2, y2, x3, y3); // inputs the coordinates of ship 3 into the array
		temp3Variables(friendly1x1, friendly1y1, friendly1x2, friendly1y2, friendly1x3, friendly1y3, x1, y1, x2, y2, x3, y3);

		enemyPositioning(actualOcean, x1, y1, x2, y2, x3, y3); // inputs the coordinates of ship 2 into the array
		temp2Variables(enemy2x1, enemy2y1, enemy2x2, enemy2y2, enemy2x3, enemy2y3, x1, y1, x2, y2, x3, y3); // stores x-y values from being over-written

		friendlyPositioning(actualOcean, x1, y1, x2, y2, x3, y3);
	}

	// --------------------------CHEAT GRID PRINTED-------------------
	// ----------------- uncomment to see locations of ships ----------------------

	/*
	for (int count = 0; count < 10; count++)
	{
	for (int counter = 0; counter < 10; counter++)
	{
	cout << actualOcean[count][counter];
	}
	cout << endl;
	} cout << endl;
	*/

	// ---------------------------END CHEAT GRID----------------------



	initializeBoard(userOcean); // prints the game board

	do
	{
		inputRow = getRow();
		inputColumn = getColumn();

		if ((inputRow == enemy1x1 && inputColumn == enemy1y1) || (inputRow == enemy1x2 && inputColumn == enemy1y2) || (inputRow == enemy1x3 && inputColumn == enemy1y3) || (inputRow == enemy2x1 && inputColumn == enemy2y1) || (inputRow == enemy2x2 && inputColumn == enemy2y2) || (inputRow == enemy2x3 && inputColumn == enemy2y3))
		{
			userOcean[inputRow][inputColumn] = enemy; // displays that the user has hit an enemy
			ammunition++; // increments the amount of tries to win the game
			cout << "You hit an enemy!" << endl;
		}
		else if ((inputRow == x1 && inputColumn == y1) || (inputRow == x2 && inputColumn == y2) || (inputRow == x3 && inputColumn == y3) || (inputRow == friendly1x1 && inputColumn == friendly1y1) || (inputRow == friendly1x2 && inputColumn == friendly1y2) || (inputRow == friendly1x3 && inputColumn == friendly1y3))
		{
			userOcean[inputRow][inputColumn] = friendly; // displays that the user has hit a friendly
			ammunition++;
			cout << "You hit a friendly!" << endl;
		}
		else if (userOcean[inputRow][inputColumn] != enemy && userOcean[inputRow][inputColumn] != friendly)
		{
			userOcean[inputRow][inputColumn] = miss; // displays that the user has missed
			ammunition++;
			cout << "You missed!" << endl;
		}

		initializeBoard(userOcean); // re prints board after user has fired

		if ((userOcean[x1][y1] == actualOcean[x1][y1]) && (userOcean[x2][y2] == actualOcean[x2][y2]) && (userOcean[x3][y3] == actualOcean[x3][y3]) && (userOcean[friendly1x1][friendly1y1] == actualOcean[friendly1x1][friendly1y1]) && (userOcean[friendly1x2][friendly1y2] == actualOcean[friendly1x2][friendly1y2]) && (userOcean[friendly1x3][friendly1y3] == actualOcean[friendly1x3][friendly1y3]))
		{
			cout << endl << "ALL FRIENDLY SHIPS SUNK! YOU LOSE!!!" << endl;
			flag = false; // flag exits loop
			outcome = false; // condition set in which you lose
		}

		if ((userOcean[enemy1x1][enemy1y1] == actualOcean[enemy1x1][enemy1y1]) && (userOcean[enemy1x2][enemy1y2] == actualOcean[enemy1x2][enemy1y2]) && (userOcean[enemy1x3][enemy1y3] == actualOcean[enemy1x3][enemy1y3]) && (userOcean[enemy2x1][enemy2y1] == actualOcean[enemy2x1][enemy2y1]) && (userOcean[enemy2x2][enemy2y2] == actualOcean[enemy2x2][enemy2y2]) && (userOcean[enemy2x3][enemy2y3] == actualOcean[enemy2x3][enemy2y3]))
		{
			cout << endl << "ALL ENEMY SHIPS SUNK! YOU WIN!!!" << endl;
			flag = false; // flag exits loop
			outcome = true; // condition set in which you win
		}

	} while (flag == true);


	if (outcome == false)
		cout << "You have used " << ammunition << " shells in the attempt of taking down the enemy!" << endl << endl;
	else if (outcome == true)
		cout << "You have used " << ammunition << " shells to take down the enemy!" << endl << endl;


	return 0;
}

char getGameMode() // gets user input for game mode
{
	char mode = 'E';

	do
	{
		cout << "Would you like to play Easy mode or Hard mode? Enter E or H" << endl;
		cin >> mode;
	} while (mode != 'E' && mode != 'e' && mode != 'H' && mode != 'h');

	return mode;
}

int randomDirectionGenerator() // decides number 0 or 1 for conditional case in main
{
	int x;

	srand(time(NULL));
	x = rand() % 2;

	return x;
}

void initializeBoard(string userOcean[][10]) // prints the user board
{
	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			cout << userOcean[x][y];
		}
		cout << endl;
	}
}

int getRow() // gets the row
{
	int x;

	do
	{
		cout << "Enter your Row: ";
		cin >> x;

		while (cin.fail() == true) // tests for invalid input such as letters
		{
			cout << "Invalid input" << endl << endl;
			cin.ignore();
			cin.clear();
			cin.get();
			cout << "Enter a valid value" << endl;
			cin >> x;
		}
	} while (x < 1 || x > 10);

	x -= 1; // subtracts 1 from the input to match the 0-9 grid of the 2 dimensional array

	return x;
}

int getColumn() // gets the column
{
	int x;

	do
	{
		cout << "Enter your Column: ";
		cin >> x;

		while (cin.fail() == true) // tests for invalid input such as letters
		{
			cout << "Invalid input" << endl << endl;
			cin.ignore();
			cin.clear();
			cin.get();
			cout << "Enter a valid value" << endl;
			cin >> x;
		}
	} while (x < 1 || x > 10);

	x -= 1; // subtracts 1 from the input to match the 0-9 grid of the 2 dimensional array

	return x;
}

void tempVariables(int &enemy1x1, int &enemy1y1, int &enemy1x2, int &enemy1y2, int &enemy1x3, int &enemy1y3, int x1, int y1, int x2, int y2, int x3, int y3) // stores variables for ship 1 
{
	enemy1x1 = x1;
	enemy1y1 = y1;
	enemy1x2 = x2;
	enemy1y2 = y2;
	enemy1x3 = x3;
	enemy1y3 = y3;
}

void temp2Variables(int &enemy2x1, int &enemy2y1, int &enemy2x2, int &enemy2y2, int &enemy2x3, int &enemy2y3, int x1, int y1, int x2, int y2, int x3, int y3) // stores variables for ship 2
{
	enemy2x1 = x1;
	enemy2y1 = y1;
	enemy2x2 = x2;
	enemy2y2 = y2;
	enemy2x3 = x3;
	enemy2y3 = y3;
}

void temp3Variables(int &friendly1x1, int &friendly1y1, int &friendly1x2, int &friendly1y2, int &friendly1x3, int &friendly1y3, int x1, int y1, int x2, int y2, int x3, int y3)
{
	friendly1x1 = x1;
	friendly1y1 = y1;
	friendly1x2 = x2;
	friendly1y2 = y2;
	friendly1x3 = x3;
	friendly1y3 = y3;
}

void enemyPositioning(string actualOcean[][10], int &x1, int &y1, int &x2, int &y2, int &x3, int &y3) // vertical enemy ship printed
{

	direction = 1;
	x1 = randomCords(actualOcean);
	direction = 0;
	y1 = randomCords(actualOcean);
	y2 = y1;
	y3 = y1;
	x2 = x1 + 1;
	x3 = x2 + 1;

	actualOcean[x1][y1] = enemy; // stores 1 of the 3 locations for an enemy ship as 'E'
	actualOcean[x2][y2] = enemy;
	actualOcean[x3][y3] = enemy;

}

void enemyPositioning2(string actualOcean[][10], int &x1, int &y1, int &x2, int &y2, int &x3, int &y3) // horizontal enemy ship printed
{

	direction = 1;
	x1 = randomCords(actualOcean);
	direction = 0;
	y1 = randomCords(actualOcean);
	x2 = x1;
	x3 = x1;
	y2 = y1 + 1;
	y3 = y2 + 1;

	actualOcean[x1][y1] = enemy; // stores 1 of the 3 locations for an enemy ship as 'E'
	actualOcean[x2][y2] = enemy;
	actualOcean[x3][y3] = enemy;

}

void friendlyPositioning(string actualOcean[][10], int &x1, int &y1, int &x2, int &y2, int &x3, int &y3) // horizontal friendly ship printed
{

	direction = 1;
	x1 = randomCords(actualOcean);
	direction = 0;
	y1 = randomCords(actualOcean);
	x2 = x1;
	x3 = x1;
	y2 = y1 + 1;
	y3 = y2 + 1;

	actualOcean[x1][y1] = friendly; // stores 1 of the 3 locations for an enemy ship as 'F'
	actualOcean[x2][y2] = friendly;
	actualOcean[x3][y3] = friendly;

}

void friendlyPositioning2(string actualOcean[][10], int &x1, int &y1, int &x2, int &y2, int &x3, int &y3) // vertical friendly ship printed
{

	direction = 1;
	x1 = randomCords(actualOcean);
	direction = 0;
	y1 = randomCords(actualOcean);
	y2 = y1;
	y3 = y1;
	x2 = x1 + 1;
	x3 = x2 + 1;

	actualOcean[x1][y1] = friendly; // stores 1 of the 3 locations for an enemy ship as 'F'
	actualOcean[x2][y2] = friendly;
	actualOcean[x3][y3] = friendly;

}

int randomCords(string actualOcean[][10]) // gets a random number for a coordinate
{
	bool flag = true;
	int z;

	while (flag == true)
	{
		if (gameMode == false) // if easy game mode is selected
		{
			srand(time(NULL));
			z = rand() % 8;
		}
		else if (gameMode == true) // if hard game mode is selected
		{
			srand(time(NULL));
			z = rand() % 4;
		}

		if (direction == 0) // tests for horizontal overlapping
		{
			if ((actualOcean[z][z] == enemy || actualOcean[z][z] == friendly) || ((actualOcean[z][z + 1]) == enemy || (actualOcean[z][z + 1]) == friendly) || ((actualOcean[z][z + 2]) == enemy || (actualOcean[z][z + 2]) == friendly))
				continue;
			else
				flag = false;
		}
		else if (direction == 1) // tests for vertical overlapping
		{
			if ((actualOcean[z][z] == enemy || actualOcean[z][z] == friendly) || ((actualOcean[z + 1][z]) == enemy || (actualOcean[z + 1][z]) == friendly) || ((actualOcean[z + 2][z]) == enemy || (actualOcean[z + 2][z]) == friendly))
				continue;
			else
				flag = false;
		}
	}

	return z;
}