# Punteros

En este laboratorio aprenderás sobre el uso de punteros, cómo declararlos, cómo utilizarlos, y su importancia en la gestión de memoria y manipulación de datos en programación.

### ¿Qué son los punteros?

En tu computadora, cada variable que tu guardas, en realidad el valor de esa variable se guarda en **una dirección de memoria**. La dirección de memoria es el **lugar físico** donde la memoria **está** siendo guardada. Los punteros, van a permitirnos almacenar la dirección de memoria de cualquier variable y nos permitirán manipularla.

Como tal, una variable tiene 3 características fundamentales:

- **Su valor** 
- **Su nombre** 
- **Dirección de memoria**

Entonces, a simple modo podemos decir que un puntero es como un tipo especial de variable, que tiene las características que mencionamos anteriormente, como todas las variables, con la única **diferencia** que su valor no será un dato como tal, si no que era una dirección de memoria que esta **apuntando** a otro objeto (int, float, chat).

Entonces los punteros nos servirán para acceder a esos objetos a los cuales apuntan, es decir, hacer referencia a ellos usando su dirección de memoria. Ahora, si tu un puntero no lo inicializas bien, va a apuntar a una direccion de memoria **no valida**.

## Escenario

Imagina que tienes un documento llamado **“informe.docx”**.

![enter image description here](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/refs/heads/main/PED/Imagenes/CP4/B.png)

| Caso 1: Archivo en tu computadora (local, sin Internet) | Caso 2: Archivo en OneDrive (en la nube, con Internet) |
|---------------------------------------------------------|--------------------------------------------------------|
| - Tienes el archivo directamente en tu escritorio.      | - No tienes el archivo físicamente en tu escritorio.    |
| - Lo abres con Word, haces cambios y lo guardas.        | - Tienes un **enlace (dirección URL)** que apunta al archivo en OneDrive. |
| - Estás **trabajando sobre el archivo original**.       | - Abres ese enlace y estás **trabajando a través de un puntero (dirección en la nube)**. |
| Esto se parece a una **referencia (`&`)** en C++        | Esto se parece a un **puntero (`*`)** en C++           |
| - Es un acceso **directo** al recurso.                  | - No tienes el archivo en sí, sino la **dirección**.    |
| - No necesitas intermediarios.                          | - Usas esa dirección para llegar hasta el archivo.      |
| - Si lo cambias, se modifica de inmediato el archivo.   | - Si la dirección está mal → sería como un `nullptr`.   |

### Ejemplo de definición de puntero
```c++
int a = 42; 
int* p = &a; 
```
### ¿Qué significan el `*` y el `&` en los punteros?
Cuando trabajamos con punteros, es esencial entender el significado de los operadores `*` y `&` porque son clave para manipular direcciones de memoria y valores.

### El operador `&`: Operador de Referencia

El **ampersand (`&`)** se utiliza para obtener la **dirección de memoria** de una variable. Este proceso se llama **referenciar** una variable.
 
 #### Ejemplo:
 ```c++
int a = 10;
int* p = &a;
 ```

Aquí, `p` es un puntero que almacena la **dirección de memoria** de la variable `a`. En este caso, `&a` proporciona la dirección donde `a` está almacenada en la memoria.

### El operador `*`: Operador de Desreferencia
El asterisco (`*`) se utiliza para acceder al **valor** almacenado en la dirección de memoria que el puntero contiene. Este proceso se llama **desreferenciar** un puntero.

```c++
#include  <iostream>
int  a  =  10;
int*  p  =  &a;

int  main()  {
	std::cout  <<  "Valor de a: "  <<  a  << std::endl;
	std::cout  <<  "Dirección de a: "  <<  &a  <<std::endl;
	std::cout  <<  "Valor de p: "  <<  p  << std::endl;
	std::cout  <<  "Valor de *p: "  <<  *p  << std::endl;
	std::cout  <<  "Dirección de p: "  <<  &p  << std::endl;
	return  0;
} 
```
```bash
Valor de a: 10
Dirección de a: 0x59db2d50c010
Valor de p: 0x59db2d50c010
Valor de *p: 10
Dirección de p: 0x59db2d50c018
```
En este ejemplo, `*p` accede al **valor** almacenado en la dirección de memoria a la que `p` apunta, es decir, el valor de `a`. La expresión `*p` es equivalente a acceder directamente a `a`.



## Punteros en parámetros

#### Paso por valor y por referencia

![enter image description here](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/refs/heads/main/PED/Imagenes/CP2/CP2-A.gif)


Uno de los mejores usos de los punteros es que nos permite optimizar nuestro programa. Y un ejemplo muy claro, es en las funciones.

En los laboratorios anteriores estudiamos que los parámetros los podemos pasar a una función por **por valor**, al hacerlo estamos dando a la función una **copia del valor original**. Esto significa que cualquier cambio que la función haga en ese valor **no afectará** al valor original fuera de la función.

#### Ejemplo de función con parametros por valor
```c++
#include <iostream>

void Sumar(int x, int y) {
  x += 10;
  y += 10;
  std::cout << "Dentro de la función: x = " << x 
       << ", y = " << y << std::endl;
}

int main() {
  int a = 5;
  int b = 3;
  Sumar(a, b);
  std::cout << "Fuera de la función: a = " << a 
       << ", b = " << b << std::endl;
  return 0;
}
```
```bash
Dentro de la función: x = 15, y = 13
Fuera de la función: a = 5, b = 3
```
Por otro lado, cuando pasamos un parámetro **por referencia**, le estamos dando a la función acceso directo al valor original mediante su dirección de memoria. Esto significa que cualquier cambio que la función haga **sí afectará** al valor original fuera de la función.

