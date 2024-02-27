/******************************************************************************
NOMBRE: Angel Simón Navarro Martín
FECHA: 26/02/2024
PROGRAMA: operaciones de dos conjuntos
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERÍA EN COMPUTACIÓN / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas
DESCRIPCIÓN: Elaborar un programa que realice las operaciones de dos conjuntos
*******************************************************************************/
#include <iostream>
#include <algorithm> // Para utilizar la función std::set_union, std::set_intersection, std::set_difference
#include <vector>

using namespace std;

const int MAX_SIZE = 100;

void printSet(const vector<int>& set) {
    cout << "{ ";
    for (int i = 0; i < set.size(); ++i) {
        cout << set[i];
        if (i != set.size() - 1)
            cout << ", ";
    }
    cout << " }" << endl;
}

void addElement(vector<int>& set, int element) {
    set.push_back(element);
}

void deleteElement(vector<int>& set, int element) {
    set.erase(remove(set.begin(), set.end(), element), set.end());
}

void clearSet(vector<int>& set) {
    set.clear();
}

vector<int> setUnion(const vector<int>& set1, const vector<int>& set2) {
    vector<int> result(set1.size() + set2.size());
    auto it = set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), result.begin());
    result.resize(distance(result.begin(), it));
    return result;
}

vector<int> setIntersection(const vector<int>& set1, const vector<int>& set2) {
    vector<int> result(min(set1.size(), set2.size()));
    auto it = set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), result.begin());
    result.resize(distance(result.begin(), it));
    return result;
}

vector<int> setDifference(const vector<int>& set1, const vector<int>& set2) {
    vector<int> result(set1.size());
    auto it = set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), result.begin());
    result.resize(distance(result.begin(), it));
    return result;
}

vector<int> setComplement(const vector<int>& universalSet, const vector<int>& set) {
    vector<int> result(universalSet.size());
    auto it = set_difference(universalSet.begin(), universalSet.end(), set.begin(), set.end(), result.begin());
    result.resize(distance(result.begin(), it));
    return result;
}

int main() {
    vector<int> set1, set2;

    int choice, element;

    do {
        cout << "Seleccione una opción:" << endl;
        cout << "1. Agregar elemento a conjunto 1" << endl;
        cout << "2. Agregar elemento a conjunto 2" << endl;
        cout << "3. Borrar elemento de conjunto 1" << endl;
        cout << "4. Borrar elemento de conjunto 2" << endl;
        cout << "5. Vaciar conjunto 1" << endl;
        cout << "6. Vaciar conjunto 2" << endl;
        cout << "7. Realizar unión" << endl;
        cout << "8. Realizar intersección" << endl;
        cout << "9. Realizar diferencia" << endl;
        cout << "10. Realizar complemento" << endl;
        cout << "11. Salir" << endl;
        cout << "Ingrese su elección: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Ingrese el elemento a agregar a conjunto 1: ";
                cin >> element;
                addElement(set1, element);
                break;
            case 2:
                cout << "Ingrese el elemento a agregar a conjunto 2: ";
                cin >> element;
                addElement(set2, element);
                break;
            case 3:
                cout << "Ingrese el elemento a borrar de conjunto 1: ";
                cin >> element;
                deleteElement(set1, element);
                break;
            case 4:
                cout << "Ingrese el elemento a borrar de conjunto 2: ";
                cin >> element;
                deleteElement(set2, element);
                break;
            case 5:
                clearSet(set1);
                break;
            case 6:
                clearSet(set2);
                break;
            case 7:
                cout << "Unión de conjuntos: ";
                printSet(setUnion(set1, set2));
                break;
            case 8:
                cout << "Intersección de conjuntos: ";
                printSet(setIntersection(set1, set2));
                break;
            case 9:
                cout << "Diferencia de conjuntos (Conjunto 1 - Conjunto 2): ";
                printSet(setDifference(set1, set2));
                break;
            case 10: {
                vector<int> universalSet;
                // Crear un conjunto universal, por ejemplo, del 1 al 100
                for (int i = 1; i <= 100; ++i) {
                    universalSet.push_back(i);
                }
                cout << "Complemento del conjunto 1 respecto al conjunto universal: ";
                printSet(setComplement(universalSet, set1));
                break;
            }
            case 11:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción inválida. Por favor, seleccione una opción válida." << endl;
                break;
        }
    } while (choice != 11);

    return 0;
}

