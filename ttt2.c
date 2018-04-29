/*
 * ttt2 - Command line Tic Tac Toe Squared game
 * Created on 4/26/2018 by Terry Hearst
 */

#include <stdio.h>
#include <stdbool.h>
#include "board.h"


/* ----- HELPER FUNCTIONS ----- */

void printInfo()
{
	printf("Welcome to ttt2 - a Tic Tac Toe Squared game for the command "
	       "line!\nWritten by Terry Hearst\n\nFor a tutorial on how to play "
	       "the game, please consult the README file.\n");
}

/*
Welcome to ttt2 - a Tic Tac Toe Squared game for the command line!
Written by Terry Hearst

For a tutorial on how to play the game, please consult the README file.
*/


/* ----- MAIN ----- */

int main(int argc, char *argv[])
{
	printInfo();
	initBoard();
	
	bool running = true;
	while (running)
	{
		
	}

	return 0;
}
