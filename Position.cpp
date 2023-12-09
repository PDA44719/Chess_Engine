#include<iostream>
#include "Position.h"
using namespace std;

Position::Position(const char* position){
	// If position is out of bounds
	if (position[0]<'A' || position[0] > 'H' || position[1] < '1' || position[1] > '8'){
		piece_file = 'X';
		piece_rank = 'X';
	} else { // Valid position
		piece_file = position[0];
		piece_rank = position[1];
	}
};

Position::Position(){
	piece_file = 'X';
	piece_rank = 'X';
};

bool Position::operator==(const Position& p2) const{
	return piece_file == p2.piece_file && piece_rank == p2.piece_rank;
}

bool Position::operator!=(const Position& p2) const{
	return piece_file != p2.piece_file || piece_rank != p2.piece_rank;
}

void Position::operator=(const Position& updated_position){
	piece_file = updated_position.piece_file;
	piece_rank = updated_position.piece_rank;
}

Move Position::operator-(const Position& p) const{
	return Move(piece_file - p.piece_file, piece_rank - p.piece_rank);
}

Position Position::operator-(const Move& m) const{
	char resulting_position[2];
	resulting_position[0] = piece_file - m.file_move;
	resulting_position[1] = piece_rank - m.rank_move;
	return Position(&resulting_position[0]);
}

Position Position::operator+(const Move& m) const{
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

void Position::move(char c){
	int step;
	if (c >= '1' && c<='8')
		step = c - '0';
	else
		step = 1;

	if ((piece_file + step) <= 'H')
		piece_file += step;
	else {
		piece_rank--;
		piece_file += step - 8;
	}

	// Invalidate the position if out of bounds
	if (piece_rank < '1') {
		piece_file = 'X';
		piece_rank = 'X';
	}
}

bool Position::isValid() {
	return piece_file != 'X' && piece_rank != 'X';
}