#include<iostream>
#include "Position.h"
using namespace std;

Position::Position(char* position): piece_file(position[0]), piece_rank(position[1]){};

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

ostream& operator<<(ostream &o, const Position& p){
	o << p.piece_file << p.piece_rank;
	return o;
}

char Position::getFile(){
	return piece_file;
}

char Position::getRank(){
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
}
