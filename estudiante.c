#include "estudiante.h"
#include <stdio.h>
#include <string.h>

// Solicita al usuario los datos de un estudiante y los almacena en la estructura
void agregarEstudiante(Estudiante *e) {
    printf("Nombre: ");
    fgets(e->nombre, 50, stdin);
    e->nombre[strcspn(e->nombre, "\n")] = 0; // Elimina salto de línea

    printf("Edad: ");
    scanf("%d", &e->edad);
    getchar(); // Limpia el buffer

    printf("Matricula: ");
    fgets(e->matricula, 15, stdin);
    e->matricula[strcspn(e->matricula, "\n")] = 0;

    printf("Ingrese 5 calificaciones:\n");
    for (int i = 0; i < 5; i++) {
        printf("Calificacion %d: ", i+1);
        scanf("%f", &e->calificaciones[i]);
    }
    getchar(); // Limpia el buffer
}

// Calcula el promedio de las 5 calificaciones y lo almacena en la estructura
void calcularPromedio(Estudiante *e) {
    float suma = 0;
    for (int i = 0; i < 5; i++) {
        suma += e->calificaciones[i];
    }
    e->promedio = suma / 5.0;
}

// Muestra en pantalla los datos de un estudiante
void mostrarEstudiante(Estudiante e) {
    printf("\nNombre: %s\n", e.nombre);
    printf("Edad: %d\n", e.edad);
    printf("Matricula: %s\n", e.matricula);
    printf("Calificaciones: ");
    for (int i = 0; i < 5; i++) {
        printf("%.2f ", e.calificaciones[i]);
    }
    printf("\nPromedio: %.2f\n", e.promedio);
}