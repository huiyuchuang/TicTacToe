//
//  Player_class.h
//
//  Created by Hui Yu Chuang on 1/9/18.
//  Copyright © 2018 Hui Yu Chuang. All rights reserved.
//

#ifndef Player_Class_H
#define Player_Class_H

#include <iostream>
#include <string>
#include <vector>

class Player
{
public:
    Player() : playerName("Player"), playerScore(0) {}; //default constructor sets playerName to Player and playerScore to 0
    Player(std::string name, int score) : playerName(name), playerScore(score) {}; //constructor sets playerName to the input name and playerScore to the inputScore
    void set_name(std::string name); //sets the player's name
    void set_score(int score); //sets the player's score
    
    std::string get_name() const; //outputs the player's name
    int get_score() const; //outputs the player's score
    
private:
    std::string playerName;
    int playerScore;
};




#endif //Header_h
