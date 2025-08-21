# Buenas practicas para desarrollo

## Google C++ Style Guide
La Guía de Estilo de C++ de Google es un conjunto de reglas estrictas que definen cómo debe formatearse el código para lograr un aspecto homogéneo en proyectos grandes y colaborativos.

### Identación

Se utiliza una **identación de 2 espacios** por nivel. Además, se deben dejar **espacios alrededor de operadores** y después de comas para mejorar la legibilidad.
```
int CalcularTotal(int a, int b) {
  return a + b * 2;
} // Correcto (espacios alrededor de operadores y después de comas)
```
### Longitud de las líneas de código

Las líneas de código deben limitarse a **80 caracteres** como máximo.  
Si una línea supera este límite, se debe aplicar un **ajuste de línea (line-wrapping)** en puntos lógicos del código, como después de operadores, comas o concatenaciones.
```
#include <string>

std::string GetMessage() {
  return "Esta es una cadena de texto muy larga que se ha dividido en dos líneas para "
         "cumplir con el límite de 100 caracteres por línea.";
}
```
### Uso de llaves

Las llaves se colocan en la **misma línea que la declaración del bloque** (estilo K&R o llaves egipcias).  
Incluso para bloques de una sola línea, **se recomienda usar llaves** para mayor claridad y evitar errores.
```
#include <iostream>

void CheckValue(int value) {
  if (value > 0) {
    std::cout << "El valor es positivo.\n";
  } else {
    std::cout << "El valor es cero o negativo.\n";
  }
}
```
Ya que en C++ se usan **clases, structs y namespaces**, también conviene aplicar la misma regla de llaves.

### Declaración y diseño de funciones

- **Responsabilidad única:** una función debe hacer una sola cosa bien.

- **Nombres claros:** verbos en **`camelCase`**, **`PascalCase`** o **`snake_case`** consistente con tu código base.

Ejemplo **`PascalCase`** : Todas las palabras inician con mayúscula, incluido el inicio. Muy usado en C# o para nombres de clases en C++.
```
#include <iostream>

int CalcularAreaCuadrado(int Lado) {
  return Lado * Lado;
}

int main() {
  int Lado = 5;
  std::cout << "Área (PascalCase): " << CalcularAreaCuadrado(Lado) << std::endl;
  return 0;
}
```
Ejemplo **`camelCase`** : Primera palabra en minúscula, las siguientes en mayúscula inicial. Ejemplo típico en Java/JavaScript, pero también usado en C++.
```
#include <iostream>

int calcularAreaCuadrado(int lado) {
  return lado * lado;
}

int main() {
  int lado = 5;
  std::cout << "Área (camelCase): " << calcularAreaCuadrado(lado) << std::endl;
  return 0;
}
```
Ejemplo **`snake_case`** : Todas en minúsculas y separadas con guiones bajos `_`. Muy común en C y Python.
```
#include <iostream>

int calcular_area_cuadrado(int lado) {
  return lado * lado;
}

int main() {
  int lado = 5;
  std::cout << "Área (snake_case): " << calcular_area_cuadrado(lado) << std::endl;
  return 0;
}
```

- **Const-correctness:** marca parámetros y métodos `const` cuando no modifiquen estado.

- **Pasa por referencia:** los pequeños tipos triviales por **valor** (`int`, `double`,`char`,`string`,`bool`).

- **Validación**: valida precondiciones al inicio para evitar errorres durante el proceso de la ejecución.

### Variables y estilo

-   **Inicializa siempre** (brace-initialization).
    
-   **`auto` con criterio**: úsalo cuando el tipo es obvio del lado derecho o es verboso (iteradores); evita ocultar tipos no triviales.
    
-   **`const` por defecto**: variables que no cambian o no se modificaran nunca → `const`.

- **Ámbito mínimo**: declara lo más cerca del uso. Evita declarar variables que no se usaran durante el proceso de ejecución.
-   **Nombres descriptivos**: evita abreviaturas crípticas; unidades en el nombre si aplica (e.g., `int X`→`int totalAmount`).

### Organización de código y headers

-   **Regla de oro**: declara en `.hpp`/`.h`, define en `.cc`.

### Documentación de archivos
Cada archivo `.hpp` o `.cc` debe empezar con un bloque de cabecera que incluya:

-   **Nombre del archivo**
    
