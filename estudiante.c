/*
Implementa las funciones para agregar, mostrar y calcular el promedio de estudiantes
*/

#include "estudiante.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Solicita al usuario los datos de un estudiante y los almacena en la estructura
void agregarEstudiante(Estudiante *e) {
    printf("%s=== Ingreso de Datos del Estudiante ===%s\n", COLOR_BLUE, COLOR_RESET);
    printf("%sNota: Tendra 3 intentos para cada campo%s\n\n", COLOR_YELLOW, COLOR_RESET);
    
    // Validar nombre
    if (!leerCadena(e->nombre, 50, "Nombre completo: ", validarNombre)) {
        printf("%s[ERROR] No se pudo registrar el nombre. Operacion cancelada.%s\n", COLOR_RED, COLOR_RESET);
        return;
    }
    
    // Validar edad
    if (!leerEntero(&e->edad, 0, 100, "Edad (0-100 anos): ")) {
        printf("%s[ERROR] No se pudo registrar la edad. Operacion cancelada.%s\n", COLOR_RED, COLOR_RESET);
        return;
    }
    
    // Validar matrícula
    char matriculaTemp[15];
    printf("\n%sFormato de matricula: 10 digitos (ej: 2024060001)%s\n", COLOR_BLUE, COLOR_RESET);
    if (!leerCadena(matriculaTemp, 15, "Matricula: ", validarFormatoMatricula)) {
        printf("%s[ERROR] No se pudo registrar la matricula. Operacion cancelada.%s\n", COLOR_RED, COLOR_RESET);
        return;
    }
    
    // Nota: La validación de matrícula única se hará en el main.c
    strcpy(e->matricula, matriculaTemp);
    
    // Validar calificaciones
    printf("\n%s=== Calificaciones (0.0 - 10.0) ===%s\n", COLOR_CYAN, COLOR_RESET);
    for (int i = 0; i < 5; i++) {
        char mensaje[50];
        sprintf(mensaje, "Calificacion %d: ", i + 1);
        
        if (!leerFloat(&e->calificaciones[i], 0.0, 10.0, mensaje)) {
            printf("%s[ERROR] No se pudo registrar la calificacion %d. Operacion cancelada.%s\n", COLOR_RED, i + 1, COLOR_RESET);
            return;
        }
    }
    
    printf("\n%s[EXITO] Todos los datos han sido validados correctamente.%s\n", COLOR_GREEN, COLOR_RESET);
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
    printf("\n%s=== %s ===%s\n", COLOR_BLUE, e.nombre, COLOR_RESET);
    printf("Edad: %d\n", e.edad);
    printf("Matricula: %s\n", e.matricula);
    printf("Calificaciones: ");
    for (int i = 0; i < 5; i++) {
        if (e.calificaciones[i] >= 6.0) {
            printf("%s%.2f%s ", COLOR_GREEN, e.calificaciones[i], COLOR_RESET);
        } else {
            printf("%s%.2f%s ", COLOR_RED, e.calificaciones[i], COLOR_RESET);
        }
    }
    
    if (e.promedio >= 6.0) {
        printf("\nPromedio: %s%.2f%s (%sAPROBADO%s)\n", 
               COLOR_GREEN, e.promedio, COLOR_RESET, COLOR_GREEN, COLOR_RESET);
    } else {
        printf("\nPromedio: %s%.2f%s (%sREPROBADO%s)\n", 
               COLOR_RED, e.promedio, COLOR_RESET, COLOR_RED, COLOR_RESET);
    }
    printf("----------------------------------------\n");
}

// Función para limpiar la pantalla
void limpiarPantalla() {
    system("cls"); // Para Windows
}

// Función para pausar y esperar entrada del usuario
void pausar() {
    printf("\n%sPresione Enter para continuar...%s", COLOR_YELLOW, COLOR_RESET);
    getchar();
}

// Función para confirmar una acción
int confirmarAccion(char *mensaje) {
    char respuesta;
    printf("%s%s (s/n): %s", COLOR_YELLOW, mensaje, COLOR_RESET);
    scanf(" %c", &respuesta);
    getchar();
    return (respuesta == 's' || respuesta == 'S');
}

