# StudentManager v3.1 - Versión Final Optimizada

**Fecha de última revisión:** 25/06/2025  
**Autor:** Iquí-Balam López Hernández

## Descripción
Este programa gestiona una lista de estudiantes con **validaciones**, **interfaz** y **funcionalidades avanzadas**.

## Características Principales v3.1

### **Sistema de Validación:**
- **Validación de nombres** - Solo letras, espacios y puntos (máximo 49 caracteres)
- **Validación de edad** - Rango 0-100 años con verificación numérica
- **Validación de matrícula** - 10 dígitos únicos, evitando duplicados
- **Validación de calificaciones** - Rango 0.0-10.0 con decimales
- **Sistema de intentos** - 3 oportunidades por campo con mensajes claros
- **Retroalimentación inmediata** - Estados [EXITO], [ERROR], [AVISO]

### **Interfaz Optimizada:**
- **Compatible** - Sin caracteres especiales problemáticos
- **Colores informativos** - Verde (éxito), Rojo (error), Azul (info), Amarillo (aviso)
- **Navegación fácil** - Menú numerado claro con 11 funciones
- **Limpieza automática** - Pantalla organizada y buffer controlado

### **Funcionalidades Avanzadas:**
- **CRUD completo** - Create, Read, Update, Delete de estudiantes
- **Búsqueda inteligente** - Por matrícula con validación de formato
- **Estadísticas detalladas** - Promedios, mejor/peor estudiante, conteos
- **Ordenamiento múltiple** - Por nombre, promedio (asc/desc), matrícula
- **Persistencia** - Guardar/cargar con diálogos de Windows

## Especificaciones Técnicas Mantenidas

### **Estructura de Datos:**
```c
typedef struct {
    char nombre[50];
    int edad;
    char matricula[15];
    float calificaciones[5];
    float promedio;
} Estudiante;
```

### **Funciones Requeridas Implementadas:**
- `void agregarEstudiante(Estudiante *e);` - Con validaciones completas
- `void calcularPromedio(Estudiante *e);` - Automático tras ingreso/edición  
- `void mostrarEstudiante(Estudiante e);` - Formato limpio y colorido
- `void guardarArchivo(Estudiante *lista, int n);` - Con diálogos Windows
- `int cargarArchivo(Estudiante *lista);` - Con verificación de errores

## Lenguaje y Requisitos
- **Lenguaje:** C con extensiones de Windows API
- **Compilador:** MinGW/GCC compatible con Windows API
- **Dependencias:** Biblioteca estándar de C + Windows API (comdlg32)
- **Sistema:** Windows (consola y diálogos nativos)

## Estructura del Proyecto

```
StudentManager/
├── main.c                    # Archivo principal con menú y lógica
├── estudiante.h              # Definiciones y prototipos
├── estudiante.c              # Implementación de funciones de estudiante
├── archivo.h                 # Prototipos de manejo de archivos
├── archivo.c                 # Implementación de persistencia
├── StudentManager.exe        # Ejecutable final optimizado
├── estudiantes.txt           # Datos de prueba
├── MANUAL.md                 # Manual de usuario
├── versiones_anteriores/     # Ejecutables de versiones previas
│   ├── StudentManager.exe            # v1.0 - Versión original
│   ├── StudentManager_Mejorado.exe   # v2.0 - Con marcos decorativos
│   ├── StudentManager_Simple.exe     # v2.1 - Interfaz simplificada
│   └── StudentManager_Validado.exe   # v3.0 - Con validaciones
└── documentacion/            # Documentación técnica detallada
    ├── COMPARACION_INTERFACES.md
    ├── DOCUMENTACION_VALIDACIONES.md
    ├── GUIA_PRUEBAS_VALIDACION.md
    ├── MANUAL_USUARIO_v2.md
    └── REPORTE_BUG_SOLUCION.md
```

## Compilación

### **Comando de Compilación:**
```bash
gcc -o StudentManager.exe main.c estudiante.c archivo.c -std=c99 -lcomdlg32
```

### **Requisitos del Sistema:**
- Windows 7/8/10/11
- MinGW o compilador GCC compatible
- Soporte para Windows API
- Terminal con soporte de colores ANSI (recomendado)

## Uso del Programa

### **Menú Principal:**
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

### **Funciones Detalladas:**

1. **Agregar estudiante** - Ingreso guiado con validaciones automáticas
2. **Mostrar todos** - Lista completa con formato organizado
3. **Mostrar aprobados** - Filtro de estudiantes con promedio >= 6.0
4. **Mostrar reprobados** - Filtro de estudiantes con promedio < 6.0
5. **Guardar en archivo** - Exportar datos con diálogo de selección
6. **Cargar desde archivo** - Importar datos con verificación
7. **Buscar por matrícula** - Localización rápida de estudiante específico
8. **Editar estudiante** - Modificación selectiva de campos existentes
9. **Eliminar estudiante** - Eliminación segura con confirmación
10. **Ordenar lista** - 4 formas de ordenamiento disponibles
11. **Ver estadísticas** - Análisis completo de rendimiento grupal

## Características Técnicas Avanzadas

### **Validaciones Implementadas:**
- **Nombres:** Máximo 49 caracteres, solo letras/espacios/puntos
- **Edades:** Rango 0-100 años, verificación numérica
- **Matrículas:** Exactamente 10 dígitos, unicidad garantizada
- **Calificaciones:** Rango 0.0-10.0, soporte para decimales

### **Sistema de Mensajes:**
- **[EXITO]** - Operaciones completadas satisfactoriamente
- **[ERROR]** - Errores de validación o sistema
- **[AVISO]** - Advertencias e información importante

### **Compatibilidad:**
- Funciona en cualquier terminal Windows
- Sin dependencias de caracteres especiales
- Colores opcionales (degrada elegantemente)
- Archivos de texto plano estándar

## Limitaciones y Especificaciones

- **Capacidad máxima:** 100 estudiantes por sesión
- **Calificaciones por estudiante:** 5 (fijo)
- **Formato de archivo:** .txt con separadores ; y ,
- **Plataforma:** Exclusivamente Windows (por uso de Windows API)
- **Codificación:** UTF-8

## Mejoras Implementadas v3.1

- **Interfaz compatible** sin caracteres problemáticos
- **Organización del proyecto** con carpetas separadas por tipo
- **Documentación** con manual de usuario
- **Corrección de bugs críticos** para estabilidad total
- **Optimización de rendimiento**
- **Validaciones** para evitar errores comunes
- **Sistema de archivos** con manejo de errores

---
