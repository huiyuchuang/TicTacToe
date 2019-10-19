//
//  main.cpp
//  Homework1
//
//  Created by Hui Yu Chuang on 1/9/18.
//  Copyright © 2018 Hui Yu Chuang. All rights reserved.
//

#include <iostream>
#include "Player_Class.h"
#include <vector>
#include <string>

/**
Fuction prints out the game board.
 
@param p1 class that stores the name and score of the first player
@param p2 class that stores the name and score of the second player
@param row1 the first row of the board
@param row2 the second row of the board
@param row3 the third row of the board
 */
void printGame(Player* p1, Player* p2, std::vector<std::string>&row1,std::vector<std::string>&row2, std::vector<std::string>&row3)
{
    
    std::cout << "       1      2      3   \n";
    std::cout << "           |      |      "<< std::endl;
    std::cout << "1" << "      " << row1[0] << "   |   "<< row1[1] << "  |   "<< row1[2] << std::endl;
    std::cout << "           |      |      "<< std::endl;
    std::cout << "     ------+------+------"<< std::endl;
    std::cout << "           |      |      "<< std::endl;
    std::cout << "2" << "      " << row2[0] << "   |   "<< row2[1] << "  |   "<< row2[2] << std::endl;
    std::cout << "           |      |      "<< std::endl;
    std::cout << "     ------+------+------"<< std::endl;
    std::cout << "           |      |      "<< std::endl;
    std::cout << "3" << "      " << row3[0] << "   |   "<< row3[1] << "  |   "<< row3[2] << std::endl;
    std::cout << "           |      |      "<< std::endl;
    
}

/**
Function that reads player 1's input and marks "X" in the correct box on the board.

@param inputRowX the row number of the chosen box
@param inputColX the column number of the chosen box
@param row1 the first row of the board
@param row2 the second row of the board
@param row3 the third row of the board
*/
void turnX(int inputRowX, int inputColX,std::vector<std::string>&row1,std::vector<std::string>&row2, std::vector<std::string>&row3)
{
    
    if (inputRowX==1)
    {
        for(int i=0; i<3; i++)
        {
            if(i == inputColX-1)
                row1[i] = "X";
        }
    }
    
    else if (inputRowX==2)
    {
        for(int i=0; i<3; i++)
        {
            if (i==inputColX-1)
                row2[i] = "X";
        }
    }
    else if (inputRowX==3)
    {
        for (int i=0; i<3; i++)
        {
            if(i==inputColX-1)
                row3[i] = "X";
        }
        
    }
}

/**
 Function that reads player 2's input and marks "O" in the correct box on the board.
 
 @param inputRowO the row number of the chosen box
 @param inputColO the column number of the chosen box
 @param row1 the first row of the board
 @param row2 the second row of the board
 @param row3 the third row of the board
 */
void turnO(int inputRowO, int inputColO, std::vector<std::string>&row1, std::vector<std::string>&row2, std::vector<std::string>&row3)
{

    if (inputRowO == 1)
    {
        for(int i=0; i < 3; i++)
        {
            if(i == inputColO-1)
                row1[i] = "O";
        }
    }
    else if (inputRowO == 2)
    {
        for(int i=0; i < 3; i++)
        {
            if(i == inputColO-1)
                row2[i] = "O";
        }
    }
    else if (inputRowO == 3)
    {
        for(int i=0; i < 3; i++)
        {
            if(i == inputColO-1)
                row3[i] = "O";
        }
    }
}

/**
Function checks if all nine boxes have a mark of either "X" or "O". Returns true if is completely filled.
 
@param row1 the first row of the board
@param row2 the second row of the board
@param row3 the third row of the board
 */
bool checkFilled(std::vector<std::string>row1,std::vector<std::string>row2,std::vector<std::string>row3)
{
    int counter=0;
    
    for (int i=0; i < 3; i++)
    {
        if (row1[i] != " ")
        {
            counter++;
        }
        if (row2[i] != " ")
        {
            counter++;
        }
        if (row3[i] != " ")
        {
            counter++;
        }
    }
    
    return counter==9;
}

