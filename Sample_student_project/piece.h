/**
@file piece.h
@author Brock Ferrell (documented by Carter Hickman) 
@brief 	Defines each space on board as a piece. Sets pieces to white or black depending. 
**/

// Brock Ferrell
// CS2401
// November 23, 2015
// Project7

#ifndef PIECE_H
#define PIECE_H
enum color {black, white, blank};

class piece {
public:
	piece() {theColor = blank;}

	void flip()
	{
		if (theColor == white) {
			theColor = black;
		}
		else if (theColor == black) {
			theColor = white;
		}
	}
	/**
	* Function name: is_blank
	* @author Brock Ferrell(Documented by Mohamed Jallow)
	* Function Declaration
	* @brief This function returns the boolean value for the conditional "theColor == blank".
	* @param None :there are no parameters
	* @return the function returns true or false depeding on what is stored in the theColor variable.
	*/
	bool is_blank()const {return theColor == blank;}
	bool is_black()const {return theColor == black;}
	bool is_white()const {return theColor == white;}
	void set_white() {theColor = white;}
	void set_black() {theColor = black;}

private:
	color theColor;

};

#endif

