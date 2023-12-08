#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook : public Piece {
	public:
		Rook(char type);
		void getType() override;
		char returnType() override;
		int getValidMovesSize() override;
		Move* getValidMoves() override;
		bool hasMoved();
		friend class GameManager;
	private:
	 	int valid_moves_size = 2; 
		Move valid_moves[2] = {Move(100,0), Move(0,100)};
		bool has_moved = true;
		void setHasNotMoved();
};

#endif
