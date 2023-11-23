#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece {
	public:
		King(char type, char position[2]);
		void getType() override;
};

#endif
