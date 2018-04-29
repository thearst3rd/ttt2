/*
 * Board module header for ttt2
 * Created on 4/26/2018 by Terry Hearst
 */

#ifndef _BOARD_H_
#define _BOARD_H_


/* ----- VARIABLE DECLARATIONS ----- */

// These are all possible boardState values
#define STATE_REGULAR 0
#define STATE_1 1
#define STATE_2 2
#define STATE_TIED 3
#define STATE_SELECTED 4

char *board[9];
char boardState[9];


/* ----- FUNCTION DECLARATIONS ----- */

void initBoard();
void doTurn();
void printBoard();
int checkWins(int);


#endif // _BOARD_H_
