# Algoritmos de Ordenamiento y Búsqueda

En este laboratorio estudiaremos sobre el uso de algoritmos de ordenamiento y búsqueda, cómo declararlos, utilizarlos, y su importancia en la organización y manipulación de datos en la programación.

# Algoritmos de ordenamiento
Los **algoritmos de ordenamiento** son técnicas utilizadas en programación para organizar los elementos de una lista o conjunto de datos según un criterio, como el orden ascendente o descendente. Estos algoritmos son esenciales cuando se necesita organizar datos de manera eficiente, ya sea números, palabras o cualquier tipo de información que deba seguir un orden.

## Ordenamiento Burbuja (Bubble Sort)

El **algoritmo de ordenamiento burbuja** es una forma básica de organizar una lista de elementos. Lo que hace es revisar cada par de elementos adyacentes y, si están en el orden incorrecto, intercambiarlos.

### ¿Cómo funciona?
1)   Se comparan los dos primeros elementos de la lista. Si el primero debería ir después del segundo, los cambia de lugar.
2)  Luego pasa al siguiente par de elementos y hace lo mismo, repitiendo el proceso hasta llegar al final de la lista.
3) Al final de cada recorrido, el número más grande "sube" o "flota" hasta el final de la lista, como una burbuja.
3) Este proceso se repite varias veces hasta que ya no haya necesidad de hacer más cambios, lo que significa que la lista está ordenada.

![bubble-sort-animation](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/refs/heads/main/PED/Imagenes/CP6/bubble-sort-animation.gif)

### Implementación de Bubble Sort
```c++
void BubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Intercambiar arr[j] y arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
```

## Ordenamiento por Selección (Selection Sort)
El **Selection Sort** (ordenamiento por selección) es un algoritmo de ordenamiento sencillo, pero no tan eficiente en términos de tiempo cuando se trabaja con conjuntos de datos grandes. La idea principal de este algoritmo es seleccionar repetidamente el **mínimo**  o **maximo** elemento de la parte no ordenada del arreglo y colocarlo en su posición correcta.

![selection-sort-animation](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/refs/heads/main/PED/Imagenes/CP6/selection-sort-animation.gif)

### Implementación del Selection Sort
```c++
void SelectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Intercambiar el elemento más pequeño con el primero
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}
```
## Ordenamiento por Inserción (Insertion Sort)
El **Insertion Sort** (ordenamiento por inserción) es un algoritmo de ordenamiento simple pero eficiente cuando se trabaja con arreglos pequeños o parcialmente ordenados. La idea detrás de este algoritmo es que los elementos del arreglo se dividen en dos partes: una parte ordenada y una parte no ordenada. Se van tomando elementos de la parte no ordenada uno por uno e insertándolos en la posición correcta dentro de la parte ordenada.

### ¿Cómo funciona?
1)   **Iniciar con el primer elemento**: Se **asume** que el primer elemento del arreglo está en la parte ordenada, ya que un solo elemento ya está ordenado por definición.
    
2)   **Tomar el siguiente elemento**: A partir del segundo elemento, el algoritmo selecciona el elemento actual de la parte no ordenada y busca la posición correcta en la parte ordenada.
    
   3)  **Mover elementos mayores hacia la derecha**: Para encontrar la posición correcta, los elementos mayores de la parte ordenada se desplazan hacia la derecha para hacer espacio para el nuevo elemento.
    
4)  **Insertar el nuevo elemento**: Una vez que se encuentra la posición correcta, el elemento se inserta en esa posición.
    
5)  **Repetir el proceso**: El proceso se repite para todos los elementos hasta que toda la lista esté ordenada.

![insertion-sort-animation](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/refs/heads/main/PED/Imagenes/CP6/insertion-sort-animation.gif)

