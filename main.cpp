#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#endif
#include <time.h>
using namespace std;

void clearScreen() {
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #else
        system("clear");
    #endif
}

string mobs1[3] = {"Scimmia", "Cane", "Goblin"};
string mobs2[3] = {"Pipistrello", "Farfalla", "Ragno"};
string mobs3[3] = {"Centauro", "Mietitore", "Fenice"};
<<<<<<< HEAD
string inventariospace[30];
=======

>>>>>>> 75fc54e26139bb65676293c738846c2800453a6b
string playerName ="Giocatore";
string difficulty = "Normale";
string infront = "w"; 
string sinistra = "a";
string destra ="d";
string indietro = "s";
string inventario = "e";
string pieta = "r";
string scappare = "l";
string attaccare = "q";
double vita = 5;
int nemiciUccisi = 0;
int livello = 1;

<<<<<<< HEAD
double vita = 5;
int nemiciUccisi = 0;
int livello = 1;

=======
>>>>>>> 75fc54e26139bb65676293c738846c2800453a6b
void livelloEsperienza() {
    if (difficulty == "Normale" ) {
            if (nemiciUccisi >= 3) {
                livello++;
                vita = vita + 2.5;
                cout << "Congratuziolazioni. Sei arrivato al livello " << livello << ". Adesso hai " << vita << "vita";
            }
    } else if (difficulty == "Facile") {
                if (nemiciUccisi >= 2) {
                    livello++;
                    vita = vita + 3.5;
                    cout << "Congratuziolazioni. Sei arrivato al livello " << livello << ". Adesso hai " << vita << "vita";
            }
    } else if (difficulty == "Difficile") {
                if (nemiciUccisi >= 5) {
                    livello++;
                    vita = vita + 1.5;
                    cout << "Congratuziolazioni. Sei arrivato al livello " << livello << ". Adesso hai " << vita << "vita";
            }
    }
}

<<<<<<< HEAD
void combattimento(int livello, int &uccisioni, string mobs[3]){
=======
void combattimento(int livello, int &nemiciUccisi, string mobs[3]){
>>>>>>> 75fc54e26139bb65676293c738846c2800453a6b

    string scelta;
    string mob = mobs[rand() % 3];
    if (mob == mobs2[1]){
        cout << "Sei stato fortunanto, la farfalla ti cura!" << endl;
    }
    else{
        cout << "\nHai incontrato : " << mob << "!" << endl;
        cout << "Vuoi attaccare (premi 'q'), essere misericordioso (premi 'r') o scappare (premi 'l')? ";
        cin >> scelta;
        if (scelta == attaccare) {
            cout << "Hai attaccato : " << mob << " e lo hai sconfitto!" << endl;
<<<<<<< HEAD
            uccisioni++;
=======
            nemiciUccisi++;
>>>>>>> 75fc54e26139bb65676293c738846c2800453a6b
        } else if (scelta == pieta) {
            cout << "Sei stato misericordioso con : " << mob << " e lo hai lasciato andare.Tuttavia prendi del danno :(" << endl;
        } else if (scelta == scappare) {
        cout << "Sei scappato da : " << mob << " per curarti." << endl;
        } else {
            cout << "Scelta non valida. " << mob << " ti ha attaccato mentre eri indeciso!" << endl;
        }
    }
<<<<<<< HEAD
}
=======

    /*
    if  difficolte == normale
    
    */
}


/*
livello 1 nemici:
- Scimmie
- Cani
- goblin
boss = Goblin king, chiave della trasformazioe

livelli 2 nemici;
Pipistrelli
Scorpioni
Ragni
boss = Vampiro

Livello 3 nemici ; 
gorilla
fantasma
fenice

boss = Drago
*/

string inventariospace[30];
>>>>>>> 75fc54e26139bb65676293c738846c2800453a6b

void loadSettings() {
    ifstream in("impostazioni.txt"); //legge
    if (in) {
        string line;
        while (getline(in, line)) {
            size_t pos = line.find(" = ");
            if (pos != string::npos) { 
                string key = line.substr(0, pos);
                string value = line.substr(pos + 3); // Dopo " = "
                if (key == "playerName") playerName = value;
                else if (key == "difficulty") difficulty = value;
                else if (key == "infront") infront = value;
                else if (key == "sinistra") sinistra = value;
                else if (key == "destra") destra = value;
                else if (key == "indietro") indietro = value;
                else if (key == "inventario") inventario = value;
                else if (key == "pieta") pieta = value;
                else if (key == "scappare") scappare = value;
                else if (key == "attaccare") attaccare = value;
            }
        }
        in.close();
    }
}

