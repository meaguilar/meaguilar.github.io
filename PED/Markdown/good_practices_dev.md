# Buenas practicas para desarrollo


[# C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines)

[Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)

[W3schools | C++](https://www.w3schools.com/cpp/default.asp)

### 1) Declaración y diseño de funciones

- **Responsabilidad única:** una función debe hacer una sola cosa bien.

- **Nombres claros:** verbos en `camelCase`, `PascalCase` o `snake_case` consistente con tu código base.

- **Const-correctness:** marca parámetros y métodos `const` cuando no modifiquen estado.
- **Pasa por referencia:** los pequeños tipos triviales por **valor** (`int`, `double`,`char`,`string`,`bool`, etc.).
- **Validación**: valida precondiciones al inicio para evitar errorres durante el proceso de la función.

### 2) Variables y estilo

-   **Inicializa siempre** (brace-initialization).
    
-   **`auto` con criterio**: úsalo cuando el tipo es obvio del lado derecho o es verboso (iteradores); evita ocultar tipos no triviales.
    
-   **`const` por defecto**: variables que no cambian o no se modificaran nunca → `const`.

- **Ámbito mínimo**: declara lo más cerca del uso. Evita declarar variables que no se usaran durante el proceso de ejecución.
-   **Nombres descriptivos**: evita abreviaturas crípticas; unidades en el nombre si aplica (e.g., `int X`→`int totalAmount`).

### 3) Estructuras dinámicas (memoria)

En C++, `struct` y `class` son casi lo mismo:

-   La diferencia principal es que en `struct` los miembros son **públicos por defecto**, mientras que en `class` son **privados por defecto**.
    
-   En la práctica, `struct` suele usarse más para **agrupación de datos simples (POD: Plain Old Data)** y `class` para **abstracciones con lógica y encapsulación**.
-  **Nombres y estilo:** Usa **PascalCase** o **CamelCase** consistente para nombres. Evita nombres genéricos como `Data`, `Info`, `Values`. Ponle nombres que indiquen claramente qué representa.

-   **RAII primero**: evita `new/delete` manuales. Usa **contenedores STL** y **smart pointers**.
--  **RAII** significa **Resource Acquisition Is Initialization** (“la adquisición del recurso es inicialización”) y es un principio central de C++.
    
-   Para arrays dinámicos, **prefiere** `std::vector`, `std::string`, `std::array` (tamaño fijo).
    
-   Evita fugas y dobles `delete` con smart pointers y contenedores.
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

#### Ejemplo sin RAII (mala práctica con `new/delete`)
```
void foo() {
    int* arr = new int[100];  // reservar memoria
    // ... usar arr ...
    delete[] arr;             // liberar memoria (si no lo haces -> fuga)
}
```
#### Ejemplo con RAII (buena práctica)
```
#include <vector>
#include <memory>

void foo() {
    std::vector<int> arr(100); // RAII: vector libera solo
    // ... usar arr ...
} // al salir del scope, arr libera la memoria automáticamente
```
Así garantizas que **el compilador gestione la liberación** automáticamente cuando el objeto sale de scope, incluso si hay errores o excepciones.

### 4) Casteo de datos

-    **Evita el cast estilo C** `(T)x`.
    
-   **Prefiere**: `static_cast<T>(expr)` para conversiones conocidas y seguras en compile-time.

### Conversión numérica
### ❌ Mala práctica
```
int x = 42;
double y = (double)x;   // C-cast
```
Problemas:

-   Poco claro qué tipo de cast es (puede ser reinterpret, const, etc.).
    
-   Difícil de detectar errores con warnings.

### ✅ Buena práctica
```
int x = 42;
double y = static_cast<double>(x); // cast explícito y seguro
```
### 5) Punteros y referencias

-   **Prefiere referencias** cuando el argumento debe existir; punteros cuando puede ser nulo (o para semántica de “opcional” en código legacy).
    
-   Usa `nullptr` (no `NULL`).

### 6) Pilas y Colas

-   Usa **`std::stack<T, Container>`** y **`std::queue<T, Container>`** como adaptadores.
- Para colas con prioridad: `std::priority_queue`.
```
std::stack<int> st;
st.push(10); st.pop();
std::queue<std::string> q;
q.push("msg"); q.front(); q.pop();
```

### 7) Bucles: for, while, range-based
-   **Prefiere** bucle **range-based** y **algoritmos STL** (`std::for_each`, `std::transform`, `std::accumulate`) por legibilidad y seguridad.
    
-   Evita índices si no son necesarios.

### 8) Cómo evitar bucles infinitos

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
### 10) Organización de código y headers

-   **Regla de oro**: declara en `.hpp`/`.h`, define en `.cpp`.


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