#### Ejemplo de función con parametros por referencia
```c++
#include <iostream>

void SumarPorReferencia(int& x, int& y) {
  x += 10;
  y += 10;
  std::cout << "Dentro de la función: x = " << x 
       << ", y = " << y << std::endl;
}

int main() {
  int a = 5;
  int b = 3;
  SumarPorReferencia(a, b);
  std::cout << "Fuera de la función: a = " << a << 
	   ", b = " << b << std::endl;
  return 0;
}
```
```bash
Dentro de la función: x = 15, y = 13
Fuera de la función: a = 15, b = 13
```

## Punteros en arreglos
En C++, los **arreglos** y los **punteros** están estrechamente relacionados. Un arreglo es básicamente una secuencia contigua de elementos almacenados en la memoria, y el **nombre del arreglo** es en realidad un **puntero** que apunta a la dirección de memoria del primer elemento del arreglo.

Por lo tanto, no es necesario usar el operador `&` para obtener la dirección del primer elemento del arreglo, ya que el nombre del arreglo ya es un puntero.
```c++
#include <iostream>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int* p = arr;
    std::cout << "Primer elemento (usando puntero): " << *p << std::endl;
    std::cout << "Segundo elemento (usando puntero + indice): " 
	     << *(p + 1) << std::endl;
    return 0;
}
```
```bash
Primer elemento (usando puntero): 10
Segundo elemento (usando puntero + indice): 20
```
El uso de punteros permite que las funciones puedan trabajar con arreglos sin tener que pasar copias de los datos, lo que ahorra memoria y tiempo de ejecución.

- **Ejemplo con array clásico**
```c++
#include <iostream>

void imprimirArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << *(arr + i) << " "; // equivalente a arr[i]
        // se aplica la aritmética de punteros para recorrer el arreglo * + índice
    }
}

int main() {
    int numeros[] = {10, 20, 30, 40, 50};
    // Calcular el tamaño del array
    int size = sizeof(numeros) / sizeof(numeros[0]);
    std::cout << "Array con punteros: ";
    imprimirArray(numeros, size);
    return 0;
}
```
```
Array con punteros: 10 20 30 40 50
```
- **Ejemplo con `std::vector`**
```c++
#include <iostream>
#include <vector>

void imprimirVector(const std::vector<int>& vec) {
    // Accediendo con puntero al primer elemento
    const int* ptr = vec.data(); // devuelve un puntero al arreglo interno
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << *(ptr + i) << " "; // equivalente a vec[i]
        // se aplica la aritmética de punteros para recorrer el arreglo * + indice
    }
}

int main() {
    std::vector<int> numeros = {5, 15, 25, 35, 45};
    std::cout << "Vector con punteros: ";
    imprimirVector(numeros);
    return 0;
}
```
```
Vector con punteros: 5 15 25 35 45
```
## Arreglos, punteros y funciones.
Cuando se pasa un arreglo a una función, en realidad lo que se está pasando es un **puntero** que apunta al primer elemento del arreglo. Esto se debe a que los arreglos son tratados como punteros cuando se pasan a funciones, permitiendo acceder y manipular directamente los elementos del arreglo.

```c++
#include <iostream>

// Función que recibe un puntero a un arreglo y su tamaño
void ModificarArreglo(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] += 10;  // Modifica cada elemento sumando 10
    }
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};  // Arreglo original
    // Llamada a la función, pasando el arreglo y su tamaño
    ModificarArreglo(arr, 5);
    // Mostrar los valores modificados
    for (int i = 0; i < 5; ++i) {
        std::cout << "Elemento " << i + 1 << ": " << arr[i] << std::endl;
    }
    return 0;
}
```
En la función `ModificarArreglo`, se recorre el arreglo y se le suma 10 a cada elemento. Esto modifica los elementos directamente en el arreglo original `arr` del `main` porque hemos pasado un puntero al arreglo.

La modificación es visible en el `main` después de la llamada a la función, ya que se trabaja sobre la misma ubicación de memoria.

## ¿Cuándo usar cada uno?

-   **Referencia (`&`)**
    
    -   Cuando siempre debe existir un valor.
        
    -   Para pasar parámetros sin copiar.
        
    -   Para modificar argumentos de una función.
        
-   **Puntero (`*`)**
    
    -   Cuando puede no existir el valor (opcional).
        
    -   Para manejar arreglos dinámicos.
        
    -   En estructuras de bajo nivel.
        
    -   Cuando se necesita cambiar a qué objeto apunta.

## Buenas practicas de uso de Referencia  `&` y Punteros `*`

**Paso por referencia (`&`)**
El paso por referencia (`&`) permite que una función modifique directamente la variable que recibe.
- Usar `const &` cuando no necesitas modificar el valor.
	-   Evita copias innecesarias en parámetros grandes (strings, vectores, objetos).
	```c++
	void imprimir(const std::string& texto) {
    std::cout << texto << std::endl;
	}
	```
- Usar `&` cuando quieres modificar la variable.
	```c++
	void incrementar(int& numero) {
	    numero++;
	}
	```
- Preferir referencias sobre punteros cuando sea posible.

**Punteros (`*`)**
Los punteros permiten trabajar con direcciones de memoria.

- Inicializar punteros siempre.

- Liberar memoria asignada dinámicamente.

- Evitar el uso innecesario de punteros crudos.





