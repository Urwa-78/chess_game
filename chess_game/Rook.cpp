#include"Rook.h"
Rook::Rook(char color, int row, int col) : piece(color, row, col){}
char Rook::getsymbol()const { return (getcolor() == 'W' ? 'R' : 'r'; }
string Rook::getname()const {
	return "Rook";
}
//rook moves in straight line only row or column
bool Rook::isvalidmove(int torow, int tocol, piece* board[8][8])const {
	if (friendly(torow, tocol, board))return false;
	bool straightline = ((torow == getrow()) || tocol == getcols());
	if (!straightline)return false;
	return isclear(torow, tocol, board);
}