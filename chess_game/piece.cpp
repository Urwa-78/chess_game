#include"piece.h"
//destructor
piece::piece(char color, int row, int cols) :color(color), row(row), cols(cols);
//return functions
virtual bool isvalidmove(int torow, int tocol, piece* board[8][8])const {

}

//getters
char piece::getcolor() const {
	return color;
}
char piece::getrow()const { return row; }
char piece:: getcols()const { return cols; }
bool  piece::captured()const { return captured; }
//seters
void piece:: setposition(int r, int c) {
	row = r;
cols = c;
}
void piece::setcaptured(bool val) {
    capture= val;
}
bool piece::friendly(int r, int c, piece* board[8][8]) const {
    if (board[r][c] == nullptr) return false;
    return board[r][c]->getcolor() == color;
}
bool piece::isclear(int torow, int tocol, piece* board[8][8])const {
	int dr = 0, dc = 0;
	if (torow > row)dr = 1;
	else if (torow < row)dr = -1;
	if (tocol > cols)dc = 1;
	else if (tocol < cols)dc = -1;
	int r = row + dr;
	int c = cols + dc;
	while (r != torow || c != tocol) {
		if (board[r][c] != nullptr)return false;
		r += dr;
		c += dc;

	}
	return true;
}