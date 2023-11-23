#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece {
	public:
		Bishop(char type, char position[2]);
		void getType() override;
};

#endif
