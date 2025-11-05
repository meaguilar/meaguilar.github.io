# Estructuras de Datos: Árboles

En este laboratorio estudiaremos los **árboles**, una estructura de datos que permite organizar y manipular información de forma jerárquica que es fundamental en la organización y manipulación de datos en muchos campos de la informática.

## ¿Qué es un Árbol?

A diferencia de estructuras como pilas y colas, que organizan los datos de forma lineal, un **árbol** es una estructura de datos jerárquica compuesta por nodos conectados entre sí mediante aristas. A diferencia de las estructuras lineales (como pilas y colas), un árbol organiza los datos de manera no lineal, permitiendo una estructura de ramificación.

El nodo principal del árbol es llamado **raíz**, y cada nodo puede tener múltiples **hijos**. Un nodo sin hijos es conocido como **hoja**.

### Características importantes de los árboles:

-   **Raíz**: El nodo en la parte superior del árbol.
-   **Hojas**: Nodos sin hijos.
-   **Padre**: Un nodo que tiene uno o más hijos.
-   **Hijos**: Nodos que descienden directamente de otro nodo.
-   **Profundidad**: La distancia de un nodo a la raíz.
-   **Altura**: La longitud del camino más largo desde un nodo hasta una hoja.

![tree-nodes-types](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/refs/heads/main/PED/Imagenes/CP7/tree-nodes-types.png)

## Tipos de Árboles
1.  **Árbol General**: No hay restricciones en el número de hijos de un nodo.
2.  **Árbol Binario**: Cada nodo tiene como máximo dos hijos.
3.  **Árbol Binario de Búsqueda (BST)**: En un árbol binario de búsqueda, los valores del subárbol izquierdo son menores que los del nodo, y los del subárbol derecho son mayores.
4.  **Árbol AVL**: Árbol binario de búsqueda balanceado donde la diferencia de altura entre subárboles de cualquier nodo no puede ser mayor que 1.

- En este laboratorio nos centraremos más en estudiar los **Árboles binarios**.

## ¿Qué es un Árbol Binario?
Un **árbol binario** es una estructura de datos en la que cada nodo tiene como máximo dos hijos, llamados **hijo izquierdo** e **hijo derecho**. Los árboles binarios son muy eficientes para realizar operaciones como la búsqueda, inserción y eliminación de datos.

Un **árbol binario perfecto** es aquel en el que todos los nodos internos tienen exactamente dos hijos y todas las hojas se encuentran al mismo nivel. Por el contrario, un **árbol binario no perfecto** es aquel en el que no todos los nodos tienen dos hijos o las hojas no están al mismo nivel, lo que genera una estructura menos simétrica.

![balance-tree](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/refs/heads/main/PED/Imagenes/CP7/balance-tree.png)

## Representación de un Árbol binario en C++


### Definición de un nodo
En C++, cada nodo de un árbol binario se puede definir mediante una estructura que contiene los datos a guardar y dos punteros, uno hacia el hijo izquierdo y otro hacia el hijo derecho.

```c++
#include <iostream>
#include <string>

struct Datos {
    int id;         
    std::string nombre; 
};

struct Nodo {
    Datos dato;         // Valor almacenado
    Nodo* izquierda;    // Puntero al hijo izquierdo
    Nodo* derecha;      // Puntero al hijo derecho
};
```
## Operaciones Básicas en Árboles Binarios

### 1. Insertar un nodo
Vamos a insertar un nodo en el árbol binario comparando el **id** del campo `Datos`. Si el **id** del nuevo nodo es menor que el nodo actual, lo insertamos en el subárbol izquierdo; si es mayor, en el subárbol derecho.
```c++
Nodo* Insertar(Nodo* raiz, Datos nuevo_dato) {
    if (raiz == nullptr) {
        Nodo* nuevo_nodo = new Nodo();
        nuevo_nodo->dato = nuevo_dato;
        nuevo_nodo->izquierda = nullptr;
        nuevo_nodo->derecha = nullptr;
        return nuevo_nodo;
    }

    if (nuevo_dato.id < raiz->dato.id) {
        raiz->izquierda = Insertar(raiz->izquierda, nuevo_dato);
    } else {
        raiz->derecha = Insertar(raiz->derecha, nuevo_dato);
    }

    return raiz;
};
```
### 2. Buscar un nodo
Para buscar un nodo en el árbol, compararemos el **id** del campo `Datos` para determinar si el nodo se encuentra en el árbol.

