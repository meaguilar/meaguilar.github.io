﻿# Funciones y estructuras de datos estáticas.

El objetivo de este laboratorio aprenderás sobre el uso de funciones y variables estáticas, así como la implementación de estructuras de datos estáticas en C++. Además, de que el aprendas a aplicar estos conceptos en la resolución de problemas de programación.

## Funciones
En C++, una **función** es un bloque de código que realiza una tarea específica. Una función es una forma de organizar y reutilizar el código, lo que facilita la programación al dividir un problema grande en subproblemas más pequeños y manejables.

### ¿Porqué usar funciones? 

-   **Modularidad:** Las funciones permiten dividir un programa en partes más pequeñas, lo que facilita el desarrollo y mantenimiento.
-   **Reutilización:** Puedes escribir una función una vez y luego reutilizarla en diferentes partes del programa.
-   **Legibilidad:** Los programas que usan funciones suelen ser más fáciles de leer y entender.
-   **Mantenimiento:** Al modificar el comportamiento de una tarea específica, solo necesitas cambiar el código en una función, sin afectar el resto del programa.

### Sintaxis de una función
Una función en C++ se compone de varias partes clave:

1.  **Tipo de retorno:** El tipo de dato que la función devuelve (por ejemplo, `int`, `float`, `void`,  **u otro tipos de datos complejos.**). Si la función no devuelve ningún valor, se utiliza `void`.
2.  **Nombre de la función:** El identificador que se usa para llamar a la función.
3.  **Parámetros (opcional):** Los valores que se pasan a la función para que realice su tarea. Estos se declaran dentro de paréntesis.
4.  **Cuerpo de la función:** El bloque de código entre llaves `{}` que define lo que hace la función.


### Ejemplo de función
```c++
#include <iostream>

int Add(int a, int b) {
    return a + b;
}

int main(int argc, char* argv[]) {
    int x = 5;
    int y = 3;
    int result = Add(x, y);
    std::cout << "La suma de " << x << " y " << y << " es: " << result << std::endl;

    return 0;
}

```
### Declaración y Definición de Funciones
En C++, las funciones pueden declararse antes de `main()` y definirse después. Esto se conoce como **prototipo de función**.
```c++
#include <iostream>

int Add(int a, int b);

int main(int argc, char* argv[]) {
    int x = 5;
    int y = 3;
    int result = Add(x, y);
    std::cout << "La suma de " << x << " y " << y << " es: " << result << std::endl;
    return 0;
}

int Add(int a, int b) {
    return a + b;
}
```
### Parámetros de una Función
Los parámetros de una función en C++ se pueden pasar de varias formas:

- **Parámetros por valor**
Cuando los parámetros se pasan por valor, se envía una copia del valor al interior de la función. Los cambios dentro de la función no afectan las variables originales.

	**![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXfTHvn_szuVOC6MM2TtzUfzcmidjr0YVMmUVJAflk0Ffl8tF_RQE9Pzfu4DmiU9mYR7ixANUB2LxuQ5mwV1j7hBGCRfLVkX1dBL5uZeRrDFafHBX5DwK8SWrfymZ6C6LMkhLnplvCiNgIV2ujHqoO7dc_ynj6Qnii4N-Bjst8LgAAw_OsSinw?key=K9mfK9RbIhO_z31INKZxXg)**
```c++
#include  <iostream>
const  int  kInitialNumber  =  5;

int  DoubleValue(int  number) {
	return  number  *  2;
}

int  main(int  argc, char  *argv[]) {
	int  number  =  DoubleValue(kInitialNumber);
	std::cout  <<  "El valor del numero duplicado es: "  <<  number  <<  std::endl; // 10

	return  0;
}
```
- **Parámetros por defecto**
C++ permite definir valores por defecto para los parámetros de una función. Si no se proporcionan argumentos durante la llamada a la función, se utilizan estos valores.
```c++
#include <iostream>

// 2 sera el valor por defecto si no se pasa B
int Sum(int a, int b = 2);

int main(int argc, char* argv[]) {
    std::cout << Sum(5) << std::endl;    // 7
    std::cout << Sum(5, 10) << std::endl; // 15

    return 0;
}

int Sum(int a, int b) {
    return a + b;
}
```
## Estructuras de datos estáticas
Las estructuras de datos estáticas son aquellas que se declaran con un tamaño fijo en tiempo de compilación. Las estructuras estáticas ocupan un bloque de memoria continuo que se mantiene constante mientras el programa está en ejecución.

