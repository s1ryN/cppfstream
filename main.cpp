#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>  // pro std::system

using namespace std;

int main() {
    // 1) Zeptáme se na název souboru (bez mezer)
    string filename;
    cout << "Zadejte název souboru k vytvoření: ";
    cin >> filename;

    // 2) Vytvoříme a otevřeme soubor pro zápis
    ofstream outfile(filename);
    if (!outfile) {
        cerr << "Chyba: nelze vytvořit soubor \""
             << filename << "\"\n";
        return 1;
    }

    // 3) Zeptáme se na tajné číslo a uložíme ho do souboru
    string secret;
    cout << "Zadejte své tajné číslo: ";
    cin >> secret;
    outfile << secret;

    // 4) Vyprázdníme výstupní buffer a zavřeme soubor
    outfile.flush();
    outfile.close();

    // 5) Vyprázdníme OS vyrovnávací paměť (na Linuxu pomocí "sync")
    system("sync");

    // 6) Otevřeme soubor pro čtení a vypíšeme jeho obsah
    ifstream infile(filename);
    if (!infile) {
        cerr << "Chyba: nelze otevřít soubor \""
             << filename << "\" pro čtení\n";
        return 1;
    }

    string content;
    cin.clear();               // (volitelně) obnovíme stav cin
    infile >> content;         // načteme celý řetězec (bez mezer)
    infile.close();

    cout << "Obsah souboru: " << content << endl;
    return 0;
}
