#include <iostream>
#include <string>
#include <fstream>
#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#endif
using namespace std;


// Su linux/macos si usa il comando clear per pulire il schermo
//  ma su windows si usa cls

void clearScreen() {
    #if defined(_win32) || defined(_WIN64)
        system("cls");
    #else
        system("clear");
    #endif
}

string playerName ="Giocatore";
string difficulty = "Normale";

void loadSettings() {
    ifstream in("impostazioni.txt"); //legge
    if (in) {
        getline(in, playerName);
        getline(in, difficulty);
        in.close();
    }
}

void saveSettings() {
    ofstream out ("impostazioni.txt"); //scrive
    out << playerName << "\n";
    out << difficulty << "\n";
    out.close();
}

void printTitle() {
    cout << "\033[35m";
    cout << "┌──────────────────────────────────────────────────────────────────────────────────────────┐\n";
    cout << "│                                                                                          │\n";
    cout << "│  █████        ██    █████                  ████                                          │\n";
    cout << "│ ░░███        ███   ░░███                  ░░███                                          │\n";
    cout << "│  ░███       ░░░     ░███   █████   ██████  ░███   ██████                                 │\n";
    cout << "│  ░███               ░███  ███░░   ███░░███ ░███  ░░░░░███                                │\n";
    cout << "│  ░███               ░███ ░░█████ ░███ ░███ ░███   ███████                                │\n";
    cout << "│  ░███      █        ░███  ░░░░███░███ ░███ ░███  ███░░███                                │\n";
    cout << "│  ███████████        █████ ██████ ░░██████  █████░░████████                               │\n";
    cout << "│ ░░░░░░░░░░░        ░░░░░ ░░░░░░   ░░░░░░  ░░░░░  ░░░░░░░░                                │\n";
    cout << "│                                                                                          │\n";
    cout << "│      █████          ████  ████                  ██████               █████               │\n";
    cout << "│     ░░███          ░░███ ░░███                 ███░░███             ░░███                │\n";
    cout << "│   ███████   ██████  ░███  ░███   ██████       ░███ ░░░   ██████   ███████   ██████       │\n";
    cout << "│  ███░░███  ███░░███ ░███  ░███  ░░░░░███     ███████    ███░░███ ███░░███  ███░░███      │\n";
    cout << "│ ░███ ░███ ░███████  ░███  ░███   ███████    ░░░███░    ░███████ ░███ ░███ ░███████       │\n";
    cout << "│ ░███ ░███ ░███░░░   ░███  ░███  ███░░███      ░███     ░███░░░  ░███ ░███ ░███░░░        │\n";
    cout << "│ ░░████████░░██████  █████ █████░░████████     █████    ░░██████ ░░████████░░██████       │\n";
    cout << "│  ░░░░░░░░  ░░░░░░  ░░░░░ ░░░░░  ░░░░░░░░     ░░░░░      ░░░░░░   ░░░░░░░░  ░░░░░░        │\n";
    cout << "│                                                                                          │\n";
    cout << "└──────────────────────────────────────────────────────────────────────────────────────────┘\n";
    cout << "\033[0m\n";
}

void printSettingsTitle() {
    cout << "\033[35m";
    cout << "┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐\n";
    cout << "│ █████                                             █████                          ███                       ███ │\n";
    cout << "│░░███                                             ░░███                          ░░░                       ░░░  │\n";
    cout << "│ ░███  █████████████   ████████   ██████   █████  ███████    ██████    █████████ ████   ██████  ████████   ████ │\n";
    cout << "│ ░███ ░░███░░███░░███ ░░███░░███ ███░░███ ███░░  ░░░███░    ░░░░░███  ░█░░░░███ ░░███  ███░░███░░███░░███ ░░███ │\n";
    cout << "│ ░███  ░███ ░███ ░███  ░███ ░███░███ ░███░░█████   ░███      ███████  ░   ███░   ░███ ░███ ░███ ░███ ░███  ░███ │\n";
    cout << "│ ░███  ░███ ░███ ░███  ░███ ░███░███ ░███ ░░░░███  ░███ ███ ███░░███    ███░   █ ░███ ░███ ░███ ░███ ░███  ░███ │\n";
    cout << "│ █████ █████░███ █████ ░███████ ░░██████  ██████   ░░█████ ░░████████  █████████ █████░░██████  ████ █████ █████│\n";
    cout << "│░░░░░ ░░░░░ ░░░ ░░░░░  ░███░░░   ░░░░░░  ░░░░░░     ░░░░░   ░░░░░░░░  ░░░░░░░░░ ░░░░░  ░░░░░░  ░░░░ ░░░░░ ░░░░░ │\n";
    cout << "│                       ░███                                                                                     │\n";
    cout << "│                       █████                                                                                    │\n";
    cout << "│                      ░░░░░                                                                                     │\n";
    cout << "└────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘\n";
    cout << "\033[0m\n";
}

