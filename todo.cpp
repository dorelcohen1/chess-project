//+ part 1 +////////////////////////////////////////////////////////////////////////////////////////////////

//! fix the bool is_there_check(std::string state_of_board); logic
//x// fix the king is_move_ok
//x// fix the rook is_move_ok
//x// fix the rook use of is_there_check
//x// fix the king use of is_there_check
//TODO get the board class runing
//TODO get the cmd output runing or the frontend 
//TODO make the main.cpp logic and run a working game

//+ part 2 +////////////////////////////////////////////////////////////////////////////////////////////////

//TODO get all the chess pieces runing 

//+ error idea +//
/*
//? will it get if the rook goes to b8 or c8 instade? maby its with the index and string changes we have? 
//-note-> see if 64 - [8 -> 7(problem becouse index from 0)] gets the less line to be only {b8 <--to--> h8} or mabye {B8 <--to--> G8}
//? see is_there_check logic for errors? 
//? it may be in it or in the const's?
//? see index in king and rook is move ok and test it 
//? test all line cases on the board all of [A][something] and [something][1] and [something][8] and [H][something]
//-note-> go over all index makeing and const's and chack logic!!!
*/

/*
//+ test out +//////////////////////////////////////////////////////////////////////////////////////////////
//|=== Rook + King endgame test ===
//|Initial board:
//|R###K#######################################################k###0
//!Move 1: White rook a1 -> a8: 0 ✗ (Expected 1=Valid_Check)
//|Board after move 1:
//|####K###################################################R###k###1
//!Move 2: Black king e8 -> d8: 0 ✗ (Expected 4=Invalid_SelfCheck)
//|Move 2 alt: Black king e8 -> f7: 0 ✓ (Valid)
//|Board after move 2:
//|####K################################################k##R#######0
//|Move 3: White king e1 -> e2: 0 ✓ (Valid)
//|Board after move 3:
//|############K########################################k##R#######1
//!Move 4: White rook a8 -> f8: 6 ✗ (Unexpected result)
//|=== End of test ===
*/