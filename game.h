#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

/********************************************************************
 ** Program Filename: game.h
 ** Author: Helena Bales
 ** Date: 04/10/2014
 ** Description: the struct and function defs for connect four
 ** Input: none
 ** Output: none
 *******************************************************************/

struct game {
   char **p1_board;
   char p1;
   char p2;
};

/********************************************************************
 ** Function: getvalidn
 ** Description: gets a valid number of rows from user
 ** Parameters: n, the number of rows, passed by reference
 ** Pre-Conditions: n exists
 ** Post-Conditions: n contains a number greater than 0
 *******************************************************************/

void getvalidn(int &n);

/********************************************************************
 ** Function: getvalidm
 ** Description: gets a valid number of columns from the user
 ** Parameters: m, the number of columns, passed by reference
 ** Pre-Conditions: m exists
 ** Post-Conditions: m contains a number greater than 0
 *******************************************************************/

void getvalidm(int &m);

/********************************************************************
 ** Function: getvalidp
 ** Description: gets a valid number of pawns to connect
 ** Parameters: p, number of pawns to connect, passed by ref
 ** Pre-Conditions: p exists
 ** Post-Conditions: p contains a number greater than 1
 *******************************************************************/

void getvalidp(int &p);

/********************************************************************
 ** Function: printboard
 ** Description: prints the board
 ** Parameters: board, 2d array in the game struct; n, num of rows; m, num of cols
 ** Pre-Conditions: board exists, n has num of rows, m has num of cols
 ** Post-Conditions: none
 *******************************************************************/

void printboard(char** board, int n, int m);

/********************************************************************
 ** Function: checkcol
 ** Description: checks which row to put the piece in for the user inputed col
 ** Parameters: b, the game struct; col, the col user chose; n, num of rows
 ** Pre-Conditions: b contains a board, col is valid, n is the number of rows in the board
 ** Post-Conditions: i is returned, containing which row to put the piece in
 *******************************************************************/

int checkcol(game b, int col, int n);

/********************************************************************
 ** Function: placepiece
 ** Description: places the piece in the lowest available place in the user-input col
 ** Parameters: b, the game struct; player, 1 or 2, depending on turn; col, col to place piece in; n, num of rows; m, num of cols
 ** Pre-Conditions: b contains a board of size n by m, player contains 1 or 2
 ** Post-Conditions: r or y is placed in the board
 *******************************************************************/

void placepiece(game b, int player, int col, int n, int m);

/********************************************************************
 ** Function: getn
 ** Description: gets the num of rows from argv
 ** Parameters: argc, num of rows in argv; argv, 2d array of user-input; n, num of rows, passed by ref; m num of cols; p num of pawns to connect
 ** Pre-Conditions: n exists
 ** Post-Conditions: n contains a valid number
 *******************************************************************/

void getn(int argc, char* argv[], int &n, int m, int p);

/********************************************************************
 ** Function: getm
 ** Description: gets a valid number of cols
 ** Parameters: argc, num of rows in argv; argv, 2d array of user-input; n, num of rows; m num of cols, passed by ref; p num of pawns to connect
 ** Pre-Conditions: m exists
 ** Post-Conditions: m contains a valid number
 *******************************************************************/

void getm(int argc, char* argv[], int &m, int n, int p);

/********************************************************************
 ** Function: getp
 ** Description: gets a valid number of pawns to connect
 ** Parameters: argc, num of rows in argv; argv, 2d array of user-input; n, num of rows; m num of cols; p num of pawns to connect, passed by ref
 ** Pre-Conditions: p exists
 ** Post-Conditions: p contains a valid number of pawns to connect
 *******************************************************************/

void getp(int argc, char* argv[], int &p, int m, int n);

/********************************************************************
 ** Function: horizontal
 ** Description: checks if someone won horizontally
 ** Parameters: b, the game struct; n, num rows; m, num cols; p, num to connect
 ** Pre-Conditions: b contains an n by m board
 ** Post-Conditions: if someone won, a 1 is returned and winner is printed, else, a 0 is returned
 *******************************************************************/

bool horizontal(game b, int n, int m, int p);

/********************************************************************
 ** Function: vertical
 ** Description: checks if someone won vertically
 ** Parameters: b, n, m, p, same as above
 ** Pre-Conditions: b contains an n by m board
 ** Post-Conditions: if won, 1 is returned, and winner is printed, else, 0 is returned
 *******************************************************************/

bool vertical(game b, int n, int m, int p);

/********************************************************************
 ** Function: downright
 ** Description: checks if someone won at a diagonal down
 ** Parameters: same as above
 ** Pre-Conditions: b contains n by m board
 ** Post-Conditions: if won, 1 is returned and winner printed, else, 0 is returned
 *******************************************************************/

bool downright(game b, int n, int m, int p);

/********************************************************************
 ** Function: upright
 ** Description: checks if someone won in a diagonal up
 ** Parameters: same as above
 ** Pre-Conditions: b contains an n by m board
 ** Post-Conditions: if won, 1 is returned and winner printed, else 0 is returned
 *******************************************************************/

bool upright(game b, int n, int m, int p);

/********************************************************************
 ** Function: win
 ** Description: runs all the checks to see if someone won
 ** Parameters: b, the game struct; n, num rows; m, num cols; p, num to connect
 ** Pre-Conditions: b contains n by m board
 ** Post-Conditions: 1 is returned if someone won, else 0
 *******************************************************************/

bool win(game b, int n, int m, int p);

/********************************************************************
 ** Function: turn
 ** Description: gets the col to put stuff in each turn
 ** Parameters: b, game struct; player, 1 or 2, depending on whose turn it is; col, where to place the piece, passed by ref; n, num rows; m, num cols
 ** Pre-Conditions: b contains n by m board, player contains 1 or 2, col exists
 ** Post-Conditions: col contains where to put the piece on the board, and the piece is placed
 *******************************************************************/

void turn(game b, int player, int &col, int n, int m);

/********************************************************************
 ** Function: cturn
 ** Description: checks that the user wants to continue playing
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: 0 is returned to quit, else 1
 *******************************************************************/

bool cturn();

