#ifndef ROOK_H
#define ROOK_H
#include "piece.h"
class Rook :public  piece {
public:
	Rook(char color, int row, int col);
	  bool isvalidmove(int torow, int tocol, piece* board[8][8])const;
	  char getsymbol()const;
	  string getname()const;
};
#endif