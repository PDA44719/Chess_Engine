#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen : public Piece {
	public:
		Queen(char type, char position[2]);
		void getType() override;
};

#endif