```c++
bool Buscar(Nodo* raiz, int id) {
    if (raiz == nullptr) {
        return false;
    }

    if (raiz->dato.id == id) {
        return true;
    }

    if (id < raiz->dato.id) {
        return Buscar(raiz->izquierda, id);
    } else {
        return Buscar(raiz->derecha, id);
    }
};
```
### 3. Recorrer un árbol binario

Los **recorridos de un árbol binario** son formás de visitar todos los nodos del árbol siguiendo un orden específico. Existen tres tipos principales de recorridos: **inorden**, **preorden** y **postorden**. La principal diferencia entre estos recorridos es el momento en que se visita el nodo **padre** en relación con su hijo izquierdo e hijo derecho.

-   **Recorrido Inorden (IPD):** En el recorrido **inorden**, primero se visita el **hijo izquierdo**, luego se **visita el nodo** padre, y finalmente se visita el **hijo derecho**.

```c++
void InOrden(Nodo* raiz) {
    if (raiz != nullptr) {
        InOrden(raiz->izquierda);
        std::cout << "ID: " << raiz->dato.id << ", Nombre: " << raiz->dato.nombre << std::endl;
        InOrden(raiz->derecha);
    }
};
```
![inorder-visualization](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/refs/heads/main/PED/Imagenes/CP7/inorder-visualization.png)

-   **Recorrido Preorden (PID):** En el recorrido **preorden**, primero se **visita el nodo** padre, luego se visita el **hijo izquierdo**, y finalmente se visita el **hijo derecho**.

```c++
void PreOrden(Nodo* raiz) {
    if (raiz != nullptr) {
        std::cout << "ID: " << raiz->dato.id << ", Nombre: " << raiz->dato.nombre << std::endl;
        PreOrden(raiz->izquierda);
        PreOrden(raiz->derecha);
    }
};
```
![preorder-visualization](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/refs/heads/main/PED/Imagenes/CP7/preorder-visualization.png)

-   **Recorrido Postorden (IDP):** En el recorrido **postorden**, primero se visita el **hijo izquierdo**, luego se visita el **hijo derecho**, y finalmente se visita el **nodo padre**. 

```c++
void PostOrden(Nodo* raiz) {
    if (raiz != nullptr) {
        PostOrden(raiz->izquierda);
        PostOrden(raiz->derecha);
        std::cout << "ID: " << raiz->dato.id << ", Nombre: " << raiz->dato.nombre << std::endl;
    }
};
```
![postorder-visualization](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/refs/heads/main/PED/Imagenes/CP7/postorder-visualization.png)

### 4. **Eliminar un Nodo**
La eliminación de un nodo sigue las mismás reglas, pero comparando siempre el **id** del campo `Datos` para encontrar el nodo a eliminar.

```c++
Nodo* EncontrarMin(Nodo* nodo) {
    while (nodo->izquierda != nullptr) {
        nodo = nodo->izquierda;
    }
    return nodo;
}

Nodo* Eliminar(Nodo* raiz, int id) {
    if (raiz == nullptr) {
        return raiz;
    }

    if (id < raiz->dato.id) {
        raiz->izquierda = Eliminar(raiz->izquierda, id);
    } else if (id > raiz->dato.id) {
        raiz->derecha = Eliminar(raiz->derecha, id);
    } else {
        if (raiz->izquierda == nullptr && raiz->derecha == nullptr) {
            delete raiz;
            raiz = nullptr;
        } else if (raiz->izquierda == nullptr) {
            Nodo* temp = raiz;
            raiz = raiz->derecha;
            delete temp;
        } else if (raiz->derecha == nullptr) {
            Nodo* temp = raiz;
            raiz = raiz->izquierda;
            delete temp;
        } else {
            Nodo* temp = EncontrarMin(raiz->derecha);
            raiz->dato = temp->dato;
            raiz->derecha = Eliminar(raiz->derecha, temp->dato.id);
        }
    }
    return raiz;
}
```
### Ejemplo completo de los recorridos y busquedas manuales de árboles binarios

