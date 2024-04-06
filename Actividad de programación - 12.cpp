/******************************************************************************
NOMBRE: Angel Simón Navarro Martín
FECHA: 05/04/2024
PROGRAMA: Torre de Hanoi
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERÍA EN COMPUTACIÓN / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas
DESCRIPCIÓN: Hacer una torre de Hanoi con recursividad
*******************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

void imprimirTorres(const vector<vector<int>>& torres) {
    for (int i = 0; i < 3; ++i) {
        cout << "Torre " << i + 1 << ": ";
        for (int j = torres[i].size() - 1; j >= 0; --j) {
            cout << torres[i][j] << " ";
        }
        cout << endl;
    }
}

void moverDisco(vector<vector<int>>& torres, int desde, int hacia) {
    int disco = torres[desde].back();
    torres[desde].pop_back();
    torres[hacia].push_back(disco);
}

void hanoiRecursivo(vector<vector<int>>& torres, int n, int desde, int hacia, int auxiliar, int& movimientos) {
    if (n == 1) {
        moverDisco(torres, desde, hacia);
        movimientos++;
        imprimirTorres(torres);
        cout << "Movimientos: " << movimientos << endl;
        return;
    }
    hanoiRecursivo(torres, n - 1, desde, auxiliar, hacia, movimientos);
    moverDisco(torres, desde, hacia);
    movimientos++;
    imprimirTorres(torres);
    cout << "Movimientos: " << movimientos << endl;
    hanoiRecursivo(torres, n - 1, auxiliar, hacia, desde, movimientos);
}

void jugarTorreDeHanoi(int n) {
    vector<vector<int>> torres(3, vector<int>());
    for (int i = n; i >= 1; --i) {
        torres[0].push_back(i);
    }
    int movimientos = 0;
    imprimirTorres(torres);
    cout << "Movimientos: " << movimientos << endl;

    // Continuar el juego hasta que todos los discos esten en la tercera torre
    while (torres[2].size() != n) {
        int desde, hacia;
        cout << "Ingresa la torre de donde quieras sacar el disco y despues hacia lo quieras mover (1, 2 o 3) ";
        cin >> desde >> hacia;

        // Validar la entrada del usuario
        if (desde < 1 || desde > 3 || hacia < 1 || hacia > 3 || desde == hacia) {
            cout << "Movimiento no valido. Por favor, elige torres distintas entre 1, 2 y 3." << endl;
            continue;
        }
        --desde;
        --hacia;

        // Verificar si el movimiento es valido y realizarlo
        if (!torres[desde].empty() && (torres[hacia].empty() || torres[hacia].back() > torres[desde].back())) {
            moverDisco(torres, desde, hacia);
            movimientos++;
            imprimirTorres(torres);
            cout << "Movimientos: " << movimientos << endl;
        } else {
            cout << "Movimiento no valido. No puedes mover un disco a una torre mas pequeña." << endl;
        }
    }
    cout << "¡Felicidades! Has completado la Torre de Hanoi en " << movimientos << " movimientos." << endl;
}

int main() {
    int numDiscos;
    cout << "Torre de Hanoi!" << endl;
    cout << "Ingresa el numero de discos (entre 3 y 8): ";
    cin >> numDiscos;
    if (numDiscos < 3 || numDiscos > 8) {
        cout << "Numero de discos no valido. Elige un numero entre 3 y 8." << endl;
        return 1;
    }
    jugarTorreDeHanoi(numDiscos);
    return 0;
}



