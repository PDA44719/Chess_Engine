#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen : public Piece {
	public:
		Queen(char type);
		void getType() override;
		const char* returnType() override;
		int getPotentialMovesSize() override;
		Move* getPotentialMoves() override;
	private:
		int potential_moves_size = 3;
		Move potential_moves[3] = {Move(0,100), Move(100,0), Move(100,100)};
};

#endif
