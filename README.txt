Welcome to ttt2 - a Tic Tac Toe Squared game for the command line!
Written by Terry Hearst


############
# OVERVIEW #
############

In this game, the idea is to get three in a row just like tic tac toe, but with
many twists. Instead of simply getting three pieces in a row, you must get three
big tic tac toe boards in a row!

The board setup looks like the following:

	       #       #
	  ...  #  ...  #  ...
	  ...  #  ...  #  ...
	  ...  #  ...  #  ...
	       #       #
	#######################
	       #       #
	  ...  #  ...  #  ...
	  ...  #  ...  #  ...
	  ...  #  ...  #  ...
	       #       #
	#######################
	       #       #
	  ...  #  ...  #  ...
	  ...  #  ...  #  ...
	  ...  #  ...  #  ...
	       #       #

Each block of 9 dots is a standard tic tac toe board. Each board is indexed like
the numpad, so each board's positions are represented by the numbers:

	789
	456
	123

This goes for each small board and the big board as well.


#############
# OBJECTIVE #
#############

Winning a board means you have won that piece on the big board. The objective of
the game is to get three big board pieces in a row. However, you cannot simply
put a piece anywhere on the board. The rules are explained below.

If a board satisfies the end condition of a regular game of tic tac toe, that is
either:

* One player got three in a row on that board, or
* The entire board is full and neither player got three in a row

Then that board is considered dead. Nobody will be able to place any pieces on
that board, and instead the board will starting counting as a scoring element
for the big board. If player 1 got three in a row, it will count as a piece for
player 1, and the same is true for player 2.

If a small board ends in a draw, then that piece on the big board will act as a
scoring element for BOTH players! This means that a either player 1 or player 2
can use that piece on the large board as one of the pieces that make up that
player's three in a row. This can cause a game to draw if both players get three
in a row at the same time with the same drawn board.

The game end condition is as follows:

* The game ends when either player has gotten three large pieces in a row,
  including pieces from tied small boards, or when the entire big board has
  filled up with dead boards but neither player has gotten three in a row.

* When this condition is met, the game counts up the number of three in a rows
  that each player got. This will usually just be 1 for the single player that
  earned three in a row, but in the odd cases of tied small boards causing both
  players to simultaniously earn three pieces in a row, this will determine if
  one player earned more three in a rows than the other.

* If one player has a higher three-in-a-row count than the other player, that
  player is the winner. If the counts are the same, including if they are both
  zero, then the game ends in a draw.


##################
# PLACING PIECES #
##################

As stated earlier, you cannot place a piece on a dead board. However, there are
more rules than just that.

At the start of the game, Player 1 is allowed to choose any spot on any board to
start the game. However, from then on, EACH PLAYER MUST PUT THEIR NEXT PIECE ON
THE BIG BOARD CORRESPONDING TO THE POSITION OF THE LAST PIECE IN IT'S SMALL
BOARD. To give an example: Lets say player 1 chooses to play in the following
location:

	       #       #
	  ...  #  ...  #  ...
	  ...  #  ...  #  ...
	  ...  #  ...  #  ...
	       #       #
	#######################
	       #       #
	  ...  #  ...  #  ...
	  ...  #  ...  #  ...
	  ...  #  ...  #  ...
	       #       #
	#######################
	       #       #
	  ...  #  X..  #  ...
	  ...  #  ...  #  ...
	  ...  #  ...  #  ...
	       #       #

Now, player 2 MUST play somewhere in the following board, marked off with the
line border:

	 /---\ #       #
	 |...| #  ...  #  ...
	 |...| #  ...  #  ...
	 |...| #  ...  #  ...
	 \---/ #       #
	#######################
	       #       #
	  ...  #  ...  #  ...
	  ...  #  ...  #  ...
	  ...  #  ...  #  ...
	       #       #
	#######################
	       #       #
	  ...  #  X..  #  ...
	  ...  #  ...  #  ...
	  ...  #  ...  #  ...
	       #       #

That is because player 1 chose the top left piece. They played it in the bottom
center board, but were they to play the top left piece in any of the boards, the
next player will be required to play in the top left board. I will refer to this
informally as "sending the player to a board". This process continues: player 2
will play in the top left board, in doing so will send player 1 to the board
which corresponds to the position of that piece in it's small board.

However, if the player tries to send the other player to a board that is dead,
then the other player gets to play in ANY board of their choosing (presuming it
is not dead).

All of these rules mean that you need to be careful putting your pieces on the
boards! You need to be able to get three in a row on the small boards to earn
pieces on the big board, all while strategically sending the player to boards
that will not be able to benefit them.


###################################
# INPUTTING INTO THE COMMAND LINE #
###################################

As stated earlier, each board is indexed by the numbers 1 through 9, and are
arranged like the numpad. This goes for the individiual pieces inside a small
board, and for each small board inside the big board.

If you are in a position where you are allowed to choose between different
boards, first you must enter the index of the small board within the big board.
This will cause that board to become the only selected board, and you will go to
the next step. If you did not need to select a small board, then you will have
skipped that step and moved onto the next.

To enter a piece into the selected small board, simply enter the index of that
position in the small board.

This will perform your turn, check for end conditions, then change turns to the
next player.


##############
# CONCLUSION #
##############

That is all for ttt2, a Tic Tac Toe Squared game for the command line! I hope
you enjoyed playing this game as much as I enjoyed writing it!
