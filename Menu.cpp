#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>
#include "Utils.h"
using namespace std;

// -------------------- Utils --------------------

void printLeft(const string &text, int margin=2) {
    for(int i=0;i<margin;i++) cout << " ";
    cout << text << endl;
}

// -------------------- Big Title --------------------
vector<string> getBigTitle() {
    return {
"██╗      █████╗     ██╗███████╗ ██████╗ ██╗      █████╗                     ",
"██║     ██╔══██╗    ██║██╔════╝██╔═══██╗██║     ██╔══██╗                    ",
"██║     ███████║    ██║███████╗██║   ██║██║     ███████║                    ",
"██║     ██╔══██║    ██║╚════██║██║   ██║██║     ██╔══██║                    ",
"███████╗██║  ██║    ██║███████║╚██████╔╝███████╗██║  ██║                    ",
"╚══════╝╚═╝  ╚═╝    ╚═╝╚══════╝ ╚═════╝ ╚══════╝╚═╝  ╚═╝                    ",
"                                                                            ",
"██████╗ ███████╗██╗     ██╗      █████╗     ███████╗███████╗██████╗ ███████╗",
"██╔══██╗██╔════╝██║     ██║     ██╔══██╗    ██╔════╝██╔════╝██╔══██╗██╔════╝",
"██║  ██║█████╗  ██║     ██║     ███████║    █████╗  █████╗  ██║  ██║█████╗  ",
"██║  ██║██╔══╝  ██║     ██║     ██╔══██║    ██╔══╝  ██╔══╝  ██║  ██║██╔══╝  ",
"██████╔╝███████╗███████╗███████╗██║  ██║    ██║     ███████╗██████╔╝███████╗",
"╚═════╝ ╚══════╝╚══════╝╚══════╝╚═╝  ╚═╝    ╚═╝     ╚══════╝╚═════╝ ╚══════╝",
"                                                                            "
    };
}

// -------------------- Menu Options --------------------
vector<vector<string>> getMenuOptions() {
    vector<string> play = {"GIOCA"};
    vector<string> credits = {"CREDITI"};
    vector<string> settings = {"IMPOSTAZIONI"};
    vector<string> exitOption = {"ESCI"};
    return {play, credits, settings, exitOption};
}

// -------------------- Confirm Exit --------------------
bool confirmExitMenu() {
    vector<string> options = {"Sì", "No"};
    int choice = 1; // default is "No"
    char key;

    while(true) {
        clearScreen();
        auto term = getTerminalSize();
        int rows = term.first;
        int topPadding = rows / 4;

        for(int i=0;i<topPadding;i++) cout << endl;

        cout << "  \033[35mSei sicuro di voler uscire?\033[0m\n\n";

        for(int i=0;i<options.size();i++) {
            cout << "    ";
            if(i==choice) cout << "\033[1;35m"; else cout << "\033[97m";
            cout << options[i] << "\033[0m\n\n";
        }

        key = _getch();
        if(key == 27) {
            char k1 = _getch(), k2 = _getch();
            if(k1 == '[') {
                if(k2 == 'A' && choice > 0) choice--;
                else if(k2 == 'B' && choice < options.size()-1) choice++;
            }
        } else if(key == 10 || key == 13) {
            if(choice == 0) { // "Sì"
                clearScreen();
                cout << "\n\n\n    \033[1;35mArrivederci, ritorna da noi amore\033[0m\n\n\n";
                usleep(100000); // wait 2 seconds so the user sees it
                return true;
            } else {
                return false;
            }
        }
    }
}

// -------------------- Show Menu --------------------
int showMenu() {
    vector<vector<string>> options = getMenuOptions();
    int choice = 0;
    char key;

    pair<int,int> termSize = getTerminalSize();
    int rows = termSize.first;

    vector<string> title = getBigTitle();
    int topPadding = rows / 4;

    while(true) {
        clearScreen();
        for(int i=0;i<topPadding;i++) cout << endl;

        // Print title
        for(auto &line : title) {
            cout << "\033[35m  " << line << "\033[0m" << endl;
        }
        cout << endl;

        // Print menu options
        for(int i=0;i<options.size();i++) {
            for(auto &line : options[i]) {
                cout << "    ";
                if(i==choice) cout << "\033[1;35m"; else cout << "\033[97m";
                cout << line << "\033[0m\n\n"; // less padding to match main menu
            }
        }

        key = _getch();
        if(key == 27) {
            _getch();
            switch(_getch()) {
                case 'A': if(choice>0) choice--; break;
                case 'B': if(choice<options.size()-1) choice++; break;
            }
        } else if(key==10 || key==13) { // Enter
            string selected = options[choice][0];
            if(selected == "ESCI") {
                if(confirmExitMenu()) exit(0);
            } else {
                return choice;
            }
        }
    }
}
