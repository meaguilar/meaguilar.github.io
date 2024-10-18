# Estructuras de Datos: Árboles

En este laboratorio estudiaremos los **árboles**, una estructura de datos que permite organizar y manipular información de forma jerárquica que es fundamental en la organización y manipulación de datos en muchos campos de la informática

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

![](https://www.oscarblancarteblog.com/wp-content/uploads/2014/08/tiposdenodos.png)

## Tipos de Árboles
1.  **Árbol General**: No hay restricciones en el número de hijos de un nodo.
2.  **Árbol Binario**: Cada nodo tiene como máximo dos hijos.
3.  **Árbol Binario de Búsqueda (BST)**: En un árbol binario de búsqueda, los valores del subárbol izquierdo son menores que los del nodo, y los del subárbol derecho son mayores.
4.  **Árbol AVL**: Árbol binario de búsqueda balanceado donde la diferencia de altura entre subárboles de cualquier nodo no puede ser mayor que 1.

En este laboratorio no centraremos más en estudiar los **Árboles binarios**

## ¿Qué es un Árbol Binario?
Un **árbol binario** es una estructura de datos en la que cada nodo tiene como máximo dos hijos, llamados **hijo izquierdo** e **hijo derecho**. Los árboles binarios son muy eficientes para realizar operaciones como la búsqueda, inserción y eliminación de datos.

Un **árbol binario perfecto** es aquel en el que todos los nodos internos tienen exactamente dos hijos y todas las hojas se encuentran al mismo nivel. Por el contrario, un **árbol binario no perfecto** es aquel en el que no todos los nodos tienen dos hijos o las hojas no están al mismo nivel, lo que genera una estructura menos simetrica.

**![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXeZUo1iQW3CvLdxyj8NvGPbOjC1AxNNDJSAqxsdiM-S0o2ZZ06U4wruYz3XDubfGT7UEQgC6cZezMcRw-SPNPHBtrsk9qB-8Wo7yRQHYddagRPnOgK0X29lNQQl0mAEBI-K9wmOLwyPduq1MYR6FWKUW4mtJV6lAIrFWPRRn7CNJzOgccGNW6M?key=BwtYwK_Wq8XuxDmwAUlVQw)**
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
}
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
}
```
### 3. Recorrer un árbol binario

Los **recorridos de un árbol binario** son formas de visitar todos los nodos del árbol siguiendo un orden específico. Existen tres tipos principales de recorridos: **inorden**, **preorden** y **postorden**. La principal diferencia entre estos recorridos es el momento en que se visita el nodo **padre** en relación con su hijo izquierdo e hijo derecho.

-   **Recorrido Inorden (IPD):** En el recorrido **inorden**, primero se visita el **hijo izquierdo**, luego se **visita el nodo** padre, y finalmente se visita el **hijo derecho**.

	```c++
	void InOrden(Nodo* raiz) {
	    if (raiz != nullptr) {
	        InOrden(raiz->izquierda);
	        std::cout << "ID: " << raiz->dato.id << ", Nombre: " << raiz->dato.nombre << std::endl;
	        InOrden(raiz->derecha);
	    }
	}
	```
  
-   **Recorrido Preorden (PID):** En el recorrido **preorden**, primero se **visita el nodo** padre, luego se visita el **hijo izquierdo**, y finalmente se visita el **hijo derecho**.

	```c++
	void PreOrden(Nodo* raiz) {
	    if (raiz != nullptr) {
	        std::cout << "ID: " << raiz->dato.id << ", Nombre: " << raiz->dato.nombre << std::endl;
	        PreOrden(raiz->izquierda);
	        PreOrden(raiz->derecha);
	    }
	}
	```
    
-   **Recorrido Postorden (IDP):** En el recorrido **postorden**, primero se visita el **hijo izquierdo**, luego se visita el **hijo derecho**, y finalmente se visita el **nodo padre**. 

	```c++
	void PostOrden(Nodo* raiz) {
	    if (raiz != nullptr) {
	        PostOrden(raiz->izquierda);
	        PostOrden(raiz->derecha);
	        std::cout << "ID: " << raiz->dato.id << ", Nombre: " << raiz->dato.nombre << std::endl;
	    }
	}
	```
### 4. **Eliminar un Nodo**
La eliminación de un nodo sigue las mismas reglas, pero comparando siempre el **id** del campo `Datos` para encontrar el nodo a eliminar.

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
## Librería de Árboles C++

En este laboratorio utilizaremos la librería `std::set`, que implementa un árbol de búsqueda balanceado, comúnmente un **Red-Black Tree**. Esto garantiza que el código sea eficiente en términos de velocidad de ejecución.

### Propiedades de la libreria `std::set` 
-   **Orden**: Los elementos siempre se almacenan en orden ascendente
-   **No duplicados**: No se permiten elementos duplicados.
-   **Autobalanceado**: Internamente, utiliza un árbol binario de búsqueda balanceado para optimizar las operaciones.

### Definición del conjunto
Para definir un conjunto, lo haremos primero creando una estructura, la cual  lo haremos mediante el siguiente codigo 

```c++
struct Persona {
    int id;
    std::string nombre;

