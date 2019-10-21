//
// Created by fbrate on 05/04/19.
//

#include "ArtAndColorFunctions.h"
#include "globals.h"
#include <vector>
#include <iostream>

using std::vector;
using std::string;
using std::cout;
using std::cin;
void colorChecker()
{
        bool * validChar = new bool;
        *validChar =false;
        char * c = new char;
        while(!*validChar) {
                clearScreen();

        cout << "\n";
        cout << allColors.yellowCombined    + "                                                                                                           "+ allColors.resetColor+"\n"+
                allColors.yellowCombined    + "-----------------------------------------------------------------------------------------------------------"+ allColors.resetColor+"\n"+
                allColors.yellowCombined    + "                                                                                                           "+ allColors.resetColor+"\n";

        cout << allColors.cyanCombined      + "                                                                                                           " + allColors.resetColor+"\n" +
                allColors.cyanCombined      + "-----------------------------------------------------------------------------------------------------------" + allColors.resetColor+"\n" +
                allColors.cyanCombined      + "                                                                                                           " + allColors.resetColor+"\n";

        cout << allColors.magentaCombined   + "                                                                                                           " + allColors.resetColor+"\n"+
                allColors.magentaCombined   + "-----------------------------------------------------------------------------------------------------------" + allColors.resetColor+"\n"+
                allColors.magentaCombined   + "                                                                                                           " + allColors.resetColor+"\n";

        cout << allColors.blueCombined      + "                                                                                                           " +allColors.resetColor+"\n" +
                allColors.blueCombined      + "-----------------------------------------------------------------------------------------------------------" +allColors.resetColor+"\n" +
                allColors.blueCombined      + "                                                                                                           " +allColors.resetColor+"\n";

        cout << allColors.blackCombined     + "                                                                                                           " +allColors.resetColor+"\n" +
                allColors.blackCombined     + "-----------------------------------------------------------------------------------------------------------" +allColors.resetColor+"\n" +
                allColors.blackCombined     + "                                                                                                           " +allColors.resetColor+"\n";

        cout << allColors.blackSoftCombined + "                                                                                                           " +allColors.resetColor+"\n" +
                allColors.blackSoftCombined + "-----------------------------------------------------------------------------------------------------------" +allColors.resetColor+"\n" +
                allColors.blackSoftCombined + "                                                                                                           " +allColors.resetColor+"\n";

        cout << allColors.redCombined       + "                                                                                                           " +allColors.resetColor+"\n"+
                allColors.redCombined       + "-----------------------------------------------------------------------------------------------------------" +allColors.resetColor+"\n"+
                allColors.redCombined       + "                                                                                                           " +allColors.resetColor+"\n";

        cout << allColors.greenCombined     + "                                                                                                           " +allColors.resetColor+"\n" +
                allColors.greenCombined     + "-----------------------------------------------------------------------------------------------------------" +allColors.resetColor+"\n" +
                allColors.greenCombined     + "                                                                                                           " +allColors.resetColor+"\n";

        cout << allColors.whiteCombined     + "                                                                                                           " +allColors.resetColor+"\n" +
                allColors.whiteCombined     + "-----------------------------------------------------------------------------------------------------------" +allColors.resetColor+"\n" +
                allColors.blackFG+allColors.whiteBG + "Can you see the colors? y/n                                                                               " +allColors.resetColor;


                std::cin >> c;
                if (*c == 'y') {

                        *validChar = true;
                        colors = true;
                        setColors();

                }
                else if (*c == 'n') {

                        *validChar = true;
                        colors = false;
                        setColors();

                }
                cout <<"\n";


        }
        delete validChar;
        delete c;

}
void colorSelection(Player * player)
{
        // lets the user choose one of 5 colors for his avatar and symbol.
        clearScreen();
        bool validNr = false;
        while(!validNr) {

        // Lists each color and shows it on the background color as text, then followed by a few lines with just the color.
        cout << "\n";
        cout << *globalBackgroundColors.bg + allColors.yellowFG
                + "Press 1 for Yellow                                                                                         "+ allColors.resetColor+"\n"+allColors.yellowCombined
                + "                                                                                                           "+allColors.resetColor+"\n"+ allColors.yellowCombined
                + "                                                                                                           "+allColors.resetColor+"\n\n";
        cout << *globalBackgroundColors.bg + allColors.cyanFG
                + "Press 2 for Cyan                                                                                           " + allColors.resetColor+"\n" +allColors.cyanCombined
                + "                                                                                                           "+allColors.resetColor+"\n"+ allColors.cyanCombined
                + "                                                                                                           "+allColors.resetColor+"\n\n";
        cout << *globalBackgroundColors.bg + allColors.magentaFG
                + "Press 3 for Magenta                                                                                        " + allColors.resetColor+"\n" +allColors.magentaCombined
                + "                                                                                                           "+allColors.resetColor+"\n"+allColors.magentaCombined
                + "                                                                                                           "+allColors.resetColor+"\n\n";
        cout << *globalBackgroundColors.bg + allColors.blueFG
                + "Press 4 for Blue                                                                                           " +allColors.resetColor+"\n" + allColors.blueCombined
                + "                                                                                                           "+allColors.resetColor+"\n"+ allColors.blueCombined
                + "                                                                                                           "+allColors.resetColor+"\n\n";
        cout << *globalBackgroundColors.bg + allColors.blackFG
                + "Press 5 for Black                                                                                          " +allColors.resetColor+"\n" + allColors.blackSoftCombined
                + "                                                                                                           "+allColors.resetColor+"\n"+ allColors.blackSoftCombined
                + "                                                                                                           "+allColors.resetColor+"\n\n";

        // The user is prompted to select a nr, and when chosen the corresponding colors are added to
        // Player::setPlayerColor


                cout << globalBackgroundColors.normalTextOnBackground + "Select a  number for a color:                                                                                              ";
                char nr;

                cin >> nr;
                cout << allColors.resetColor;

                switch(nr) {
                        case '1': player->setPlayerColor(&allColors.yellowFG, &allColors.yellowBG, &allColors.yellowCombined);
                                validNr = true;
                                break;
                        case '2': player->setPlayerColor(&allColors.cyanFG, &allColors.cyanBG, &allColors.cyanCombined);
                                validNr = true;
                                break;
                        case '3': player->setPlayerColor(&allColors.magentaFG, &allColors.magentaBG, &allColors.magentaCombined);
                                validNr = true;
                                break;
                        case '4': player->setPlayerColor(&allColors.blueFG, &allColors.blueBG, &allColors.blueCombined);
                                validNr = true;
                                break;
                        case '5': player->setPlayerColor(&allColors.blackFG, &allColors.blackBG, &allColors.blackCombined);
                                validNr = true;
                                break;
                        default:
                                break;

                }

                clearScreen();
        }


}

