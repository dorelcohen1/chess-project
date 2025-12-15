// filepath: chess-project/code/class_chess_p.cpp

#include "class_chess_p.hpp"
#include <iostream>

// Constructor
chess_p::chess_p(std::string loc, bool is_it_white) 
{
	location = loc;
	is_white = is_it_white;
}

bool chess_p::get_is_alive()
{
	return is_alive;
}

bool chess_p::get_is_white()
{
	return is_white;
}

void chess_p::set_destination(std::string try_move)
{
	destination = try_move;
}

void chess_p::set_die()
{
	is_alive = false;
}

void chess_p::move()
{
	location = destination;
}
std::string chess_p::give_location()
{
    return location;
}