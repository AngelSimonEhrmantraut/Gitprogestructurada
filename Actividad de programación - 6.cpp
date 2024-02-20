/******************************************************************************
NOMBRE: Angel Simón Navarro Martín
FECHA: 20/02/2024
PROGRAMA:Suma de vectores
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERÍA EN COMPUTACIÓN / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas
DESCRIPCIÓN: Elaborar una suma de un vectores
*******************************************************************************/
#include <iostream>
#include <vector>

int main() {
    // Definir un vector de enteros
    std::vector<int> vec;
    int opcion, posicion, valor;
    bool continuar = true;  // Bandera de control para el bucle
    int suma = 0;  // Mover la inicialización de 'suma' aquí

    while(continuar) {  // Modificar la condición del bucle
        std::cout << "Selecciona una opción\n1. Agregar elemento\n2. Editar elemento\n3. Borrar elemento\n4. Vaciar vec\n5. Mostrar vector y sumatoria\n6. Salir\nElige una opción: ";
        std::cin >> opcion;

        // Ejecutar la opción elegida por el usuario
        switch(opcion) {
            case 1:  // Agregar elemento
                std::cout << "Ingresa el valor para la posición " << vec.size()+1 << ": ";
                std::cin >> valor;
                vec.push_back(valor);
                break;
            case 2:  // Editar elemento
                std::cout << "¿Qué posición quieres editar? ";
                std::cin >> posicion;
                // Verificar si la posición es válida
                if(posicion >= 1 && posicion <= vec.size()) {
                    std::cout << "Ingresa el nuevo valor: ";
                    std::cin >> valor;
                    vec[posicion-1] = valor;
                } else {
                    std::cout << "Posición inválida.\n";
                }
                break;
            case 3:  // Borrar elemento
                std::cout << "¿Qué posición quieres borrar? ";
                std::cin >> posicion;
                // Verificar si la posición es válida
                if(posicion >= 1 && posicion <= vec.size()) {
                    // Borrar el elemento en la posición dada
                    vec.erase(vec.begin() + posicion - 1);
                } else {
                    std::cout << "Posición inválida.\n";
                }
                break;
            case 4:  // Vaciar vec
                vec.clear();
                break;
            case 5:  // Mostrar vec y sumatoria
                suma = 0;  // Reiniciar 'suma' aquí
                std::cout << "vec: ";
                for(int i = 0; i < vec.size(); i++) {
                    std::cout << vec[i] << " ";
                    suma += vec[i];
                }
                std::cout << "\nSumatoria: " << suma << "\n";
                break;
            case 6:  // Salir
                continuar = false;  // Cambiar la bandera de control para salir del bucle
                break;
            default:
                std::cout << "Opción inválida.\n";
        }
    }

    return 0;
}
