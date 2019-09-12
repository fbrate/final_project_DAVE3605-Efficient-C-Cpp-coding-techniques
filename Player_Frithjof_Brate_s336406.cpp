//
// Created by fbrate on 01/04/19.
//

#include "Player_Frithjof_Brate_s336406.h"
#include <string>
#include <iostream>
#include "globals_Frithjof_Brate_s336406.h"
//public
using std::string;
Player::Player(string name) {
        this->name = name;
        // initalizes black as standard in case of colorsless state.
        // prvents nullpointers if no setPlayerColor is called -> which happens only after colorselection.
        // colorsseleciton is disabled if colors = false;
       playerColor = {&allColors.blackFG, &allColors.blackBG, &allColors.blackCombined, globalBackgroundColors.combined
                      , &globalBackgroundColors.normalTextOnBackground};
}


string Player::getName() {
        return name;
}
string Player::getSymbolColor() {
        return *playerColor.playerTurnFGColor;
}

// sets the avatar art from the avatar seleciton
void Player::setAvatarArt(const std::vector<string> &avArt)
{
        avatarArt = avArt;
}

// sets color for player -> only called if colors = true;
void Player::setPlayerColor(std::string *fg , std::string *bg, std::string *comb) {
        playerColor.playerTurnFGColor = fg;
        playerColor.playerTurnBGColor = bg;
        playerColor.playerTurnOutline = comb;
}

// prints the avatar line by line.
// since terminal output has to be printed line by line
string Player::getAvatarByLine(int line, bool playerTurn) {
        string stringToReturn;

        // set outline and asci color to waitturnoutline, and asci art to waitTurnColor;
        string turnColorOutline = *playerColor.waitTurnOutline;
        string turnColor = *playerColor.waitTurnColor;
        if(playerTurn)
        {
                // if this players turn set foreground color for avatar turncolor to playercolor.
                // and set outline(square surrounding char) to block of colors.
                turnColor = *playerColor.playerTurnFGColor+*globalBackgroundColors.bg;
                turnColorOutline = *playerColor.playerTurnOutline;


        }

        // the top and bottom "square" surrounding the avatar indication that it is his turn.
        // will be @ if colorless mode or a block of color in color mode.
        // if not this players turn -> it will just be an empty "           " with backgroundcolor.
        if(line == 1 || line == 27)
        {
                if(playerTurn) {
                        // for no colorversion
                                stringToReturn += turnColorOutline+"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
                }
                else
                {
                        stringToReturn += turnColorOutline+"                                 ";
                }

        }

        // avatar lines top.
        else if (line == 2)
        {
                // Frame surrounding avatar
                if(playerTurn)
                {
                stringToReturn += turnColorOutline +"@@"+turnColor+"  _________________________  "+turnColorOutline+"@@";

                }
                else {
                stringToReturn += turnColor +"  "+"  __________________________ "+"  ";
                }

                // __________________
        }
        // avatar image lines bot
        else if(line == 26)
        {
                // frame surrounding avatar
                if(playerTurn)
                {

                        stringToReturn += turnColorOutline+"@@" +turnColor+"  ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾  "+turnColorOutline+"@@";
                }
                else {

                stringToReturn += turnColor+"  " +"  ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾ "+"  ";
                }

        }
        // return avatar art by line.
        else
        {
                // 23 spots in array however 27 line calls.
                line = line -3;
                if(playerTurn)
                {
                        stringToReturn+= turnColorOutline+"@@"+turnColor+" |"+avatarArt.at(line)+"| "+ turnColorOutline+"@@";
                }
                else {

                        stringToReturn +=
                                turnColor + "  " + " |" + avatarArt.at(line)+ "| " +"  ";
                }


        }
        // make sure the string to return is color reset to standard:
        stringToReturn += allColors.resetColor;
        return  stringToReturn;


}


