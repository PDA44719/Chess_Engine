#ifndef POSITION_H
#define POSITION_H
#include<iostream>
#include "Move.h"
			
class Position {

        public:
			Position(const char*);
			bool operator==(const Position&) const;
			bool operator!=(const Position&) const;
			void operator=(const Position&);
			Move operator-(const Position&) const;
			Position operator+(const Move&);
			friend std::ostream& operator << (std::ostream&, const Position&);
			void move(char);
			char getFile();
			char getRank();
			bool isValid();
		private:
			char piece_file; 
			char piece_rank; 

};

#endif