// Función para buscar estudiante por matrícula
void buscarEstudiantePorMatricula(Estudiante *lista, int n) {
    char matricula[15];
    int encontrado = 0;
    
    printf("%s--- Buscar Estudiante ---%s\n", COLOR_CYAN, COLOR_RESET);
    printf("Ingrese la matricula a buscar: ");
    fgets(matricula, 15, stdin);
    matricula[strcspn(matricula, "\n")] = 0;
    
    for (int i = 0; i < n; i++) {
        if (strcmp(lista[i].matricula, matricula) == 0) {
            printf("%s[EXITO] Estudiante encontrado:%s\n", COLOR_GREEN, COLOR_RESET);
            mostrarEstudiante(lista[i]);
            encontrado = 1;
            break;
        }
    }
    
    if (!encontrado) {
        printf("%s[ERROR] No se encontro ningun estudiante con esa matricula.%s\n", COLOR_RED, COLOR_RESET);
    }
}

// Función para editar un estudiante existente
void editarEstudiante(Estudiante *lista, int n) {
    char matricula[15];
    int encontrado = -1;
    
    printf("%s--- Editar Estudiante ---%s\n", COLOR_CYAN, COLOR_RESET);
    if (!leerCadena(matricula, 15, "Ingrese la matricula del estudiante a editar: ", validarFormatoMatricula)) {
        printf("%s[ERROR] Operacion cancelada.%s\n", COLOR_RED, COLOR_RESET);
        return;
    }
    
    for (int i = 0; i < n; i++) {
        if (strcmp(lista[i].matricula, matricula) == 0) {
            encontrado = i;
            break;
        }
    }
    
    if (encontrado == -1) {
        printf("%s[ERROR] No se encontro ningun estudiante con esa matricula.%s\n", COLOR_RED, COLOR_RESET);
        return;
    }
    
    printf("%s[EXITO] Estudiante encontrado:%s\n", COLOR_GREEN, COLOR_RESET);
    mostrarEstudiante(lista[encontrado]);
    
    if (!confirmarAccion("Desea editar este estudiante?")) {
        return;
    }
    
    printf("\n%s=== Edicion de Datos ===%s\n", COLOR_YELLOW, COLOR_RESET);
    printf("%sNota: Presione Enter para mantener el valor actual%s\n\n", COLOR_BLUE, COLOR_RESET);
    
    // Crear copia temporal
    Estudiante temp = lista[encontrado];
    
    // Editar nombre
    char nuevoNombre[50];
    printf("Nombre actual: %s%s%s\n", COLOR_CYAN, temp.nombre, COLOR_RESET);
    printf("Nuevo nombre (Enter para mantener): ");
    fgets(nuevoNombre, 50, stdin);
    nuevoNombre[strcspn(nuevoNombre, "\n")] = 0;
    
    if (strlen(nuevoNombre) > 0) {
        if (validarNombre(nuevoNombre)) {
            strcpy(temp.nombre, nuevoNombre);
            printf("%s[EXITO] Nombre actualizado.%s\n", COLOR_GREEN, COLOR_RESET);
        } else {
            printf("%s[AVISO] Nombre no valido, se mantiene el anterior.%s\n", COLOR_YELLOW, COLOR_RESET);
        }
    }
    
    // Editar edad
    printf("\nEdad actual: %s%d%s\n", COLOR_CYAN, temp.edad, COLOR_RESET);
    printf("Desea cambiar la edad? (s/n): ");
    char respuesta;
    scanf(" %c", &respuesta);
    getchar();
    
    if (respuesta == 's' || respuesta == 'S') {
        int nuevaEdad;
        if (leerEntero(&nuevaEdad, 0, 100, "Nueva edad (0-100): ")) {
            temp.edad = nuevaEdad;
            printf("%s[EXITO] Edad actualizada.%s\n", COLOR_GREEN, COLOR_RESET);
        } else {
            printf("%s[AVISO] Edad no valida, se mantiene la anterior.%s\n", COLOR_YELLOW, COLOR_RESET);
        }
    }
    
    // Editar calificaciones
    printf("\nCalificaciones actuales: ");
    for (int i = 0; i < 5; i++) {
        printf("%.2f ", temp.calificaciones[i]);
    }
    printf("\nDesea cambiar las calificaciones? (s/n): ");
    scanf(" %c", &respuesta);
    getchar();
    
    if (respuesta == 's' || respuesta == 'S') {
        printf("\n%s=== Nuevas Calificaciones ===%s\n", COLOR_CYAN, COLOR_RESET);
        for (int i = 0; i < 5; i++) {
            printf("Calificacion actual %d: %.2f\n", i + 1, temp.calificaciones[i]);
            char mensaje[50];
            sprintf(mensaje, "Nueva calificacion %d (Enter para mantener): ", i + 1);

            char input[20];
            printf("%s", mensaje);
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = 0;
            
            if (strlen(input) > 0) {
                float nuevaCalif = atof(input);
                if (validarCalificacion(nuevaCalif)) {
                    temp.calificaciones[i] = nuevaCalif;
                    printf("%s[EXITO] Calificacion %d actualizada.%s\n", COLOR_GREEN, i + 1, COLOR_RESET);
                } else {
                    printf("%s[AVISO] Calificacion no valida, se mantiene la anterior.%s\n", COLOR_YELLOW, COLOR_RESET);
                }
            }
        }
    }
    
    // Confirmar cambios
    printf("\n%s=== Resumen de Cambios ===%s\n", COLOR_YELLOW, COLOR_RESET);
    mostrarEstudiante(temp);
    
    if (confirmarAccion("Confirma los cambios?")) {
        calcularPromedio(&temp);
        lista[encontrado] = temp;
        printf("%s[EXITO] Estudiante actualizado exitosamente.%s\n", COLOR_GREEN, COLOR_RESET);
    } else {
        printf("%s[AVISO] Cambios descartados.%s\n", COLOR_YELLOW, COLOR_RESET);
    }
}