/**
Function checks if player 1 is the winner and returns true if he/she is.
 
@param row1 the first row of the board
@param row2 the second row of the board
@param row3 the third row of the board
*/
bool checkWinnerX(std::vector<std::string>row1,std::vector<std::string>row2,std::vector<std::string>row3)
{
    bool isWinnerX = false;
    if(row1[0] == row2[1] && row2[1] == row3[2] && row1[0] == "X")
        isWinnerX = true;
    if(row1[2] == row2[1] && row2[1] == row3[0] && row1[2] == "X")
        isWinnerX = true;
    if(row1[0] == row1[1] && row1[1] == row1[2] && row1[0] == "X")
        isWinnerX = true;
    if(row2[0] == row2[1] && row2[1] == row2[2] && row2[0] == "X")
        isWinnerX = true;
    if(row3[0] == row3[1] && row3[1] == row3[2] && row3[0] == "X")
        isWinnerX = true;
    if(row1[0] == row2[0] && row2[0] == row3[0] && row1[0] == "X")
        isWinnerX = true;
    if(row1[1] == row2[1] && row2[1] == row3[1] && row1[1] == "X")
        isWinnerX = true;
    if(row1[2] == row2[2] && row2[2] == row3[2] && row1[2] == "X")
        isWinnerX = true;
                                    
    return isWinnerX;
}

/**
Function checks if player 2 is the winner and returns true if he/she is.
 
@param row1 the first row of the board
@param row2 the second row of the board
@param row3 the third row of the board
 */
bool checkWinnerO(std::vector<std::string>row1,std::vector<std::string>row2,std::vector<std::string>row3)
{
    bool isWinnerO = false;
    if(row1[0] == row2[1] && row2[1] == row3[2] && row1[0] == "O")
        isWinnerO = true;
    if(row1[2] == row2[1] && row2[1] == row3[0] && row1[2] == "O")
        isWinnerO = true;
    if(row1[0] == row1[1] && row1[1] == row1[2] && row1[0] == "O")
        isWinnerO = true;
    if(row2[0] == row2[1] && row2[1] == row2[2] && row2[0] == "O")
        isWinnerO = true;
    if(row3[0] == row3[1] && row3[1] == row3[2] && row3[0] == "O")
        isWinnerO = true;
    if(row1[0] == row2[0] && row2[0] == row3[0] && row1[0] == "O")
        isWinnerO = true;
    if(row1[1] == row2[1] && row2[1] == row3[1] && row1[1] == "O")
        isWinnerO = true;
    if(row1[2] == row2[2] && row2[2] == row3[2] && row1[2] == "O")
        isWinnerO = true;
    
    return isWinnerO;
}

/**
Function checks if the result is a Draw.

@param row1 the first row of the board
@param row2 the second row of the board
@param row3 the third row of the board
 */
bool checkDraw(std::vector<std::string>row1,std::vector<std::string>row2,std::vector<std::string>row3)
{
    bool isDraw = false;
    if (checkWinnerX(row1, row2, row3) != true && checkWinnerO(row1,row2,row3) != true && checkFilled(row1,row2,row3) == true)
    {
        isDraw = true;
    }
    return isDraw;
}