Existen 3 tipos de estructuras de datos estáticas:

- **Arreglo unidimensional o Vector**
- **Arreglo multidimensional o Matriz**
- **Structs**

### Arreglo unidimensional o Vector (Array)

Un **arreglo estático** es una colección de elementos del mismo tipo, almacenados en ubicaciones contiguas de memoria. Su tamaño se especifica en tiempo de compilación, lo que significa que **no se puede cambiar durante la ejecución** del programa. Existen arreglos unidimensional (vector) y arreglo multidimensional (matriz).

**Ejemplo: Declaración e inicialización de un arreglo (vector)**
```c++
int numbers[5] = {1, 2, 3, 4, 5, 6};

std::string fruits[4] = {"Manzana", "Pera", "Mandarina", "Naranja"};
```
#### Asignación de valores a un arreglo (vector)
Para asignar valores desde teclado a un arreglo unidimensional (vector), se hace uso de la estructura  `for`. 
```c++
#include <iostream>

const int kArraySize = 5;

int main(int argc, char* argv[]) {
    int numbers[kArraySize];  
    for (int i = 0; i < kArraySize; i++) { 
        std::cout << "Ingrese un valor: ";
        std::cin >> numbers[i];
    } 
    
    return 0; 
}
```
#### Imprimiendo valores de un arreglo (vector)
Para imprimir los valores que contiene un arreglo, se hace uso de la estructura `for`, la cual nos ayuda a recorrer todos los valores que contiene el arreglo.
```c++
#include <iostream>

const int kArraySize = 5;

int main(int argc, char* argv[]) {
    int numbers[kArraySize] = {10, 20, 30, 40, 50};  
    
    for (int i = 0; i < kArraySize; i++) { 
        std::cout << "Elemento en la posicion " << i << ": " << numbers[i] << std::endl; 
    } 
    
    return 0; 
}
```

### Arreglo multidimensional o Matriz

Una **matriz** es una extensión de un arreglo estático, pero en lugar de ser unidimensional, es multidimensional. La más común es la **matriz bidimensional**, que puede pensarse como una tabla de filas y columnas. Al igual que los arreglos, el tamaño de la matriz se define en tiempo de compilación y no puede cambiarse durante la ejecución del programa.

Las matrices se utilizan cuando necesitamos representar datos en forma de tabla, como una cuadrícula, un tablero de juego, o cualquier estructura donde se manejen dos dimensiones (como filas y columnas).

**Ejemplo: Declaración e inicialización de un arreglo (matriz)**	
```c++
int matrix[3][3] = { 
    {1, 2, 3}, 
    {4, 5, 6}, 
    {7, 8, 9} 
};

char board[3][3] = { 
    {'X', 'O', 'X'}, 
    {'O', 'X', 'O'}, 
    {'X', 'O', 'X'} 
};
```
#### Ejemplo: Asignación de valores a un arreglo (matriz)
Para asignar valores desde teclado a un arreglo multidimensional (matriz), se hace uso de la estructura  `for`. 

```c++
#include <iostream>

const int kMatrixRows = 3;
const int kMatrixCols = 3;

int main(int argc, char* argv[]) {
    int matrix[kMatrixRows][kMatrixRows];
    
    for (int i = 0; i < kMatrixRows; i++) { 
        for (int j = 0; j < kMatrixCols; j++) { 
            std::cout << "Ingrese un valor para la fila " << i << " columna " << j << ": "; 
            std::cin >> matrix[i][j];
        } 
    } 
    
    return 0; 
}
```
#### Ejemplo: Imprimir una matriz

Para acceder a los elementos de una matriz, se utiliza un par de índices: uno para las filas y otro para las columnas. Para recorrer e imprimir todos los elementos de una matriz, se puede usar un bucle `for` anidado.

