#include <iostream>
#include "board.hpp"
 
void test_rook();
void test_knight(); 
void test_bishop();
void test_queen();
void test_pawn(); 
void test_king();  
void test_rook_and_king();
 
int main() 
{
    std::cout << "Chess pieces module loaded successfully." << std::endl;
    
    // some tests:

    // rook
    test_rook();

    //king
    test_king();

    std::cin.get(); // this keeps the console window open until a key is pressed
    return 0;
}

void test_rook()
{
    // rook
    rook test_rook("a1", true);

    if(test_rook.give_location() == "a1" && test_rook.get_is_white() == true)
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
    MoveResult result = test_rook.is_move_ok("R#####rr########################################################0");
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
    // king
    king test_king("a1", true);

    if(test_king.give_location() == "a1" && test_king.get_is_white() == true)
    {
        std::cout << "king make tests passed." << std::endl;
    }
    else
    {
        std::cout << "king make tests failed." << std::endl;
    }
    test_king.set_destination("b1");
    if(test_king.get_destination() == "b1")
    {
        std::cout << "king destination set correctly." << std::endl;
    }
    else
    {
        std::cout << "king destination not set correctly." << std::endl;
    }
    MoveResult result = test_king.is_move_ok("K###############################################################0");
    if(result == MoveResult::Valid_Checkmate)
    {
        std::cout << "king move validation passed." << std::endl;
    }
    else
    {
        std::cout << "got: " << std::endl;
        std::cout << result << std::endl;
        std::cout << "king move validation failed." << std::endl;
    }   
    test_king.move();
    if(test_king.give_location() == "b1")
    {
        std::cout << "king move executed correctly." << std::endl;
    }
    else
    {
        std::cout << "king move execution failed." << std::endl;
    }
    test_king.set_destination("c1");
    result = test_king.is_move_ok("#K#######################################k######################0");
    if(result == MoveResult::Valid)
    {
        std::cout << "king move validation 2 passed." << std::endl;
    }
    else
    {
        std::cout << "got: " << std::endl;
        std::cout << result << std::endl;
        std::cout << "king move validation 2 failed." << std::endl;
    } 
    test_king.set_destination("a1");
    result = test_king.is_move_ok("kK##############################################################0");
    if(result == MoveResult::Valid_Checkmate)
    {
        std::cout << "king move validation 3 passed." << std::endl;
    }
    else
    {
        std::cout << "got: " << std::endl;
        std::cout << result << std::endl;
        std::cout << "king move validation 3 failed." << std::endl;
    }   

    // end of tests for king
}

