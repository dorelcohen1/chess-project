#include <iostream>
#include "board.hpp"

void test_rook();
void test_knight();
void test_bishop();
void test_queen();
void test_pawn();
void test_king();

int main() 
{
    std::cout << "Chess pieces module loaded successfully." << std::endl;
    
    // some tests:

    // rook
    test_rook();

    std::cin.get(); // this keeps the console window open until a key is pressed
    return 0;
}

void test_rook()
{
        // rook
    rook test_rook("a1", true);

    if(test_rook.give_location() == "a1" && test_rook.get_is_alive() == true && test_rook.get_is_white() == true)
    {
        std::cout << "Rook make tests passed." << std::endl;
    }
    else
    {
        std::cout << "Rook make tests failed." << std::endl;
    }
    test_rook.set_destination("a4");
    if(test_rook.get_destination() == "a4")
    {
        std::cout << "Rook destination set correctly." << std::endl;
    }
    else
    {
        std::cout << "Rook destination not set correctly." << std::endl;
    }
    MoveResult result = test_rook.is_move_ok("R#####rr########################################################1");
    if(result == MoveResult::Valid_Checkmate)
    {
        std::cout << "Rook move validation passed." << std::endl;
    }
    else
    {
        std::cout << "got: " << std::endl;
        std::cout << result << std::endl;
        std::cout << "Rook move validation failed." << std::endl;
    }   
    test_rook.move();
    if(test_rook.give_location() == "a4")
    {
        std::cout << "Rook move executed correctly." << std::endl;
    }
    else
    {
        std::cout << "Rook move execution failed." << std::endl;
    }
    test_rook.set_die();
    if(test_rook.get_is_alive() == false)
    {
        std::cout << "Rook set_die() test passed." << std::endl;
    }
    else
    {
        std::cout << "Rook set_die() test failed. \n\n\n" << std::endl;
    }
    // end of tests for rook
}
void test_knight()
{

}
void test_bishop()
{

}
void test_queen()
{

}
void test_pawn()
{

}
void test_king()
{

}