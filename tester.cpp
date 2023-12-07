#include"ChessBoard.h"

#include<iostream>

using std::cout;

int main() {

	cout << "========================\n";
	cout << "Testing the Chess Engine\n";
	cout << "========================\n\n";

	ChessBoard cb;
	//cb.loadState("1Q3k2/8/5K2/8/8/8/8/8 b -"); // POSITION 1
	//cb.loadState("k7/8/1KNN4/8/8/8/8/8 b -"); // POSITION 3
	//cb.loadState("7k/6R1/5K2/8/8/8/8/8 b -"); // POSITION 4
	//cb.loadState("R7/1k6/2B5/1P1N4/1K6/8/8/8 b -"); // POSITION 5
	//cb.loadState("8/k1NN4/2P5/8/8/8/8/6K1 b -"); // POSITION 6
	//cb.loadState("r1bqkbnr/pp2pQpp/2np4/2p5/2B1P3/8/PPPP1PPP/RNB1K1NR b -"); // POSITION 7
	//cb.loadState("r1bqkb1r/pp1npppp/2pN1n2/8/3P4/8/PPP1QPPP/R1B1KBNR b -"); // POSITION 8
	cb.loadState("7k/5K2/6Q1/8/8/8/8/8 b -"); // POSITION 9
	cb.displayPieces();

	//cb.submitMove("D7", "D6");
	cout << cb.gm.isCheckMateOrStaleMate(BLACK) << std::endl;

	// THIS WAS USED FOR CHECKING PROPER PAWN BEHAVIOUR
	//cout << cb.gm.isMoveValid(Position("A2"), Position("A4")) << std::endl;
	//cout << cb.gm.isMoveValid(Position("E7"), Position("E5")) << std::endl;
	//cout << cb.gm.isMoveValid(Position("D6"), Position("D4")) << std::endl;
	//cout << cb.gm.isMoveValid(Position("D6"), Position("C5")) << std::endl;
	//cout << cb.gm.isMoveValid(Position("E7"), Position("F6")) << std::endl;
	//cout << cb.gm.isMoveValid(Position("E7"), Position("D6")) << std::endl;

	//cb.submitMove("D7", "D6");
	//cb.submitMove("D7", "D6");
	
	/* THIS IS THE CODE I WAS USING TO TEST THE PROGRAM
	cb.submitMove("B1", "C3");
	cout << "\nAFTER THE CHANGE" << std::endl;
	cout << '\n';
	cb.displayPieces();
	cb.submitMove("C3", "E4"); // Make sure that white cannot move again
	cout << "\nAFTER THE CHANGE" << std::endl;
	cout << '\n';
	cb.displayPieces();
	cb.submitMove("A7", "A5"); 
	cout << "\nAFTER THE CHANGE" << std::endl;
	cout << '\n';
	cb.displayPieces();
	cb.submitMove("E2", "E4"); 
	cout << "\nAFTER THE CHANGE" << std::endl;
	cout << '\n';
	cb.displayPieces();
	cb.submitMove("A8", "A6"); 
	cout << "\nAFTER THE CHANGE" << std::endl;
	cout << '\n';
	cb.displayPieces();
	cb.submitMove("E4", "E5"); 
	cout << "\nAFTER THE CHANGE" << std::endl;
	cout << '\n';
	cb.displayPieces();
	cb.submitMove("A6", "A8"); 
	cout << "\nAFTER THE CHANGE" << std::endl;
	cout << '\n';
	cb.displayPieces();
	cb.submitMove("C1", "H5"); 
	cout << "\nAFTER THE CHANGE" << std::endl;
	cout << '\n';
	cb.displayPieces();
	cb.submitMove("D1", "H5"); 
	cout << "\nAFTER THE CHANGE" << std::endl;
	cout << '\n';
	cb.displayPieces();
	cb.submitMove("D8", "D5"); 
	cout << "\nAFTER THE CHANGE" << std::endl;
	cout << '\n';
	cb.displayPieces();
	cb.submitMove("H5", "F4"); 
	cout << "\nAFTER THE CHANGE" << std::endl;
	cout << '\n';
	cb.displayPieces();
	cb.submitMove("H5", "D5"); 
	cout << "\nAFTER THE CHANGE" << std::endl;
	cout << '\n';
	cb.displayPieces();
	cb.submitMove("E8", "F7"); 
	cout << "\nAFTER THE CHANGE" << std::endl;
	cout << '\n';
	cb.displayPieces();
	cb.submitMove("E1", "E3"); 
	cout << "\nAFTER THE CHANGE" << std::endl;
	cout << '\n';
	cb.displayPieces();
	cb.submitMove("E1", "E2"); 
	cout << "\nAFTER THE CHANGE" << std::endl;
	cout << '\n';
	cb.displayPieces();
	cb.submitMove("F7", "H5"); 
	cout << "\nAFTER THE CHANGE" << std::endl;
	cout << '\n';
	cb.displayPieces();
	cb.submitMove("F7", "E7"); 
	cout << "\nAFTER THE CHANGE" << std::endl;
	cout << '\n';
	cb.displayPieces();
	*/

	//cb.submitMove("A6", "F6"); 
	//cout << "\nAFTER THE CHANGE" << std::endl;
	//cout << '\n';
	//cb.displayPieces();
	//cb.submitMove("E5", "F6"); 
	//cout << "\nAFTER THE CHANGE" << std::endl;
	//cout << '\n';
	//cb.displayPieces();

}
