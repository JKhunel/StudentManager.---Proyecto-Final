/*
Fecha de ultima revision:20/06/2025
Nombre: Iquí-Balam López Hernández.

## StudentManager  v0.1
Descripción: Este programa gestiona una lista de estudiantes, permitiendo agregar, mostrar, guardar y cargar datos desde un archivo.

Estructura base para el proyecto.

Compilacion: gcc estudiantes.c -o estudiantes.exe -lcomdlg32
*/

#include <stdio.h>              // Incluye funciones de entrada/salida estándar (printf, scanf, etc.)
#include <stdlib.h>             // Incluye funciones de utilidad general (atoi, atof, etc.)
#include <string.h>             // Incluye funciones para manipulación de cadenas (strcpy, strtok, etc.)
#include <windows.h>            // Incluye definiciones para la API de Windows
#include <commdlg.h>            // Incluye funciones para cuadros de diálogo comunes (abrir/guardar archivo)

#define MAX_ESTUDIANTES 100     // Define el número máximo de estudiantes permitidos

// Definición de la estructura Estudiante
typedef struct {
    char nombre[50];            // Nombre del estudiante
    int edad;                   // Edad del estudiante
    char matricula[15];         // Matrícula del estudiante
    float calificaciones[5];    // Arreglo de 5 calificaciones
    float promedio;             // Promedio de las calificaciones
} Estudiante;

// Declaración de funciones
void agregarEstudiante(Estudiante *e);           // Agrega un estudiante
void calcularPromedio(Estudiante *e);            // Calcula el promedio de un estudiante
void mostrarEstudiante(Estudiante e);            // Muestra los datos de un estudiante
void guardarArchivo(Estudiante *lista, int n);   // Guarda la lista de estudiantes en un archivo
int cargarArchivo(Estudiante *lista);            // Carga la lista de estudiantes desde un archivo
int seleccionarArchivo(char *ruta, DWORD modoGuardar); // Muestra un cuadro de diálogo para seleccionar archivo

