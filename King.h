#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece {
	public:
		King(char type);
		void getType() override;
		char returnType() override;
		int getValidMovesSize() override;
		Move* getValidMoves() override;
		bool hasMoved();
	private:
		int valid_moves_size = 10;
		Move valid_moves[10] = {Move(0,1), Move(0,-1), Move(1,0), Move(-1,0), Move(1,1), Move(-1,-1), Move(1,-1), Move(-1,1), Move(2,0), Move(-2,0)};
		bool has_moved = false;
};

#endif
