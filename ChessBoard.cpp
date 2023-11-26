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
	for (Position p("A8"); p!=Position("A0"); p.move('1')){
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
		case 'K':
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
	Position p(initial_position);
	Position final_p(final_position);
	Move m = final_p - p;
	if ((*this)[p]){
		if(gm.checkTurn((*this)[p])){
			// This would be the checkValidMove method
			Move* valid_move = (*this)[p]->getValidMoves();
			// Print the valid moves
			cout << endl << endl;
			cout << (*this)[p]->getValidMovesSize() << endl;
			for (int j=0; j<(*this)[p]->getValidMovesSize(); j++)
				cout << valid_move[j] << "   ";

			bool is_valid = false;
			for (int i=0; i<(*this)[p]->getValidMovesSize(); i++){
				if (m == *valid_move)
					is_valid = true;
				valid_move++; // Go to the next valid move
			}
			if (is_valid) {
				board[final_p.getRank() - '1'][final_p.getFile() - 'A'] = board[p.getRank() - '1'][p.getFile() - 'A'];
				board[p.getRank() - '1'][p.getFile() - 'A'] = NULL;
				gm.updateTurn();
			} else {
				cout << "\nThe move was invalid" << endl;
			}
		}
		return;
	}
	cout << "No pieces were found in that position" << endl;
}

void ChessBoard::getInitialBoard(const char* FEN_char){
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

// I NEED TO IMPLEMENT A DESTRUCTOR AS I AM CREATING PIECES IN THE HEAP
