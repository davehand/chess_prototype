//  Name: David Hand
//  Course: CSC260, Section 1
//  Semester: Fall 2012
//  Instructor: Dr. Pulimood
//  Assignment: Final Project
//  Description: Header file for piece (base class)
//  Filename: Piece.cpp
//  Last modified on: 12/14/12

#include "Piece.h"

//constructor for Piece
Piece::Piece (int inRow, int inCol, Color inColor)
{
    row = inRow;
    col = inCol;
    player = inColor;
    ID = 0;
}

//destructor for piece, virtual
Piece::~Piece()
{
}

//accessor for ID
int Piece::getID()
{
    return ID;
}

//accessor for Color, returned as int
int Piece::getColor()
{
    if (player == GREEN)
        return 0;
    else
        return 1;
}

//returns false for piece
bool Piece::isRealPiece() const
{
    return false;
}

//converts Piece to string, virtual
string Piece::object2string() const
{
    return string ("  ");
}

//virtual function to be overwritten
bool Piece::move(int e_row, int e_col)
{
    return false;
}

//sets new row and column for piece
void Piece::set_new_pos(int n_row, int n_col)
{
    row = n_row;
    col = n_col;
}
