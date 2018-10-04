/**
@file main.cc
@author Brock Ferrell (documented by Carter Hickman) 
@brief 	Start, restart called here. No functionality, only calls for came to play or restart. 
**/


// Brock Ferrell
// CS2401
// November 23, 2015
// Project7

#include "game.h"
#include "othello.h"
using namespace main_savitch_14;

	/**
	* Function name: main()
	* @author Brock Ferrell(Documented by Mohamed Jallow)
	* @brief This function creates an Othello object named theGame, runs the restart function, then runs the play function.
	* @param None :there are no parameters
	* @return the function returns the value 0.
	*/
int main()
{
	Othello theGame;
	theGame.restart();
	theGame.play();
}
