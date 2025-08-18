# Buenas practicas para desarrollo

[# C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines)

[Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)

[W3schools | C++](https://www.w3schools.com/cpp/default.asp)

## Google C++ Style Guide
La Guía de Estilo de C++ de Google es un conjunto de reglas estrictas que definen cómo debe formatearse el código para lograr un aspecto homogéneo en proyectos grandes y colaborativos.

### Identación

Se utiliza una **identación de 2 espacios** por nivel. Además, se deben dejar **espacios alrededor de operadores** y después de comas para mejorar la legibilidad.
```
int calcularTotal(int a, int b) {
  return a + b * 2;
} // Correcto (espacios alrededor de operadores y después de comas)
```
### Longitud de las líneas de código

Las líneas de código deben limitarse a **100 caracteres** como máximo.  
Si una línea supera este límite, se debe aplicar un **ajuste de línea (line-wrapping)** en puntos lógicos del código, como después de operadores, comas o concatenaciones.
```
#include <string>

std::string getMessage() {
  return "Esta es una cadena de texto muy larga que se ha dividido en dos líneas para "
         "cumplir con el límite de 100 caracteres por línea.";
}
```
### Uso de llaves

Las llaves se colocan en la **misma línea que la declaración del bloque** (estilo K&R o llaves egipcias).  
Incluso para bloques de una sola línea, **se recomienda usar llaves** para mayor claridad y evitar errores.
```
#include <iostream>

void checkValue(int value) {
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

- **Nombres claros:** verbos en `camelCase`, `PascalCase` o `snake_case` consistente con tu código base.

Ejemplo **`camelCase`** : Primera palabra en minúscula, las siguientes en mayúscula inicial.
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
Ejemplo **`PascalCase`** : Todas las palabras inician con mayúscula, incluido el inicio.
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
Ejemplo **`Snake_case`** : Todas en minúsculas y separadas con guiones bajos `_`.
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

-   **Regla de oro**: declara en `.hpp`/`.h`, define en `.cpp`.

### Documentación de archivos
Cada archivo `.hpp` o `.cpp` debe empezar con un bloque de cabecera que incluya:

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
int calcularAreaCuadrado(int lado){
};
```

---
---
---
---
# Esto IA NO :P

### Estructuras dinámicas (memoria)

En C++, `struct` y `class` son casi lo mismo:

La diferencia principal es que en `struct` los miembros son **públicos por defecto**, mientras que en `class` son **privados por defecto**.
    
En la práctica, `struct` suele usarse más para **agrupación de datos simples (POD: Plain Old Data)** y `class` para **abstracciones con lógica y encapsulación**.
-  **Nombres y estilo:** Usa **PascalCase** o **CamelCase** consistente para nombres. Evita nombres genéricos como `Data`, `Info`, `Values`. Ponle nombres que indiquen claramente qué representa.

-   **RAII primero**: evita `new/delete` manuales. Usa **contenedores STL** y **smart pointers**.
--  **RAII** significa **Resource Acquisition Is Initialization** (“la adquisición del recurso es inicialización”) y es un principio central de C++.
    
-   Para arrays dinámicos, **prefiere** `std::vector`, `std::string`, `std::array` (tamaño fijo).
    
-   Evita fugas y dobles `delete` con **smart pointers** y **contenedores**.
```
struct UserProfile {
    std::string name;
    int age;
    std::string email;
};
```
-   Puedes añadir métodos, pero que sean **ligeros y relacionados directamente con los datos**.
    
```
struct Rectangle {
    double width;
    double height;
    double area() const { return width * height; }
};
```
-   Si la lógica empieza a crecer demasiado → usa `class`.

Ejemplo sin RAII (mala práctica con `new/delete`)
```
void foo() {
    int* arr = new int[100];  // reservar memoria
    // ... usar arr ...
    delete[] arr;             // liberar memoria (si no lo haces -> fuga)
}
```
Ejemplo con RAII (buena práctica)
```
#include <vector>
#include <memory>

void foo() {
    std::vector<int> arr(100); // RAII: vector libera solo
    // ... usar arr ...
} // al salir del scope, arr libera la memoria automáticamente
```
Así garantizas que **el compilador gestione la liberación** automáticamente cuando el objeto sale de scope, incluso si hay errores o excepciones.

### Casteo de datos

-    **Evita el cast estilo C** `(T)x`.
    
-   **Prefiere**: `static_cast<T>(expr)` para conversiones conocidas y seguras en compile-time.

Ejemplo de conversión numérica (Mala práctica)
```
int x = 42;
double y = (double)x;   // C-cast
```
Problemas:

-   Poco claro qué tipo de cast es (puede ser reinterpret, const, etc.).
    
-   Difícil de detectar errores con warnings.

Ejemplo de conversión numérica (Buena práctica) 
```
int x = 42;
double y = static_cast<double>(x); // cast explícito y seguro
```
### Punteros y referencias

-   **Prefiere referencias** cuando el argumento debe existir; punteros cuando puede ser nulo (o para semántica de “opcional” en código legacy).
    
-   Usa `nullptr` (no `NULL`).

### Pilas y Colas

-   Usa **`std::stack<T, Container>`** y **`std::queue<T, Container>`** como adaptadores.
- Para colas con prioridad: `std::priority_queue`.
```
std::stack<int> st;
st.push(10);
st.pop();
std::queue<std::string> q;
q.push("msg");
q.front();
q.pop();
```

### Bucles: for, while, range-based
-   **Prefiere** bucle **range-based** y **algoritmos STL** (`std::for_each`, `std::transform`, `std::accumulate`) por legibilidad y seguridad.
    
-   Evita índices si no son necesarios.

### Cómo evitar bucles infinitos

-   **Condición de salida clara**: debe depender de variables que **cambian** dentro del bucle.
    
-   **Progreso garantizado**: introduce una métrica que decrece/avanza (ej., tamaño restante, contador).
    
-   **Límites/failsafes**: agrega un **contador máximo** de iteraciones o un **deadline** de tiempo para tareas potencialmente no deterministas (I/O, red).
- **Time-outs** con `std::chrono`.
```
int attempts = 0;
const int kMaxAttempts = 1000;
while (!done()) {
    step();
    if (++attempts > kMaxAttempts) {
        throw std::runtime_error("Exceeded max attempts");
    }
}
```
```
using namespace std::chrono;
auto deadline = steady_clock::now() + 500ms;
while (!ready()) {
    if (steady_clock::now() >= deadline) break; // salir con timeout
    std::this_thread::sleep_for(1ms);           // cede CPU si es espera activa
}
```

## Guía para escribir buenos commits

### 1. Usa el verbo imperativo (`Añadir`,  `Cambiar`,  `Arreglar`,  `Remover`, …)
Aunque el mensaje puede sonar un poco raro el verbo presente es una forma de expresar la acción que se realiza en el commit. Por ejemplo, `Añadir` significa que se añade un nuevo archivo, `Cambiar` significa que se modifica un archivo existente y `Arreglar` significa que se arregla un bug.

![enter image description here](https://imgs.xkcd.com/comics/git_commit_2x.png)

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

 Eres un asistente de control de versiones. Con el diff adjunto, genera un mensaje de commit en **Conventional Commits** (título ≤72 chars + cuerpo con motivación, riesgos y pruebas). Solo devuelve el mensaje.  
Diff: `{diff}`

### B) **Reescribir Commit**

Reescribe este mensaje de commit a **Conventional Commits** y mejora claridad técnica. Mantén intención original, agrega “Pruebas” y “Riesgos”.  
Mensaje: `{texto}`

### C) **Descripción de PR**

Crea una descripción de PR con secciones: Resumen, Contexto, Cambios clave (bullets), Riesgos/rollback, Cómo probar (pasos), Checklist. Español, conciso, profesional.  
Material: `{resumen + lista de archivos + fragmentos relevantes}`

### D) **Bug Issue**

A partir del reporte, redacta un Issue de bug con Título (≤80), Expected vs Actual, Steps to Reproduce (numerados), Evidencia (bloque), Severidad y Entorno (OS/compilador).  
Reporte: `{texto}`

### E) **Feature/Mejora Issue**

Redacta un Issue de mejora con: Motivación, Propuesta, Alcance, Impacto, Alternativas, Checklist.  
Tema: `{texto}`

---

### Ejemplo de Commit desde un resumen breve

**Prompt:** Convierte este resumen en un mensaje de commit estilo Conventional Commits (título imperativo ≤72 chars + cuerpo con motivación, riesgos y pruebas):  
Resumen: “Reemplazar punteros crudos por std::unique_ptr en clase FileReader y ajustar constructor y destructor.”

**Ejemplo de salida (C++ – RAII):**
```
refactor(io): usar std::unique_ptr en FileReader

Se reemplazan punteros crudos por std::unique_ptr para asegurar RAII y
evitar fugas de memoria. Se simplifica el destructor y el manejo de
errores al abrir archivos.

Riesgos: cambios en ciclo de vida del recurso; revisar ownership.
Pruebas: ejecución de ejemplo `./bin/read_sample` y tests unitarios.
```
---
### Ejemplo de PR de algoritmo básico (p. ej., Bubble Sort → std::sort)

**Prompt:** Redacta una descripción de PR con el formato anterior para: “Reemplazar Bubble Sort casero por `std::sort` en `sort_utils.cpp`; añadir benchmark simple”.

**Ejemplo (resumen de salida):**

-   **Resumen**: Sustituye implementación O(n²) por `std::sort` (O(n log n)).
    
-   **Cambios clave**: `sort_utils.cpp` actualizado, benchmark simple con `std::chrono`, pruebas de orden estable.
    
-   **Riesgos**: comportamiento de orden parcial; rollback: restaurar `sort_utils.cpp`.
    
-   **Cómo probar**: compilar, ejecutar `./bench/sort_bench`, validar pruebas.

---
### Ejemplo de Issue de mejora (performance/limpieza)

**Prompt:** Genera un Issue de mejora con secciones: Motivación, Propuesta, Alcance, Impacto, Alternativas, Checklist.  
Tema: “Reservar capacidad en `std::vector` en parser para reducir realocaciones”.

**Ejemplo (resumen):**

-   **Motivación**: alta latencia en archivos grandes por realocaciones.
    
-   **Propuesta**: `result.reserve(estimated)` antes de `push_back`.
    
-   **Impacto**: mejor throughput; sin cambios funcionales.
    
-   **Checklist**: [ ] benchmark, [ ] pruebas, [ ] docs.
