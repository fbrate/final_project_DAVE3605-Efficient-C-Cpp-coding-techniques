
#include "globals.h"
#include <iostream>

bool colors;
GlobalBackgroundColors globalBackgroundColors;
AllColors allColors =   {
        // red        greeen
        "\033[31;41m", "\033[32;42m",
        // FG           BG|          combined    soft
        //yellow
        "\033[33m", "\033[43m", "\033[33;43m",
        // cyan
        "\033[36m", "\033[46m", "\033[36;46m",
        //white
        "\033[97m", "\033[107m", "\033[97;107m",
        // magenta
        "\033[35m", "\033[45m", "\033[35;45m",
        //black
        "\033[90m","\033[100m", "\033[90;100m","\033[30;40m",
        // blue
        "\033[34m", "\033[44m","\033[34;44m",
        // reset
        "\033[0m" };




void setColors()
{
        if(!colors)
        {
                // set all color strings to "";
                // that way all calls still operate(at same speed as with colors);
                // but all nullpointers are avoided.
                allColors = {"","",
                             "","",""
                             ,"","",""
                             ,"","",""
                             ,"","",""
                             ,"","","", "",
                             "","","",
                             ""};
        }
        // taken from allcolors to distribute preset colors for important feautures
        // as borders and backgorunds.
        globalBackgroundColors= {&allColors.whiteFG, &allColors.whiteBG, &allColors.whiteCombined
                , allColors.blackFG + allColors.whiteBG, &allColors.blackCombined, &allColors.blackSoftCombined};
}
// cross platform screen clearer. May not be the best and fastest but a decent
// way without using system() -> bad practice and platform dependent."cls" for windows, and "clear" for unix systems.

