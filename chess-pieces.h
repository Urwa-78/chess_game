#pragma once

// File 1: ChessPiece.h
#ifndef CHESSPIECES_H
#define CHESSPIECES_H

#include <string>

using namespace std;

class ChessPiece {
protected:
    char color;
    string type;
    int x, y;

public:
    ChessPiece(char c, string t, int startX, int startY);
    virtual ~ChessPiece() {}

    char getColor() const;
    string getType() const;
    int getX() const;
    int getY() const;
    void setPosition(int newX, int newY);

    // Changed from = 0 to a default implementation
    virtual bool isValidMove(int newX, int newY, ChessPiece* board[8][8]) const;

    virtual bool canCapture(int newX, int newY, ChessPiece* board[8][8]) const;
};

class Knight : public ChessPiece {
public:
    Knight(char c, int startX, int startY);
    bool isValidMove(int newX, int newY, ChessPiece* board[8][8]) const override;
};

class Bishop : public ChessPiece {
public:
    Bishop(char c, int startX, int startY);
    bool isValidMove(int newX, int newY, ChessPiece* board[8][8]) const override;
};

class Queen : public ChessPiece {
public:
    Queen(char c, int startX, int startY);
    bool isValidMove(int newX, int newY, ChessPiece* board[8][8]) const override;
};

class King : public ChessPiece {
public:
    King(char c, int startX, int startY);
    bool isValidMove(int newX, int newY, ChessPiece* board[8][8]) const override;
};

#endif