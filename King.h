#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece {
	public:
		King(char type, Position position);
		void getType() override;
};

#endif
