//
//  Player_Class.cpp
//  Homework1
//
//  Created by Hui Yu Chuang on 1/10/18.
//  Copyright © 2018 Hui Yu Chuang. All rights reserved.
//

#include <iostream>
#include "Player_Class.h"

void Player::set_name(std::string name)
{
    playerName= name;
}

void Player::set_score(int amount)
{
    playerScore =amount;
}

std::string Player::get_name() const
{
    return playerName;
}

int Player::get_score() const
{
    return playerScore;
}
