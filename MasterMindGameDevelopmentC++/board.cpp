#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include "board.h"
#include "player.h"


using namespace std;



Board::Board(){
    
}


Board::Board(int board_ColumnP , int board_RowP, int board_caseLevelP, int board_caseElementP, int board_currentPointsP,int currentStateP){
    board_Column = board_ColumnP;
    board_Row    = board_RowP;
    board_caseLevel = board_caseLevelP;
    board_caseElement = board_caseElementP;
    board_currentPoints = board_currentPointsP;
    board_currentState = board_currentPointsP;
}
Board::~Board(){
    cout << "\nThe board is destroyed!";
}







//functions in derived classes:

void EasyNumberBoard::BoardStartNum(){
    
    
    // gameState identifier:
    int GameState = 0;
    //generate random answer:
        vector<int> answerVector;
        srand((unsigned)time(NULL));
        int a = 4;
        for (int i = 0; i < a; i++){
            int b = rand() % 4 + 1;
            answerVector.push_back(b);
            //output the answer to user:
            cout << answerVector[i] <<" ";
        }
        cout <<"\n\n\n";


    //let user inputs:
    //
    //CHANCES THAT PLAYER HAVE:
    //
        for (int i = 0; i < 12; i++) {
            
            cout << "\n  ||  please enter your " << i+1 << " guess:  ||  \n";
            int input;
            int counter = 0;
            vector<int> userVector;

                for (int i = 0; counter < 4; i++) {
                    cout << "  ||  ";
                    cin >> input;
                    if ((input >= 0) && (input <=4)){
                    userVector.push_back(input);
                    counter ++;
                    }
                    else {
                    cout <<  "please enter a valid number!";
                    }
                    
                }

            
            vector<string> clueVector;                 //the vector is to display the clue content
            vector<int> checkAnswerVector = {0,0,0,0}; //checkerVector is for checking if the answer has been checked
            vector<int> checkUserVector =   {0,0,0,0}; //checkerUserInput is for checking if the user input has been checked

             
             
             //
             //                      Begin Checking "o" statement:
             //
             //
             
             
             
             //check first input:
             if ( userVector[0] == answerVector[0]){
                 checkAnswerVector[0] = 1; //toggle the state for answer
                 checkUserVector[0]   = 1; //toggle the state for user
                 clueVector.push_back("o");
             }

             
             //Check second input:
             if ( userVector[1] == answerVector[1]){
                    checkAnswerVector[1] = 1;
                    checkUserVector[1] = 1;
                    clueVector.push_back("o");
                }

             
             
             //Check third input:
             if ( userVector[2] == answerVector[2]){
                    checkAnswerVector[2] = 1;
                    checkUserVector[2] = 1;
                    clueVector.push_back("o");
                }
            
             
             //Check fourth input:
             if ( userVector[3] == answerVector[3]){
                    checkAnswerVector[3] = 1;
                    checkUserVector[3] = 1;
                    clueVector.push_back("o");
                }

             
             //
             //                      Begin Checking "?" statement:
             //
             //
             
             
             
             //
             //                      First element check :
             //
             //
            cout<<"\n";
             if ( (  ((userVector[0] == answerVector[0]) && (checkAnswerVector[0] == 0)) ||
                     ((userVector[0] == answerVector[1]) && (checkAnswerVector[1] == 0)) ||
                     ((userVector[0] == answerVector[2]) && (checkAnswerVector[2] == 0)) ||
                     ((userVector[0] == answerVector[3]) && (checkAnswerVector[3] == 0))  ) && (checkUserVector[0] == 0) )
             {

                 clueVector.push_back("?");
                 
                 checkUserVector[0] = 1;  //toggle the userInput state
                 
                 if (userVector[0] == answerVector[0]) { //toggle the answer state
                     checkAnswerVector[0] = 1;
                 }
                 else if (userVector[0] == answerVector[1]){
                     checkAnswerVector[1] = 1;
                 }
                 else if (userVector[0] == answerVector[2]){
                     checkAnswerVector[2] = 1;
                 }
                 else if (userVector[0] == answerVector[3]){
                     checkAnswerVector[3] = 1;
                 }
                 
             }

             
             
             //
             //                      Second element check :
             //
             //
             if ( (  ((userVector[1] == answerVector[0]) && (checkAnswerVector[0] == 0)) ||
                     ((userVector[1] == answerVector[1]) && (checkAnswerVector[1] == 0)) ||
                     ((userVector[1] == answerVector[2]) && (checkAnswerVector[2] == 0)) ||
                     ((userVector[1] == answerVector[3]) && (checkAnswerVector[3] == 0))  ) && (checkUserVector[1] == 0) )
             {

                 clueVector.push_back("?");
                 
                 checkUserVector[1] = 1;  //toggle the userInput state
                 
                 if (userVector[1] == answerVector[0]) { //toggle the answer state
                     checkAnswerVector[0] = 1;
                 }
                 else if (userVector[1] == answerVector[1]){
                     checkAnswerVector[1] = 1;
                 }
                 else if (userVector[1] == answerVector[2]){
                     checkAnswerVector[2] = 1;
                 }
                 else if (userVector[1] == answerVector[3]){
                     checkAnswerVector[3] = 1;
                 }
                 
             }

             //
             //                      Third element check :
             //
             //
             if ( (  ((userVector[2] == answerVector[0]) && (checkAnswerVector[0] == 0)) ||
                     ((userVector[2] == answerVector[1]) && (checkAnswerVector[1] == 0)) ||
                     ((userVector[2] == answerVector[2]) && (checkAnswerVector[2] == 0)) ||
                     ((userVector[2] == answerVector[3]) && (checkAnswerVector[3] == 0))  ) && (checkUserVector[2] == 0) )
             {
                 clueVector.push_back("?");
                 
                 checkUserVector[2] = 1;  //toggle the userInput state
                 
                 if (userVector[2] == answerVector[0]) { //toggle the answer state
                     checkAnswerVector[0] = 1;
                 }
                 else if (userVector[2] == answerVector[1]){
                     checkAnswerVector[1] = 1;
                 }
                 else if (userVector[2] == answerVector[2]){
                     checkAnswerVector[2] = 1;
                 }
                 else if (userVector[2] == answerVector[3]){
                     checkAnswerVector[3] = 1;
                 }
                 
             }
             
             //
             //                      Fourth element check :
             //
             //
             
             if ( (  ((userVector[3] == answerVector[0]) && (checkAnswerVector[0] == 0)) ||
                     ((userVector[3] == answerVector[1]) && (checkAnswerVector[1] == 0)) ||
                     ((userVector[3] == answerVector[2]) && (checkAnswerVector[2] == 0)) ||
                     ((userVector[3] == answerVector[3]) && (checkAnswerVector[3] == 0))  ) && (checkUserVector[3] == 0) )
             {
                 clueVector.push_back("?");
                 
                 checkUserVector[3] = 1;  //toggle the userInput state
                 
                 if (userVector[3] == answerVector[0]) { //toggle the answer state
                     checkAnswerVector[0] = 1;
                 }
                 else if (userVector[3] == answerVector[1]){
                     checkAnswerVector[1] = 1;
                 }
                 else if (userVector[3] == answerVector[2]){
                     checkAnswerVector[2] = 1;
                 }
                 else if (userVector[3] == answerVector[3]){
                     checkAnswerVector[3] = 1;
                 }
                 
             }

            //Output the clue:
             cout<<"\n   CLUE: ";
             for (int i = 0; i < clueVector.size(); i++) {
                 cout << clueVector[i] << " ";
             }
            
            //Check if the Player win and execute current game:
            if( ((userVector[0] == answerVector[0])) &&
            ((userVector[1] == answerVector[1])) &&
            ((userVector[2] == answerVector[2]) ) &&
            ((userVector[3] == answerVector[3])) ) {
            
            //toggle the gameState:
            GameState = 1 ;
            cout << "\n\n   YOU WIN! You break the code!!!\n\n";
            board_currentState = 1;
            board_currentPoints = 0;
            board_currentPoints += 100;
            break;
            }
        
          }
            //Execute the game if player runs out of turns:
            if(GameState!= 1){
                board_currentState = 0;
                board_currentPoints = 0;
                board_currentPoints -= 50;
                cout << "\nSorry, you have run out of turns, you lose!\n\n";
            }

}
void MediumNumberBoard::BoardStartNum(){

    // gameState identifier:
    int GameState = 0;
    
    //generate random answer:
        vector<int> answerVector;
        srand((unsigned)time(NULL));
        int a = 4;
        for (int i = 0; i < a; i++){
            int b = rand() % 4 + 1;
            answerVector.push_back(b);
            //output the answer to user:
            //cout << answerVector[i] <<" ";
        }
        cout <<"\n\n\n";


    //let user inputs:
    //
    //CHANCES THAT PLAYER HAVE:
    //
        for (int i = 0; i < 8; i++) {
            cout << "\n  ||  please enter your " << i+1 << " guess:  ||  \n";
            int input;
            int counter = 0;
            vector<int> userVector;

                for (int i = 0; counter < 4; i++) {
                    cout << "  ||  ";
                    cin >> input;
                    if ((input >= 0) && (input <=4)){
                    userVector.push_back(input);
                    counter ++;
                    }
                    else {
                    cout <<  "please enter a valid number!";
                    }
                    
                }


            vector<string> clueVector;

            vector<int> checkAnswerVector = {0,0,0,0}; //checkerVector is for checking if the answer has been checked
             vector<int> checkUserVector =   {0,0,0,0}; //checkerUserInput is for checking if the user input has been checked

             
             
             //
             //                      Begin Checking "o" statement:
             //
             //
             
             
             
             //check first input:
             if ( userVector[0] == answerVector[0]){
                 checkAnswerVector[0] = 1; //toggle the state for answer
                 checkUserVector[0]   = 1; //toggle the state for user
                 clueVector.push_back("o");
             }

             
             //Check second input:
             if ( userVector[1] == answerVector[1]){
                    checkAnswerVector[1] = 1;
                    checkUserVector[1] = 1;
                    clueVector.push_back("o");
                }

             
             
             //Check third input:
             if ( userVector[2] == answerVector[2]){
                    checkAnswerVector[2] = 1;
                    checkUserVector[2] = 1;
                    clueVector.push_back("o");
                }
            
             
             //Check fourth input:
             if ( userVector[3] == answerVector[3]){
                    checkAnswerVector[3] = 1;
                    checkUserVector[3] = 1;
                    clueVector.push_back("o");
                }

             
             //
             //                      Begin Checking "?" statement:
             //
             //
             
             
             
             //
             //                      First element check :
             //
             //
            cout<<"\n";
             if ( (  ((userVector[0] == answerVector[0]) && (checkAnswerVector[0] == 0)) ||
                     ((userVector[0] == answerVector[1]) && (checkAnswerVector[1] == 0)) ||
                     ((userVector[0] == answerVector[2]) && (checkAnswerVector[2] == 0)) ||
                     ((userVector[0] == answerVector[3]) && (checkAnswerVector[3] == 0))  ) && (checkUserVector[0] == 0) )
             {

                 clueVector.push_back("?");
                 
                 checkUserVector[0] = 1;  //toggle the userInput state
                 
                 if (userVector[0] == answerVector[0]) { //toggle the answer state
                     checkAnswerVector[0] = 1;
                 }
                 else if (userVector[0] == answerVector[1]){
                     checkAnswerVector[1] = 1;
                 }
                 else if (userVector[0] == answerVector[2]){
                     checkAnswerVector[2] = 1;
                 }
                 else if (userVector[0] == answerVector[3]){
                     checkAnswerVector[3] = 1;
                 }
                 
             }

             
             
             //
             //                      Second element check :
             //
             //
             if ( (  ((userVector[1] == answerVector[0]) && (checkAnswerVector[0] == 0)) ||
                     ((userVector[1] == answerVector[1]) && (checkAnswerVector[1] == 0)) ||
                     ((userVector[1] == answerVector[2]) && (checkAnswerVector[2] == 0)) ||
                     ((userVector[1] == answerVector[3]) && (checkAnswerVector[3] == 0))  ) && (checkUserVector[1] == 0) )
             {

                 clueVector.push_back("?");
                 
                 checkUserVector[1] = 1;  //toggle the userInput state
                 
                 if (userVector[1] == answerVector[0]) { //toggle the answer state
                     checkAnswerVector[0] = 1;
                 }
                 else if (userVector[1] == answerVector[1]){
                     checkAnswerVector[1] = 1;
                 }
                 else if (userVector[1] == answerVector[2]){
                     checkAnswerVector[2] = 1;
                 }
                 else if (userVector[1] == answerVector[3]){
                     checkAnswerVector[3] = 1;
                 }
                 
             }

             //
             //                      Third element check :
             //
             //
             if ( (  ((userVector[2] == answerVector[0]) && (checkAnswerVector[0] == 0)) ||
                     ((userVector[2] == answerVector[1]) && (checkAnswerVector[1] == 0)) ||
                     ((userVector[2] == answerVector[2]) && (checkAnswerVector[2] == 0)) ||
                     ((userVector[2] == answerVector[3]) && (checkAnswerVector[3] == 0))  ) && (checkUserVector[2] == 0) )
             {
                 clueVector.push_back("?");
                 
                 checkUserVector[2] = 1;  //toggle the userInput state
                 
                 if (userVector[2] == answerVector[0]) { //toggle the answer state
                     checkAnswerVector[0] = 1;
                 }
                 else if (userVector[2] == answerVector[1]){
                     checkAnswerVector[1] = 1;
                 }
                 else if (userVector[2] == answerVector[2]){
                     checkAnswerVector[2] = 1;
                 }
                 else if (userVector[2] == answerVector[3]){
                     checkAnswerVector[3] = 1;
                 }
                 
             }
             
             //
             //                      Fourth element check :
             //
             //
             
             if ( (  ((userVector[3] == answerVector[0]) && (checkAnswerVector[0] == 0)) ||
                     ((userVector[3] == answerVector[1]) && (checkAnswerVector[1] == 0)) ||
                     ((userVector[3] == answerVector[2]) && (checkAnswerVector[2] == 0)) ||
                     ((userVector[3] == answerVector[3]) && (checkAnswerVector[3] == 0))  ) && (checkUserVector[3] == 0) )
             {
                 clueVector.push_back("?");
                 
                 checkUserVector[3] = 1;  //toggle the userInput state
                 
                 if (userVector[3] == answerVector[0]) { //toggle the answer state
                     checkAnswerVector[0] = 1;
                 }
                 else if (userVector[3] == answerVector[1]){
                     checkAnswerVector[1] = 1;
                 }
                 else if (userVector[3] == answerVector[2]){
                     checkAnswerVector[2] = 1;
                 }
                 else if (userVector[3] == answerVector[3]){
                     checkAnswerVector[3] = 1;
                 }
                 
             }

            //Output the clue:
             cout<<"\n   CLUE: ";
             for (int i = 0; i < clueVector.size(); i++) {
                 cout << clueVector[i] << " ";
             }
            
            //Check if the Player win and execute current game:
            if( ((userVector[0] == answerVector[0])) &&
            ((userVector[1] == answerVector[1])) &&
            ((userVector[2] == answerVector[2]) ) &&
            ((userVector[3] == answerVector[3])) ) {
                //toggle the gameState:
                    GameState = 1 ;
                    cout << "\n\n   YOU WIN! You break the code!!!\n\n";
                    board_currentState = 1;
                    board_currentPoints = 0;
                    board_currentPoints += 300;
                    break;
                    }
                
                  }
                    //Execute the game if player runs out of turns:
                    if(GameState!= 1){
                        board_currentState = 0;
                        board_currentPoints = 0;
                        board_currentPoints -= 150;
                        cout << "\nSorry, you have run out of turns, you lose!\n\n";
                
                    }

}
void HardNumberBoard::BoardStartNum(){

    // gameState identifier:
    int GameState = 0;
    //generate random answer:
        vector<int> answerVector;
        srand((unsigned)time(NULL));
        int a = 4;
        for (int i = 0; i < a; i++){
            int b = rand() % 4 + 1;
            answerVector.push_back(b);
            //output the answer to user:
            //cout << answerVector[i] <<" ";
        }
        cout <<"\n\n\n";


    //let user inputs:
    //
    //CHANCES THAT PLAYER HAVE:
    //
        for (int i = 0; i < 5; i++) {
            cout << "\n  ||  please enter your " << i+1 << " guess:  ||  \n";
            int input;
            int counter = 0;
            vector<int> userVector;

                for (int i = 0; counter < 4; i++) {
                    cout << "  ||  ";
                    cin >> input;
                    if ((input >= 0) && (input <=4)){
                    userVector.push_back(input);
                    counter ++;
                    }
                    else {
                    cout <<  "please enter a valid number!";
                    }
                    
                }


            vector<string> clueVector;

            vector<int> checkAnswerVector = {0,0,0,0}; //checkerVector is for checking if the answer has been checked
             vector<int> checkUserVector =   {0,0,0,0}; //checkerUserInput is for checking if the user input has been checked

             
             
             //
             //                      Begin Checking "o" statement:
             //
             //
             
             
             
             //check first input:
             if ( userVector[0] == answerVector[0]){
                 checkAnswerVector[0] = 1; //toggle the state for answer
                 checkUserVector[0]   = 1; //toggle the state for user
                 clueVector.push_back("o");
             }

             
             //Check second input:
             if ( userVector[1] == answerVector[1]){
                    checkAnswerVector[1] = 1;
                    checkUserVector[1] = 1;
                    clueVector.push_back("o");
                }

             
             
             //Check third input:
             if ( userVector[2] == answerVector[2]){
                    checkAnswerVector[2] = 1;
                    checkUserVector[2] = 1;
                    clueVector.push_back("o");
                }
            
             
             //Check fourth input:
             if ( userVector[3] == answerVector[3]){
                    checkAnswerVector[3] = 1;
                    checkUserVector[3] = 1;
                    clueVector.push_back("o");
                }

             
             //
             //                      Begin Checking "?" statement:
             //
             //
             
             
             
             //
             //                      First element check :
             //
             //
            cout<<"\n";
             if ( (  ((userVector[0] == answerVector[0]) && (checkAnswerVector[0] == 0)) ||
                     ((userVector[0] == answerVector[1]) && (checkAnswerVector[1] == 0)) ||
                     ((userVector[0] == answerVector[2]) && (checkAnswerVector[2] == 0)) ||
                     ((userVector[0] == answerVector[3]) && (checkAnswerVector[3] == 0))  ) && (checkUserVector[0] == 0) )
             {

                 clueVector.push_back("?");
                 
                 checkUserVector[0] = 1;  //toggle the userInput state
                 
                 if (userVector[0] == answerVector[0]) { //toggle the answer state
                     checkAnswerVector[0] = 1;
                 }
                 else if (userVector[0] == answerVector[1]){
                     checkAnswerVector[1] = 1;
                 }
                 else if (userVector[0] == answerVector[2]){
                     checkAnswerVector[2] = 1;
                 }
                 else if (userVector[0] == answerVector[3]){
                     checkAnswerVector[3] = 1;
                 }
                 
             }

             
             
             //
             //                      Second element check :
             //
             //
             if ( (  ((userVector[1] == answerVector[0]) && (checkAnswerVector[0] == 0)) ||
                     ((userVector[1] == answerVector[1]) && (checkAnswerVector[1] == 0)) ||
                     ((userVector[1] == answerVector[2]) && (checkAnswerVector[2] == 0)) ||
                     ((userVector[1] == answerVector[3]) && (checkAnswerVector[3] == 0))  ) && (checkUserVector[1] == 0) )
             {

                 clueVector.push_back("?");
                 
                 checkUserVector[1] = 1;  //toggle the userInput state
                 
                 if (userVector[1] == answerVector[0]) { //toggle the answer state
                     checkAnswerVector[0] = 1;
                 }
                 else if (userVector[1] == answerVector[1]){
                     checkAnswerVector[1] = 1;
                 }
                 else if (userVector[1] == answerVector[2]){
                     checkAnswerVector[2] = 1;
                 }
                 else if (userVector[1] == answerVector[3]){
                     checkAnswerVector[3] = 1;
                 }
                 
             }

             //
             //                      Third element check :
             //
             //
             if ( (  ((userVector[2] == answerVector[0]) && (checkAnswerVector[0] == 0)) ||
                     ((userVector[2] == answerVector[1]) && (checkAnswerVector[1] == 0)) ||
                     ((userVector[2] == answerVector[2]) && (checkAnswerVector[2] == 0)) ||
                     ((userVector[2] == answerVector[3]) && (checkAnswerVector[3] == 0))  ) && (checkUserVector[2] == 0) )
             {
                 clueVector.push_back("?");
                 
                 checkUserVector[2] = 1;  //toggle the userInput state
                 
                 if (userVector[2] == answerVector[0]) { //toggle the answer state
                     checkAnswerVector[0] = 1;
                 }
                 else if (userVector[2] == answerVector[1]){
                     checkAnswerVector[1] = 1;
                 }
                 else if (userVector[2] == answerVector[2]){
                     checkAnswerVector[2] = 1;
                 }
                 else if (userVector[2] == answerVector[3]){
                     checkAnswerVector[3] = 1;
                 }
                 
             }
             
             //
             //                      Fourth element check :
             //
             //
             
             if ( (  ((userVector[3] == answerVector[0]) && (checkAnswerVector[0] == 0)) ||
                     ((userVector[3] == answerVector[1]) && (checkAnswerVector[1] == 0)) ||
                     ((userVector[3] == answerVector[2]) && (checkAnswerVector[2] == 0)) ||
                     ((userVector[3] == answerVector[3]) && (checkAnswerVector[3] == 0))  ) && (checkUserVector[3] == 0) )
             {
                 clueVector.push_back("?");
                 
                 checkUserVector[3] = 1;  //toggle the userInput state
                 
                 if (userVector[3] == answerVector[0]) { //toggle the answer state
                     checkAnswerVector[0] = 1;
                 }
                 else if (userVector[3] == answerVector[1]){
                     checkAnswerVector[1] = 1;
                 }
                 else if (userVector[3] == answerVector[2]){
                     checkAnswerVector[2] = 1;
                 }
                 else if (userVector[3] == answerVector[3]){
                     checkAnswerVector[3] = 1;
                 }
                 
             }

            //Output the clue:
             cout<<"\n   CLUE: ";
             for (int i = 0; i < clueVector.size(); i++) {
                 cout << clueVector[i] << " ";
             }
            
            //Check if the Player win and execute current game:
            if( ((userVector[0] == answerVector[0])) &&
            ((userVector[1] == answerVector[1])) &&
            ((userVector[2] == answerVector[2]) ) &&
            ((userVector[3] == answerVector[3])) ) {
                //toggle the gameState:
                    GameState = 1 ;
                    cout << "\n\n   YOU WIN! You break the code!!!\n\n";
                    board_currentState = 1;
                    board_currentPoints = 0;
                    board_currentPoints += 500;
                    break;
                    }
                
                  }
                    //Execute the game if player runs out of turns:
                    if(GameState!= 1){
                        board_currentState = 0;
                        board_currentPoints = 0;
                        board_currentPoints -= 250;
                        cout << "\nSorry, you have run out of turns, you lose!\n\n";
                
                    }

}



