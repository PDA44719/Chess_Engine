#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight : public Piece {
	public:
		Knight(char type);
		void getSymbol() override;
		const char* getType() override;
		int getPotentialMovesSize();
		Move* getPotentialMoves();
	private:
	 	int potential_moves_size = 8;
		Move potential_moves[8] = {Move(1,2), Move(1,-2), Move(-1,2), Move(-1, -2), Move(2,1), Move(2,-1), Move(-2,1), Move(-2, -1)};
};

#endif
