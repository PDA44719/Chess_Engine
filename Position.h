#ifndef POSITION_H
#define POSITION_H
#include<iostream>
#include "Move.h"
			
class Position {

        public:
			Position(const char*);
			Position();
			bool operator==(const Position&) const;
			bool operator!=(const Position&) const;
			void operator=(const Position&);
			Move operator-(const Position&) const;
			Position operator-(const Move&) const;
			Position operator+(const Move&) const;
			friend std::ostream& operator << (std::ostream&, const Position&);
			void move(char);
			char getFile();
			char getRank() const;
			bool isValid();
		private:
			char piece_file; 
			char piece_rank; 

};

#endif
