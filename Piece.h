//  Name: David Hand
//  Course: CSC260, Section 1
//  Semester: Fall 2012
//  Instructor: Dr. Pulimood
//  Assignment: Final Project
//  Description: Implementation for Piece class
//  Filename: Piece.cpp
//  Last modified on: 12/14/12

#if ! defined (PIECE_H)
#define PIECE_H

#include <string>

using namespace std;

//sets constants for piece
const int PRESIDENT = 1;
const int CEO = 2;
const int MANAGER = 3;
const int SUPERVISOR = 4;
const int TEAMLEADER = 5;
const int DEVELOPER = 6;

//creates enum for Color
enum Color {GREEN=0, YELLOW=1};

class Piece 
{
    
protected:
    //instance data for Piece
    int row;
    int col;
    Color player;
    int ID; //used to hold type of piece
    
public:
    Piece (int=0, int=0, Color=YELLOW);
    //constructor for Piece
    virtual ~Piece();
    //destructor for Piece
    int getID();
    //PRE: User wants ID of piece
    //POST: Returns ID
    //PARAM: NONE
    //RETURN: int - number corresponding to piece
    int getColor();
    //PRE: User wants Color of piece
    //POST: Returns Color
    //PARAM: NONE
    //RETURN: int - number corresponding to color
    virtual bool isRealPiece() const; //virtual
    //PRE: User wants to know if piece is real
    //POST: Returns if piece is real or not
    //PARAM: NONE
    //RETURN: bool - if piece is real or not
    virtual string object2string() const;
    //PRE: User wants to convert piece to string
    //POST: Piece in string format
    //PARAM: NONE
    //RETURN: string - Piece in format that can be output
    virtual bool move(int, int);
    //PRE: User wants to convert piece to string
    //POST: Piece in string format
    //PARAM: NONE
    //RETURN: string - Piece in format that can be output
    void set_new_pos(int, int);
    //PRE: User wants to set new position for piece
    //POST: New row and column set
    //PARAM: int - new row
    //       int - new column
    //RETURN: NONE
};

#endif  // PIECE_H
