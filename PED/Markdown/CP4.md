# Estructuras de datos dinámicas lineales: listas

En este laboratorio aprenderás sobre el uso de listas dinámicas, cómo declararlas, utilizarlas, y su importancia en la organización y manipulación de datos en la programación.

## ¿Qué es una lista dinámica?

Una **lista dinámica** es una estructura de datos en la que los elementos se organizan secuencialmente, pero su tamaño puede cambiar de manera dinámica, es decir, puede crecer o reducirse según sea necesario.

A diferencia de las **listas estáticas** o arreglos, las listas dinámicas **no necesitan un tamaño fijo** y permiten una mayor flexibilidad en la gestión de la memoria.

### Características de las listas dinámicas
- **Uso de punteros**: Los nodos de una lista dinámica almacenan punteros que enlazan los nodos entre sí.
- **Memoria dinámica**: Se gestiona mediante punteros, lo que permite un uso eficiente de la me la listaista dn un al sguta, a
-  **Inserción y eliminación eficientes**: Las operaciones de inserción y eliminación de elementos son más eficientes que en los arreglos estáticos.

## Importancia de los Punteros en la Gestión de Memoria y Manipulación de Datos

Los punteros juegan un papel fundamental en la **gestión eficiente de la memoria** y en la **manipulación de datos** dentro de la programación. 

En muchas aplicaciones, no siempre sabemos cuánta memoria será necesaria durante la ejecución del programa. Los punteros nos permiten **asignar y liberar memoria dinámica** de manera manual, lo cual es crucial para gestionar correctamente los recursos en programas que requieren mucha memoria o cuya cantidad de datos no es fija.

Al usar punteros, es posible **optimizar el rendimiento** del programa al reducir el uso de memoria y permitir un acceso más rápido a los datos.

## Punteros propietarios
Cuando un programa necesita más espacio para guardar algo grande, usa una parte especial de la memoria llamada **_heap_**. Cuando hace esto, el programa recibe una "dirección" que le dice dónde se guarda ese algo, y esa dirección se guarda en forma de puntero. Este tipo de punteros se llaman **punteros propietarios**.

El problema es que, cuando terminas de usar ese espacio, el programa no lo libera automáticamente. Tú tienes que decirle al programa que lo haga, porque si no, el espacio sigue ocupado y el programa o incluso otros programas no podrán usarlo. Esto se llama **"fuga de memoria"**, porque el espacio queda atrapado sin poder ser reutilizado.

Para manejar esto, se usan dos comandos importantes: `new` para **pedir** espacio en el heap y `delete` para **liberar** ese espacio cuando ya no lo necesitas.

```c++
#include <iostream>

int main() {
    int* p = new int;
    *p = 42;  
    std::cout << "Valor en el heap: " << *p << std::endl;
    delete p;  
    p = nullptr; 
    return 0;
}
```
```bash
Valor en el heap: 42
```
En este ejemplo, hemos usado `new` para pedir espacio en el heap y almacenamos la dirección de esa memoria en el puntero `p`. Usamos `p` para almacenar el valor `42` en esa memoria.

Si no liberamos la memoria con `delete`, esa memoria sigue ocupada aunque ya no la estemos usando, lo que genera una **fuga de memoria**.

### ¿Que es nullptr?
`nullptr` es un valor especial en C++ que representa un puntero que **no apunta a ninguna dirección de memoria válida**. En otras palabras, es una forma de inicializar o restablecer un puntero para indicar que **no tiene un objeto o memoria a la cual apuntar**.

Después de liberar la memoria con `delete`, es buena práctica asignar `nullptr` al puntero. Esto ayuda a evitar que el puntero siga apuntando a una ubicación de memoria que ya no es válida (puntero colgante).


## Tipos de listas dinámicas

En general estudiaremos cuatro tipos de listas dinámicas, las cuales serán:

-  **Lista simplemente enlazada**
-  **Listas doblemente enlazada**
- **Listas circulares simplemente enlazadas**
- **Listas circulares doblemente enlazadas**


Pero antes de ver a profundidad como funcionan estas tipos de listas, veremos que todas están compuestas por **nodos**. Cada nodo está compuesto por dos partes principales:

-   **Dato**: El valor almacenado en el nodo.
-   **Puntero**: Cada nodo va a apuntar a otro nodo mediante punteros, ya sea para adelante o para atras **(Veremos más adelante en que casos)**

En C++, cada nodo puede declararse como una estructura que almacena un valor y punteros para enlazar con los nodos anterior y siguiente, como se muestra a continuación:

