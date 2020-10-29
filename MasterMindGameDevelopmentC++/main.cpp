#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include "player.h"
#include "board.h"
#include "main.h"

using namespace std;



//for main.cpp:
// I can use virtual methods to save lots of effort and use the code that in mail utilise to make the clue easier use for loop

int main() {
    
    //game paramters:
    string caseLevel;
    string caseElement;
    int caseLevelNum;
    int caseElementNum;
    int boardIdetifier;
    
   //Initialise the Player vector:
    vector<Player*> playerVector;
    playerVector.push_back(new Player("",0,0,0));
    
   
    
    
    
    //Initial the game variables:
    // Initialise the vector of number boards:
    vector<EasyNumberBoard*> EasyNumberBoardVector;
    vector<MediumNumberBoard*> MediumNumberBoardVector;
    vector<HardNumberBoard*> HardNumberBoardVector;
    //vector of char board:
    vector<EasyCharBoard*> EasyCharBoardVector;
    vector<MediumCharBoard*> MediumCharBoardVector;
    vector<HardCharBoard*> HardCharBoardVector;
    //vector of Symbol board:
    vector<EasySymbolBoard*> EasySymbolBoardVector;
    vector<MediumSymbolBoard*> MediumSymbolBoardVector;
    vector<HardSymbolBoard*> HardSymbolBoardVector;
    
    //output the introduction and check user if want to start:
    cout << Intro();
    checkStart1();
    
    
    
    // User interface starts here:
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
            "                               MasterMind :: Code Detective                                   \n"
            "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
            "Please enter your first name:";
    cin >> (*playerVector[0]).playerName;
    
    
    //label:
    jump1:
    //
    //let user enter the caseLevel:
    //
    //promoted checker:
    char promoCheck;
    //Check user if demoted:
    if ((*playerVector[0]).playerFailedCases >= 10) {
        cout << "\nBecause you have failed ten games in a row, you are automatically demoted and expelled from the hardest and Medium level!\n";
        cout << "\nPlease ENTER [0] to select a level!\n";
        cin >> caseLevelNum;
        while (caseLevelNum != 0) {
            cout << "Please ENTER [0] to select a level!\n";
            cin >> caseLevelNum;
        }
    }
    else if ((*playerVector[0]).playerFailedCases >= 5) {
        cout << "\nBecause you have failed five games in a row, you are automatically demoted and expelled from the hardest level!\n";
        cout << "\nPlease ENTER [0] [1] to select a level!\n";
        cin >> caseLevelNum;
        while ((caseLevelNum != 0)&&(caseLevelNum != 1)) {
            cout << "Please ENTER [0] [1] to select a level!\n";
            cin >> caseLevelNum;
        }
    }
    //check user if promoted:
    else if ( ((*playerVector[0]).playerFailedCases <= -5) && ((*playerVector[0]).playerFailedCases > -10) ){
        cout << "\nBecause you have pass five games in a row, you can choose to promoted to a higher level! Press [y] for yes or [n] to reject \n";
        cin >> promoCheck;
        //check:
        if (promoCheck == 'y'){
            cout << "\nPlease ENTER [1] [2] to select a level for medium or hard!\n";
            cin >> caseLevelNum;
            while ((caseLevelNum != 1)&&(caseLevelNum != 2)) {
                cout << "Please ENTER [1] [2] to select a level!\n";
                cin >> caseLevelNum;
            }
        }
        else{
                cout << "\nPlease select a difficulty level do you want to play:                                       \n"
                        "[0]:easy [1]:medium [2]:hard                                                                  \n";
                cin >> caseLevelNum;
                while ((caseLevelNum != 0)&&(caseLevelNum != 1)&&(caseLevelNum != 2)) {
                    cout << "Please ENTER [0] [1] or [2] to select a level!\n";
                    cin >> caseLevelNum;
                }
            
        }
    }
    else if ((*playerVector[0]).playerFailedCases <= -10) {
        cout << "\nBecause you have pass ten games in a row, you can choose to promoted to a higher level! Press [y] for yes or [n] to reject \n";
        cin >> promoCheck;
        //check:
        if (promoCheck == 'y'){
            cout << "\nPlease ENTER [2] to select a level for hard!\n";
            cin >> caseLevelNum;
            while (caseLevelNum != 2) {
                cout << "Please ENTER [2] to select a level!\n";
                cin >> caseLevelNum;
            }
        }
        else{
                cout << "\nPlease select a difficulty level do you want to play:                                       \n"
                        "[0]:easy [1]:medium [2]:hard                                                                  \n";
                cin >> caseLevelNum;
                while ((caseLevelNum != 0)&&(caseLevelNum != 1)&&(caseLevelNum != 2)) {
                    cout << "Please ENTER [0] [1] or [2] to select a level!\n";
                    cin >> caseLevelNum;
                }
            
        }
        
        
        
    }
    else{
        cout << "\nPlease select a difficulty level do you want to play:                                       \n"
                "[0]:easy [1]:medium [2]:hard                                                                  \n";
        cin >> caseLevelNum;
        while ((caseLevelNum != 0)&&(caseLevelNum != 1)&&(caseLevelNum != 2)) {
            cout << "Please ENTER [0] [1] or [2] to select a level!\n";
            cin >> caseLevelNum;
        }
    }
    
    
    
    
    
    
    
    
    
    //initial the caselevel value depends on user input:
    if (caseLevelNum == 0) {
        caseLevel = "Easy";
    }
    else if(caseLevelNum == 1){
        caseLevel = "Medium";
    }
    else if(caseLevelNum == 2){
        caseLevel = "Hard";
    }
    
    
    //
    //let user enter the caseElements (pointers with constructor):
    //
    cout << "\nPlease select which game mode do you want to play:                                       \n"
            "[0]:number [1]:char [2]:symbol                                                             \n";
    cin >> caseElementNum;
    while ((caseElementNum != 0)&&(caseElementNum != 1)&&(caseElementNum != 2)) {
        cout << "Please ENTER [0] [1] or [2] to select a elment!\n";
        cin >> caseElementNum;
    }
    if (caseElementNum == 0) {
        caseElement = "number";
    }
    else if(caseElementNum == 1){
        caseElement = "char";
    }
    else if(caseElementNum == 2){
        caseElement = "symbol";
    }
    
    
    
    //Generate the boards:
    //number board:
    if ((caseLevel == "Easy")&&(caseElement == "number")){
        EasyNumberBoardVector.push_back(new EasyNumberBoard(4,12,0,0,0,0));
        boardIdetifier = 1;
    }
    else if ((caseLevel == "Medium")&&(caseElement == "number")){
        MediumNumberBoardVector.push_back(new MediumNumberBoard(4,8,1,0,0,0));
        boardIdetifier = 2;
    }
    else if ((caseLevel == "Hard")&&(caseElement == "number")){
        HardNumberBoardVector.push_back(new HardNumberBoard(4,5,2,0,0,0));
        boardIdetifier = 3;
    }
    //char board:
    else if ((caseLevel == "Easy")&&(caseElement == "char")){
        EasyCharBoardVector.push_back(new EasyCharBoard(4,12,0,1,0,0));
        boardIdetifier = 4;
    }
    else if ((caseLevel == "Medium")&&(caseElement == "char")){
        MediumCharBoardVector.push_back(new MediumCharBoard(4,8,1,1,0,0));
        boardIdetifier = 5;
    }
    else if ((caseLevel == "Hard")&&(caseElement == "char")){
        HardCharBoardVector.push_back(new HardCharBoard(4,5,2,1,0,0));
        boardIdetifier = 6;
    }
    //symbol board:
    else if ((caseLevel == "Easy")&&(caseElement == "symbol")){
        EasySymbolBoardVector.push_back(new EasySymbolBoard(4,12,0,2,0,0));
        boardIdetifier = 7;
    }
    else if ((caseLevel == "Medium")&&(caseElement == "symbol")){
        MediumSymbolBoardVector.push_back(new MediumSymbolBoard(4,8,1,2,0,0));
        boardIdetifier = 8;
    }
    else {
        HardSymbolBoardVector.push_back(new HardSymbolBoard(4,5,2,2,0,0));
        boardIdetifier = 9;
    }
    
    
    //
    //Display the initial elements:
    //
    
    //we can use a stringstream here:
    cout << "\nThanks Detective " << (*playerVector[0]).playerName <<". Good luck with your adventure!\n\n\n";
    cout << "                               ===============================                                \n"
            "                               Name:     "<<(*playerVector[0]).playerName<<                  "\n"
            "                               Level:    "<<caseLevel<<                                      "\n"
            "                               game element:    "<<caseElement<<                             "\n"
            "                               Total cases:    "<<(*playerVector[0]).playerCases<<           "\n"
            "                               Solved cases:    "<<(*playerVector[0]).playerSolvedCases<<    "\n"
            "                               Total points:    "<<(*playerVector[0]).playerTotalPoints<<    "\n"
            "                               ===============================                                \n";
    
    
    //begin the game:
    checkStart2();
    //CHOOSE THE RIGHT BOARD TO START THE GAME:
    
    
    switch (boardIdetifier) {
        case 1:
            cout << "You have to guess the answer within four elements: 1 2 3 4 and you have 12 chances\n\n ";
            (*EasyNumberBoardVector[0]).BoardStartNum();
            //check user if win: //every game finish, total score change:
            if ((*EasyNumberBoardVector[0]).board_currentState == 1){
                (*playerVector[0]).playerSolvedCases += 1;
                (*playerVector[0]).playerFailedCases -= 1;
            }
            else{
                (*playerVector[0]).playerFailedCases += 1;
            }
            (*playerVector[0]).playerTotalPoints += (*EasyNumberBoardVector[0]).board_currentPoints;
            break;
            
        case 2:
            cout << "You have to guess the answer within four elements: 1 2 3 4 and you have 8 chances\n\n ";
            (*MediumNumberBoardVector[0]).BoardStartNum();
            //check user if win: //every game finish, total score change:
            if ((*MediumNumberBoardVector[0]).board_currentState == 1){
                (*playerVector[0]).playerSolvedCases += 1;
                (*playerVector[0]).playerFailedCases -= 1;
            }
            else{
                (*playerVector[0]).playerFailedCases += 1;
            }
            (*playerVector[0]).playerTotalPoints += (*MediumNumberBoardVector[0]).board_currentPoints;
            break;
            
        case 3:
            cout << "You have to guess the answer within four elements: 1 2 3 4 and you have 5 chances\n\n ";
            (*HardNumberBoardVector[0]).BoardStartNum();
            //check user if win: //every game finish, total score change:
            if ((*HardNumberBoardVector[0]).board_currentState == 1){
                (*playerVector[0]).playerSolvedCases += 1;
                (*playerVector[0]).playerFailedCases -= 1;
            }
            else{
                (*playerVector[0]).playerFailedCases += 1;
            }
            (*playerVector[0]).playerTotalPoints += (*HardNumberBoardVector[0]).board_currentPoints;
            break;
            
        case 4:
            cout << "You have to guess the answer within four elements: a b c d and you have 12 chances\n\n ";
            (*EasyCharBoardVector[0]).BoardStartChar();
            //check user if win: //every game finish, total score change:
            if ((*EasyCharBoardVector[0]).board_currentState == 1){
                (*playerVector[0]).playerSolvedCases += 1;
                (*playerVector[0]).playerFailedCases -= 1;
            }
            else{
                (*playerVector[0]).playerFailedCases += 1;
            }
            (*playerVector[0]).playerTotalPoints += (*EasyCharBoardVector[0]).board_currentPoints;
            break;
            
        case 5:
            cout << "You have to guess the answer within four elements: a b c d and you have 8 chances\n\n ";
            (*MediumCharBoardVector[0]).BoardStartChar();
            //check user if win: //every game finish, total score change:
            if ((*MediumCharBoardVector[0]).board_currentState == 1){
                (*playerVector[0]).playerSolvedCases += 1;
                (*playerVector[0]).playerFailedCases -= 1;
            }
            else{
                (*playerVector[0]).playerFailedCases += 1;
            }
            (*playerVector[0]).playerTotalPoints += (*MediumCharBoardVector[0]).board_currentPoints;
            break;
        
        case 6:
            cout << "You have to guess the answer within four elements: a b c d and you have 5 chances\n\n ";
            (*HardCharBoardVector[0]).BoardStartChar();
            //check user if win: //every game finish, total score change:
            if ((*HardCharBoardVector[0]).board_currentState == 1){
                (*playerVector[0]).playerSolvedCases += 1;
                (*playerVector[0]).playerFailedCases -= 1;
            }
            else{
                (*playerVector[0]).playerFailedCases += 1;
            }
            (*playerVector[0]).playerTotalPoints += (*HardCharBoardVector[0]).board_currentPoints;
            break;
        
        case 7:
            cout << "You have to guess the answer within four elements: # $ * @ and you have 12 chances\n\n ";
            (*EasySymbolBoardVector[0]).BoardStartSymbol();
            //check user if win: //every game finish, total score change:
            if ((*EasySymbolBoardVector[0]).board_currentState == 1){
                (*playerVector[0]).playerSolvedCases += 1;
                (*playerVector[0]).playerFailedCases -= 1;
            }
            else{
                (*playerVector[0]).playerFailedCases += 1;
            }
            (*playerVector[0]).playerTotalPoints += (*EasySymbolBoardVector[0]).board_currentPoints;
            break;
            
        case 8:
            cout << "You have to guess the answer within four elements: # $ * @ and you have 8 chances\n\n ";
            (*MediumSymbolBoardVector[0]).BoardStartSymbol();
            //check user if win: //every game finish, total score change:
            if ((*MediumSymbolBoardVector[0]).board_currentState == 1){
                (*playerVector[0]).playerSolvedCases += 1;
                (*playerVector[0]).playerFailedCases -= 1;
            }
            else{
                (*playerVector[0]).playerFailedCases += 1;
            }
            (*playerVector[0]).playerTotalPoints += (*MediumSymbolBoardVector[0]).board_currentPoints;
            break;
            
        case 9:
            cout << "You have to guess the answer within four elements: # $ * @ and you have 5 chances\n\n ";
            (*HardSymbolBoardVector[0]).BoardStartSymbol();
            //check user if win: //every game finish, total score change:
            if ((*HardSymbolBoardVector[0]).board_currentState == 1){
                (*playerVector[0]).playerSolvedCases += 1;
                (*playerVector[0]).playerFailedCases -= 1;
            }
            else{
                (*playerVector[0]).playerFailedCases += 1;
            }
            (*playerVector[0]).playerTotalPoints += (*HardSymbolBoardVector[0]).board_currentPoints;
            break;
                
        default:
            break;
            
            
    }
    //every game finish, total cases += 1:
    (*playerVector[0]).playerCases += 1;
   
    //Display current results:
     cout<< "                               ===============================                                \n"
            "                               Total cases:    "<<(*playerVector[0]).playerCases<<           "\n"
            "                               Solved cases:    "<<(*playerVector[0]).playerSolvedCases<<    "\n"
            "                               points for current game:    ";
    
    switch (boardIdetifier) {
           case 1:
                cout << EasyNumberBoardVector[0]->board_currentPoints;
               break;
            
           case 2:
                cout << MediumNumberBoardVector[0]->board_currentPoints;
               break;
            
           case 3:
                cout << HardNumberBoardVector[0]->board_currentPoints;
               break;
               
           case 4:
               cout << EasyCharBoardVector[0]->board_currentPoints;
               break;
               
           case 5:
               cout << MediumCharBoardVector[0]->board_currentPoints;
               break;
           
           case 6:
               cout << HardCharBoardVector[0]->board_currentPoints;
               break;
           
           case 7:
               cout << EasySymbolBoardVector[0]->board_currentPoints;
               break;
               
           case 8:
               cout << MediumSymbolBoardVector[0]->board_currentPoints;
               break;
               
           case 9:
               cout << HardSymbolBoardVector[0]->board_currentPoints;
               break;
                   
           default:
               break;
       }
    cout<<  "\n                               Total points:    "<<(*playerVector[0]).playerTotalPoints<<  "\n"
            "                               ===============================                                \n";
    
    
    
    
    
    
    //ask user if want to start a new game:
    cout << "Do you want to start a new game? Press [y] to start new game or [n] to execute the program ";
    char continueState;
    cin >> continueState;
    while ((continueState != 'y')&&(continueState != 'n')){
        cout << "Please press [y] to start new game or press [n] to execute the program\n";
        cin >> continueState;
    }
    if (continueState == 'y') {
        goto jump1;
    }
    else{
        exit(0);
    }
    
    
    return 0;
}







