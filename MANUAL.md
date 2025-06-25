# Manual de Usuario - StudentManager v3.1

## Índice
1. [Introducción](#introducción)
2. [Instalación y Ejecución](#instalación-y-ejecución)
3. [Menú Principal](#menú-principal)
4. [Gestión de Estudiantes](#gestión-de-estudiantes)
5. [Funciones Avanzadas](#funciones-avanzadas)
6. [Manejo de Archivos](#manejo-de-archivos)
7. [Consejos y Mejores Prácticas](#consejos-y-mejores-prácticas)
8. [Solución de Problemas](#solución-de-problemas)

---

## Introducción

**StudentManager v3.1** es un sistema de gestión de estudiantes desarrollado en C. Permite registrar, consultar, editar y analizar información de estudiantes.

### **Características Principales:**
- Gestión completa de estudiantes (CRUD)
- Validaciones de datos
- Interfaz con colores informativos
- Sistema de archivos para persistencia
- Estadísticas y reportes automáticos
- Compatible con casi cualquier terminal en Windows

---

## Instalación y Ejecución

### **Requisitos del Sistema:**
- Windows 7-11
- Terminal o Command Prompt
- Archivo ejecutable `StudentManager.exe`

### **Ejecución:**
1. Abra Command Prompt o PowerShell
2. Navegue a la carpeta del programa
3. Ejecute el comando:
   ```
   StudentManager.exe
   ```
4. El programa se iniciará automáticamente

### **Primera Ejecución:**
- El programa inicia con 0 estudiantes registrados
- Capacidad máxima: 100 estudiantes
- Todos los menús y funciones están disponibles inmediatamente

---

## Menú Principal

Al iniciar el programa, verá el menú principal:

```
=== GESTOR DE ESTUDIANTES ===

1. Agregar estudiante
2. Mostrar todos los estudiantes
3. Mostrar aprobados
4. Mostrar reprobados
5. Guardar en archivo
6. Cargar desde archivo

--- Funciones adicionales ---
7. Buscar estudiante por matrícula
8. Editar estudiante
9. Eliminar estudiante
10. Ordenar lista
11. Ver estadísticas

0. Salir

Estudiantes registrados: 0/100
Seleccione una opción: 
```

### **Navegación:**
- Ingrese el número de la opción deseada (0-11)
- Presione Enter para confirmar
- Use 0 para salir del programa
- El contador muestra estudiantes actuales/máximo

---

## Gestión de Estudiantes

### **1. Agregar Estudiante**

**Seleccione opción:** `1`

El sistema solicitará los siguientes datos con validación automática:

#### **Nombre Completo:**
- **Formato aceptado:** Solo letras, espacios y puntos
- **Ejemplos válidos:** 
  - "Ana Garcia Lopez"
  - "Dr. Juan Perez"
  - "Maria Jose"
- **Ejemplos NO válidos:**
  - "Ana123" (contiene números)
  - "José@email" (contiene símbolos)
  - "" (vacío)

#### **Edad:**
- **Rango permitido:** 0 a 100 años
- **Formato:** Número entero
- **Ejemplos válidos:** 18, 25, 67
- **Ejemplos NO válidos:** 1.4, 112, -5

#### **Matrícula:**
- **Formato requerido:** Exactamente 10 dígitos
- **Solo números:** No letras ni símbolos
- **Debe ser única:** No puede repetirse
- **Ejemplos válidos:** "2024060001", "2025123456"
- **Ejemplos NO válidos:** 
  - "123456" (muy corta)
  - "2024ABC001" (contiene letras)
  - Matrícula ya existente

#### **Calificaciones:**
- **Cantidad:** 5 calificaciones obligatorias
- **Rango:** 0.0 a 10.0
- **Formato:** Números decimales (use punto, no coma)
- **Ejemplos válidos:** 8.5, 10.0, 0.0, 7.25
- **Ejemplos NO válidos:** -1.0, 11.5, abc

#### **Sistema de Intentos:**
- Cada campo permite **3 intentos**
- Si agota los intentos, la operación se cancela
- Puede reintentar desde el menú principal

### **2. Mostrar Estudiantes**

#### **Mostrar Todos (Opción 2):**
Muestra la lista completa de estudiantes registrados con formato:
```
[1/5] === Ana Garcia Lopez ===
Edad: 20
Matrícula: 2024060001
Calificaciones: 8.50 9.00 7.50 8.00 9.50 
Promedio: 8.50 (APROBADO)
----------------------------------------
```

#### **Mostrar Aprobados (Opción 3):**
- Filtra estudiantes con promedio >= 6.0
- Muestra el total de aprobados al final

#### **Mostrar Reprobados (Opción 4):**
- Filtra estudiantes con promedio < 6.0  
- Muestra el total de reprobados al final

### **3. Buscar Estudiante (Opción 7)**

**Búsqueda por matrícula:**
1. Ingrese la matrícula exacta (10 dígitos)
2. El sistema mostrará los datos completos si existe
3. Mensaje de error si no se encuentra

### **4. Editar Estudiante (Opción 8)**

**Proceso de edición:**
1. Ingrese la matrícula del estudiante a editar
2. El sistema muestra los datos actuales
3. Confirme que desea editar
4. Para cada campo:
   - Se muestra el valor actual
   - Puede mantener el valor (presione Enter)
   - O ingresar un nuevo valor
5. Confirme los cambios antes de guardar

**Campos editables:**
- Nombre (con validación)
- Edad (con validación)
- Calificaciones individuales (con validación)
- **Nota:** La matrícula NO se puede editar

### **5. Eliminar Estudiante (Opción 9)**

**Proceso de eliminación:**
1. Ingrese la matrícula del estudiante
2. El sistema muestra los datos del estudiante
3. **CONFIRMACIÓN OBLIGATORIA:** Debe confirmar la eliminación
4. La eliminación es **PERMANENTE** (no se puede deshacer)

---

## Funciones Avanzadas

### **6. Ordenar Lista (Opción 10)**

**Criterios de ordenamiento disponibles:**
1. **Por nombre (A-Z)** - Orden alfabético
2. **Por promedio (mayor a menor)** - Mejores estudiantes primero
3. **Por promedio (menor a mayor)** - Para identificar estudiantes en riesgo
4. **Por matrícula** - Orden numérico

**Uso:**
1. Seleccione la opción 10
2. Elija el criterio (1-4)
3. La lista se reordena automáticamente
4. El nuevo orden se mantiene hasta nuevo ordenamiento

### **7. Ver Estadísticas (Opción 11)**

**Información proporcionada:**
- **Total de estudiantes** registrados
- **Promedio general** del grupo
- **Número de aprobados** y porcentaje
- **Número de reprobados** y porcentaje
- **Mejor estudiante** (mayor promedio)
- **Estudiante con menor promedio**

**Ejemplo de salida:**
```
=== ESTADÍSTICAS ===
Total de estudiantes: 5
Promedio general: 7.28
Aprobados: 4
Reprobados: 1

Mejor estudiante:
  María José Fernández (Promedio: 9.30)

Estudiante con menor promedio:
  Carlos Ruiz (Promedio: 4.80)
```

---

## Manejo de Archivos

### **8. Guardar en Archivo (Opción 5)**

**Proceso:**
1. Seleccione la opción 5
2. Se abrirá un diálogo de Windows para elegir ubicación
3. Ingrese el nombre del archivo (se agrega .txt automáticamente)
4. Los datos se guardan

**Formato del archivo:**
```
Ana Garcia Lopez;20;2024060001;8.50,9.00,7.50,8.00,9.50;8.50
Carlos Ruiz;22;2024060002;6.00,5.50,7.00,6.50,6.00;6.20
```

### **9. Cargar desde Archivo (Opción 6)**

**Proceso:**
1. Seleccione la opción 6
2. **ADVERTENCIA:** Si hay datos actuales, se preguntará si desea sobrescribirlos
3. Se abrirá un diálogo para seleccionar el archivo
4. Los datos se cargan y validan automáticamente

**Consideraciones importantes:**
- Los datos actuales se **PERDERÁN** al cargar un archivo
- El archivo debe tener el formato correcto
- Matrículas duplicadas en el archivo causarán errores

---

## Solución de Problemas

### **Problemas Comunes:**

#### **"El programa no inicia"**
- Verifique que esté en una máquina Windows
- Asegúrese de tener permisos de ejecución
- Ejecute desde Command Prompt, o ejecute el .exe directamente

#### **"No acepta nombre/matrícula"**
- **Nombres:** Solo letras, espacios y puntos
- **Matrículas:** Exactamente 10 dígitos numéricos
- Revise los ejemplos del manual

#### **"Dice que la matrícula ya existe"**
- Cada matrícula debe ser única
- Use la función "Buscar" para verificar si ya existe
- Inntente borrando el estudiante con esa matrícula si es necesario

#### **"No se puede guardar/cargar archivos"**
- Verifique permisos de escritura en la carpeta
- Asegúrese de que no haya archivos bloqueados
- Revisar que el archivo tenga el formato correcto y sea un .txt

#### **"Los colores no se ven bien"**
- Use Windows Terminal o PowerShell para mejor soporte
- Intente cambiar la configuración de colores desde la terminal

#### **"Perdí mis datos"**
- Sin archivo guardado, los datos se pierden al cerrar
- Siempre usar "Guardar en archivo" antes de salir
- Los archivos guardados se pueden cargar nuevamente

### **Mensajes del Sistema:**

- **[EXITO]** - La operación se completó correctamente
- **[ERROR]** - Hay un problema que debe corregir
- **[AVISO]** - Información importante

### **Límites del Programa:**
- **Máximo 100 estudiantes** por sesión
- **3 intentos** por campo al ingresar datos
- **5 calificaciones** por estudiante (fijo)
- **Solo Windows** como plataforma compatible

---
