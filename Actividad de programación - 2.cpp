/******************************************************************************
NOMBRE: Angel Simón Navarro Martín
FECHA: 02/02/2024
PROGRAMA: Datos
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERÍA EN COMPUTACIÓN / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas
DESCRIPCIÓN: Mostrar Nombre, Edad, Lugar de residencia, Fecha, Carrera y Semestre
*******************************************************************************/
#include <iostream>
using namespace std;
//Declaro todas las variables de prueba para utilizar Las cadenas de control de tipo de salida.
int main() {
int edad= 18;
int year= 2024;
float fecha= 02.02;
char inicial = 'A';
float semestre= 2;
int siclo= 2023;

//Comienzo a utilizar las secuencias de escape "Avance de línea,tabuación, alarma, signo de interrogación, comillas y diagonal.
    printf ("Nombre\\ %cngel Simon Navarro Martin \t\n\a",inicial);
    printf ("Edad\\ %i years \n",edad) ;
    printf ("Lugar de residencia\\ \"Capilla de Guadalupe\" \n");
    printf ("Fecha\\ %.2lf %d\? \n",fecha,year);
    printf ("Carrera\\ Computacion %u \n",siclo);
    printf ("Semestres\\ %gdo \n",semestre);
    return 0;
}