void loadInventory() {
    ifstream in("inventario.txt"); //legge
    if (in) {
        string line;
        while (getline(in, line)) {
            size_t pos = line.find(" = ");
            if (pos != string::npos) { 
                string key = line.substr(0, pos);
                string value = line.substr(pos + 3); // Dopo " = "
                if (key == "oggetto") inventariospace[0] = value;
                else if (key == "oggetto") inventariospace[1] = value;
                else if (key == "oggetto") inventariospace[2] = value;
                else if (key == "oggetto") inventariospace[3] = value;
                else if (key == "oggetto") inventariospace[4] = value;
                else if (key == "oggetto") inventariospace[5] = value;
                else if (key == "oggetto") inventariospace[6] = value;
                else if (key == "oggetto") inventariospace[7] = value;
                else if (key == "oggetto") inventariospace[8] = value;
                else if (key == "oggetto") inventariospace[9] = value;
                else if (key == "oggetto") inventariospace[10] = value;
                else if (key == "oggetto") inventariospace[11] = value;
                else if (key == "oggetto") inventariospace[12] = value;
                else if (key == "oggetto") inventariospace[13] = value;
                else if (key == "oggetto") inventariospace[14] = value;
                else if (key == "oggetto") inventariospace[15] = value;
                else if (key == "oggetto") inventariospace[16] = value;
                else if (key == "oggetto") inventariospace[17] = value;
                else if (key == "oggetto") inventariospace[18] = value;
                else if (key == "oggetto") inventariospace[19] = value;
                else if (key == "oggetto") inventariospace[20] = value;
                else if (key == "oggetto") inventariospace[21] = value;
                else if (key == "oggetto") inventariospace[22] = value;
                else if (key == "oggetto") inventariospace[23] = value;
                else if (key == "oggetto") inventariospace[24] = value;
                else if (key == "oggetto") inventariospace[25] = value;
            }
        }
        in.close();
    }
}

<<<<<<< HEAD
=======

>>>>>>> 75fc54e26139bb65676293c738846c2800453a6b
void saveSettings() {
    ofstream out("impostazioni.txt"); //scrive
    out << "playerName = " << playerName << "\n";
    out << "difficulty = " << difficulty << "\n";
    out << "infront = " << infront << "\n";
    out << "sinistra = " << sinistra << "\n";
    out << "destra = " << destra << "\n";
    out << "indietro = " << indietro << "\n";
    out << "inventario = " << inventario << "\n";
    out << "pieta = " << pieta << "\n";
    out << "scappare = " << scappare << "\n";
    out << "attaccare = " << attaccare << "\n";
    out.close();
}

