#ifndef CHESS_PIECES_HPP
#define CHESS_PIECES_HPP

#include <iostream> // for std::string and other I/O operations
#include "class_chess_p.hpp"

/*
// Class definition for Rook chess piece
// ------------------------------------------
// This class inherits from the base chess_p class
// It contains specific attributes and methods for the Rook piece
*/
class rook : public chess_p 
{
private:
    // Private member variables

public:
    // Public methods
    // -- Constructor --//

    rook(const std::string& start_loc, bool is_it_white);

    // --- Override Methods --- //

    MoveResult is_move_ok(std::string state_of_board ) override; // state_of_board: current state of the chess board
};

/*
// Class definition for King chess piece
// ------------------------------------------
// This class inherits from the base chess_p class
// It contains specific attributes and methods for the King piece
*/
class king : public chess_p 
{
private:
    // Private member variables

public:
    // Public methods
    // -- Constructor --//

    king(const std::string& start_loc, bool is_it_white);

    // --- Override Methods --- //

    MoveResult is_move_ok(std::string state_of_board ) override; // state_of_board: current state of the chess board
};

/*
// Class definition for knight chess piece
// ------------------------------------------
// This class inherits from the base chess_p class
// It contains specific attributes and methods for the knight piece
*/
class knight : public chess_p   
{    
private:
    // Private member variables

public:     
	// Public methods
    // -- Constructor --//
	knight(std::string start_loc, bool is_it_white);    

    // --- Override Methods --- //

	MoveResult is_move_ok(std::string state_of_board ) override;    
};     

#endif // CHESS_PIECES_HPP


