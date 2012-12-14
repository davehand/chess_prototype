//  Name: David Hand
//  Course: CSC260, Section 1
//  Semester: Fall 2012
//  Instructor: Dr. Pulimood
//  Assignment: Final Project
//  Description: Driver for the program
//  Filename: gameDriver.cpp
//  Last modified on: 12/14/12

#include "GameBoard.h"
#include <iostream>
#include <fstream>
using namespace std;

int getValidInt();
//PRE: System wants a valid integer to be entered
//POST: A valid integer has been entered
//PARAM: NONE
//RETURN: int - valid integer

//Driver for the chess game
int main (void)
{
    //generates data to initialize board
	ifstream initBoardStr;
	string initBoardFile = "";
    bool worked = true;
        
    //gets the file name to input the start board from
    //makes sure file is valid and can be opened
    do
    {
        cout << "Please enter file to read start board from." << endl;
        cin >> initBoardFile;
        
        initBoardStr.open(initBoardFile.c_str());
        
        if (initBoardStr.fail())
        {
            cerr << "Error opening file. Try again." << endl;
            initBoardStr.clear();
            initBoardStr.ignore(80, '\n');
            worked = false;
        }
        else
            worked = true;
    }
    while (!worked);
	
    //constructs/initilizes board and closes stream
    GameBoard newBoard(initBoardStr);
    initBoardStr.close();
    
	//initializes data for use by program
	int option = 0, gameEndOpt = 0;
	int fromRow = 0, toRow = 0;
	int fromCol = 0, toCol = 0;
	bool gameEnd = false, tryEndAgain = true;
    
    //begins game
    while (!gameEnd) 
	{
        //creates menu for user - gets user choice
		cout << "The current board is:" << endl; 
		cout << newBoard.object2string();
		cout << "What do you want to do?" << endl;
		cout << "(1) Make a move" << endl;
		cout << "(2) End the game" << endl;
        option = getValidInt();
        
        //executes user choice
		switch (option)
		{
			case 1: // Make a move
                //checks if fourth draw technique has been reached
                if (newBoard.isDraw())
                {
                    cout << "This game has resulted in a draw." << endl;
                    gameEnd = true;
                    break;
                }
                
                //gets start and ending coordinates for piece to move
				gameEnd = false;
				cout << "Enter coordinates of piece to move (row first): ";
                fromRow = getValidInt();
                fromCol = getValidInt();
				cout << "Enter coordinates to move piece to (row first): ";
                toRow = getValidInt();
                toCol = getValidInt();
				
                //attempts to execute move
				if (newBoard.doMove (fromRow, fromCol, toRow, toCol))
					cout << "Move Succeeded\n\n";
				else
					cout << "*** Invalid Move ***\n\n";
				break;
                
			case 2: //End the game
                
				gameEnd = true;
				tryEndAgain = true;
                
                //prints second menu for ending game
				while (tryEndAgain)
				{
					tryEndAgain = false;
					
                    //gets user choice to end game
					cout << "How did the game end?" << endl;
					cout << "(1) Green Won" << endl;
					cout << "(2) Yellow Won" << endl;
					cout << "(3) Green Resigned" << endl;
					cout << "(4) Yellow Resigned" << endl;
					cout << "(5) It's a Draw" << endl;
					cout << "(6) OOPS! Continue Game" << endl;
                    gameEndOpt = getValidInt();
                    
                    //executes user choice
					switch (gameEndOpt) 
                    {
						case 1: // Green Won
							cout << "Green gains " << WIN << " points" << endl;
							break;
						case 2: // Yellow Won
							cout << "Yellow gains " << WIN << " points" << endl;
							break;
						case 3: // Green Resigns
							cout << "Yellow gains " << RES_WIN << " points" << endl;
							cout << "Green forfeits " << RES_LOSE << " points" << endl;
							break;
						case 4: // Yellow Resigns
							cout << "Green gains " << RES_WIN << " points" << endl;
							cout << "Yellow forfeits " << RES_LOSE << " points" << endl;
							break;
						case 5: // Draw
							cout << "Green gains " << DRAW << " points" << endl;
							cout << "Yellow gains " << DRAW << " points" << endl;
							break;
						case 6:   // Don't end game
							cout << "Continuing Game" << endl;
							gameEnd = false;
							break;
						default: //reprint menu
							cout << "Invalid game end option" << endl << endl;
							tryEndAgain = true;
							break;
					} // end switch (gameEndOpt)
				} // while (tryEndAgain)
                break;
				
			default: //reprint menu
				gameEnd = false;
				cout << "Invalid option" << endl;
				break;
                
		} // end switch (option)
	} // while (!gameEnd) 
} // end main

//gets valid integer
int getValidInt()
{
    bool tryAgain = true;
    int x = 0;
    
    while (tryAgain)
    {
        cin >> x;
        
        //ensures valid number is read in
        if (cin.fail())
        {
            cout << "Invalid input - Please enter an integer: " << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else
            tryAgain = false;
    }
    
    return x;
}

