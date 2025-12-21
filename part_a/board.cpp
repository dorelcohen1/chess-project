#include "board.hpp"
#include <iostream>

board::board() 
{
    int i = 0;
    int j = 0;

    char file = '\0';

    std::string pos = "";

    state_of_board_as_string = STARTING_BOARD_STATE;

    // set it all to null pointer
    for (i = 0; i < BOARD_SIZE_UP; ++i)
    {
        for (j = 0; j < BOARD_SIZE_RIGHT; ++j)
        {
            chess_board[i][j] = nullptr;
        }
    }

    chess_board[0][0] = new rook("a1", true);    // White Rook (true = white)
    chess_board[0][1] = new knight("b1", true);  // White Knight
    chess_board[0][2] = new bishop("c1", true);  // White Bishop
    chess_board[0][3] = new queen("d1", true);   // White Queen
    chess_board[0][4] = new king("e1", true);    // White King
    chess_board[0][5] = new bishop("f1", true);  // White Bishop
    chess_board[0][6] = new knight("g1", true);  // White Knight    
    chess_board[0][7] = new rook("h1", true);    // White Rook
    
    // White pawns at rank 2 (row 1)
    for (j = 0; j < BOARD_SIZE_RIGHT; ++j)
    {
        // make the loc (pos) string 
        file = 'a' + j;
        pos = "";
        pos += file;
        pos += '2';

        chess_board[1][j] = new pawn(pos, true);  // White Pawns
    }

    // Row index 7 corresponds to rank 8
    chess_board[7][0] = new rook("a8", false);   // Black Rook (false = black)
    chess_board[7][1] = new knight("b8", false); // Black Knight
    chess_board[7][2] = new bishop("c8", false); // Black Bishop
    chess_board[7][3] = new queen("d8", false);  // Black Queen
    chess_board[7][4] = new king("e8", false);   // Black King
    chess_board[7][5] = new bishop("f8", false); // Black Bishop
    chess_board[7][6] = new knight("g8", false); // Black Knight
    chess_board[7][7] = new rook("h8", false);   // Black Rook
    
    // Black pawns at rank 7 (row 6)
    for (j = 0; j < BOARD_SIZE_RIGHT; ++j)
    {
        // make the loc (pos) string 
        file = 'a' + j;
        pos = "";
        pos += file;
        pos += '7';

        chess_board[6][j] = new pawn(pos, false);  // Black Pawns
    }
}



// Destructor to clean up dynamically allocated pieces
board::~board()
{ 
	int i = 0;
	int j = 0;

	for (i = 0; i < BOARD_SIZE_UP; ++i)
	{
		for (j = 0; j < BOARD_SIZE_RIGHT; ++j)
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

void board::update_board_state_string()
{
	// Reset the board state string
	state_of_board_as_string = "";

	for (int i = 0; i < BOARD_SIZE_UP; ++i)
	{
		for (int j = 0; j < BOARD_SIZE_RIGHT; ++j)
		{
			if (chess_board[i][j] != nullptr)
			{
				// Append the piece representation to the board state string
				state_of_board_as_string += chess_board[i][j]->get_piece_representation();
			}
			else
			{
				// Append empty square character
				state_of_board_as_string += EMPTY_SQUARE;
			}
		}
	}

	// Append turn information at the end
	state_of_board_as_string += turn_info_frontend_format;
}