void EasyCharBoard::BoardStartChar(){

         // gameState identifier:
         int GameState = 0;
         char letter;
         int randomNum;
        
             vector<char> answerVector;
             srand((unsigned)time(NULL));
         
         
         
             
             for (int i = 0; i < 4; i++){
                 
                 randomNum = rand() % 4;   // generate a random number
                 letter = 'a' + randomNum;
                 answerVector.push_back(letter);
                 //output the answer to user:
                 //cout << answerVector[i] <<" ";;
             }
             cout <<"\n\n\n";


         
         
         
         
         //let user inputs:
             for (int i = 0; i < 12; i++) { //user guess chances
                 cout << "\n  ||  please enter your " << i+1 << " guess:  ||  \n";
                 char input;
                 int counter = 0;
                 vector<char> userVector;
                 
             
                     for (int i = 0; counter < 4; i++) {
                         cout << "  ||  ";
                         cin >> input;
                         
                         
                         if ((input=='a')||(input=='b')||(input=='c')||(input=='d')){
                         userVector.push_back(input);
                         counter ++;
                         }
                         
                         
                         else {
                         cout <<  "please enter a valid letters!";
                         }
                     }


                 vector<string> clueVector;

                 vector<int> checkAnswerVector = {0,0,0,0}; //checkerVector is for checking if the answer has been checked
                  vector<int> checkUserVector  = {0,0,0,0}; //checkerUserInput is for checking if the user input has been checked

                  
                  
                  //
                  //                      Begin Checking "o" statement:
                  //
                  //
                  
                  
                  
                  //check first input:
                  if ( userVector[0] == answerVector[0]){
                      checkAnswerVector[0] = 1; //toggle the state for answer
                      checkUserVector[0]   = 1; //toggle the state for user
                      clueVector.push_back("o");
                  }

                  
                  //Check second input:
                  if ( userVector[1] == answerVector[1]){
                         checkAnswerVector[1] = 1;
                         checkUserVector[1] = 1;
                         clueVector.push_back("o");
                     }

                  
                  
                  //Check third input:
                  if ( userVector[2] == answerVector[2]){
                         checkAnswerVector[2] = 1;
                         checkUserVector[2] = 1;
                         clueVector.push_back("o");
                     }
                 
                  
                  //Check fourth input:
                  if ( userVector[3] == answerVector[3]){
                         checkAnswerVector[3] = 1;
                         checkUserVector[3] = 1;
                         clueVector.push_back("o");
                     }

                  
                  //
                  //                      Begin Checking "?" statement:
                  //
                  //
                  
                  
                  
                  //
                  //                      First element check :
                  //
                  //
                 cout<<"\n";
                  if ( (  ((userVector[0] == answerVector[0]) && (checkAnswerVector[0] == 0)) ||
                          ((userVector[0] == answerVector[1]) && (checkAnswerVector[1] == 0)) ||
                          ((userVector[0] == answerVector[2]) && (checkAnswerVector[2] == 0)) ||
                          ((userVector[0] == answerVector[3]) && (checkAnswerVector[3] == 0))  ) && (checkUserVector[0] == 0) )
                  {

                      clueVector.push_back("?");
                      
                      checkUserVector[0] = 1;  //toggle the userInput state
                      
                      if (userVector[0] == answerVector[0]) { //toggle the answer state
                          checkAnswerVector[0] = 1;
                      }
                      else if (userVector[0] == answerVector[1]){
                          checkAnswerVector[1] = 1;
                      }
                      else if (userVector[0] == answerVector[2]){
                          checkAnswerVector[2] = 1;
                      }
                      else if (userVector[0] == answerVector[3]){
                          checkAnswerVector[3] = 1;
                      }
                      
                  }

                  
                  
                  //
                  //                      Second element check :
                  //
                  //
                  if ( (  ((userVector[1] == answerVector[0]) && (checkAnswerVector[0] == 0)) ||
                          ((userVector[1] == answerVector[1]) && (checkAnswerVector[1] == 0)) ||
                          ((userVector[1] == answerVector[2]) && (checkAnswerVector[2] == 0)) ||
                          ((userVector[1] == answerVector[3]) && (checkAnswerVector[3] == 0))  ) && (checkUserVector[1] == 0) )
                  {

                      clueVector.push_back("?");
                      
                      checkUserVector[1] = 1;  //toggle the userInput state
                      
                      if (userVector[1] == answerVector[0]) { //toggle the answer state
                          checkAnswerVector[0] = 1;
                      }
                      else if (userVector[1] == answerVector[1]){
                          checkAnswerVector[1] = 1;
                      }
                      else if (userVector[1] == answerVector[2]){
                          checkAnswerVector[2] = 1;
                      }
                      else if (userVector[1] == answerVector[3]){
                          checkAnswerVector[3] = 1;
                      }
                      
                  }

                  //
                  //                      Third element check :
                  //
                  //
                  if ( (  ((userVector[2] == answerVector[0]) && (checkAnswerVector[0] == 0)) ||
                          ((userVector[2] == answerVector[1]) && (checkAnswerVector[1] == 0)) ||
                          ((userVector[2] == answerVector[2]) && (checkAnswerVector[2] == 0)) ||
                          ((userVector[2] == answerVector[3]) && (checkAnswerVector[3] == 0))  ) && (checkUserVector[2] == 0) )
                  {
                      clueVector.push_back("?");
                      
                      checkUserVector[2] = 1;  //toggle the userInput state
                      
                      if (userVector[2] == answerVector[0]) { //toggle the answer state
                          checkAnswerVector[0] = 1;
                      }
                      else if (userVector[2] == answerVector[1]){
                          checkAnswerVector[1] = 1;
                      }
                      else if (userVector[2] == answerVector[2]){
                          checkAnswerVector[2] = 1;
                      }
                      else if (userVector[2] == answerVector[3]){
                          checkAnswerVector[3] = 1;
                      }
                      
                  }
                  
                  //
                  //                      Fourth element check :
                  //
                  //
                  
                  if ( (  ((userVector[3] == answerVector[0]) && (checkAnswerVector[0] == 0)) ||
                          ((userVector[3] == answerVector[1]) && (checkAnswerVector[1] == 0)) ||
                          ((userVector[3] == answerVector[2]) && (checkAnswerVector[2] == 0)) ||
                          ((userVector[3] == answerVector[3]) && (checkAnswerVector[3] == 0))  ) && (checkUserVector[3] == 0) )
                  {
                      clueVector.push_back("?");
                      
                      checkUserVector[3] = 1;  //toggle the userInput state
                      
                      if (userVector[3] == answerVector[0]) { //toggle the answer state
                          checkAnswerVector[0] = 1;
                      }
                      else if (userVector[3] == answerVector[1]){
                          checkAnswerVector[1] = 1;
                      }
                      else if (userVector[3] == answerVector[2]){
                          checkAnswerVector[2] = 1;
                      }
                      else if (userVector[3] == answerVector[3]){
                          checkAnswerVector[3] = 1;
                      }
                      
                  }

                 //output clue:
                  cout<<"\n   CLUE: ";
                  for (int i = 0; i < clueVector.size(); i++) {
                      cout << clueVector[i] << " ";
                  }
                 
                 
                 //Check if the Player win and execute current game:
                         if( ((userVector[0] == answerVector[0])) &&
                         ((userVector[1] == answerVector[1])) &&
                         ((userVector[2] == answerVector[2]) ) &&
                         ((userVector[3] == answerVector[3])) ) {
                             //toggle the gameState:
                                 GameState = 1 ;
                                 cout << "\n\n   YOU WIN! You break the code!!!\n\n";
                                 board_currentState = 1;
                                 board_currentPoints = 0;
                                 board_currentPoints += 100;
                                 break;
                                 }
                             
                               }
                                 //Execute the game if player runs out of turns:
                                 if(GameState!= 1){
                                     board_currentState = 0;
                                     board_currentPoints = 0;
                                     board_currentPoints -= 50;
                                     cout << "\nSorry, you have run out of turns, you lose!\n\n";
                             
                                 }
         

}
void MediumCharBoard::BoardStartChar(){

     // gameState identifier:
     int GameState = 0;
     char letter;
     int randomNum;
    
         vector<char> answerVector;
         srand((unsigned)time(NULL));
     
     
     
         
         for (int i = 0; i < 4; i++){
             
             randomNum = rand() % 4;   // generate a random number
             letter = 'a' + randomNum;
             answerVector.push_back(letter);
             //output the answer to user:
             //cout << answerVector[i] <<" ";
         }
         cout <<"\n\n\n";


     
     
     
     
     //let user inputs:
         for (int i = 0; i < 8; i++) { //user guess chances
             cout << "\n  ||  please enter your " << i+1 << " guess:  ||  \n";
             char input;
             int counter = 0;
             vector<char> userVector;
             
         
                 for (int i = 0; counter < 4; i++) {
                     cout << "  ||  ";
                     cin >> input;
                     
                     
                     if ((input=='a')||(input=='b')||(input=='c')||(input=='d')){
                     userVector.push_back(input);
                     counter ++;
                     }
                     
                     
                     else {
                     cout <<  "please enter a valid letters!";
                     }
                 }


             vector<string> clueVector;

             vector<int> checkAnswerVector = {0,0,0,0}; //checkerVector is for checking if the answer has been checked
              vector<int> checkUserVector =   {0,0,0,0}; //checkerUserInput is for checking if the user input has been checked

              
              
              //
              //                      Begin Checking "o" statement:
              //
              //
              
              
              
              //check first input:
              if ( userVector[0] == answerVector[0]){
                  checkAnswerVector[0] = 1; //toggle the state for answer
                  checkUserVector[0]   = 1; //toggle the state for user
                  clueVector.push_back("o");
              }

              
              //Check second input:
              if ( userVector[1] == answerVector[1]){
                     checkAnswerVector[1] = 1;
                     checkUserVector[1] = 1;
                     clueVector.push_back("o");
                 }

              
              
              //Check third input:
              if ( userVector[2] == answerVector[2]){
                     checkAnswerVector[2] = 1;
                     checkUserVector[2] = 1;
                     clueVector.push_back("o");
                 }
             
              
              //Check fourth input:
              if ( userVector[3] == answerVector[3]){
                     checkAnswerVector[3] = 1;
                     checkUserVector[3] = 1;
                     clueVector.push_back("o");
                 }

              
              //
              //                      Begin Checking "?" statement:
              //
              //
              
              
              
              //
              //                      First element check :
              //
              //
             cout<<"\n";
              if ( (  ((userVector[0] == answerVector[0]) && (checkAnswerVector[0] == 0)) ||
                      ((userVector[0] == answerVector[1]) && (checkAnswerVector[1] == 0)) ||
                      ((userVector[0] == answerVector[2]) && (checkAnswerVector[2] == 0)) ||
                      ((userVector[0] == answerVector[3]) && (checkAnswerVector[3] == 0))  ) && (checkUserVector[0] == 0) )
              {

                  clueVector.push_back("?");
                  
                  checkUserVector[0] = 1;  //toggle the userInput state
                  
                  if (userVector[0] == answerVector[0]) { //toggle the answer state
                      checkAnswerVector[0] = 1;
                  }
                  else if (userVector[0] == answerVector[1]){
                      checkAnswerVector[1] = 1;
                  }
                  else if (userVector[0] == answerVector[2]){
                      checkAnswerVector[2] = 1;
                  }
                  else if (userVector[0] == answerVector[3]){
                      checkAnswerVector[3] = 1;
                  }
                  
              }

              
              
              //
              //                      Second element check :
              //
              //
              if ( (  ((userVector[1] == answerVector[0]) && (checkAnswerVector[0] == 0)) ||
                      ((userVector[1] == answerVector[1]) && (checkAnswerVector[1] == 0)) ||
                      ((userVector[1] == answerVector[2]) && (checkAnswerVector[2] == 0)) ||
                      ((userVector[1] == answerVector[3]) && (checkAnswerVector[3] == 0))  ) && (checkUserVector[1] == 0) )
              {

                  clueVector.push_back("?");
                  
                  checkUserVector[1] = 1;  //toggle the userInput state
                  
                  if (userVector[1] == answerVector[0]) { //toggle the answer state
                      checkAnswerVector[0] = 1;
                  }
                  else if (userVector[1] == answerVector[1]){
                      checkAnswerVector[1] = 1;
                  }
                  else if (userVector[1] == answerVector[2]){
                      checkAnswerVector[2] = 1;
                  }
                  else if (userVector[1] == answerVector[3]){
                      checkAnswerVector[3] = 1;
                  }
                  
              }

              //
              //                      Third element check :
              //
              //
              if ( (  ((userVector[2] == answerVector[0]) && (checkAnswerVector[0] == 0)) ||
                      ((userVector[2] == answerVector[1]) && (checkAnswerVector[1] == 0)) ||
                      ((userVector[2] == answerVector[2]) && (checkAnswerVector[2] == 0)) ||
                      ((userVector[2] == answerVector[3]) && (checkAnswerVector[3] == 0))  ) && (checkUserVector[2] == 0) )
              {
                  clueVector.push_back("?");
                  
                  checkUserVector[2] = 1;  //toggle the userInput state
                  
                  if (userVector[2] == answerVector[0]) { //toggle the answer state
                      checkAnswerVector[0] = 1;
                  }
                  else if (userVector[2] == answerVector[1]){
                      checkAnswerVector[1] = 1;
                  }
                  else if (userVector[2] == answerVector[2]){
                      checkAnswerVector[2] = 1;
                  }
                  else if (userVector[2] == answerVector[3]){
                      checkAnswerVector[3] = 1;
                  }
                  
              }
              
              //
              //                      Fourth element check :
              //
              //
              
              if ( (  ((userVector[3] == answerVector[0]) && (checkAnswerVector[0] == 0)) ||
                      ((userVector[3] == answerVector[1]) && (checkAnswerVector[1] == 0)) ||
                      ((userVector[3] == answerVector[2]) && (checkAnswerVector[2] == 0)) ||
                      ((userVector[3] == answerVector[3]) && (checkAnswerVector[3] == 0))  ) && (checkUserVector[3] == 0) )
              {
                  clueVector.push_back("?");
                  
                  checkUserVector[3] = 1;  //toggle the userInput state
                  
                  if (userVector[3] == answerVector[0]) { //toggle the answer state
                      checkAnswerVector[0] = 1;
                  }
                  else if (userVector[3] == answerVector[1]){
                      checkAnswerVector[1] = 1;
                  }
                  else if (userVector[3] == answerVector[2]){
                      checkAnswerVector[2] = 1;
                  }
                  else if (userVector[3] == answerVector[3]){
                      checkAnswerVector[3] = 1;
                  }
                  
              }

             
              cout<<"\n   CLUE: ";
              for (int i = 0; i < clueVector.size(); i++) {
                  cout << clueVector[i] << " ";
              }
             
             
             //Check if the Player win and execute current game:
                     if( ((userVector[0] == answerVector[0])) &&
                     ((userVector[1] == answerVector[1])) &&
                     ((userVector[2] == answerVector[2]) ) &&
                     ((userVector[3] == answerVector[3])) ) {
                         //toggle the gameState:
                             GameState = 1 ;
                             cout << "\n\n   YOU WIN! You break the code!!!\n\n";
                             board_currentState = 1;
                             board_currentPoints = 0;
                             board_currentPoints += 300;
                             break;
                             }
                         
                           }
                             //Execute the game if player runs out of turns:
                             if(GameState!= 1){
                                 board_currentState = 0;
                                 board_currentPoints = 0;
                                 board_currentPoints -= 150;
                                 cout << "\nSorry, you have run out of turns, you lose!\n\n";
                             }
     

}
void HardCharBoard::BoardStartChar(){

     // gameState identifier:
     int GameState = 0;
     char letter;
     int randomNum;
    
         vector<char> answerVector;
         srand((unsigned)time(NULL));
     
     
     
         
         for (int i = 0; i < 4; i++){
             
             randomNum = rand() % 4;   // generate a random number
             letter = 'a' + randomNum;
             answerVector.push_back(letter);
             //output the answer to user:
             //cout << answerVector[i] <<" ";
         }
         cout <<"\n\n\n";


     
     
     
     
     //let user inputs:
         for (int i = 0; i < 5; i++) { //user guess chances
             cout << "\n  ||  please enter your " << i+1 << " guess:  ||  \n";
             char input;
             int counter = 0;
             vector<char> userVector;
             
         
                 for (int i = 0; counter < 4; i++) {
                     cout << "  ||  ";
                     cin >> input;
                     
                     
                     if ((input=='a')||(input=='b')||(input=='c')||(input=='d')){
                     userVector.push_back(input);
                     counter ++;
                     }
                     
                     
                     else {
                     cout <<  "please enter a valid letters!";
                     }
                 }


             vector<string> clueVector;

             vector<int> checkAnswerVector = {0,0,0,0}; //checkerVector is for checking if the answer has been checked
              vector<int> checkUserVector =   {0,0,0,0}; //checkerUserInput is for checking if the user input has been checked

              
              
              //
              //                      Begin Checking "o" statement:
              //
              //
              
              
              
              //check first input:
              if ( userVector[0] == answerVector[0]){
                  checkAnswerVector[0] = 1; //toggle the state for answer
                  checkUserVector[0]   = 1; //toggle the state for user
                  clueVector.push_back("o");
              }

              
              //Check second input:
              if ( userVector[1] == answerVector[1]){
                     checkAnswerVector[1] = 1;
                     checkUserVector[1] = 1;
                     clueVector.push_back("o");
                 }

              
              
              //Check third input:
              if ( userVector[2] == answerVector[2]){
                     checkAnswerVector[2] = 1;
                     checkUserVector[2] = 1;
                     clueVector.push_back("o");
                 }
             
              
              //Check fourth input:
              if ( userVector[3] == answerVector[3]){
                     checkAnswerVector[3] = 1;
                     checkUserVector[3] = 1;
                     clueVector.push_back("o");
                 }

              
              //
              //                      Begin Checking "?" statement:
              //
              //
              
              
              
              //
              //                      First element check :
              //
              //
             cout<<"\n";
              if ( (  ((userVector[0] == answerVector[0]) && (checkAnswerVector[0] == 0)) ||
                      ((userVector[0] == answerVector[1]) && (checkAnswerVector[1] == 0)) ||
                      ((userVector[0] == answerVector[2]) && (checkAnswerVector[2] == 0)) ||
                      ((userVector[0] == answerVector[3]) && (checkAnswerVector[3] == 0))  ) && (checkUserVector[0] == 0) )
              {

                  clueVector.push_back("?");
                  
                  checkUserVector[0] = 1;  //toggle the userInput state
                  
                  if (userVector[0] == answerVector[0]) { //toggle the answer state
                      checkAnswerVector[0] = 1;
                  }
                  else if (userVector[0] == answerVector[1]){
                      checkAnswerVector[1] = 1;
                  }
                  else if (userVector[0] == answerVector[2]){
                      checkAnswerVector[2] = 1;
                  }
                  else if (userVector[0] == answerVector[3]){
                      checkAnswerVector[3] = 1;
                  }
                  
              }

              
              
              //
              //                      Second element check :
              //
              //
              if ( (  ((userVector[1] == answerVector[0]) && (checkAnswerVector[0] == 0)) ||
                      ((userVector[1] == answerVector[1]) && (checkAnswerVector[1] == 0)) ||
                      ((userVector[1] == answerVector[2]) && (checkAnswerVector[2] == 0)) ||
                      ((userVector[1] == answerVector[3]) && (checkAnswerVector[3] == 0))  ) && (checkUserVector[1] == 0) )
              {

                  clueVector.push_back("?");
                  
                  checkUserVector[1] = 1;  //toggle the userInput state
                  
                  if (userVector[1] == answerVector[0]) { //toggle the answer state
                      checkAnswerVector[0] = 1;
                  }
                  else if (userVector[1] == answerVector[1]){
                      checkAnswerVector[1] = 1;
                  }
                  else if (userVector[1] == answerVector[2]){
                      checkAnswerVector[2] = 1;
                  }
                  else if (userVector[1] == answerVector[3]){
                      checkAnswerVector[3] = 1;
                  }
                  
              }

              //
              //                      Third element check :
              //
              //
              if ( (  ((userVector[2] == answerVector[0]) && (checkAnswerVector[0] == 0)) ||
                      ((userVector[2] == answerVector[1]) && (checkAnswerVector[1] == 0)) ||
                      ((userVector[2] == answerVector[2]) && (checkAnswerVector[2] == 0)) ||
                      ((userVector[2] == answerVector[3]) && (checkAnswerVector[3] == 0))  ) && (checkUserVector[2] == 0) )
              {
                  clueVector.push_back("?");
                  
                  checkUserVector[2] = 1;  //toggle the userInput state
                  
                  if (userVector[2] == answerVector[0]) { //toggle the answer state
                      checkAnswerVector[0] = 1;
                  }
                  else if (userVector[2] == answerVector[1]){
                      checkAnswerVector[1] = 1;
                  }
                  else if (userVector[2] == answerVector[2]){
                      checkAnswerVector[2] = 1;
                  }
                  else if (userVector[2] == answerVector[3]){
                      checkAnswerVector[3] = 1;
                  }
                  
              }
              
              //
              //                      Fourth element check :
              //
              //
              
              if ( (  ((userVector[3] == answerVector[0]) && (checkAnswerVector[0] == 0)) ||
                      ((userVector[3] == answerVector[1]) && (checkAnswerVector[1] == 0)) ||
                      ((userVector[3] == answerVector[2]) && (checkAnswerVector[2] == 0)) ||
                      ((userVector[3] == answerVector[3]) && (checkAnswerVector[3] == 0))  ) && (checkUserVector[3] == 0) )
              {
                  clueVector.push_back("?");
                  
                  checkUserVector[3] = 1;  //toggle the userInput state
                  
                  if (userVector[3] == answerVector[0]) { //toggle the answer state
                      checkAnswerVector[0] = 1;
                  }
                  else if (userVector[3] == answerVector[1]){
                      checkAnswerVector[1] = 1;
                  }
                  else if (userVector[3] == answerVector[2]){
                      checkAnswerVector[2] = 1;
                  }
                  else if (userVector[3] == answerVector[3]){
                      checkAnswerVector[3] = 1;
                  }
                  
              }

             
              cout<<"\n   CLUE: ";
              for (int i = 0; i < clueVector.size(); i++) {
                  cout << clueVector[i] << " ";
              }
             
             
             //Check if the Player win and execute current game:
                     if( ((userVector[0] == answerVector[0])) &&
                     ((userVector[1] == answerVector[1])) &&
                     ((userVector[2] == answerVector[2]) ) &&
                     ((userVector[3] == answerVector[3])) ) {
                         
                         //toggle the gameState:
                             GameState = 1 ;
                             cout << "\n\n   YOU WIN! You break the code!!!\n\n";
                             board_currentState = 1;
                             board_currentPoints = 0;
                             board_currentPoints += 500;
                             break;
                             }
                         
                           }
                             //Execute the game if player runs out of turns:
                             if(GameState!= 1){
                                 board_currentState = 0;
                                 board_currentPoints = 0;
                                 board_currentPoints -= 250;
                                 cout << "\nSorry, you have run out of turns, you lose!\n\n";
                         
                             }
     

}