### Implementación de Insertion Sort
```c++
void InsertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
```

 ### Ejemplo Completo de Algoritmos de Ordenamiento
 Puedes ver un ejemplo de todos los algoritmos de ordenamiento en este [Repositorio - Algoritmos de Ordenamiento](https://github.com/UCASV/RecursosExtraPED/blob/main/SortYBinarySearch/AlgoritmosOrdenamiento.cc)
 
## Ordenamiento usando la librería de C++
La librería estándar de C++ provee algoritmos eficientes para el ordenamiento de datos. El algoritmo más común para ordenar datos es `std::sort`, el cual se encuentra en la cabecera `<algorithm>`.

### Uso de `std::sort`

`std::sort` es una función que implementa algoritmos optimizados para ordenamiento, como **QuickSort** y **HeapSort** ofreciendo un rendimiento más optimo.

```c++
#include <algorithm>
#include <iostream>

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::sort(arr, arr + n);

    std::cout << "Arreglo ordenado: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    return 0;
}
```
En este ejemplo, `std::sort` ordena el arreglo de enteros en orden ascendente. Solo necesitas darle el rango de elementos que quieres ordenar. `arr` es el primer elemento del arreglo, y `arr + n` indica la posición justo después del último elemento. 

En C++, los rangos son **[primero, último)**, lo que significa que el primer valor se incluye, pero el último no. Por eso, `arr + n` apunta justo después del último elemento, indicando el final del rango a ordenar.. Como resultado, `std::sort` ordena todos los elementos desde el principio hasta el final del arreglo.

# Algoritmos de búsqueda

Los **algoritmos de búsqueda** son métodos usados en programación para encontrar un elemento específico dentro de un conjunto de datos, como una lista o un arreglo. Son esenciales cuando se necesita localizar rápidamente un dato en particular, especialmente en grandes volúmenes de información.

## Búsqueda Lineal (Linear Search)

La **búsqueda lineal** es el algoritmo más simple de todos. Consiste en recorrer una lista de datos desde el primer hasta el último elemento, comparando cada uno con el valor que estamos buscando. Si encuentra el valor, la búsqueda termina; si no lo encuentra después de recorrer todos los elementos, devuelve un valor que indica que no se encontró el elemento.

### ¿Cómo funciona?

1.  **Inicio en el primer elemento**: Comenzamos desde el primer elemento de la lista.
2.  **Comparación**: Comparamos el valor del elemento actual con el valor que estamos buscando.
3.  **Encontrar o seguir buscando**:
    -   Si el valor es igual al buscado, se devuelve el índice de ese elemento.
    -   Si no es igual, se avanza al siguiente elemento y se repite el proceso.
4.  **Finalizar la búsqueda**: Si se recorren todos los elementos sin encontrar una coincidencia, el valor no está presente en la lista.

![linear_search](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/refs/heads/main/PED/Imagenes/CP6/linear_search.gif)

### Implementación de Linear Search
```c++
int LinearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;  // Devuelve el índice donde se encuentra el valor
        }
    }
    return -1;  // Si no se encuentra, devuelve -1
}
```
## Búsqueda Binaria (Binary Search)

La **búsqueda binaria** es un algoritmo mucho más eficiente que la búsqueda lineal, pero requiere que los datos estén **ordenados**. Funciona dividiendo repetidamente el espacio de búsqueda a la mitad, lo que reduce drásticamente el número de comparaciones necesarias.

### ¿Cómo funciona?

1.  **Dividir la lista**: Comienza comparando el valor buscado con el valor en el medio de la lista.
2.  **Reducir el espacio de búsqueda**:
    -   Si el valor buscado es menor que el valor en el medio, la búsqueda continúa en la mitad izquierda de la lista.
    -   Si el valor buscado es mayor, continúa en la mitad derecha.
3.  **Repetir el proceso**: El proceso de dividir a la mitad se repite hasta que se encuentra el valor o se reduce el espacio de búsqueda a cero (lo que indica que el valor no está presente).

![binary_search](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/refs/heads/main/PED/Imagenes/CP6/binary_search.gif)

### Implementación de Binary Search
```c++
int BinarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;  // Encuentra el punto medio
        
        if (arr[mid] == key) {
            return mid;  // El valor ha sido encontrado
        }
        
        if (arr[mid] < key) {
            low = mid + 1;  // El valor está en la mitad derecha
        } else {
            high = mid - 1;  // El valor está en la mitad izquierda
        }
    }
    return -1;  // El valor no está presente
}
```

 ### Ejemplo Completo de Algoritmos de Ordenamiento
 Puedes ver un ejemplo de todos los algoritmos de ordenamiento en este [Repositorio - Algoritmos de Busqueda](https://github.com/UCASV/RecursosExtraPED/blob/main/SortYBinarySearch/AlgoritmosBusqueda.cc)
 
## Busqueda usando la librería de C++
La librería estándar de C++ provee la función `std::binary_search` para realizar búsquedas de manera eficiente en arreglos **ordenados** haciendo uso del algoritmo del mismo nombre.

### Uso de `std::binary_search`
Así como se explicó anteriormente, el algoritmo `binary search` requiere que el arreglo esté previamente ordenado, por lo cual debemos proveerle un arreglo que cumpla esa caracteristica.

```c++
#include <algorithm>
#include <iostream>

int main() {
    int arr[] = {11, 12, 22, 25, 34, 64, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    int key = 22;
    bool found = std::binary_search(arr, arr + n, key);

    if (found)
        std::cout << "Elemento " << key << " encontrado en el arreglo.\n";
    else
        std::cout << "Elemento " << key << " no encontrado.\n";

    return 0;
}
```
En este ejemplo, `std::binary_search` se utiliza para verificar si el valor `22` está presente en el arreglo. Para que la función funcione correctamente, necesitamos pasarle tres parámetros: el inicio del arreglo, el final del arreglo y el valor que queremos buscar. l inicio del arreglo se indica con `arr`, y el final con `arr + n`, que apunta justo después del último elemento, asegurando que todos los valores sean considerados en la búsqueda. El tercer parámetro es el valor que estamos buscando, en este caso `22`.

Es importante recordar que la búsqueda binaria **solo funciona en arreglos ordenados**, ya que el algoritmo divide el arreglo en mitades de forma eficiente para encontrar el valor. Si el valor se encuentra, la función devuelve `true`; si no, devuelve `false`

## Estructuras de datos dinámicas lineales: Listas (std::list)

En este laboratorio estudiaremos el uso de **listas dinámicas** mediante la librería estándar de C++ `<list>`.  
Aprenderemos qué son, cómo declararlas, utilizarlas y cuáles son sus operaciones más importantes en la organización y manipulación de datos.

### ¿Qué son las Listas?

Una **lista** es una estructura de datos dinámica **lineal** que permite almacenar y acceder a elementos de forma **secuencial**, con la ventaja de poder **insertar o eliminar elementos en cualquier posición** sin necesidad de mover todos los demás.

A diferencia de los **vectores (`std::vector`)**, las listas **no almacenan los elementos de forma contigua en memoria**, sino que cada elemento está enlazado con el siguiente y el anterior, permitiendo una gestión flexible del tamaño y de las operaciones intermedias.

En C++, esta estructura se maneja fácilmente con la librería estándar **`std::list`**, que representa una **lista doblemente enlazada**.

## Inclusión de la librería `std::list`

Para usar las listas en C++, debemos incluir la librería:

```c++
#include <iostream>
#include <list>
```
### Definición de una lista

La sintaxis general para declarar una lista es la siguiente:

```c++
std::list<TipoDeDato> nombre_de_la_lista;
```

## Operaciones básicas de una lista

Una lista en C++ nos permite realizar varias operaciones fundamentales para agregar, eliminar y recorrer elementos.

-   **`push_back(valor)`** → Agrega un elemento al **final** de la lista.
   
-   **`push_front(valor)`** → Agrega un elemento al **inicio** de la lista.
    
-   **`insert(iterador, valor)`** → Inserta un elemento en una posición específica.

-   **`pop_back()`** → Elimina el último elemento.
    
-   **`pop_front()`** → Elimina el primer elemento.
    
-   **`erase(iterador)`** → Elimina el elemento en una posición específica.
    
-   **`clear()`** → Elimina todos los elementos.
    
-   **`remove(valor)`** → Elimina todos los elementos con el valor indicado.

-   **`front()`** → Devuelve una referencia al **primer elemento**.
    
-   **`back()`** → Devuelve una referencia al **último elemento**.
    
-   **`empty()`** → Devuelve `true` si la lista está vacía.
    
-   **`size()`** → Retorna la cantidad de elementos en la lista.

### Otras operaciones importantes

-   **`sort()`** → Ordena los elementos de menor a mayor.
    
-   **`reverse()`** → Invierte el orden de los elementos.
    
-   **`unique()`** → Elimina elementos consecutivos duplicados.
    
-   **`merge(otra_lista)`** → Combina dos listas **ordenadas** en una sola.
    
-   **`splice(pos, otra_lista)`** → Mueve elementos de una lista a otra sin copiarlos.

### Ejemplo completo de uso de librería `<list>`
A continuación, un ejemplo donde se aplican varias de las funciones mencionadas:

```c++
#include <iostream>
#include <list>
using namespace std;

int main() {
    // Declaramos una lista de enteros
    list<int> numeros;

    // Agregamos elementos
    numeros.push_back(10);
    numeros.push_back(20);
    numeros.push_front(5);

    cout << "Lista inicial: ";
    for (int n : numeros) cout << n << " ";
    cout << endl;

    // Insertar un elemento en una posición específica
    auto it = numeros.begin();
    ++it; // avanzamos una posición
    numeros.insert(it, 15); // insertamos 15 después del primer elemento

    cout << "Después de insertar 15: ";
    for (int n : numeros) cout << n << " ";
    cout << endl;

    // Eliminar elementos
    numeros.remove(20); // elimina el número 20
    cout << "Después de eliminar 20: ";
    for (int n : numeros) cout << n << " ";
    cout << endl;

    // Ordenar y revertir la lista
    numeros.sort();
    numeros.reverse();

    cout << "Lista ordenada y luego invertida: ";
    for (int n : numeros) cout << n << " ";
    cout << endl;

    // Tamaño y extremos
    cout << "Primer elemento: " << numeros.front() << endl;
    cout << "Último elemento: " << numeros.back() << endl;
    cout << "Total de elementos: " << numeros.size() << endl;

    // Vaciar la lista
    numeros.clear();
    if (numeros.empty()) {
        cout << "La lista está vacía." << endl;
    }

    return 0;
}
```
```
Lista inicial: 5 10 20 
Después de insertar 15: 5 15 10 20 
Después de eliminar 20: 5 15 10 
Lista ordenada y luego invertida: 15 10 5 
Primer elemento: 15
Último elemento: 5
Total de elementos: 3
La lista está vacía.
```

## Anexos

**VisuAlgo** es una herramienta interactiva y visual que ayuda a entender y simular diferentes algoritmos de búsqueda, ordenamiento, y estructuras de datos. 
[Sorting (Bubble, Selection, Insertion, Merge, Quick, Counting, Radix) - VisuAlgo](https://visualgo.net/en/sorting)

**Cplusplus** contiene la referencia de la libreria `algorithm`
[cplusplus.com/reference/algorithm/](https://cplusplus.com/reference/algorithm/)

[Bubble Sort | Sorting Algorithm | Code Pumpkin](https://codepumpkin.com/bubble-sort/)

[Bubble Sort Algorithm in Java | Visualization and Examples](https://swtestacademy.com/bubble-sort-algorithm-java-visualization-examples/)

[Insertion Sort Algorithm in Java | Visualization and Examples](https://swtestacademy.com/insertion-sort-algorithm-java-visualization-examples/)

[Selection Sort Algorithm in Java | Visualization and Examples](https://swtestacademy.com/selection-sort-algorithm-java-visualization-examples/)
