#ifndef PIECE_H
#define PIECE_H
#include<iostream>
#include<string>
using namespace std;
class piece {
private:
	char color;
	int row;
	int cols;
	bool capture; 
public:
	//constructors
	piece(char color, int row, int cols);
	//destructor
	virtual ~piece() {};
	//return functions
	virtual  bool isvalidmove(int torow, int tocol, piece* board[8][8])const=0;
	virtual char getsymbol()const = 0;
	virtual string getname()const = 0;
	//getters
	char getcolor() const { return color; }
	char getrow()const;
	char getcols()const;
	bool captured()const;
	//seters
	void setposition(int rows, int cols);
	void setcaptured(bool val);  
	bool friendly(int rows, int cols, piece* board[8][8])const; // check is the path occupied
	bool isclear(int rows, int cols, piece* board[8][8])const; // check is the path clear


};
#endif
