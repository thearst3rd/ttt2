/*
 * Board module for ttt2
 * Created on 4/26/2018 by Terry Hearst
 */

#include <stdio.h>
#include <stdlib.h>
#include "board.h"


/* ----- VARIABLE DECLARATIONS ----- */

const char PLAYER_1_CHAR = 'X';
const char PLAYER_2_CHAR = 'O';
const char BLANK_CHAR    = '.';

static char rawBoard[81];


/* ----- FUNCTION IMPLEMENTATIONS ----- */

// Initialize the game board
void initBoard()
{
	for (int i = 0; i < 9; i++)
	{
		board[i] = rawBoard + (9 * i);
		boardState[i] = 0;
		for (int j = 0; j < 9; j++)
		{
			board[i][j] = 0;
		}
	}
}

// Writes the contents of a small boards visuals to the 

// Helper function, gets a player's input
int getInput()
{
	/*char buf[INPUT_BUF_SIZE];
	fgets(buf, INPUT_BUF_SIZE, stdin);
	
	fputc('\n', stdin);
	int c; while ((c = getc(stdin)) != '\n' && c != EOF);
	
	return atoi(buf);*/
	int result;
	scanf("%d", &result);
	
	int c; while ((c = getchar()) != '\n' && c != EOF);
	
	return result;
}

// Performs a complete turn
void doTurn()
{
	int input = getInput();
	printf("%d\n", input);
}