void test_rook_and_king()
{
    void test_rook_and_king()
{
    // setup: white pieces
    king w_king("a1", true);
    rook w_rook1("a4", true);
    rook w_rook2("c3", true);

    // setup: black pieces
    king b_king("e8", false);
    rook b_rook1("c8", false);
    rook b_rook2("f7", false);

    std::cout << "=== Starting Rook+King mini-game ===" << std::endl;

    // initial sanity checks
    if (w_king.give_location() == std::string("a1") && w_king.get_is_white())
        std::cout << "White king initialized correctly at a1." << std::endl;
    else
        std::cout << "White king initialization FAILED." << std::endl;

    if (w_rook1.give_location() == std::string("a4") && w_rook1.get_is_white())
        std::cout << "White rook1 initialized correctly at a4." << std::endl;
    else
        std::cout << "White rook1 initialization FAILED." << std::endl;

    if (b_king.give_location() == std::string("e8") && !b_king.get_is_white())
        std::cout << "Black king initialized correctly at e8." << std::endl;
    else
        std::cout << "Black king initialization FAILED." << std::endl;

    std::cout << std::endl;

    // Move 1: White rook a4 -> a8 (aggressive rook lift toward enemy back rank)
    w_rook1.set_destination("a8");
    std::cout << "White rook1: set destination to a8." << std::endl;
    MoveResult result = w_rook1.is_move_ok("R#####rr########################################################0");
    if (result == MoveResult::Valid)
        std::cout << "White rook1 move validation passed (a4->a8)." << std::endl;
    else
    {
        std::cout << "White rook1 move validation failed (a4->a8). Got: " << std::endl;
        std::cout << result << std::endl;
    }
    w_rook1.move();
    if (w_rook1.give_location() == "a8")
        std::cout << "White rook1 executed move to a8 correctly." << std::endl;
    else
        std::cout << "White rook1 did NOT move to a8." << std::endl;

    std::cout << std::endl;

    // Move 2: Black rook f7 -> f4 (counterplay: try to activate)
    b_rook2.set_destination("f4");
    std::cout << "Black rook2: set destination to f4." << std::endl;
    result = b_rook2.is_move_ok("r###############################################################0");
    if (result == MoveResult::Valid)
        std::cout << "Black rook2 move validation passed (f7->f4)." << std::endl;
    else
    {
        std::cout << "Black rook2 move validation failed (f7->f4). Got: " << std::endl;
        std::cout << result << std::endl;
    }
    b_rook2.move();
    if (b_rook2.give_location() == "f4")
        std::cout << "Black rook2 executed move to f4 correctly." << std::endl;
    else
        std::cout << "Black rook2 did NOT move to f4." << std::endl;

    std::cout << std::endl;

    // Move 3: White rook a8 -> c8 (capture on c8 or dominate file) — attempt to remove black rook on c8
    w_rook1.set_destination("c8");
    std::cout << "White rook1: set destination to c8 (attack on enemy rook at c8)." << std::endl;
    result = w_rook1.is_move_ok("R##R##########################################################0");
    if (result == MoveResult::Valid)
        std::cout << "White rook1 move validation passed (a8->c8 capture/attack)." << std::endl;
    else if (result == MoveResult::Valid_Checkmate)
        std::cout << "White rook1 move validation returned checkmate (unexpected but accepted)." << std::endl;
    else
    {
        std::cout << "White rook1 move validation failed (a8->c8). Got: " << std::endl;
        std::cout << result << std::endl;
    }
    w_rook1.move();
    if (w_rook1.give_location() == "c8")
        std::cout << "White rook1 executed move to c8 correctly." << std::endl;
    else
        std::cout << "White rook1 did NOT move to c8." << std::endl;

    std::cout << std::endl;

    // Move 4: Black king e8 -> d8 (try to escape toward center)
    b_king.set_destination("d8");
    std::cout << "Black king: set destination to d8." << std::endl;
    result = b_king.is_move_ok("k##############################################################0");
    if (result == MoveResult::Valid)
        std::cout << "Black king move validation passed (e8->d8)." << std::endl;
    else
    {
        std::cout << "Black king move validation failed (e8->d8). Got: " << std::endl;
        std::cout << result << std::endl;
    }
    b_king.move();
    if (b_king.give_location() == "d8")
        std::cout << "Black king executed move to d8 correctly." << std::endl;
    else
        std::cout << "Black king did NOT move to d8." << std::endl;

    std::cout << std::endl;

    // Move 5: White rook2 c3 -> c7 (bring the second rook up to trap the king)
    w_rook2.set_destination("c7");
    std::cout << "White rook2: set destination to c7 to join the attack." << std::endl;
    result = w_rook2.is_move_ok("RR######k######################################################0");
    if (result == MoveResult::Valid)
        std::cout << "White rook2 move validation passed (c3->c7)." << std::endl;
    else
    {
        std::cout << "White rook2 move validation failed (c3->c7). Got: " << std::endl;
        std::cout << result << std::endl;
    }
    w_rook2.move();
    if (w_rook2.give_location() == "c7")
        std::cout << "White rook2 executed move to c7 correctly." << std::endl;
    else
        std::cout << "White rook2 did NOT move to c7." << std::endl;

    std::cout << std::endl;

    // Move 6: White king a1 -> b2 (close up to help limit escape squares)
    w_king.set_destination("b2");
    std::cout << "White king: set destination to b2 (advance to help mate)." << std::endl;
    result = w_king.is_move_ok("#K#######################################k######################0");
    if (result == MoveResult::Valid)
        std::cout << "White king move validation passed (a1->b2)." << std::endl;
    else
    {
        std::cout << "White king move validation failed (a1->b2). Got: " << std::endl;
        std::cout << result << std::endl;
    }
    w_king.move();
    if (w_king.give_location() == "b2")
        std::cout << "White king executed move to b2 correctly." << std::endl;
    else
        std::cout << "White king did NOT move to b2." << std::endl;

    std::cout << std::endl;

    // Final move: White rook1 c8 -> d8 (deliver final blow / mate if engine/state allows)
    w_rook1.set_destination("d8");
    std::cout << "White rook1: set destination to d8 (final attempt to trap king on d8)." << std::endl;
    result = w_rook1.is_move_ok("RrK############################################################0");
    if (result == MoveResult::Valid_Checkmate)
    {
        std::cout << "White rook1 move validation passed: CHECKMATE detected (c8->d8)." << std::endl;
    }
    else if (result == MoveResult::Valid)
    {
        std::cout << "White rook1 move validation passed (c8->d8) but not checkmate." << std::endl;
    }
    else
    {
        std::cout << "White rook1 move validation failed (c8->d8). Got: " << std::endl;
        std::cout << result << std::endl;
    }
    w_rook1.move();
    std::cout << "White rook1 new location: " << w_rook1.give_location() << std::endl;

    std::cout << std::endl;
    std::cout << "=== Mini-game finished ===" << std::endl;
    std::cout << "Final piece locations:" << std::endl;
    std::cout << "White king: " << w_king.give_location() << std::endl;
    std::cout << "White rook1: " << w_rook1.give_location() << std::endl;
    std::cout << "White rook2: " << w_rook2.give_location() << std::endl;
    std::cout << "Black king: " << b_king.give_location() << std::endl;
    std::cout << "Black rook1: " << b_rook1.give_location() << std::endl;
    std::cout << "Black rook2: " << b_rook2.give_location() << std::endl;

    std::cout << std::endl;
}
}

