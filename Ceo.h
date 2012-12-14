//  Name: David Hand
//  Course: CSC260, Section 1
//  Semester: Fall 2012
//  Instructor: Dr. Pulimood
//  Assignment: Final Project
//  Description: Header file for CEO class
//  Filename: CEO.h
//  Last modified on: 12/14/12

#if ! defined (CEO_H)
#define CEO_H

#include <iostream>
#include <string>
#include "Piece.h"
using namespace std;

class Ceo : public Piece
{
private:
    bool validDiagMove (int, int);
    //PRE: User wants to know if diagonal move is valid
    //POST: Returns if move is valid or not
    //PARAM: int - row destination
    //       int - column destination
    //RETURN: bool - if move is valid or not
public:
    Ceo(int=0, int=0, Color=YELLOW);
    //constructor for Ceo
    ~Ceo();
    //destructor for Ceo
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
    //PRE: User wants to know if move is valid
    //POST: Returns if move is valid
    //PARAM: int - destination row
    //       int - destination column
    //RETURN: bool - True if move valid, false otherwise
};

#endif