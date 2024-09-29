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

![Bubble Sort Algorithm in Java | Visualization and Examples](https://www.swtestacademy.com/wp-content/uploads/2021/11/bubble-sort-animation-swtestacademy-bg.gif)

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

![Selection Sort Algorithm in Java | Visualization and Examples](https://www.swtestacademy.com/wp-content/uploads/2021/11/selection-sort-amination.gif)

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

![Insertion Sort Algorithm in Java | Visualization and Examples](https://www.swtestacademy.com/wp-content/uploads/2021/11/insertion-sort.gif)

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
 Puedes ver un ejemplo de todos los algoritmos de ordenamiento en este [repositorio](https://github.com/German234/LaboratoriosPED.github.io/blob/3acf90416ffa969de51863d879bc8ee1c1d9c5c6/Laboratorio-07/AlgoritmosOrdenamiento.cc).
 
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

![Linear Search Algorithm](https://www.tutorialspoint.com/data_structures_algorithms/images/linear_search.gif)

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

![Binary Search | Brilliant Math & Science Wiki](https://d18l82el6cdm1i.cloudfront.net/uploads/bePceUMnSG-binary_search_gif.gif)

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
 Puedes ver un ejemplo de todos los algoritmos de ordenamiento en este [repositorio](https://github.com/German234/LaboratoriosPED.github.io/blob/3acf90416ffa969de51863d879bc8ee1c1d9c5c6/Laboratorio-07/AlgoritmosBusqueda.cc).
 
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

## Anexos

### Visualgo

[Visualgo](https://visualgo.net/en/sorting) es una herramienta interactiva y visual que ayuda a entender y simular diferentes algoritmos de búsqueda, ordenamiento, y estructuras de datos. 

###  Cplusplus
[Cplusplus](https://cplusplus.com/reference/algorithm/) contiene la referencia de la libreria `algorithm`
