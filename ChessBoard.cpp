#include<iostream>
#include "ChessBoard.h"
#include "Piece.h"
using namespace std;

void ChessBoard::loadState(const char* string){
	FEN_string = string;
	this->getInitialPieces();
}

void ChessBoard::displayPieces(){
	for (int i=0; i<32; i++){
		//cout << "I am doing something at position " << i << endl;
		pieces[i]->getType();
		//cout << i << endl;
	}
}

void ChessBoard::getInitialPieces(){
	const char *ptr = FEN_string;
	//Piece *first_piece = pieces[0];
	int piece_counter = 0;
	while (*ptr != ' '){
		if (*ptr >= 'A' && *ptr <= 'z'){
			//Piece new_piece = new Piece(*ptr);
			cout << "Creating a new piece with type: " << *ptr << endl;
			pieces[piece_counter] = new Piece(*ptr);
			//first_piece++;
			piece_counter++;
		}
		ptr++;
	}
}

// I NEED TO IMPLEMENT A DESTRUCTOR AS I AM CREATING PIECES IN THE HEAP
