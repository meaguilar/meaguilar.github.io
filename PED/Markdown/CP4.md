
# Punteros
En este laboratorio aprenderás sobre el uso de punteros, cómo declararlos, cómo utilizarlos, y su importancia en la gestión de memoria y manipulación de datos en programación.

### ¿Qué son los punteros?

En tu computadora, cada variable que tu guardas, en realidad el valor de esa variable se guarda en **una dirección de memoria**. Los punteros, van a permitirnos almacenar la dirección de memoria de cualquier variable y nos permitirán manipularla.


Como tal, una variable tiene 3 características fundamentales:

- **Su valor** 
- **Su nombre** 
- **Dirección de memoria**

La dirección de memoria es el **lugar fisico** donde la memoria esta siendo guardada.

Entonces, a simple modo podemos decir que un puntero es como un tipo especial de variable, que tiene las características que mencionamos anteriormente, como todas las variables, con la única **diferencia** que su valor no será un dato como tal, si no que era una dirección de memoria que esta **apuntando** a otro objeto (int, float, chat).

Entonces los punteros nos servirán para acceder a esos objetos a los cuales apuntan, es decir, hacer referencia a ellos usando su dirección de memoria. Ahora, si tu un puntero no lo inicializas bien, va a apuntar a una direccion de memoria **no valida**.

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

int  main(int  argc,  char*  argv[])  {
	std::cout  <<  "Valor de a: "  <<  a  << std::endl;
	std::cout  <<  "Dirección de a: "  <<  &a  <<std::endl;
	std::cout  <<  "Valor de p: "  <<  p  << std::endl;
	std::cout  <<  "Valor de *p: "  <<  *p  << std::endl;
	std::cout  <<  "Dirección de p: "  <<  &p  << std::endl;
	return  0;
} 
```
En este ejemplo, `*p` accede al **valor** almacenado en la dirección de memoria a la que `p` apunta, es decir, el valor de `a`. La expresión `*p` es equivalente a acceder directamente a `a`.

## Punteros propietarios
Cuando un programa necesita más espacio para guardar algo grande, usa una parte especial de la memoria llamada **_heap_**. Cuando hace esto, el programa recibe una "dirección" que le dice dónde se guarda ese algo, y esa dirección se guarda en forma de puntero. Este tipo de punteros se llaman **punteros propietarios**

El problema es que, cuando terminas de usar ese espacio, el programa no lo libera automáticamente. Tú tienes que decirle al programa que lo haga, porque si no, el espacio sigue ocupado y el programa o incluso otros programas no podrán usarlo. Esto se llama **"fuga de memoria"**, porque el espacio queda atrapado sin poder ser reutilizado.

Para manejar esto, se usan dos comandos importantes: `new` para **pedir** espacio en el heap y `delete` para **liberar** ese espacio cuando ya no lo necesitas.

```c++
#include <iostream>

int main(int argc, char* argv[]) {
    int* p = new int;
    *p = 42;  

    std::cout << "Valor en el heap: " << *p << std::endl;

    delete p;  
    
    p = nullptr; 

    return 0;
}
```
En este ejemplo, hemos usado `new` para pedir espacio en el heap y almacenamos la dirección de esa memoria en el puntero `p`. Usamos `p` para almacenar el valor `42` en esa memoria.

Si no liberamos la memoria con `delete`, esa memoria sigue ocupada aunque ya no la estemos usando, lo que genera una **fuga de memoria**

### ¿Que es nullptr?
`nullptr` es un valor especial en C++ que representa un puntero que **no apunta a ninguna dirección de memoria válida**. En otras palabras, es una forma de inicializar o restablecer un puntero para indicar que **no tiene un objeto o memoria a la cual apuntar**.

Después de liberar la memoria con `delete`, es buena práctica asignar `nullptr` al puntero. Esto ayuda a evitar que el puntero siga apuntando a una ubicación de memoria que ya no es válida (puntero colgante).

## Punteros en parámetros

#### Paso por valor y por referencia
Uno de los mejores usos de los punteros es que nos permite optimizar nuestro programa. Y un ejemplo muy claro, es en las funciones.

En los laboratorios anteriores vimos que los parámetros los podemos pasar a una función por **por valor**, al hacerlo estamos dando a la función una **copia del valor original**. Esto significa que cualquier cambio que la función haga en ese valor **no afectará** al valor original fuera de la función.

#### Ejemplo de función con parametros por valor
```c++
#include <iostream>

void Sumar(int x, int y) {
  x += 10;
  y += 10;
  std::cout << "Dentro de la función: x = " << x 
            << ", y = " << y << std::endl;
}

int main(int argc, char* argv[]) {
  int a = 5;
  int b = 3;

  Sumar(a, b);

  std::cout << "Fuera de la función: a = " << a 
            << ", b = " << b << std::endl;

  return 0;
}
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

int main(int argc, char* argv[]) {
  int a = 5;
  int b = 3;

  SumarPorReferencia(a, b);

  std::cout << "Fuera de la función: a = " << a 
            << ", b = " << b << std::endl;

  return 0;
}

```

![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXc7MKyKN-EU3Zl3Ow5J_iq_VmB7bKNq1HOjUhy6yTTnj6RmHP9H4OYZvZrE18oToHvF8SCrq_zT2Dl8I0dlw_1aGOW1ScUkAL-NadMddpMCF5bZ2TyTYY-Hr_EDfvBIoDxXi9nwUp_Tx1Z1uMyfDUhKGj2U4n7E3zqELe1wet_ZqCBctADggnI?key=Ebc5RBD3qg94hAq1Y-1isQ)**
## Punteros en arreglos
En C++, los **arreglos** y los **punteros** están estrechamente relacionados. Un arreglo es básicamente una secuencia contigua de elementos almacenados en la memoria, y el **nombre del arreglo** es en realidad un **puntero** que apunta a la dirección de memoria del primer elemento del arreglo.

Por lo tanto, no es necesario usar el operador `&` para obtener la dirección del primer elemento del arreglo, ya que el nombre del arreglo ya es un puntero.
```c++
#include <iostream>

int main(int argc, char* argv[]) {
    int arr[5] = {10, 20, 30, 40, 50};

    int* p = arr;

    std::cout << "Primer elemento (usando puntero): " << *p << std::endl;

    std::cout << "Segundo elemento : " << *(p + 1) << std::endl;

    return 0;
}
```
El uso de punteros permite que las funciones puedan trabajar con arreglos sin tener que pasar copias de los datos, lo que ahorra memoria y tiempo de ejecución.

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

int main(int argc, char* argv[]) {
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

## Importancia de los Punteros en la Gestión de Memoria y Manipulación de Datos

Los punteros juegan un papel fundamental en la **gestión eficiente de la memoria** y en la **manipulación de datos** dentro de la programación. 

En muchas aplicaciones, no siempre sabemos cuánta memoria será necesaria durante la ejecución del programa. Los punteros nos permiten **asignar y liberar memoria dinámica** de manera manual, lo cual es crucial para gestionar correctamente los recursos en programas que requieren mucha memoria o cuya cantidad de datos no es fija.

Al usar punteros, es posible **optimizar el rendimiento** del programa al reducir el uso de memoria y permitir un acceso más rápido a los datos

