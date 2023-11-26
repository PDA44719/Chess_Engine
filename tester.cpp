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
	cb.submitMove("C3", "E5");
	cout << "\nAFTER THE CHANGE" << std::endl;
	cout << '\n';
	cb.displayPieces();
}
