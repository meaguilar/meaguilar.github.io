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

