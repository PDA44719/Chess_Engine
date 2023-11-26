#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn : public Piece {
	public:
		Pawn(char type);
		void getType() override;
		int getValidMovesSize() override;
		Move* getValidMoves() override;

	private:
	 	int valid_moves_size = 4;
		Move valid_moves[4] = {Move(0, 1), Move(0, 2), Move(1, 1), Move(-1, 1)};
};

#endif
