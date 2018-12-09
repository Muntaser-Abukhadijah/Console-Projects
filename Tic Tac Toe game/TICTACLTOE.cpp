#include <functional>
#include <iomanip>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include<complex>
#include <unordered_map>
#include<unordered_set>
#include <numeric>
#include <string>
#include<iostream>
#include <fstream>
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include<cmath>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <sstream>
using namespace std;
char grid[3][3];
void drive();
void Display();
int calc();
void update();
void initialize();
bool checkValidation(int &);
int turn = 0;

/*******************************************************************
							MAIN
********************************************************************/
int main()
{
#ifndef ONLINE_JUDGE
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
#endif
	drive();
	return 0;
}

/*******************************************************************
				The Control Function
********************************************************************/

void drive()
{
	memset(grid, -1, sizeof(grid));
	initialize();
	while (!calc() && turn < 9)
	{
		system("CLS");
		Display();
		update();
		turn++;
	}
	system("CLS");
	int res = calc();
	Display();
	if (res == 3)
	{
		cout << "Game draw\n";
		return;
	}
	cout << "\n*******************************************\n";
	cout << "\tCongratulation player " << res;
	cout << "\n*******************************************\n";
}

/*******************************************************************
	 FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
********************************************************************/

void Display()
{
	cout << "  \t\t *Tic-Tac-Toe*\n\n";
	cout << "\t\t     |     |    \n";
	cout << "\t\t  " << grid[0][0] << "  |  " << grid[0][1] << "  |  " << grid[0][2] << endl;
	cout << "\t\t_____|_____|____\n";
	cout << "\t\t     |     |    \n";
	cout << "\t\t  " << grid[1][0] << "  |  " << grid[1][1] << "  |  " << grid[1][2] << endl;
	cout << "\t\t_____|_____|____\n";
	cout << "\t\t     |     |    \n";
	cout << "\t\t  " << grid[2][0] << "  |  " << grid[2][1] << "  |  " << grid[2][2] << endl;
	cout << "\t\t     |     |    \n\n";
}
void update()
{
	int pos;
	if (!(turn & 1))
	{
		cout << "Player number 1-(X) , Enter your choice : ";
		cin >> pos;
		checkValidation(pos);
		grid[(pos - 1) / 3][(pos - 1) % 3] = 'X';
	}
	else
	{
		cout << "Player number 2-(O) , Enter your choice : ";
		cin >> pos;
		checkValidation(pos);
		grid[(pos - 1) / 3][(pos - 1) % 3] = 'O';
	}
}
bool checkValidation(int &pos)
{
	while (cin.fail() || (grid[(pos - 1) / 3][(pos - 1) % 3] == 'X' || grid[(pos - 1) / 3][(pos - 1) % 3] == 'O') || pos > 9 || pos < 1)
	{
		cout << "Invalid Input try again : ";
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> pos;
	}
	return 1;
}

/*********************************************
	To Numbering The Grid
**********************************************/
void initialize()
{
	for (int c1 = 0; c1 < 3; c1++)
		for (int c2 = 0; c2 < 3; c2++)
			grid[c1][c2] = c1 * 3 + (c2 + 1) + '0';
}

/*********************************************
	FUNCTION TO RETURN GAME STATUS
**********************************************/

int calc()
{
	for (int i = 0; i < 3; i++)
		if (grid[i][0] == 'X'&&grid[i][1] == 'X'&&grid[i][2] == 'X')return 1;
	for (int i = 0; i < 3; i++)
		if (grid[0][i] == 'X'&&grid[1][i] == 'X'&&grid[2][i] == 'X')return 1;
	if (grid[0][0] == 'X'&&grid[1][1] == 'X'&&grid[2][2] == 'X')return 1;
	if (grid[0][2] == 'X'&&grid[1][1] == 'X'&&grid[2][0] == 'X')return 1;

	//     check for O 
	for (int i = 0; i < 3; i++)
		if (grid[i][0] == 'O'&&grid[i][1] == 'O'&&grid[i][2] == 'O')return 2;
	for (int i = 0; i < 3; i++)
		if (grid[0][i] == 'O'&&grid[1][i] == 'O'&&grid[2][i] == 'O')return 2;
	if (grid[0][0] == 'O'&&grid[1][1] == 'O'&&grid[2][2] == 'O')return 2;
	if (grid[0][2] == 'O'&&grid[1][1] == 'O'&&grid[2][0] == 'O')return 2;
	return 0;
}
/*******************************************************************
				END OF THE PROJECT
********************************************************************/