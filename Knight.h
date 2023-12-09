#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight : public Piece {
	public:
		Knight(char type);
		void getType() override;
		const char* returnType() override;
		int getValidMovesSize();
		Move* getValidMoves();
	private:
	 	int valid_moves_size = 8;
		Move valid_moves[8] = {Move(1,2), Move(1,-2), Move(-1,2), Move(-1, -2), Move(2,1), Move(2,-1), Move(-2,1), Move(-2, -1)};
};

#endif
