//  Name: David Hand
//  Course: CSC260, Section 1
//  Semester: Fall 2012
//  Instructor: Dr. Pulimood
//  Assignment: Final Project
//  Description: Header file for gameboard
//  Filename: GameBoard.h
//  Last modified on: 12/14/12

#if !defined (GAMEBOARD_H)
#define GAMEBOARD_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "Piece.h"
#include "President.h"
#include "Manager.h"
#include "Developer.h"
#include "Ceo.h"
#include "Supervisor.h"
#include "TeamLeader.h"

using namespace std;

//initializes constants for GameBoard
const int MROWS = 8;
const int MCOLS = 8;
const int WIN = 10; 
const int RES_LOSE = -2; 
const int RES_WIN = 7; 
const int DRAW = 5; 
const int NUM_TYPES = 6;
const int NUM_PLAYERS = 2;

bool isValidInt(int, int);
//PRE: System wants to check if int is valid
//POST: Returns if int is valid or not
//PARAM: int - number to be verified
//       int - maximum that number can be
//RETURN: bool - true if valid int, false otherwise

class GameBoard 
{
private:
    //board that holds pointers to Pieces
    Piece *board [MROWS][MCOLS];
    //function to initialize board from file
	void initBoard (ifstream&);
    //count for number of moves without capture (for draw condition)
    int move_count;
    //count for number of moves that aren't developer pieces (for draw condition) 
    int dev_move_count;
	
public:
    GameBoard (ifstream&);
    //constructor for GameBoard
    string object2string () const;
    //PRE: User wants to convert board to string
    //POST: Board has been converted to string
    //PARAM: NONE
    //RETURN: string - string containing current board display
    bool doMove(int, int, int, int);
    //PRE: User wants to perform a move
    //POST: Move has been determined to be invalid or is executed
    //PARAM: int - starting row
    //       int - staring column
    //       int - ending row
    //       int - ending column
    //RETURN: bool - true if valid move, false otherwise    
    bool isDraw();
    //PRE: User wants to determine if fourth draw condition has been reached
    //POST: Returns if fourth condition for draw has been met
    //PARAM: NONE
    //RETURN: bool - true if draw condition met, false otherwise
};

#endif  // GAMEBOARD_H
