#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include "player.h"

using namespace std;

//static variable initialization:
int Player::playerSolvedCases = 0;
int Player::playerFailedCases = 0;



//constructors:
Player::Player(){
    
}
Player::Player(string playerNameP,int playerCasesP,int playerSolvedCasesP,int playerTotalPointsP){
    playerName = playerNameP;
    playerCases = playerCasesP;
    playerSolvedCases = playerSolvedCasesP;
    playerTotalPoints = playerTotalPointsP;
}
Player::~Player(){
    cout << "The player is destroyed!\n";
}


//member function:
void Player::setPlayerName(string newName){
    playerName = newName;
}

