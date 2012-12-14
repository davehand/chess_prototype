//  Name: David Hand
//  Course: CSC260, Section 1
//  Semester: Fall 2012
//  Instructor: Dr. Pulimood
//  Assignment: Final Project
//  Description: Implementation for President class
//  Filename: President.cpp
//  Last modified on: 12/14/12

#include "President.h"

//constructor for President
President::President(int inRow, int inCol, Color inColor):Piece(inRow, inCol, inColor)
{
    ID = PRESIDENT;
}

//destructor for President
President::~President()
{
}

//returns true for President
bool President::isRealPiece() const
{
    return true;
}

//converts Preisdent to string
string President::object2string() const
{
    string result = "";
    if (player == GREEN)
		result = "g";
    else if (player == YELLOW)
		result = "y";
    
    result = result + "P";
    
    return result;
}

//checks if move is valid for President
bool President::move(int e_row, int e_col)
{
    if ((e_row == row-1 || e_row == row || e_row == row+1) && (e_col == col-1 || e_col == col || e_col == col+1))
        return true;
    else
        return false;
}
