#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook : public Piece {
	public:
		Rook(char type, char position[2]);
		void getType() override;
};

#endif
