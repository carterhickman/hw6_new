/**
@file game.cc
@author Brock Ferrell(documented by Carter Hickman)
@brief 		 Initiates start of game and checks for end of game/restart. Calls for humans or computer to make move and will move for computer. Looks for best moves with function look ahead. The majority of the functionality of the game is here
**/
#include <cassert>    // Provides assert
#include <climits>    // Provides INT_MAX and INT_MIN
#include <iostream>   // Provides cin, cout
#include <queue>      // Provides queue<string>
#include <string>     // Provides string
#include "game.h"     // Provides definition of game class
using namespace std;

namespace main_savitch_14
{
//*************************************************************************
// STATIC MEMBER CONSTANTS
// const int game::SEARCH_LEVELS;

//*************************************************************************
// PUBLIC MEMBER FUNCTIONS

/**
*  This function returns whos turn it currently is in the game and weather or not the game has concluded
*  @param   No parameters passed to function
*  @return  The winner of the game is returned
*  @author Brock Ferrell   Documentation by Daniel Ingram
*/

game::who game::play( )
// The play function should not be overridden. It plays one round of the
// game, with the human player moving first and the computer second.
// The return value is the winner of the game (or NEUTRAL for a tie).
{
	restart( );

	while (!is_game_over( ))
	{
		display_status( );
		whosTurn();
		if (last_mover( ) == COMPUTER) {
			countingPieces();
			make_human_move( );
		}
		else {
			make_computer_move( );
		}
	}
	display_status( );
	return HUMAN;
}



//*************************************************************************
// OPTIONAL VIRTUAL FUNCTIONS (overriding these functions is optional)

/**
*  This function displays a message to the screen
*  @param  message  The message to be printed to the screen
*  @return  Nothing is returned
*  @author Brock Ferrell   Documentation by David Thompson
*/

void game::display_message(const string& message) const
{
	cout << message;
}

/**
*  Function asks user for a move which the user then enters. If user cannot
*  move then they enter 'S' to the screen
*  @param No parameters passed to function
*  @return A string is returned containing the users input of their move
*  @author Brock Ferrell   Documentation by David Thompson
*/

string game::get_user_move( ) const
{
	string answer;

	display_message("If you cannot move, please press 'S'\n");
	display_message("Your move, please: ");
	getline(cin, answer);
	return answer;
}

/**
*  Function determines whih player is currently winning the game
*  @param No parameters passed to function
*  @return Function returns enum who which is either Human, Computer, or neutral depending on who is winning
*  @author Brock Ferrell   Documentation by David Thompson
*/

game::who game::winning()const {

	int value = evaluate();

	if (value > 0) {
		return last_mover();
	} else if (value < 0) {
		return next_mover();
	} else {
		return NEUTRAL;
	}

}

//*************************************************************************
// PRIVATE FUNCTIONS (these are the same for every game)

/**
*  This function determines the best move for the computer to make
*  @param  look_ahead is how many moves ahead should the computer consider in its evaluation, beat_this is the current best move value that the computer is checking to try to beat
*  @return  function returns the value of what was determined to be the best move
*  @author Brock Ferrell   Documentation by David Thompson
*/

int game::eval_with_lookahead(int look_ahead, int beat_this)
// Evaluate a board position with lookahead.
// --int look_aheads:  How deep the lookahead should go to evaluate the move.
// --int beat_this: Value of another move that we're considering. If the
// current board position can't beat this, then cut it short.
// The return value is large if the position is good for the player who just
// moved.
{
	queue<string> moves;   // All possible opponent moves
	int value;             // Value of a board position after opponent moves
	int best_value;        // Evaluation of best opponent move
	game* future;          // Pointer to a future version of this game

	// Base case:
	if (look_ahead == 0 || is_game_over( ))
	{
		if (last_mover( ) == COMPUTER)
			return evaluate( );
		else
			return -evaluate( );
	}

	// Recursive case:
	// The level is above 0, so try all possible opponent moves. Keep the
	// value of the best of these moves from the opponent's perspective.
	compute_moves(moves);
	// assert(!moves.empty( ));
	best_value = INT_MIN;
	while (!moves.empty( ))
	{
		future = clone( );
		future->make_move(moves.front( ));
		value = future->eval_with_lookahead(look_ahead - 1, best_value);
		delete future;
		if (value > best_value)
		{
			if (-value <= beat_this)
				return INT_MIN + 1; // Alpha-beta pruning
			best_value = value;
		}
		moves.pop( );
	}

	// The value was calculated from the opponent's perspective.
	// The answer we return should be from player's perspective, so multiply times -1:
	return -best_value;
}

/**
*  This function determines the actual move that the computer is going to make
*  @param No pararmeters
*  @return Nothing returned
*  @author Brock Ferrell   Documentation by David Thompson
*/

void game::make_computer_move( )
{
	queue<string> moves;
	int value;
	int best_value;
	string best_move;
	game* future;

	// Compute all legal moves that the computer could make.
	compute_moves(moves);
	//assert(!moves.empty( ));

	// Evaluate each possible legal move, saving the index of the best
	// in best_index and saving its value in best_value.
	best_value = INT_MIN;
	while (!moves.empty( ))
	{
		future = clone( );
		future->make_move(moves.front( ));
		value = future->eval_with_lookahead(SEARCH_LEVELS, best_value);
		delete future;
		if (value >= best_value)
		{
			best_value = value;
			best_move = moves.front( );
		}
		moves.pop( );
	}

	// Make the best move.
	make_move(best_move);
}

/**
*  This fuction checks gets the users move, checks if its legal, and finally makes that move
*  @param No pararmeters
*  @return Nothing returned
*  @author Brock Ferrell   Documentation by David Thompson
*/

void game::make_human_move( ) {
	string move;

	move = get_user_move( );
	while (!is_legal(move))
	{
		display_message("Illegal move.\n");
		move = get_user_move( );
	}
	make_move(move);
}

}
