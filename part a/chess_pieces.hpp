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

constexpr int BOARD_SIZE = 64;                           // Total number of squares on the chess board
constexpr int BOARD_STATE_LENGTH = 65;                   // Board state string length (64 squares + 1 turn indicator)
constexpr char EMPTY_SQUARE = '#';                       // Character representing an empty square
constexpr char WHITE_TURN = '0';                         // Character indicating it's white's turn
constexpr int VERTICAL_STEP = 8;                         // Step size to move vertically (one rank)
constexpr int HORIZONTAL_STEP = 1;                       // Step size to move horizontally (one file)
constexpr int FILE_OFFSET = 0;                           // Index offset for file (column) in location string
constexpr int RANK_OFFSET = 1;                           // Index offset for rank (row) in location string

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

    // --- Other Methods --- //

    bool is_there_check(std::string state_of_board, char turn); // state_of_board: current state of the chess board

};


#endif // CHESS_PIECES_HPP