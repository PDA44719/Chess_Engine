#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight : public Piece {
	public:
		Knight(char type, Position position);
		void getType() override;
};

#endif
