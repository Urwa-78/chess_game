#include "Pawn.h"
#include<cstdlib>
Pawn::Pawn(char color, int row, int col) : piece(color, row, col) {}

char Pawn::getsymbol() const {
    return (getcolor() == 'W') ? 'P' : 'p';
}

string Pawn::getname() const {
    return "Pawn";
}

bool Pawn::isvalidmove(int torow, int tocol, piece* board[8][8]) const {
    int r = getrow();
    int c = getcols();
    int direction = (getcolor() == 'W') ? -1 : 1;
    int startRow = (getcolor() == 'W') ? 6 : 1;
    int dr = torow - r;
    int dc = tocol - c;
    if (friendly(torow, tocol, board)) return false;
    // single step forward
    if (dc == 0 && dr == direction) {
        return board[torow][tocol] == nullptr;
    }
    // double step move forward from start
    if (dc == 0 && dr == 2 * direction && r == startRow) {
        int midrow = r + direction;
        return board[midrow][tocol] == nullptr && board[torow][tocol] == nullptr;
    }
    // capture
    if (abs(dc) == 1 && dr == direction) {
        return board[torow][tocol] != nullptr &&
            board[torow][tocol]->getcolor() != getcolor();
    }
    return false;
}