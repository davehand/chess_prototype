//  Name: David Hand
//  Course: CSC260, Section 1
//  Semester: Fall 2012
//  Instructor: Dr. Pulimood
//  Assignment: Final Project
//  Description: Gameboard implementation
//  Filename: GameBoard.cpp
//  Last modified on: 12/14/12

#include "GameBoard.h"

//constructor to create GameBoard from file
GameBoard::GameBoard (ifstream& initStr)
{
    //initializes all pointers to null and counters to zero
    for (int i = 0; i < MROWS; i++)
        for (int j = 0; j < MCOLS; j++)
            board[i][j] = NULL;
    
    move_count = 0;
    dev_move_count = 0;
    
    //calls function to initialize board from stream
    initBoard(initStr);
}

//function used to initialize board from file
//initializes all pieces dynamically
void GameBoard::initBoard (ifstream& initStr)
{
	//initializes data to create GameBoard
    int row = 0, col = 0, pieceType = -1;
	Color player = YELLOW;
    bool again = false;
    
    //initializes counters to ensure the correct number of each piece is instantiated
    int g_pres_count = 0, g_ceo_count = 0, g_man_count = 0, g_sup_count = 0; 
    int g_team_count = 0, g_dev_count = 0;
    
    int y_pres_count = 0, y_ceo_count = 0, y_man_count = 0, y_sup_count = 0; 
    int y_team_count = 0, y_dev_count = 0;
	
    //continues until end of file
	while (!initStr.eof())
	{
        //input from file with error checking
        //gets row for piece
        while (!again)
        {
            initStr >> row;
            again = isValidInt(row,MROWS-1);
            if (!again)
                cout << "Invalid input. Row must be between 0 and " << MROWS-1 << ". Try again: " << endl;
        }
        again = false;
        
        //gets column for piece
        while (!again)
        {
            initStr >> col;
            again = isValidInt(col,MCOLS-1);
            if (!again)
                cout << "Invalid input. Column must be between 0 and " << MCOLS-1 << ". Try again: " << endl;
        }
        again = false;
        
        //gets tyoe of piece
        while (!again)
        {
            initStr >> pieceType;
            again = isValidInt(pieceType-1,NUM_TYPES-1);
            if (!again)
                cout << "Invalid input. Piece type must be between 1 and " << NUM_TYPES << ". Try again:" << endl;
        }
        again = false;
        
        //gets color of piece - Green or Yellow
        while (!again)
        {
            int p;
            initStr >> p;
            again = isValidInt(p,NUM_PLAYERS-1);

            if (!again)
                cout << "Invalid input. Player type must be either 0 or " <<  NUM_PLAYERS-1 << ". Try again: " << endl;
            else
            {
                if (p == 0)
                    player = GREEN;
                else
                    player = YELLOW;
            }
        }
        again = false;
        
		//after data has been read in for piece, creates piece, if not too many already created
        //also ensures that piece is instantiated where it should be
		switch (pieceType) {
                
            //creates President piece, if there aren't already too many
			case PRESIDENT: 
                
                if (player == 0 && g_pres_count < 1 && row == 0) //green and president doesn't exist
                {
                    President *g_pres = new President(row,col,player);
                    board[row][col] = g_pres;
                    g_pres_count++;
                }
                else if (player == 1 && y_pres_count < 1 && row == MROWS-1) //yellow and president doesn't exist
                {
                    President *y_pres = new President(row,col,player);
                    board [row][col] = y_pres;
                    y_pres_count++;
                }
                else
                    cout << "" << endl;
                
                break;
            
            //creates CEO piece, if there aren't already too many    
            case CEO:
                
                if (player == 0 && g_ceo_count < 1 && row == 0) //green and CEO doesn't exist
                {
                    Ceo *g_ceo = new Ceo(row,col,player);
                    board [row][col] = g_ceo;
                    g_ceo_count++;
                }
                else if (player == 1 && y_ceo_count < 1 && row == MROWS-1) //yellow and CEO doesn't exist
                {
                    Ceo *y_ceo = new Ceo(row,col,player);
                    board [row][col] = y_ceo;
                    y_ceo_count++;
                }
                else
                    cout << "" << endl;
                
				break;
            
            //creates Manager piece, if there aren't already too many    
            case MANAGER:
                
                if (player == 0 && g_man_count < 2 && row == 0) //green and less than 2 green managers initialized
                {
                    Manager *g_man = new Manager(row,col,player);
                    board [row][col] = g_man;
                    g_man_count++;
                }
                else if (player == 1 && y_man_count < 2 && row == MROWS-1) //yellow and less than 2 yellow managers initialized
                {
                    Manager *y_man = new Manager(row,col,player);
                    board [row][col] = y_man;
                    y_man_count++;
                }
                else
                    cout << "" << endl;
                
				break;
            
            //creates Supervisor piece, if there aren't already too many    
            case SUPERVISOR:
                
                if (player == 0 && g_sup_count < 2 && row == 0) //green and less than 2 green supervisors initialized
                {
                    Supervisor *g_sup = new Supervisor(row,col,player);
                    board [row][col] = g_sup;
                    g_sup_count++;
                }
                else if (player == 1 && y_sup_count < 2 && row == MROWS-1) //yellow and less than 2 yellow supervisors initialized
                {
                    Supervisor *y_sup = new Supervisor(row,col,player);
                    board [row][col] = y_sup;
                    y_sup_count++;
                }
                else
                    cout << "" << endl;
                
				break;
            
            //creates TeamLeader piece, if there aren't already too many    
            case TEAMLEADER:
                
                if (player == 0 && g_team_count < 2 && row == 0) //green and less than 2 green team leaders initialized
                {
                    TeamLeader *g_team = new TeamLeader(row,col,player);
                    board [row][col] = g_team;
                    g_team_count++;
                }
                else if (player == 1 && y_team_count < 2 && row == MROWS-1) //yellow and less than 2 yellow team leaders initialized
                {
                    TeamLeader *y_team = new TeamLeader(row,col,player);
                    board [row][col] = y_team;
                    y_team_count++;
                }
                else
                    cout << "" << endl;
                    
				break;
            
            //creates Developer piece, if there aren't already too many    
            case DEVELOPER:
                
                if (player == 0 && g_dev_count < 8 && row == 1) //green and less than 8 green developers initialized
                {
                    Developer *g_dev = new Developer(row,col,player);
                    board [row][col] = g_dev;
                    g_dev_count++;
                }
                else if (player == 1 && y_dev_count < 8 && row == MROWS-2) //yellow and less than 8 yellow developers initialized
                {
                    Developer *y_dev = new Developer(row,col,player);
                    board [row][col] = y_dev;
                    y_dev_count++;
                }
                else
                    cout << "" << endl;
                
				break;
			
            //no piece on the space    
            default: 
                cout << "Used default" << endl;
				board [row][col] = NULL;
				break;
                
		} // end switch (pieceType)
	} // end while (!eof)
        
} // end initBoard()

