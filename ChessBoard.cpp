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

ChessBoard::~ChessBoard(){
	// Loop through all squares on the board
	for (Position p("A8"); p!=Position("XX"); p.move('1')){
		// Set the pointer at that position to NULL
		Piece* piece_at_position = (*this)[p];
		(*this)[p] = NULL;

		if (piece_at_position) // Destroy the piece if there was one
			delete piece_at_position;
	}
}

void ChessBoard::loadState(const char* FEN_string){
	this->~ChessBoard(); // Reset the board state
	Position pos("A8"); // Initial position
	while (*FEN_string != ' '){
		// If there is a piece character, create the piece at pos
		if (*FEN_string >= 'A' && *FEN_string <= 'z'){ 
			this->createPiece(*FEN_string, pos); 
		}

		// Move the position to the next square where a piece is present
		if (*FEN_string != '/')
			pos.move(*FEN_string);

		FEN_string++; // Move the pointer to the next char in the array
	}

	// After all the pieces have been created, set the information about the turn
	FEN_string++; 
	gm.setTurn(*FEN_string); 
	
	// Advance FEN_char to castling information and set that information
	FEN_string = FEN_string+2;  
	gm.setCastlingInformation(FEN_string);
	cout << "A new board state is loaded!" << endl;
}

void ChessBoard::displayPieces(){
	cout << "  A B C D E F G H\n";
	// Loop until all valid positions have been displayed 
	for (Position p("A8"); p!=Position("XX"); p.move('1')){
		if (p.getFile() == 'A') // Print the rank (row) number
			cout << p.getRank() << " ";

		if ((*this)[p] != NULL){ // If there is a piece
			(*this)[p]->getSymbol();
			cout << " ";
		} else{ // If there is no piece at that position
			cout << "- ";
		}

		// Print new line if all files for the current rank have been displayed
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
	}
}

void ChessBoard::submitMove(const char initial_position[2], const char final_position[2]){
	Position p(initial_position);
	Position final_p(final_position);

	if (p == Position("XX") || final_p == Position("XX")) { // Invalid position
		cout << "Invalid position was given!" << endl;
		return;
	}
	if (!(*this)[p]){ // Pointer is NULL
		cout << "There is no piece at position " << p << "!" << endl;
		return;
	}
	if (!gm.checkTurn((*this)[p])){ // Not the player's turn
		cout << "It is not " << (*this)[p]->getColour() << "'s turn to move!\n";
		return;
	}
	if (!gm.isMoveValid(p, final_p, true)){ // Invalid move
		cout << (*this)[p]->getType() << " cannot move to " << final_p << "!\n";
		return;
	}

	// If the move was valid, make it
	Piece* piece_taken = gm.makeMove(p, final_p);
	cout << (*this)[final_p]->getType() << " moves from " << p << " to " << final_p;

	if (piece_taken){ // If a piece was taken, print to the terminal and delete it
		cout << " taking " << piece_taken->getType();
		delete piece_taken;
	}
	cout << endl;

	// Update the turn and check if the move led to the game end or to check
	gm.updateTurn();
	bool end_of_game = gm.isCheckMateOrStaleMate(gm.getTurn());
	if (!end_of_game && gm.checkCounter(gm.getTurn()) != 0){
		cout << gm.getTurn() << " is in check" << endl;
	}
}

Position ChessBoard::getKingPosition(Color king_color) {
	return king_color == BLACK ? black_king_pos : white_king_pos;
}
