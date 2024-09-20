# **Estructuras de datos dinámicas lineales colas y pilas**

En este laboratorio estudiaremos sobre el uso de pilas y colas dinámicas, cómo declararlas, utilizarlas, y su importancia en la organización y manipulación de datos en la programación.

## ¿Qué son las Pilas y Colas?
Las **pilas** y **colas** son estructuras de datos lineales que permiten almacenar y acceder a elementos de manera ordenada. Ambas utilizan nodos y punteros para gestionar la memoria de forma dinámica, lo que significa que pueden crecer o reducirse según sea necesario durante la ejecución del programa, **al igual que las listas que estudiamos en el laboratorio anterior**.

## Pilas
Una **pila** es una estructura de datos que sigue el principio **LIFO (Last In, First Out)**, es decir, el último elemento en entrar es el primero en salir. Imagina una pila de platos: el último plato que colocas en la cima es el primero que quitarás.

<p align="center"> <img src="https://lh7-rt.googleusercontent.com/docsz/AD_4nXdIATfVXY4Ni-804VGKv9LGcuVZPA4sxNh27aGg8q-9-D36OgD8e0ZdXh0eVBamU71Cc4h13vdEQ7QaBkkHz0Zmza09Z88Qvlf1Tv17_3MyPsl3h3vZTIEGfqOikQTdYLUOrE3HzAjRl7WalB86qhIbOc_EhDHuuCcSRwzXjg?key=nHEcAS-RB1f7GUpWs0_PNg" alt="Descripción de la imagen" width="0"/> </p>

### Operaciones básicas en una pila

-   **Push (Apilar)**: Agregar un elemento al tope de la pila.
-   **Pop (Desapilar)**: Eliminar el elemento del tope de la pila.
-   **Peek (Cima)**: Obtener el valor del elemento en el tope sin eliminarlo.
-   **isEmpty (Está vacía)**: Verificar si la pila está vacía.

### Definición de una pila
Cada nodo en una pila almacena un valor y un puntero al nodo siguiente.
```c++
struct Nodo {
    int dato;         // Valor almacenado en el nodo
    Nodo* siguiente;  // Puntero al siguiente nodo
};
```

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
###  Ejemplo completo de una pila
Puedes mirar un ejemplo completo de todas las funciones que se pueden hacer con las pilas, en este <a href="https://github.com/German234/LaboratoriosPED/blob/e039ff2747632b5f9b67b1811cdd88ed8d158bbb/Laboratorio-6/PilasManual.cc">repositorio</a>.


##  Uso de pilas usando libreria de C++
Ahora que ya aprendimos como funcionan las pilas internamente podemos hacer uso de una libreria que C++ ya trae por defecto, que es 
`std::stack`. Esta libreria nos traerá todas las funciones que mencionamos anteriormente y las tendremos a dispocision para manejar pilas de una manera muchisimo más sencilla.

Para eso, primero importaremos la libreria, para eso la importaremos de la siguiente manera:
```c++
#include <iostream>
#include <stack>
```
Luego, en ves de crear los nodos, ahora lo declararemos de la siguiente manera:
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

Para hacer uso de todas estas funciones, accederemos a traves de nuestra pila. Por ejemplo:

```c++
pila.push(10);
pila.push(20);
pila.push(30);
```

### Ejemplo practico de uso de libreria
Puedes mirar un ejemplo completo de todas las funciones que se pueden hacer con las pilas, en este <a href="https://github.com/German234/LaboratoriosPED/blob/e039ff2747632b5f9b67b1811cdd88ed8d158bbb/Laboratorio-6/PilasLibreria.cc">repositorio</a>.

## Colas (Queues)
Una **cola** es una estructura de datos que sigue el principio **FIFO (First In, First Out)**, es decir, el primer elemento en entrar es el primero en salir. Puedes imaginar una fila de personas esperando para ser atendidas; la primera persona en llegar es la primera en ser atendida.

