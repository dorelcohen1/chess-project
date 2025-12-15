// filepath: chess_project\part a\chess_pieces.cpp

#include "chess_pieces.hpp"

// --- Rook Constructor --- //
/*
^   * fanction name:        rook::rook
---------------------------------------------------------------------------------------
    * fanction description: Initializes a Rook chess piece with its starting location and color.
    * fanction input:       const std::string& start_loc, bool is_it_white
        - start_loc:        The starting location of the Rook piece.
        - is_it_white:      Indicates whether the piece is white (true) or black (false).
    * fanction output:      void
    * return value:         None.
    * eficency:             O(1) - constant time complexity.
---------------------------------------------------------------------------------------
*/
rook::rook(const std::string& start_loc, bool is_it_white) : chess_p(start_loc, is_it_white){}

/*
^   * fanction name:        rook::is_move_ok
---------------------------------------------------------------------------------------
    * fanction description: Determines if the proposed move for the Rook piece is valid based on the current state of the chess board.
    * fanction input:       std::string state_of_board
        - state_of_board:   The current state of the chess board.
    * fanction output:      MoveResult
    * return value:         An enumeration value indicating the result of the move validation.
    * eficency:             O(n) - linear time complexity, where n is the number of squares checked for path clearance.
---------------------------------------------------------------------------------------
*/
MoveResult rook::is_move_ok(std::string state_of_board)
{
    /*
    Valid = 0,
    Valid_Check = 1,
    Invalid_NoPieceAtSource = 2,
    Invalid_DestinationOccupiedByOwnPiece = 3,
    Invalid_SelfCheck = 4,
    Invalid_IndexOutOfRange = 5,
    Invalid_IllegalMovement = 6,
    Invalid_SameSourceAndDestination = 7,
    Valid_Checkmate = 8
    */

    std::string loc = give_location();                       // Get the current location of the rook
    std::string dest = get_destination();                    // Get the destination location for the move
    char turn = state_of_board[BOARD_STATE_LENGTH - 1];      // Extract whose turn it is from the board state
    int source_index = 0;                                    // Index of the source square on the board
    int dest_index = 0;                                      // Index of the destination square on the board
    int start_index = 0;                                     // Starting index for path validation
    int end_index = 0;                                       // Ending index for path validation
    int step = 0;                                            // Step direction (vertical or horizontal)
    bool dest_is_white = false;                              // Color of the piece at the destination
    char dest_piece = '\0';                                  // Piece at the destination square
    int i = 0;                                               // Loop variable
    std::string new_state_of_board = state_of_board;         // Copy of the board state for self-check validation
    char opponent_king = '\0';                               // Opponent's king character
    bool king_exists = false;                                // Flag to check if opponent's king exists

    // code number 7
    // Check for same source and destination
    if (loc == dest)
    {
        return MoveResult::Invalid_SameSourceAndDestination;
    }

    // code number 2
    // Check if there is a piece at the source location
    source_index = (loc[RANK_OFFSET] - '1') * VERTICAL_STEP + (loc[FILE_OFFSET] - 'a');
    if (state_of_board[source_index] == EMPTY_SQUARE)
    {
        return MoveResult::Invalid_NoPieceAtSource;
    }

    // code number 3
    // Check if the destination is occupied by own piece
    dest_index = (dest[RANK_OFFSET] - '1') * VERTICAL_STEP + (dest[FILE_OFFSET] - 'a');
    if (state_of_board[dest_index] != EMPTY_SQUARE)
    {
        dest_piece = state_of_board[dest_index];
        dest_is_white = (dest_piece >= 'A' && dest_piece <= 'Z');
        if (dest_is_white == get_is_white())
        {
            return MoveResult::Invalid_DestinationOccupiedByOwnPiece;
        }
    }

    // code number 5
    // Check for index out of range
    if (source_index < 0 || source_index >= BOARD_SIZE || dest_index < 0 || dest_index >= BOARD_SIZE)
    {
        return MoveResult::Invalid_IndexOutOfRange;
    }

    // code number 6
    // Validate rook movement (horizontal or vertical)
    if ((turn == WHITE_TURN && get_is_white()) || (turn != WHITE_TURN && !get_is_white())) // Check if it's the correct player's turn
    {
        if (loc[FILE_OFFSET] == dest[FILE_OFFSET] || loc[RANK_OFFSET] == dest[RANK_OFFSET]) // Valid rook move (same file or same rank)
        {
            // Calculate start and end indices for path validation
            // this converts loc and dest from chess notation to board string index so we can use simple integer arithmetic
            start_index = (loc[RANK_OFFSET] - '1') * VERTICAL_STEP + (loc[FILE_OFFSET] - 'a');
            end_index = (dest[RANK_OFFSET] - '1') * VERTICAL_STEP + (dest[FILE_OFFSET] - 'a');
            
            // Determine step direction based on movement type
            if (loc[FILE_OFFSET] == dest[FILE_OFFSET])
            {
            // Vertical movement: check if moving up or down
            if (loc[RANK_OFFSET] < dest[RANK_OFFSET])
            {
                step = VERTICAL_STEP;  // Moving up
            }
            else
            {
                step = -VERTICAL_STEP; // Moving down
            }
            }
            else
            {
            // Horizontal movement: check if moving left or right
            if (loc[FILE_OFFSET] < dest[FILE_OFFSET])
            {
                step = HORIZONTAL_STEP;  // Moving right
            }
            else
            {
                step = -HORIZONTAL_STEP; // Moving left
            }
            }
            
            for (i = start_index + step; i != end_index; i += step)
            {
                if (state_of_board[i] != EMPTY_SQUARE)
                {
                    return MoveResult::Invalid_IllegalMovement;
                }
            }
        }
        else
        {
            return MoveResult::Invalid_IllegalMovement;
        }
    }
    else
    {
        return MoveResult::Invalid_IllegalMovement;
    }

    // code number 4
    // check for self-check
    // make a copy of how the board would look after the move
    new_state_of_board = state_of_board;
    new_state_of_board[dest_index] = new_state_of_board[source_index]; // Move piece to destination
    new_state_of_board[source_index] = EMPTY_SQUARE;                   // Empty the source square
    if (is_there_check(new_state_of_board, turn))
    {
        return MoveResult::Invalid_SelfCheck;
    }
    // this makes sure that the move does not put own king in check or if it was already in check it makes sure the move gets the king out of check

    // If all checks passed, the move is valid
    // now we need to check if the move results in a check or checkmate
    // we can use the is_there_check function again
    new_state_of_board = state_of_board;
    new_state_of_board[dest_index] = new_state_of_board[source_index]; // Move piece to destination
    new_state_of_board[source_index] = EMPTY_SQUARE;                   // Empty the source square
    // Check if the move puts the opponent in check
    if (is_there_check(new_state_of_board, turn))
    {
        return MoveResult::Valid_Check;
    }
    
    // Determine opponent's king character
    if (get_is_white())
    {
        opponent_king = 'K';
    }
    else
    {
        opponent_king = 'k';
    }
    
    // Check if opponent's king is on the board
    king_exists = false;
    for (i = 0; i < BOARD_SIZE; i++)
    {
        if (new_state_of_board[i] == opponent_king)
        {
            king_exists = true;
            break;
        }
    }
    
    // If king doesn't exist, it's checkmate; otherwise, it's a valid move
    if (!king_exists)
    {
        return MoveResult::Valid_Checkmate;
    }
    else
    {
        return MoveResult::Valid;
    }
}

/*^   * fanction name:        rook::is_there_check
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
bool rook::is_there_check(std::string state_of_board, char turn)
{
    // TODO : Implement check detection logic for the rook
    return false; // Placeholder return value
}

