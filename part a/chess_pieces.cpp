// filepath: chess_project\part a\chess_pieces.cpp

#include "chess_pieces.hpp"

// --- Rook Constructor --- //
rook::rook(std::string start_loc, bool is_it_white) 
    : chess_p(start_loc, is_it_white)
{
    // Rook-specific initialization (if needed)
}

bool rook::is_move_ok(std::string state_of_board) override
{
    
}

