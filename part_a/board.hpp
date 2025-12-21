#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>          // for std::string and other I/O operations
#include "chess_pieces.hpp"  // include chess pieces definitions

constexpr int BOARD_SIZE_UP = 8;   // Number of squares along one side of the chess board
constexpr int BOARD_SIZE_RIGHT = 8; // Number of squares along the other side of the chess board
const std::string STARTING_BOARD_STATE = "RNBQKBNRPPPPPPPP################################pppppppprnbqkbnr1"; // Initial board state

/* Class definition for the chess board */
class board 
{ 
private:
    // Private member variables

    // !pointers to all the chess pieces on the board we will format it to send to the frontend
    chess_p* chess_board[BOARD_SIZE_UP][BOARD_SIZE_RIGHT] = { nullptr }; // 8x8 board of chess pieces

    // !will hold the state of the board as a string after formatting it from the pieces on the board and will be used to send to the frontend
    std::string state_of_board_as_string; // string representation of the board state in the frontend format

    // !will hold the proposed move the user is trying to make in the frontend
    std::string try_move; // holds the proposed move in frontend format

    // !this will hold the code we need to send to the frontend after trying to make a move
    MoveResult move_result; // holds the result of the last move attempt 

    // !will hold the turn information in frontend format its important and carries all the needed info about the turn and is sent to pieces as state_of_board 
    std::string turn_info_frontend_format; // holds the turn information in frontend format

public:
    // Public methods
    //---------------//

    void update_board_state_string();

    // -- Constructor --//
    board(); // initializes the chess board with pieces in starting positions
	
    // --- getters --- //

    // --- setters --- //

    // --- Other Methods --- //
    bool kill(chess_p* p_chess);

    // --- Virtual Methods --- //

    // --- Destructor --- //
    ~board(); // destructor to clean up dynamically allocated memory
};
/*
we will use the 

-state_of_board_as_string    
-board[BOARD_SIZE_UP][BOARD_SIZE_RIGHT]

we will culculate the backend with the pointers on the board 
and then format it to a string to send to the frontend with state_of_board_as_string wich 
keeps track of what piece on the board is what 
we need this only to send to the frontend

from the frontend we will get
-try_move
-turn_info_frontend_format

and we will use these to culculate the backend
and then update the pointers on the board and the state_of_board_as_string
after every move attempt

pointers will be used to kill pieces and check for valid moves etc
string will be used to send to the frontend after every move attempt
*/

#endif // BOARD_HPP