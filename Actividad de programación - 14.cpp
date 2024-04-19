/*******************************************************************************
NOMBRE: Angel Simón Navarro Martín
FECHA: 06/02/2024
PROGRAMA: Aumento de números
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERÍA EN COMPUTACIÓN / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas
DESCRIPCIÓN: Dependiendo el número insertado se realizan ciertos aumentos del número
*******************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<string> palabras = {
    "BritneySpears", "TwentyOnePilots", "Gorillaz", "AvengedSevenfold", "Molotov",
    "Aerosmith", "FiveFingerDeathPunch", "MyChemicalRomance", "DefLeppard", "MacMiller",
    "MileyCyrus", "MGMT", "MelanieMartinez", "LadyGaga", "LanaDelRey", "TaylorSwift",
    "Abba", "KanyeWest", "BillyJoel", "BackstreetBoys", "ChildishGambino", "TheWeekend",
    "Eminem", "KingsOfLeon", "TheNeighbourhood", "CageTheElephant", "BrunoMars",
    "ElCuartetoDeNos", "Slipknot", "REM", "Adele", "Canserbero", "VicenteFernandez",
    "JulietaVenegas", "FosterThePeople", "LilNasX", "ArcticMonkeys", "FooFighters",
    "ZZTop", "Oasis", "Audioslave", "ElvisPresley", "CreedenceClearwaterRevival",
    "Scorpions", "DaftPunk", "Pantera", "Radiohead", "DavidBowie", "PostMalone",
    "OneDirection", "MarilynManson", "Coldplay", "BonJovi", "NickelBack", "Blur",
    "BobMarley", "LedZeppelin", "TheRollingStones", "KISS", "GreenDay", "Nirvana",
    "Beethoven", "Metálica", "Skrillex", "TheBeatles", "PinkFloyd", "RedHotChiliPeppers",
    "GunsNRoses", "ImagineDragons", "ACDC", "Disturbed", "MichaelJackson", "Queen", "Rammstein"
};

string seleccionarPalabraAleatoria() {
    srand(time(nullptr));
    int indice = rand() % palabras.size();
    return palabras[indice];
}

void mostrarPalabra(const string& palabra, const vector<bool>& letrasDescubiertas) {
    for (size_t i = 0; i < palabra.length(); ++i) {
        if (letrasDescubiertas[i]) {
            cout << palabra[i] << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}

bool letraEstaEnPalabra(char letra, const string& palabra) {
    for (char c : palabra) {
        if (c == letra || c == toupper(letra)) {
            return true;
        }
    }
    return false;
}

bool palabraCorrecta(const string& intento, const string& palabra) {
    return intento == palabra;
}

int main() {
    string palabraAdivinar = seleccionarPalabraAleatoria();
    vector<bool> letrasDescubiertas(palabraAdivinar.length(), false);
    int vidas = 6;
    bool ganado = false;

    cout << "Bienvenido al juego del ahorcado!" << endl;
    cout << "Tienes 6 vidas. Adivina la palabra." << endl;

    while (vidas > 0 && !ganado) {
        cout << "Vidas restantes: " << vidas << endl;
        mostrarPalabra(palabraAdivinar, letrasDescubiertas);

        cout << "Ingresa una letra o intenta adivinar la palabra completa: ";
        string intento;
        cin >> intento;

        if (intento.length() == 1 && isalpha(intento[0])) {
            char letra = intento[0];
            if (letraEstaEnPalabra(letra, palabraAdivinar)) {
                for (size_t i = 0; i < palabraAdivinar.length(); ++i) {
                    if (palabraAdivinar[i] == letra || palabraAdivinar[i] == toupper(letra)) {
                        letrasDescubiertas[i] = true;
                    }
                }
                if (toupper(letra) == 'A' || toupper(letra) == 'E' || toupper(letra) == 'I' ||
                    toupper(letra) == 'O' || toupper(letra) == 'U') {
                    vidas--;
                    cout << "Correcto, pero por ser vocal te quito una vida." << endl;
                }
            } else {
                cout << "Letra incorrecta." << endl;
                vidas--;
            }

            bool todasDescubiertas = true;
            for (bool descubierto : letrasDescubiertas) {
                if (!descubierto) {
                    todasDescubiertas = false;
                    break;
                }
            }

            if (todasDescubiertas) {
                ganado = true;
            }
        } else if (intento.length() > 1) {
            if (palabraCorrecta(intento, palabraAdivinar)) {
                ganado = true;
            } else {
                cout << "Palabra incorrecta." << endl;
                vidas--;
            }
        } else {
            cout << "Entrada no válida. Ingresa una letra o intenta adivinar la palabra completa." << endl;
        }
    }

    if (ganado) {
        cout << "Felicidades! Has adivinado la palabra: " << palabraAdivinar << endl;
    } else {
        cout << "Perdiste. La palabra era: " << palabraAdivinar << endl;
    }

    return 0;
}

