#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn : public Piece {
	public:
		Pawn(char type);
		void getType() override;
		int getValidMovesSize() override;
		Move* getValidMoves() override;
};

#endif