void EasySymbolBoard::BoardStartSymbol(){

          
         
         // gameState identifier:
          int GameState = 0;
          vector<string> answerVector;
          string str;
          char randomSymbol[] ="#$*@";
          int LengthOfString = sizeof(randomSymbol) - 1;
          //random generator:
          srand((unsigned)time(NULL));
          //generate secret code:
          for( int i = 0; i < 4; ++i){
          str = randomSymbol[rand() % LengthOfString];
              answerVector.push_back(str);
                         //output the answer to user:
                         //cout << answerVector[i] <<" ";
          }
          cout <<"\n\n\n";
          
    
    
    
          //let user inputs:
              for (int i = 0; i < 12; i++) { //user guess chances
                  cout << "\n  ||  please enter your " << i+1 << " guess:  ||  \n";
                  string input;
                  int counter = 0;
                  vector<string> userVector;
                  
              
                      for (int i = 0; counter < 4; i++) {
                          cout << "  ||  ";
                          cin >> input;
                          
                          
                          if ((input=="#")||(input=="$")||(input=="*")||(input=="@")){
                          userVector.push_back(input);
                          counter ++;
                          }
                          
                          
                          else {
                          cout <<  "please enter a valid symbol!";
                          }
                      }


                  vector<string> clueVector;

                  vector<int> checkAnswerVector = {0,0,0,0}; //checkerVector is for checking if the answer has been checked
                   vector<int> checkUserVector =   {0,0,0,0}; //checkerUserInput is for checking if the user input has been checked

                   
                   
                   //
                   //                      Begin Checking "o" statement:
                   //
                   //
                   
                   
                   
                   //check first input:
                   if ( userVector[0] == answerVector[0]){
                       checkAnswerVector[0] = 1; //toggle the state for answer
                       checkUserVector[0]   = 1; //toggle the state for user
                       clueVector.push_back("o");
                   }

                   
                   //Check second input:
                   if ( userVector[1] == answerVector[1]){
                          checkAnswerVector[1] = 1;
                          checkUserVector[1] = 1;
                          clueVector.push_back("o");
                      }

                   
                   
                   //Check third input:
                   if ( userVector[2] == answerVector[2]){
                          checkAnswerVector[2] = 1;
                          checkUserVector[2] = 1;
                          clueVector.push_back("o");
                      }
                  
                   
                   //Check fourth input:
                   if ( userVector[3] == answerVector[3]){
                          checkAnswerVector[3] = 1;
                          checkUserVector[3] = 1;
                          clueVector.push_back("o");
                      }

                   
                   //
                   //                      Begin Checking "?" statement:
                   //
                   //
                   
                   
                   
                   //
                   //                      First element check :
                   //
                   //
                  cout<<"\n";
                   if ( (  ((userVector[0] == answerVector[0]) && (checkAnswerVector[0] == 0)) ||
                           ((userVector[0] == answerVector[1]) && (checkAnswerVector[1] == 0)) ||
                           ((userVector[0] == answerVector[2]) && (checkAnswerVector[2] == 0)) ||
                           ((userVector[0] == answerVector[3]) && (checkAnswerVector[3] == 0))  ) && (checkUserVector[0] == 0) )
                   {

                       clueVector.push_back("?");
                       
                       checkUserVector[0] = 1;  //toggle the userInput state
                       
                       if (userVector[0] == answerVector[0]) { //toggle the answer state
                           checkAnswerVector[0] = 1;
                       }
                       else if (userVector[0] == answerVector[1]){
                           checkAnswerVector[1] = 1;
                       }
                       else if (userVector[0] == answerVector[2]){
                           checkAnswerVector[2] = 1;
                       }
                       else if (userVector[0] == answerVector[3]){
                           checkAnswerVector[3] = 1;
                       }
                       
                   }

                   
                   
                   //
                   //                      Second element check :
                   //
                   //
                   if ( (  ((userVector[1] == answerVector[0]) && (checkAnswerVector[0] == 0)) ||
                           ((userVector[1] == answerVector[1]) && (checkAnswerVector[1] == 0)) ||
                           ((userVector[1] == answerVector[2]) && (checkAnswerVector[2] == 0)) ||
                           ((userVector[1] == answerVector[3]) && (checkAnswerVector[3] == 0))  ) && (checkUserVector[1] == 0) )
                   {

                       clueVector.push_back("?");
                       
                       checkUserVector[1] = 1;  //toggle the userInput state
                       
                       if (userVector[1] == answerVector[0]) { //toggle the answer state
                           checkAnswerVector[0] = 1;
                       }
                       else if (userVector[1] == answerVector[1]){
                           checkAnswerVector[1] = 1;
                       }
                       else if (userVector[1] == answerVector[2]){
                           checkAnswerVector[2] = 1;
                       }
                       else if (userVector[1] == answerVector[3]){
                           checkAnswerVector[3] = 1;
                       }
                       
                   }

                   //
                   //                      Third element check :
                   //
                   //
                   if ( (  ((userVector[2] == answerVector[0]) && (checkAnswerVector[0] == 0)) ||
                           ((userVector[2] == answerVector[1]) && (checkAnswerVector[1] == 0)) ||
                           ((userVector[2] == answerVector[2]) && (checkAnswerVector[2] == 0)) ||
                           ((userVector[2] == answerVector[3]) && (checkAnswerVector[3] == 0))  ) && (checkUserVector[2] == 0) )
                   {
                       clueVector.push_back("?");
                       
                       checkUserVector[2] = 1;  //toggle the userInput state
                       
                       if (userVector[2] == answerVector[0]) { //toggle the answer state
                           checkAnswerVector[0] = 1;
                       }
                       else if (userVector[2] == answerVector[1]){
                           checkAnswerVector[1] = 1;
                       }
                       else if (userVector[2] == answerVector[2]){
                           checkAnswerVector[2] = 1;
                       }
                       else if (userVector[2] == answerVector[3]){
                           checkAnswerVector[3] = 1;
                       }
                       
                   }
                   
                   //
                   //                      Fourth element check :
                   //
                   //
                   
                   if ( (  ((userVector[3] == answerVector[0]) && (checkAnswerVector[0] == 0)) ||
                           ((userVector[3] == answerVector[1]) && (checkAnswerVector[1] == 0)) ||
                           ((userVector[3] == answerVector[2]) && (checkAnswerVector[2] == 0)) ||
                           ((userVector[3] == answerVector[3]) && (checkAnswerVector[3] == 0))  ) && (checkUserVector[3] == 0) )
                   {
                       clueVector.push_back("?");
                       
                       checkUserVector[3] = 1;  //toggle the userInput state
                       
                       if (userVector[3] == answerVector[0]) { //toggle the answer state
                           checkAnswerVector[0] = 1;
                       }
                       else if (userVector[3] == answerVector[1]){
                           checkAnswerVector[1] = 1;
                       }
                       else if (userVector[3] == answerVector[2]){
                           checkAnswerVector[2] = 1;
                       }
                       else if (userVector[3] == answerVector[3]){
                           checkAnswerVector[3] = 1;
                       }
                       
                   }

                  
                   cout<<"\n   CLUE: ";
                   for (int i = 0; i < clueVector.size(); i++) {
                       cout << clueVector[i] << " ";
                   }
                  
                               //Check if the Player win and execute current game:
                          if( ((userVector[0] == answerVector[0])) &&
                          ((userVector[1] == answerVector[1])) &&
                          ((userVector[2] == answerVector[2]) ) &&
                          ((userVector[3] == answerVector[3])) ) {
                              //toggle the gameState:
                                  GameState = 1 ;
                                  cout << "\n\n   YOU WIN! You break the code!!!\n\n";
                                  board_currentState = 1;
                                  board_currentPoints = 0;
                                  board_currentPoints += 100;
                                  break;
                                  }
                              
                                }
                                  //Execute the game if player runs out of turns:
                                  if(GameState!= 1){
                                      board_currentState = 0;
                                      board_currentPoints = 0;
                                      board_currentPoints -= 50;
                                      cout << "\nSorry, you have run out of turns, you lose!\n\n";
                              
                                  }

}
void MediumSymbolBoard::BoardStartSymbol(){

          
         
         // gameState identifier:
          int GameState = 0;
          vector<string> answerVector;
          string str;
          char randomSymbol[] ="#$*@";
          int LengthOfString = sizeof(randomSymbol) - 1;
          //random generator:
          srand((unsigned)time(NULL));
          //generate secret code:
          for( int i = 0; i < 4; ++i){
          str = randomSymbol[rand() % LengthOfString];
              answerVector.push_back(str);
                         //output the answer to user:
                         //cout << answerVector[i] <<" ";
          }
          cout <<"\n\n\n";
          
    
    
    
          //let user inputs:
              for (int i = 0; i < 8; i++) { //user guess chances
                  cout << "\n  ||  please enter your " << i+1 << " guess:  ||  \n";
                  string input;
                  int counter = 0;
                  vector<string> userVector;
                  
              
                      for (int i = 0; counter < 4; i++) {
                          cout << "  ||  ";
                          cin >> input;
                          
                          
                          if ((input=="#")||(input=="$")||(input=="*")||(input=="@")){
                          userVector.push_back(input);
                          counter ++;
                          }
                          
                          
                          else {
                          cout <<  "please enter a valid symbol!";
                          }
                      }


                  vector<string> clueVector;

                  vector<int> checkAnswerVector = {0,0,0,0}; //checkerVector is for checking if the answer has been checked
                   vector<int> checkUserVector =   {0,0,0,0}; //checkerUserInput is for checking if the user input has been checked

                   
                   
                   //
                   //                      Begin Checking "o" statement:
                   //
                   //
                   
                   
                   
                   //check first input:
                   if ( userVector[0] == answerVector[0]){
                       checkAnswerVector[0] = 1; //toggle the state for answer
                       checkUserVector[0]   = 1; //toggle the state for user
                       clueVector.push_back("o");
                   }

                   
                   //Check second input:
                   if ( userVector[1] == answerVector[1]){
                          checkAnswerVector[1] = 1;
                          checkUserVector[1] = 1;
                          clueVector.push_back("o");
                      }

                   
                   
                   //Check third input:
                   if ( userVector[2] == answerVector[2]){
                          checkAnswerVector[2] = 1;
                          checkUserVector[2] = 1;
                          clueVector.push_back("o");
                      }
                  
                   
                   //Check fourth input:
                   if ( userVector[3] == answerVector[3]){
                          checkAnswerVector[3] = 1;
                          checkUserVector[3] = 1;
                          clueVector.push_back("o");
                      }

                   
                   //
                   //                      Begin Checking "?" statement:
                   //
                   //
                   
                   
                   
                   //
                   //                      First element check :
                   //
                   //
                  cout<<"\n";
                   if ( (  ((userVector[0] == answerVector[0]) && (checkAnswerVector[0] == 0)) ||
                           ((userVector[0] == answerVector[1]) && (checkAnswerVector[1] == 0)) ||
                           ((userVector[0] == answerVector[2]) && (checkAnswerVector[2] == 0)) ||
                           ((userVector[0] == answerVector[3]) && (checkAnswerVector[3] == 0))  ) && (checkUserVector[0] == 0) )
                   {

                       clueVector.push_back("?");
                       
                       checkUserVector[0] = 1;  //toggle the userInput state
                       
                       if (userVector[0] == answerVector[0]) { //toggle the answer state
                           checkAnswerVector[0] = 1;
                       }
                       else if (userVector[0] == answerVector[1]){
                           checkAnswerVector[1] = 1;
                       }
                       else if (userVector[0] == answerVector[2]){
                           checkAnswerVector[2] = 1;
                       }
                       else if (userVector[0] == answerVector[3]){
                           checkAnswerVector[3] = 1;
                       }
                       
                   }

                   
                   
                   //
                   //                      Second element check :
                   //
                   //
                   if ( (  ((userVector[1] == answerVector[0]) && (checkAnswerVector[0] == 0)) ||
                           ((userVector[1] == answerVector[1]) && (checkAnswerVector[1] == 0)) ||
                           ((userVector[1] == answerVector[2]) && (checkAnswerVector[2] == 0)) ||
                           ((userVector[1] == answerVector[3]) && (checkAnswerVector[3] == 0))  ) && (checkUserVector[1] == 0) )
                   {

                       clueVector.push_back("?");
                       
                       checkUserVector[1] = 1;  //toggle the userInput state
                       
                       if (userVector[1] == answerVector[0]) { //toggle the answer state
                           checkAnswerVector[0] = 1;
                       }
                       else if (userVector[1] == answerVector[1]){
                           checkAnswerVector[1] = 1;
                       }
                       else if (userVector[1] == answerVector[2]){
                           checkAnswerVector[2] = 1;
                       }
                       else if (userVector[1] == answerVector[3]){
                           checkAnswerVector[3] = 1;
                       }
                       
                   }

                   //
                   //                      Third element check :
                   //
                   //
                   if ( (  ((userVector[2] == answerVector[0]) && (checkAnswerVector[0] == 0)) ||
                           ((userVector[2] == answerVector[1]) && (checkAnswerVector[1] == 0)) ||
                           ((userVector[2] == answerVector[2]) && (checkAnswerVector[2] == 0)) ||
                           ((userVector[2] == answerVector[3]) && (checkAnswerVector[3] == 0))  ) && (checkUserVector[2] == 0) )
                   {
                       clueVector.push_back("?");
                       
                       checkUserVector[2] = 1;  //toggle the userInput state
                       
                       if (userVector[2] == answerVector[0]) { //toggle the answer state
                           checkAnswerVector[0] = 1;
                       }
                       else if (userVector[2] == answerVector[1]){
                           checkAnswerVector[1] = 1;
                       }
                       else if (userVector[2] == answerVector[2]){
                           checkAnswerVector[2] = 1;
                       }
                       else if (userVector[2] == answerVector[3]){
                           checkAnswerVector[3] = 1;
                       }
                       
                   }
                   
                   //
                   //                      Fourth element check :
                   //
                   //
                   
                   if ( (  ((userVector[3] == answerVector[0]) && (checkAnswerVector[0] == 0)) ||
                           ((userVector[3] == answerVector[1]) && (checkAnswerVector[1] == 0)) ||
                           ((userVector[3] == answerVector[2]) && (checkAnswerVector[2] == 0)) ||
                           ((userVector[3] == answerVector[3]) && (checkAnswerVector[3] == 0))  ) && (checkUserVector[3] == 0) )
                   {
                       clueVector.push_back("?");
                       
                       checkUserVector[3] = 1;  //toggle the userInput state
                       
                       if (userVector[3] == answerVector[0]) { //toggle the answer state
                           checkAnswerVector[0] = 1;
                       }
                       else if (userVector[3] == answerVector[1]){
                           checkAnswerVector[1] = 1;
                       }
                       else if (userVector[3] == answerVector[2]){
                           checkAnswerVector[2] = 1;
                       }
                       else if (userVector[3] == answerVector[3]){
                           checkAnswerVector[3] = 1;
                       }
                       
                   }

                  
                   cout<<"\n   CLUE: ";
                   for (int i = 0; i < clueVector.size(); i++) {
                       cout << clueVector[i] << " ";
                   }
                  
                               //Check if the Player win and execute current game:
                          if( ((userVector[0] == answerVector[0])) &&
                          ((userVector[1] == answerVector[1])) &&
                          ((userVector[2] == answerVector[2]) ) &&
                          ((userVector[3] == answerVector[3])) ) {
                              //toggle the gameState:
                                  GameState = 1 ;
                                  cout << "\n\n   YOU WIN! You break the code!!!\n\n";
                                  board_currentState = 1;
                                  board_currentPoints = 0;
                                  board_currentPoints += 300;
                                  break;
                                  }
                              
                                }
                                  //Execute the game if player runs out of turns:
                                  if(GameState!= 1){
                                      board_currentState = 0;
                                      board_currentPoints = 0;
                                      board_currentPoints -= 150;
                                      cout << "\nSorry, you have run out of turns, you lose!\n\n";
                              
                                  }

}
void HardSymbolBoard::BoardStartSymbol(){

          
         
         // gameState identifier:
          int GameState = 0;
          vector<string> answerVector;
          string str;
          char randomSymbol[] ="#$*@";
          int LengthOfString = sizeof(randomSymbol) - 1;
          //random generator:
          srand((unsigned)time(NULL));
          //generate secret code:
          for( int i = 0; i < 4; ++i){
          str = randomSymbol[rand() % LengthOfString];
              answerVector.push_back(str);
                         //output the answer to user:
                         //cout << answerVector[i] <<" ";
          }
          cout <<"\n\n\n";
          
    
    
    
          //let user inputs:
              for (int i = 0; i < 5; i++) { //user guess chances
                  cout << "\n  ||  please enter your " << i+1 << " guess:  ||  \n";
                  string input;
                  int counter = 0;
                  vector<string> userVector;
                  
              
                      for (int i = 0; counter < 4; i++) {
                          cout << "  ||  ";
                          cin >> input;
                          
                          
                          if ((input=="#")||(input=="$")||(input=="*")||(input=="@")){
                          userVector.push_back(input);
                          counter ++;
                          }
                          
                          
                          else {
                          cout <<  "please enter a valid symbol!";
                          }
                      }


                  vector<string> clueVector;

                  vector<int> checkAnswerVector = {0,0,0,0}; //checkerVector is for checking if the answer has been checked
                   vector<int> checkUserVector =   {0,0,0,0}; //checkerUserInput is for checking if the user input has been checked

                   
                   
                   //
                   //                      Begin Checking "o" statement:
                   //
                   //
                   
                   
                   
                   //check first input:
                   if ( userVector[0] == answerVector[0]){
                       checkAnswerVector[0] = 1; //toggle the state for answer
                       checkUserVector[0]   = 1; //toggle the state for user
                       clueVector.push_back("o");
                   }

                   
                   //Check second input:
                   if ( userVector[1] == answerVector[1]){
                          checkAnswerVector[1] = 1;
                          checkUserVector[1] = 1;
                          clueVector.push_back("o");
                      }

                   
                   
                   //Check third input:
                   if ( userVector[2] == answerVector[2]){
                          checkAnswerVector[2] = 1;
                          checkUserVector[2] = 1;
                          clueVector.push_back("o");
                      }
                  
                   
                   //Check fourth input:
                   if ( userVector[3] == answerVector[3]){
                          checkAnswerVector[3] = 1;
                          checkUserVector[3] = 1;
                          clueVector.push_back("o");
                      }

                   
                   //
                   //                      Begin Checking "?" statement:
                   //
                   //
                   
                   
                   
                   //
                   //                      First element check :
                   //
                   //
                  cout<<"\n";
                   if ( (  ((userVector[0] == answerVector[0]) && (checkAnswerVector[0] == 0)) ||
                           ((userVector[0] == answerVector[1]) && (checkAnswerVector[1] == 0)) ||
                           ((userVector[0] == answerVector[2]) && (checkAnswerVector[2] == 0)) ||
                           ((userVector[0] == answerVector[3]) && (checkAnswerVector[3] == 0))  ) && (checkUserVector[0] == 0) )
                   {

                       clueVector.push_back("?");
                       
                       checkUserVector[0] = 1;  //toggle the userInput state
                       
                       if (userVector[0] == answerVector[0]) { //toggle the answer state
                           checkAnswerVector[0] = 1;
                       }
                       else if (userVector[0] == answerVector[1]){
                           checkAnswerVector[1] = 1;
                       }
                       else if (userVector[0] == answerVector[2]){
                           checkAnswerVector[2] = 1;
                       }
                       else if (userVector[0] == answerVector[3]){
                           checkAnswerVector[3] = 1;
                       }
                       
                   }

                   
                   
                   //
                   //                      Second element check :
                   //
                   //
                   if ( (  ((userVector[1] == answerVector[0]) && (checkAnswerVector[0] == 0)) ||
                           ((userVector[1] == answerVector[1]) && (checkAnswerVector[1] == 0)) ||
                           ((userVector[1] == answerVector[2]) && (checkAnswerVector[2] == 0)) ||
                           ((userVector[1] == answerVector[3]) && (checkAnswerVector[3] == 0))  ) && (checkUserVector[1] == 0) )
                   {

                       clueVector.push_back("?");
                       
                       checkUserVector[1] = 1;  //toggle the userInput state
                       
                       if (userVector[1] == answerVector[0]) { //toggle the answer state
                           checkAnswerVector[0] = 1;
                       }
                       else if (userVector[1] == answerVector[1]){
                           checkAnswerVector[1] = 1;
                       }
                       else if (userVector[1] == answerVector[2]){
                           checkAnswerVector[2] = 1;
                       }
                       else if (userVector[1] == answerVector[3]){
                           checkAnswerVector[3] = 1;
                       }
                       
                   }

                   //
                   //                      Third element check :
                   //
                   //
                   if ( (  ((userVector[2] == answerVector[0]) && (checkAnswerVector[0] == 0)) ||
                           ((userVector[2] == answerVector[1]) && (checkAnswerVector[1] == 0)) ||
                           ((userVector[2] == answerVector[2]) && (checkAnswerVector[2] == 0)) ||
                           ((userVector[2] == answerVector[3]) && (checkAnswerVector[3] == 0))  ) && (checkUserVector[2] == 0) )
                   {
                       clueVector.push_back("?");
                       
                       checkUserVector[2] = 1;  //toggle the userInput state
                       
                       if (userVector[2] == answerVector[0]) { //toggle the answer state
                           checkAnswerVector[0] = 1;
                       }
                       else if (userVector[2] == answerVector[1]){
                           checkAnswerVector[1] = 1;
                       }
                       else if (userVector[2] == answerVector[2]){
                           checkAnswerVector[2] = 1;
                       }
                       else if (userVector[2] == answerVector[3]){
                           checkAnswerVector[3] = 1;
                       }
                       
                   }
                   
                   //
                   //                      Fourth element check :
                   //
                   //
                   
                   if ( (  ((userVector[3] == answerVector[0]) && (checkAnswerVector[0] == 0)) ||
                           ((userVector[3] == answerVector[1]) && (checkAnswerVector[1] == 0)) ||
                           ((userVector[3] == answerVector[2]) && (checkAnswerVector[2] == 0)) ||
                           ((userVector[3] == answerVector[3]) && (checkAnswerVector[3] == 0))  ) && (checkUserVector[3] == 0) )
                   {
                       clueVector.push_back("?");
                       
                       checkUserVector[3] = 1;  //toggle the userInput state
                       
                       if (userVector[3] == answerVector[0]) { //toggle the answer state
                           checkAnswerVector[0] = 1;
                       }
                       else if (userVector[3] == answerVector[1]){
                           checkAnswerVector[1] = 1;
                       }
                       else if (userVector[3] == answerVector[2]){
                           checkAnswerVector[2] = 1;
                       }
                       else if (userVector[3] == answerVector[3]){
                           checkAnswerVector[3] = 1;
                       }
                       
                   }

                  
                   cout<<"\n   CLUE: ";
                   for (int i = 0; i < clueVector.size(); i++) {
                       cout << clueVector[i] << " ";
                   }
                  
                               //Check if the Player win and execute current game:
                          if( ((userVector[0] == answerVector[0])) &&
                          ((userVector[1] == answerVector[1])) &&
                          ((userVector[2] == answerVector[2]) ) &&
                          ((userVector[3] == answerVector[3])) ) {
                              //toggle the gameState:
                                  GameState = 1 ;
                                  cout << "\n\n   YOU WIN! You break the code!!!\n\n";
                                  board_currentState = 1;
                                  board_currentPoints = 0;
                                  board_currentPoints += 500;
                                  break;
                                  }
                              
                                }
                                  //Execute the game if player runs out of turns:
                                  if(GameState!= 1){
                                      board_currentState = 0;
                                      board_currentPoints = 0;
                                      board_currentPoints -= 250;
                                      cout << "\nSorry, you have run out of turns, you lose!\n\n";
                              
                                  }

}



