#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook : public Piece {
	public:
		Rook(char type);
		void getType() override;
		const char* returnType() override;
		int getPotentialMovesSize() override;
		Move* getPotentialMoves() override;
		friend class GameManager;
	private:
	 	int potential_moves_size = 2; 
		Move potential_moves[2] = {Move(100,0), Move(0,100)};
};

#endif
