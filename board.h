/*
 * Board module header for ttt2
 * Created on 4/26/2018 by Terry Hearst
 */

#ifndef _BOARD_H_
#define _BOARD_H_


/* ----- VARIABLE DECLARATIONS ----- */

char *board[9];
/*
 * Valid board states:
 * 0 : No player, not selected
 * 1 : Player 1 owned
 * 2 : Player 2 owned
 * 3 : Tied board (both players owned)
 * 4 : Selected
 */
char boardState[9];


/* ----- FUNCTION DECLARATIONS ----- */

void initBoard();
void doTurn();
void printBoard();


#endif // _BOARD_H_
