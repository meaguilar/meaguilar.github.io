
# Algoritmos de Ordenamiento y Búsqueda

En este laboratorio estudiaremos los algoritmos de ordenamiento y búsqueda, su complejidad, el uso de la librería estándar de C++ (STL).

# Algoritmos de ordenamiento

Los **algoritmos de ordenamiento** organizan los elementos de una colección según un criterio definido (ascendente o descendente) para facilitar su procesamiento y optimizar las operaciones posteriores de búsqueda.

![BubbleSort](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/refs/heads/main/PED/Imagenes/CP4/A.png)

## Ordenamiento Burbuja (Bubble Sort)

Compara pares de elementos adyacentes y los intercambia si están en el orden incorrecto, haciendo que en cada recorrido el elemento mayor "flote" hacia el final del arreglo hasta que no se requieran más intercambios.

- **Complejidad temporal:** $O(n^2)$ en el caso promedio y peor; $O(n)$ en el mejor caso (arreglo ya ordenado).
- **Espacio de memoria:** $O(1)$ (ordenamiento *in-place*, solo utiliza una variable temporal auxiliar).



```c++
void BubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
```

## Ordenamiento por Selección (Selection Sort)

Busca repetidamente el elemento mínimo de la sección no ordenada del arreglo y lo intercambia con el primer elemento de dicha sección, expandiendo progresivamente la parte ordenada.

- **Complejidad temporal:** $O(n^2)$ en el mejor, promedio y peor caso.
- **Espacio de memoria:** $O(1)$ (ordenamiento *in-place*).



```c++
void SelectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) min_idx = j;
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}
```

## Ordenamiento por Inserción (Insertion Sort)

Divide virtualmente el arreglo en una parte ordenada y otra no ordenada; toma cada elemento de la parte no ordenada y desplaza los elementos mayores hacia la derecha para insertarlo en su posición correcta.

- **Complejidad temporal:** $O(n^2)$ en el caso promedio y peor; $O(n)$ en el mejor caso (arreglo casi o totalmente ordenado).
- **Espacio de memoria:** $O(1)$ (ordenamiento *in-place*).



```c++
void InsertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
```


## Ordenamiento usando la librería de C++

### ¿Qué es la implementación con STL?

La **STL (Standard Template Library)** es la biblioteca de plantillas estándar de C++ que proporciona contenedores genéricos (como `std::list` o `std::vector`), iteradores y funciones optimizadas en la cabecera `<algorithm>`. En lugar de programar algoritmos desde cero, la STL permite operar sobre estructuras personalizadas (como un `struct Estudiante`) mediante predicados o funciones *lambda*:

- **`sort`:** Ordena los elementos dividiendo el problema logarítmicamente (con profundidad de partición $\log(n)$ y complejidad total $O(n \log n)$). En `std::list` se invoca como método miembro `lista.sort(...)` porque las listas enlazadas no tienen acceso aleatorio.

### Ordenar una lista de `Estudiante` con `sort`

```c++
#include <list>
#include <string>

struct Estudiante {
    std::string nombre;
    int edad;
};

void ordenarPorEdad(std::list<Estudiante>& lista) {
    // Ordena de menor a mayor edad usando una expresión lambda
    lista.sort([](const Estudiante& a, const Estudiante& b) {
        return a.edad < b.edad;
    });
}
```

# Algoritmos de búsqueda

Los **algoritmos de búsqueda** permiten localizar un elemento específico dentro de una estructura de datos (como un arreglo o una lista) y determinar su posición o confirmar su existencia de manera eficiente.

![Search](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/refs/heads/main/PED/Imagenes/CP4/B.png)
## Búsqueda Lineal (Linear Search)

Recorre secuencialmente la colección desde el primer hasta el último elemento comparando cada valor con la clave buscada. No requiere que los datos estén previamente ordenados.

- **Complejidad temporal:** $O(n)$ en el caso promedio y peor; $O(1)$ en el mejor caso (si el elemento está al inicio).
- **Espacio de memoria:** $O(1)$.



```c++
int LinearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) return i;
    }
    return -1;
}
```

## Búsqueda Binaria (Binary Search)

