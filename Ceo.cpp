//  Name: David Hand
//  Course: CSC260, Section 1
//  Semester: Fall 2012
//  Instructor: Dr. Pulimood
//  Assignment: Final Project
//  Description: Implementation for CEO class
//  Filename: CEO.cpp
//  Last modified on: 12/14/12

#include "CEO.h"

//constructor for Ceo
Ceo::Ceo(int inRow, int inCol, Color inColor):Piece(inRow, inCol, inColor)
{
    ID = CEO;
}

//destructor for Ceo
Ceo::~Ceo()
{
}

//returns Ceo is real
bool Ceo::isRealPiece() const
{
    return true;
}

//converts Ceo to string
string Ceo::object2string() const
{
    string result = "";
    if (player == GREEN)
		result = "g";
    else if (player == YELLOW)
		result = "y";
    
    result = result + "C";
    
    return result;
}

//returns if move is valid
bool Ceo::move(int e_row, int e_col)
{
    if (row == e_row || col == e_col || validDiagMove(e_row, e_col))
        return true;
    else
        return false;
}

//returns if diagonal move is valid
bool Ceo::validDiagMove(int end_row, int end_col)
{    
    //checks left and up diagonal
    int i = row-1, j = col-1;
    while (i >= 0 && j >= 0)
    {
        if (i == end_row && j == end_col)
            return true;
        i--;
        j--;
    }
    
    //checks right and up diagonal
    i = row-1, j = col+1;
    while (i >= 0 && j < 8)
    {
        if (i == end_row && j == end_col)
            return true;
        i--;
        j++;
    }
    
    //checks left and down diagonal
    i = row+1, j = col-1;
    while (i < 8 && j >= 0)
    {
        if (i == end_row && j == end_col)
            return true;
        i++;
        j--;
    }
    
    //checks right and down diagonal
    i = row+1, j = col+1;
    while (i < 8 && j < 8)
    {
        if (i == end_row && j == end_col)
            return true;
        i++;
        j++;
    }
    
    return false;        
}
