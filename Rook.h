#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook : public Piece {
	public:
		Rook(char type);
		void getType() override;
		int getValidMovesSize() override;
		Move* getValidMoves() override;
};

#endif
