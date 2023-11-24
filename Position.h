#ifndef POSITION_H
#define POSITION_H
#include<iostream>

			
class Position {

        public:
			Position(char*);
			bool operator==(const Position&) const;
			bool operator!=(const Position&) const;
			void operator=(const Position&);
			friend std::ostream& operator << (std::ostream&, const Position&);
			void move(char);
			char getFile();
			char getRank();
		private:
			char piece_file; 
			char piece_rank; 

};

#endif
