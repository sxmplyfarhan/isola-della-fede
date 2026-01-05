#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#endif
#include <time.h>
using namespace std;
// Variabili
string mob;
string mobs1[3] = {"Scimmia", "Cane", "Rana"};
string mobs2[3] = {"Pipistrello", "Farfalla", "Ragno"};
string mobs3[3] = {"Centauro", "Mietitore", "Fenice"};
string inventariospace[30];
string playerName ="Giocatore";
string difficulty = "Normale";
string infront = "w"; 
string sinistra = "a";
string destra ="d";
string indietro = "s";
string pieta = "r";
string scappare = "l";
string attaccare = "q";
double vita = 5.0;
double vitaMax = 5.0;
int nemiciUccisi = 0;
int esperienza = 1;
bool hasTotem = false;
bool hasShield = false;
// Funzioni per tutto il codice
void clearScreen() {
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #else
        system("clear");
    #endif
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
    cin.ignore();
    cin.get(); 
}
void linea(){
    cout << "\033[35m";
    cout << "\n────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────\n";
    cout << "\033[0m";
}
//funzioni ascii per il gioco
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
void displayCane() {
    displayAsciiArt("ASCII/cane.txt");
}
void displayCentauro() {
    displayAsciiArt("ASCII/centauro.txt");
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
void displayRana() {
    displayAsciiArt("ASCII/rana.txt");
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
void displaySkull() {
    displayAsciiArt("ASCII/skull.txt");
}
void displayCamera() {
    displayAsciiArt("ASCII/camera.txt");
}
void displayChest() {
    displayAsciiArt("ASCII/chest.txt");
}
void displayTotem(){
    displayAsciiArt("ASCII/totem.txt");
}
void displayBedroom() {
    displayAsciiArt("ASCII/bedroom.txt");
}
void displaySea() {
    displayAsciiArt("ASCII/sea.txt");
}
void displayTrail() {
    displayAsciiArt("ASCII/trail.txt");
}
void displayForest() {
    displayAsciiArt("ASCII/forest.txt");
}
void displayMob(const string& mob) {
    if (mob == "Boss") {
        displayBoss();
    } else if (mob == "Cane") {
        displayCane();
    } else if (mob == "Centauro") {
        displayCentauro();
    } else if (mob == "Dragon") {
        displayDragon();
    } else if (mob == "Farfalla") {
        displayFarfalla();
    } else if (mob == "Fenice") {
        displayFenice();
    } else if (mob == "Rana") {
        displayRana();
    } else if (mob == "GoblinKing") {
        displayGoblinKing();
    } else if (mob == "Reaper") {
        displayReaper();
    } else if (mob == "Isola") {
        displayIsola();
    } else if (mob == "Bat") {
        displayBat();
    } else if (mob == "Ragni") {
        displayRagni();
    } else if (mob == "Scimmia") {
        displayScimmie();
    } else if (mob == "VampireBoss") {
        displayVampireBoss();
    } 
}
// Funzione per tutti i titoli
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
//funzioni esperienza e vita
void livelloEsperienza() {
    if (difficulty == "Normale" ) {
            if (nemiciUccisi >= 3) {
                esperienza++;
                vita = vita + 2.5;
                vitaMax += 2.5;
                cout << "Congratulazioni, Sei arrivato al livello. " << esperienza << "\n Adesso hai Vita: " << vita ;
            }
    } else if (difficulty == "Facile") {
                if (nemiciUccisi >= 2) {
                    esperienza++;
                    vita = vita + 3.5;
                    vitaMax += 3.5;
                cout << "Congratulazioni, hai ottenuto più esperienza. \nEsperienza: " << esperienza << "\nVita: " << vita ;
            }
    } else if (difficulty == "Difficile") {
                if (nemiciUccisi >= 5) {
                    esperienza++;
                    vita = vita + 1.5;
                    vitaMax += 1.5;
                cout << "Congratulazioni, hai ottenuto più esperienza. \nEsperienza: " << esperienza << "\nVita: " << vita ;
            }
    }
}
void menuVita(){
    cout << "\033[31m";
    cout << "┌───────────┐";
    cout << "\033[0m\n";
    cout << "\033[31m";
    cout << "| ";
    cout << "\033[0m";
    cout << "Vita = " << vita;
    cout << "\033[31m";
    cout << "  | ";
    cout << "\033[0m\n"; 
    cout << "\033[31m";
    cout << "└───────────┘";
    cout << "\033[0m\n";
}
void menuVitaPiuScudo(){
    cout << "\033[31m";
    cout << "┌───────────┐";
    cout << "\033[0m";
    cout << "\033[90m";
    cout << " ┌──────────────┐";
    cout << "\033[0m";
    cout << "\033[31m\n";
    cout << "| ";
    cout << "\033[0m";
    cout << "Vita = " << vita;
    cout << "\033[31m";
    cout << "  |";
    cout << "\033[0m"; 
    cout << "\033[90m";
    cout << " | ";
    cout << "\033[0m"; 
    cout << "Scudo = True";
    cout << "\033[90m";
    cout << " | ";
    cout << "\033[0m\n"; 
    cout << "\033[31m";
    cout << "└───────────┘";
    cout << "\033[0m";
    cout << "\033[90m";
    cout << " └──────────────┘";
    cout << "\033[0m\n";
}
void menuVitaPiuTotem(){
    cout << "\033[31m";
    cout << "┌───────────┐";
    cout << "\033[0m";
    cout << "\033[33m";
    cout << " ┌──────────────┐";
    cout << "\033[0m";
    cout << "\033[31m\n";
    cout << "| ";
    cout << "\033[0m";
    cout << "Vita = " << vita;
    cout << "\033[31m";
    cout << "  |";
    cout << "\033[0m"; 
    cout << "\033[33m";
    cout << " | ";
    cout << "\033[0m"; 
    cout << "Totem = True";
    cout << "\033[33m";
    cout << " | ";
    cout << "\033[0m\n"; 
    cout << "\033[31m";
    cout << "└───────────┘";
    cout << "\033[0m";
    cout << "\033[33m";
    cout << " └──────────────┘";
    cout << "\033[0m\n";
}
void menuVitaConTutto(){
    cout << "\033[31m";
    cout << "┌───────────┐";
    cout << "\033[0m";
    cout << "\033[33m";
    cout << " ┌──────────────┐";
    cout << "\033[0m";
    cout << "\033[90m";
    cout << " ┌──────────────┐";
    cout << "\033[0m";
    cout << "\033[31m\n";
    cout << "| ";
    cout << "\033[0m";
    cout << "Vita = " << vita;
    cout << "\033[31m";
    cout << "  |";
    cout << "\033[0m"; 
    cout << "\033[33m";
    cout << " | ";
    cout << "\033[0m"; 
    cout << "Totem = True";
    cout << "\033[33m";
    cout << " |";
    cout << "\033[0m"; 
    cout << "\033[90m";
    cout << " | ";
    cout << "\033[0m"; 
    cout << "Scudo = True";
    cout << "\033[90m";
    cout << " | ";
    cout << "\033[0m\n"; 
    cout << "\033[31m";
    cout << "└───────────┘";
    cout << "\033[0m";
    cout << "\033[33m";
    cout << " └──────────────┘";
    cout << "\033[0m";
    cout << "\033[90m";
    cout << " └──────────────┘";
    cout << "\033[0m\n";
}
void scegliMenu(){
    if (hasTotem == true && hasShield == true) {
        menuVitaConTutto();
    } else if (hasTotem == true) {
        menuVitaPiuTotem();
    } else if (hasShield == true) {
        menuVitaPiuScudo();
    } else {
        menuVita();
    }
}
//funzioni per quando vai avanti. RANDOM
void niente(){
    cout << "Non hai trovato niente";
}
void apriChest() {
    clearScreen();
    scegliMenu();
    displayChest();
    linea();
    cout << "Hai trovato un forziere misterioso..." << endl;
    Invio();

    int chance = rand() % 100; 

    if (chance < 20) {
        cout << "Il forziere è vuoto... che delusione." << endl;
    } else {
        int itemType = rand() % 6; 
        switch (itemType) {
            case 0: { 
                cout << "Hai trovato una pozione di cura!" << endl;
                double heal = 3.0;
                vita += heal;
                cout << "Ti senti meglio. + " << heal << " vita. (Totale: " << vita << ")" << endl;
                break;
            }
            case 1: { 
                cout << "Hai bevuto una pozione strana... era avvelenata!" << endl;
                applyDamage(2.0);
                cout << "- 2.0" << " vita. (Totale: " << vita << ")" << endl;
                break;
            }
            case 2: { 
                cout << "Hai trovato una pozione nera... la tocchi e senti il gelo della morte!" << endl;
                if (hasTotem) {
                    cout << "Il tuo totem si illumina e ti salva dalla morte certa!" << endl;
                    hasTotem = false;
                } else {
                    applyDamage(1000000.0);
                }
                break;
            }
            case 3: { 
                if (hasTotem) {
                    cout << "Hai trovato un altro totem... ma ne hai già uno attivo. Lo lasci dove sta." << endl;
                } else {
                    cout << "Hai trovato un totem della seconda vita!" << endl;
                    hasTotem = true;
                    cout << "Ora sarai salvato una volta se muori." << endl;
                }
                break;
            }
            case 4: { 
                cout << "Hai trovato della frutta fresca!" << endl;
                double heal = 1.5;
                vita += heal;
                cout << "Ti cura leggermente. + " << heal << " vita. (Totale: " << vita << ")" << endl;
                break;
            }
            case 5: { 
                if (hasShield) {
                    cout << "Hai trovato uno scudo... ma ne hai già uno. Lo lasci per non appesantirti." << endl;
                } else {
                    cout << "Hai trovato uno scudo magico!" << endl;
                    hasShield = true;
                    cout << "50% di probabilità di bloccare il prossimo danno." << endl;
                }
                break;
            }
        }
    }
    linea();
    Invio();
}
void combattimento(int livello, int &nemiciUccisi, string mobs[3]) {
    if (difficulty == "Facile"){
        combattimentoFacile(livello, nemiciUccisi, mobs);
    }
    else if (difficulty == "Normale"){
        combattimentoNormale(livello, nemiciUccisi, mobs);
    }
    else if (difficulty == "Difficile"){
        combattimentoDifficile(livello, nemiciUccisi, mobs);
    }
}
//Funzione danno
void applyDamage(double damage) {
    if (hasShield) {
        int chance = rand() % 2; 
        if (chance == 0) {
            cout << "\nIl tuo scudo blocca completamente il danno!" << endl;
            hasShield = false; 
            Invio();
            return; 
        } else {
            cout << "\nLo scudo non riesce a bloccare il danno..." << endl;
            hasShield = false; 
        }
    }

    
    vita -= damage;

    
    if (vita <= 0.01 && hasTotem) {
        clearScreen();
        scegliMenu();
        displayTotem();
        linea();
        cout << "\nIl tuo totem si illumina! Ti salva dalla morte..." << endl;
        vita = vitaMax; 
        hasTotem = false;
        return;
    }

    
    if (vita <= 0.01) {
        clearScreen();
        displaySkull();
        cout << "\nGame Over! Hai perso tutta la tua vita..." << endl;
        Invio();
        exit(0);
    }
}
//funzioni combattimento con difficolta "Facile/Normale/Difficile"
void combattimentoFacile(int livello, int &nemiciUccisi, string mobs[3]){
    clearScreen();
    string scelta;
    string mob = mobs[rand() % 3];
    if (livello == 2 && mob == "Farfalla") {
    cout << "Sei stato fortunato, la farfalla ti cura!" << endl;
    vita += 4;
    return; 
}
    else{
        scegliMenu();
        displayMob(mob);
        linea();
        cout << "Hai incontrato : " << mob << "!" << endl;
        cout << "Vuoi attaccare (premi '" << attaccare << "'), essere misericordioso (premi '" << pieta << "') o scappare (premi '" << scappare << "')? ";
        Input();
        cin >> scelta;
        if (scelta == attaccare) {
            cout << "Hai attaccato : " << mob << " e lo hai sconfitto!" << endl;
            nemiciUccisi++;
            cout << "Hai perso della vita...";
            applyDamage(1.0);
        } else if (scelta == pieta) {
            cout << "Sei stato misericordioso con : " << mob << " e lo hai lasciato andare.Tuttavia prendi del danno :(" << endl;
            applyDamage(1.0);
        } else if (scelta == scappare) {
        cout << "Sei scappato da : " << mob << " per curarti." << endl;
        } else {
            cout << "Scelta non valida. " << mob << " ti ha attaccato mentre eri indeciso!" << endl;
            applyDamage(3.0);
        }
    }
    Invio();
}
void combattimentoDifficile(int livello, int &nemiciUccisi, string mobs[3]){
    clearScreen();
    string scelta;
    string mob = mobs[rand() % 3];
    if (livello == 2 && mob == "Farfalla") {
    cout << "Sei stato fortunato, la farfalla ti cura!" << endl;
    vita += 0.5;
    return; // finisce il combattimento
}
    else{
        scegliMenu();
        displayMob(mob);
        linea();
        cout << "Hai incontrato : " << mob << "!" << endl;
        cout << "Vuoi attaccare (premi '" << attaccare << "'), essere misericordioso (premi '" << pieta << "') o scappare (premi '" << scappare << "')? ";
        Input();
        cin >> scelta;
        if (scelta == attaccare) {
            cout << "Hai attaccato : " << mob << " e lo hai sconfitto!" << endl;
            nemiciUccisi++;
            cout << "Hai perso della vita...";
            applyDamage(3.0);
        } else if (scelta == pieta) {
            cout << "Sei stato misericordioso con : " << mob << " e lo hai lasciato andare.Tuttavia prendi del danno :(" << endl;
            applyDamage(4.0);
        } else if (scelta == scappare) {
        cout << "Sei scappato da : " << mob << " per curarti." << endl;
        } else {
            cout << "Scelta non valida. " << mob << " ti ha attaccato mentre eri indeciso!" << endl;
            applyDamage(9.0);
        }
    }
    Invio();
}
void combattimentoNormale(int livello, int &nemiciUccisi, string mobs[3]){
    clearScreen();
    string scelta;
    string mob = mobs[rand() % 3];
    if (livello == 2 && mob == "Farfalla") {
    cout << "Sei stato fortunato, la farfalla ti cura!" << endl;
    vita += 3;
    return; // finisce il combattimento
}
    else{
        scegliMenu();
        displayMob(mob);
        linea();
        cout << "Hai incontrato : " << mob << "!" << endl;
        cout << "Vuoi attaccare (premi '" << attaccare << "'), essere misericordioso (premi '" << pieta << "') o scappare (premi '" << scappare << "')? ";
        Input();
        cin >> scelta;
        if (scelta == attaccare) {
            cout << "Hai attaccato : " << mob << " e lo hai sconfitto!" << endl;
            nemiciUccisi++;
            cout << "Hai perso della vita...";
            applyDamage(1.5);
        } else if (scelta == pieta) {
            cout << "Sei stato misericordioso con : " << mob << " e lo hai lasciato andare.Tuttavia prendi del danno :(" << endl;
            applyDamage(2.0);
        } else if (scelta == scappare) {
        cout << "Sei scappato da : " << mob << " per curarti." << endl;
        } else {
            cout << "Scelta non valida. " << mob << " ti ha attaccato mentre eri indeciso!" << endl;
            applyDamage(6.0);
        }
    }
    Invio();
}
// Combattimento Tutti i boss 
void combattimentoGoblinKing() {
    double toglivita = vita/5.0;
    char scelta;

    clearScreen();
    scegliMenu();
    displayGoblinKing();
    linea();
    cout << "1. Perchè in C++ gli array partono dall'indice 0?" << endl;
    cout << "A. Per comodità dei programmatori" << endl;
    cout << "B. Perché l’indice rappresenta uno spostamento in memoria" << endl;
    cout << "C. Per motivi grafici" << endl;
    cout << "D. Per risparmiare spazio" << endl;
    Input();
    cin >> scelta;

    if (scelta == 'B') {
        cout << "Hai risposto correttamente..\n Che fortuna che hai avuto.. non hai perso vita." << endl;
    } else {
        cout << "Hai risposto male... hai perso 1/5 della tua vita.." << endl;
        applyDamage(toglivita);
    }

    Invio();


    clearScreen();
    scegliMenu();
    displayGoblinKing();
    linea();
    cout << "2. Quale di questi è un uso comune degli array nei videogiochi?" << endl;
    cout << "A. Stampare testo" << endl;
    cout << "B. Memorizzare nemici, oggetti o livelli" << endl;
    cout << "C. Creare finestre" << endl;
    cout << "D. Gestire il mouse" << endl;
    Input();
    cin >> scelta;

    if (scelta == 'B') {
        cout << "Hai risposto correttamente..\n Che fortuna che hai avuto.. non hai perso vita." << endl;
    } else {
        cout << "Hai risposto male... hai perso 1/5 della tua vita.." << endl;
        applyDamage(toglivita);
    }

    Invio();

    
    clearScreen();
    scegliMenu();
    displayGoblinKing();
    linea();
    cout << "3. Da quanto tempo esistono gli array in informatica?" << endl;
    cout << "A. Dagli anni 2000" << endl;
    cout << "B. Dagli anni 90" << endl;
    cout << "C. Dagli anni ’50" << endl;
    cout << "D. Dal 2010" << endl;
    Input();
    cin >> scelta;

    if (scelta == 'C') {
        cout << "Hai risposto correttamente..\n Che fortuna che hai avuto.. non hai perso vita." << endl;
    } else {
        cout << "Hai risposto male... hai perso 1/5 della tua vita.." << endl;
        applyDamage(toglivita); 
    }

    Invio();


    
    clearScreen();
    scegliMenu();
    displayGoblinKing();
    linea();
    cout << "4. Perché una variabile si chiama così?" << endl;
    cout << "A. Perché è casuale" << endl;
    cout << "B. Perché è costante" << endl;
    cout << "C. Perché il suo valore può cambiare" << endl;
    cout << "D. Perché è numerica" << endl;
    Input();
    cin >> scelta;

    if (scelta == 'C') {
        cout << "Hai risposto correttamente..\n Che fortuna che hai avuto.. non hai perso vita." << endl;
    } else {
        cout << "Hai risposto male... hai perso 1/5 della tua vita.." << endl;
        applyDamage(toglivita);  
    }

    Invio();

    
    clearScreen();
    scegliMenu();
    displayGoblinKing();
    linea();
    cout << "5. Quale struttura dati è basata direttamente sugli array?" << endl;
    cout << "A. Funzioni" << endl;
    cout << "B. Classi" << endl;
    cout << "C. Vettori e matrici" << endl;
    cout << "D. Cicli" << endl;
    Input();
    cin >> scelta;

    if (scelta == 'C') {
        cout << "Hai risposto correttamente..\n Che fortuna che hai avuto.. non hai perso vita." << endl;
    } else {
        cout << "Hai risposto male... hai perso 1/5 della tua vita.." << endl;
        applyDamage(toglivita);
    }
    
    Invio();

    // Final screen after all questions
    clearScreen();
    scegliMenu();
    linea();
    cout << "Hai completato il livello 1, ti stai avvicinando al cuore dell'isola.." << endl;

}
void combattimentoVampiro() {
    double toglivita = vita / 5.0;
    char scelta;

    clearScreen();
    scegliMenu();
    displayVampireBoss();
    linea();
    cout << "1. Perché il C++ NON controlla automaticamente i limiti degli array?" << endl;
    cout << "A. Per semplicità" << endl;
    cout << "B. Per errore" << endl;
    cout << "C. Per essere più veloce" << endl;
    cout << "D. Per sicurezza" << endl;
    Input();
    cin >> scelta;

    if (scelta == 'C') {
        cout << "Hai risposto correttamente..\n Che fortuna che hai avuto.. non hai perso vita." << endl;
    } else {
        cout << "Hai risposto male... hai perso 1/5 della tua vita.." << endl;
        applyDamage(toglivita);
    }

    Invio();

    clearScreen();
    scegliMenu();
    displayVampireBoss();
    linea();
    cout << "2. D. Per sicurezza" << endl;
    cout << "A. È più veloce" << endl;
    cout << "B. Non modifica la variabile originale" << endl;
    cout << "C. Usa meno memoria" << endl;
    cout << "D. Evita i bug" << endl;
    Input();
    cin >> scelta;

    if (scelta == 'B') {
        cout << "Hai risposto correttamente..\n Che fortuna che hai avuto.. non hai perso vita." << endl;
    } else {
        cout << "Hai risposto male... hai perso 1/5 della tua vita.." << endl;
        applyDamage(toglivita);
    }

    Invio();

    clearScreen();
    scegliMenu();
    displayVampireBoss();
    linea();
    cout << "3. In quale situazione è meglio usare il passaggio per riferimento?" << endl;
    cout << "A. Quando non serve modificare dati" << endl;
    cout << "B. Quando si vogliono modificare variabili esterne" << endl;
    cout << "C. Solo con int" << endl;
    cout << "D. Solo con stringhe" << endl;
    Input();
    cin >> scelta;

    if (scelta == 'B') {
        cout << "Hai risposto correttamente..\n Che fortuna che hai avuto.. non hai perso vita." << endl;
    } else {
        cout << "Hai risposto male... hai perso 1/5 della tua vita.." << endl;
        applyDamage(toglivita); 
    }

    Invio();

    clearScreen();
    scegliMenu();
    displayVampireBoss();
    linea();
    cout << "4. Perché const è molto usato nelle librerie professionali?" << endl;
    cout << "A. Rende il codice più corto" << endl;
    cout << "B. Rende il programma più bello" << endl;
    cout << "C. Previene modifiche accidentali" << endl;
    cout << "D. Aumenta la memoria" << endl;
    Input();
    cin >> scelta;

    if (scelta == 'C') {
        cout << "Hai risposto correttamente..\n Che fortuna che hai avuto.. non hai perso vita." << endl;
    } else {
        cout << "Hai risposto male... hai perso 1/5 della tua vita.." << endl;
        applyDamage(toglivita); 
    }

    Invio();

    clearScreen();
    scegliMenu();
    displayVampireBoss();
    linea();
    cout << "5. Quale problema comune causa errori negli array?" << endl;
    cout << "A. Troppi commenti" << endl;
    cout << "B. Uso di cout" << endl;
    cout << "C. Indice fuori dai limiti" << endl;
    cout << "D. Uso delle funzioni" << endl;
    Input();
    cin >> scelta;

    if (scelta == 'C') {
        cout << "Hai risposto correttamente..\n Che fortuna che hai avuto.. non hai perso vita." << endl;
    } else {
        cout << "Hai risposto male... hai perso 1/5 della tua vita.." << endl;
        applyDamage(toglivita); 
    }


    Invio();

    clearScreen();
    scegliMenu();
    linea();
    cout << "Hai completato il livello 2! La tua avventura continua..." << endl;
}
void combattimentoDrago(){
    double toglivita = vita / 5.0;
    char scelta;

    clearScreen();
    scegliMenu();
    displayDragon();
    linea();
    cout << "1. Perché il passaggio per riferimento migliora le prestazioni?" << endl;
    cout << "A. Usa più CPU" << endl;
    cout << "B. Evita la copia di grandi dati" << endl;
    cout << "C. Duplica la memoria" << endl;
    cout << "D. Evita i cicli" << endl;
    Input();
    cin >> scelta;

    if (scelta == 'B') {
        cout << "Hai risposto correttamente..\n Che fortuna che hai avuto.. non hai perso vita." << endl;
    } else {
        cout << "Hai risposto male... hai perso 1/5 della tua vita.." << endl;
        applyDamage(toglivita); 
    }

    Invio();

    clearScreen();
    scegliMenu();
    displayDragon();
    linea();
    cout << "2. Qual è uno dei principali rischi del C++ rispetto ad altri linguaggi moderni??" << endl;
    cout << "A. È troppo lento" << endl;
    cout << "B. Gestione manuale della memoria" << endl;
    cout << "C. Non usa funzioni" << endl;
    cout << "D. Non usa classi" << endl;
    Input();
    cin >> scelta;

    if (scelta == 'B') {
        cout << "Hai risposto correttamente..\n Che fortuna che hai avuto.. non hai perso vita." << endl;
    } else {
        cout << "Hai risposto male... hai perso 1/5 della tua vita.." << endl;
        applyDamage(toglivita);
    }

    Invio();

    clearScreen();
    scegliMenu();
    displayDragon();
    linea();
    cout << "3. Perché molti bug storici sono causati dagli array?" << endl;
    cout << "A. Sono nuovi" << endl;
    cout << "B. Non hanno controllo automatico dei limiti" << endl;
    cout << "C. Usano stringhe" << endl;
    cout << "D. Sono lenti" << endl;
    Input();
    cin >> scelta;

    if (scelta == 'B') {
        cout << "Hai risposto correttamente..\n Che fortuna che hai avuto.. non hai perso vita." << endl;
    } else {
        cout << "Hai risposto male... hai perso 1/5 della tua vita.." << endl;
        applyDamage(toglivita);
    }

    Invio();

    clearScreen();
    scegliMenu();
    displayDragon();
    linea();
    cout << "4. In quali ambiti è ancora molto usato il C++ oggi?" << endl;
    cout << "A. Solo scuola" << endl;
    cout << "B. Per la creazione di siti Web" << endl;
    cout << "C. Videogiochi, sistemi operativi, motori grafici" << endl;
    cout << "D. Social network" << endl;
    Input();
    cin >> scelta;

    if (scelta == 'C') {
        cout << "Hai risposto correttamente..\n Che fortuna che hai avuto.. non hai perso vita." << endl;
    } else {
        cout << "Hai risposto male... hai perso 1/5 della tua vita.." << endl;
        applyDamage(toglivita);
    }

    
    Invio();


    clearScreen();
    scegliMenu();
    displayDragon();
    linea();
    cout << "5. Perché il C++ viene ancora insegnato a scuola nonostante sia complesso?" << endl;
    cout << "A. Perché è facile" << endl;
    cout << "B. Perché è nuovo" << endl;
    cout << "C. Per comprendere la memoria " << endl;
    cout << "D. Perché non esistono alternative" << endl;
    Input();
    cin >> scelta;

    if (scelta == 'C') {
        cout << "Hai risposto correttamente..\n Che fortuna che hai avuto.. non hai perso vita." << endl;
    } else {
        cout << "Hai risposto male... hai perso 1/5 della tua vita.." << endl;
        applyDamage(toglivita);
    }

    Invio();

    clearScreen();
    scegliMenu();
    linea();
    cout << "Hai completato il livello 3! Il boss ti sta aspettando..." << endl;
}
// Carica e salva impostazioni
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
                else if (key == "pieta") pieta = value;
                else if (key == "scappare") scappare = value;
                else if (key == "attaccare") attaccare = value;
            }
        }
        in.close();
    }
}
void saveSettings() {
    ofstream out("impostazioni.txt"); //scrive
    out << "playerName = " << playerName << "\n";
    out << "difficulty = " << difficulty << "\n";
    out << "infront = " << infront << "\n";
    out << "sinistra = " << sinistra << "\n";
    out << "destra = " << destra << "\n";
    out << "indietro = " << indietro << "\n";
    out << "pieta = " << pieta << "\n";
    out << "scappare = " << scappare << "\n";
    out << "attaccare = " << attaccare << "\n";
    out.close();
}
//funzioni per menu inizialle
void showCredits() {
    clearScreen();
    printCreditsTitle();
    cout << "Questi sono i crediti";

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
        cout << "7. Pietá: " <<  pieta << endl;
        cout << "8. Scappare: " <<  scappare << endl;
        cout << "9. Attaccare: " <<  attaccare << endl;
        cout << "10. Salva " << endl;
        cout << "11. Esci" << endl;
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
            } else if (difficulty == "Normale") {
                difficulty = "Difficile";
                cout << "Difficolta' impostata su: " << difficulty << endl;
                Invio();
            } else {
                difficulty = "Facile";
                cout << "Difficolta' impostata su: " << difficulty << endl;
                Invio();
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
            cout << "Inserisci tasto da assegnare a 'Pietà': ";
            cin.ignore();
            getline(cin, pieta);
        }else if (choice == 8) {
            cout << "Inserisci tasto da assegnare a 'Scappare': ";
            cin.ignore();
            getline(cin, scappare);
        }else if (choice == 9) {
            cout << "Inserisci tasto da assegnare a 'Attaccare': ";
            cin.ignore();
            getline(cin, attaccare);
        } else if (choice == 10) {
            saveSettings();
            cout << "Impostazioni Salvate!\n";
            Invio();
        } else if (choice == 11) {
            break;
        }

    }  
}
// Gioco
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
    
    clearScreen();
    printIntroductionTitle();
    cout << "\033[97;1m";
    cout << "Nel gioco ci sono fare cose che puoi fare: \n";
    cout << "\033[97;0m";
    cout << "\nCon il pulsante " << "\033[35m" << pieta << "\033[0m" << " puoi lacsiare un nemico vivere.\n";
    cout << "Con il pulsante " << "\033[35m" << scappare << "\033[0m" << " puoi scappare da una battaglia per curarti.\n";
    cout << "Con il pulsante " << "\033[35m" << attaccare << "\033[0m" <<" puoi attaccare un nemico.\n";
    Invio();

    clearScreen();
    printIntroductionTitle();
    cout << "\033[97;1m";
    cout << "Informazioni sul gioco\n";
    cout << "\033[97;0m";
    cout << "\nInizi con 5 cuori e puoi arrivare fino a 20.\n";
    cout << "I nemici fanno piu danno quando hai piu cuori.\n";
    cout << "L'inventario non ha limiti di spazio.\n";
    cout << "Ci sono 4 livelli: 3 con mostri e boss, e l'ultimo con il boss finale.\n";
    cout << "I boss possono dropare amuleti e danno sempre una chiave.\n";
    cout << "Puoi portare armi e pozioni di cura.\n";
    cout << "Le tue scelte influenzano il gioco.\n";
    cout << "\033[97;1m";
    cout << "\nDopo che premi INVIO. Iniziera il gioco reale...";
    cout << "\033[97;0m";
    Invio();


    clearScreen();
    displayIsola();
    linea();
    cout << "\nCiao, so che sei un po' stordito, sono successe un paio di cose che ti hanno portato su quest'isola. Ora ti racconto tutto.\n";
    Invio();

    clearScreen();
    displayBedroom();
    linea();
    cout << "\nTutto era iniziato nella tua camera mentre stavi guardando l'ultimo episodio di Twisted Metal/The Witcher (oppure mentre stavi leggendo 'Niente di nuovo sul fronte occidentale')";
    cout << ",intorno a te c'era un silenzio tombale.\n";
    cout << "All’improvviso un tonfo proveniente dalla finestra attirò la tua attenzione e provasti a capire da dove provenisse.\n";
    cout << "Pochi secondi dopo la finestra si frantumò e quattro figure irruppero in camera tua, nel tentaivo di scappare facesti un rumore e una delle figure ti stordì.\n";
    Invio();

    clearScreen();
    displayIsola();
    linea();
    cout << "\nQuando ti svegliasti eri sull'isola legato con i quattro ladri che stavano discutendo, in qualche modo riuscisti a slegarti e ti allontanasti da loro.\n";
    cout << "Per questo ti trovi qui.\n";
    Invio();
    break;
    }
    }