int main(){
    
    Player* player1 = new Player(); //creates new Player, player1
    Player* player2 = new Player(); //creates new Player, player2
    
    std::cout<< "This is a Tic Tac Toe game!\nPlease enter the name of Player 1:";
    std::string name1;
    getline(std::cin,name1);
    player1->set_name(name1); //sets the name of player1 in Player class as name1
    
    std::cout<< "Thanks. Please enter the name of Player 2:";
    std::string name2;
    getline(std::cin,name2);
    player2->set_name(name2); //sets the name of player2 in Player class as name2
    
    std::cout<< "How many games would you like to play?";
    int number;
    std::cin >> number;
    
    std::cout<< "Let the games begin!"<<std::endl;
    
    int scoreX=0; //a counter to count player1's total score for all the games
    int scoreO=0; //a counter to count player2's total score for all the games
    
    for (int i=0;i<number;i++) //this for loop loops the for the total number of games
    {
        
        std::vector<std::string> row1(3," ");
        std::vector<std::string> row2(3," ");
        std::vector<std::string> row3(3," ");
        
        if (i%2==0) //run this loop if round number is even, first round being round 0
        {
            
            while (checkWinnerX(row1,row2,row3) != true && checkWinnerO(row1,row2,row3) != true && checkDraw(row1,row2,row3) != true && checkFilled(row1,row2,row3) != true)
            {
            
                printGame(player1,player2,row1,row2,row3);
        
                std::cout << "It is " << player1->get_name() << "'s turn.\nWhere would you like to play? Enter your row position and column position: row col:";
            
                int inputRowX;
                int inputColX;
                std::cin>>inputRowX;
                std::cin>>inputColX;
        
                turnX(inputRowX,inputColX, row1, row2, row3);
        
                printGame(player1, player2, row1, row2, row3);
        
                if (checkWinnerX(row1,row2,row3)==true) //if the player1 wins, the round ends
                {
                    scoreX++; //player1's score increases by 1
                    player1->set_score(scoreX);
                    std::cout<< player1->get_name()<< " won this round!\nPresently, " << player1->get_name() << " has " <<player1->get_score()<< " points and " << player2->get_name() << " has " <<player2->get_score() << " points.\n";
                }
                else if (checkDraw(row1,row2,row3)== true) //check for Draw once player1 marks the last box and there is no winner.
                {
                    std::cout << "It is a draw!\n";
                }
                else //if player1 did not win, player2 gets to make his/her move next.
                {
                    std::cout<< "It is " << player2->get_name()<< "'s turn.\nWhere would you like to play? Enter your row position and column position: row col:";
        
                    int inputRowO;
                    int inputColO;
                    std::cin >> inputRowO;
                    std::cin >>inputColO;
        
                    turnO(inputRowO,inputColO, row1, row2, row3);
            
                    if (checkWinnerO(row1,row2,row3)==true) //if player2 wins, round ends. Else it will loop back up and player1 gets to play the next move.
                    {
                        printGame(player1, player2, row1, row2, row3);
                        scoreO++; //player2's score increases by 1
                        player2->set_score(scoreO);
                        std::cout<< player2->get_name()<< " won this round!\nPresently, " << player1->get_name() << " has " <<player1->get_score()<< " points and " << player2->get_name() << " has " <<player2->get_score() << " points.\n";
                    }
                }
            }
        }
        
        else if (i%2!=0) //run this loop if round number is odd, first round being round 0
        {
            while (checkWinnerX(row1,row2,row3) != true && checkWinnerO(row1,row2,row3) != true && checkDraw(row1,row2,row3) != true && checkFilled(row1,row2,row3) != true)
            {
                
                printGame(player1,player2,row1,row2,row3);
                
                std::cout << "It is " << player2->get_name() << "'s turn.\nWhere would you like to play? Enter your row position and column position: row col:";
                
                int inputRowO;
                int inputColO;
                std::cin >> inputRowO;
                std::cin >>inputColO;
                
                turnO(inputRowO,inputColO, row1, row2, row3);
                
                printGame(player1, player2, row1, row2, row3);
                
                if (checkWinnerO(row1,row2,row3)==true) //if player2 wins, the round ends
                    
                {
                    scoreO++; //player2's score increases by 1
                    player2->set_score(scoreO);
                    std::cout<< player2->get_name()<< " won this round!\nPresently, " << player1->get_name() << " has " <<player1->get_score()<< " points and " << player2->get_name() << " has " <<player2->get_score() << " points.\n";
                }
                else if (checkDraw(row1,row2,row3)== true) //check for Draw when player2 marks the last box and there is no winner.
                {
                    std::cout << "It is a draw!\n";
                }
                else
                {
                    std::cout<< "It is " << player1->get_name()<< "'s turn.\nWhere would you like to play? Enter your row position and column position: row col:";
                    
                    int inputX;
                    int inputCol;
                    std::cin>>inputX;
                    std::cin>>inputCol;
                    
                turnX(inputX, inputCol, row1, row2, row3);
                    
                    if (checkWinnerX(row1,row2,row3)==true) //if player1 wins, round ends. Else, loop back up and player2 gets to play the next move.
                    {
                        printGame(player1, player2, row1, row2, row3);
                        scoreX++; //player1's score increases by 1
                        player1->set_score(scoreX); //sets player1's score to scoreX
                        std::cout<< player1->get_name()<< " won this round!\nPresently, " << player1->get_name() << " has " <<player1->get_score()<< " points and " << player2->get_name() << " has " <<player2->get_score() << " points.\n";
                    }
                }
            }
        }
    }
    /*
    After all the games have been played, compare the final score of both players
    */
    if (player1->get_score()>player2->get_score()) //if score of player1 is greater than that of player 2, player1 wins
        std::cout<< player1->get_name() << " is the winner!\n";
    else if (player1->get_score()<player2->get_score()) //if score of player2 is greater than that of player1, player2 wins
        std::cout<<player2->get_name() << " is the winner!\n";
    else if (player1->get_score()==player2->get_score()) //if both scores are the same, it is a draw
        std::cout<<"It is a draw!\n";

    return 0;
}