Compara el valor buscado con el elemento central del arreglo y descarta la mitad en la que el elemento no puede encontrarse, repitiendo la división hasta hallar el dato o vaciar el rango.

- **Ordenamiento basado en su búsqueda:** La búsqueda binaria **exige que los datos estén previamente ordenados** bajo el mismo criterio de comparación. Si el conjunto está desordenado, primero debe aplicarse un algoritmo de ordenamiento (por ejemplo, `std::sort` en $O(n \log n)$) antes de ejecutar la búsqueda binaria.
- **Complejidad temporal:** $O(\log n)$ en el caso promedio y peor; $O(1)$ en el mejor caso.
- **Espacio de memoria:** $O(1)$ en su versión iterativa.



```c++
#include <algorithm>

int BinarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) return mid;
        if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

// Ordenar antes de buscar:
// std::sort(arr, arr + n);
// int pos = BinarySearch(arr, 0, n - 1, clave);
```

## Búsqueda usando la librería de C++

La cabecera `<algorithm>` de la STL ofrece funciones listas para realizar tanto búsquedas lineales como búsquedas binarias sobre cualquier rango de iteradores `[inicio, fin)`:

```c++
#include <algorithm> // Librería necesaria para find_if, binary_search y lower_bound
#include <iostream>
```

### 1. Búsqueda lineal con `std::find_if` ($O(n)$)

- **`std::find_if(inicio, fin, predicado)`:** Recorre secuencialmente un rango `[inicio, fin)` sin exigir orden previo y devuelve un iterador al primer elemento que cumple una condición booleana (como una función anónima *lambda*), con una complejidad lineal de **$O(n)$**.

```c++
#include <algorithm>
#include <list>
#include <string>

auto buscarEstudiante(const std::list<Estudiante>& lista, const std::string& nombreBuscado) {
    // Recorre la lista en O(n) hasta encontrar la coincidencia
    return std::find_if(lista.begin(), lista.end(), [&](const Estudiante& e) {
        return e.nombre == nombreBuscado;
    });
}
```

### 2. Búsqueda binaria con `std::binary_search` y `std::lower_bound` ($O(\log n)$)

- **`std::binary_search(inicio, fin, clave)`:** Devuelve `true` o `false` indicando si el elemento existe en un rango **previamente ordenado** en tiempo $O(\log n)$.
- **`std::lower_bound(inicio, fin, clave)`:** Devuelve un iterador al primer elemento mayor o igual a la clave dentro de un rango **ordenado** en tiempo $O(\log n)$.

```c++
int arr[] = {11, 12, 22, 25, 34, 64, 90};
int n = sizeof(arr) / sizeof(arr[0]);

// Verifica en O(log n) si el número 22 está en el arreglo ordenado
bool encontrado = std::binary_search(arr, arr + n, 22);
```

## Ejemplo
[Ver ejemplo de registro y búsqueda de estudiantes](https://github.com/meaguilar/PED-Clases/tree/main/EjerciciosLaboratorios/Laboratorio-4)

## Anexos

- [Sorting (Bubble, Selection, Insertion, Merge, Quick, Counting, Radix) - VisuAlgo](https://www.google.com/search?q=https%3A%2F%2Fvisualgo.net%2Fen%2Fsorting)
- [Referencia de la librería \<algorithm\> - cplusplus.com](https://www.google.com/search?q=https%3A%2F%2Fcplusplus.com%2Freference%2Falgorithm%2F)
- [Bubble Sort \| Sorting Algorithm \| Code Pumpkin](https://www.google.com/search?q=https%3A%2F%2Fcodepumpkin.com%2Fbubble-sort%2F)
- [Bubble Sort Algorithm in Java \| Visualization and Examples](https://www.google.com/search?q=https%3A%2F%2Fswtestacademy.com%2Fbubble-sort-algorithm-java-visualization-examples%2F)
- [Insertion Sort Algorithm in Java \| Visualization and Examples](https://www.google.com/search?q=https%3A%2F%2Fswtestacademy.com%2Finsertion-sort-algorithm-java-visualization-examples%2F)
- [Selection Sort Algorithm in Java \| Visualization and Examples](https://www.google.com/search?q=https%3A%2F%2Fswtestacademy.com%2Fselection-sort-algorithm-java-visualization-examples%2F)
