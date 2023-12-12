#include<iostream>
#include "Position.h"
using namespace std;

Position::Position(const char* position){
	// If given position is out of bounds
	if (position[0]<'A' || position[0] > 'H' || position[1] < '1' || position[1] > '8'){
		piece_file = 'X';
		piece_rank = 'X';
	} else { // Given position is valid
		piece_file = position[0];
		piece_rank = position[1];
	}
};

Position::Position(){
	// Default constructor will initialize the position to be invalid
	piece_file = 'X';
	piece_rank = 'X';
};

bool Position::operator==(const Position& p2) const{
	// Check that the rank and file for both positions is the same
	return piece_file == p2.piece_file && piece_rank == p2.piece_rank;
}

bool Position::operator!=(const Position& p2) const{
	// Check that either the rank or the file is different
	return piece_file != p2.piece_file || piece_rank != p2.piece_rank;
}

void Position::operator=(const Position& another){
	piece_file = another.piece_file;
	piece_rank = another.piece_rank;
}

Move Position::operator-(const Position& p) const{
	return Move(piece_file - p.piece_file, piece_rank - p.piece_rank);
}

Position Position::operator+(const Move& m) const{
	// Add the file and rank values separately
	char resulting_position[2];
	resulting_position[0] = piece_file + m.file_move;
	resulting_position[1] = piece_rank + m.rank_move;
	return Position(&resulting_position[0]);
}

ostream& operator<<(ostream &o, const Position& p){
	o << p.piece_file << p.piece_rank;
	return o;
}

char Position::getFile(){
	return piece_file;
}

char Position::getRank() const{
	return piece_rank;
}

void Position::move(char amount_to_move){
	// Convert amount to move char into int
	int step;
	if (amount_to_move >= '1' && amount_to_move<='8')
		step = amount_to_move - '0';
	else // Assume the step will be 1 if provided char is out of range
		step = 1;
	
	if ((piece_file + step) <= 'H') // If the move can be contained within one rank
		piece_file += step;
	else { // Moving down one rank required (assumed we move from high to low ranks)
		piece_rank--;
		piece_file += step - 8;
	}

	// Invalidate the position if move leads to out-of-bounds position
	if (piece_rank < '1') {
		piece_file = 'X';
		piece_rank = 'X';
	}
}

bool Position::isValid() {
	return piece_file != 'X' && piece_rank != 'X';
}