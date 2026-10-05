# Estructuras de datos dinámicas lineales: Colas y Pilas


## 1. ¿Que es una Pila (Stack)?

Una **pila** es una estructura de datos que sigue el principio **LIFO (Last In, First Out)**.

![Stack](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/refs/heads/main/PED/Imagenes/CP5/Stack-data-structure.webp)

##  Uso de pilas de manera manual

### Apilar (Push)
Cuando agregamos elementos a una pila, esta por defecto se va a agregar hasta encima, por el principio que mencionamos anteriormente, que cuando apilamos, el ultimo que agregamos es el primero.

```c++
void Push(Nodo*& cima, int valor) {
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->dato = valor;
    nuevo_nodo->siguiente = cima;
    cima = nuevo_nodo;
}
```

**NOTA**: En este caso, `cima` es el ultimo elemento que se agrego, por eso al final del codigo, decimos que 
```c++
cima = nuevo_nodo;
```
para ir actualizando la cima cada que se agrega un nuevo nodo.

### Desapilar (Pop)
Elimina el nodo del tope de la pila y devuelve su valor.
```c++
int Pop(Nodo*& cima) {
    if (cima == nullptr) {
        std::cerr << "La pila está vacía." << std::endl;
        return -1; // O lanzar una excepción
    }
    
    Nodo* nodo_eliminar = cima;
    int valor = nodo_eliminar->dato;
    cima = cima->siguiente;
    delete nodo_eliminar;
    return valor;
}
```
En este caso, si la cima (que como dijimos anteriormente es el ultimo nodo que agregamos) esta vacia, significa que NO hay elementos, asi que ya no eliminamos. Pero de haber, lo interesante es que al final, decimos que:
```c++
cima = cima->siguiente;
``` 
Dando a entender que ahora, como eliminamos la cima, el que estaba debajo del que acabamos de eliminar, **es la nueva cima**
### 

### Obtener la cima (Peek)
Esta función solo muestra la cima, sin embargo no la elimina.
```c++
int Peek(Nodo* cima) {
    if (cima == nullptr) {
        std::cerr << "La pila está vacía." << std::endl;
        return -1; // O lanzar una excepción
    }
    return cima->dato;
}
```

##  Uso de pilas usando libreria de C++

Ahora que ya aprendimos como funcionan las pilas internamente podemos hacer uso de una libreria que C++ ya trae por defecto, que es 
`std::stack`. Esta libreria nos traerá todas las funciones que mencionamos anteriormente y las tendremos a dispocision para manejar pilas de una manera muchisimo más sencilla.

Para eso, primero importaremos la libreria, para eso la importaremos de la siguiente manera:
```c++
#include <iostream>
#include <stack>
```
En lugar de crear los nodos manualmente, ahora podemos declarar la pila de la siguiente manera:
```c++
std::stack<TipoDeDato> nombre_de_la_pila;
```
Donde el `tipo de dato` puede ser int, float, char o incluso una estructura. Mientras que el nombre de la pila, sera el identificador de toda nuestra pila.

Ahora que ya creamos nuestra pila, ya podemos hacer uso de las funciones que trae la libreria:

-   **`push(valor)`**: Agrega un elemento al tope de la pila.
-   **`pop()`**: Elimina el elemento del tope de la pila.
-   **`top()`**: Devuelve una referencia al elemento en el tope de la pila.
-   **`empty()`**: Devuelve `true` si la pila está vacía; de lo contrario, devuelve `false`.
-   **`size()`**: Devuelve el número de elementos en la pila.

## ¿Que son las Colas (Queues)?

Una **cola** es una estructura de datos que sigue el principio **FIFO (First In, First Out)**. A diferencia de las pilas, donde el acceso es por un solo extremo, en las colas se interactúa por ambos extremos.


![Queue](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/refs/heads/main/PED/Imagenes/CP5/Queue-data-structure.png)

### Definición de un nodo

Al igual que en las listas y pilas, una cola está compuesta por **nodos**. Cada nodo contiene un valor y un puntero al siguiente nodo.

