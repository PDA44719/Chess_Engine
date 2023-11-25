#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight : public Piece {
	public:
		Knight(char type);
		void getType() override;
};

#endif
