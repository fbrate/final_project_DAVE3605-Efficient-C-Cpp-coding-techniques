#include <iostream>
#include <string>
#include "Board_Frithjof_Brate_s336406.h"
#include "globals_Frithjof_Brate_s336406.h"
#include "ArtAndColorFunctions_Frithjof_Brate_s336406.h"
#include <chrono>
#include <thread>


using std::cout;
using std::string;
using std::vector;


Player addPlayer();
void startGame(Player *, Player *);
int main(){


        colorChecker();
        Player playerOne = addPlayer();
        Player playerTwo = addPlayer();
        startGame(&playerOne, &playerTwo);
        char * answ =  new char;
        bool play = true;

        // answers after callDrawArt or callWinArt
        // those calls are last things called by startGame
        while(play)
        {
                std::cin >> answ;
                if(*answ == 'y')
                {
                     startGame(&playerOne, &playerTwo);
                }
                else if(*answ == 'n')
                {
                        play = false;
                }
                // make sure no leftovercollors.
                cout << allColors.resetColor;
        }
        return 0;
}
Player addPlayer()
{
        clearScreen();
        std::cout << "\n"+*globalBackgroundColors.borderColor +"|‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾|" +allColors.resetColor +"\n" +
                     *globalBackgroundColors.borderColor +"|                                                                                                                         |" +allColors.resetColor +"\n" +
                     *globalBackgroundColors.borderColor +"|   |"+globalBackgroundColors.normalTextOnBackground+"‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾"+*globalBackgroundColors.borderColor+"|   |" +allColors.resetColor +"\n" +
                     *globalBackgroundColors.borderColor +"|   |"+globalBackgroundColors.normalTextOnBackground+"                                        Welcome new player. Enter ur firstname:                                  "+*globalBackgroundColors.borderColor+"|   |" +allColors.resetColor +"\n" +
                     *globalBackgroundColors.borderColor +"|    ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾    |" +allColors.resetColor +"\n" +
                     *globalBackgroundColors.borderColor +"|_________________________________________________________________________________________________________________________|" +allColors.resetColor +"\n" +
                     *globalBackgroundColors.borderColor+"                                                "+globalBackgroundColors.normalTextOnBackground+"        :";

        string *name = new string;
        std::cin >> *name;
        if(name->length() > 17)
        {
                long charsTodelete = name->length() - 17;
                name->erase(name->length()-charsTodelete);
        }
        std::cout << allColors.resetColor;
        Player player(*name);
        delete name;
        if(colors) {
                colorSelection(&player);
        }
        avatarSelection(player);
        return  player;
}
// Keeps track of the gamestate best of format.
// Players swap each round on whose is starting.
// Number of games and each players score is tracked.
void startGame(Player *playerOne, Player *playerTwo) {


        int games = 1;
        int maxGames = 2;
        Player *pFirst = playerOne;
        Player *pLast = playerTwo;
        int pFirstScore = 0;
        int pLastScore = 0;
        while (games <= maxGames) {
                Board *myBoardOne = new Board(pFirst, pLast, pFirstScore, pLastScore, games, maxGames);
                int *winnerOne = new int;
                *winnerOne = myBoardOne->startRound();
                if (*winnerOne == 1) {
                        pFirstScore++;
                } else if (*winnerOne == 2) {
                        pLastScore++;
                }
                delete myBoardOne;
                delete winnerOne;


                Player *tmpPlayer = pFirst;
                pFirst = pLast;
                pLast = tmpPlayer;

                int tmpScore = pFirstScore;
                pFirstScore = pLastScore;
                pLastScore = tmpScore;
                games++;
        }
        clearScreen();
        if (pFirstScore > pLastScore) {
                callWinArt(playerOne);
        } else if (pFirstScore == pLastScore) {
                callDrawArt();
        } else {
                callWinArt(playerTwo);
        }
}

