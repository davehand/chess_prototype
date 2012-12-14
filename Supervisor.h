//  Name: David Hand
//  Course: CSC260, Section 1
//  Semester: Fall 2012
//  Instructor: Dr. Pulimood
//  Assignment: Final Project
//  Description: Header file for Supervisor class
//  Filename: Manager.h
//  Last modified on: 12/14/12

#if ! defined (SUPERVISOR_H)
#define SUPERVISOR_H

#include <iostream>
#include <string>
#include "Piece.h"
using namespace std;

class Supervisor : public Piece
{
private:
    
public:
    Supervisor(int=0, int=0, Color=YELLOW);
    //constructor for Supervisor
    ~Supervisor();
    //destructor for Supervisor
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