Puedes consultar un ejemplo completo de los recorridos y búsquedas manuales en árboles binarios en el siguiente repositorio: [Repositorio - Árboles manual](https://github.com/UCASV/RecursosExtraPED/blob/main/ArbolesBinarios/ArbolesManual.cc)

## Red-Black Tree
Un **árbol rojo-negro (Red-Black Tree)** es un **árbol binario de búsqueda auto-balanceado** que garantiza operaciones en **O(log n)** para inserción, búsqueda y borrado. Se usa como estructura interna de `std::set` y `std::map`.

![Red Black Tree](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/refs/heads/main/PED/Imagenes/CP7/Red-Black-Tree.png)

### Ideas clave

-   **Orden BST**: para cada nodo, todos los valores del subárbol izquierdo son menores y los del derecho mayores.
-   **Color por nodo**: cada nodo es **rojo** o **negro** (solo un bit extra).
-   **Reglas de balance** (intuitivas):
    1.  La **raíz** es negra.
    2.  Todas las **hojas nulas (NIL)** se consideran negras.
    3.  Un **nodo rojo no puede tener hijo rojo** (no hay dos rojos consecutivos).
    4.  Todo **camino desde un nodo hasta sus hojas NIL tiene el mismo número de nodos negros** (altura negra constante).

Cuando una inserción o eliminación rompe alguna regla, el árbol realiza **rotaciones** (izq./der.) y **recoloraciones** para recuperar el balance.  

**¿Qué ganamos?** Un árbol balanceado siempre, sin necesidad de re-balanceos costosos como en peores casos de un BST normal.


## Librería de Árboles C++

En este laboratorio utilizaremos la librería `std::set` y `std::map`, que implementa un árbol de búsqueda balanceado, comúnmente un **Red-Black Tree**. Esto garantiza que el código sea eficiente en términos de velocidad de ejecución.

![Map vs Set](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/refs/heads/main/PED/Imagenes/CP7/Map-vs-Set.png)

### Propiedades de la librería `std::set` 
-   **Elementos únicos**: Cada valor dentro del conjunto es **único**; si se intenta insertar un elemento duplicado, será ignorado automáticamente.
-   **Orden automático**: Los elementos se almacenan de forma **ordenada ascendentemente** según el operador `<` del tipo de dato (puede personalizarse con un comparador).
-   **Estructura interna balanceada**: Está implementado como un **árbol rojo–negro**, lo que garantiza operaciones eficientes de inserción, búsqueda y eliminación en tiempo **O(log n)**.
-   **Inmutabilidad de elementos**: Los valores almacenados dentro del `set` son **constantes**; no se pueden modificar directamente una vez insertados, ya que esto alteraría el orden del árbol.
-   **Ideal para pruebas de pertenencia**: Es especialmente útil cuando se necesita saber rápidamente si un elemento existe en una colección sin duplicados.

### Propiedades de la librería `std::map`
-   **Clave–Valor**: Cada elemento del mapa almacena un par formado por una **clave única** y un **valor asociado**.
-   **Sin claves duplicadas**: No se pueden repetir las claves; si insertas una clave existente, el valor anterior se reemplaza.
-   **Ordenado automáticamente**: Los elementos se ordenan según la clave, en orden ascendente por defecto (`<`).
-   **Acceso rápido**: Permite acceder, insertar o eliminar elementos en tiempo logarítmico (_O(log n)_), gracias a su implementación como **árbol rojo–negro**.
-   **Modificable por valor**: Es posible cambiar el valor asociado a una clave existente sin afectar el orden del árbol.

### Comparación entre `std::set` y `std::map`

| Característica | `std::set` | `std::map` |
|----------------|-------------|-------------|
| **Tipo de dato almacenado** | Solo almacena **valores únicos** | Almacena **pares (clave, valor)** |
| **Definición** | `std::set<T>` | `std::map<Key, Value>` |
| **Clave** | El **valor mismo** actúa como clave | La **clave** y el **valor** son independientes |
| **Duplicados** | No se permiten valores duplicados | No se permiten **claves** duplicadas (los valores pueden repetirse) |
| **Orden** | Ordenado automáticamente por el valor (`<`) | Ordenado automáticamente por la **clave** (`<`) |
| **Acceso a elementos** | Solo se puede **buscar o recorrer** valores | Se puede **buscar por clave** y **modificar el valor asociado** |
| **Inserción** | `insert(valor)` o `emplace(valor)` | `insert({clave, valor})` o `operator[](clave) = valor` |
| **Modificación de elementos** | No es posible modificar un elemento directamente | El valor puede modificarse mediante la clave |
| **Uso típico** | Verificar existencia, eliminar duplicados, mantener ordenado un conjunto de valores únicos | Crear diccionarios, tablas de correspondencia o contadores clave→valor |
| **Estructura interna** | Árbol binario balanceado (Red-Black Tree) | Árbol binario balanceado (Red-Black Tree) |
| **Complejidad** | Inserción, búsqueda y borrado en **O(log n)** | Inserción, búsqueda y borrado en **O(log n)** |
| **Variantes con duplicados** | `std::multiset` | `std::multimap` |


### Métodos básicos de librería `std::set` y `std::map`

**Métodos de inserción**

- `insert(valor)`: Inserta un elemento en el set (si no existe).
- `insert(clave, valor)`: Inserta un elemento en el map (si no existe).
- `insert(hint, valor)`: Inserta con una posición sugerida (optimiza si el orden es conocido).
- `insert(rango_inicio, rango_fin)`: Inserta un rango de elementos de otro contenedor.

**Métodos de eliminación**
- `erase(valor)`: Elimina el elemento igual a `valor` (si existe).
- `erase(iterador)`: Elimina el elemento apuntado por el iterador.
- `erase(rango_inicio, rango_fin)`: Elimina un rango de elementos.
- `clear()`: Borra todos los elementos del set.

**Métodos de búsqueda**
- `find(valor)`: Devuelve un iterador al elemento si existe, o `end()` si no.
- `count(valor)`: Devuelve `1` si el valor existe, `0` si no.
- `lower_bound(valor)`: Devuelve iterador al primer elemento **≥ valor**.

**Métodos de iteración**
- `begin()`: Iterador al primer elemento (menor).
- `end()`: Iterador “uno más allá” del último elemento.

**Métodos de capacidad**
- `size()`: Retorna el número de elementos.
- `empty()`: Retorna `true` si está vacío.


## Métodos básicos de librerías `std::set` y `std::map`

### Métodos de inserción
- `insert(valor)`: Inserta un elemento en el `set` (si no existe).  
- `insert(clave, valor)`: Inserta un nuevo par en el `map` con la **clave** y el **valor** (si la clave no existe).  
- `insert(hint, valor)`: Inserta un elemento con una **posición sugerida**.  
  - `hint`: Iterador que indica el lugar aproximado de inserción.  
  - `valor`: Elemento a insertar.  
  - Optimiza la inserción cuando el orden es conocido previamente.  
- `insert(rango_inicio, rango_fin)`: Inserta un **rango completo de elementos** desde otro contenedor.  
  - `rango_inicio`: Iterador al inicio del rango.  
  - `rango_fin`: Iterador al final del rango.  
  - Copia los elementos dentro del rango en el contenedor actual.

### Métodos de eliminación
- `erase(valor)`:  
  - En `set`: Elimina el **valor** especificado (si existe).  
  - En `map`: Elimina el elemento con la **clave** indicada.  
- `erase(iterador)`:  
  - Elimina el elemento apuntado por el **iterador**.  
  - Parámetro: iterador válido dentro del contenedor.  
- `erase(rango_inicio, rango_fin)`:  
  - Elimina todos los elementos comprendidos en el **rango** indicado.  
  - Parámetros: iteradores de inicio y fin del rango.  
- `clear()`:  
  - Elimina **todos los elementos** del contenedor, dejándolo vacío.  
  - No recibe parámetros.

### Métodos de búsqueda
- `find(valor)`:  
  - En `set`: Busca el **valor** y devuelve un iterador a él (o `end()` si no existe).  
  - En `map`: Busca la **clave** y devuelve un iterador al par correspondiente (o `end()` si no existe).  
- `count(valor)`:  
  - En `set`: Devuelve `1` si el **valor** existe, `0` si no.  
  - En `map`: Devuelve `1` si la **clave** existe, `0` si no.  
- `lower_bound(valor)`:  
  - Devuelve un **iterador** al primer elemento **≥ valor** (o **≥ clave** en `map`).  
  - Útil para buscar rangos dentro del contenedor ordenado.  
- `upper_bound(valor)`:  
  - Devuelve un **iterador** al primer elemento **> valor** (o **> clave** en `map`).  
  - Permite definir el final de un rango de búsqueda.  

### Métodos de iteración
- `begin()`:  
  - Devuelve un **iterador al primer elemento** (el menor en orden).  
  - En `map`, el primer elemento corresponde a la **clave más pequeña**.  
- `end()`:  
  - Devuelve un **iterador “uno más allá”** del último elemento (no accesible directamente).  
  - Se usa para determinar el final en los bucles de recorrido.  
- `rbegin()`:  
  - Devuelve un **iterador inverso** al último elemento (mayor en orden).  
- `rend()`:  
  - Devuelve un **iterador inverso “uno antes” del primero**.  

### Métodos de capacidad
- `size()`:  
  - Retorna el **número total de elementos** almacenados en el contenedor.  
  - Tipo de retorno: `size_t`.  
- `empty()`:  
  - Retorna `true` si el contenedor está **vacío**, `false` en caso contrario.  
  - No recibe parámetros.  
- `max_size()`:  
  - Devuelve el **número máximo de elementos** que el contenedor puede almacenar según el sistema.  

## Ejemplo 1: Registro de visitantes frecuentes (uso de `set`)

### El museo nacional desea registrar a sus visitantes frecuentes. 
Cada visitante tiene un número de documento, nombre y categoría (estudiante, docente o público general).  
El sistema debe evitar duplicados y mantener los visitantes **ordenados automáticamente**.

Utiliza **set** para almacenar a los visitantes, ya que este contenedor evita repetidos y mantiene los datos ordenados.

**Funciones a implementar:**
-   **Registrar Visitante:** Inserta un visitante nuevo. Si el documento ya existe, muestra un mensaje de error.
-   **Buscar Visitante:** Dado el documento, muestra su información.
-   **Eliminar Visitante:** Elimina un visitante usando su documento.
-   **Mostrar Visitantes:** Muestra todos los visitantes registrados en orden.
-   **Registrar desde Lista:** Inserta varios visitantes de otra lista usando un rango.
-   **Contar Visitante:** Verifica si un documento está registrado.
-   **Mostrar desde Documento:** Usa `lower_bound` para mostrar visitantes desde un valor dado.
-   **Mostrar Cantidad:** Indica cuántos visitantes hay registrados.
-   **Limpiar Registro:** Elimina todos los visitantes (clear).

**Validaciones:**  
No permitir duplicados ni campos vacíos. Mostrar mensaje si el visitante no existe al eliminar o buscar.

```c++
#include <iostream>
#include <set>
#include <string>

struct Visitante {
    string documento;
    string nombre;
    string categoria;
};

// Comparador para ordenar por documento
struct CompVisitante {
    bool operator()(const Visitante& a, const Visitante& b) const {
        return a.documento < b.documento;
    }
};
```

El código fuente completo correspondiente a este ejercicio presentado en esta guía se encuentra disponible en el repositorio oficial del curso en **GitHub** en [EjercicioSet](https://github.com/UCASV/RecursosExtraPED/blob/main/ArbolesBinarios/EjercicioSet.cc).

## Ejemplo 2: Sistema de inventario de ferretería (uso de `map`)

### Una ferretería necesita un sistema para registrar sus productos.
Cada producto tiene un código único, nombre, categoría, precio y cantidad en existencia.  
El sistema debe mantener los productos **ordenados por código** y permitir actualizaciones rápidas.

Utiliza **map** para almacenar los productos, donde la llave sea el código.

**Funciones a implementar:**
-   **Agregar Producto:** Inserta un nuevo producto si el código no existe.
-   **Actualizar Producto:** Usa el acceso directo para modificar el precio o cantidad.
-   **Buscar Producto:** Muestra la información de un producto dado su código.
-   **Eliminar Producto:** Elimina un producto usando su código.
-   **Mostrar Inventario:** Muestra todos los productos en orden ascendente.
-   **Buscar por Rango:** Usa `lower_bound` y `upper_bound` para mostrar productos con código mayor o igual a uno dado.
-   **Contar Productos:** Indica el total de registros.
-   **Limpiar Inventario:** Vacía todo el registro.
    
**Validaciones:**  
No permitir precios o existencias negativas, ni códigos duplicados o vacíos.

```c++
#include <iostream>
#include <map>
#include <string>

struct Producto {
    string nombre;
    string categoria;
    double precio;
    int stock;
};

void mostrarCantidad(const map<string, Producto>& inventario) {
    cout << "Total de productos: " << inventario.size() << "\n";
}
```
El código fuente completo correspondiente a este ejercicio presentado en esta guía se encuentra disponible en el repositorio oficial del curso en **GitHub** en [EjercicioMap](https://github.com/UCASV/RecursosExtraPED/blob/main/ArbolesBinarios/EjercicioMap.cc).

# Anexos

-   [Referencia oficial de la librería `std::set`](https://en.cppreference.com/w/cpp/container/set) — Documentación técnica oficial que describe en detalle la implementación, propiedades y operaciones del contenedor `std::set` en C++, parte de la Biblioteca Estándar (STL).
    
-   [Introducción a `set` en la STL de C++ — GeeksforGeeks](https://www.geeksforgeeks.org/set-in-cpp-stl/) — Recurso educativo que ofrece una explicación práctica sobre el uso del contenedor `set`, acompañado de ejemplos de código y análisis de su comportamiento interno.
    
-   [Visualización interactiva de estructuras de datos — Binary Search Tree (BST)](https://visualgo.net/en/bst) — Herramienta visual que permite observar el funcionamiento dinámico de los árboles binarios de búsqueda. Ideal para comprender de forma gráfica los procesos de inserción, búsqueda y eliminación en estructuras jerárquicas.
    
-   [Binary Tree Traversals — Preorder, Inorder, and Postorder (EnjoyAlgorithms)](https://www.enjoyalgorithms.com/blog/binary-tree-traversals-preorder-inorder-postorder) — Artículo académico que explica de manera clara los tres recorridos fundamentales de los árboles binarios (preorden, inorden y postorden). Incluye diagramas ilustrativos, pseudocódigo y ejemplos en C++ y Python, reforzando la comprensión de las operaciones de recorrido recursivo.

- [Red/Black Tree Visualization — University of San Francisco](https://www.cs.usfca.edu/~galles/visualization/RedBlack.html) — Herramienta interactiva desarrollada por la _University of San Francisco_ que permite visualizar el funcionamiento interno de los **árboles rojo-negro**, una estructura de datos auto-balanceada. Presenta de forma animada los procesos de inserción, eliminación y rotación de nodos, facilitando la comprensión del equilibrio dinámico de este tipo de árbol binario de búsqueda.

- [Introduction to Red-Black Tree – GeeksforGeeks](https://www.geeksforgeeks.org/dsa/introduction-to-red-black-tree/) — Explica la estructura y funcionamiento de los **árboles Red-Black**, base interna de `std::map` y `std::set`. Describe sus reglas de balanceo, ventajas en eficiencia y cómo garantizan operaciones rápidas de búsqueda e inserción.

- [Using std::map with a custom class key – Walletfox](https://www.walletfox.com/course/mapwithcustomclasskey.php) — Muestra cómo usar `std::map` con **claves personalizadas**, definiendo comparadores o el operador `<` para mantener el orden de los elementos. Incluye ejemplos prácticos con clases.

- [C++ Map – Programiz](https://www.programiz.com/cpp-programming/map) — Ofrece una guía básica sobre `std::map`, explicando su estructura de pares clave-valor, sus métodos principales (`insert`, `erase`, `find`, `[]`) y ejemplos de recorrido y acceso ordenado.
