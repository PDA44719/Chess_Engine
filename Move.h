#ifndef MOVE_H
#define MOVE_H
#include<iostream>
			
class Move {

        public:
            Move(int f_move, int r_move);
			friend std::ostream& operator << (std::ostream&, const Move&);
            bool operator==(const Move&) const;
		private:
			int file_move; 
			int rank_move; 

};

#endif
