#include<iostream>
#include<type_traits>
#include<typeinfo>
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

ChessBoard::ChessBoard(): gm(GameManager(this)){}

ChessBoard::~ChessBoard(){
	// Loop through all squares on the board
	for (Position p("A8"); p!=Position("XX"); p.move('1')){
		// If there is a piece at that square, set to null and delete the piece
		Piece* piece_at_position = (*this)[p];
		(*this)[p] = NULL;
		if (piece_at_position)
			delete piece_at_position;
	}
}

void ChessBoard::loadState(const char* FEN_string){
	this->~ChessBoard();
	Position pos("A8");
	while (*FEN_string != ' '){
		if (*FEN_string >= 'A' && *FEN_string <= 'z'){
			this->createPiece(*FEN_string, pos); // Create the new piece
		}
		if (*FEN_string != '/')
			pos.move(*FEN_string);
		FEN_string++;
	}
	FEN_string++; // Get to the turn information
	gm.setTurn(*FEN_string); // Send the turn information to the game manager
	
	// Advance FEN_char to castling info and set that info
	FEN_string = FEN_string+2;  
	gm.setCastlingInformation(FEN_string);
	cout << "A new board state is loaded!" << endl;
}

void ChessBoard::displayPieces(){
	cout << "  A B C D E F G H\n";
	// Loop until invalid position reached
	for (Position p("A8"); p!=Position("XX"); p.move('1')){
		if (p.getFile() == 'A')
			cout << p.getRank() << " ";
		if ((*this)[p] != NULL){
			(*this)[p]->getSymbol();
			cout << " ";
		} else{
			cout << "- ";
		}
		if (p.getFile() == 'H')
			cout << "\n";

	}
}

Piece*& ChessBoard::operator[](Position p){
	return board[p.getRank() - '1'][p.getFile() - 'A'];
}

void ChessBoard::createPiece(char type, Position p){
	switch(type){
		case 'r':
		case 'R':
			(*this)[p] = new Rook(type);
			break;
		case 'k':
			black_king_pos = p;
			(*this)[p] = new King(type);
			break;
		case 'K':
		 	white_king_pos = p;
			(*this)[p] = new King(type);
			break;
		case 'q':
		case 'Q':
			(*this)[p] = new Queen(type);
			break;
		case 'b':
		case 'B':
			(*this)[p] = new Bishop(type);
			break;
		case 'p':
		case 'P':
			(*this)[p] = new Pawn(type);
			break;
		case 'n':
		case 'N':
			(*this)[p] = new Knight(type);
			break;

		//  MAYBE ADD A DEFAULT CASE
			
	}
}

void ChessBoard::submitMove(const char initial_position[2], const char final_position[2]){
	//gm.checkCounter(Position("G8"), BLACK); // These values must be changed
	Position p(initial_position);
	Position final_p(final_position);
	//Move m = final_p - p; 

	if (!(*this)[p]){
		cout << "There is no piece at position " << p << "!" << endl;
		return;
	}
	
	if (!gm.checkTurn((*this)[p])){
		cout << "It is not " << (*this)[p]->getColour() << "'s turn to move!\n";
		return;
	}

	if (!gm.isMoveValid(p, final_p, true)){
		cout << (*this)[p]->getType() << " cannot move to " << final_p << "!\n";
		return;
	}


	Piece* piece_taken = gm.makeMove(p, final_p);
	cout << (*this)[final_p]->getType() << " moves from " << p << " to " << final_p;
	if (piece_taken){
		cout << " taking " << piece_taken->getType();
		delete piece_taken;
	}
	cout << endl;
	gm.updateTurn();
	bool end_of_game = gm.isCheckMateOrStaleMate(gm.getTurn());
	if (!end_of_game && gm.checkCounter(gm.getTurn()) != 0){
		cout << gm.getTurn() << " is in check" << endl;
	}
}

Position ChessBoard::getKingPosition(Color king_color) {
	return king_color == BLACK ? black_king_pos : white_king_pos;
}

// I NEED TO IMPLEMENT A DESTRUCTOR AS I AM CREATING PIECES IN THE HEAP
