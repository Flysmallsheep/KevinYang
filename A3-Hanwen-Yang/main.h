#ifndef main_h
#define main_h

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include "player.h"
#include "board.h"


 
using namespace std ;

string Intro(){
    return "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
    "                               MasterMind :: Code Detective                                   \n"
    "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
    "Hello Detective! This is a game called MasterMind, please type in numbers, characters or even \n"
    "the symbols and press Enter to see if you guess them correctly before your turns run out!   \n\n"
    "The clues will show you if you have guess the elements right in the right positions:  (o) or  \n"
    "guess the right elements but in wrong positions:  (?) or nothing to show if neither of them.  \n"
    "The number of elements in the code for you to guess will be shown at the top of the board.  \n\n"
    "There are three skill levels you can choose for: Easy(12 chances), Medium(8 chances) or Hard  \n"
    "(5 chances). Different skill levels will result in different scores that gain or lose by the  \n"
    "player. If you win or lose specific amount of games, you will be asked to promoted or automati-\n"
    "-cally demoted for the following games!                                                      \n\n"
    "So seize the opportunity to maximize your scores and win the game!                           \n\n"
    "Enjoy playing, code detective! type [P] to continue:                                          \n";
}

void checkStart1(){
    char begin;
    cin >> begin;
    while (begin != 'P') {
        cout << "Please press [P] to start the game!\n";
        cin >> begin;
    }
}

void checkStart2(){
    char begin;
    cout << "\nType [P] to begin begin your adventure!!!  ";
    cin >> begin;
    while (begin != 'P') {
        cout << "Please press [P] to start the game!\n";
        cin >> begin;
    }
    
}







#endif /* main_h */
