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
	int piece_counter = 0;
	char initial_position[] = "A8";
	while (*ptr != ' '){
		if (*ptr >= 'A' && *ptr <= 'z'){
			// Define a new position char array
			char *piece_position = new char[2];
			piece_position[0] = initial_position[0];
			piece_position[1] = initial_position[1];

			// Create the new piece
			pieces[piece_counter] = new Piece(*ptr, piece_position);

			// Increase the piece counter and go to the next position in the board
			piece_counter++;
			initial_position[0] += 1;

		} else if (*ptr >= '1' && *ptr <= '8') { // Go to the next non-empty cell
			initial_position[0] += *ptr - '1';

		} else { // If there is a '/', the go to the next rank
			initial_position[0] = 'A';
			initial_position[1] -= 1;
		}
		ptr++;
	}
}

// I NEED TO IMPLEMENT A DESTRUCTOR AS I AM CREATING PIECES IN THE HEAP
