#include <iostream>
#include "Menu.h"       // include the header, not Menu.cpp
#include "Settings.cpp"
 // for now, can leave cpp
#include "Utils.h"

using namespace std;

int main() {
    while(true) {
        int selected = showMenu();
        clearScreen();

        switch(selected) {
            case 0: { // PLAY
                Settings s;
                string playerName = s.get("player_name", "Player");
                string difficulty = s.get("difficulty", "Normal");
                cout << "Starting game for " << playerName 
                     << " at " << difficulty << " difficulty...\n";
                _getch();
                break;
            }
            case 1: // CREDITS
                cout << "Credits coming soon!\n";
                _getch();
                break;
            case 2: { // SETTINGS
                Settings s;
                s.showMenu();
                break;
            }
        }
    }
    return 0;
}
