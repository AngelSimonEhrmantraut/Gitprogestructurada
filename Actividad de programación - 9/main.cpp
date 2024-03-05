/******************************************************************************
NOMBRE: Angel Simón Navarro Martín
FECHA: 04/03/2024
PROGRAMA: operaciones de dos conjuntos
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERÍA EN COMPUTACIÓN / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas
DESCRIPCIÓN: Elaborar un programa que realice las operaciones de dos conjuntos
*******************************************************************************/
#include <iostream>
#include "conjunto.h"

int main() {
    // Objeto de la clase Conjuntos
    Conjuntos conjuntos;
    //Declarar variables
    char opcion;

    do {
            // Se muestra el menú
        std::cout << "Seleccione una opción:\n";
        std::cout << "1. Agregar elemento\n";
        std::cout << "2. Borrar elemento\n";
        std::cout << "3. Editar elemento\n";
        std::cout << "4. Vaciar conjunto\n";
        std::cout << "5. Realizar operaciones de conjuntos\n";
        std::cout << "6. Salir\n";
        std::cin >> opcion;

        switch (opcion) {
            case '1': {
                // Agregar elemento a un conjunto
                char elemento;
                int conjunto;
                std::cout << "Ingrese el elemento a agregar: ";
                std::cin >> elemento;
                std::cout << "Ingrese el número de conjunto (1 o 2): ";
                std::cin >> conjunto;
                conjuntos.agregarElemento(elemento, conjunto);
                break;
            }
            case '2': {
                // Borrar elemento de un conjunto
                char elemento;
                int conjunto;
                std::cout << "Ingrese el elemento a borrar: ";
                std::cin >> elemento;
                std::cout << "Ingrese el número de conjunto (1 o 2): ";
                std::cin >> conjunto;
                conjuntos.borrarElemento(elemento, conjunto);
                break;
            }
            case '3': {
                // Editar elemento de un conjunto
                char elementoViejo, elementoNuevo;
                int conjunto;
                std::cout << "Ingrese el elemento a editar: ";
                std::cin >> elementoViejo;
                std::cout << "Ingrese el nuevo elemento: ";
                std::cin >> elementoNuevo;
                std::cout << "Ingrese el número de conjunto (1 o 2): ";
                std::cin >> conjunto;
                conjuntos.editarElemento(elementoViejo, elementoNuevo, conjunto);
                break;
            }
            case '4': {
                // Vaciar un conjunto
                int conjunto;
                std::cout << "Ingrese el número de conjunto a vaciar (1 o 2): ";
                std::cin >> conjunto;
                conjuntos.vaciarConjunto(conjunto);
                break;
            }
            case '5': {
                // Realizar operaciones de conjuntos
                std::vector<char> conjuntoA, conjuntoB, resultado;
                char opcionOperacion;
                std::cout << "Seleccione la operación de conjuntos:\n";
                std::cout << "a. Unión\n";
                std::cout << "b. Intersección\n";
                std::cout << "c. Diferencia\n";
                std::cout << "d. Complemento\n";
                std::cin >> opcionOperacion;

                std::cout << "Ingrese los elementos del conjunto A (ingrese '.' para terminar):\n";
                char elemento;
                while (std::cin >> elemento && elemento != '.') {
                    conjuntoA.push_back(elemento);
                }

                std::cout << "Ingrese los elementos del conjunto B (ingrese '.' para terminar):\n";
                while (std::cin >> elemento && elemento != '.') {
                    conjuntoB.push_back(elemento);
                }

                switch (opcionOperacion) {
                    case 'a':
                        resultado = conjuntos.unionConjuntos(conjuntoA, conjuntoB);
                        break;
                    case 'b':
                        resultado = conjuntos.interseccionConjuntos(conjuntoA, conjuntoB);
                        break;
                    case 'c':
                        resultado = conjuntos.diferenciaConjuntos(conjuntoA, conjuntoB);
                        break;
                    case 'd':
                        resultado = conjuntos.complementoConjunto(conjuntoA);
                        break;
                    default:
                        std::cout << "Operación inválida.\n";
                        break;
                }

                std::cout << "Resultado de la operación:\n";
                for (char elemento : resultado) {
                    std::cout << elemento << " ";
                }
                std::cout << std::endl;

                break;
            }
            case '6':
                 // Salir del programa
                std::cout << "Saliendo del programa.\n";
                break;
            default:
                 // Opción inválida
                std::cout << "Opción inválida. Intente de nuevo.\n";
                break;
        }
    } while (opcion != '6');

    return 0;
}

