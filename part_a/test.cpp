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
    std::cout << "Chess pieces module loaded successfully.\n" << std::endl;
    
    // some tests:

    // rook
    test_rook();

    //king
    test_king();


    //combo tests
    test_rook_and_king();

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
    std::cout << "=== Rook + King endgame test ===" << std::endl;

    // Initial board:
    // White: King e1, Rook a1
    // Black: King e8
    // White to move
    std::string board =
        "R###K###"   // rank 1
        "########"  // rank 2
        "########"  // rank 3
        "########"  // rank 4
        "########"  // rank 5
        "########"  // rank 6
        "########"  // rank 7
        "####k###"  // rank 8
        "0";        // white to move

    king w_king("e1", true);
    rook w_rook("a1", true);
    king b_king("e8", false);

    std::cout << "Initial board:\n" << board << std::endl;

    // --- Move 1: White rook a1 -> a8 (check) ---
    w_rook.set_destination("a8");
    MoveResult result = w_rook.is_move_ok(board);

    std::cout << "White rook a1 -> a8 : ";
    std::cout << result << std::endl;

    if (result == MoveResult::Valid_Check)
    {
        w_rook.move();

        // update board
        board[0] = '#';    // a1
        board[56] = 'R';   // a8
        board.back() = '1'; // black to move
    }
    else 
    {
        std::cout << "White rook a1 -> a8 didnt get  : MoveResult::Valid_Check it got:  " << result <<"\n";
    }

    std::cout << "Board after move 1:\n" << board << std::endl;

    // --- Move 2: Black king e8 -> d8 ---
    b_king.set_destination("d8");
    result = b_king.is_move_ok(board);

    std::cout << "Black king e8 -> d8 : " <<"\n";
    std::cout << result << std::endl;

    if (result == MoveResult::Invalid_SelfCheck)
    {
        b_king.move();

        board[60] = '#';  // e8
        board[59] = 'k';  // d8
        board.back() = '0'; // white to move
    }    
    else 
    {
        std::cout << "Black king e8 -> d8 didnt get: MoveResult::Invalid_SelfCheck it got:  " << result <<"\n";;
    }

    std::cout << "Board after move 2:\n" << board << std::endl;

    // --- Move 3: White king e1 -> d2 ---
    w_king.set_destination("d2");
    result = w_king.is_move_ok(board);

    std::cout << "White king e1 -> d2 : ";
    std::cout << result << std::endl;

    if (result == MoveResult::Valid_Check)
    {
        w_king.move();

        board[4] = '#';    // e1
        board[11] = 'K';   // d2
        board.back() = '1'; // black to move
    }
    else 
    {
        std::cout << "\n" << "Black king e8 -> d8 didnt get: MoveResult::Invalid_SelfCheck it got:" << result <<"\n";;
    }

    std::cout << "Board after move 3:\n" << board << std::endl;

    // --- Final move: White rook a8 -> d8 (KING CAPTURE) ---
    w_rook.set_destination("d8");
    result = w_rook.is_move_ok(board);

    std::cout << "White rook a8 -> d8 : ";
    std::cout << result << std::endl;

    if (result == MoveResult::Valid_Checkmate)
    {
        w_rook.move();

        // remove black king, place rook
        board[56] = '#';  // a8
        board[59] = 'R';  // d8
        board.back() = '1';

        std::cout << "Black king captured. Game over." << std::endl;
    }
    else
    {
        std::cout << "Final move failed unexpectedly." << std::endl;
        std::cout << "White rook a8 -> d8 didnt get: MoveResult::Valid_Checkmate it got:" << result <<"\n";;
    }
    w_rook.move();

    // remove black king, place rook
    board[56] = '#';  // a8
    board[59] = 'R';  // d8
    board.back() = '1';
    w_rook.set_destination("d1");
    result = w_rook.is_move_ok(board);
    if (result == MoveResult::Valid_Checkmate)
    {
        w_rook.move();

        // remove black king, place rook
        board[56] = '#';  // a8
        board[59] = 'R';  // d8
        board.back() = '1';

        std::cout << "if you see this Valid_Checkmate is delayed by 1 round." << std::endl;
    }

    std::cout << "Final board:\n" << board << std::endl;

    std::cout << "=== End of test ===" << std::endl;
}
