#ifndef ARCHIVO_H
#define ARCHIVO_H

#include "estudiante.h"

// Prototipos de funciones para guardar y cargar estudiantes en archivo
void guardarArchivo(Estudiante *lista, int n); // Guarda la lista de estudiantes en un archivo
int cargarArchivo(Estudiante *lista);          // Carga estudiantes desde un archivo y retorna la cantidad

#endif