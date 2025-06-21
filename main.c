#include <stdio.h>
#include "estudiante.h"
#include "archivo.h"

#define MAX_ESTUDIANTES 100

// Función principal: muestra el menú y gestiona las opciones del usuario
int main() {
    Estudiante lista[MAX_ESTUDIANTES]; // Arreglo para almacenar estudiantes
    int n = 0, opcion, i;

    while (1) {
        // Menú de opciones
        printf("\n--- MENU ---\n");
        printf("1. Agregar estudiante\n");
        printf("2. Mostrar todos los estudiantes\n");
        printf("3. Mostrar aprobados\n");
        printf("4. Mostrar reprobados\n");
        printf("5. Guardar en archivo\n");
        printf("6. Cargar desde archivo\n");
        printf("0. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        getchar(); // Limpia el buffer

        switch (opcion) {
            case 1:
                // Agrega un nuevo estudiante
                if (n < MAX_ESTUDIANTES) {
                    agregarEstudiante(&lista[n]);
                    calcularPromedio(&lista[n]);
                    n++;
                } else {
                    printf("Limite de estudiantes alcanzado.\n");
                }
                break;
            case 2:
                // Muestra todos los estudiantes
                for (i = 0; i < n; i++) {
                    mostrarEstudiante(lista[i]);
                }
                break;
            case 3:
                // Muestra solo los estudiantes aprobados (promedio >= 6.0)
                printf("\n--- Estudiantes Aprobados ---\n");
                for (i = 0; i < n; i++) {
                    if (lista[i].promedio >= 6.0)
                        mostrarEstudiante(lista[i]);
                }
                break;
            case 4:
                // Muestra solo los estudiantes reprobados (promedio < 6.0)
                printf("\n--- Estudiantes Reprobados ---\n");
                for (i = 0; i < n; i++) {
                    if (lista[i].promedio < 6.0)
                        mostrarEstudiante(lista[i]);
                }
                break;
            case 5:
                // Guarda los estudiantes en un archivo
                guardarArchivo(lista, n);
                break;
            case 6:
                // Carga estudiantes desde un archivo
                n = cargarArchivo(lista);
                printf("Datos cargados: %d estudiantes.\n", n);
                break;
            case 0:
                // Sale del programa
                printf("Saliendo...\n");
                return 0;
            default:
                printf("Opcion invalida.\n");
        }
    }
    return 0;
}