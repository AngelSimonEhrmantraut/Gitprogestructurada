/******************************************************************************
NOMBRE: Angel Simón Navarro Martín
FECHA: 09/04/2024
PROGRAMA: Descripción de frases
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERÍA EN COMPUTACIÓN / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas
DESCRIPCIÓN: Describir la frase o palabra escrita:(Vocales, consonantes, espacios y si es palíndromo)
*******************************************************************************/
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Función para contar el número de vocales, consonantes y espacios
void contarCaracteres(const string& palabra, int& vocales, int& consonantes, int& espacios) {
    vocales = consonantes = espacios = 0;

    for(char c : palabra) {
        if (isspace(c)) {
            espacios++;
        } else if (isalpha(c)) {
            char lower_c = tolower(c); // Convertir a minúscula para hacer comparaciones más fáciles
            if (lower_c == 'a' || lower_c == 'e' || lower_c == 'i' || lower_c == 'o' || lower_c == 'u') {
                vocales++;
            } else {
                consonantes++;
            }
        }
    }
}

// Función para verificar si una palabra o frase es palíndromo
bool esPalindromo(const string& palabra) {
    int inicio = 0;
    int fin = palabra.length() - 1;

    while (inicio < fin) {
        if (!isalpha(palabra[inicio])) {
            inicio++;
            continue;
        }
        if (!isalpha(palabra[fin])) {
            fin--;
            continue;
        }
        if (tolower(palabra[inicio]) != tolower(palabra[fin])) {
            return false;
        }
        inicio++;
        fin--;
    }

    return true;
}

int main() {
    string entrada;
    string concatenado;

    while (true) {
        cout << "Ingrese una palabra o frase (escriba 'salir' para terminar): ";
        getline(cin, entrada);

        if (entrada == "salir") {
            break;
        }

        // Contar caracteres
        int vocales, consonantes, espacios;
        contarCaracteres(entrada, vocales, consonantes, espacios);

        cout << "Vocales: " << vocales << ", Consonantes: " << consonantes << ", Espacios: " << espacios << endl;

        // Verificar si es palíndromo
        if (esPalindromo(entrada)) {
            cout << "Palindromo: Si. " << entrada << endl;
        } else {
            cout << "Palindromos: No" << endl;
        }

        // Convertir a mayúsculas y minúsculas
        string mayusculas = entrada;
        for (char& c : mayusculas) {
            c = toupper(c);
        }
        string minusculas = entrada;
        for (char& c : minusculas) {
            c = tolower(c);
        }

        cout << "En mayusculas: " << mayusculas << endl;
        cout << "En minusculas: " << minusculas << endl;

        // Concatenar con la entrada anterior
        concatenado += entrada;
    }

    cout << "Palabra o frase concatenada: " << concatenado << endl;

    return 0;
}



