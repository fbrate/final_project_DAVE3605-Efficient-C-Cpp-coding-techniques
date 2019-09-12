//
// Created by fbrate on 30/03/19.
//

#include "Board_Frithjof_Brate_s336406.h"
#include "globals_Frithjof_Brate_s336406.h"
#include <string>
#include <vector>
#include <iostream>
#include <thread>

using std::string;
using std::cout;
using std::vector;
using std::endl;

//class Board::Board{

    // playerOneGoesFirst
    Board::Board(Player *pOne, Player *pTwo, int p1Score, int p2Score, int games, int maxGames){

            // fills the board with Available spots.
            for (int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; j++)
                {
                        board[i][j] = Available;
                }
            }
            lineCounter = 1;
            selectionPosition = {1, 1};
            roundEnded = false;
            turnCounter = 0;

            this->playerOne = pOne;
            this->playerTwo = pTwo;
            pOneTurn = true;
            pTwoTurn = false;
            playerOneSymbolColor = *globalBackgroundColors.bg+playerOne->getSymbolColor();
            playerTwoSymbolColor = *globalBackgroundColors.bg+playerTwo->getSymbolColor();



            // colors gathered from allcolors and globalBackgroundCOlors
            resetColor = &allColors.resetColor;
            borderColor = globalBackgroundColors.borderColor;
            sectionColor = globalBackgroundColors.sectionColor;
            selectionAvailableColor = &allColors.greenCombined;
            selectionTakenColor= &allColors.redCombined;
            backgroundColor = globalBackgroundColors.combined;
            textOnBackgroundColor = &globalBackgroundColors.normalTextOnBackground;

            // infobar -> displays score, and game number + player names on top of board.
            infoBarPlayerOne = pOne->getName();
            infoBarPlayerTwo = pTwo->getName();
            // make sure names are long enough to not destroy the asci art.
            while (infoBarPlayerOne.length() < 17)
            {
                    infoBarPlayerOne = " " +infoBarPlayerOne;
            }
            infoBarPlayerOne = *textOnBackgroundColor + infoBarPlayerOne;
            while (infoBarPlayerTwo.length() < 17)
            {
                    infoBarPlayerTwo = " " +infoBarPlayerTwo;
            }
            infoBarPlayerTwo = *textOnBackgroundColor + infoBarPlayerTwo;

            infoBarScore = playerOneSymbolColor + std::to_string(p1Score) + *textOnBackgroundColor+ " versus " +*resetColor+playerTwoSymbolColor+ std::to_string(p2Score);
            infoBarOverview = *textOnBackgroundColor+"Game: " +std::to_string(games)+ *textOnBackgroundColor +" out of " + std::to_string(maxGames);

    }

    void Board::gameWonOrDraw() {
            // Player going first need to have finished 3rd move or more to win.
            if(turnCounter >= 5)
            {
                        // last marker = selectionPosition;
                        // if won that marker will have winning symbol (type)
                        int type = board[selectionPosition.x][selectionPosition.y];

                        // check row
                        for (int i = 0; i <3; i++)
                        {
                                if(board[selectionPosition.x][i] != type)
                                {
                                        break;
                                }
                                if(i == 2)
                                {
                                        // 3 in a row here
                                        // set markers
                                        for (int ii = 0; ii <3; ii++) {
                                                wonMarkers[ii].x = selectionPosition.x;
                                                wonMarkers[ii].y = ii;
                                        }
                                        if(pOneTurn)
                                        {
                                                infoBarPlayerOne = *textOnBackgroundColor +"          Winner!";
                                                infoBarPlayerTwo = *textOnBackgroundColor+"           Loser!";
                                        }
                                        else if(pTwoTurn)
                                        {
                                                infoBarPlayerTwo = *textOnBackgroundColor+ "          Winner!";
                                                infoBarPlayerOne = *textOnBackgroundColor+ "           Loser!";
                                        }
                                        roundEnded = true;
                                        winner = type;
                                }
                        }
                        // check col:
                        for(int i = 0; i < 3; i++)
                        {
                                if(board[i][selectionPosition.y] != type)
                                {
                                        break;
                                }
                                if(i == 2)
                                {
                                        for (int ii = 0; ii <3; ii++) {
                                                wonMarkers[ii].x = ii;
                                                wonMarkers[ii].y = selectionPosition.y;
                                        }
                                        if(pOneTurn)
                                        {
                                                infoBarPlayerOne = *textOnBackgroundColor +"          Winner!";
                                                infoBarPlayerTwo = *textOnBackgroundColor +"           Loser!";
                                        }
                                        else if(pTwoTurn)
                                        {
                                                infoBarPlayerTwo = *textOnBackgroundColor +"          Winner!";
                                                infoBarPlayerOne = *textOnBackgroundColor +"           Loser!";
                                        }
                                        roundEnded = true;
                                        winner = type;

                                }
                        }

                    // check diag(top down left. // only if last marker was top left, bot right, or middle.
                    if((selectionPosition.x == 0 && selectionPosition.y == 0) ||
                       (selectionPosition.x == 2 && selectionPosition.y == 2) ||
                       (selectionPosition.x == 1 && selectionPosition.y == 1)) {

                            for (int i = 0; i < 3; i++) {

                                    if(board[i][i] != type)
                                    {
                                            break;
                                    }
                                    if(i == 2)
                                    {
                                            for (int ii = 0; ii <3; ii++) {
                                                    wonMarkers[ii].x = ii;
                                                    wonMarkers[ii].y = ii;
                                            }
                                            if(pOneTurn)
                                            {
                                                    infoBarPlayerOne = *textOnBackgroundColor +"          Winner!";
                                                    infoBarPlayerTwo = *textOnBackgroundColor +"           Loser!";
                                            }
                                            else if(pTwoTurn)
                                            {
                                                    infoBarPlayerTwo = *textOnBackgroundColor+"          Winner!";
                                                    infoBarPlayerOne = *textOnBackgroundColor+"           Loser!";
                                            }
                                            roundEnded = true;
                                            winner = type;

                                    }
                            }
                    }

                        // check antidiag bot up right// only if last marker was top right, bot left, middle
                        if((selectionPosition.x == 0 && selectionPosition.y == 2) ||
                        (selectionPosition.x == 2 && selectionPosition.y == 0) ||
                        (selectionPosition.x == 1 && selectionPosition.y == 1)) {

                                int j = 2;
                                for (int i = 0; i < 3; i++) {

                                                if(board[i][j] != type)
                                                {
                                                        break;
                                                }
                                                if(i == 2)
                                                {
                                                        j = 2;
                                                        for (int ii = 0; ii < 3; ii++) {


                                                                wonMarkers[ii].x = ii;
                                                                wonMarkers[ii].y = j;
                                                                j--;
                                                        }
                                                        if(pOneTurn)
                                                        {
                                                                infoBarPlayerOne = *textOnBackgroundColor +"          Winner!";
                                                                infoBarPlayerTwo = *textOnBackgroundColor +"           Loser!";
                                                        }
                                                        else if(pTwoTurn)
                                                        {
                                                                infoBarPlayerTwo = *textOnBackgroundColor +"          Winner!";
                                                                infoBarPlayerOne = *textOnBackgroundColor +"           Loser!";
                                                        }
                                                        roundEnded = true;
                                                        winner = type;

                                                }
                                                j--;
                                }
                        }
                        else if(turnCounter == 9 && !roundEnded)
                        {
                                infoBarPlayerOne = *textOnBackgroundColor +"            Draw!";
                                infoBarPlayerTwo = *textOnBackgroundColor +"            Draw!";
                                roundEnded = true;
                                pOneTurn = false;
                                pTwoTurn = false;
                                winner = Available;
                        }
            }
    }

    // moves the selection marker letting us place symbols.
    void Board::selectionMove(char key) {
            switch(key)
            {
                    // move north, but not out of bounds.
                    case 'w':
                            if(selectionPosition.x != 0)
                            {
                                    selectionPosition.x -= 1;
                            }
                            break;
                     // move south, but not out of bounds.
                    case 's':
                            if(selectionPosition.x != 2)
                            {
                                    selectionPosition.x += 1;
                            }
                            break;
                    //move east, but not out of bounds.
                    case 'd':
                            if(selectionPosition.y != 2)
                            {
                                    selectionPosition.y += 1;
                            }
                            break;
                    //move west, but not out of bounds.
                    case 'a':
                            if(selectionPosition.y != 0)
                            {
                                    selectionPosition.y -= 1;
                            }
                            break;
                    case 'x':
                            // if no other symbol, add the turn's player's symbol to the board.
                            if (board[selectionPosition.x][selectionPosition.y] == Available)
                            {
                                    turnCounter++;
                                    if(pOneTurn) {
                                            board[selectionPosition.x][selectionPosition.y] = PlayerOne;
                                            gameWonOrDraw();
                                            if(!roundEnded) {
                                                    pOneTurn = false;
                                                    pTwoTurn = true;
                                            }
                                    }
                                    else
                                    {
                                             board[selectionPosition.x][selectionPosition.y] = PlayerTwo;
                                             gameWonOrDraw();
                                            if(!roundEnded) {
                                                    pOneTurn = true;
                                                    pTwoTurn = false;
                                            }
                                    }

                            }

                    default:
                            break;
            }
    }


    // pulls together all the needed graphics for // make sure names are long enough to not destroy the asci art.each line one at a time.

    // most here is just lines | and upper and lowerscores: ___‾‾‾. This is to farm the "layout" of the board.
    // all the color calls are calling the correct color for that part of the board.

    // NB!! Colors are terminal dependent and may vary,
    // *resetColor resets the colors (foreground and background to default)
    // *borderColor sets the colors to black(ca). Used for the border, and seperation between board and playerArt
    // IMPORTANT:
    // +playerTwo->getAvatarByLine(lineCounter, pTwoTurn, *backgroundColor)
    // The line above is the one which calls the art from the Player class. The Background is passed along to match, and
    // a boolean determining whether the player should  be " highlighted" to indicate that it is that players turn.
    // the lineCounter tells what line from the player art graphic to return.

    // Every string append ends with *resetColor for good practice.
    void Board::addIntersectionGraphic(string *toPrintString, string intersectPos)
    {
            if(intersectPos == "infoBar")
            {
                    *toPrintString +="\n";
                    *toPrintString +=*resetColor+"                                                        "+*borderColor+"|‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾|"+*resetColor+"\n";
                    *toPrintString +=*borderColor+"|‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾|"+*resetColor+"   "+*borderColor+"|‾‾‾‾‾‾‾‾‾‾‾     __________      ‾‾‾‾‾‾‾‾‾‾‾|"+*resetColor+"   "+*borderColor+"|‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾|"
                                     +*resetColor +"\n";
                    *toPrintString += *borderColor +"|       _____________________________    ‾‾‾             ___|"+*resetColor+infoBarScore+*borderColor+"|___               ‾‾‾   ______________________________      |"+*resetColor+"\n";
                    *toPrintString += *borderColor+"|      |"+*backgroundColor+*resetColor+infoBarPlayerOne+*backgroundColor+"            "+*borderColor+"|                  |"+*backgroundColor+" "+*resetColor+infoBarOverview+*backgroundColor+"  "+*borderColor+"|                  |"+*backgroundColor+infoBarPlayerTwo+*backgroundColor+"             "+ *borderColor+"|     |"+    *resetColor+"\n";
            }
            // appends the Top horizontal part of the board.
            else if (intersectPos == "horTop")
            {

                    *toPrintString +=   *borderColor+
                            "|       ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾                    ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾                    ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾      |"
                            +*resetColor +"\n";

                    *toPrintString +=
                            *borderColor+ "|     "+"                                                                                                                              |"+
                            *resetColor +"\n";
                    *toPrintString += *borderColor+ "|   |"+*backgroundColor+"‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾"
                            +    *borderColor+"|   "+ *backgroundColor +"|‾‾‾‾‾‾‾‾‾‾‾|"+*sectionColor
                            +"   "+ *backgroundColor +"|‾‾‾‾‾‾‾‾‾‾‾|"+ *sectionColor +"   "+ *backgroundColor
                            +"|‾‾‾‾‾‾‾‾‾‾‾|"+*borderColor+"   |"+*backgroundColor+"‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾"+
                            *borderColor+"|   |"+ *resetColor+"\n";
                    lineCounter = 1;


            }
            // appends the middle intersections in the board. Called twice per graphics call.
            else if (intersectPos == "horDivider")
            {
                    *toPrintString +=   *borderColor+ "|   |"+*backgroundColor+" "+*resetColor +playerOne->getAvatarByLine(lineCounter, pOneTurn)+
                            *resetColor +*backgroundColor+" "+ *borderColor +"|   "+ *backgroundColor +"|___________|"+ *sectionColor +"   "
                            + *backgroundColor +"|___________|"+ *sectionColor +"   "+ *backgroundColor +"|___________|"+ *borderColor
                            +"   |"+ *backgroundColor +" "+*resetColor +playerTwo->getAvatarByLine(lineCounter, pTwoTurn)
                            +*resetColor +*backgroundColor+" "+*borderColor+"|   |"+*resetColor +"\n";
                    lineCounter++;

                    *toPrintString += *borderColor+ "|   |"+*backgroundColor+" "+*resetColor
                            +        playerOne->getAvatarByLine(lineCounter, pOneTurn) +*backgroundColor+" "+
                            *borderColor +"|   "+ *sectionColor+"                                             "+*borderColor+
                            "   |"+ *backgroundColor +" "+*resetColor +playerTwo->getAvatarByLine(lineCounter, pTwoTurn)
                            +*resetColor+*backgroundColor+" "+*borderColor+"|   |"+*resetColor +"\n";
                    lineCounter++;

                    *toPrintString += *borderColor+ "|   |"+*backgroundColor+" "+*resetColor
                            +        playerOne->getAvatarByLine(lineCounter, pOneTurn) +*backgroundColor
                            +" " +*borderColor +"|   "+ *backgroundColor +"|‾‾‾‾‾‾‾‾‾‾‾|"+ *sectionColor +"   "+ *backgroundColor
                            +"|‾‾‾‾‾‾‾‾‾‾‾|"+ *sectionColor +"   "+ *backgroundColor +"|‾‾‾‾‾‾‾‾‾‾‾|"+ *borderColor +"   |"+ *backgroundColor
                            +" "+*resetColor
                            +playerTwo->getAvatarByLine(lineCounter, pTwoTurn) +*backgroundColor+" "+*borderColor+"|   |"+*resetColor +"\n";
                    lineCounter++;

            }
            // appends the Bot part of the board.
            else if(intersectPos =="horBottom") {
                    *toPrintString +=
                            *borderColor+"|   |"+*backgroundColor+"___________________________________" + *borderColor + "|   "
                            +*backgroundColor+"|___________|" + *sectionColor + "   " +*backgroundColor + "|___________|"
                            + *sectionColor + "   " + *backgroundColor +"|___________|" + *borderColor + "   |"+*backgroundColor
                            +"___________________________________"+*borderColor+"|   |"+*resetColor +"\n";
                    *toPrintString +=
                    *borderColor+ "|                                                                                                                                   |"
                    +*resetColor +"\n";
                    *toPrintString +=*borderColor+ "|___________________________________________________________________________________________________________________________________|"
                            +        *resetColor +"\n";
                    *toPrintString += *textOnBackgroundColor +"               Move using w, a, s, d. Place symbol by pressing x. Each keystroke should be followed by ENTER                       :"+ *resetColor;


            }
                    // all of these are called as seperators on each line for the printet symbols |# | # |# |
            // left edge of board.
            else if(intersectPos == "vertDivStart")
            {

                    *toPrintString += *borderColor+ "|   |"+*backgroundColor+" "+*resetColor
                            +        playerOne->getAvatarByLine(lineCounter, pOneTurn)+*resetColor
                            +*backgroundColor+" "+*borderColor+"|   "+*backgroundColor+"| "+*resetColor;
            }
            // in the middle of board
            else if(intersectPos == "vertDiv"){
                    *toPrintString += *backgroundColor+" |"+*sectionColor+"   "+*backgroundColor+"| " + *resetColor; // start and vert div
            }
            // right side of the board.
            else if(intersectPos == "vertDivEnd")
            {


                    *toPrintString += *backgroundColor+" |"+*borderColor+"   |"+*backgroundColor+" "+*resetColor
                            +        playerTwo->getAvatarByLine(lineCounter, pTwoTurn) +*backgroundColor+" "
                            +*borderColor+"|   |"+*resetColor;
            }

    }

