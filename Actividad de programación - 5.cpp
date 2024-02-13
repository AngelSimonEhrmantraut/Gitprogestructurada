/******************************************************************************
NOMBRE: Angel Simón Navarro Martín
FECHA: 13/02/2024
PROGRAMA:Suma de arreglos
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERÍA EN COMPUTACIÓN / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas
DESCRIPCIÓN: Elaborar una suma de un arreglos
*******************************************************************************/
#include <iostream>
#include <vector>
int main() {
    // Definir un vector de enteros con tamaño 10
    std::vector<int> arreglo(10);
    int opcion, posicion, valor;
    bool continuar = true;  // Bandera de control para el bucle
    int n = 0;  // Inicializar el contador de elementos en el arreglo a 0
    int suma = 0;  // Mover la inicialización de 'suma' aquí

    while(continuar) {  // Modificar la condición del bucle
        std::cout << "\Selecciona una opción\n1. Agregar elemento\n2. Editar elemento\n3. Borrar elemento\n4. Vaciar arreglo\n5. Mostrar arreglo y sumatoria\n6. Salir\nElige una opción: ";
        std::cin >> opcion;

        // Ejecutar la opción elegida por el usuario
        switch(opcion) {
            case 1:  // Agregar elemento
                // Verificar si hay espacio en el arreglo
                if(n < 10) {
                    std::cout << "Ingresa el valor para la posición " << n+1 << ": ";
                    std::cin >> arreglo[n++];
                } else {
                    std::cout << "El arreglo ya está lleno.\n";
                }
                break;
            case 2:  // Editar elemento
                std::cout << "¿Qué posición quieres editar? ";
                std::cin >> posicion;
                // Verificar si la posición es válida
                if(posicion >= 1 && posicion <= n) {
                    std::cout << "Ingresa el nuevo valor: ";
                    std::cin >> valor;
                    arreglo[posicion-1] = valor;
                } else {
                    std::cout << "Posición inválida.\n";
                }
                break;
            case 3:  // Borrar elemento
                std::cout << "¿Qué posición quieres borrar? ";
                std::cin >> posicion;
                // Verificar si la posición es válida
                if(posicion >= 1 && posicion <= n) {
                    // Desplazar los elementos a la izquierda
                    for(int i = posicion-1; i < n-1; i++) {
                        arreglo[i] = arreglo[i+1];
                    }
                    n--;
                } else {
                    std::cout << "Posición inválida.\n";
                }
                break;
            case 4:  // Vaciar arreglo
                n = 0;
                break;
            case 5:  // Mostrar arreglo y sumatoria
                suma = 0;  // Reiniciar 'suma' aquí
                std::cout << "Arreglo: ";
                for(int i = 0; i < n; i++) {
                    std::cout << arreglo[i] << " ";
                    suma += arreglo[i];
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

