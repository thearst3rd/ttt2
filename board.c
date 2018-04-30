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
	currPlayer = 1;
	
	for (int i = 0; i < 9; i++)
	{
		board[i] = rawBoard + (9 * i);
		boardState[i] = STATE_SELECTED;
		
		for (int j = 0; j < 9; j++)
		{
			board[i][j] = '.';
		}
	}
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

// Helper function that calculates if a small board triple is a win
int checkTripleSmall(int bIndex, int i, int j, int k)
{
	return ((board[bIndex][i] != '.')
	       && (board[bIndex][i] == board[bIndex][j])
	       && (board[bIndex][i] == board[bIndex][k]));
}

// Helper function that calculates the new state of a board
void calculateBoardState(int bIndex)
{
	// Calculate verticals
	for (int i = 0; i < 3; i++)
	{
		if (checkTripleSmall(bIndex, i, i + 3, i + 6))
		{
			boardState[bIndex] = board[bIndex][i] == 'X' ? 1 : 2;
			return;
		}
	}
	
	// Calculate horizontals
	for (int i = 0; i < 9; i += 3)
	{
		if (checkTripleSmall(bIndex, i, i + 1, i + 2))
		{
			boardState[bIndex] = board[bIndex][i] == 'X' ? 1 : 2;
			return;
		}
	}
	
	// Calculate diagonals
	if (checkTripleSmall(bIndex, 0, 4, 8) || checkTripleSmall(bIndex, 2, 4, 6))
	{
		boardState[bIndex] = board[bIndex][4] == 'X' ? 1 : 2;
		return;
	}
	
	// Nobody has won this board, so set it back to regular
	boardState[bIndex] = STATE_REGULAR;
}

// Performs a complete turn
void doTurn()
{
	// Print header
	printf("Player %d's turn!\n", currPlayer);
	
	// Get the number of selected boards
	int selectedCount = 0;
	for (int i = 0; i < 9; i++)
	{
		if (boardState[i] == STATE_SELECTED)
			selectedCount++;
	}
	
	int selectedBoard = -1;
	
	if (selectedCount > 1)
	{
		// Ask player to select a single large board
		printf("Please select a large board: ");
		int input = getInput();
		while ((input < 1) || (input > 9) || (boardState[input-1] != 4))
		{
			printf("That is invalid, try again: ");
			input = getInput();
		}
		
		// Reduce boards to only a single selected board
		selectedBoard = input - 1;
		for (int i = 0; i < 9; i++)
		{
			if (i == selectedBoard)
				continue;
			
			if (boardState[i] == STATE_SELECTED)
				boardState[i] = STATE_REGULAR;
		}
		
		printBoard();
		printf("\n");
	}
	else
	{
		for (int i = 0; i < 9; i++)
		{
			if (boardState[i] == STATE_SELECTED)
			{
				selectedBoard = i;
				break;
			}
		}
	}
	
	if (selectedBoard == -1)
	{
		printf("ERROR, no board seleceted");
		exit(1);
	}
	
	// Ask for piece location
	printf("Please select a location within board %d: ", selectedBoard);
	int input = getInput();
	
	while ((input < 1) || (input > 9)
	      || (board[selectedBoard][input - 1] != '.'))
	{
		printf("That is invalid, try again: ");
		input = getInput();
	}
	int selectedPiece = input - 1;
	
	board[selectedBoard][selectedPiece] = ((currPlayer == 1) ? 'X' : 'O');
	calculateBoardState(selectedBoard);
	
	if (boardState[selectedPiece] != STATE_REGULAR)
	{
		for (int i = 0; i < 9; i++)
		{
			if (boardState[i] == STATE_REGULAR)
				boardState[i] = STATE_SELECTED;
		}
	}
	else
	{
		boardState[selectedPiece] = STATE_SELECTED;
	}
	
	currPlayer = (currPlayer == 1) ? 2 : 1;
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
			break;
		
		default:
			printf("ERROR: Unknown board state %d\n", state);
			break;
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
	
	putchar('\n');
	
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

	putchar('\n');
	
	// Free the small board buffers
	for (int i = 0; i < 9; i++)
	{
		free(bufs[i]);
	}
	free(bufs);
}

// Helper function that checks the given three big board pieces for a win
int checkTripleBig(int player, int i, int j, int k)
{
	return (boardState[i] == player || boardState[i] == 3)
	       && (boardState[j] == player || boardState[j] == 3)
	       && (boardState[k] == player || boardState[k] == 3);
}

// Returns the number of three in a rows by the given player
int checkWins(int player)
{
	int count = 0;
	
	// Check verticals
	for (int i = 0; i < 3; i++)
	{
		if (checkTripleBig(player, i, i + 3, i + 6))
			count++;
	}
	
	// Check horizontals
	for (int i = 0; i < 9; i += 3)
	{
		if (checkTripleBig(player, i, i + 1, i + 2))
			count++;
	}
	
	// Check diagonals
	if (checkTripleBig(player, 0, 4, 8))
		count++;
	if (checkTripleBig(player, 2, 4, 6))
		count++;
	
	return count;
}