void printCreditsTitle() {
    cout << "\033[35m";
    cout << "┌────────────────────────────────────────────────────────────┐\n";
    cout << "│                                 █████  ███   █████     ███ │\n";
    cout << "│                                ░░███  ░░░   ░░███     ░░░  │\n";
    cout << "│  ██████  ████████   ██████   ███████  ████  ███████   ████ │\n";
    cout << "│ ███░░███░░███░░███ ███░░███ ███░░███ ░░███ ░░░███░   ░░███ │\n";
    cout << "│░███ ░░░  ░███ ░░░ ░███████ ░███ ░███  ░███   ░███     ░███ │\n";
    cout << "│░███  ███ ░███     ░███░░░  ░███ ░███  ░███   ░███ ███ ░███ │\n";
    cout << "│░░██████  █████    ░░██████ ░░████████ █████  ░░█████  █████│\n";
    cout << "│ ░░░░░░  ░░░░░      ░░░░░░   ░░░░░░░░ ░░░░░    ░░░░░  ░░░░░ │\n";
    cout << "└────────────────────────────────────────────────────────────┘\n";
    cout << "\033[0m\n";
}

void showCredits() {
    clearScreen();
    printCreditsTitle();
    cout << "Questi sono i crediti";
    cin.ignore();
    cin.get();

}

void showSettings() {
    do {
        clearScreen();
        printSettingsTitle();

        cout << "\n1. Nome giocatore: " << playerName << endl;
        cout << "2. Difficolta: " <<  difficulty << endl;
        cout << "3. Salva " << endl;
        cout << "4. Esci" << endl;
        
        cout << "\033[35m";
        cout << "\n>> ";
        cout << "\033[0m";

        int choice;
        cin >> choice;
        if(choice == 1) {
            cout << "Inserisci nome: ";
            cin.ignore();
            getline(cin, playerName);
            
        } else if (choice == 2) {
            if (difficulty == "Facile") {
                difficulty = "Normale"; 
                cout << "Difficolta' impostata su: " << difficulty << endl;
                cout << "Premi invio per continuare.. ";
                cin.ignore();
                cin.get();
            } else if (difficulty == "Normale") {
                difficulty = "Difficile";
                cout << "Difficolta' impostata su: " << difficulty << endl;
                cout << "Premi invio per continuare.. ";
                cin.ignore();
                cin.get();
            } else {
                difficulty = "Facile";
                cout << "Difficolta' impostata su: " << difficulty << endl;
                cout << "Premi invio per continuare.. ";
                cin.ignore();
                cin.get();
            }
        } else if (choice == 3) {
            saveSettings();
            cout << "Impostazioni Salvate!\n" <<"Premi invio per continuare.. ";
            cin.ignore();
            cin.get();
        } else if (choice == 4) {
            break;
        } else {
            do {
            cout << "Scelta non valida. \n Premi invio per riprovare"; // sappaimo che possiamo fare in un altro modo pero per non sprecare tempo abbiamo usato cin.ignore e cin.get
            cin >> choice;
            } while (choice != 1 || choice != 2 || choice != 3 || choice != 4);
        }

        } while (true); 
}

int main() {
    loadSettings();
    SetConsoleOutputCP(CP_UTF8);
    while (true) {
        clearScreen();
        printTitle();
        cout << "\n1. Gioca " << endl;
        cout << "2. Crediti " << endl;
        cout << "3. impostazioni" << endl;
        cout << "4. Esci" << endl; 

        cout << "\033[35m";
        cout << "\n>> ";
        cout << "\033[0m";

        int choice;
        cin >> choice;
        if (choice == 1) {
            clearScreen();
            cout << "Avvio del gioco per " << playerName << " In modalita' " << difficulty << "..." << endl;
            cout << "premi invio per per ritornare indietro";
            cin.ignore();
            cin.get(); 
        } else if (choice == 2) {
            showCredits();
        } else if (choice == 3) {
            showSettings();
        } else if (choice == 4) {
            clearScreen();
            cout << "Arrivederci, ritorna da noi amore <3" << endl;
            break;
        } else {
            cout << "Scelta non valida. Premi invio per riprovare"; 
            cin.ignore();
            cin.get();
        }

    }
}