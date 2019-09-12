//
// Created by fbrate on 01/04/19.
//

#ifndef TICTACTOE_GROUP17_FINAL_PROJECT_PLAYER_H
#define TICTACTOE_GROUP17_FINAL_PROJECT_PLAYER_H


#include <string>
#include <vector>

class Player {
private:
    std::string name;
    std::vector<std::string> avatarArt;
    struct PlayerColor{
        std::string *playerTurnFGColor;
        std::string *playerTurnBGColor;
        std::string *playerTurnOutline;
        std::string *waitTurnOutline;
        std::string *waitTurnColor;
    };
    PlayerColor playerColor;
public:
    explicit Player(std::string);
    std::string getName();
    std::string getSymbolColor();
    void setAvatarArt(const std::vector<std::string>&);
    void setPlayerColor(std::string*, std::string*, std::string*);
    std::string getAvatarByLine(int, bool);


};


#endif //TICTACTOE_GROUP17_FINAL_PROJECT_PLAYER_H
