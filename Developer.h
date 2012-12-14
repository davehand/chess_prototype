//  Name: David Hand
//  Course: CSC260, Section 1
//  Semester: Fall 2012
//  Instructor: Dr. Pulimood
//  Assignment: Final Project
//  Description: Header file for Developer class
//  Filename: Developer.h
//  Last modified on: 12/14/12

#if ! defined (DEVELOPER_H)
#define DEVELOPER_H

#include <iostream>
#include <string>
#include "Piece.h"
using namespace std;

class Developer : public Piece
{
private:
    
public:
    Developer(int=0, int=0, Color=YELLOW);
    //constructor for Developer
    ~Developer();
    //destructor for Developer
    bool isRealPiece() const;
    //PRE: User wants to know if piece is real
    //POST: Returns if piece is real or not
    //PARAM: NONE
    //RETURN: bool - if piece is real or not
    string object2string() const;
    //PRE: User wants to convert piece to string
    //POST: Piece in string format
    //PARAM: NONE
    //RETURN: string - Piece in format that can be output
    bool move(int, int);
    //PRE: User wants to convert piece to string
    //POST: Piece in string format
    //PARAM: NONE
    //RETURN: string - Piece in format that can be output
};

#endif
