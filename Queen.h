#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen : public Piece {
	public:
		Queen(char type, Position position);
		void getType() override;
};

#endif
