//
// Created by fbrate on 30/03/19.
//

#ifndef TICTACTOE_GROUP17_FINAL_PROJECT_BOARD_H
#define TICTACTOE_GROUP17_FINAL_PROJECT_BOARD_H

#include <string>
#include "globals.h"
#include "Player.h"

class Board {
private:
    enum Symbol{Available = 0, PlayerOne, PlayerTwo};
    int board[3][3];
    int turnCounter;
    bool roundEnded;
    int winner;
    int lineCounter;

    std::string *borderColor;
    std::string *sectionColor;
    std::string *backgroundColor;
    std::string *textOnBackgroundColor;
    std::string playerOneSymbolColor;
    std::string playerTwoSymbolColor;
    std::string *resetColor;
    std::string *selectionAvailableColor;
    std::string *selectionTakenColor;
    std::string infoBarPlayerOne;
    std::string infoBarPlayerTwo;
    std::string infoBarOverview;
    std::string infoBarScore;

    bool pOneTurn;
    bool pTwoTurn;
    Player *playerOne;
    Player *playerTwo;
    struct Position {
        int x;
        int y;
    };
    Position selectionPosition;
    Position wonMarkers[3];

    void gameWonOrDraw();
    void selectionMove(char);
    void addIntersectionGraphic(std::string*, std::string);
    std::string playerGetSymbolByLine(int *, int, int, int );
    void printGraphics();

public:
    Board(Player*, Player*, int, int, int, int);
    int startRound();
};


#endif //TICTACTOE_GROUP17_FINAL_PROJECT_BOARD_H