// Función para eliminar un estudiante
void eliminarEstudiante(Estudiante *lista, int *n) {
    char matricula[15];
    int encontrado = -1;
    
    printf("%s--- Eliminar Estudiante ---%s\n", COLOR_RED, COLOR_RESET);
    printf("Ingrese la matricula del estudiante a eliminar: ");
    fgets(matricula, 15, stdin);
    matricula[strcspn(matricula, "\n")] = 0;
    
    for (int i = 0; i < *n; i++) {
        if (strcmp(lista[i].matricula, matricula) == 0) {
            encontrado = i;
            break;
        }
    }
    
    if (encontrado == -1) {
        printf("%s[ERROR] No se encontro ningun estudiante con esa matricula.%s\n", COLOR_RED, COLOR_RESET);
        return;
    }
    
    printf("%s[AVISO] Estudiante a eliminar:%s\n", COLOR_YELLOW, COLOR_RESET);
    mostrarEstudiante(lista[encontrado]);
    
    if (!confirmarAccion("Esta seguro de eliminar este estudiante?")) {
        return;
    }
    
    // Mover todos los elementos hacia la izquierda
    for (int i = encontrado; i < *n - 1; i++) {
        lista[i] = lista[i + 1];
    }
    (*n)--;
    
    printf("%s[EXITO] Estudiante eliminado exitosamente.%s\n", COLOR_GREEN, COLOR_RESET);
}

// Función para mostrar estadísticas
void mostrarEstadisticas(Estudiante *lista, int n) {
    if (n == 0) {
        printf("%s[ERROR] No hay estudiantes registrados.%s\n", COLOR_RED, COLOR_RESET);
        return;
    }
    
    float sumaPromedios = 0;
    float mejorPromedio = lista[0].promedio;
    float peorPromedio = lista[0].promedio;
    int aprobados = 0, reprobados = 0;
    int indiceMejor = 0, indicePeor = 0;
    
    for (int i = 0; i < n; i++) {
        sumaPromedios += lista[i].promedio;
        
        if (lista[i].promedio >= 6.0) aprobados++;
        else reprobados++;
        
        if (lista[i].promedio > mejorPromedio) {
            mejorPromedio = lista[i].promedio;
            indiceMejor = i;
        }
        
        if (lista[i].promedio < peorPromedio) {
            peorPromedio = lista[i].promedio;
            indicePeor = i;
        }
    }
    
    printf("\n%s=== ESTADISTICAS ===%s\n", COLOR_CYAN, COLOR_RESET);
    printf("Total de estudiantes: %d\n", n);
    printf("Promedio general: %.2f\n", sumaPromedios/n);
    printf("%sAprobados: %d%s\n", COLOR_GREEN, aprobados, COLOR_RESET);
    printf("%sReprobados: %d%s\n", COLOR_RED, reprobados, COLOR_RESET);
    printf("\n%sMejor estudiante:%s\n", COLOR_GREEN, COLOR_RESET);
    printf("  %s (Promedio: %.2f)\n", lista[indiceMejor].nombre, mejorPromedio);
    printf("\nEstudiante con menor promedio:\n");
    printf("  %s (Promedio: %.2f)\n", lista[indicePeor].nombre, peorPromedio);
}

// Función para mostrar menú de ordenamiento
void mostrarMenuOrdenamiento() {
    printf("\n%s--- Criterios de Ordenamiento ---%s\n", COLOR_CYAN, COLOR_RESET);
    printf("1. Por nombre (A-Z)\n");
    printf("2. Por promedio (mayor a menor)\n");
    printf("3. Por promedio (menor a mayor)\n");
    printf("4. Por matricula\n");
    printf("Seleccione un criterio: ");
}

