#include<iostream>
#include "ChessBoard.h"
#include "Piece.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Rook.h"
#include "Pawn.h"
#include "Knight.h"
#include "Position.h"
using namespace std;

void ChessBoard::loadState(const char* string){
	FEN_string = string;
	this->getInitialPieces();
}

void ChessBoard::displayPieces(){
	cout << "  A B C D E F G H\n";
	for (Position p("A8"); p!=Position("A0"); p.move('1')){
		if (p.getFile() == 'A')
			cout << p.getRank() << " ";
		bool piece_found = false;
		for (int i=0; i<32; i++){
			if (pieces[i]->getPosition() == p){
				pieces[i]->getType();
				cout << " ";
				piece_found = true;
			}
		}
		if (!piece_found)
			cout << "- ";
		if (p.getFile() == 'H')
			cout << "\n";

	}
}


void ChessBoard::createPiece(int piece_index, char type, Position position){
	switch(type){
		case 'r':
		case 'R':
			pieces[piece_index] = new Rook(type, position);
			break;
		case 'k':
		case 'K':
			pieces[piece_index] = new King(type, position);
			break;
		case 'q':
		case 'Q':
			pieces[piece_index] = new Queen(type, position);
			break;
		case 'b':
		case 'B':
			pieces[piece_index] = new Bishop(type, position);
			break;
		case 'p':
		case 'P':
			pieces[piece_index] = new Pawn(type, position);
			break;
		case 'n':
		case 'N':
			pieces[piece_index] = new Knight(type, position);
			break;
			
	}
}

void ChessBoard::submitMove(char initial_position[2], char final_position[2]){
	for (int i=0; i<32; i++){
		//cout << pieces[i]->getPosition();
		//cout << " and " << initial_position << " is being looked for" << endl;
		if (pieces[i]!=NULL && pieces[i]->getPosition() == Position(initial_position)){
			pieces[i]->updatePosition(Position(final_position));
			//pieces[i]->getType();
			return;
		}
	}
	cout << "No pieces were found in that position" << endl;
}

void ChessBoard::getInitialPieces(){
	const char *ptr = FEN_string;
	int piece_counter = 0;
	Position pos("A8");
	while (*ptr != ' '){
		if (*ptr >= 'A' && *ptr <= 'z'){
			// Create the new piece
			//pieces[piece_counter] = new King(*ptr, piece_position);
			this->createPiece(piece_counter, *ptr, pos);

			// Increase the piece counter and go to the next position in the board
			piece_counter++;
		}
		if (*ptr != '/')
			pos.move(*ptr);
		ptr++;
	}
}

// I NEED TO IMPLEMENT A DESTRUCTOR AS I AM CREATING PIECES IN THE HEAP