```c++
#include <iostream>

const int kMatrixCols = 3;
const int kMatrixRows = 3;

int main(int argc, char* argv[]) {
    int matrix[kMatrixRows][kMatrixCols] = { 
        {1, 2, 3}, 
        {4, 5, 6}, 
        {7, 8, 9} 
    }; 
    
    for (int i = 0; i < kMatrixRows; i++) { 
        for (int j = 0; j < kMatrixCols; j++) { 
            std::cout << "Elemento de la posicion [" << i << "][" << j << "]: " << matrix[i][j] << std::endl; 
        } 
    } 
    
    return 0; 
}

```

### Structs

Un **struct** es una estructura de datos compuesta que permite agrupar diferentes **tipos de datos bajo un mismo nombre**.  A diferencia de los arreglos (vector y matriz), que solo pueden almacenar datos del mismo tipo, los structs permiten almacenar datos de distintos tipos. Cada elemento dentro de un struct se llama _miembro_.

Los structs son útiles para representar entidades más complejas que requieren varios atributos. Por ejemplo, una entidad de tipo `Libro` puede tener varios atributos como titulo, autor, páginas y precio, uno de diferente tipo.

#### Definición de un struct
```c++
struct Book { 
    std::string title; 
    std::string author; 
    int pages; 
    float price; 
};
```
En este ejemplo cuando tú declaras el struct `Libro`,  este crea un nuevo tipo de dato que contiene múltiples miembros En este caso, `Libro` se convierte en un tipo de dato personalizado que puedes usar en tu programa, al igual que usar cualquier otro tipo de dato.

Ahora que ya definimos a ese tipo de dato `Libro`podemos declarar nuevas variables de tipo `Libro`y definir sus miembros, accediendo a través del operador punto. Por ejemplo:

```c++
// Primer libro
Book book1; 
book1.title = "Cien Años de Soledad"; 
book1.author = "Gabriel García Márquez"; 
book1.pages = 417; book1.price = 29.99;

// Segundo libro
Book book2; 
book2.title = "Harry Potter and the Philosopher's Stone";
book2.author = "J.K. Rowling"; 
book2.pages = 309; 
book2.price = 19.99;`
```

#### Structs anidados
Una característica poderosa de los structs es que pueden contener otros structs como miembros. Esto permite crear estructuras de datos más complejas y jerárquicas. Por ejemplo:
```c++
struct Author {
    std::string first_name;
    std::string last_name;
};

struct Book { 
    std::string title; 
    int pages; 
    float price;
    Author author; // Estructura Autor
};
``` 
En este ejemplo, hemos creado un struct para Autor, que solo contiene el nombre y su apellido, luego en Libro, hemos creado un miembro, que es del tipo `Autor`.

#### Ejemplo: Imprimir structs
Para imprimir los structs, los podemos imprimir manualmente uno a uno, de la misma forma de como les asignamos valores, por ejemplo, el `libro1`que declaramos anteriormente.

```c++
std::cout << "Book 1:" << std::endl; 
std::cout << "Title: " << book1.title << std::endl;
std::cout << "Author: " << book1.author.first_name << " " << book1.author.last_name << std::endl; 
std::cout << "Pages: " << book1.pages << std::endl; 
std::cout << "Price: $" << book1.price << std::endl;
```
Ese fragmento de código imprime uno a uno los diferentes miembros que asignamos al libro 1. 

#### Arreglos de estructuras
Como bien se menciono anteriormente, un struct **es como que creemos un nuevo tipo de dato**. Por lo tanto, tenemos a disposición la bondad de combinarlo con la estructura de datos que vimos anteriormente, los **arreglos**.

Para eso, podemos crear un arreglo con varios libros:
```c++
Book books[3] = { 
    {"Cien Años de Soledad", 417, 29.99, {"Gabriel", "García Márquez"}}, 
    {"Don Quijote de la Mancha", 1023, 35.50, {"Miguel", "de Cervantes"}}, 
    {"Harry Potter and the Philosopher's Stone", 309, 19.99, {"J.K.", "Rowling"}} 
};
``` 
#### Ejemplo; Asignación de valores a los miembros de la estructura 

Para asignar los valores a un miembro de un struct, se debe utilizar el operador punto para poder ingresar a los miembros de la estructura.
```c++
#include <iostream>
#include <string>

