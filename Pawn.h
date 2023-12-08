#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"
#include "ChessBoard.h"
//class ChessBoard;

class Pawn : public Piece {
	public:
		Pawn(char type);
		void getType() override;
		char returnType() override;
		int getValidMovesSize() override;
		Move* getValidMoves() override;
		bool additionalConditionsMet(ChessBoard*, Position, Move) override;

	private:
	 	int valid_moves_size = 4;
		Move valid_moves[4] = {Move(0, 1), Move(0, 2), Move(1, 1), Move(-1, 1)};
};

#endif