// Lets the user choose 1 of 4 characters for his gameplay.
void avatarSelection(Player &player)
{
        clearScreen();

        vector<string> pigArt;
        pigArt.reserve(23);

        //line 1
        pigArt.push_back("                         ");
        pigArt.push_back("                         ");
        pigArt.push_back("                         ");
        pigArt.push_back("                         ");
        pigArt.push_back(",--.       ,--._         ");
        pigArt.push_back("     \\  > `-\"\"\"-' <  /   ");
        pigArt.push_back("      `-.         .-'    ");
        pigArt.push_back("        / 'e___e` \\      ");
        pigArt.push_back("       (   (o o)   )     ");
        pigArt.push_back("       _\\_  `='  _/_     ");
        pigArt.push_back("      / /|`-._.-'|\\ \\    ");
        pigArt.push_back("     / /||_______||\\ \\   ");
        pigArt.push_back("   _/ /_||=======||_\\ \\_ ");
        pigArt.push_back("  / _/==||       ||==\\_ \\");
        pigArt.push_back("  `'(   ^^       ^^   )`'");
        pigArt.push_back("     \\               /   ");
        pigArt.push_back("      \\______|______/    ");
        pigArt.push_back("      |______|______|    ");
        pigArt.push_back("        )__|   |__(      ");
        pigArt.push_back("       /   ]   [   \\     ");
        pigArt.push_back("       `--'     `--'     ");
        pigArt.push_back("                         ");
        pigArt.push_back("                         ");


        vector<string> monkeyArt;
        monkeyArt.reserve(23);

        monkeyArt.push_back("   .--.  .-'''-.  .--.   ");
        monkeyArt.push_back("  /.\"\".v'.-. .-.`v.\"\"\\\\  ");
        monkeyArt.push_back("  ||  / / O| | O\\ \\  ||  ");
        monkeyArt.push_back("  \\\\_/| \\__| |__/  \\_//  ");
        monkeyArt.push_back("   `-'\\  .-n-n-.  /`-'   ");
        monkeyArt.push_back("    _.-\\/       \\/-._    ");
        monkeyArt.push_back("  .'   (\\`.___.'/)   `.  ");
        monkeyArt.push_back(" /      \\`.___.'/      `.");
        monkeyArt.push_back("/        `.___.'         ");
        monkeyArt.push_back("|     |             \\    ");
        monkeyArt.push_back("|     |   .      .  |\\   ");
        monkeyArt.push_back("|     |             | \\  ");
        monkeyArt.push_back(" \\     \\            |  \\ ");
        monkeyArt.push_back("  \\     \\           |.' `");
        monkeyArt.push_back("   `.    \\         .'    ");
        monkeyArt.push_back("._   `.   `-. ___ /      ");
        monkeyArt.push_back("  `-._ `.    `.__)       ");
        monkeyArt.push_back("      `-.\\     \\/      .'");

        monkeyArt.push_back("        _/ / /|/     .'  ");
        monkeyArt.push_back("_      (__/_/-/   ..'    ");
        monkeyArt.push_back(" ``--._____.-(     `.    ");
        monkeyArt.push_back("              `--.   `.  ");
        monkeyArt.push_back("                (_/\\ \\\\\\ ");

        vector<string> roboArt;
        roboArt.reserve(23);

        roboArt.push_back("                         ");
        roboArt.push_back("                         ");
        roboArt.push_back("                         ");
        roboArt.push_back("                         ");
        roboArt.push_back("                         ");
        roboArt.push_back("     [___] /~\\ [___]     ");
        roboArt.push_back("     |ooo|.\\_/.|ooo|     ");
        roboArt.push_back("     |888||   ||888|     ");
        roboArt.push_back("    /|888||   ||888|\\    ");
        roboArt.push_back("  /_,|###||___||###|._\\  ");
        roboArt.push_back(" /~\\  ~~~ /[_]\\ ~~~  /~\\ ");
        roboArt.push_back("(O_O) /~~[_____]~~\\ (O_O)");
        roboArt.push_back("     (  |       |  )     ");
        roboArt.push_back("    [~` ]       [ '~]    ");
        roboArt.push_back("    |~~|         |~~|    ");
        roboArt.push_back("    |  |         |  |    ");
        roboArt.push_back("   _<\\/>_       _<\\/>_   ");
        roboArt.push_back("  /_====_\\     /_====_\\  ");
        roboArt.push_back("                         ");
        roboArt.push_back("                         ");
        roboArt.push_back("                         ");
        roboArt.push_back("                         ");
        roboArt.push_back("                         ");

        vector<string> manArt;
        manArt.reserve(23);

        manArt.push_back("                         ");
        manArt.push_back("                         ");
        manArt.push_back("                         ");
        manArt.push_back("            _            ");
        manArt.push_back("           / \\           ");
        manArt.push_back("     __/\\_/   \\_/\\__     ");
        manArt.push_back("    /   _________   \\    ");
        manArt.push_back("    \\__/\\_______/\\__/    ");
        manArt.push_back("        _/      \\_       ");
        manArt.push_back("      / |       | \\      ");
        manArt.push_back("     /  |__   __|  \\     ");
        manArt.push_back("    |__/((o| |o))\\__|    ");
        manArt.push_back("    |      | |      |    ");
        manArt.push_back("    |\\     |_|     /|    ");
        manArt.push_back("    | \\           / |    ");
        manArt.push_back("     \\| /  ___  \\ |/     ");
        manArt.push_back("      \\ | / _ \\ | /      ");
        manArt.push_back("       \\_________/       ");
        manArt.push_back("        _|_____|_        ");
        manArt.push_back("   ____|_________|____   ");
        manArt.push_back("  /                   \\  ");
        manArt.push_back(" /                     \\ ");
        manArt.push_back(" |   /             \\   | ");



        // Loop for valid input check.
        bool validNr = false;
        while(!validNr) {


                // Loops through all the avatars side by side, line by line to display them for the user.
                // There is also some borders .
                // This code until next comment frames each avatar in a square and displays a border around then all.
                cout << "\n"+*globalBackgroundColors.borderColor + "|‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾|" + allColors.resetColor + "\n";

                cout << *globalBackgroundColors.borderColor+"|  "+*globalBackgroundColors.bg+player.getSymbolColor()+" _________________________ "+*globalBackgroundColors.borderColor+"   "+*globalBackgroundColors.combined+player.getSymbolColor()+" _________________________ "+*globalBackgroundColors.borderColor+"   "+*globalBackgroundColors.combined+player.getSymbolColor()+" _________________________ "+*globalBackgroundColors.borderColor+"   "+*globalBackgroundColors.combined+player.getSymbolColor()+" _________________________ " +*globalBackgroundColors.borderColor+"  |"+allColors.resetColor +"\n";
                for(int i = 0; i < 23; i++)
                {
                        cout << *globalBackgroundColors.borderColor+"|  "+*globalBackgroundColors.bg+player.getSymbolColor()+"|"+pigArt.at(i) +"|"+*globalBackgroundColors.borderColor+"   "+*globalBackgroundColors.bg+player.getSymbolColor()+"|" +monkeyArt.at(i)  +"|"+*globalBackgroundColors.borderColor+"   "+*globalBackgroundColors.bg+player.getSymbolColor()+"|"+roboArt.at(i) +"|"+*globalBackgroundColors.borderColor+"   "+*globalBackgroundColors.bg+player.getSymbolColor()+"|" + manArt.at(i) + "|" +*globalBackgroundColors.borderColor+"  |"+allColors.resetColor +"\n";
                }


                cout << *globalBackgroundColors.borderColor+"|  "+*globalBackgroundColors.bg+player.getSymbolColor()+" ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾ "+*globalBackgroundColors.borderColor+"   "+*globalBackgroundColors.combined+player.getSymbolColor()+" ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾ "+*globalBackgroundColors.borderColor+"   "+*globalBackgroundColors.combined+player.getSymbolColor()+" ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾ "+*globalBackgroundColors.borderColor+"   "+*globalBackgroundColors.combined+player.getSymbolColor()+" ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾ " +*globalBackgroundColors.borderColor+"  |"+allColors.resetColor +"\n";
                cout << *globalBackgroundColors.borderColor + "|_________________________________________________________________________________________________________________________|" + allColors.resetColor + "\n";
                cout << globalBackgroundColors.normalTextOnBackground +"                1                             2                             3                             4                "+allColors.resetColor +"\n";
                cout << globalBackgroundColors.normalTextOnBackground + "Select a  number for an avatar:                                                                                           ";

                // Gets a number from the user -> if not 1-4 the entire graphic above will be looped again after a clearscreen.
                // Then prompted to input a new number.
                char nr;
                cin >> nr;
                cout << allColors.resetColor;


                // Check input, and set corresponding avatar to the player.
                // if not 1-4, the default switch will falsify validNr and repeat.
                validNr = true;
                switch(nr) {
                        case '1': player.setAvatarArt(pigArt);
                                break;
                        case '2': player.setAvatarArt(monkeyArt);
                                break;
                        case '3': player.setAvatarArt(roboArt);
                                break;
                        case '4': player.setAvatarArt(manArt);
                                break;
                        default:
                                validNr = false;
                                break;
                }
                clearScreen();
        }
}


