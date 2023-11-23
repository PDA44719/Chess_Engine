#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight : public Piece {
	public:
		Knight(char type, char position[2]);
		void getType() override;
};

#endif
