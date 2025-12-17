#include "board.hpp"
#include <iostream>

board::board() 
{
    int i = 0;
    int j = 0;
    char file = '\0';
    std::string pos = "";

    // Initialize the chess board with pieces in starting positions
    state_of_board_as_string = STARTING_BOARD_STATE;

    // Initialize the chess_board array with nullptrs
    for ( i = 0; i < BOARD_SIZE_UP; ++i)
	{
		for ( j = 0; j < BOARD_SIZE_RIGHT; ++j)
		{
			chess_board[i][j] = nullptr; // Initialize all board positions to nullptr
		}
	}

    // Place black pieces
    chess_board[0][0] = new rook("a8", true);   // Black Rook
	chess_board[0][1] = new knight("b8", true);  // Black Knight
	chess_board[0][2] = new bishop("c8", true); // Black Bishop
	chess_board[0][3] = new queen("d8", true);  // Black Queen
	chess_board[0][4] = new king("e8", true);   // Black King
	chess_board[0][5] = new bishop("f8", true); // Black Bishop
	chess_board[0][6] = new knight("g8", true);  // Black Knight
	chess_board[0][7] = new rook("h8", true);   // Black Rook
	for (j = 0; j < BOARD_SIZE_RIGHT; ++j)
	{
		file = 'a' + j;
		pos = "";
		pos += file;
		pos += '2';
		chess_board[1][j] = new pawn(pos, true); // Black Pawns
	}

    i = 0;
    j = 0;
    file = '\0';
    pos = "";

    // Place white pieces
    chess_board[7][0] = new rook("a1", false);   // White Rook
	chess_board[7][1] = new knight("b1", false);  // White Knight
	chess_board[7][2] = new bishop("c1", false); // White Bishop
	chess_board[7][3] = new queen("d1", false);  // White Queen
	chess_board[7][4] = new king("e1", false);   // White King
	chess_board[7][5] = new bishop("f1", false); // White Bishop
	chess_board[7][6] = new knight("g1", false);  // White Knight
	chess_board[7][7] = new rook("h1", false);   // White Rook
	for (j = 0; j < BOARD_SIZE_RIGHT; ++j)
	{
			file = 'a' + j;
			pos = "";
			pos += file;
			pos += '7';
			chess_board[6][j] = new pawn(pos, false); // White Pawns
	}
	// The rest of the board is already initialized to nullptr
}

// Destructor to clean up dynamically allocated pieces
board::~board()
{
	for (int i = 0; i < BOARD_SIZE_UP; ++i)
	{
		for (int j = 0; j < BOARD_SIZE_RIGHT; ++j)
		{
			delete chess_board[i][j]; // Delete each piece if it exists
			chess_board[i][j] = nullptr; // Set pointer to nullptr after deletion
		}
	}
}

bool board::kill(chess_p* p_chess)
{
	std::string des = p_chess->get_destination();

	int col = des[0] - 'a';
	int row = des[1] - '1';

	if (chess_board[row][col] != nullptr)
	{
		delete chess_board[row][col];
		chess_board[row][col] = nullptr;
		return true;
	}

	return false;
}
