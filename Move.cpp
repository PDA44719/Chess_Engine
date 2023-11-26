#include "Move.h"
#include<iostream>
using namespace std;

Move::Move(int f_move, int r_move) : file_move(f_move), rank_move(r_move){}

ostream& operator << (ostream& o, const Move& m){
    o << m.file_move << "|" << m.rank_move;
    return o;
}

bool Move::operator==(const Move& m) const {
    return file_move == m.file_move && rank_move == m.rank_move;
}