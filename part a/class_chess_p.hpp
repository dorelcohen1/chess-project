#ifndef CLASS_CHESS_P_HPP
#define CLASS_CHESS_P_HPP

#include <iostream> // for std::string and other I/O operations

enum MoveResult 
{
    Valid = 0,
    Valid_Check = 1,
    Invalid_NoPieceAtSource = 2,
    Invalid_DestinationOccupiedByOwnPiece = 3,
    Invalid_SelfCheck = 4,
    Invalid_IndexOutOfRange = 5,
    Invalid_IllegalMovement = 6,
    Invalid_SameSourceAndDestination = 7,
    Valid_Checkmate = 8
} moveResult;

constexpr int BOARD_SIZE = 64;                           // Total number of squares on the chess board
constexpr int BOARD_STATE_LENGTH = 65;                   // Board state string length (64 squares + 1 turn indicator)
constexpr char EMPTY_SQUARE = '#';                       // Character representing an empty square
constexpr char WHITE_TURN = '0';                         // Character indicating it's white's turn
constexpr int VERTICAL_STEP = 8;                         // Step size to move vertically (one rank)
constexpr int HORIZONTAL_STEP = 1;                       // Step size to move horizontally (one file)
constexpr int FILE_OFFSET = 0;                           // Index offset for file (column) in location string
constexpr int RANK_OFFSET = 1;                           // Index offset for rank (row) in location string

/*
// Class definition for chess pieces 
// ------------------------------------------
// This class serves as a base class for all chess pieces
// It contains common attributes and methods that all chess pieces share
// --- Class Definition --- //
*/
class chess_p 
{
private:
    // Private member variables
    std::string location; // get set in chess_p constructor
    std::string destination; // get set in set_destination method
    bool is_white; // get set in chess_p constructor
    bool is_alive; // is set to true in chess_p constructor

public:
    // Public methods

    // -- Constructor --//

    chess_p(std::string loc, bool is_it_white); // loc: initial location, color: true for white, false for black

    // --- Getters --- //

    bool get_is_alive(); // returns is_alive status
    bool get_is_white(); // returns is_white status
    std::string get_destination(); // returns destination location

    // --- Setters --- //

    void set_destination(std::string try_move); // try_move: proposed destination location
    void set_die(); // turns is_alive from true to false 

    // --- Other Methods --- //

    void move(); // updates location to destination if move is valid
    std::string give_location(); // returns current location of the piece
    bool is_there_check(std::string state_of_board, char turn);


    // --- Virtual Methods --- //

    virtual MoveResult is_move_ok(std::string state_of_board ) = 0; // state_of_board: current state of the chess board

};


#endif // CLASS_CHESS_P_HPP 