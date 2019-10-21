//
// Created by fbrate on 29/03/19.
//

#ifndef TICTACTOE_GROUP17_FINAL_PROJECT_GLOBALS_H
#define TICTACTOE_GROUP17_FINAL_PROJECT_GLOBALS_H

#include <string>
#include <iostream>

extern bool colors;

// pointers to existing colors
// easily gathered throughout the program
// with low memory requirement.
struct GlobalBackgroundColors{
    std::string *fg;
    std::string *bg;
    std::string *combined;
    // text on background is a combination
    // one existing foreground and background
    // there for needs to be declared.
    std::string normalTextOnBackground;
    std::string *borderColor;
    std::string *sectionColor;
};
extern GlobalBackgroundColors globalBackgroundColors;
struct AllColors{

    std::string redCombined;

    std::string greenCombined;

    std::string yellowFG;
    std::string yellowBG;
    std::string yellowCombined;

    std::string cyanFG;
    std::string cyanBG;
    std::string cyanCombined;

    std::string whiteFG;
    std::string whiteBG;
    std::string whiteCombined;

    std::string magentaFG;
    std::string magentaBG;
    std::string magentaCombined;

    std::string blackFG;
    std::string blackBG;
    std::string blackCombined;
    std::string blackSoftCombined;

    std::string blueFG;
    std::string blueBG;
    std::string blueCombined;

    std::string resetColor;

};

extern AllColors allColors;
void setColors();

// cross platform screen clearer. May not be the best and fastest but a decent
// way without using system() -> bad practice and platform dependent."cls" for windows, and "clear" for unix systems.
// inlined to improve performance - it is called after every input throughout the entire program.
inline void clearScreen()
{
    for (int i = 0; i < 3; i++)
    {
        std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"; // 25 newlines

    }
}








#endif //TICTACTOE_GROUP17_FINAL_PROJECT_GLOBALS_H
