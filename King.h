#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece {
	public:
		King(char type);
		void getType() override;
		int getValidMovesSize() override;
		Move* getValidMoves() override;
};

#endif
