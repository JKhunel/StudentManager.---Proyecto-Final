# [SHIELD] Sistema de Validación de Datos - StudentManager

## [MANUAL] **Validaciones Implementadas**

### **1. Validación de Nombres** 
```c
int validarNombre(char *nombre)
```
**Criterios:**
- [OK] No puede estar vacío
- [OK] Máximo 49 caracteres
- [OK] Solo letras, espacios y puntos
- ❌ Números o símbolos especiales

**Ejemplos:**
- [OK] `"Ana García Lopez"`
- [OK] `"Jose María"`
- [OK] `"Dr. Juan Perez"`
- ❌ `"Ana123"` (contiene números)
- ❌ `""`  (vacío)

### **2. Validación de Edad**
```c
int validarEdad(int edad)
```
**Criterios:**
- [OK] Rango: 0 a 100 años
- ❌ Menores de 0 años
- ❌ Mayores de 100 años

**Ejemplos:**
- [OK] `18`, `25`, `45`
- ❌ `-14`, `112`, `-5`

### **3. Validación de Matrícula**
```c
int validarMatricula(char *matricula, Estudiante *lista, int n)
```
**Criterios:**
- [OK] Exactamente 10 dígitos
- [OK] Solo números
- [OK] Debe ser única (no duplicada)
- ❌ Letras o símbolos
- ❌ Más o menos de 10 dígitos

**Ejemplos:**
- [OK] `"2024060001"`
- [OK] `"2025123456"`
- ❌ `"2024ABC001"` (contiene letras)
- ❌ `"123456"` (muy corta)
- ❌ `"2024060001"` (si ya existe)

### **4. Validación de Calificaciones**
```c
int validarCalificacion(float calificacion)
```
**Criterios:**
- [OK] Rango: 0.0 a 10.0
- [OK] Acepta decimales
- ❌ Valores negativos
- ❌ Mayores a 10.0

**Ejemplos:**
- [OK] `8.5`, `10.0`, `0.0`, `6.75`
- ❌ `-1.0`, `11.5`, `100`

## [TOOL] **Funciones de Apoyo**

### **Lectura Segura de Enteros**
```c
int leerEntero(int *valor, int min, int max, char *mensaje)
```
- 🔄 **3 intentos** por campo
- 🔍 **Validación automática** de rango
- [WARNING] **Mensajes informativos** de error

### **Lectura Segura de Decimales**
```c
int leerFloat(float *valor, float min, float max, char *mensaje)
```
- 🔄 **3 intentos** por campo
- 🔍 **Validación de formato** decimal
- [WARNING] **Guía de uso** (punto decimal)

### **Lectura Segura de Cadenas**
```c
int leerCadena(char *destino, int tamano, char *mensaje, int (*validador)(char*))
```
- 🔄 **3 intentos** por campo
- 🔍 **Validador personalizable**
- [SHIELD] **Protección contra desbordamiento**

## 📝 **Experiencia de Usuario**

### **Flujo de Validación:**
```
=== Ingreso de Datos del Estudiante ===
Nota: Tendrá 3 intentos para cada campo

Nombre completo: Ana123
❌ Error: El nombre solo puede contener letras, espacios y puntos.
[WARNING] Intento 2 de 3. Nombre completo: Ana García
✓ Nombre validado correctamente.

Edad (15-100 años): 200
❌ Error: El valor debe estar entre 15 y 100.
[WARNING] Intento 2 de 3. Edad (15-100 años): 20
✓ Edad validada correctamente.

Formato de matrícula: 10 dígitos (ej: 2024060001)
Matrícula: 123
❌ Error: La matrícula debe tener exactamente 10 dígitos.
[WARNING] Intento 2 de 3. Matrícula: 2024060001
✓ Matrícula validada correctamente.

=== Calificaciones (0.0 - 10.0) ===
Calificación 1: 15
❌ Error: El valor debe estar entre 0.0 y 10.0.
[WARNING] Intento 2 de 3. Calificación 1: 8.5
✓ Calificación validada correctamente.

✓ Todos los datos han sido validados correctamente.
```

## 🚨 **Manejo de Errores**

### **Límite de Intentos:**
- Cada campo permite **máximo 3 intentos**
- Si se agotan los intentos, se **cancela la operación**
- El usuario recibe **retroalimentación clara**

### **Tipos de Error:**
- 🔴 **Error crítico**: Cancela la operación
- 🟡 **Advertencia**: Permite reintento
- 🔵 **Información**: Guía al usuario

### **Prevención de Duplicados:**
- La **matrícula se valida** contra la lista existente
- Se **previenen registros duplicados**
- **Mensaje específico** para duplicados

## [TARGET] **Beneficios de la Validación**

### **Para el Usuario:**
- [OK] **Retroalimentación inmediata** sobre errores
- [OK] **Guías claras** de formato esperado
- [OK] **Múltiples oportunidades** para corregir
- [OK] **Confirmación visual** de datos correctos

### **Para el Sistema:**
- [SHIELD] **Integridad de datos** garantizada
- [SHIELD] **Prevención de errores** de sistema
- [SHIELD] **Consistencia** en formatos
- [SHIELD] **Prevención de duplicados**

### **Para el Administrador:**
- [DATA] **Datos confiables** para análisis
- [DATA] **Reportes precisos**
- [DATA] **Búsquedas efectivas**
- [DATA] **Mantenimiento simplificado**

## [TIP] **Ejemplos de Casos de Uso**

### **Caso 1: Estudiante Nuevo**
```
Nombre: "María José Fernández"     [OK] Válido
Edad: 19                           [OK] Válido
Matrícula: "2025060001"           [OK] Válido (no existe)
Calificaciones: 8.5, 9.0, 7.5, 8.0, 9.5  [OK] Todas válidas
Resultado: [OK] Estudiante agregado exitosamente
```

### **Caso 2: Datos Inválidos**
```
Nombre: "Ana123"                   ❌ Contiene números
Edad: 250                          ❌ Fuera de rango
Matrícula: "ABC123"               ❌ Contiene letras
Calificaciones: -5, 15            ❌ Fuera de rango
Resultado: ❌ Operación cancelada tras 3 intentos
```

### **Caso 3: Matrícula Duplicada**
```
Matrícula: "2024060001"           ❌ Ya existe en el sistema
Mensaje: "❌ Error: Ya existe un estudiante con esa matrícula."
Resultado: ❌ Se solicita nueva matrícula
```

## 🔄 **Edición Mejorada**

### **Características:**
- 🔍 **Muestra valores actuales** antes de cambiar
- [NEXT] **Opción de mantener** valores existentes
- [OK] **Validación individual** de cada campo
- 🔄 **Confirmación final** antes de guardar
- ❌ **Opción de cancelar** cambios

### **Flujo de Edición:**
```
=== Edición de Datos ===
Nota: Presione Enter para mantener el valor actual

Nombre actual: Ana García
Nuevo nombre (Enter para mantener): [Enter]
✓ Nombre mantenido.

Edad actual: 20
¿Desea cambiar la edad? (s/n): s
Nueva edad (15-100): 21
✓ Edad actualizada.

=== Resumen de Cambios ===
[Muestra datos actualizados]
¿Confirma los cambios? (s/n): s
✓ Estudiante actualizado exitosamente.
```

## [FOLDER] **Archivos Actualizados**

- [OK] `estudiante.h` - Prototipos de validación
- [OK] `estudiante.c` - Implementación completa
- [OK] `main.c` - Integración en el menú

**El sistema ahora es robusto, seguro y fácil de usar con validaciones completas.**
