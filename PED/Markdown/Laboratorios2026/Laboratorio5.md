# Guía de laboratorio: Estructuras de Datos No Lineales

## Introducción

Las estructuras de datos no lineales permiten organizar información mediante relaciones jerárquicas o conexiones entre elementos. En esta práctica se estudiarán los árboles binarios de búsqueda y su aplicación mediante los contenedores `std::set` y `std::map` de C++, que facilitan el almacenamiento, la búsqueda y la organización eficiente de datos.

## 1. Estructuras de datos no lineales

Una **estructura de datos no lineal** organiza sus elementos mediante conexiones, en lugar de una secuencia única. Sus componentes se denominan **nodos o vértices**, los cuales almacenan información y establecen relaciones con otros elementos.

Dos ejemplos de estas estructuras son los **árboles** y los **grafos**.

**[IMAGEN 1 — Estructuras no lineales y representación en memoria]**

*Nota de edición — Sustituir por una imagen que incluya:*

- Un árbol y un grafo, señalando que ambos están formados por nodos conectados.
- Un nodo ampliado que muestre cómo se almacena información mediante un `struct`, incluyendo datos y punteros.
- Una representación de memoria donde la variable puntero `raiz`, ubicada en el **stack**, apunta al nodo raíz reservado dinámicamente en el **heap**.
- Los demás nodos del árbol conectados mediante punteros, con direcciones de memoria ilustrativas.
- Referencias visuales a las operaciones de insertar, buscar y eliminar.

*Importante: el puntero `raiz` puede ser una variable local en el stack, pero el nodo al que apunta se encuentra en el heap cuando se reserva mediante `new`. En un grafo no necesariamente existe una raíz.*

### Propiedades

- **Profundidad:** distancia desde la raíz hasta un nodo, medida por el número de aristas.
- **Altura:** longitud del camino más largo desde un nodo hasta una hoja del árbol.

Estas propiedades ayudan a comprender la eficiencia de la búsqueda: mientras más niveles deban recorrerse, mayor puede ser la cantidad de comparaciones necesarias.

*En los grafos también se pueden estudiar distancias respecto a un vértice de referencia, aunque la altura no se define necesariamente de la misma manera que en un árbol.*

## 2. Árbol binario de búsqueda (ABB)

Un **árbol binario de búsqueda (ABB)** es una estructura no lineal donde los valores menores que un nodo se ubican en su subárbol izquierdo y los mayores en el derecho.

Esta organización permite descartar partes del árbol durante la búsqueda, reduciendo la cantidad de comparaciones cuando se encuentra balanceado.

### Ejemplo práctico: agenda de contactos

Consideremos una agenda telefónica que almacena nombres de contactos. La información puede organizarse mediante una estructura lineal o un árbol binario de búsqueda.

**[IMAGEN 2 — Comparación entre una lista y un ABB]**

*Nota de edición — Crear una imagen dividida en dos paneles.*

**Panel izquierdo: lista de contactos**

Mostrar una lista lineal con los contactos en este orden:

Carla → Ana → Mario → Brenda → Luis → Elena → Roberto

- Señalar el recorrido secuencial para buscar a **Roberto**.
- Resaltar los siete elementos revisados.
- Colocar una etiqueta de complejidad: **O(n) — Búsqueda lineal**.

**Panel derecho: árbol binario de búsqueda**

Representar los mismos siete contactos organizados así:

- Raíz: Elena.
- Hijos de Elena: Brenda y Mario.
- Hijos de Brenda: Ana y Carla.
- Hijos de Mario: Luis y Roberto.

La ilustración debe señalar **raíz, padre, hijos, hermanos, hojas y aristas**.

Resaltar el recorrido de búsqueda de Roberto: **Elena → Mario → Roberto**, mostrando tres comparaciones.

Agregar la etiqueta: **O(log n) — Búsqueda en ABB balanceado**.

### Complejidad en la búsqueda y el ordenamiento

En una **lista no ordenada**, la búsqueda puede requerir revisar todos sus elementos, por lo que su complejidad es O(n) en el peor caso.

En un **ABB balanceado**, la búsqueda puede realizarse en O(log n), gracias a que se descartan subárboles en cada comparación. Sin embargo, un ABB desbalanceado puede alcanzar O(n).

Además, un recorrido *inorden* de un ABB permite obtener sus elementos ordenados en O(n), mientras que una lista no ordenada requiere un proceso de ordenamiento adicional.

## 3. Contenedores `std::set` y `std::map` en C++

La Biblioteca Estándar de C++ (STL) ofrece los contenedores `std::set` y `std::map`, que utilizan estructuras de búsqueda balanceadas, comúnmente implementadas mediante un **árbol rojo-negro (Red-Black Tree)**.

Este árbol mantiene su equilibrio mediante reglas de coloración y reorganización de nodos, permitiendo realizar operaciones de búsqueda, inserción y eliminación en **O(log n)**.

Estos contenedores permiten trabajar con estructuras ordenadas sin necesidad de implementar manualmente el árbol ni sus mecanismos de balanceo.

### Comparación entre `std::set` y `std::map`

**[IMAGEN 3 — Propiedades de SET vs. MAP]**

*Nota de edición — Imagen comparativa con dos árboles, utilizando el contexto de una agenda telefónica.*

**Panel izquierdo: `std::set`**

Representar un árbol que almacene números telefónicos como elementos únicos, por ejemplo:

- 7100-1000
- 7200-2000
- 7300-3000

Señalar visualmente estas propiedades:

- Elementos únicos.
- Orden automático ascendente.
- Elementos inmutables dentro del contenedor.

**Panel derecho: `std::map`**

Representar un árbol con números de teléfono como claves y datos de los contactos como valores:

- 7100-1000 → Ana López
- 7200-2000 → Roberto Pérez
- 7300-3000 → Ana Martínez

Señalar visualmente estas propiedades:

- Almacenamiento mediante **clave–valor**.
- Claves únicas; los valores pueden repetirse.
- Orden automático por clave.
- Valores modificables.

**Debajo de ambos árboles:** indicar que utilizan estructuras balanceadas y permiten operaciones de búsqueda, inserción y eliminación en O(log n).

### Métodos básicos

| Método | Funcionalidad |
|---|---|
| `insert()` | Inserta un elemento nuevo. |
| `find()` | Busca un elemento o una clave. |
| `erase()` | Elimina un elemento o una clave. |
| `size()` | Obtiene la cantidad de elementos. |
| `begin()` / `end()` | Permiten recorrer el contenedor mediante iteradores. |
| `clear()` | Elimina todos los elementos. |

En `std::set`, las operaciones utilizan el valor almacenado; en `std::map`, utilizan principalmente la clave.

## 4. Ejemplo


## 5. Enlaces adicionales

- [Visualgo — Binary Search Tree](https://visualgo.net/en/bst): visualización interactiva de las operaciones sobre árboles de búsqueda.
- [Red-Black Tree Visualization — University of San Francisco](https://www.cs.usfca.edu/~galles/visualization/RedBlack.html): permite observar inserciones, eliminaciones y balanceo.
- [GeeksforGeeks — Set en C++](https://www.geeksforgeeks.org/set-in-cpp-stl/): introducción práctica a `std::set`.
- [Programiz — C++ Map](https://www.programiz.com/cpp-programming/map): explicación y ejemplos básicos del uso de `std::map`.
