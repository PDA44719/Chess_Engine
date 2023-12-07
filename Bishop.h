#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece {
	public:
		Bishop(char type);
		void getType() override;
		char returnType() override;
		int getValidMovesSize() override;
		Move* getValidMoves() override;
	private:
	 	int valid_moves_size = 1;
		Move valid_moves[1] = {Move(100,100)};
};

#endif