const int kNumAuthors = 2;

struct Author {
    std::string first_name;
    std::string last_name;
};

struct Book { 
    std::string title; 
    int pages; 
    float price; 
    Author authors[kNumAuthors]; 
};

int main(int argc, char* argv[]) {

    // Declarando un nuevo libro
    Book book;
    
    std::cout << "Ingrese el titulo del libro: ";
    std::getline(std::cin, book.title);
    std::cout << "Ingrese el numero de paginas del libro: ";
    std::cin >> book.pages;	
    std::cout << "Ingrese el precio del libro: $";
    std::cin >> book.price;
    
    // Se le asigna valores al autor (suponiendo que tiene 2 autores un libro)
    for(int i = 0; i < kNumAuthors; i++) {
        std::cout << "Ingrese el primer nombre del autor " << i + 1 << ": ";
        std::cin >> book.authors[i].first_name;
        std::cout << "Ingrese el segundo nombre del autor " << i + 1 << ": ";
        std::cin >> book.authors[i].last_name;
    }
    
    return 0;
}
``` 
####  Ejemplo: Asignación de valores a un arreglo  de estructura 

```c++
#include <iostream>
#include <string>

const int kNumBooks = 3;
const int kNumAuthorsPerBook = 2;

struct Author {
    std::string first_name;
    std::string last_name;
};

struct Book { 
    std::string title; 
    int pages; 
    float price; 
    Author authors[kNumAuthorsPerBook]; 
};

int main(int argc, char* argv[]) {

    // Creando un arreglo de libros
    Book books[kNumBooks];
    
    for (int i = 0; i < kNumBooks; i++) {
        std::cout << "Ingrese el titulo del libro " << i + 1 << ": ";
        std::cin >> books[i].title;
        std::cout << "Ingrese el numero de paginas " << i + 1 << ": ";
        std::cin >> books[i].pages;	
        std::cout << "Ingrese el precio del libro " << i + 1 << ": $";
        std::cin >> books[i].price;
        
        // Se le asigna valores al autor (suponiendo que tiene 2 autores un libro)
        for (int j = 0; j < kNumAuthorsPerBook; j++) {
            std::cout << "Ingrese el primer nombre del autor " << j + 1 << " del libro " << i + 1 << ": ";
            std::cin >> books[i].authors[j].first_name;
            std::cout << "Ingrese el segundo nombre del autor" << j + 1 << " del libro " << i + 1 << ": ";
            std::cin >> books[i].authors[j].last_name;
        }
    }
    
    return 0;
}
``` 
De esta manera, podemos crear un arreglo con 3 libros definiendo adentro los valores que queremos que contenga. Ahora que ya tenemos varios libros agrupados **en una sola variable**, podemos imprimirlos

#### Ejemplo: Imprimir structs anidados
Para imprimir de la misma manera structs anidados como el que vimos al principio, se sigue la misma lógica, sin embargo, **Se deben acceder a los miembros del autor** dentro del bucle.
```c++
#include <iostream>
#include <string>

struct Author {
    std::string first_name;
    std::string last_name;
};

struct Book {
    std::string title;
    int pages;
    float price;
    Author author;
};

int main(int argc, char* argv[]) 
{
    Book books[2] = {
        {"El amor en los tiempos del colera", 417, 29.99, {"Gabriel", "Garcia Marquez"}},
        {"Don Quijote de la Mancha", 1023, 35.50, {"Miguel", "de Cervantes"}},
    };

    for (int i = 0; i < 2; i++) {
        std::cout << "Libro " << i + 1 << ":" << std::endl;
        std::cout << "Titulo: " << books[i].title << std::endl;
        std::cout << "Autor: " << books[i].author.first_name << " " << books[i].author.last_name << std::endl;
        std::cout << "Paginas: " << books[i].pages << std::endl;
        std::cout << "Precio: $" << books[i].price << std::endl;
    }

    return 0;
}
```
