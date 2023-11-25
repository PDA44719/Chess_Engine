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


void ChessBoard::createPiece(char type, Position p){
	switch(type){
		case 'r':
		case 'R':
			board[p.getRank() - '1'][p.getFile() - 'A'] = new Rook(type);
			break;
		case 'k':
		case 'K':
			board[p.getRank() - '1'][p.getFile() - 'A'] = new King(type);
			break;
		case 'q':
		case 'Q':
			board[p.getRank() - '1'][p.getFile() - 'A'] = new Queen(type);
			break;
		case 'b':
		case 'B':
			board[p.getRank() - '1'][p.getFile() - 'A'] = new Bishop(type);
			break;
		case 'p':
		case 'P':
			board[p.getRank() - '1'][p.getFile() - 'A'] = new Pawn(type);
			break;
		case 'n':
		case 'N':
			board[p.getRank() - '1'][p.getFile() - 'A'] = new Knight(type);
			break;
			
	}
}

void ChessBoard::submitMove(char initial_position[2], char final_position[2]){
	Position p(initial_position);
	Position final_p(final_position);
	if (board[p.getRank() - '1'][p.getFile() - 'A'] != NULL){
		if(gm.checkTurn(board[p.getRank() - '1'][p.getFile() - 'A'])){
			board[final_p.getRank() - '1'][final_p.getFile() - 'A'] = board[p.getRank() - '1'][p.getFile() - 'A'];
			board[p.getRank() - '1'][p.getFile() - 'A'] = NULL;
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
