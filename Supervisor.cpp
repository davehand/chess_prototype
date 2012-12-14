//  Name: David Hand
//  Course: CSC260, Section 1
//  Semester: Fall 2012
//  Instructor: Dr. Pulimood
//  Assignment: Final Project
//  Description: Implementation for Supervisor class
//  Filename: Supervisor.cpp
//  Last modified on: 12/14/12

#include "Supervisor.h"

//constructor for Supervisor
Supervisor::Supervisor(int inRow, int inCol, Color inColor):Piece(inRow, inCol, inColor)
{
    ID = SUPERVISOR;
}

//destructor for Supervsior
Supervisor::~Supervisor()
{
}

//returns true for Supervisor
bool Supervisor::isRealPiece() const
{
    return true;
}

//converts Supervisor to string
string Supervisor::object2string() const
{
    string result = "";
    if (player == GREEN)
		result = "g";
    else if (player == YELLOW)
		result = "y";
    
    result = result + "S";
    
    return result;
}

//checks if move is valid for Supervisor
bool Supervisor::move(int e_row, int e_col)
{
    //checks left and up diagonal
    int i = row-1, j = col-1;
    while (i >= 0 && j >= 0)
    {
        if (i == e_row && j == e_col)
            return true;
        i--;
        j--;
    }
    
    //checks right and up diagonal
    i = row-1, j = col+1;
    while (i >= 0 && j < 8)
    {
        if (i == e_row && j == e_col)
            return true;
        i--;
        j++;
    }
    
    //checks left and down diagonal
    i = row+1, j = col-1;
    while (i < 8 && j >= 0)
    {
        if (i == e_row && j == e_col)
            return true;
        i++;
        j--;
    }
    
    //checks right and down diagonal
    i = row+1, j = col+1;
    while (i < 8 && j < 8)
    {
        if (i == e_row && j == e_col)
            return true;
        i++;
        j++;
    }
    
    return false; 
}