#include"ChessBoard.h"

#include<iostream>

using std::cout;

int main() {

	//cout << "========================\n";
	//cout << "Testing the Chess Engine\n";
	//cout << "========================\n\n";

	//ChessBoard cb;
	//cb.loadState("1Q3k2/8/5K2/8/8/8/8/8 b -"); // POSITION 1
	//cb.loadState("k7/8/1KNN4/8/8/8/8/8 b -"); // POSITION 3
	//cb.loadState("7k/6R1/5K2/8/8/8/8/8 b -"); // POSITION 4
	//cb.loadState("R7/1k6/2B5/1P1N4/1K6/8/8/8 b -"); // POSITION 5
	//cb.loadState("8/k1NN4/2P5/8/8/8/8/6K1 b -"); // POSITION 6
	//cb.loadState("r1bqkbnr/pp2pQpp/2np4/2p5/2B1P3/8/PPPP1PPP/RNB1K1NR b -"); // POSITION 7
	//cb.loadState("r1bqkb1r/pp1npppp/2pN1n2/8/3P4/8/PPP1QPPP/R1B1KBNR b -"); // POSITION 8
	//cb.loadState("7k/5K2/6Q1/8/8/8/8/8 b -"); // POSITION 9
	//cb.loadState("r3k2r/8/P7/8/8/8/8/R3KB1R w KQkq"); 

	//cb.displayPieces();

	//Piece* tmp;
	//tmp = cb.gm.makeMove(Position("E8"), Position("G8"));
	//cb.displayPieces();
	//cb.gm.undoLastMove(Position("E8"), Position("G8"), tmp);
	//cb.displayPieces();
	//tmp = cb.gm.makeMove(Position("E8"), Position("G8"));
	//cout << "REDOO" << std::endl;
	//cb.displayPieces();
	//tmp = cb.gm.makeMove(Position("A8"), Position("A6"));
	//cb.displayPieces();
	//cb.gm.undoLastMove(Position("A8"), Position("A6"), tmp);
	//cb.displayPieces();
	//tmp = cb.gm.makeMove(Position("A8"), Position("A7"));
	//cb.displayPieces();
	//cb.gm.undoLastMove(Position("A8"), Position("A7"), tmp);
	//cb.displayPieces();
	//cb.gm.makeMove(Position("E8"), Position("G8"));
	//cb.displayPieces();
	//cb.gm.makeMove(Position("A8"), Position("A5"));
	//cb.displayPieces();
	//cout << "Yo";


	cout << "========================\n";
	cout << "Testing the Chess Engine\n";
	cout << "========================\n\n";

	ChessBoard cb;
	cb.loadState("Q3r2k/8/8/8/8/8/8/5K2 w -");
	cb.displayPieces();
	//cout << '\n';

	cb.submitMove("F1", "E1");
	cout << '\n';
	cb.displayPieces();

	//cb.submitMove("D4", "H6");
	//cout << '\n';

	//cb.submitMove("D2", "D4");
	//cout << '\n';

	//cb.submitMove("F8", "B4");
	//cout << '\n';

	//cout << "=========================\n";
	//cout << "Alekhine vs. Vasic (1931)\n";
	//cout << "=========================\n\n";

	//cb.loadState("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq");
	//cout << '\n';

	//cb.submitMove("E2", "E4");
	//cb.submitMove("E7", "E6");
	//cout << '\n';

	////cb.displayPieces();
	////cout << '\n';

	//cb.submitMove("D2", "D4");
	//cb.submitMove("D7", "D5");
	//cout << '\n';

	//cb.submitMove("B1", "C3");
	//cb.submitMove("F8", "B4");
	//cout << '\n';

	////cb.displayPieces();
	////cout << '\n';

	//cb.submitMove("F1", "D3");
	//cb.submitMove("B4", "C3");
	//cout << '\n';

	//cb.submitMove("B2", "C3");
	//cb.submitMove("H7", "H6");
	//cout << '\n';

	//cb.submitMove("C1", "A3");
	//cb.submitMove("B8", "D7");
	//cout << '\n';

	//cb.submitMove("D1", "E2");
	//cb.submitMove("D5", "E4");
	//cout << '\n';

	//cb.submitMove("D3", "E4");
	//cb.submitMove("G8", "F6");
	//cout << '\n';

	//cb.submitMove("E4", "D3");
	//cb.submitMove("B7", "B6");
	//cout << '\n';

	//cb.submitMove("E2", "E6");
	//cb.submitMove("F7", "E6");
	//cout << '\n';

	//cb.submitMove("D3", "G6");
	//cout << '\n';

	return 0;


	//cb.submitMove("D7", "D6");
	//cout << cb.gm.isCheckMateOrStaleMate(BLACK) << std::endl;
	//cout << "Move 1: " << std::endl;
	//cout << cb.gm.isMoveValid("E1", "G1") << std::endl;
	//cout << "Move 2: " << std::endl;
	//cout << cb.gm.isMoveValid("E1", "C1") << std::endl;
	//cout << "Move 3: " << std::endl;
	//cout << cb.gm.isMoveValid("E8", "G8") << std::endl;
	//cout << "Move 4: " << std::endl;
	//cout << cb.gm.isMoveValid("E8", "C8") << std::endl;
	

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
