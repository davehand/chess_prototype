//  Name: David Hand
//  Course: CSC260, Section 1
//  Semester: Fall 2012
//  Instructor: Dr. Pulimood
//  Assignment: Final Project
//  Description: Implementation for Manager class
//  Filename: Manager.cpp
//  Last modified on: 12/14/12

#include "Manager.h"

//constructor for Manager
Manager::Manager(int inRow, int inCol, Color inColor):Piece(inRow, inCol, inColor)
{
    ID = MANAGER;
}

//destructor for Manager
Manager::~Manager()
{
}

//returns true for Manager
bool Manager::isRealPiece() const
{
    return true;
}

//converts Manager to string
string Manager::object2string() const
{
    string result = "";
    if (player == GREEN)
		result = "g";
    else if (player == YELLOW)
		result = "y";
    
    result = result + "M";
    
    return result;
}

//returns if move is valid for Manager
bool Manager::move(int e_row, int e_col)
{
    if (row == e_row || col == e_col)
        return true;
    else
        return false;
}