// print draw animation after best of games.
void callDrawArt(){
        std::cout << "\n"+*globalBackgroundColors.borderColor +"|‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾|" +allColors.resetColor +"\n" +
                     *globalBackgroundColors.borderColor +"|                                                                                                                         |" +allColors.resetColor +"\n" +
                     *globalBackgroundColors.borderColor +"|   |"+globalBackgroundColors.normalTextOnBackground+"‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾"+*globalBackgroundColors.borderColor+"|   |" +allColors.resetColor +"\n" +
                     *globalBackgroundColors.borderColor +"|   |"+globalBackgroundColors.normalTextOnBackground+"                                                  DRAW! Want to play again? y/n                                  "+*globalBackgroundColors.borderColor+"|   |" +allColors.resetColor +"\n" +
                     *globalBackgroundColors.borderColor +"|    ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾    |" +allColors.resetColor +"\n" +
                     *globalBackgroundColors.borderColor +"|_________________________________________________________________________________________________________________________|" +allColors.resetColor +"\n" +
                     *globalBackgroundColors.borderColor+"                                                "+globalBackgroundColors.normalTextOnBackground+"        :";
}
// print win for player animation after best of games.
void callWinArt(Player * player)
{
        std::string name= player->getName();
        while(name.length() < 17)
        {
                name =" "+ name;
        }
        std::cout << "\n"+*globalBackgroundColors.borderColor +"|‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾|" +allColors.resetColor +"\n" +
                     *globalBackgroundColors.borderColor +"|                                                                                                                         |" +allColors.resetColor +"\n" +
                     *globalBackgroundColors.borderColor +"|   |"+globalBackgroundColors.normalTextOnBackground+"‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾"+*globalBackgroundColors.borderColor+"|   |" +allColors.resetColor +"\n" +
                     *globalBackgroundColors.borderColor +"|   |"+globalBackgroundColors.normalTextOnBackground+"                                  Winner is: "+name+"! Want to play again? y/n                          "+*globalBackgroundColors.borderColor+"|   |" +allColors.resetColor +"\n" +
                     *globalBackgroundColors.borderColor +"|    ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾    |" +allColors.resetColor +"\n" +
                     *globalBackgroundColors.borderColor +"|_________________________________________________________________________________________________________________________|" +allColors.resetColor +"\n" +
                     *globalBackgroundColors.borderColor+"                                                "+globalBackgroundColors.normalTextOnBackground+"        :";
}
