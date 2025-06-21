# StudentManager v1.0

**Fecha de última revisión:** 20/06/2025  
**Autor:** Iquí-Balam López Hernández

## Descripción
Este programa gestiona una lista de estudiantes, permitiendo agregar, mostrar, guardar y cargar datos desde un archivo.

## Lenguaje
C

## Requisitos
- Windows API para manejar diálogos de archivos.
- Biblioteca estándar de C para manejo de cadenas y entrada/salida.
- Requiere MinGW o un compilador compatible con la API de Windows para compilar correctamente.

## Estructura de archivos

- **main.c**  
  Archivo principal. Muestra el menú, gestiona las opciones del usuario y coordina las operaciones sobre la lista de estudiantes.

- **estudiante.h**  
  Define la estructura `Estudiante` y declara las funciones para agregar, mostrar y calcular el promedio de estudiantes.

- **estudiante.c**  
  Implementa las funciones para solicitar datos, calcular el promedio y mostrar la información de cada estudiante.

- **archivo.h**  
  Declara las funciones para guardar y cargar estudiantes en/desde un archivo.

- **archivo.c**  
  Implementa las funciones para guardar y cargar la lista de estudiantes usando cuadros de diálogo de Windows para seleccionar archivos.

### Compilación con GCC (MinGW)
Este código está diseñado para compilarse en un entorno Windows utilizando el compilador de C estándar.
Abre la terminal en la carpeta del proyecto y ejecuta:

```sh
gcc main.c estudiante.c archivo.c -o StudentManager.exe -lcomdlg32
```

Esto generará el ejecutable `StudentManager.exe`.

## Uso
1. Compila el código en un entorno compatible con C.
2. Ejecuta el programa.
3. Sigue las instrucciones del menú para agregar estudiantes, mostrar datos, guardar en un archivo o cargar desde un archivo.

## Limitaciones
- El número máximo de estudiantes es 100.
- Las calificaciones se limitan a 5 por estudiante.
- El programa utiliza un formato de archivo simple para guardar y cargar datos, separado por punto y coma y comas.
- El programa está diseñado para ejecutarse en un entorno de consola de Windows.
- No se implementa manejo de errores avanzado, por lo que se asume que las entradas son válidas.
- No se aceptan entradas de texto con caracteres especiales que puedan interferir con el formato del archivo.