// Función para ordenar estudiantes
void ordenarEstudiantes(Estudiante *lista, int n, int criterio) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            int intercambiar = 0;
            
            switch (criterio) {
                case 1: // Por nombre
                    if (strcmp(lista[j].nombre, lista[j + 1].nombre) > 0)
                        intercambiar = 1;
                    break;
                case 2: // Por promedio (mayor a menor)
                    if (lista[j].promedio < lista[j + 1].promedio)
                        intercambiar = 1;
                    break;
                case 3: // Por promedio (menor a mayor)
                    if (lista[j].promedio > lista[j + 1].promedio)
                        intercambiar = 1;
                    break;
                case 4: // Por matrícula
                    if (strcmp(lista[j].matricula, lista[j + 1].matricula) > 0)
                        intercambiar = 1;
                    break;
            }
            
            if (intercambiar) {
                Estudiante temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
            }
        }
    }
    printf("%s[EXITO] Lista ordenada exitosamente.%s\n", COLOR_GREEN, COLOR_RESET);
}

// ===== FUNCIONES DE VALIDACIÓN =====

// Función para limpiar el buffer de entrada
void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Función para verificar si una cadena contiene solo números
int esNumerico(char *str) {
    if (str == NULL || strlen(str) == 0) return 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) return 0;
    }
    return 1;
}

// Función para validar nombres (solo letras y espacios)
int validarNombre(char *nombre) {
    if (nombre == NULL || strlen(nombre) == 0) {
        printf("%s[ERROR] Error: El nombre no puede estar vacio.%s\n", COLOR_RED, COLOR_RESET);
        return 0;
    }
    
    if (strlen(nombre) > 49) {
        printf("%s[ERROR] Error: El nombre es demasiado largo (maximo 49 caracteres).%s\n", COLOR_RED, COLOR_RESET);
        return 0;
    }
    
    for (int i = 0; nombre[i] != '\0'; i++) {
        if (!isalpha(nombre[i]) && nombre[i] != ' ' && nombre[i] != '.') {
            printf("%s[ERROR] Error: El nombre solo puede contener letras, espacios y puntos.%s\n", COLOR_RED, COLOR_RESET);
            return 0;
        }
    }
    return 1;
}

// Función para validar edad
int validarEdad(int edad) {
    if (edad < 0 || edad > 100) {
        printf("%s[ERROR] Error: La edad debe estar entre 0 y 100 anos.%s\n", COLOR_RED, COLOR_RESET);
        return 0;
    }
    return 1;
}

// Función para validar matrícula (10 dígitos y única)
int validarMatricula(char *matricula, Estudiante *lista, int n) {
    if (matricula == NULL || strlen(matricula) == 0) {
        printf("%s[ERROR] Error: La matricula no puede estar vacia.%s\n", COLOR_RED, COLOR_RESET);
        return 0;
    }
    
    if (strlen(matricula) != 10) {
        printf("%s[ERROR] Error: La matricula debe tener exactamente 10 digitos.%s\n", COLOR_RED, COLOR_RESET);
        return 0;
    }
    
    if (!esNumerico(matricula)) {
        printf("%s[ERROR] Error: La matricula solo puede contener numeros.%s\n", COLOR_RED, COLOR_RESET);
        return 0;
    }
    
    // Verificar que la matrícula no esté duplicada
    for (int i = 0; i < n; i++) {
        if (strcmp(lista[i].matricula, matricula) == 0) {
            printf("%s[ERROR] Error: Ya existe un estudiante con esa matricula.%s\n", COLOR_RED, COLOR_RESET);
            return 0;
        }
    }
    
    return 1;
}

// Función para validar formato básico de matrícula (sin verificar duplicados)
int validarFormatoMatricula(char *matricula) {
    if (matricula == NULL || strlen(matricula) == 0) {
        printf("%s[ERROR] Error: La matricula no puede estar vacia.%s\n", COLOR_RED, COLOR_RESET);
        return 0;
    }
    
    if (strlen(matricula) != 10) {
        printf("%s[ERROR] Error: La matricula debe tener exactamente 10 digitos.%s\n", COLOR_RED, COLOR_RESET);
        return 0;
    }
    
    if (!esNumerico(matricula)) {
        printf("%s[ERROR] Error: La matricula solo puede contener numeros.%s\n", COLOR_RED, COLOR_RESET);
        return 0;
    }
    
    return 1;
}