void Board::printGraphics(){

        string *stringToPrint = new string;
        addIntersectionGraphic(stringToPrint, "infoBar");
        addIntersectionGraphic(stringToPrint, "horTop");

        // Loops through x values of board[x][y]
        for (int row = 0; row < 3; row++) {
                // Controller to store values for the symbols.
                // since each symbol's graphic consist of a 5x5 net
                // One and one line has to be printed for the correct asci art.
                // it is not possible to print a 9x7 figure, then jump back up the line 1.
                vector<int> rowLineController;
                rowLineController.reserve(3);
                for (int col = 0; col < 3; col++) {
                        rowLineController.push_back(board[row][col]);
                }

                // for each of the 5 lines get that lines graphic.
                for (int line = 1; line <= 7; line++) {


                        // Line prefix
                        // lineCOunter ++
                        addIntersectionGraphic(stringToPrint, "vertDivStart"); // should add prefix
                        // once for each "token" on each tic tac toe row.

                        for (int col = 0; col < rowLineController.size(); col++) {


                                //*stringToPrint+=" |   | "; // start and vert div
                                if(col != 0) {

                                        addIntersectionGraphic(stringToPrint, "vertDiv");

                                }

                                *stringToPrint += playerGetSymbolByLine(&rowLineController.at(col), line, row, col);


                        }
                        addIntersectionGraphic(stringToPrint, "vertDivEnd");
                        lineCounter++;
                        *stringToPrint += "\n";

                }
                if(row != 2) {
                        addIntersectionGraphic(stringToPrint, "horDivider");
                }
                else
                {
                        addIntersectionGraphic(stringToPrint, "horBottom");
                }
        }
        cout << *stringToPrint;

}




    string Board::playerGetSymbolByLine(int *symbol, int line, int i, int j)
    {
            string * selectionOutline = &*backgroundColor;
            string selectTopBot = "         ";
            string selectSingle = " ";
            // if selector on this position, and if round not over -> Show the marker
            if (i == selectionPosition.x && j == selectionPosition.y && !roundEnded)
            {

                    selectTopBot = "#########";
                    selectSingle = "#"; // how # as seleciton marker. WIll be hidden if colors are enabled.
                    if(*symbol != 0)
                    {
                            selectionOutline = &*selectionTakenColor;

                    }
                    else
                    {
                            selectionOutline = &*selectionAvailableColor;

                    }
            }
            // if game is over, Show the winmarkers if there is some // will be none in case of draw.
            else if(roundEnded)
            {
                    for (Position pos : wonMarkers)
                    {
                            if(pos.x == i && pos.y == j)
                            {
                                    selectTopBot = "#########";
                                    selectSingle = "#"; // how # as seleciton marker. WIll be hidden if colors are enabled.
                                    selectionOutline = &*selectionAvailableColor;

                            }
                    }
            }


            switch (*symbol) {
                    case Available:
                            switch (line) {
                                    case 1:
                                            return *selectionOutline + selectTopBot+*resetColor;
                                    case 2:
                                            return *selectionOutline+selectSingle+*backgroundColor+"       "
                                                   +*selectionOutline+selectSingle+*resetColor;
                                    case 3:
                                            return *selectionOutline+selectSingle+*backgroundColor+"       "
                                            +*selectionOutline+selectSingle+*resetColor;
                                    case 4:
                                            return *selectionOutline+selectSingle+*backgroundColor+"       "
                                            +*selectionOutline+selectSingle+*resetColor;
                                    case 5:
                                            return *selectionOutline+selectSingle+*backgroundColor+"       "
                                            +*selectionOutline+selectSingle+*resetColor;
                                    case 6:
                                            return *selectionOutline+selectSingle+*backgroundColor+"       "
                                            +*selectionOutline+selectSingle+*resetColor;
                                    case 7:
                                            return *selectionOutline + selectTopBot+*resetColor;
                                    default:
                                            exit(-1);
                            }
                    case PlayerOne:

                            switch (line) {
                                    case 1:
                                            return *selectionOutline+selectTopBot+*resetColor;
                                    case 2:
                                            return *selectionOutline+selectSingle+*backgroundColor+" "
                                            +playerOneSymbolColor+"¤"+*backgroundColor+"   "+playerOneSymbolColor+"¤"
                                            +*backgroundColor+" "+*selectionOutline+selectSingle+*resetColor;
                                    case 3:
                                            return *selectionOutline+selectSingle+*backgroundColor+"  "
                                            +playerOneSymbolColor+"¤"+*backgroundColor+" "+playerOneSymbolColor+"¤"
                                            +*backgroundColor+"  "+*selectionOutline+selectSingle+*resetColor;
                                    case 4:
                                            return *selectionOutline+selectSingle+*backgroundColor+"   "
                                            +playerOneSymbolColor+"¤"+*backgroundColor+"   "+*selectionOutline+selectSingle+*resetColor;
                                    case 5:
                                            return *selectionOutline+selectSingle+*backgroundColor+"  "+playerOneSymbolColor
                                            +"¤"+*backgroundColor+" "+playerOneSymbolColor+"¤"+*backgroundColor+"  "
                                            +*selectionOutline+selectSingle+*resetColor;
                                    case 6:
                                            return *selectionOutline+selectSingle+*backgroundColor+" "+playerOneSymbolColor
                                            +"¤"+*backgroundColor+"   "+playerOneSymbolColor+"¤"+*backgroundColor+" "
                                            +*selectionOutline+selectSingle+*resetColor;
                                    case 7:
                                            return *selectionOutline+selectTopBot+*resetColor;
                                    default:
                                            exit(-1);
                            }

        {

        }

                    case PlayerTwo:
                            switch (line) {
                                    case 1:
                                            return *selectionOutline+selectTopBot+*resetColor;
                                    case 2:
                                            return *selectionOutline+selectSingle+*backgroundColor+"  "+playerTwoSymbolColor+
                                            "¤¤¤"+*backgroundColor+"  "+*selectionOutline+selectSingle+*resetColor;
                                    case 3:
                                            return *selectionOutline+selectSingle+*backgroundColor+" "+playerTwoSymbolColor+
                                            "¤"+*backgroundColor+"   "+playerTwoSymbolColor+"¤"+*backgroundColor+" "
                                            +*selectionOutline+selectSingle+*resetColor;
                                    case 4:
                                            return *selectionOutline+selectSingle+*backgroundColor+" "+playerTwoSymbolColor+
                                            "¤"+*backgroundColor+" "+playerTwoSymbolColor+"¤"+*backgroundColor+" "
                                            +playerTwoSymbolColor+"¤"+*backgroundColor+" "+*selectionOutline+selectSingle+*resetColor;
                                    case 5:
                                            return *selectionOutline+selectSingle+*backgroundColor+" "+playerTwoSymbolColor+
                                            "¤"+*backgroundColor+"   "+playerTwoSymbolColor+"¤"+*backgroundColor+" "
                                            +*selectionOutline+selectSingle+*resetColor;
                                    case 6:
                                            return *selectionOutline+selectSingle+*backgroundColor+"  "+playerTwoSymbolColor+
                                            "¤¤¤"+*backgroundColor+"  "+*selectionOutline+selectSingle+*resetColor;
                                    case 7:
                                            return *selectionOutline+selectTopBot+*resetColor;

                                    default:
                                            exit(-1);
                            }

                    default:
                            exit(-1);

            }

    }

     int Board::startRound(){

            clearScreen();
            while(!roundEnded)
            {
                    printGraphics();
                    char * direction = new char;
                    std::cin >> *direction;

                    selectionMove(*direction);
                    clearScreen();
            }

            printGraphics();
            std::this_thread::sleep_for(std::chrono::milliseconds(2500));
            return winner;

    }



    // check for win