```c++
struct Nodo{
    int dato;            // Valor almacenado
    NodoDoble* siguiente; // Puntero al siguiente nodo
    NodoDoble* anterior;  // Puntero al nodo anterior
};
```
Sin embargo, se sugiere una mejora organizativa: separar los datos en una estructura independiente. Esto proporciona dos ventajas clave: primero, **mejora el orden** y la **modularidad del código**; segundo, facilita la **ampliación** de los datos almacenados en el futuro, permitiendo agregar múltiples valores sin necesidad de modificar la estructura del nodo.

```c++
// Estructura para almacenar los datos
struct Datos {
    int valor;       // Valor que se quiere almacenar en la lista
    // Puedes agregar más campos si es necesario
};

// Estructura del nodo
struct Nodo {
    Datos dato;      // Campo de tipo Datos que contiene el valor
    Nodo* anterior;  // Puntero al nodo anterior
    Nodo* siguiente; // Puntero al nodo siguiente
};
```

### Funciones en una lista
Las operaciones más comunes que se pueden realizar en una lista enlazada incluyen:

-   **Agregar un nodo al principio**.
-   **Mostrar todos los nodos** (recorrer la lista).
-   **Eliminar un nodo**.
-   **Buscar un valor en la lista**

## Listas simplemente enlazadas
Una **lista enlazada simple** es una estructura de datos dinámica en la que cada nodo apunta al nodo siguiente. Esto va a ser verdadero hasta el ultimo nodo, ya que el ultimo nodo no apunta a otro nodo como tal, si no que el puntero apunta a `nullptr`

`nullptr` es un valor especial en C++ que representa un **puntero que no apunta a ninguna dirección de memoria válida**. En otras palabras, indica que un puntero no está asociado con ningún objeto o variable en particular.

![enter image description here](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/refs/heads/main/PED/Imagenes/CP4/Listas-simplemente-enlazadas.png)

### Agregar un nodo al principio
Esta función agrega un nuevo nodo al principio de la lista, actualizando la referencia de la cabeza para que apunte a este nuevo nodo.
```c++
void AgregarNodo(Nodo*& cabeza, int valor) {
    Nodo* nuevo_nodo = new Nodo();  // Crear un nuevo nodo en memoria dinámica
    nuevo_nodo->dato = valor;       // Asignar el valor al nodo
    nuevo_nodo->siguiente = cabeza; // Apuntar al antiguo primer nodo
    cabeza = nuevo_nodo;            // Actualizar la cabeza para que apunte al nuevo nodo
}
```

### Mostrar todos los nodos
 Utiliza un bucle `while` para recorrer la lista mientras el nodo actual no sea `nullptr`, imprimiendo cada valor. Al llegar al final de la lista, imprime "nullptr" para indicar que no hay más nodos.
```c++
void MostrarLista(Nodo* cabeza) {
    Nodo* actual = cabeza;  // Iniciar desde la cabeza
    while (actual != nullptr) {
        std::cout << actual->dato << " -> ";  // Mostrar el valor del nodo actual
        actual = actual->siguiente;           // Avanzar al siguiente nodo
    }
    std::cout << "nullptr" << std::endl;      // Final de la lista
}
```

### Buscar un valor en la lista

Partiendo del nodo `cabeza`, recorre la lista utilizando un bucle `while` que continúa mientras el nodo actual no sea `nullptr`. En cada iteración, compara el valor del nodo actual con el valor buscado. Si encuentra una coincidencia, devuelve `true`, indicando que el valor está presente en la lista. Si el bucle termina sin encontrar el valor, devuelve `false`
```c++
bool BuscarValor(Nodo* cabeza, int valor) {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        if (actual->dato == valor) {
            return true;  // Valor encontrado
        }
        actual = actual->siguiente;
    }
    return false;  // Valor no encontrado
}
```
### Eliminar un nodo con un valor específico
Para eliminar un nodo, se comienza con dos punteros, `actual` apuntando al primer nodo y `anterior` a `nullptr`. Recorre la lista hasta encontrar el valor deseado. Si encuentra el nodo, revisa si es el primer nodo (si `anterior` es `nullptr`) y ajusta el nodo `cabeza` al siguiente. Si no es el primero, enlaza el nodo `anterior` directamente al siguiente de `actual`, omitiéndolo de la lista.
```c++
void EliminarNnodo(Nodo*& cabeza, int valor) {
    Nodo* actual = cabeza;
    Nodo* anterior = nullptr;

    while (actual != nullptr && actual->dato != valor) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == nullptr) return;  // Valor no encontrado

    if (anterior == nullptr) {
        cabeza = actual->siguiente;  // Si es el primer nodo
    } else {
        anterior->siguiente = actual->siguiente;  // Saltar el nodo a eliminar
    }

    delete actual;  // Liberar la memoria del nodo eliminado
}
```