void livelloUno() {
    int contaAvanti = 0;
    const int NORMALE = 0;
    const int MARE = 1;
    const int FORESTA = 2;
    
    int stato = NORMALE;
    string choice;

    do {
        if (contaAvanti >= 15) {
            combattimentoGoblinKing();
        }
        clearScreen();
        scegliMenu();
        displayIsola();
        linea();

        Input();
        cin >> choice;

        if (stato == NORMALE) {  // stato di partenza

            if (choice == sinistra) {
                clearScreen();
                scegliMenu();
                displaySea();
                linea();
                cout << "Stai guardando il mare, l'acqua è cristallina e si sente il suono delle onde che si infrangono sulla riva.\n";
                stato = MARE;
            }
            else if (choice == destra) {
                clearScreen();
                scegliMenu();
                displayForest();
                linea();
                cout << "Stai guardando la foresta fitta e oscura." << endl;
                stato = FORESTA;
            }
            else if (choice == infront) {
                clearScreen();
                scegliMenu();
                displayTrail();
                linea();
                cout << "Avanzi lungo il sentiero deserto." << endl;
                contaAvanti++;
            }
            else if (choice == indietro) {
                cout << "Torni indietro." << endl;
                contaAvanti--;
            }
        }

        else if (stato == MARE) {  // stato quando sta guardando il mare ovvero sinistra
            if (choice == infront) {
                clearScreen();
                scegliMenu();
                displaySea();
                linea();
                cout << "L'acqua è troppo profonda, è pericoloso andare avanti." << endl;
            }
            else if (choice == destra || choice == sinistra) {
                clearScreen();
                scegliMenu();
                displayTrail();
                linea();
                cout << "Sei andato fuori strada, devi tornare indietro." << endl;
            }
            else if (choice == indietro) {
                cout << "Torni sui tuoi passi." << endl;
                stato = NORMALE;
            }
        }


        else if (stato == FORESTA) {   // stato quando sta guardando la foresta ovvero destra
            if (choice == infront) {
                clearScreen();
                scegliMenu();
                displayForest();
                linea();
                cout << "La foresta è fitta e pericolosa, non sai cosa può nascondersi." << endl;
            }
            else if (choice == destra || choice == sinistra) {
                clearScreen();
                scegliMenu();
                displayTrail();
                linea();
                cout << "Sei andato fuori strada, devi tornare indietro." << endl;
            }
            else if (choice == indietro) {
                cout << "Torni sui tuoi passi." << endl;
                stato = NORMALE;
            }
        }

        Invio();

    } while (true);

}
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
            livelloUno();
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
