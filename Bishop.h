#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece {
	public:
		Bishop(char type, Position position);
		void getType() override;
};

#endif
