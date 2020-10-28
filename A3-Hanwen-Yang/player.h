#ifndef player_h
#define player_h

#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>



using namespace std;


class Player{
    public:
    string playerName;
    int    playerCases;
    static int    playerSolvedCases;
    int    playerTotalPoints;
    static int playerFailedCases;
    
    Player();
    Player(string playerNameP,int playerCasesP,int playerSolvedCasesP,int playerTotalPointsP);
    ~Player();
    void setPlayerName(string newName);
    
    
};


#endif /* player_h */
