#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn : public Piece {
	public:
		Pawn(char type, char position[2]);
		void getType() override;
};

#endif