<p align="center"> <img src="https://www.encolate.es/wp-content/uploads/2019/11/amimacion-fila-unica.gif" alt="Descripción de la imagen" width="300"/> </p>

A diferencia de las pilas, donde el acceso es por un solo extremo, en las colas se interactúa por ambos extremos: los elementos se **agregan** por un extremo (final) y se **eliminan** por el otro (frente).

### Operaciones básicas en una cola

-   **Enqueue (Encolar)**: Agregar un elemento al final de la cola.
-   **Dequeue (Desencolar)**: Eliminar el elemento al frente de la cola.
-   **Front (Frente)**: Obtener el valor del elemento al frente sin eliminarlo.
-   **isEmpty (Está vacía)**: Verificar si la cola está vacía.

### Definición de un nodo

Al igual que en las listas y pilas, una cola está compuesta por **nodos**. Cada nodo contiene un valor y un puntero al siguiente nodo.

```c++
struct Nodo {
    int dato;         // Valor almacenado en el nodo
    Nodo* siguiente;  // Puntero al siguiente nodo
};
```

Primero, recordemos la definición de la estructura `Nodo`:

Cada `Nodo` contiene:

-   Un valor (`dato`).
-   Un puntero al siguiente `Nodo` en la cola (`siguiente`).

Los nodos están enlazados entre sí formando una **lista enlazada**. En este caso, utilizamos una lista enlazada simple para implementar la cola.

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

Aunque `Cola` no tiene un miembro que sea directamente un `Nodo`, mantiene punteros a los nodos que conforman la cola. Esto es suficiente para gestionar la estructura y realizar las operaciones necesarias.

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
En este código, primero se crea un nuevo `nodo` y luego se le asignan los valores, una vez tienen los valores, al igual que una **lista enlazada**, el siguiente del nuevo nodo que acabamos de crear apuntara a `nillptr`.  Luego solo se hace una pequeña verificación para analizar si la lista esta vacía o no, y en base a eso agregar al final de la lista.

## Función para desencolar (Dequeue)
Esta función eliminara el nodo que este de primero, funciona igual que una fila de personas, el primero que entra, será el primero **en salir**.

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
En este código después de verificar la fila esta vacía o no, si no lo está, entonces como ya tenemos un puntero, se dice que el nodo a eliminar será justo el de enfrente. Luego, solo se hace una pequeña comparación para mover la lista, donde el nuevo frente será justo **el siguiente del frente que vamos a eliminar**. Luego, solo se hace la comparación de que si justo ese nodo era el ultimo, entonces la cola, el final y el principio, son `nullptr` y se libera la memoria del nodo que se elimino.

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
Acá cabe aclarar que la función debe ser **del mismo tipo de dato** del contenido de cada nodo, en este caso estamos asumiendo que el dato es un entero, por eso retorna la función un **entero**.

###  Ejemplo completo de una pila manualmente.
Puedes mirar un ejemplo completo de todas las funciones que se pueden hacer con las colas, en este <a href="https://github.com/German234/LaboratoriosPED/blob/e039ff2747632b5f9b67b1811cdd88ed8d158bbb/Laboratorio-6/ColasManual.cc">repositorio</a>.

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

Podemos notar que el uso y las funciones son muy parecidas a las de las pilas. De igual manera para acceder a las funciones de las colas, lo hacemos a través de la cola que hemos creado con la librería.

### Ejemplo de uso
```c++
    std::queue<int> cola;
    cola.push(10);
    cola.push(20);
    cola.push(30);
```

### Ejemplo practico de uso de libreria
Puedes mirar un ejemplo completo de todas las funciones que se pueden hacer con las colas, en este <a href="https://github.com/German234/LaboratoriosPED/blob/e039ff2747632b5f9b67b1811cdd88ed8d158bbb/Laboratorio-6/PilasLibreria.cc">repositorio</a>.
