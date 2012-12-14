//  Name: David Hand
//  Course: CSC260, Section 1
//  Semester: Fall 2012
//  Instructor: Dr. Pulimood
//  Assignment: Final Project
//  Description: Implementation for Developer class
//  Filename: Developer.cpp
//  Last modified on: 12/14/12

#include "Developer.h"

//constructor for Developer
Developer::Developer(int inRow, int inCol, Color inColor):Piece(inRow, inCol, inColor)
{
    ID = DEVELOPER;
}

//destructor for Developer
Developer::~Developer()
{
}

//returns true for Developer
bool Developer::isRealPiece() const
{
    return true;
}

//converts Developer to string
string Developer::object2string() const
{
    string result = "";
    if (player == GREEN)
		result = "g";
    else if (player == YELLOW)
		result = "y";
    
    result = result + "D";
    
    return result;
}

//checks if move is valid for Developer
bool Developer::move(int e_row, int e_col)
{
    //checks not going backwards
    if (player == GREEN && e_row < row)
        return false;
    if (player == YELLOW && e_row > row)
        return false;
    
    //if on row 6 (YELLOW) or 1 (GREEN), hasn't moved yet, so can move up two
    if (player == GREEN && row == 1)
        if (e_row == row+2 && e_col == col)
            return true;
    
    if (player == YELLOW && row == 6)
        if (e_row == row-2 && e_col == col)
            return true;
    
    //can move forward one space and go either one column over or 
    if (player == GREEN && e_row == row+1 && e_col == col)
        return true;
    
    if (player == YELLOW && e_row == row-1 && e_col == col)
        return true;
    
    //can move diagonally if capture
    if (player == GREEN && e_row == row+1 && (e_col == col-1 || e_col == col+1))
        return true;
    
    if (player == YELLOW && e_row == row-1 && (e_col == col-1 || e_col == col+1))
        return true;
    
    return false;
}
