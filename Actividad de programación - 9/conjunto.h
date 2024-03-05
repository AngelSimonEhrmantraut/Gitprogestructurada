// conjuntos.h
#ifndef CONJUNTOS_H
#define CONJUNTOS_H

#include <vector>

class Conjuntos {
public:
    Conjuntos(); // Constructor

    // Agrega un elemento al conjunto especificado si no está ya presente
    void agregarElemento(char elemento, int conjunto);

    // Borra un elemento del conjunto especificado
    void borrarElemento(char elemento, int conjunto);

    // Edita un elemento del conjunto especificado
    void editarElemento(char elementoViejo, char elementoNuevo, int conjunto);

    // Vacia el conjunto especificado
    void vaciarConjunto(int conjunto);

    // Devuelve la unión de dos conjuntos
    std::vector<char> unionConjuntos(const std::vector<char>& conjuntoA, const std::vector<char>& conjuntoB);

    // Devuelve la intersección de dos conjuntos
    std::vector<char> interseccionConjuntos(const std::vector<char>& conjuntoA, const std::vector<char>& conjuntoB);

    // Devuelve la diferencia de dos conjuntos
    std::vector<char> diferenciaConjuntos(const std::vector<char>& conjuntoA, const std::vector<char>& conjuntoB);

    // Devuelve el complemento de un conjunto
    std::vector<char> complementoConjunto(const std::vector<char>& conjunto);

private:
    std::vector<char> conjunto1; // Primer conjunto
    std::vector<char> conjunto2; // Segundo conjunto
};

#endif // CONJUNTOS_H