// Función para validar calificaciones (0.0 a 10.0)
int validarCalificacion(float calificacion) {
    if (calificacion < 0.0 || calificacion > 10.0) {
        printf("%s[ERROR] Error: La calificacion debe estar entre 0.0 y 10.0.%s\n", COLOR_RED, COLOR_RESET);
        return 0;
    }
    return 1;
}

// Función para leer un entero con validación
int leerEntero(int *valor, int min, int max, char *mensaje) {
    char input[20];
    int intentos = 0;
    
    do {
        if (intentos > 0) {
            printf("%s[AVISO] Intento %d de 3. %s", COLOR_YELLOW, intentos + 1, COLOR_RESET);
        }
        printf("%s", mensaje);
        
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("%s[ERROR] Error al leer la entrada.%s\n", COLOR_RED, COLOR_RESET);
            return 0;
        }
        
        // Eliminar salto de línea
        input[strcspn(input, "\n")] = 0;
        
        // Verificar si es numérico
        int esValido = 1;
        for (int i = 0; input[i] != '\0'; i++) {
            if (!isdigit(input[i])) {
                esValido = 0;
                break;
            }
        }
        
        if (!esValido || strlen(input) == 0) {
            printf("%s[ERROR] Error: Debe ingresar un numero valido.%s\n", COLOR_RED, COLOR_RESET);
            intentos++;
            continue;
        }
        
        *valor = atoi(input);
        
        if (*valor >= min && *valor <= max) {
            return 1;
        } else {
            printf("%s[ERROR] Error: El valor debe estar entre %d y %d.%s\n", COLOR_RED, min, max, COLOR_RESET);
            intentos++;
        }
        
    } while (intentos < 3);
    
    printf("%s[ERROR] Demasiados intentos fallidos.%s\n", COLOR_RED, COLOR_RESET);
    return 0;
}

// Función para leer un float con validación
int leerFloat(float *valor, float min, float max, char *mensaje) {
    char input[20];
    int intentos = 0;
    
    do {
        if (intentos > 0) {
            printf("%s[AVISO] Intento %d de 3. %s", COLOR_YELLOW, intentos + 1, COLOR_RESET);
        }
        printf("%s", mensaje);
        
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("%s[ERROR] Error al leer la entrada.%s\n", COLOR_RED, COLOR_RESET);
            return 0;
        }
        
        // Eliminar salto de línea
        input[strcspn(input, "\n")] = 0;
        
        // Convertir y validar
        char *endptr;
        *valor = strtof(input, &endptr);
        
        if (*endptr != '\0' || strlen(input) == 0) {
            printf("%s[ERROR] Error: Debe ingresar un numero valido (use punto decimal).%s\n", COLOR_RED, COLOR_RESET);
            intentos++;
            continue;
        }
        
        if (*valor >= min && *valor <= max) {
            return 1;
        } else {
            printf("%s[ERROR] Error: El valor debe estar entre %.1f y %.1f.%s\n", COLOR_RED, min, max, COLOR_RESET);
            intentos++;
        }
        
    } while (intentos < 3);
    
    printf("%s[ERROR] Demasiados intentos fallidos.%s\n", COLOR_RED, COLOR_RESET);
    return 0;
}

// Función para leer una cadena con validación
int leerCadena(char *destino, int tamano, char *mensaje, int (*validador)(char*)) {
    int intentos = 0;
    
    do {
        if (intentos > 0) {
            printf("%s[AVISO] Intento %d de 3. %s", COLOR_YELLOW, intentos + 1, COLOR_RESET);
        }
        printf("%s", mensaje);
        
        if (fgets(destino, tamano, stdin) == NULL) {
            printf("%s[ERROR] Error al leer la entrada.%s\n", COLOR_RED, COLOR_RESET);
            return 0;
        }
        
        // Eliminar salto de línea
        destino[strcspn(destino, "\n")] = 0;
        
        // Si no hay validador, aceptar cualquier entrada no vacía
        if (validador == NULL) {
            if (strlen(destino) > 0) {
                return 1;
            } else {
                printf("%s[ERROR] Error: La entrada no puede estar vacia.%s\n", COLOR_RED, COLOR_RESET);
                intentos++;
                continue;
            }
        }
        
        // Si hay validador, usarlo
        if (validador(destino)) {
            return 1;
        }
        
        intentos++;
        
    } while (intentos < 3);
    
    printf("%s[ERROR] Demasiados intentos fallidos.%s\n", COLOR_RED, COLOR_RESET);
    return 0;
}