#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece {
	public:
		Bishop(char type);
		void getSymbol() override;
		const char* getType() override;
		int getPotentialMovesSize() override;
		Move* getPotentialMoves() override;
	private:
	 	int potential_moves_size = 1;
		Move potential_moves[1] = {Move(100,100)};
};

#endif