//converts the board into a string to be printed
string GameBoard::object2string () const
{
    ostringstream os;
	
    //labels columns
	cout << setw(5) << " ";
    for (int j = 0; j < MCOLS; j++)
		os << setw(5) << j;
    os << endl << endl;
    
    //labels rows and prints piece at each space on board
    //blank if NULL
    for (int i = 0; i < MROWS; i++) {
		os << setw(5) << i;
		for (int j = 0; j < MCOLS; j++)
        {
            if (board[i][j] != NULL)
                os << setw(5) << board[i][j]->object2string();
            else
                os << setw(5) << "";
        }
		os << endl;
	}
    os << endl;
    //returns string of board
    return os.str();
}

//function that performs movements for the board
//checks for if invalid move
//if valid move, performs the movement of data and manipulates pointers
//if capture, removes captured piece from game via delete
bool GameBoard::doMove(int s_row, int s_col, int e_row, int e_col)
{
    bool validSpot = true, legalmove = false;
    
    //checks that start and end are not the same
    if (s_row == e_row && s_col == e_col)
        return false;
    
    //checks that start and end positions are on the board
    if (s_row < 0 || s_row > MROWS-1)
        validSpot = false;

    if (s_col < 0 || s_col > MCOLS-1)
        validSpot = false;
        
    if (e_row < 0 || e_row > MROWS-1)
        validSpot = false;
        
    if (e_col < 0 || e_col > MROWS-1)
        validSpot = false;
    
    if (!validSpot)
        return false;
        
    //checks that piece is at start position
    Piece* piecePtr = board[s_row][s_col];
    if (piecePtr == NULL)
        return false;
    
    //sees if move is legal for the piece
    legalmove = board[s_row][s_col]->move(e_row, e_col);
    
    //check for collisions
    if (legalmove)
    {
        int color = board[s_row][s_col]->getColor();
        
        //gets piece type to check collisions for
        switch (board[s_row][s_col]->getID())
        {
            case 1: //President piece
            {
                if (color == 0) //if GREEN
                {
                    //if destination is NULL, move piece
                    if (board[e_row][e_col] == NULL)
                    {
                        board[e_row][e_col] = board[s_row][s_col];
                        board[s_row][s_col] = NULL;
                        board[e_row][e_col]->set_new_pos(e_row, e_col);
                        move_count++;
                        dev_move_count++;
                    }
                    //if green piece already there, move invalid
                    else if (board[e_row][e_col]->getColor() == 0)
                    {
                        return false;
                    }
                    //if yellow piece there, capture piece and move
                    else
                    {
                        delete board[e_row][e_col];
                        board[e_row][e_col] = board[s_row][s_col];
                        board[s_row][s_col] = NULL;
                        board[e_row][e_col]->set_new_pos(e_row, e_col);
                        move_count = 0;
                        dev_move_count++;
                    }
                }
                else //YELLOW
                {
                    //if destination is NULL, move piece
                    if (board[e_row][e_col] == NULL)
                    {
                        board[e_row][e_col] = board[s_row][s_col];
                        board[s_row][s_col] = NULL;
                        board[e_row][e_col]->set_new_pos(e_row, e_col);
                        move_count++;
                        dev_move_count++;
                    }
                    //if yellow piece already there, move invalid
                    else if (board[e_row][e_col]->getColor() == 1)
                    {
                        return false;
                    }
                    //if green piece there, capture piece and move
                    else
                    {
                        delete board[e_row][e_col];
                        board[e_row][e_col] = board[s_row][s_col];
                        board[s_row][s_col] = NULL;
                        board[e_row][e_col]->set_new_pos(e_row, e_col);
                        move_count = 0;
                        dev_move_count++;
                    }
                }
                break;
            }    
            case 2: //CEO piece
            {
                if (color == 0) //GREEN
                {
                    //find out if piece is going diagonally, horizontally, or vertically
                    int choice = 0;
                    if (s_row == e_row) //horizontal
                        choice = 1;
                    else if (s_col == e_col) //vertical
                        choice = 2;
                    else
                        choice = 3;
                    
                    //begins choices
                    switch (choice)
                    {
                        //CEO moving horizontally
                        case 1:
                        {
                            int res = s_col - e_col;
                            
                            if (res > 0) //negative traversal, check for collisions
                            {
                                for (int a = s_col-1; a > e_col; a--)
                                {
                                    if (board[s_row][a] == NULL)
                                        ;
                                    else
                                        return false;
                                }
                            }
                            else //positive traversal, check for collisions
                            {
                                for (int b = s_col+1; b < e_col; b++)
                                {
                                    if (board[s_row][b] == NULL)
                                        ;
                                    else
                                        return false;
                                }
                            }

                            //if destination is NULL, move piece
                            if (board[e_row][e_col] == NULL)
                            {
                                board[e_row][e_col] = board[s_row][s_col];
                                board[s_row][s_col] = NULL;
                                board[e_row][e_col]->set_new_pos(e_row, e_col);
                                move_count++;
                                dev_move_count++;
                                return true;
                            }
                            //if green piece already there, move invalid
                            else if (board[e_row][e_col]->getColor() == 0)
                            {
                                return false;
                            }
                            //if yellow piece there, capture piece and move
                            else
                            {
                                delete board[e_row][e_col];
                                board[e_row][e_col] = board[s_row][s_col];
                                board[s_row][s_col] = NULL;
                                board[e_row][e_col]->set_new_pos(e_row, e_col);
                                move_count = 0;
                                dev_move_count++;
                                return true;
                            }
                            
                            break;
                        }
                        //CEO moving vertically
                        case 2:
                        {
                            int res = s_row - e_row;
                            
                            //check for collisions
                            if (res > 0) //negative traversal
                            {
                                for (int a = s_row-1; a > e_row; a--)
                                {
                                    if (board[a][s_col] == NULL)
                                        ;
                                    else
                                        return false;
                                }
                            }
                            else //positive traversal
                            {
                                for (int b = s_row+1; b < e_row; b++)
                                {
                                    if (board[b][s_col] == NULL)
                                        ;
                                    else
                                        return false;
                                }
                            }

                            //if destination is NULL, move piece
                            if (board[e_row][e_col] == NULL)
                            {
                                board[e_row][e_col] = board[s_row][s_col];
                                board[s_row][s_col] = NULL;
                                board[e_row][e_col]->set_new_pos(e_row, e_col);
                                move_count++;
                                dev_move_count++;
                                return true;
                            }
                            //if green piece already there, move invalid
                            else if (board[e_row][e_col]->getColor() == 0)
                            {
                                return false;
                            }
                            //if yellow piece there, capture piece and move
                            else
                            {
                                delete board[e_row][e_col];
                                board[e_row][e_col] = board[s_row][s_col];
                                board[s_row][s_col] = NULL;
                                board[e_row][e_col]->set_new_pos(e_row, e_col);
                                move_count = 0;
                                dev_move_count++;
                                return true;
                            }
                            
                            break;
                        }
                        //CEO moving diagonally
                        case 3:
                        {
                            int res = s_row - e_row;
                            int res2 = s_col - e_col;
                            
                            //check for collisions
                            if (res > 0 && res2 > 0) //up and to left
                            {
                                int i = s_row-1, j = s_col-1;
                                while (i != e_row)
                                {
                                    if (board[i][j] == NULL)
                                    {
                                        i--;
                                        j--;
                                    }
                                    else
                                        return false;
                                }
                            }
                            else if (res > 0 && res2 < 0) //up and to right
                            {
                                int i = s_row-1, j = s_col+1;
                                while (i != e_row)
                                {
                                    if (board[i][j] == NULL)
                                    {
                                        i--;
                                        j++;
                                    }
                                    else
                                        return false;
                                }
                            }
                            else if (res < 0 && res2 > 0) //down and to left
                            {
                                int i = s_row+1, j = s_col-1;
                                while (i != e_row)
                                {
                                    if (board[i][j] == NULL)
                                    {
                                        i++;
                                        j--;
                                    }
                                    else
                                        return false;
                                }
                            }
                            else //down and to right
                            {
                                int i = s_row+1, j = s_col+1;
                                while (i != e_row)
                                {
                                    if (board[i][j] == NULL)
                                    {
                                        i++;
                                        j++;
                                    }
                                    else
                                        return false;
                                }
                            }
                            
                            //if destination is NULL, move piece
                            if (board[e_row][e_col] == NULL)
                            {
                                board[e_row][e_col] = board[s_row][s_col];
                                board[s_row][s_col] = NULL;
                                board[e_row][e_col]->set_new_pos(e_row, e_col);
                                move_count++;
                                dev_move_count++;
                                return true;
                            }
                            //if green piece already there, invalid move
                            else if (board[e_row][e_col]->getColor() == 0)
                            {
                                return false;
                            }
                            //if yellow piece there, capture piece and move
                            else
                            {
                                delete board[e_row][e_col];
                                board[e_row][e_col] = board[s_row][s_col];
                                board[s_row][s_col] = NULL;
                                board[e_row][e_col]->set_new_pos(e_row, e_col);
                                move_count = 0;
                                dev_move_count++;
                                return true;
                            }
                            
                            break;
                        }
                        //no other cases reached
                        default:
                            legalmove = false;
                            break;
                    }
                }
                else //YELLOW
                {
                    //find out if piece is going diagonally, horizontally, or vertically
                    int choice = 0;
                    if (s_row == e_row) //horizontal
                        choice = 1;
                    else if (s_col == e_col) //vertical
                        choice = 2;
                    else
                        choice = 3;
                    
                    //begins choices
                    switch (choice)
                    {
                        //CEO moving horizontally
                        case 1:
                        {
                            int res = s_col - e_col;
                            
                            //checks for collisionss
                            if (res > 0) //negative traversal
                            {
                                for (int a = s_col-1; a > e_col; a--)
                                {
                                    if (board[s_row][a] == NULL)
                                        ;
                                    else
                                        return false;
                                }
                            }
                            else //positive traversal
                            {
                                for (int b = s_col+1; b < e_col; b++)
                                {
                                    if (board[s_row][b] == NULL)
                                        ;
                                    else
                                        return false;
                                }
                            }
                            
                            //if destination is NULL, move piece
                            if (board[e_row][e_col] == NULL)
                            {
                                board[e_row][e_col] = board[s_row][s_col];
                                board[s_row][s_col] = NULL;
                                board[e_row][e_col]->set_new_pos(e_row, e_col);
                                move_count++;
                                dev_move_count++;
                                return true;
                            }
                            //if yellow piece already there, invalid move
                            else if (board[e_row][e_col]->getColor() == 1)
                            {
                                return false;
                            }
                            //if green piece there, capture piece and move
                            else
                            {
                                delete board[e_row][e_col];
                                board[e_row][e_col] = board[s_row][s_col];
                                board[s_row][s_col] = NULL;
                                board[e_row][e_col]->set_new_pos(e_row, e_col);
                                move_count = 0;
                                dev_move_count++;
                                return true;
                            }
                            
                            break;
                        }
                        //CEO moving vertically
                        case 2:
                        {
                            int res = s_row - e_row;
                            
                            //checks for collisions
                            if (res > 0) //negative traversal
                            {
                                for (int a = s_row-1; a > e_row; a--)
                                {
                                    if (board[a][s_col] == NULL)
                                        ;
                                    else
                                        return false;
                                }
                            }
                            else //positive traversal
                            {
                                for (int b = s_row+1; b < e_row; b++)
                                {
                                    if (board[b][s_col] == NULL)
                                        ;
                                    else
                                        return false;
                                }
                            }

                            //if destination is NULL, move piece
                            if (board[e_row][e_col] == NULL)
                            {
                                board[e_row][e_col] = board[s_row][s_col];
                                board[s_row][s_col] = NULL;
                                board[e_row][e_col]->set_new_pos(e_row, e_col);
                                move_count++;
                                dev_move_count++;
                                return true;
                            }
                            //if yellow piece already there, invalid move
                            else if (board[e_row][e_col]->getColor() == 1)
                            {
                                return false;
                            }
                            //if green piece there, capture piece and move
                            else
                            {
                                delete board[e_row][e_col];
                                board[e_row][e_col] = board[s_row][s_col];
                                board[s_row][s_col] = NULL;
                                board[e_row][e_col]->set_new_pos(e_row, e_col);
                                move_count = 0;
                                dev_move_count++;
                                return true;
                            }
                            
                            break;
                        }
                        //CEO moving diagonally
                        case 3:
                        {
                            int res = s_row - e_row;
                            int res2 = s_col - e_col;
                            
                            //checks for collisions
                            if (res > 0 && res2 > 0) //up and to left
                            {
                                int i = s_row-1, j = s_col-1;
                                while (i != e_row)
                                {
                                    if (board[i][j] == NULL)
                                    {
                                        i--;
                                        j--;
                                    }
                                    else
                                        return false;
                                }
                            }
                            else if (res > 0 && res2 < 0) //up and to right
                            {
                                int i = s_row-1, j = s_col+1;
                                while (i != e_row)
                                {
                                    if (board[i][j] == NULL)
                                    {
                                        i--;
                                        j++;
                                    }
                                    else
                                        return false;
                                }
                            }
                            else if (res < 0 && res2 > 0) //down and to left
                            {
                                int i = s_row+1, j = s_col-1;
                                while (i != e_row)
                                {
                                    if (board[i][j] == NULL)
                                    {
                                        i++;
                                        j--;
                                    }
                                    else
                                        return false;
                                }
                            }
                            else //down and to right
                            {
                                int i = s_row+1, j = s_col+1;
                                while (i != e_row)
                                {
                                    if (board[i][j] == NULL)
                                    {
                                        i++;
                                        j++;
                                    }
                                    else
                                        return false;
                                }
                            }
                            
                            //if destination is NULL, move piece
                            if (board[e_row][e_col] == NULL)
                            {
                                board[e_row][e_col] = board[s_row][s_col];
                                board[s_row][s_col] = NULL;
                                board[e_row][e_col]->set_new_pos(e_row, e_col);
                                move_count++;
                                dev_move_count++;
                                return true;
                            }
                            //if yellow piece already there, invalid move
                            else if (board[e_row][e_col]->getColor() == 1)
                            {
                                return false;
                            }
                            //if green piece there, capture piece and move
                            else
                            {
                                delete board[e_row][e_col];
                                board[e_row][e_col] = board[s_row][s_col];
                                board[s_row][s_col] = NULL;
                                board[e_row][e_col]->set_new_pos(e_row, e_col);
                                move_count = 0;
                                dev_move_count++;
                                return true;
                            }
                            
                            break;
                        }
                        //no other cases reached
                        default:
                            legalmove = false;
                            break;
                    }
                }
            }    
            case 3: //Manager piece
            {    
                if (color == 0) //GREEN
                {
                    //find out if piece is going horizontally or vertically
                    int choice = 0;
                    if (s_row == e_row) //horizontal
                        choice = 1;
                    else //vertical
                        choice = 2;
                    
                    //begins choices
                    switch (choice)
                    {
                        //Manager moving horizontally
                        case 1:
                        {
                            int res = s_col - e_col;
                            
                            //checks for collisions
                            if (res > 0) //negative traversal
                            {
                                for (int a = s_col-1; a > e_col; a--)
                                {
                                    if (board[s_row][a] == NULL)
                                        ;
                                    else
                                        return false;
                                }
                            }
                            else //positive traversal
                            {
                                for (int b = s_col+1; b < e_col; b++)
                                {
                                    if (board[s_row][b] == NULL)
                                        ;
                                    else
                                        return false;
                                }
                            }
                            
                            //if destination is NULL, move piece
                            if (board[e_row][e_col] == NULL)
                            {
                                board[e_row][e_col] = board[s_row][s_col];
                                board[s_row][s_col] = NULL;
                                board[e_row][e_col]->set_new_pos(e_row, e_col);
                                move_count++;
                                dev_move_count++;
                            }
                            //if green piece already there, move invalid
                            else if (board[e_row][e_col]->getColor() == 0)
                            {
                                return false;
                            }
                            //if yellow piece there, capture piece and move
                            else
                            {
                                delete board[e_row][e_col];
                                board[e_row][e_col] = board[s_row][s_col];
                                board[s_row][s_col] = NULL;
                                board[e_row][e_col]->set_new_pos(e_row, e_col);
                                move_count = 0;
                                dev_move_count++;
                            }
                            
                            break;
                        }
                        //Manager moving vertically
                        case 2:
                        {
                            int res = s_row - e_row;
                            
                            //checks for collisions
                            if (res > 0) //negative traversal
                            {
                                for (int a = s_row-1; a > e_row; a--)
                                {
                                    if (board[a][s_col] == NULL)
                                        ;
                                    else
                                        return false;
                                }
                            }
                            else //positive traversal
                            {
                                for (int b = s_row+1; b < e_row; b++)
                                {
                                    if (board[b][s_col] == NULL)
                                        ;
                                    else
                                        return false;
                                }
                            }
                            
                            //if destination is NULL, move piece
                            if (board[e_row][e_col] == NULL)
                            {
                                board[e_row][e_col] = board[s_row][s_col];
                                board[s_row][s_col] = NULL;
                                board[e_row][e_col]->set_new_pos(e_row, e_col);
                                move_count++;
                                dev_move_count++;
                            }
                            //if green piece already there, move invalid
                            else if (board[e_row][e_col]->getColor() == 0)
                            {
                                return false;
                            }
                            //if yellow piece there, capture piece and move
                            else
                            {
                                delete board[e_row][e_col];
                                board[e_row][e_col] = board[s_row][s_col];
                                board[s_row][s_col] = NULL;
                                board[e_row][e_col]->set_new_pos(e_row, e_col);
                                move_count = 0;
                                dev_move_count++;
                            }
                            
                            break;
                        }
                        //no other cases reached
                        default:
                            legalmove = false;
                            break;
                    }
                }
                else //YELLOW
                {
                    //find out if piece is going horizontally or vertically
                    int choice = 0;
                    if (s_row == e_row) //horizontal
                        choice = 1;
                    else //vertical
                        choice = 2;
                    
                    //begins choices
                    switch (choice)
                    {
                        //Manager moving horizontally
                        case 1:
                        {
                            int res = s_col - e_col;
                            
                            //checks for collisions
                            if (res > 0) //negative traversal
                            {
                                for (int a = s_col-1; a > e_col; a--)
                                {
                                    if (board[s_row][a] == NULL)
                                        ;
                                    else
                                        return false;
                                }
                            }
                            else //positive traversal
                            {
                                for (int b = s_col+1; b < e_col; b++)
                                {
                                    if (board[s_row][b] == NULL)
                                        ;
                                    else
                                        return false;
                                }
                            }
                            
                            //if destination is NULL, move piece
                            if (board[e_row][e_col] == NULL)
                            {
                                board[e_row][e_col] = board[s_row][s_col];
                                board[s_row][s_col] = NULL;
                                board[e_row][e_col]->set_new_pos(e_row, e_col);
                                move_count++;
                                dev_move_count++;
                            }
                            //if yellow piece already there, move invalid
                            else if (board[e_row][e_col]->getColor() == 1)
                            {
                                return false;
                            }
                            //if green piece there, capture piece and move
                            else
                            {
                                delete board[e_row][e_col];
                                board[e_row][e_col] = board[s_row][s_col];
                                board[s_row][s_col] = NULL;
                                board[e_row][e_col]->set_new_pos(e_row, e_col);
                                move_count = 0;
                                dev_move_count++;
                            }
                            
                            break;
                        }
                        //Manager moving vertically
                        case 2:
                        {
                            int res = s_row - e_row;
                            
                            //checks for collisions
                            if (res > 0) //negative traversal
                            {
                                for (int a = s_row-1; a > e_row; a--)
                                {
                                    if (board[a][s_col] == NULL)
                                        ;
                                    else
                                        return false;
                                }
                            }
                            else //positive traversal
                            {
                                for (int b = s_row+1; b < e_row; b++)
                                {
                                    if (board[b][s_col] == NULL)
                                        ;
                                    else
                                        return false;
                                }
                            }
                            
                            //if destination is NULL, move piece
                            if (board[e_row][e_col] == NULL)
                            {
                                board[e_row][e_col] = board[s_row][s_col];
                                board[s_row][s_col] = NULL;
                                board[e_row][e_col]->set_new_pos(e_row, e_col);
                                move_count++;
                                dev_move_count++;
                            }
                            //if yellow piece already there, invalid move
                            else if (board[e_row][e_col]->getColor() == 1)
                            {
                                return false;
                            }
                            //if green piece there, capture piece and move
                            else
                            {
                                delete board[e_row][e_col];
                                board[e_row][e_col] = board[s_row][s_col];
                                board[s_row][s_col] = NULL;
                                board[e_row][e_col]->set_new_pos(e_row, e_col);
                                move_count = 0;
                                dev_move_count++;
                            }
                            
                            break;
                        }
                        //no other cases reached
                        default:
                            legalmove = false;
                            break;
                    }
                }
                
                break;
            }
            case 4: //Supervisor piece
            {   
                int res = s_row - e_row;
                int res2 = s_col - e_col;
                
                //checks for collisions
                if (color == 0) //GREEN
                {
                    if (res > 0 && res2 > 0) //up and to left
                    {
                        int i = s_row-1, j = s_col-1;
                        while (i != e_row)
                        {
                            if (board[i][j] == NULL)
                            {
                                i--;
                                j--;
                            }
                            else
                                return false;
                        }
                    }
                    else if (res > 0 && res2 < 0) //up and to right
                    {
                        int i = s_row-1, j = s_col+1;
                        while (i != e_row)
                        {
                            if (board[i][j] == NULL)
                            {
                                i--;
                                j++;
                            }
                            else
                                return false;
                        }
                    }
                    else if (res < 0 && res2 > 0) //down and to left
                    {
                        int i = s_row+1, j = s_col-1;
                        while (i != e_row)
                        {
                            if (board[i][j] == NULL)
                            {
                                i++;
                                j--;
                            }
                            else
                                return false;
                        }
                    }
                    else //down and to right
                    {
                        int i = s_row+1, j = s_col+1;
                        while (i != e_row)
                        {
                            if (board[i][j] == NULL)
                            {
                                i++;
                                j++;
                            }
                            else
                                return false;
                        }
                    }
                    
                    //if destination is NULL, move piece
                    if (board[e_row][e_col] == NULL)
                    {
                        board[e_row][e_col] = board[s_row][s_col];
                        board[s_row][s_col] = NULL;
                        board[e_row][e_col]->set_new_pos(e_row, e_col);
                        move_count++;
                        dev_move_count++;
                    }
                    //if green piece already there, move invalid
                    else if (board[e_row][e_col]->getColor() == 0)
                    {
                        return false;
                    }
                    //if yellow piece there, capture piece and move
                    else
                    {
                        delete board[e_row][e_col];
                        board[e_row][e_col] = board[s_row][s_col];
                        board[s_row][s_col] = NULL;
                        board[e_row][e_col]->set_new_pos(e_row, e_col);
                        move_count = 0;
                        dev_move_count++;
                    }
                }
                else //YELLOW
                {
                    int res = s_row - e_row;
                    int res2 = s_col - e_col;
                    
                    //checks for collisions
                    if (res > 0 && res2 > 0) //up and to left
                    {
                        int i = s_row-1, j = s_col-1;
                        while (i != e_row)
                        {
                            if (board[i][j] == NULL)
                            {
                                i--;
                                j--;
                            }
                            else
                                return false;
                        }
                    }
                    else if (res > 0 && res2 < 0) //up and to right
                    {
                        int i = s_row-1, j = s_col+1;
                        while (i != e_row)
                        {
                            if (board[i][j] == NULL)
                            {
                                i--;
                                j++;
                            }
                            else
                                return false;
                        }
                    }
                    else if (res < 0 && res2 > 0) //down and to left
                    {
                        int i = s_row+1, j = s_col-1;
                        while (i != e_row)
                        {
                            if (board[i][j] == NULL)
                            {
                                i++;
                                j--;
                            }
                            else
                                return false;
                        }
                    }
                    else //down and to right
                    {
                        int i = s_row+1, j = s_col+1;
                        while (i != e_row)
                        {
                            if (board[i][j] == NULL)
                            {
                                i++;
                                j++;
                            }
                            else
                                return false;
                        }
                    }
                    
                    //if destination is NULL, move piece
                    if (board[e_row][e_col] == NULL)
                    {
                        board[e_row][e_col] = board[s_row][s_col];
                        board[s_row][s_col] = NULL;
                        board[e_row][e_col]->set_new_pos(e_row, e_col);
                        move_count++;
                        dev_move_count++;
                    }
                    //if yellow piece already there, move invalid
                    else if (board[e_row][e_col]->getColor() == 1)
                    {
                        return false;
                    }
                    //if green piece there, capture piece and move
                    else
                    {
                        delete board[e_row][e_col];
                        board[e_row][e_col] = board[s_row][s_col];
                        board[s_row][s_col] = NULL;
                        board[e_row][e_col]->set_new_pos(e_row, e_col);
                        move_count = 0;
                        dev_move_count++;
                    }
                }

                break;
            }    
            case 5: //TeamLeader piece
            {    
                if (color == 0) //if GREEN
                {
                    //if destination is NULL, move piece
                    if (board[e_row][e_col] == NULL)
                    {
                        board[e_row][e_col] = board[s_row][s_col];
                        board[s_row][s_col] = NULL;
                        board[e_row][e_col]->set_new_pos(e_row, e_col);
                        move_count++;
                        dev_move_count++;
                    }
                    //if green piece already there, move invalid
                    else if (board[e_row][e_col]->getColor() == 0)
                    {
                        return false;
                    }
                    //if yellow piece there, capture piece and move
                    else
                    {
                        delete board[e_row][e_col];
                        board[e_row][e_col] = board[s_row][s_col];
                        board[s_row][s_col] = NULL;
                        board[e_row][e_col]->set_new_pos(e_row, e_col);
                        move_count = 0;
                        dev_move_count++;
                    }
                }
                else //YELLOW
                {
                    //if destination is NULL, move piece
                    if (board[e_row][e_col] == NULL)
                    {
                        board[e_row][e_col] = board[s_row][s_col];
                        board[s_row][s_col] = NULL;
                        board[e_row][e_col]->set_new_pos(e_row, e_col);
                        move_count++;
                        dev_move_count++;
                    }
                    //if yellow piece already there, move invalid
                    else if (board[e_row][e_col]->getColor() == 1)
                    {
                        return false;
                    }
                    //if green piece there, move invalid
                    else
                    {
                        delete board[e_row][e_col];
                        board[e_row][e_col] = board[s_row][s_col];
                        board[s_row][s_col] = NULL;
                        board[e_row][e_col]->set_new_pos(e_row, e_col);
                        move_count = 0;
                        dev_move_count++;
                    }
                }
                
                break;
            }    
            case 6: //Developer piece
            {   
                if (color == 0) //GREEN
                {
                    int res = e_row - s_row;
                    
                    //for if pawn is moving 2 spaces
                    if (res == 2)
                    {
                        //checks for collision
                        if (board[s_row+1][s_col] == NULL)
                        {
                            //if destination is NULL, move piece
                            if (board[e_row][e_col] == NULL)
                            {
                                board[e_row][e_col] = board[s_row][s_col];
                                board[s_row][s_col] = NULL;
                                board[e_row][e_col]->set_new_pos(e_row, e_col);
                                move_count++;
                                dev_move_count = 0;
                            }
                            //if green piece already there, move invalid
                            else 
                            {
                                return false;
                            }
                        }
                        else 
                            return false; //collision
                    }
                    else //res == 1, pawn moving 1 space
                    {
                        int res2 = e_col - s_col;
                        
                        if (res2 == 0) //move forward
                        {
                            //if destination is NULL, move piece
                            if (board[e_row][e_col] == NULL)
                            {
                                board[e_row][e_col] = board[s_row][s_col];
                                board[s_row][s_col] = NULL;
                                board[e_row][e_col]->set_new_pos(e_row, e_col);
                                move_count++;
                                dev_move_count = 0;
                            }
                            //space not empty, invalid move
                            else
                            {
                                return false;
                            }
                        }
                        else //looking to capture
                        {
                            //invalid move if no capture at space
                            if (board[e_row][e_col] == NULL)
                            {
                                return false;
                            }
                            //invalid move if pawn of same color
                            else if (board[e_row][e_col]->getColor() == 0)
                            {
                                return false;
                            }
                            //if capture, removes yellow piece and moves green piece
                            else
                            {
                                delete board[e_row][e_col];
                                board[e_row][e_col] = board[s_row][s_col];
                                board[s_row][s_col] = NULL;
                                board[e_row][e_col]->set_new_pos(e_row, e_col);
                                move_count = 0;
                                dev_move_count = 0;
                            }
                        }
                    }
                }
                else //YELLOW
                {
                    int res = s_row - e_row;
                    
                    //for if pawn is moving two spaces
                    if (res == 2)
                    {
                        //checks for colision
                        if (board[s_row-1][s_col] == NULL)
                        {
                            //if destination is NULL, move piece
                            if (board[e_row][e_col] == NULL)
                            {
                                board[e_row][e_col] = board[s_row][s_col];
                                board[s_row][s_col] = NULL;
                                board[e_row][e_col]->set_new_pos(e_row, e_col);
                                move_count++;
                                dev_move_count = 0;
                            }
                            //if space occupied by same color piece, invalid move
                            else 
                            {
                                return false;
                            }

                        }
                        else 
                            return false; //collision so move invalid
                    }
                    else //res == 1
                    {
                        int res2 = s_col - e_col;
                        
                        if (res2 == 0) //move forward
                        {
                            //if space is empty, move piece
                            if (board[e_row][e_col] == NULL)
                            {
                                //if destination is NULL, move piece
                                board[e_row][e_col] = board[s_row][s_col];
                                board[s_row][s_col] = NULL;
                                board[e_row][e_col]->set_new_pos(e_row, e_col);
                                move_count++;
                                dev_move_count = 0;
                            }
                            else //collision
                            {
                                return false;
                            }
                        }
                        else //looking to capture
                        {
                            //if space is empty, move invalid (no capture)
                            if (board[e_row][e_col] == NULL)
                            {
                                return false;
                            }
                            //if space occupied by same color, move invalid
                            else if (board[e_row][e_col]->getColor() == 1)
                            {
                                return false;
                            }
                            //if green piece there, capture piece and move
                            else
                            {
                                delete board[e_row][e_col];
                                board[e_row][e_col] = board[s_row][s_col];
                                board[s_row][s_col] = NULL;
                                board[e_row][e_col]->set_new_pos(e_row, e_col);
                                move_count = 0;
                                dev_move_count = 0;
                            }
                        }
                    }
                }
                
                break;
            }
            default: //Piece not found
            {
                legalmove = false;
                break;
            }
        }
    }
    
    return legalmove;
}

//checks that conditions have not been met
bool GameBoard::isDraw()
{
    if (move_count >= 100 || dev_move_count >= 100) //fifty moves by each player meeting either condition
        return true;
    else
        return false;
}

//gets valid integer between 0 and maximum passes to it
bool isValidInt(int x, int max)
{    
    if (x >= 0 && x <= max)
        return true;
    else
        return false;
}