int main() {
    Estudiante lista[MAX_ESTUDIANTES];   // Arreglo para almacenar los estudiantes
    int n = 0, opcion, i;                // n: número de estudiantes, opcion: opción del menú, i: índice

    while (1) {                          // Bucle principal del menú
        printf("\n--- MENU ---\n");
        printf("1. Agregar estudiante\n");
        printf("2. Mostrar todos los estudiantes\n");
        printf("3. Mostrar aprobados\n");
        printf("4. Mostrar reprobados\n");
        printf("5. Guardar en archivo\n");
        printf("6. Cargar desde archivo\n");
        printf("0. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);            // Lee la opción del usuario
        getchar();                       // Limpia el buffer de entrada

        switch (opcion) {                // Selecciona la acción según la opción
            case 1:
                if (n < MAX_ESTUDIANTES) {           // Si hay espacio para más estudiantes
                    agregarEstudiante(&lista[n]);    // Agrega un nuevo estudiante
                    calcularPromedio(&lista[n]);     // Calcula su promedio
                    n++;                             // Incrementa el contador de estudiantes
                } else {
                    printf("Limite de estudiantes alcanzado.\n");
                }
                break;
            case 2:
                for (i = 0; i < n; i++) {            // Muestra todos los estudiantes
                    mostrarEstudiante(lista[i]);
                }
                break;
            case 3:
                printf("\n--- Estudiantes Aprobados ---\n");
                for (i = 0; i < n; i++) {            // Muestra solo los aprobados (promedio >= 6.0)
                    if (lista[i].promedio >= 6.0)
                        mostrarEstudiante(lista[i]);
                }
                break;
            case 4:
                printf("\n--- Estudiantes Reprobados ---\n");
                for (i = 0; i < n; i++) {            // Muestra solo los reprobados (promedio < 6.0)
                    if (lista[i].promedio < 6.0)
                        mostrarEstudiante(lista[i]);
                }
                break;
            case 5:
                guardarArchivo(lista, n);             // Guarda los datos en un archivo
                break;
            case 6:
                n = cargarArchivo(lista);             // Carga los datos desde un archivo
                printf("Datos cargados: %d estudiantes.\n", n);
                break;
            case 0:
                printf("Saliendo...\n");              // Sale del programa
                return 0;
            default:
                printf("Opcion invalida.\n");         // Opción no válida
        }
    }
    return 0;
}

// Función para agregar un estudiante
void agregarEstudiante(Estudiante *e) {
    printf("Nombre: ");
    fgets(e->nombre, 50, stdin);                      // Lee el nombre (incluye salto de línea)
    e->nombre[strcspn(e->nombre, "\n")] = 0;          // Elimina el salto de línea

    printf("Edad: ");
    scanf("%d", &e->edad);                            // Lee la edad
    getchar();                                        // Limpia el buffer

    printf("Matricula: ");
    fgets(e->matricula, 15, stdin);                   // Lee la matrícula
    e->matricula[strcspn(e->matricula, "\n")] = 0;    // Elimina el salto de línea

    printf("Ingrese 5 calificaciones:\n");
    for (int i = 0; i < 5; i++) {
        printf("Calificacion %d: ", i+1);
        scanf("%f", &e->calificaciones[i]);           // Lee cada calificación
    }
    getchar();                                        // Limpia el buffer
}

// Calcula el promedio de un estudiante
void calcularPromedio(Estudiante *e) {
    float suma = 0;
    for (int i = 0; i < 5; i++) {
        suma += e->calificaciones[i];                 // Suma las calificaciones
    }
    e->promedio = suma / 5.0;                         // Calcula el promedio
}

// Muestra los datos de un estudiante
void mostrarEstudiante(Estudiante e) {
    printf("\nNombre: %s\n", e.nombre);
    printf("Edad: %d\n", e.edad);
    printf("Matricula: %s\n", e.matricula);
    printf("Calificaciones: ");
    for (int i = 0; i < 5; i++) {
        printf("%.2f ", e.calificaciones[i]);         // Muestra cada calificación
    }
    printf("\nPromedio: %.2f\n", e.promedio);         // Muestra el promedio
}

// Guarda la lista de estudiantes en un archivo
void guardarArchivo(Estudiante *lista, int n) {
    char ruta[MAX_PATH];                              // Ruta del archivo
    if (!seleccionarArchivo(ruta, 1)) {               // Selecciona el archivo para guardar
        printf("Operacion cancelada.\n");
        return;
    }
    FILE *f = fopen(ruta, "w");                       // Abre el archivo en modo escritura
    if (!f) {
        printf("Error al abrir el archivo.\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        fprintf(f, "%s;%d;%s;", lista[i].nombre, lista[i].edad, lista[i].matricula); // Escribe nombre, edad y matrícula
        for (int j = 0; j < 5; j++) {
            fprintf(f, "%.2f", lista[i].calificaciones[j]);                          // Escribe cada calificación
            if (j < 4) fprintf(f, ",");                                              // Separa con coma
        }
        fprintf(f, ";%.2f\n", lista[i].promedio);                                    // Escribe el promedio
    }
    fclose(f);                                                                       // Cierra el archivo
    printf("Datos guardados correctamente en %s\n", ruta);
}

// Carga la lista de estudiantes desde un archivo
int cargarArchivo(Estudiante *lista) {
    char ruta[MAX_PATH];                              // Ruta del archivo
    if (!seleccionarArchivo(ruta, 0)) {               // Selecciona el archivo para abrir
        printf("Operacion cancelada.\n");
        return 0;
    }
    FILE *f = fopen(ruta, "r");                       // Abre el archivo en modo lectura
    if (!f) {
        printf("No se pudo abrir el archivo.\n");
        return 0;
    }
    int n = 0;
    char linea[256];                                  // Buffer para cada línea del archivo
    while (fgets(linea, sizeof(linea), f) && n < MAX_ESTUDIANTES) {
        printf("Leyendo: %s\n", linea);               // Línea de depuración

        linea[strcspn(linea, "\r\n")] = 0;            // Elimina salto de línea

        // Separa los campos usando ';' como delimitador
        char *nombre = strtok(linea, ";");
        char *edad = strtok(NULL, ";");
        char *matricula = strtok(NULL, ";");
        char *califStr = strtok(NULL, ";");
        char *promedio = strtok(NULL, ";");

        if (!nombre || !edad || !matricula || !califStr || !promedio) continue;

        strncpy(lista[n].nombre, nombre, sizeof(lista[n].nombre));    // Copia el nombre
        lista[n].nombre[sizeof(lista[n].nombre)-1] = '\0';
        lista[n].edad = atoi(edad);                                  // Convierte edad a entero
        strncpy(lista[n].matricula, matricula, sizeof(lista[n].matricula)); // Copia matrícula
        lista[n].matricula[sizeof(lista[n].matricula)-1] = '\0';

        // Lee las calificaciones separadas por coma
        char *calif = strtok(califStr, ",");
        int i = 0;
        while (calif && i < 5) {
            lista[n].calificaciones[i++] = atof(calif);              // Convierte a float
            calif = strtok(NULL, ",");
        }
        while (i < 5) lista[n].calificaciones[i++] = 0.0f;           // Rellena con ceros si faltan

        lista[n].promedio = atof(promedio);                          // Convierte promedio a float

        n++;                                                         // Incrementa el contador de estudiantes
    }
    fclose(f);                                                       // Cierra el archivo
    printf("Datos cargados desde %s\n", ruta);
    return n;                                                        // Retorna el número de estudiantes cargados
}

// Muestra un cuadro de diálogo para seleccionar archivo
int seleccionarArchivo(char *ruta, DWORD modoGuardar) {
    OPENFILENAME ofn;                        // Estructura para el cuadro de diálogo
    ZeroMemory(&ofn, sizeof(ofn));           // Inicializa la estructura en cero
    ZeroMemory(ruta, MAX_PATH);              // Inicializa la ruta en cero
    ofn.lStructSize = sizeof(ofn);           // Tamaño de la estructura
    ofn.hwndOwner = NULL;                    // Sin ventana propietaria
    ofn.lpstrFile = ruta;                    // Buffer para la ruta del archivo
    ofn.nMaxFile = MAX_PATH;                 // Tamaño máximo del buffer
    ofn.lpstrFilter = "Archivos de texto\0*.txt\0Todos los archivos\0*.*\0"; // Filtro de archivos
    ofn.nFilterIndex = 1;                    // Índice del filtro por defecto
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST; // Flags para el cuadro de diálogo
    if (modoGuardar) {                       // Si es para guardar archivo
        ofn.Flags |= OFN_OVERWRITEPROMPT;    // Pregunta si se va a sobrescribir
        return GetSaveFileName(&ofn);        // Muestra el cuadro de diálogo para guardar
    } else {
        return GetOpenFileName(&ofn);        // Muestra el cuadro de diálogo para abrir
    }
}