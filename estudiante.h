/*
Funciones para agregar, mostrar y calcular el promedio de estudiantes
*/

#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

// Códigos de color para la consola
#define COLOR_RESET   "\033[0m"
#define COLOR_RED     "\033[31m"
#define COLOR_GREEN   "\033[32m"
#define COLOR_YELLOW  "\033[33m"
#define COLOR_BLUE    "\033[34m"
#define COLOR_MAGENTA "\033[35m"
#define COLOR_CYAN    "\033[36m"
#define COLOR_WHITE   "\033[37m"

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

// Prototipos de funciones adicionales
void buscarEstudiantePorMatricula(Estudiante *lista, int n);
void editarEstudiante(Estudiante *lista, int n);
void eliminarEstudiante(Estudiante *lista, int *n);
void mostrarEstadisticas(Estudiante *lista, int n);
void ordenarEstudiantes(Estudiante *lista, int n, int criterio);
void mostrarMenuOrdenamiento();
void limpiarPantalla();
void pausar();
int confirmarAccion(char *mensaje);

// Prototipos de funciones de validación
int validarNombre(char *nombre);
int validarEdad(int edad);
int validarMatricula(char *matricula, Estudiante *lista, int n);
int validarFormatoMatricula(char *matricula);
int validarCalificacion(float calificacion);
int esNumerico(char *str);
void limpiarBuffer();
int leerEntero(int *valor, int min, int max, char *mensaje);
int leerFloat(float *valor, float min, float max, char *mensaje);
int leerCadena(char *destino, int tamano, char *mensaje, int (*validador)(char*));

#endif