    // Sobrecargamos el operador < para ordenar por id
    bool operator<(const Persona& otra) const {
        return id < otra.id;
    }
};
```
En este caso, para el conjunto que vamos a crear, es necesario que la estructura personalizada defina el operador `<`, ya que C++ no sabe cómo comparar automáticamente dichos tipos, al no existir una regla predefinida para determinar cuál es **'menor'**. Aquí es donde entra en juego la **sobrecarga del operador `<`**: debemos especificar cómo comparar dos objetos de la estructura `Persona` para que el conjunto pueda ordenarlos correctamente, en este caso, definimos que lo ordenara por id. Si no lo hacemos, se generará un error de compilación.

Luego para definir un conjunto, lo haremos de la siguiente manera
```c++
std::set<Persona> personas;
```

### Operaciones basicas de `std::set`

### Insertar elementos
Cada vez que agregas algo a un `std::set`, lo guarda en orden y no deja que haya duplicados. Si intentas agregar algo que ya existe, simplemente no lo inserta.
```c++
personas.insert({1, "Juan"}); 
personas.insert({3, "Ana"}); 
personas.insert({2, "Pedro"});
```
### Buscar un elemento en el conjunto
Puedes buscar un elemento para ver si está en el conjunto. Como es de tipo booleano, te devolvera verdadero o falso, indicando si lo encontro o no.

```c++
    // Buscar una persona por id
    Persona buscar = {2, ""};  // Solo necesitamos el 'id' para buscar
    auto it = personas.find(buscar);

    if (it != personas.end()) {
        std::cout << "Persona encontrada: " << it->nombre << std::endl;
    } else {
        std::cout << "Persona no encontrada." << std::endl;
    }
```

#### ¿Que es el tipo de dato auto?
El tipo de dato `auto` es una palabra clave que permite al compilador deducir automáticamente el tipo de una variable a partir de su valor de inicialización. Es especialmente útil cuando el tipo de la variable es complejo o largo de escribir, como en el caso de los iteradores, funciones lambda, o punteros inteligentes.

Como `personas.find(buscar)` devuelve un iterador que apunta al tipo de dato almacenado en el contenedor en este caso, una estructura `Persona`, `it` será del tipo adecuado, que normalmente sería algo como `std::set<Persona>::iterator`, en ves de escribir todo eso, lo simplificamos con `auto`.

### Eliminar del conjunto
Para eliminar una persona, usamos la función `erase`, pasando el identificador que queremos eliminar.

```c++
Persona eliminar = {1, ""};  // Solo necesitamos el 'id' para eliminar
personas.erase(eliminar);
```
### Recorrer un conjunto
Para recorrer el conjunto e imprimir los elementos, podemos usar un bucle `for`, donde el conjunto ya se encuentra ordenado automáticamente.

```c++
 for (auto it = personas.begin(); it != personas.end(); ++it) {
    const auto& persona = *it;
    std::cout << "ID: " << persona.id << ", Nombre: " << persona.nombre << std::endl;
}
```
`personas.begin()` indica el inicio y `personas.end()` el ultimo elemento del conjunto.

Una forma mucho mas común de implementar un recorrido y simplificandolo, es aplicando un **bucle rango** . Este tipo de bucle simplifica la iteración sobre contenedores como `std::set`, `std::vector`, `std::array`, entre otros. Lo podemos definir de la siguiente manera

```c++
 for (const auto& persona : personas) {
    std::cout << "ID: " << persona.id << ", Nombre: " << persona.nombre << std::endl;
 }
```

  `const`: Indica que la variable `persona` no se puede modificar durante la iteración. Esto asegura que el contenido de cada objeto no cambie accidentalmente.
  
`&` (Referencia): Permite evitar la copia de cada elemento en cada iteración. En lugar de copiar los elementos del contenedor `personas`, se accede a ellos por referencia, lo que mejora la eficiencia al no duplicar los objetos.

`persona`: Es la variable que representa un elemento individual del contenedor `personas`. En cada iteración, `persona` toma el valor de un objeto diferente del tipo `Persona`.

`personas`: Es el contenedor que estamos recorriendo. En este caso, es un `std::set<Persona>`


# Anexos

-   [Referencia oficial de la librería `std::set`](https://en.cppreference.com/w/cpp/container/set) - Documentación detallada sobre la implementación y uso del contenedor `set` en C++.
    
-   [Introducción a `set` en la STL de C++](https://www.geeksforgeeks.org/set-in-cpp-stl/) - Un recurso práctico que explica cómo utilizar `set` con ejemplos claros y concisos.
    
-   [Visualización interactiva de estructuras de datos - Binary Search Tree (BST)](https://visualgo.net/en/bst) - Herramienta visual para entender el funcionamiento de los árboles binarios de búsqueda, base de la implementación de `std::set`.

