#include"ChessBoard.h"

#include<iostream>

using std::cout;

int main() {

	cout << "========================\n";
	cout << "Testing the Chess Engine\n";
	cout << "========================\n\n";

	ChessBoard cb;
	cb.loadState("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq");
	//cb.loadState("rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq");
	//cb.loadState("rnbqkbnr/pp1ppppp/8/2p5/4P3/5N2/PPPP1PPP/RNBQKB1R b KQkq");
	cb.displayPieces();

	//cb.submitMove("D7", "D6");
	//cb.submitMove("D7", "D6");
	
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

	//cb.submitMove("A6", "F6"); 
	//cout << "\nAFTER THE CHANGE" << std::endl;
	//cout << '\n';
	//cb.displayPieces();
	//cb.submitMove("E5", "F6"); 
	//cout << "\nAFTER THE CHANGE" << std::endl;
	//cout << '\n';
	//cb.displayPieces();

}