### Ejemplo completo
Puedes ver un ejemplo completo de la implementación de listas simples en este [repositorio lista simplemente enlazada](https://github.com/meaguilar/meaguilar.github.io/blob/main/PED/RepoLaboratorios/Listas/ListasSimples.cc).

## Listas doblemente enlazadas

Después de haber estudiado que son las listas enlazadas simples, es el momento de introducir una variante más compleja: las **listas doblemente enlazadas**. Estas listas permiten una navegación bidireccional a través de los nodos, gracias a que cada nodo de la lista tiene dos punteros: uno hacia el siguiente nodo y otro hacia el anterior.

![enter image description here](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/refs/heads/main/PED/Imagenes/CP4/Listas-doblemente-enlazadas.png)
### Definición de nodos en una lista doblemente enlazada
En C++, un nodo en una lista doblemente enlazada se declara generalmente con la siguiente estructura:
```c++
struct Nodo{
    int dato;            // Valor almacenado
    NodoDoble* siguiente; // Puntero al siguiente nodo
    NodoDoble* anterior;  // Puntero al nodo anterior
};
```

Algo importante que aclarar es que en las listas doblemente enlazadas, el nodo anterior del primer nodo apunta a `nullptr`. De manera similar, el nodo siguiente del nodo final también apunta a `nullptr`. Estos punteros a `nullptr` son cruciales para identificar los **extremos de la lista**.

### Agregar un nodo al principio
Para crear un nuevo nodo, se asigna el valor proporcionado y se conecta al actual primer nodo de la lista. Si ya hay nodos en la lista, actualiza el nodo que estaba al inicio para que reconozca al nuevo nodo como su anterior. Al final, establece este nuevo nodo como el nuevo inicio de la lista actualizando el puntero `cabeza`.
```c++
void AgregarNodoAlInicio(Nodo*& cabeza, int valor) {
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->dato = valor;
    nuevo_nodo->siguiente = cabeza;
    nuevo_nodo->anterior = nullptr;
    if (cabeza != nullptr) {
        cabeza->anterior = nuevo_nodo;
    }
    cabeza = nuevo_nodo;
}
```
### Agregar un nodo al final
Inicialmente crea un nuevo nodo con el valor dado y lo prepara para ser el último estableciendo su puntero `siguiente` a `nullptr`. Si la lista está vacía, simplemente establece este nuevo nodo como el primer y último nodo de la lista. Si hay otros nodos, recorre la lista hasta el final y enlaza el nuevo nodo al último nodo existente, ajustando adecuadamente los punteros `siguiente` del último nodo y `anterior` del nuevo nodo.
```c++
void AgregarNodoAlFinal(Nodo*& cabeza, int valor) {
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->dato = valor;
    nuevo_nodo->siguiente = nullptr;

    if (cabeza == nullptr) {
        nuevo_nodo->anterior = nullptr;
        cabeza = nuevo_nodo;
    } else {
        Nodo* actual = cabeza;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo_nodo;
        nuevo_nodo->anterior = actual;
    }
}
```

### Eliminar un nodo
Para eliminar un nodo primero, busca por toda la lista hasta encontrar el nodo con el valor que se quiere eliminar. Si lo encuentra, desconecta ese nodo de la lista ajustando los enlaces del nodo anterior y del siguiente, para que ya no se conecten con el nodo eliminado. Si el nodo a eliminar es el primero, simplemente cambia el inicio de la lista al siguiente nodo. Si no encuentra el nodo con el valor deseado, no hace nada. Al final, elimina el nodo para liberar el espacio que ocupaba.

```c++
void EliminarNodo(Nodo*& cabeza, int valor) {
    Nodo* actual = cabeza;

    while (actual != nullptr && actual->dato != valor) {
        actual = actual->siguiente;
    }

    if (actual == nullptr) return; // Valor no encontrado

    if (actual->anterior != nullptr) {
        actual->anterior->siguiente = actual->siguiente;
    } else {
        cabeza = actual->siguiente; // Eliminar el primer nodo
    }

    if (actual->siguiente != nullptr) {
        actual->siguiente->anterior = actual->anterior;
    }

    delete actual; // Liberar la memoria del nodo eliminado
}
```

### Recorrer un nodo
Esta función recorre y muestra los valores de una lista doblemente enlazada, empezando desde el primer nodo de la lista. Comienza con el primer nodo y continúa avanzando de nodo en nodo hasta que no hay más nodos que mostrar, lo que se indica cuando el nodo actual es `nullptr`
```c++
void MostrarLista(Nodo* cabeza) {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        std::cout << actual->dato << " <-> ";
        actual = actual->siguiente;
    }
    std::cout << "nullptr" << std::endl;
}
```

### Ejemplo completo
Puedes ver un ejemplo completo de la implementación de listas dobles en este [repositorio listas doblemente enlazadas](https://github.com/meaguilar/meaguilar.github.io/blob/main/PED/RepoLaboratorios/Listas/ListasDobles.cc)


## Listas circulares simplemente enlazadas

Una **lista circular simple** es una estructura de datos dinámica en la que cada nodo apunta al siguiente, formando un ciclo cerrado en el que el último nodo está conectado al primer nodo. A diferencia de una lista enlazada simple, no tiene un final definido (`nullptr`), lo que permite un recorrido continuo.

![enter image description here](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/refs/heads/main/PED/Imagenes/CP4/Listas-circulares-simplemente-enlazadas.png)

### Características de una lista circular simple

-   **Circularidad**: El último nodo de la lista no apunta a `nullptr`, sino que enlaza de vuelta al primer nodo.
-   **Uso de punteros**: Los nodos se conectan mediante punteros que apuntan al siguiente nodo en la secuencia.
-   **Recorrido continuo**: Debido a su naturaleza circular, se puede recorrer la lista indefinidamente, útil en aplicaciones donde se necesita un acceso recurrente a los elementos.
-   **Inserción y eliminación eficiente**: Al igual que en otras listas dinámicas, estas operaciones son eficientes porque solo se requiere ajustar los punteros.

### Nodos en una lista circular simple
Al igual que las listas enlazadas simples, las listas circulares simples están compuestas por **nodos**, y cada nodo tiene dos partes principales, **valor** y el puntero **siguiente**

```c++
struct Nodo {
    int dato;         // Valor almacenado en el nodo
    Nodo* siguiente;  // Puntero al siguiente nodo
};
```
### Agregar un nodo al principio
Para agregar un nodo al principio de una lista circular simple, se debe crear el nuevo nodo, enlazarlo al antiguo primer nodo y hacer que el último nodo apunte al nuevo nodo. Si la lista está vacía, el nuevo nodo será el único nodo, y su puntero apuntará a sí mismo.
```c++
void AgregarNodoAlPrincipio(Nodo*& cabeza, int valor) {
    Nodo* nuevo_nodo = new Nodo();  // Crear un nuevo nodo en memoria dinámica
    nuevo_nodo->dato = valor;

    if (cabeza == nullptr) {
        nuevo_nodo->siguiente = nuevo_nodo;  // Si la lista está vacía, apunta a sí mismo
        cabeza = nuevo_nodo;
    } else {
        Nodo* temp = cabeza;
        while (temp->siguiente != cabeza) {  // Encontrar el último nodo
            temp = temp->siguiente;
        }
        nuevo_nodo->siguiente = cabeza;  // Enlazar al antiguo primer nodo
        temp->siguiente = nuevo_nodo;    // Enlazar el último nodo al nuevo nodo
        cabeza = nuevo_nodo;             // Actualizar la cabeza al nuevo nodo
    }
}
```
### Mostrar todos los nodos
Esta función recorre la lista circular e imprime el valor de cada nodo. Dado que no hay un nodo con valor `nullptr`, se detiene cuando vuelve al primer nodo.
```c++
void MostrarLista(Nodo* cabeza) {
    if (cabeza == nullptr) {
        std::cout << "La lista está vacía" << std::endl;
        return;
    }

    Nodo* actual = cabeza;
    do {
        std::cout << actual->dato << " -> ";  // Mostrar el valor del nodo
        actual = actual->siguiente;           // Avanzar al siguiente nodo
    } while (actual != cabeza);  // Detenerse cuando se vuelve a la cabeza

}
```
### Eliminar un nodo con un valor específico
Para eliminar un nodo de una lista circular simple, primero se debe localizar el nodo con el valor deseado. Una vez encontrado, se actualizan los punteros del nodo anterior y, si es necesario, se actualiza la referencia de la cabeza.
```c++
void EliminarNodo(Nodo*& cabeza, int valor) {
    if (cabeza == nullptr) return;  // Si la lista está vacía, no hacer nada

    Nodo* actual = cabeza;
    Nodo* anterior = nullptr;

    do {
        if (actual->dato == valor) {
            if (anterior == nullptr) {  // Si es el primer nodo
                Nodo* temp = cabeza;
                while (temp->siguiente != cabeza) {
                    temp = temp->siguiente;
                }
                if (cabeza == cabeza->siguiente) {
                    delete cabeza;  // Eliminar el único nodo
                    cabeza = nullptr;
                } else {
                    temp->siguiente = cabeza->siguiente;
                    delete cabeza;
                    cabeza = temp->siguiente;
                }
            } else {
                anterior->siguiente = actual->siguiente;
                delete actual;
            }
            return;
        }
        anterior = actual;
        actual = actual->siguiente;
    } while (actual != cabeza);
}
```
### Ejemplo completo
Puedes ver un ejemplo completo de la implementación de listas simples circulares en este [repositorio lista circular simplemente enlazada](https://github.com/meaguilar/meaguilar.github.io/blob/main/PED/RepoLaboratorios/Listas/ListasSimplesCirculares.cc).

## Listas circulares doblemente enlazadas
Una **lista circular doblemente enlazada** es una estructura de datos dinámica en la que cada nodo tiene dos punteros: uno que apunta al siguiente nodo y otro que apunta al anterior. La principal diferencia con las listas doblemente enlazadas tradicionales es que el último nodo está conectado al primero y viceversa, formando un ciclo cerrado.
![enter image description here](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/refs/heads/main/PED/Imagenes/CP4/Listas-circulares-doblemente-enlazadas.png)

### Características de una lista circular doblemente enlazada
- **Circularidad**: El último nodo apunta al primero y el primero apunta al último, permitiendo un recorrido continuo en ambas direcciones.
-   **Punteros dobles**: Cada nodo tiene un puntero al siguiente y otro al anterior nodo.
-   **Recorrido bidireccional**: Se puede recorrer la lista tanto hacia adelante como hacia atrás.

### Nodos en una lista circular doblemente enlazada
Así como las listas doblemente enlazadas, las listas circulares doblemente enlazadas se definen de la misma manera, un nodo tiene un nodo anterior y uno siguiente, lo podemos definir con la siguiente estructura:
```c++
struct Nodo {
    int dato;            // Valor almacenado en el nodo
    Nodo* siguiente;     // Puntero al siguiente nodo
    Nodo* anterior;      // Puntero al nodo anterior
};
```
### Agregar un nodo al principio
Para agregar un nuevo nodo al principio primero se verifica si la lista está vacía, de ser el caso, el nuevo nodo apunta a sí mismo tanto como siguiente como anterior. Si la lista ya contiene nodos, el nuevo nodo se conecta al nodo existente que era la cabeza y se ajustan los punteros del último nodo para mantener la circularidad.
```c++
void AgregarNodoAlPrincipio(Nodo*& cabeza, int valor) {
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->dato = valor;

    if (cabeza == nullptr) {
        nuevo_nodo->siguiente = nuevo_nodo;
        nuevo_nodo->anterior = nuevo_nodo;
        cabeza = nuevo_nodo;
    } else {
        Nodo* ultimo = cabeza->anterior;
        nuevo_nodo->siguiente = cabeza;
        nuevo_nodo->anterior = ultimo;
        cabeza->anterior = nuevo_nodo;
        ultimo->siguiente = nuevo_nodo;
        cabeza = nuevo_nodo;
    }
}
```
### Agregar un nodo al final
En este caso, cumple lo mismo si solo es un nodo, pero, si la lista ya tiene nodos, el nuevo nodo se conecta al último nodo existente y se ajustan los punteros para mantener la circularidad.
```c++
void AgregarNodoAlFinal(Nodo*& cabeza, int valor) {
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->dato = valor;

    if (cabeza == nullptr) {
        nuevo_nodo->siguiente = nuevo_nodo;
        nuevo_nodo->anterior = nuevo_nodo;
        cabeza = nuevo_nodo;
    } else {
        Nodo* ultimo = cabeza->anterior;
        nuevo_nodo->siguiente = cabeza;
        nuevo_nodo->anterior = ultimo;
        ultimo->siguiente = nuevo_nodo;
        cabeza->anterior = nuevo_nodo;
    }
}
```
### Eliminar un nodo con un valor específico
Para eliminar un nodo de la lista circular doble, se debe localizar el nodo con el valor deseado. Una vez encontrado, se ajustan los punteros del nodo anterior y del siguiente para que el nodo sea excluido de la lista. Si el nodo a eliminar es la cabeza, se actualiza la referencia de la cabeza.
```c++
void EliminarNodo(Nodo*& cabeza, int valor) {
    if (cabeza == nullptr) return;

    Nodo* actual = cabeza;

    do {
        if (actual->dato == valor) {
            if (actual == cabeza && actual->siguiente == cabeza) {
                delete actual;
                cabeza = nullptr;
                return;
            }

            Nodo* anterior = actual->anterior;
            Nodo* siguiente = actual->siguiente;
            anterior->siguiente = siguiente;
            siguiente->anterior = anterior;

            if (actual == cabeza) {
                cabeza = siguiente;
            }

            delete actual;
            return;
        }
        actual = actual->siguiente;
    } while (actual != cabeza);
}
```
### Mostrar todos los nodos
Para recorrer y mostrar todos los nodos, se comienza desde la cabeza y sigue recorriendo los nodos en dirección hacia adelante. Dado que es una lista circular, el bucle se detiene cuando vuelve a la cabeza.
```c++
void MostrarLista(Nodo* cabeza) {
    if (cabeza == nullptr) {
        std::cout << "La lista está vacía" << std::endl;
        return;
    }

    Nodo* actual = cabeza;
    do {
        std::cout << actual->dato << " <-> ";
        actual = actual->siguiente;
    } while (actual != cabeza);
}
```

### Ejemplo completo
Puedes ver un ejemplo completo de la implementación de listas dobles circulares en este [repositorio lista circular doblemente enlazada](https://github.com/meaguilar/meaguilar.github.io/blob/main/PED/RepoLaboratorios/Listas/ListasDoblesCirculares.cc).

## Ventajas de las listas enlazadas
Cada tipo de lista ofrece diferentes ventajas: las **listas enlazadas simples** son fáciles de implementar y permiten una gestión básica de datos, mientras que las **listas doblemente enlazadas** facilitan el recorrido bidireccional. Por otro lado, las **listas circulares** son ideales para aplicaciones donde se requiere un recorrido continuo y cíclico de los datos.

Las listas enlazadas, aunque ofrecen muchas ventajas, también presentan algunas desventajas importantes en comparación con otras estructuras de datos, como los arreglos, por ejemplo **en el uso de la memoria** y sobre todo sobre su complejidad y conocimiento sobre punteros, ya que si los punteros no se gestionan correctamente, puede haber errores como pérdida de memoria o acceso a punteros inválidos.

## buenas prácticas con punteros en listas dinámicas

-   **Uso de `new` y `delete`**    
    -   Sirven para reservar y liberar memoria dinámica.
    -   Cada `new` debe tener un `delete` correspondiente.
    -   **Riesgo**: olvidarlos produce fugas de memoria.

-   **Mejor usar punteros inteligentes (`std::unique_ptr`, `std::shared_ptr`)**
    -   Liberan memoria automáticamente.
    -   Evitan fugas y dobles liberaciones.
    -   Para listas: normalmente `std::unique_ptr` es suficiente.
        
-   **Gestión de memoria**
    -   Define claramente qué puntero es el **dueño** del nodo.
    -   Usa RAII (Resource Acquisition Is Initialization): la memoria se libera cuando el objeto deja de existir.
    -   Evita punteros colgantes: nunca uses un puntero después de `delete`.
       
-   **Uso de `next` y `prev`**
    -   En **lista simple**: solo `next` para enlazar al siguiente nodo.
    -   En **lista doble**: `next` apunta al siguiente y `prev` al anterior.
    -   Cuida mantenerlos coherentes al insertar/eliminar.
        
-   **Uso de `nullptr`**
    -   Inicializa todos los punteros en `nullptr` en lugar de valores basura.
    -   Verifica siempre `if (ptr != nullptr)` antes de usar.
    -   Evita errores como acceso a memoria inválida.
        
-   **Inserción y eliminación**
    -   Al insertar: crea el nodo, ajusta enlaces (`next`/`prev`) y recién conecta.
    -   Al eliminar: cambia enlaces primero, luego libera la memoria.

## Referencias
Puedes leer más sobre las listas enlazadas, te recomendamos los siguientes enlaces que puedes visitar para entender un poco más sobre como funcionan.

https://conclase.net/c/edd/cap4
https://youtu.be/15urP2LmfqY?si=Xfad9_-OtewdvhqO

