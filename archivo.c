#include "archivo.h"
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <commdlg.h>

#define MAX_PATH_LEN 260
#define MAX_ESTUDIANTES 100

// Muestra un cuadro de diálogo para seleccionar un archivo para abrir o guardar
// modoGuardar = 1 para guardar, 0 para abrir
int seleccionarArchivo(char *ruta, DWORD modoGuardar) {
    OPENFILENAME ofn;
    ZeroMemory(&ofn, sizeof(ofn));
    ZeroMemory(ruta, MAX_PATH_LEN);
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = NULL;
    ofn.lpstrFile = ruta;
    ofn.nMaxFile = MAX_PATH_LEN;
    ofn.lpstrFilter = "Archivos de texto\0*.txt\0Todos los archivos\0*.*\0";
    ofn.nFilterIndex = 1;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
    if (modoGuardar) {
        ofn.Flags |= OFN_OVERWRITEPROMPT;
        return GetSaveFileName(&ofn); // Cuadro de diálogo para guardar
    } else {
        return GetOpenFileName(&ofn); // Cuadro de diálogo para abrir
    }
}

// Guarda la lista de estudiantes en el archivo seleccionado por el usuario
void guardarArchivo(Estudiante *lista, int n) {
    char ruta[MAX_PATH_LEN];
    if (!seleccionarArchivo(ruta, 1)) {
        printf("Operacion cancelada.\n");
        return;
    }
    FILE *f = fopen(ruta, "w");
    if (!f) {
        printf("Error al abrir el archivo.\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        // Escribe los datos separados por ';' y las calificaciones por ','
        fprintf(f, "%s;%d;%s;", lista[i].nombre, lista[i].edad, lista[i].matricula);
        for (int j = 0; j < 5; j++) {
            fprintf(f, "%.2f", lista[i].calificaciones[j]);
            if (j < 4) fprintf(f, ",");
        }
        fprintf(f, ";%.2f\n", lista[i].promedio);
    }
    fclose(f);
    printf("Datos guardados correctamente en %s\n", ruta);
}

// Carga los estudiantes desde el archivo seleccionado por el usuario
// Muestra la cantidad de estudiantes cargados
int cargarArchivo(Estudiante *lista) {
    char ruta[MAX_PATH_LEN];
    if (!seleccionarArchivo(ruta, 0)) {
        printf("Operacion cancelada.\n");
        return 0;
    }
    FILE *f = fopen(ruta, "r");
    if (!f) {
        printf("No se pudo abrir el archivo.\n");
        return 0;
    }
    int n = 0;
    char linea[256];
    // Lee cada línea del archivo y la separa en los campos correspondientes
    while (fgets(linea, sizeof(linea), f) && n < MAX_ESTUDIANTES) {
        linea[strcspn(linea, "\r\n")] = 0; // Elimina salto de línea
        char *nombre = strtok(linea, ";");
        char *edad = strtok(NULL, ";");
        char *matricula = strtok(NULL, ";");
        char *califStr = strtok(NULL, ";");
        char *promedio = strtok(NULL, ";");

        if (!nombre || !edad || !matricula || !califStr || !promedio) continue;

        strncpy(lista[n].nombre, nombre, sizeof(lista[n].nombre));
        lista[n].nombre[sizeof(lista[n].nombre)-1] = '\0';
        lista[n].edad = atoi(edad);
        strncpy(lista[n].matricula, matricula, sizeof(lista[n].matricula));
        lista[n].matricula[sizeof(lista[n].matricula)-1] = '\0';

        // Separa las calificaciones por coma
        char *calif = strtok(califStr, ",");
        int i = 0;
        while (calif && i < 5) {
            lista[n].calificaciones[i++] = atof(calif);
            calif = strtok(NULL, ",");
        }
        while (i < 5) lista[n].calificaciones[i++] = 0.0f;

        lista[n].promedio = atof(promedio);

        n++;
    }
    fclose(f);
    printf("Datos cargados desde %s\n", ruta);
    return n;
}