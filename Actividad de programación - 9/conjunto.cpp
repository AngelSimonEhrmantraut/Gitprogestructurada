// conjuntos.cpp
#include "conjunto.h"
#include <algorithm>

Conjuntos::Conjuntos() {
    // Constructor
}

// Agrega un elemento al conjunto especificado si no está ya presente
void Conjuntos::agregarElemento(char elemento, int conjunto) {
    if (conjunto == 1) {
        if (std::find(conjunto1.begin(), conjunto1.end(), elemento) == conjunto1.end()) {
            conjunto1.push_back(elemento);
        }
    } else if (conjunto == 2) {
        if (std::find(conjunto2.begin(), conjunto2.end(), elemento) == conjunto2.end()) {
            conjunto2.push_back(elemento);
        }
    }
}

// Borra un elemento del conjunto especificado
void Conjuntos::borrarElemento(char elemento, int conjunto) {
    if (conjunto == 1) {
        conjunto1.erase(std::remove(conjunto1.begin(), conjunto1.end(), elemento), conjunto1.end());
    } else if (conjunto == 2) {
        conjunto2.erase(std::remove(conjunto2.begin(), conjunto2.end(), elemento), conjunto2.end());
    }
}

// Edita un elemento del conjunto especificado
void Conjuntos::editarElemento(char elementoViejo, char elementoNuevo, int conjunto) {
    borrarElemento(elementoViejo, conjunto);
    agregarElemento(elementoNuevo, conjunto);
}

// Vacia el conjunto especificado
void Conjuntos::vaciarConjunto(int conjunto) {
    if (conjunto == 1) {
        conjunto1.clear();
    } else if (conjunto == 2) {
        conjunto2.clear();
    }
}

// Devuelve la unión de dos conjuntos
std::vector<char> Conjuntos::unionConjuntos(const std::vector<char>& conjuntoA, const std::vector<char>& conjuntoB) {
    std::vector<char> resultado = conjuntoA;
    for (char elemento : conjuntoB) {
        if (std::find(resultado.begin(), resultado.end(), elemento) == resultado.end()) {
            resultado.push_back(elemento);
        }
    }
    return resultado;
}

// Devuelve la intersección de dos conjuntos
std::vector<char> Conjuntos::interseccionConjuntos(const std::vector<char>& conjuntoA, const std::vector<char>& conjuntoB) {
    std::vector<char> resultado;
    for (char elemento : conjuntoA) {
        if (std::find(conjuntoB.begin(), conjuntoB.end(), elemento) != conjuntoB.end()) {
            resultado.push_back(elemento);
        }
    }
    return resultado;
}

// Devuelve la diferencia de dos conjuntos
std::vector<char> Conjuntos::diferenciaConjuntos(const std::vector<char>& conjuntoA, const std::vector<char>& conjuntoB) {
    std::vector<char> resultado;
    for (char elemento : conjuntoA) {
        if (std::find(conjuntoB.begin(), conjuntoB.end(), elemento) == conjuntoB.end()) {
            resultado.push_back(elemento);
        }
    }
    return resultado;
}

// Devuelve el complemento de un conjunto
std::vector<char> Conjuntos::complementoConjunto(const std::vector<char>& conjunto) {
    std::vector<char> resultado;
    for (char c = 'a'; c <= 'z'; ++c) {
        if (std::find(conjunto.begin(), conjunto.end(), c) == conjunto.end()) {
            resultado.push_back(c);
        }
    }
    return resultado;
}


