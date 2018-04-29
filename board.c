/*
 * Board module for ttt2
 * Created on 4/26/2018 by Terry Hearst
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "board.h"


/* ----- VARIABLE DECLARATIONS ----- */

static char rawBoard[81];


/* ----- FUNCTION IMPLEMENTATIONS ----- */

// Initialize the game board
void initBoard()
{
	for (int i = 0; i < 9; i++)
	{
		board[i] = rawBoard + (9 * i);
		boardState[i] = 4; 	// Board selected, piece can be placed on it
		for (int j = 0; j < 9; j++)
		{
			board[i][j] = '1' + j;//'.';
		}
	}

	boardState[0] = 1;
	boardState[5] = 2;
	boardState[3] = 3;
	boardState[1] = 0;
	boardState[2] = 0;
}

// Helper function, gets a player's input
int getInput()
{
	int result;
	scanf("%d", &result);
	
	// Clear any unused input characters from stdin's buffer
	int c; while ((c = getchar()) != '\n' && c != EOF);
	
	return result;
}

// Performs a complete turn
void doTurn()
{
	int input = getInput();
	printf("%d\n", input);
}

// Writes the contents of a small boards visuals to the given buffer
void writeBoardBuf(int bIndex, char buf[25])
{
	int state = boardState[bIndex];
	switch (state)
	{
		case 1:
			strncpy(buf, "X   X X X   X   X X X   X", 25);
			break;
		
		case 2:
			strncpy(buf, " OOO O   OO   OO   O OOO ", 25);
			break;

		case 3:
			strncpy(buf, "XOOOXOX XOO X OOX XOXOOOX", 25);
			break;

		case 4:
			strncpy(buf, "/---\\|   ||   ||   |\\---/", 25);
			
		case 0:
			if (state != 4)
				strncpy(buf, "                         ", 25);
			for (int i = 0; i < 9; i++)
			{
				int pos = 6 + i + 2 * (i / 3);
				if (pos < 9)
					pos += 10;
				else if (pos > 14)
					pos -= 10;
				buf[pos] = board[bIndex][i];
			}
	}
}

void printBoard()
{
	// Allocate all of the visuals for the small boards
	char **bufs = (char **) malloc(9 * sizeof(char *));
	for (int i = 0; i < 9; i++)
	{
		bufs[i] = (char *) malloc(25 * sizeof(char));
		writeBoardBuf(i, bufs[i]);
	}
	
	for (int i = 0; i < 5; i++)
	{
		fputs(" ", stdout);
		for (int j = 0; j < 5; j++)
			putchar(bufs[6][5 * i + j]);
		
		fputs(" # ", stdout);
		for (int j = 0; j < 5; j++)
			putchar(bufs[7][5 * i + j]);
		
		fputs(" # ", stdout);
		for (int j = 0; j < 5; j++)
			putchar(bufs[8][5 * i + j]);

		putchar('\n');
	}
	
	puts("#######################");
	
	for (int i = 0; i < 5; i++)
	{
		fputs(" ", stdout);
		for (int j = 0; j < 5; j++)
			putchar(bufs[3][5 * i + j]);
		
		fputs(" # ", stdout);
		for (int j = 0; j < 5; j++)
			putchar(bufs[4][5 * i + j]);
		
		fputs(" # ", stdout);
		for (int j = 0; j < 5; j++)
			putchar(bufs[5][5 * i + j]);

		putchar('\n');
	}
	
	puts("#######################");
	
	for (int i = 0; i < 5; i++)
	{
		fputs(" ", stdout);
		for (int j = 0; j < 5; j++)
			putchar(bufs[0][5 * i + j]);
		
		fputs(" # ", stdout);
		for (int j = 0; j < 5; j++)
			putchar(bufs[1][5 * i + j]);
		
		fputs(" # ", stdout);
		for (int j = 0; j < 5; j++)
			putchar(bufs[2][5 * i + j]);

		putchar('\n');
	}
	
	// Free the small board buffers
	for (int i = 0; i < 9; i++)
	{
		free(bufs[i]);
	}
	free(bufs);
}
