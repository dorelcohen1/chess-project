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
chess_p::chess_p(std::string loc, bool is_it_white ,std::string string_piece_representation)
{
	location = loc;
	is_white = is_it_white;
	piece_representation = string_piece_representation;
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


 