-   **Descripción breve de su propósito**
    
-   **Autor(es)**
    
-   **Fecha de creación / modificación**
    
-   (Opcional) **Licencia** si aplica

Ejemplo:
```
/**
 * @file math_utils.hpp
 * @brief Funciones matemáticas auxiliares para cálculos básicos.
 *
 * Contiene funciones para sumar, restar y calcular áreas de figuras simples.
 *
 * @author Cristofer
 * @date 2025-08-15
 */
```
### Documentación de funciones

Usar un formato estandarizado (ej. **Doxygen**) para que las herramientas puedan generar documentación automáticamente.

Cada función debe incluir:

-   **Descripción breve** de lo que hace
    
-   **Parámetros** (`@param`)
    
-   **Valor de retorno** (`@return`)
    
-   **Excepciones lanzadas** (`@throw`) si aplica
    
-   **Ejemplo de uso** (opcional, pero útil)
    
Ejemplo:
```
/**
 * @brief Calcula el área de un cuadrado.
 *
 * Recibe la longitud de un lado y devuelve el área correspondiente.
 *
 * @param lado Longitud de un lado del cuadrado (debe ser mayor que 0).
 * @return Área del cuadrado (lado * lado).
 *
 * @throw std::invalid_argument si lado <= 0.
 *
 * @example
 * int a = calcularAreaCuadrado(5); // devuelve 25
 */
int CalcularAreaCuadrado(int lado){
};
```

### Referencias
Esta guía de buenas prácticas en C++ está basada en los siguientes recursos:

- [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)  
- [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines) 

## Guía para escribir buenos commits

### 1. Usa el verbo imperativo (`Añadir`,  `Cambiar`,  `Arreglar`,  `Remover`, …)
Aunque el mensaje puede sonar un poco raro el verbo presente es una forma de expresar la acción que se realiza en el commit. Por ejemplo, `Añadir` significa que se añade un nuevo archivo, `Cambiar` significa que se modifica un archivo existente y `Arreglar` significa que se arregla un bug.

![enter image description here](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/refs/heads/main/PED/Imagenes/good_practices_dev/A.png)

Sé que muchas veces estamos tentados a escribirlo en pasado  _“Añadido…”_,  _“Arreglado…”_  o  _“Removido…”_  pero  **cada commit hay que entenderlo como una instrucción para cambiar el estado del proyecto**. Dicho de otro modo, el verbo presente nos permite saber qué estado queremos que el proyecto se encuentre en el momento de añadir el commit.

Sólo hay que ver también los mensajes de commit que el propio Git nos añade (al hacer merge de una rama usa  `Merge branch`).

### 2. No uses punto final ni puntos suspensivos en tus mensajes
Usar puntuación, más allá de las comas, es innecesario a la hora de crear un buen mensaje de commit. Cada carácter cuenta a la hora de crear un buen mensaje de commit así que no lo desperdicies con puntos innecesarios.
```shell
git commit -m "Add new search feature." # ❌  
git commit -m "Fix a problem with the topbar..." # ❌  
git commit -m "Change the default system color" # ✅
```
¿Por qué? **El primer mensaje de commit es el título del commit.** Y según las reglas de puntuación para títulos, tanto en castellano como en inglés, estos no llevan puntuación final. Sobre los puntos suspensivos… ¡Nuestros commits no deberían tener ningún suspenso! Deben ser una instrucción clara y concisa.

### 3. Usa como máximo 50 carácteres para tu mensaje de commit
Sé corto y conciso. Si tienes mucho que explicar… seguramente es que tu commit hace demasiadas cosas. ¿Puedes separarlo en diferentes commits? Pues hazlo.

