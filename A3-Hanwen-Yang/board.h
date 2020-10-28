#ifndef board_h
#define board_h

#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include "player.h"

using namespace std;

//Base class:
class Board{
    
    public:
    int board_Column;
    int board_Row;
    int board_caseLevel;
    int board_caseElement;
    int board_currentPoints;
    int board_currentState;
    
    
    explicit Board();
    explicit Board(int board_ColumnP, int board_RowP, int board_caseLevelP, int board_caseElementP, int board_currentPointsP, int currentStateP);
    ~Board();

    
};


//Nine inherited classes (INCLUDE mutiple and multilevel inheritance):

class EasyNumberBoard : public Board{
    public:
    void  BoardStartNum();
    using Board::Board;
};
class MediumNumberBoard : public EasyNumberBoard{
    public:
    void  BoardStartNum();
    using EasyNumberBoard::EasyNumberBoard;
};
class HardNumberBoard : public EasyNumberBoard{
    public:
    void  BoardStartNum();
    using EasyNumberBoard::EasyNumberBoard;
};




class EasyCharBoard : public Board{
public:
    void  BoardStartChar();
    using Board::Board;
};
class MediumCharBoard : public EasyCharBoard{
public:
     void  BoardStartChar();
    using EasyCharBoard::EasyCharBoard;
    
};
class HardCharBoard : public EasyCharBoard{
public:
     void  BoardStartChar();
    using EasyCharBoard::EasyCharBoard;
};




class EasySymbolBoard : public Board{
public:
     void  BoardStartSymbol();
     using Board::Board;
};
class MediumSymbolBoard : public EasySymbolBoard{
public:
    void  BoardStartSymbol();
    using EasySymbolBoard::EasySymbolBoard;
};
class HardSymbolBoard : public EasySymbolBoard{
public:
    void  BoardStartSymbol();
    using EasySymbolBoard::EasySymbolBoard;
};






#endif /* board_h */
