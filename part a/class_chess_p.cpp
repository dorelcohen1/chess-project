// filepath: chess-project/code/class_chess_p.cpp

#include "class_chess_p.hpp"
#include <iostream>

// Constructor
/*
^   * fanction name:        chess_p
---------------------------------------------------------------------------------------
    * fanction description: Initializes a chess piece with its starting location and color.
    * fanction input:       std::string loc, bool is_it_white
        - loc:              The starting location of the piece.
        - is_it_white:      Indicates whether the piece is white (true) or black (false).
    * fanction output:      void
    * return value:         None.
    * eficency:             O(n) - linear time complexity, where n is the number of command-line arguments, as it needs to print each argument.
---------------------------------------------------------------------------------------
*/
chess_p::chess_p(std::string loc, bool is_it_white) 
{
	location = loc;
	is_white = is_it_white;
}

/*
^   * fanction name:        chess_p::get_is_alive
---------------------------------------------------------------------------------------
    * fanction description: Returns the alive status of the chess piece.
    * fanction input:       None
    * fanction output:      bool
    * return value:         True if the piece is alive, false otherwise.
    * eficency:             O(1) - constant time complexity.
---------------------------------------------------------------------------------------
*/
bool chess_p::get_is_alive()
{
	return is_alive;
}

/*
^   * fanction name:        chess_p::get_is_white
---------------------------------------------------------------------------------------
    * fanction description: Returns the color of the chess piece.
    * fanction input:       None
    * fanction output:      bool
    * return value:         True if the piece is white, false otherwise.
    * eficency:             O(1) - constant time complexity.
---------------------------------------------------------------------------------------
*/
bool chess_p::get_is_white()
{
	return is_white;
}

/*
^   * fanction name:        chess_p::set_destination
---------------------------------------------------------------------------------------
	* fanction description: Sets the proposed destination location for the chess piece.
	* fanction input:       std::string try_move
		- try_move:         The proposed destination location.
	* fanction output:      void
	* return value:         None.
	* eficency:             O(1) - constant time complexity.
---------------------------------------------------------------------------------------
*/
void chess_p::set_destination(std::string try_move)
{
	destination = try_move;
}

/*
^   * fanction name:        chess_p::set_die
---------------------------------------------------------------------------------------
	* fanction description: Marks the chess piece as dead by setting its alive status to false.
	* fanction input:       None
	* fanction output:      void
	* return value:         None.
	* eficency:             O(1) - constant time complexity.
---------------------------------------------------------------------------------------
*/
void chess_p::set_die()
{
	is_alive = false;
}

/*
^   * fanction name:        chess_p::move
---------------------------------------------------------------------------------------
	* fanction description: Updates the current location of the chess piece to its destination.
	* fanction input:       None
	* fanction output:      void
	* return value:         None.
	* eficency:             O(1) - constant time complexity.
---------------------------------------------------------------------------------------
*/
void chess_p::move()
{
	location = destination;
}

/*
^   * fanction name:        chess_p::give_location
---------------------------------------------------------------------------------------
	* fanction description: Returns the current location of the chess piece.
	* fanction input:       None
	* fanction output:      std::string
	* return value:         The current location of the piece.
	* eficency:             O(1) - constant time complexity.
---------------------------------------------------------------------------------------
*/
std::string chess_p::give_location()
{
    return location;
}

/*
^   * fanction name:        chess_p::get_destination
---------------------------------------------------------------------------------------
	* fanction description: Returns the proposed destination location of the chess piece.
	* fanction input:       None
	* fanction output:      std::string
	* return value:         The proposed destination location of the piece.
	* eficency:             O(1) - constant time complexity.
---------------------------------------------------------------------------------------
*/
std::string chess_p::get_destination()
{
    return destination;
}

/*^   * fanction name:      chess_p::is_there_check
---------------------------------------------------------------------------------------
    * fanction description: Checks if the current player's king is in check based on the state of the chess board.
    * fanction input:       std::string state_of_board, char turn
        - state_of_board:   The current state of the chess board.
        - turn:             Indicates whose turn it is ('0' for white, '1' for black).
    * fanction output:      bool
    * return value:         True if the king is in check, false otherwise.
    * eficency:             O(n) - linear time complexity, where n is the number of squares on the board.
---------------------------------------------------------------------------------------
*/
bool chess_p::is_there_check(std::string state_of_board, char turn)
{
	// !just shit to avoid gcc warnings
	state_of_board[BOARD_STATE_LENGTH - 1] = turn; // set the turn in the state_of_board string
	turn = (turn == WHITE_TURN) ? '1' : '0'; // switch turn for opponent
    // TODO : Implement check detection logic for the rook
    return false; // Placeholder return value
}

 