Haz que el mensaje sea claro, directo y que realmente refleje los cambios que lleva.
```Shell
git commit -m "Add new search feature and change typography to improve performance" # ❌  
git commit -m "Add new search feature" # ✅  
git commit -m "Change typography to improve performance" # ✅
```
### 4. Usa un prefijo para tus commits para hacerlos más semánticos
Cuando un proyecto crece, es necesario que existan ciertas reglas para que el historial sea legible. Para ello, puedes añadir un prefijo para darle más significado a los commits que realizas. A esto se le llama  _commits semánticos_  y se haría de la siguiente manera:
```shell
<tipo-de-commit>[scope]: <descripcion>
feat: add new search feature
```
Puedes usar los siguientes prefijos
-   **feat**: Una nueva característica para el usuario.
-   **fix**: Arregla un bug que afecta al usuario.
-   **perf**: Cambios que mejoran el rendimiento del sitio.
-   **build**: Cambios en el sistema de build, tareas de despliegue o instalación.
-   **ci**: Cambios en la integración continua.
-   **docs**: Cambios en la documentación.
-   **refactor**: Refactorización del código como cambios de nombre de variables o funciones.
-   **style**: Cambios de formato, tabulaciones, espacios o puntos y coma, etc; no afectan al usuario.
-   **test**: Añade tests o refactoriza uno existente.

En su defecto tambien puedes usar emojis para indicar el tipo de commit que se esta haciendo, por ejemplo usando la herramienta Gitmoji, donde **cada emoji tiene su propia razon de ser**  es decir, no debemos poner el emoji que mejor nos parezca, si no el que este acorde al commit, puedes revisarlo en la siguiente web.
https://gitmoji.dev/

## Guía práctica para mejorar commits, PRs e issues usando IA

Es una guía práctica para mejorar **commits**, **PRs** e **issues** de GitHub usando IA con prompts y ejemplos listos para usar. Estos son ejemplos usando de referencia [Conventional Commits](https://www.conventionalcommits.org/en/v1.0.0/).

### Prompts “multi-uso”

### A) **Generar Commit desde Diff**

 Eres un asistente de control de versiones. Con el diff adjunto, genera un mensaje de commit en **Conventional Commits** (título ≤72 chars + cuerpo con motivación). Solo devuelve el mensaje.  
Diff: `{diff}`

### B) **Reescribir Commit**

Reescribe este mensaje de commit a **Conventional Commits** y mejora claridad técnica. Mantén intención original.  
Mensaje: `{texto}`

### C) **Descripción de PR**

Crea una descripción de PR con secciones: Resumen, Contexto, Cambios clave (bullets), Checklist. Español, conciso, profesional.  
Material: `{resumen + lista de archivos + fragmentos relevantes}`

### D) **Bug Issue**

A partir del reporte, redacta un Issue de bug con Título (≤80), Expected vs Actual, Steps to Reproduce (numerados), Evidencia (bloque), Severidad y Entorno (OS/compilador).  
Reporte: `{texto}`

### E) **Feature/Mejora Issue**

Redacta un Issue de mejora con: Motivación, Propuesta, Alcance, Impacto, Alternativas, Checklist.  
Tema: `{texto}`

---

### Ejemplo de Commit

**Prompt:** Reescribe este mensaje de commit a **Conventional Commits** y mejora claridad técnica. Mantén intención original.
Resumen: `Añadí int sum(int a,int b) en math.cpp y su prototipo en math.h.`

**Ejemplo:**
```
feat(math): agregar función sum de dos enteros.
Se implementa sum(a, b) y se declara en math.h para reutilización.
Cómo probar: compilar con CMake y ejecutar.
```
---
### Ejemplo de PR

**Prompt:** Crea una descripción de PR con secciones: Resumen, Contexto, Cambios clave (bullets), Checklist. Español, conciso, profesional.  
Material: `Resumen: Implementé factorial iterativo y pruebas mínimas.
Archivos: src/math/factorial.cpp, include/math/factorial.h, tests/FactorialTests.cpp
`

**Ejemplo:**
```
Resumen: Añade factorial(unsigned int) iterativo.  
Cambios: nueva función + pruebas de 0,1,5.  
Cómo probar: cmake -S . -B build && cmake --build build && ctest -R FactorialTests
Riesgos: valores grandes pueden desbordar (documentado).
```

---
### Ejemplo de Issue

**Prompt:** Redacta un Issue de mejora con: Motivación, Propuesta, Alcance, Impacto, Alternativas, Checklist.  
Tema: `Crash cuando divisor=0 en divide.cpp (Windows, MSVC).`

**Ejemplo:**
```
Título: Evitar división por cero en divide.cpp  
Expected vs Actual:
-   Expected: retornar error o 0 sin crashear.
-   Actual: crash.
Pasos: 1) Compilar, 2) ejecutar `./divide 10 0`.
Evidencia: Floating point  exception (core dumped).
Severidad: media.
Entorno: Windows 11.
```