void saveInventory() {
    ofstream out("inventario.txt"); //scrive
    out << "oggetto = " << inventariospace[0] << "\n";
    out << "oggetto = " << inventariospace[1] << "\n";
    out << "oggetto = " << inventariospace[2] << "\n";
    out << "oggetto = " << inventariospace[3] << "\n";
    out << "oggetto = " << inventariospace[4] << "\n";
    out << "oggetto = " << inventariospace[5] << "\n";
    out << "oggetto = " << inventariospace[6] << "\n";
    out << "oggetto = " << inventariospace[7] << "\n";
    out << "oggetto = " << inventariospace[8] << "\n";
    out << "oggetto = " << inventariospace[9] << "\n";
    out << "oggetto = " << inventariospace[10] << "\n";
    out << "oggetto = " << inventariospace[11] << "\n";
    out << "oggetto = " << inventariospace[12] << "\n";
    out << "oggetto = " << inventariospace[13] << "\n";
    out << "oggetto = " << inventariospace[14] << "\n";
    out << "oggetto = " << inventariospace[15] << "\n";
    out << "oggetto = " << inventariospace[16] << "\n";
    out << "oggetto = " << inventariospace[17] << "\n";
    out << "oggetto = " << inventariospace[18] << "\n";
    out << "oggetto = " << inventariospace[19] << "\n";
    out << "oggetto = " << inventariospace[20] << "\n";
    out << "oggetto = " << inventariospace[21] << "\n";
    out << "oggetto = " << inventariospace[22] << "\n";
    out << "oggetto = " << inventariospace[23] << "\n";
    out << "oggetto = " << inventariospace[24] << "\n";
    out << "oggetto = " << inventariospace[25] << "\n";
<<<<<<< HEAD
=======

>>>>>>> 75fc54e26139bb65676293c738846c2800453a6b
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

void printIntroductionTitle(){
    cout << "\033[35m";
    cout << "┌─────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐\n";
    cout << "│  ███              █████                           █████                        ███                              │\n";
    cout << "│ ░░░              ░░███                           ░░███                        ░░░                               │\n";
    cout << "│ ████  ████████   ███████   ████████   ██████   ███████  █████ ████  █████████ ████   ██████  ████████    ██████ │\n";
    cout << "│░░███ ░░███░░███ ░░░███░   ░░███░░███ ███░░███ ███░░███ ░░███ ░███  ░█░░░░███ ░░███  ███░░███░░███░░███  ███░░███│\n";
    cout << "│ ░███  ░███ ░███   ░███     ░███ ░░░ ░███ ░███░███ ░███  ░███ ░███  ░   ███░   ░███ ░███ ░███ ░███ ░███ ░███████ │\n";
    cout << "│ ░███  ░███ ░███   ░███ ███ ░███     ░███ ░███░███ ░███  ░███ ░███    ███░   █ ░███ ░███ ░███ ░███ ░███ ░███░░░  │\n";
    cout << "│ █████ ████ █████  ░░█████  █████    ░░██████ ░░████████ ░░████████  █████████ █████░░██████  ████ █████░░██████ │\n";
    cout << "│░░░░░ ░░░░ ░░░░░    ░░░░░  ░░░░░      ░░░░░░   ░░░░░░░░   ░░░░░░░░  ░░░░░░░░░ ░░░░░  ░░░░░░  ░░░░ ░░░░░  ░░░░░░  │\n";
    cout << "└─────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘\n";
    cout << "\033[0m\n";
}

void Input(){
    cout << "\033[35m";
    cout << "\n>> ";
    cout << "\033[0m";
}

void Invio(){
    cout << "\033[90m";
    cout << "\nPremi invio per continuare...";
    cout << "\033[0m";
}

void displayAsciiArt(const string& filename) {
    ifstream file(filename);
    char c;
    while (file.get(c)) {
        cout << c;
    }
}

void displayBoss() {
    displayAsciiArt("ASCII/boss.txt");
}
void displayVane() {
    displayAsciiArt("ASCII/cane.txt");
}
void displayCentauro() {
    displayAsciiArt("ASCII/isola.txt");
}
void displayDragon() {
    displayAsciiArt("ASCII/dragoboss.txt");
}
void displayFarfalla() {
    displayAsciiArt("ASCII/farfalla.txt");
}
void displayFenice() {
    displayAsciiArt("ASCII/fenice.txt");
}
void displayGoblin() {
    displayAsciiArt("ASCII/goblin.txt");
}
void displayGoblinKing() {
    displayAsciiArt("ASCII/goblinking.txt");
}
void displayReaper() {
    displayAsciiArt("ASCII/grimreaper.txt");
}
void displayIsola() {
    displayAsciiArt("ASCII/isola.txt");
}
void displayBat() {
    displayAsciiArt("ASCII/pipistrelli.txt");
}
void displayRagni() {
    displayAsciiArt("ASCII/ragni.txt");
}
void displayScimmie() {
    displayAsciiArt("ASCII/scimmie.txt");
}
void displayVampireBoss() {
    displayAsciiArt("ASCII/vampiroboss.txt");
}

void showCredits() {
    clearScreen();
    printCreditsTitle();
    cout << "Questi sono i crediti";
    cin.ignore();
    cin.get();

}

void showSettings() {
    while(true) {

        clearScreen();
        printSettingsTitle();
        cout << "\n1. Nome giocatore: " << playerName << endl;
        cout << "2. Difficolta: " <<  difficulty << endl;
        cout << "3. Avanti: " <<  infront << endl;
        cout << "4. Sinistra: " <<  sinistra << endl;
        cout << "5. Destra: " <<  destra << endl;
        cout << "6. Indietro: " <<  indietro << endl;
        cout << "7. Inventario: " <<  inventario << endl;
        cout << "8. Pietá: " <<  pieta << endl;
        cout << "9. Scappare: " <<  scappare << endl;
        cout << "10. Attaccare: " <<  attaccare << endl;
        cout << "11. Salva " << endl;
        cout << "12. Esci" << endl;
        Input();

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
                Invio();
                cin.ignore();
                cin.get();
            } else if (difficulty == "Normale") {
                difficulty = "Difficile";
                cout << "Difficolta' impostata su: " << difficulty << endl;
                Invio();
                cin.ignore();
                cin.get();
            } else {
                difficulty = "Facile";
                cout << "Difficolta' impostata su: " << difficulty << endl;
                Invio();
                cin.ignore();
                cin.get();
            }
        } else if (choice == 3) {
            cout << "Inserisci tasto da assegnare a 'Avanti': ";
            cin.ignore();
            getline(cin, infront);
        } else if (choice == 4) {
            cout << "Inserisci tasto da assegnare a 'Sinistra': ";
            cin.ignore();
            getline(cin, sinistra);
        }else if (choice == 5) {
            cout << "Inserisci tasto da assegnare a 'Destra': ";
            cin.ignore();
            getline(cin, destra);
        }else if (choice == 6) {
            cout << "Inserisci tasto da assegnare a 'Indiestro': ";
            cin.ignore();
            getline(cin, indietro);
        }else if (choice == 7) {
            cout << "Inserisci tasto da assegnare a 'Inventario': ";
            cin.ignore();
            getline(cin, inventario);
        }else if (choice == 8) {
            cout << "Inserisci tasto da assegnare a 'Pietà': ";
            cin.ignore();
            getline(cin, pieta);
        }else if (choice == 9) {
            cout << "Inserisci tasto da assegnare a 'Scappare': ";
            cin.ignore();
            getline(cin, scappare);
        }else if (choice == 10) {
            cout << "Inserisci tasto da assegnare a 'Attaccare': ";
            cin.ignore();
            getline(cin, attaccare);
        } else if (choice == 11) {
            saveSettings();
            saveInventory();
<<<<<<< HEAD
            cout << "Impostazioni Salvate!\n";
            Invio();
=======
            cout << "Impostazioni Salvate!\n" <<"Premi invio per continuare.. ";
>>>>>>> 75fc54e26139bb65676293c738846c2800453a6b
            cin.ignore();
            cin.get();
        } else if (choice == 12) {
            break;
        }

    }  
}