```c++
struct Nodo {
    int dato;         // Valor almacenado en el nodo
    Nodo* siguiente;  // Puntero al siguiente nodo
};
```


### Definición de una cola

Para facilitar el acceso tanto al frente como al final de la cola, utilizamos una estructura que mantiene punteros a ambos extremos.
```c++
struct Cola {
    Nodo* frente;     // Puntero al frente de la cola
    Nodo* final;      // Puntero al final de la cola
};
```
La estructura `Cola` contiene dos punteros:

-   `frente`: Apunta al primer nodo de la cola (donde se realiza la operación de **desencolar**).
-   `final`: Apunta al último nodo de la cola (donde se realiza la operación de **encolar**).

## Uso de colas de manera manual

### Encolar (Enqueue)
Esta función nos agregará un nodo al final de la cola.
```c++
void Encolar(Cola*& cola, int valor) {
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->dato = valor;
    nuevo_nodo->siguiente = nullptr;

    if (cola->frente == nullptr) {
        // La cola está vacía
        cola->frente = nuevo_nodo;
    } else {
        // La cola tiene al menos un elemento
        cola->final->siguiente = nuevo_nodo;
    }
    cola->final = nuevo_nodo;
}
```

## Función para desencolar (Dequeue)
Esta función eliminara el nodo que este de primero.

```c++
int Desencolar(Cola*& cola) {
    if (cola->frente == nullptr) {
        std::cerr << "La cola está vacía." << std::endl;
    }

    Nodo* nodo_eliminar = cola->frente;
    int valor = nodo_eliminar->dato;
    cola->frente = cola->frente->siguiente;

    if (cola->frente == nullptr) {
        // Si la cola quedó vacía, actualizamos el puntero final
        cola->final = nullptr;
    }

    delete nodo_eliminar;
    return valor;
}
```

## Obtener el valor del frente (Front)

Esta función, hace casi lo mismo que el de eliminar, solo que, no elimina como tal el nodo, solo lo muestra.

```c++
int Frente(Cola* cola) {
    if (cola->frente == nullptr) {
        std::cerr << "La cola está vacía." << std::endl;
    }
    return cola->frente->dato;
}
```

## Uso de colas usando librería de C++
Al igual que con las pilas, C++ nos provee de una librería para gestionar las colas llamada `queue`

### Incluyendo la librería
Para utilizar `std::queue`,  incluiremos el encabezado correspondiente:
```c++
#include <iostream>
#include <queue>
```
### Definición de una cola
La sintaxis general para declarar una cola es:
```c++
std::queue<TipoDeDato> nombre_de_la_cola;
```
Donde el `tipo de dato` puede ser int, float, char o incluso una estructura. Mientras que el nombre de la cola, sera el identificador de toda nuestra cola.

Ahora que ya creamos nuestra cola, ya podemos hacer uso de las funciones que trae la libreria:

-   **`push(valor)`**: Agrega un elemento al final de la cola.
-   **`pop()`**: Elimina el elemento al frente de la cola.
-   **`front()`**: Devuelve una referencia al elemento al frente de la cola.
-   **`back()`**: Devuelve una referencia al último elemento de la cola.
-   **`empty()`**: Devuelve `true` si la cola está vacía; de lo contrario, devuelve `false`.
-   **`size()`**: Devuelve el número de elementos en la cola.

## Buenas practicas de implementacion.

## Ejemplo 


## Anexos
- [Stack Data Structure - GeeksforGeeks](https://www.geeksforgeeks.org/dsa/stack-data-structure/)

- [Queue Data Structure - GeeksforGeeks](https://www.geeksforgeeks.org/dsa/queue-data-structure/)

- [DSA Stacks - w3schools](https://www.w3schools.com/dsa/dsa_data_stacks.php)

- [DSA Queues - w3schools](https://www.w3schools.com/dsa/dsa_data_queues.php)

- [Linked List (Single, Doubly), Stack, Queue, Deque - VisuAlgo](https://visualgo.net/en/list)
