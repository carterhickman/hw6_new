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
	* @param there are no parameters.
	* @return the function returns the value 0.
	*/
int main()
{
	Othello theGame;
	theGame.restart();
	theGame.play();
}
