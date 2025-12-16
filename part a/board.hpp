#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>          // for std::string and other I/O operations
#include "chess_pieces.hpp"  // include chess pieces definitions

constexpr int BOARD_SIZE_UP = 8;   // Number of squares along one side of the chess board
constexpr int BOARD_SIZE_RIGHT = 8; // Number of squares along the other side of the chess board

/* Class definition for the chess board */
class board
{
private:
	// Private member variables

	// !pointers to all the chess pieces on the board we will format it to send to the frontend
	chess_p* board[BOARD_SIZE_UP][BOARD_SIZE_RIGHT] = { nullptr }; // 8x8 board of chess pieces

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

	// -- Constructor --//
	board()
	{
		for (int i = 0; i < BOARD_SIZE_UP; ++i)
		{
			for (int j = 0; j < BOARD_SIZE_RIGHT; ++j)
			{
				board[i][j] = nullptr; // Initialize all board positions to nullptr
			}
		}
		board[0][0] = new rook("a8", true);   // Black Rook
		board[0][1] = new knight("b8", true);  // Black Knight
		board[0][2] = new bishop("c8", true); // Black Bishop
		board[0][3] = new queen("d8", true);  // Black Queen
		board[0][4] = new king("e8", true);   // Black King
		board[0][5] = new bishop("f8", true); // Black Bishop
		board[0][6] = new knight("g8", true);  // Black Knight
		board[0][7] = new rook("h8", true);   // Black Rook
		for (int j = 0; j < BOARD_SIZE_RIGHT; ++j)
		{
			char file = 'a' + j;
			std::string pos = "";
			pos += file;
			pos += '2';
			board[1][j] = new pawn(pos, true); // Black Pawns
		}
		board[7][0] = new rook("a1", false);   // White Rook
		board[7][1] = new knight("b1", false);  // White Knight
		board[7][2] = new bishop("c1", false); // White Bishop
		board[7][3] = new queen("d1", false);  // White Queen
		board[7][4] = new king("e1", false);   // White King
		board[7][5] = new bishop("f1", false); // White Bishop
		board[7][6] = new knight("g1", false);  // White Knight
		board[7][7] = new rook("h1", false);   // White Rook
		for (int j = 0; j < BOARD_SIZE_RIGHT; ++j)
		{
			char file = 'a' + j;
			std::string pos = "";
			pos += file;
			pos += '7';
			board[6][j] = new pawn(pos, false); // White Pawns
		}
		// The rest of the board is already initialized to nullptr
	}

	// --- getters --- //

	// --- setters --- //

	// --- Other Methods --- //

	// --- Virtual Methods --- //

	// --- Destructor --- //
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