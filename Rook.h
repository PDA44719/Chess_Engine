#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook : public Piece {
	public:
		Rook(char type);
		void getType() override;
		const char* returnType() override;
		int getValidMovesSize() override;
		Move* getValidMoves() override;
		friend class GameManager;
	private:
	 	int valid_moves_size = 2; 
		Move valid_moves[2] = {Move(100,0), Move(0,100)};
};

#endif
