/*
Funciones para gestionar el menú y las opciones del usuario
*/

#include <stdio.h>
#include <stdlib.h>
#include "estudiante.h"
#include "archivo.h"

#define MAX_ESTUDIANTES 100

// Función auxiliar para validar matrícula única en el contexto del arreglo
int validarMatriculaUnica(char *matricula, Estudiante *lista, int n) {
    return validarMatricula(matricula, lista, n);
}

// Función principal: muestra el menú y gestiona las opciones del usuario
int main() {
    Estudiante lista[MAX_ESTUDIANTES]; // Arreglo para almacenar estudiantes
    int n = 0, opcion, i;

    while (1) {
        limpiarPantalla();
        // Menú de opciones simplificado
        printf("%s=== GESTOR DE ESTUDIANTES ===%s\n\n", COLOR_CYAN, COLOR_RESET);
        printf("1. Agregar estudiante\n");
        printf("2. Mostrar todos los estudiantes\n");
        printf("3. Mostrar aprobados\n");
        printf("4. Mostrar reprobados\n");
        printf("5. Guardar en archivo\n");
        printf("6. Cargar desde archivo\n");
        printf("\n%s--- Funciones adicionales ---%s\n", COLOR_YELLOW, COLOR_RESET);
        printf("7. Buscar estudiante por matricula\n");
        printf("8. Editar estudiante\n");
        printf("9. Eliminar estudiante\n");
        printf("10. Ordenar lista\n");
        printf("11. Ver estadisticas\n");
        printf("\n%s0. Salir%s\n", COLOR_RED, COLOR_RESET);
        printf("\n%sEstudiantes registrados: %d/%d%s\n", COLOR_BLUE, n, MAX_ESTUDIANTES, COLOR_RESET);
        printf("%sSeleccione una opcion: %s", COLOR_GREEN, COLOR_RESET);
        scanf("%d", &opcion);
        getchar(); // Limpia el buffer

        switch (opcion) {
            case 1:
                // Agrega un nuevo estudiante
                if (n < MAX_ESTUDIANTES) {
                    printf("%s\n--- Agregar Nuevo Estudiante ---%s\n", COLOR_GREEN, COLOR_RESET);
                    
                    Estudiante nuevoEstudiante;
                    agregarEstudiante(&nuevoEstudiante);
                    
                    // Validar matrícula única después de ingresarla
                    if (!validarMatricula(nuevoEstudiante.matricula, lista, n)) {
                        printf("%s[ERROR] Estudiante no agregado debido a matricula invalida.%s\n", COLOR_RED, COLOR_RESET);
                    } else {
                    calcularPromedio(&nuevoEstudiante);
                    lista[n] = nuevoEstudiante;
                    n++;
                    printf("%s[EXITO] Estudiante agregado exitosamente.%s\n", COLOR_GREEN, COLOR_RESET);
                        
                        // Mostrar resumen del estudiante agregado
                        printf("\n%s=== Resumen del Estudiante Agregado ===%s\n", COLOR_BLUE, COLOR_RESET);
                        mostrarEstudiante(lista[n-1]);
                    }
                } else {
                    printf("%s[ERROR] Limite de estudiantes alcanzado (%d/%d).%s\n", COLOR_RED, n, MAX_ESTUDIANTES, COLOR_RESET);
                }
                pausar();
                break;
            case 2:
                // Muestra todos los estudiantes
                printf("%s\n--- Todos los Estudiantes (%d) ---%s\n", COLOR_BLUE, n, COLOR_RESET);
                if (n == 0) {
                    printf("%s[ERROR] No hay estudiantes registrados.%s\n", COLOR_RED, COLOR_RESET);
                } else {
                    for (i = 0; i < n; i++) {
                        printf("%s[%d/%d]%s", COLOR_YELLOW, i+1, n, COLOR_RESET);
                        mostrarEstudiante(lista[i]);
                    }
                }
                pausar();
                break;
            case 3:
                // Muestra solo los estudiantes aprobados (promedio >= 6.0)
                printf("%s\n--- Estudiantes Aprobados ---%s\n", COLOR_GREEN, COLOR_RESET);
                int aprobados = 0;
                for (i = 0; i < n; i++) {
                    if (lista[i].promedio >= 6.0) {
                        mostrarEstudiante(lista[i]);
                        aprobados++;
                    }
                }
                if (aprobados == 0) {
                    printf("%s[ERROR] No hay estudiantes aprobados.%s\n", COLOR_RED, COLOR_RESET);
                } else {
                    printf("%s[EXITO] Total de aprobados: %d%s\n", COLOR_GREEN, aprobados, COLOR_RESET);
                }
                pausar();
                break;
            case 4:
                // Muestra solo los estudiantes reprobados (promedio < 6.0)
                printf("%s\n--- Estudiantes Reprobados ---%s\n", COLOR_RED, COLOR_RESET);
                int reprobados = 0;
                for (i = 0; i < n; i++) {
                    if (lista[i].promedio < 6.0) {
                        mostrarEstudiante(lista[i]);
                        reprobados++;
                    }
                }
                if (reprobados == 0) {
                    printf("%s[EXITO] No hay estudiantes reprobados.%s\n", COLOR_GREEN, COLOR_RESET);
                } else {
                    printf("%s[AVISO] Total de reprobados: %d%s\n", COLOR_RED, reprobados, COLOR_RESET);
                }
                pausar();
                break;
            case 5:
                // Guarda los estudiantes en un archivo
                if (n == 0) {
                    printf("%s[ERROR] No hay estudiantes para guardar.%s\n", COLOR_RED, COLOR_RESET);
                } else {
                    printf("%s\n--- Guardar en Archivo ---%s\n", COLOR_YELLOW, COLOR_RESET);
                    guardarArchivo(lista, n);
                }
                pausar();
                break;
            case 6:
                // Carga estudiantes desde un archivo
                printf("%s\n--- Cargar desde Archivo ---%s\n", COLOR_YELLOW, COLOR_RESET);
                if (n > 0 && !confirmarAccion("Desea sobrescribir los datos actuales?")) {
                    break;
                }
                int cargados = cargarArchivo(lista);
                if (cargados > 0) {
                    n = cargados;
                    printf("%s[EXITO] Datos cargados: %d estudiantes.%s\n", COLOR_GREEN, n, COLOR_RESET);
                } else {
                    printf("%s[ERROR] No se pudieron cargar los datos.%s\n", COLOR_RED, COLOR_RESET);
                }
                pausar();
                break;
            case 7:
                // Buscar estudiante por matrícula
                if (n == 0) {
                    printf("%s[ERROR] No hay estudiantes registrados.%s\n", COLOR_RED, COLOR_RESET);
                } else {
                    buscarEstudiantePorMatricula(lista, n);
                }
                pausar();
                break;
            case 8:
                // Editar estudiante
                if (n == 0) {
                    printf("%s[ERROR] No hay estudiantes registrados.%s\n", COLOR_RED, COLOR_RESET);
                } else {
                    editarEstudiante(lista, n);
                }
                pausar();
                break;
            case 9:
                // Eliminar estudiante
                if (n == 0) {
                    printf("%s[ERROR] No hay estudiantes registrados.%s\n", COLOR_RED, COLOR_RESET);
                } else {
                    eliminarEstudiante(lista, &n);
                }
                pausar();
                break;
            case 10:
                // Ordenar lista
                if (n == 0) {
                    printf("%s[ERROR] No hay estudiantes registrados.%s\n", COLOR_RED, COLOR_RESET);
                } else {
                    mostrarMenuOrdenamiento();
                    int criterio;
                    scanf("%d", &criterio);
                    getchar();
                    if (criterio >= 1 && criterio <= 4) {
                        ordenarEstudiantes(lista, n, criterio);
                    } else {
                        printf("%s[ERROR] Criterio no valido.%s\n", COLOR_RED, COLOR_RESET);
                    }
                }
                pausar();
                break;
            case 11:
                // Ver estadísticas
                mostrarEstadisticas(lista, n);
                pausar();
                break;
            case 0:
                // Sale del programa
                if (confirmarAccion("Esta seguro de que desea salir?")) {
                    printf("%sHasta luego! %s\n", COLOR_GREEN, COLOR_RESET);
                    return 0;
                }
                break;
            default:
                printf("%s[ERROR] Opcion invalida. Intente nuevamente.%s\n", COLOR_RED, COLOR_RESET);
                pausar();
        }
    }
    return 0;
}
