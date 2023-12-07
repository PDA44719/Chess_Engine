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
	private:
		int valid_moves_size = 8;
		Move valid_moves[8] = {Move(0,1), Move(0,-1), Move(1,0), Move(-1,0), Move(1,1), Move(-1,-1), Move(1,-1), Move(-1,1)};
};

#endif
