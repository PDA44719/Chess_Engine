#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen : public Piece {
	public:
		Queen(char type);
		void getType() override;
		int getValidMovesSize() override;
		Move* getValidMoves() override;
};

#endif
