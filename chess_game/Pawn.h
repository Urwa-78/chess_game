#ifndef PAWN_H
#define PAWN_H
#include "Piece.h"
class Pawn :public piece {
public:
	Pawn(char color, int row, int col);
	bool isvalidmove(int torow, int tocol, piece* board[8][8])const;
	char getsymbol()const;
	string  getname()const;

};
#endif