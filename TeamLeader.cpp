//  Name: David Hand
//  Course: CSC260, Section 1
//  Semester: Fall 2012
//  Instructor: Dr. Pulimood
//  Assignment: Final Project
//  Description: Implementation for TeamLeader class
//  Filename: TeamLeader.cpp
//  Last modified on: 12/14/12

#include "TeamLeader.h"

//constructor for TeamLeader
TeamLeader::TeamLeader(int inRow, int inCol, Color inColor):Piece(inRow, inCol, inColor)
{
    ID = TEAMLEADER;
}

//destructor for TeamLeader
TeamLeader::~TeamLeader()
{
}

//returns true for TeamLeader
bool TeamLeader::isRealPiece() const
{
    return true;
}

//converts TeamLeader to string
string TeamLeader::object2string() const
{
    string result = "";
    if (player == GREEN)
		result = "g";
    else if (player == YELLOW)
		result = "y";
    
    result = result + "T";
    
    return result;
}

//checks that move is valid for TeamLeader
bool TeamLeader::move(int e_row, int e_col)
{
    bool result = false;
    //calculate possible destinations
    int row1, row2, row3, row4;
    int col1, col2, col3, col4;
    
    row1 = row + 1;
    row2 = row + 2;
    row3 = row - 1;
    row4 = row - 2;
    
    col1 = col + 1;
    col2 = col + 2;
    col3 = col - 1;
    col4 = col - 2;
    
    //test each combination for if matches ending destination
    if (row1 == e_row && col2 == e_col)
        result = true;
    else if (row2 == e_row && col1 == e_col)
        result = true;
    else if (row3 == e_row && col2 == e_col)
        result = true;
    else if (row4 == e_row && col1 == e_col)
        result = true;
    else if (row1 == e_row && col4 == e_col)
        result = true;
    else if (row2 == e_row && col3 == e_col)
        result = true;
    else if (row3 == e_row && col4 == e_col)
        result = true;
    else if (row4 == e_row && col3 == e_col)
        result = true;
    else
        result = false;
        
    
    return result;
}
