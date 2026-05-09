
#include "chess-pieces.h"
#include <cstdlib> // for abs

ChessPiece::ChessPiece(char c, string t, int startX, int startY)
    : color(c), type(t), x(startX), y(startY) {
}

char ChessPiece::getColor() const { return color; }
string ChessPiece::getType() const { return type; }
int ChessPiece::getX() const { return x; }
int ChessPiece::getY() const { return y; }

void ChessPiece::setPosition(int newX, int newY) {
    x = newX;
    y = newY;
}

bool ChessPiece::canCapture(int newX, int newY, ChessPiece* board[8][8]) const {
    if (newX < 0 || newX > 7 || newY < 0 || newY > 7) return false;
    ChessPiece* target = board[newX][newY];
    return target == nullptr || target->getColor() != color;
}

// Knight
Knight::Knight(char c, int startX, int startY)
    : ChessPiece(c, "Knight", startX, startY) {
}

bool Knight::isValidMove(int newX, int newY, ChessPiece* board[8][8]) const {
    if (!canCapture(newX, newY, board)) return false;
    int dx = abs(newX - x);
    int dy = abs(newY - y);
    return (dx == 1 && dy == 2) || (dx == 2 && dy == 1);
}

// Bishop
Bishop::Bishop(char c, int startX, int startY)
    : ChessPiece(c, "Bishop", startX, startY) {
}

bool Bishop::isValidMove(int newX, int newY, ChessPiece* board[8][8]) const {
    if (!canCapture(newX, newY, board)) return false;
    int dx = abs(newX - x);
    int dy = abs(newY - y);
    if (dx != dy || dx == 0) return false;

    // Check path clear
    int stepX = (newX > x) ? 1 : -1;
    int stepY = (newY > y) ? 1 : -1;
    int currX = x + stepX;
    int currY = y + stepY;
    while (currX != newX && currY != newY) {
        if (board[currX][currY] != nullptr) return false;
        currX += stepX;
        currY += stepY;
    }
    return true;
}

// Queen
Queen::Queen(char c, int startX, int startY)
    : ChessPiece(c, "Queen", startX, startY) {
}

bool Queen::isValidMove(int newX, int newY, ChessPiece* board[8][8]) const {
    if (!canCapture(newX, newY, board)) return false;

    int dx = abs(newX - x);
    int dy = abs(newY - y);

    // Rook-like or Bishop-like
    if (x == newX || y == newY || dx == dy) {
        // Check path clear
        int stepX = (newX > x) ? 1 : (newX < x ? -1 : 0);
        int stepY = (newY > y) ? 1 : (newY < y ? -1 : 0);

        int currX = x + stepX;
        int currY = y + stepY;
        while (currX != newX || currY != newY) {
            if (board[currX][currY] != nullptr) return false;
            currX += stepX;
            currY += stepY;
        }
        return true;
    }
    return false;
}

// King
King::King(char c, int startX, int startY)
    : ChessPiece(c, "King", startX, startY) {
}

bool King::isValidMove(int newX, int newY, ChessPiece* board[8][8]) const {
    if (!canCapture(newX, newY, board)) return false;
    int dx = abs(newX - x);
    int dy = abs(newY - y);
    return dx <= 1 && dy <= 1 && (dx + dy > 0);
}