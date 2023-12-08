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

void ChessBoard::loadState(const char* FEN_string){
	this->getInitialBoard(FEN_string);
}

void ChessBoard::displayPieces(){
	cout << "  A B C D E F G H\n";
	// Loop until invalid position reached
	for (Position p("A8"); p!=Position("XX"); p.move('1')){
		if (p.getFile() == 'A')
			cout << p.getRank() << " ";
		if (board[p.getRank() - '1'][p.getFile() - 'A'] != NULL){
			board[p.getRank() - '1'][p.getFile() - 'A']->getType();
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
			cout << "Black king pos is: " << p << endl;
			black_king_pos = p;
			(*this)[p] = new King(type);
			break;
		case 'K':
			cout << "White king pos is: " << p << endl;
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
	gm.checkCounter(Position("G8"), BLACK); // These values must be changed
	Position p(initial_position);
	Position final_p(final_position);
	Move m = final_p - p; 
	if (!(*this)[p] || !gm.checkTurn((*this)[p]) || !gm.isMoveValid(p, final_p)) // Have to check the turn here
		return;

	if (!gm.pieceInThePath(p, final_p, m.getDirection())) {
		(*this)[final_p] = (*this)[p];
		(*this)[p] = NULL;
		gm.updateTurn();
	} 	
}

void ChessBoard::getInitialBoard(const char* FEN_char){
	// TODO: MUST ENSURE HAS MOVED IS PROPERLY INITIALIZED IN CHESSBOARD
	Position pos("A8");
	while (*FEN_char != ' '){
		if (*FEN_char >= 'A' && *FEN_char <= 'z'){
			this->createPiece(*FEN_char, pos); // Create the new piece
		}
		if (*FEN_char != '/')
			pos.move(*FEN_char);
		FEN_char++;
	}
	FEN_char++; // Get to the turn information
	gm.setTurn(*FEN_char); // Send the turn information to the game manager
}

Position ChessBoard::getKingPosition(Color king_color) {
	return king_color == BLACK ? black_king_pos : white_king_pos;
}

// I NEED TO IMPLEMENT A DESTRUCTOR AS I AM CREATING PIECES IN THE HEAP
