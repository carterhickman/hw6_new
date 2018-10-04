// Brock Ferrell
// CS2401
// November 23, 2015
// Project7
/**
@file othello.h
@author Brock Ferrell(documented by Carter Hickman) 
@brief .h file for othello.cc. Private variables and functions declared here. 
**/

#ifndef OTHELLO_H
#define OTHELLO_H
#include "game.h"
#include "piece.h"
#include "colors.h"
#include <iostream>
using namespace std;

namespace main_savitch_14
{

class Othello: public game {
public:

	Othello() {}
	
	/**
	* Function name: display_status
	* @author Brock Ferrell(Documented by Mohamed Jallow)
	* Function Declaration
	* @brief This function displays the current state of the board to the user.
	* @param there are no parameters.
	* @return the function is void so it does not return a value.
	*/
	void display_status()const;
	int evaluate()const;
	bool is_game_over()const;
	bool is_legal(const string& move)const;
	void make_move(const string& move);
	void restart();
	void make_skips();
	void countingPieces();
	void whosTurn();
	game* clone()const{return new Othello(*this);}
	void compute_moves(std::queue<std::string>& moves)const;
	who winning()const;

protected:
	int black;
	int white;
	int skips;
	int openSpots;
	int b;
	int w;

private:
	piece gameBoard[8][8];
};
}

#endif

