#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>
#include "Utils.h"
using namespace std;

class Settings {
public:
    Settings(const string &file = "settings.txt") : filename(file) { load(); }

    void load() {
        settings.clear();
        ifstream in(filename);
        if(!in.is_open()) {
            // Default values if file doesn't exist
            settings["player_name"] = "Giocatore";
            settings["difficulty"] = "Normal";
            savedState = settings;
            return;
        }
        string line;
        while(getline(in, line)) {
            size_t pos = line.find('=');
            if(pos != string::npos)
                settings[line.substr(0,pos)] = line.substr(pos+1);
        }
        savedState = settings;
    }

    void save() {
        ofstream out(filename);
        for(auto &p : settings)
            out << p.first << "=" << p.second << "\n";
        savedState = settings;
    }

    bool hasUnsavedChanges() { return settings != savedState; }

    void set(const string &key, const string &value) { settings[key] = value; }
    string get(const string &key, const string &defaultVal="") {
        return settings.count(key) ? settings[key] : defaultVal;
    }

    // -------------------- Confirmation popup --------------------
    bool confirmExit() {
        vector<string> options = {"SI", "NO"};
        int choice = 1;
        char key;

        while(true) {
            clearScreen();
            auto term = getTerminalSize();
            int rows = term.first;
            int topPadding = rows / 3;
            for(int i=0;i<topPadding;i++) cout << endl;

            cout << "  \033[35mSei sicuro che vuoi uscire senza salvare?\033[0m\n\n";

            for(int i = 0; i < options.size(); i++) {
                cout << "    ";
                if(i == choice) cout << "\033[1;35m"; else cout << "\033[97m";
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
                return (options[choice] == "SI");
            }
        }
    }

    // -------------------- Settings Menu --------------------
    void showMenu() {
        vector<string> options = {"NOME GIOCATORE", "DIFFICOLTÀ", "SALVA", "INDIETRO"};
        int choice = 0;
        char key;

        vector<string> title = {
"██╗███╗   ███╗██████╗  ██████╗ ███████╗████████╗ █████╗ ███████╗██╗ ██████╗ ███╗   ██╗██╗",
"██║████╗ ████║██╔══██╗██╔═══██╗██╔════╝╚══██╔══╝██╔══██╗╚══███╔╝██║██╔═══██╗████╗  ██║██║",
"██║██╔████╔██║██████╔╝██║   ██║███████╗   ██║   ███████║  ███╔╝ ██║██║   ██║██╔██╗ ██║██║",
"██║██║╚██╔╝██║██╔═══╝ ██║   ██║╚════██║   ██║   ██╔══██║ ███╔╝  ██║██║   ██║██║╚██╗██║██║",
"██║██║ ╚═╝ ██║██║     ╚██████╔╝███████║   ██║   ██║  ██║███████╗██║╚██████╔╝██║ ╚████║██║",
"╚═╝╚═╝     ╚═╝╚═╝      ╚═════╝ ╚══════╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚═╝"
        };

        while(true) {
            clearScreen();

            auto term = getTerminalSize();
            int rows = term.first;
            int topPadding = rows / 4;
            for(int i=0;i<topPadding;i++) cout << endl;

            // Print title
            for(auto &line : title) cout << "\033[35m  " << line << "\033[0m" << endl;

            cout << endl << endl;

            // Print menu options
            for(int i = 0; i < options.size(); i++) {
                string line;
                if(options[i] == "NOME GIOCATORE")
                    line = options[i] + ": " + get("player_name", "Giocatore");
                else if(options[i] == "DIFFICOLTÀ") {
                    string cur = get("difficulty","Normal");
                    if(cur == "Easy") cur = "Facile";
                    else if(cur == "Normal") cur = "Normale";
                    else if(cur == "Hard") cur = "Difficile";
                    line = options[i] + ": " + cur;
                } else
                    line = options[i];

                cout << "    ";
                if(i == choice) cout << "\033[1;35m"; else cout << "\033[97m";
                cout << line << "\033[0m\n\n";
            }

            key = _getch();
            if(key == 27) {
                char k1 = _getch(), k2 = _getch();
                if(k1 == '[') {
                    if(k2 == 'A' && choice > 0) choice--;
                    else if(k2 == 'B' && choice < options.size()-1) choice++;
                }
            } else if(key == 10 || key == 13) {
                if(options[choice] == "INDIETRO") {
                    if(hasUnsavedChanges()) {
                        bool confirm = confirmExit();
                        if(confirm) return;
                    } else return;
                } else if(options[choice] == "SALVA") {
                    save();
                } else if(options[choice] == "NOME GIOCATORE") {
                    string name;
                    cout << "\033[0mInserisci Nome Giocatore: ";
                    getline(cin, name);
                    if(!name.empty()) set("player_name", name);
                } else if(options[choice] == "DIFFICOLTÀ") {
                    vector<pair<string,string>> levels = { {"Easy","Facile"}, {"Normal","Normale"}, {"Hard","Difficile"} };
                    string current = get("difficulty","Normal");
                    int idx = 1;
                    for(int i=0;i<levels.size();i++) if(levels[i].first == current) idx=i;
                    idx = (idx+1)%levels.size();
                    set("difficulty", levels[idx].first);
                }
            }
        }
    }

private:
    string filename;
    map<string,string> settings;
    map<string,string> savedState;
};
