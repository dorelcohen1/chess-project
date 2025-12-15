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
    
    rook(std::string start_loc, bool is_it_white);

    // --- Other Methods --- //

    bool is_move_ok(std::string state_of_board ) override; // state_of_board: current state of the chess board
};


#endif // CHESS_PIECES_HPP