void introduzioneGioco(){
    while (true) {
    clearScreen();
    printIntroductionTitle();
    cout << "\033[97;1m";
    cout << "Puoi muoverti facilmente nel mondo usanto i tasti: \n";
    cout << "\033[0m";
    cout << "\nCon il pulsante " << "\033[35m" << infront << "\033[0m" << " puoi andare avanti.\n";
    cout << "Con il pulsante " << "\033[35m" << sinistra << "\033[0m" << " puoi andare a sinistra.\n";
    cout << "Con il pulsante " << "\033[35m" << destra << "\033[0m" << " puoi andare a destra.\n";
    cout << "Con il pulsante " << "\033[35m" << indietro << "\033[0m" <<" puoi andare indietro.\n";
    Invio();
    
    cin.ignore();
    cin.get();
    clearScreen();
    printIntroductionTitle();
    cout << "\033[97;1m";
    cout << "Nel gioco ci sono fare cose che puoi fare: \n";
    cout << "\033[97;0m";
    cout << "\nCon il pulsante " << "\033[35m" << inventario << "\033[0m" << " puoi aprire lo zaino.\n";
    cout << "Con il pulsante " << "\033[35m" << pieta << "\033[0m" << " puoi lacsiare un nemico vivere.\n";
    cout << "Con il pulsante " << "\033[35m" << scappare << "\033[0m" << " puoi scappare da una battaglia per curarti.\n";
    cout << "Con il pulsante " << "\033[35m" << attaccare << "\033[0m" <<" puoi attaccare un nemico.\n";
    Invio();
    cin.get();

<<<<<<< HEAD
=======
    cout << "\033[90m";
    cout << "\nPremi invio per continuare...";
    cout << "\033[0m";

    cin.get();

>>>>>>> 75fc54e26139bb65676293c738846c2800453a6b
    clearScreen();
    printIntroductionTitle();
    cout << "\033[97;1m";
    cout << "Informazioni sul gioco\n";
    cout << "\033[97;0m";
<<<<<<< HEAD
    cout << "\nInizi con 5 cuori e puoi arrivare fino a 20.\n";
    cout << "I nemici fanno piu danno quando hai piu cuori.\n";
=======

    cout << "\nInizi con 5 cuori e puoi arrivare fino a 20.\n";
    cout << "I nemici fanno piu' danno quando hai piu' cuori.\n";
>>>>>>> 75fc54e26139bb65676293c738846c2800453a6b
    cout << "L'inventario non ha limiti di spazio.\n";
    cout << "Ci sono 4 livelli: 3 con mostri e boss, e l'ultimo con il boss finale.\n";
    cout << "I boss possono dropare amuleti e danno sempre una chiave.\n";
    cout << "Puoi portare armi e pozioni di cura.\n";
    cout << "Le tue scelte influenzano il gioco.\n";
    cout << "\033[97;1m";
    cout << "\nDopo che premi INVIO. Iniziera il gioco reale...";
    cout << "\033[97;0m";
<<<<<<< HEAD
    Invio();
    cin.get();

    clearScreen();
    displayIsola();
    cout << "\nCiao, so che sei un po stordito poiche non ricordi nulla e non sai perche su un'isola in mezzo al nulla ora ti raccontero tutto.\n";
    cout << "Tutto era iniziato nella tua camera mentre stavi guardando l'ultimo episodio di Twisted Metal/The Witcher mentre intorno a te cera un silenzio tombale.\n";
    cout << "All'improvviso sentissi un tonfo proveniente dalla finestra e cercassi di capire l'origine.\n";
    Invio();
    cin.get();

    clearScreen();
    displayIsola();
    cout << "\nAll'improvviso si ruppe la finestra e dopo quatro rapitori entrarono all'interno molto velocemente, tu provassi a reagire ma eri in svantaggio numerico quindi ti rapirono.\n";
    cout << "Quando ti svegliasti eri su un'sola legato con i quatro ladri davanti a te, tu trovassi un buon momento in cui erano distratti e scappasti ma dopo un po svenni per la stanchewzza.\n";
    cout << "Per questo ti trovi qui.\n";
    Invio();
=======

    cout << "\033[90m";
    cout << "\nPremi invio per continuare...";
    cout << "\033[0m";

    cin.get();

    clearScreen();

    ifstream file("ASCII/isola.txt");

    char c;
    while (file.get(c)) {
        cout << c;
    }

    file.close();
    cout << "\nCiao, so che sei un po stordito poiche non ricordi nulla e non sai perche su un'isola in mezzo al nulla ora ti raccontero tutto.\n";
    cout << "Tutto era iniziato nella tua camera mentre stavi guardando l'ultimo episodio di Twisted Metal/The Witcher mentre intorno a te cera un silenzio tombale.\n";
    cout << "All'improvviso sentissi un tonfo proveniente dalla finestra e cercassi di capire l'origine.\n";
    cout << "\033[90m";
    cout << "\nPremi invio per continuare...";
    cout << "\033[0m";
    cin.get();
    clearScreen();

    file.open("ASCII/isola.txt");

    char b;
    while (file.get(b)) {
        cout << b;
    }
    cout << "\nAll'improvviso si ruppe la finestra e dopo quatro rapitori entrarono all'interno molto velocemente, tu provassi a reagire ma eri in svantaggio numerico quindi ti rapirono.\n";
    cout << "Quando ti svegliasti eri su un'sola legato con i quatro ladri davanti a te, tu trovassi un buon momento in cui erano distratti e scappasti ma dopo un po svenni per la stanchewzza.\n";
    cout << "Per questo ti trovi qui.";

    cout << "\033[90m";
    cout << "\nPremi invio per continuare...";
    cout << "\033[0m";

>>>>>>> 75fc54e26139bb65676293c738846c2800453a6b
    cin.get();
    break;
    }
}

<<<<<<< HEAD
=======

>>>>>>> 75fc54e26139bb65676293c738846c2800453a6b
int main() {
    loadSettings();
    #if defined(_WIN32) || defined(_WIN64)
    SetConsoleOutputCP(CP_UTF8);
    #endif
    srand(time(NULL));
    while (true) {
        clearScreen();
        printTitle();
        cout << "\n1. Gioca " << endl;
        cout << "2. Crediti " << endl;
        cout << "3. impostazioni" << endl;
        cout << "4. Esci" << endl; 
        Input();

        int choice;
        cin >> choice;
        if (choice == 1) {
            introduzioneGioco();
<<<<<<< HEAD
=======
            combattimento(1, uccisioni1, mobs1);
            combattimento(2, uccisioni2, mobs2);
            combattimento(3, uccisioni3, mobs3);
>>>>>>> 75fc54e26139bb65676293c738846c2800453a6b
        } else if (choice == 2) {
            showCredits();
        } else if (choice == 3) {
            showSettings();
        } else if (choice == 4) {
            clearScreen();
            cout << "Arrivederci, ritorna da noi amore <3" << endl;
            break;
        } else {
            cout << "Scelta non valida."; 
            Invio();
            cin.ignore();
            cin.get();
        }

    }
}
