/*
Funciones para agregar, mostrar y calcular el promedio de estudiantes
*/

#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

// Definición de la estructura Estudiante
typedef struct {
    char nombre[50];         // Nombre del estudiante
    int edad;                // Edad del estudiante
    char matricula[15];      // Matrícula del estudiante
    float calificaciones[5]; // Arreglo de 5 calificaciones
    float promedio;          // Promedio de calificaciones
} Estudiante;

// Prototipos de funciones relacionadas con estudiantes
void agregarEstudiante(Estudiante *e);      // Solicita datos y llena un estudiante
void calcularPromedio(Estudiante *e);       // Calcula el promedio de un estudiante
void mostrarEstudiante(Estudiante e);       // Muestra los datos de un estudiante

#endif