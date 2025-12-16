#include <iostream>
#include "board.hpp"

int main() 
{
    std::cout << "Chess pieces module loaded successfully." << std::endl;
    // some tests:
    // rook
    rook test_rook("a1", true);
    std::cout << test_rook.give_location() << std::endl; // see if location is set correctly
    std::cout << test_rook.get_is_alive() << std::endl;  // see if is_alive is true
    test_rook.set_destination("a4");
    std::cout << test_rook.get_destination() << std::endl; // see if destination is set correctly
    if (test_rook.give_location() == "a1" && test_rook.get_is_alive() == true && test_rook.get_destination() == "a4") 
    {
        std::cout << "Rook tests passed." << std::endl;
    } 
    else 
    {
        std::cout << "Rook tests failed." << std::endl;
    }
    // end of tests for rook


    std::cin.get(); // this keeps the console window open until a key is pressed
    return 0;
}

