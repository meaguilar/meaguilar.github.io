# Funciones recursivas

En este laboratorio aprenderás sobre que son las funciones recursivas, su implementación y aplicaciones prácticas.

### ¿Qué es recursividad?
La recursividad es una técnica de programación donde una función **se llama a sí misma** para resolver un problema. En esencia, una función recursiva aborda un problema dividiéndolo en subproblemas más pequeños y más sencillos de resolver, hasta llegar a una condición base que **detiene la recursión**.

Es crucial establecer una **condición base** que detenga la recursión, para evitar que la función se llame indefinidamente.

![](https://i.ytimg.com/vi/_-5l_gKnnsM/maxresdefault.jpg)


#### 1. **Características Clave de las Funciones Recursivas**

-   **Llamada Recursiva:** En el corazón de toda función recursiva hay una llamada a sí misma, es decir se invoca a si misma adentro.
-   **Caso Base:** Este es el punto de parada. Sin un caso base, la función seguiría llamándose a sí misma indefinidamente, lo que llevaría a un error.
-   **Descomposición del Problema:** Cada vez que la función se llama a sí misma, debe acercarse al caso base.

#### **2. Ventajas de la Recursividad**

-   **Simplicidad Elegante:** En algunos casos, las soluciones recursivas pueden ser más claras y elegantes que las iterativas, facilitando la comprensión del código.
-   **Resolución de Problemas Complejos:** La recursividad es especialmente útil cuando un problema puede dividirse naturalmente en subproblemas más pequeños.

#### 3. **Desventajas de la Recursividad**

-   **Consumo de Memoria:** Cada llamada recursiva se guarda en la pila de ejecución, lo que puede consumir mucha memoria si hay demasiadas llamadas anidadas. 


### Ejemplos de recursividad
A continuación, implementaremos algunos ejemplos clásicos de funciones recursivas para ilustrar cómo funcionan en la práctica.

#### 1. Factorial de un número
El factorial de un número n (denotado como n!) es el producto de todos los enteros positivos menores o iguales a n. Por ejemplo:
$$5! = 5 × 4 × 3 × 2 × 1 =120$$

 Se define recursivamente como:

$$ n! = n × (n - 1)! $$

Y la condición de paro o **caso base** es que:
 $$0! = 1$$
 
 Implementando esto a código obtenemos lo siguiente:
```c++
#include <iostream>

int factorial(int n) {
    if (n == 0) {
        return 1; // Caso base o condición de paro
    } else {
        return n * factorial(n - 1); // Llamada recursiva
    }
}

int main() {
    int num;
    std::cout << "Ingresa un numero: ";
    std::cin >> num;
    std::cout << "El factorial de " << num << " es: " << factorial(num) << std::endl;
    return 0;
}
```
En este ejemplo, como se vio en la teoría, la función `factorial` dentro de la misma función se esta llamando a si misma, retornando la operación mencionada anteriormente en la teoría.

Esta iteración la seguirá haciendo hasta que el numero que retorne sea igual a 0. Esa condición que hacemos al principio, es nuestra condición de paro, cuando eso se cumpla, la función ya no seguirá haciendo llamadas recursivas.

#### 2. Sucesión de Fibonacci
Otro ejemplo matemático donde podemos usar recursividad es la sucesión de Fibonacci. Esta es un serie de números donde el siguiente es la suma de los dos anteriores. 
$$0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89$$

Es decir:
- 0 + 1 da como resultado 1
- 1 + 1 da como resultado 2
- 1 + 2 da como resultado 3
- 2 + 3 da como resultado 5

Y así sucesivamente e indefinidamente, esto lo podemos aplicar a código, aunque la sucesión de Fibonacci sea infinita. Es decir, a la función brindarle una posición y en base a eso calcule cual es el número. Por ejemplo, en la posición 6 esta el numero 8.

Aplicando esto a código, nos queda lo siguiente:
```c++
#include <iostream>

int Fibonacci(int n) {

  // Condición de paro
  // si n es 0 o 1, se retorna el mismo número
  
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  }
  
  // Caso recursivo: se suman los dos números anteriores
  return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main() {
  int numero;
  std::cout << "Ingresa un numero: ";
  std::cin >> numero;

  std::cout << "El numero de Fibonacci en la posicion " << numero << " es "
            << Fibonacci(numero) << std::endl;

  return 0;
}
```
En este ejemplo, vimos que llamamos a la misma función en el cuerpo de la función, y esta el `n` que recibe es el que retornó en su llamada anterior, esto hasta que llegue a nuestra condición de paro, sea 0 o sea 1.

#### 3. Cuenta regresiva
De momento los ejemplos que hemos visto, son de libros, muy matemáticos, sin embargo, las funciones recursivas las podemos usar para cosas mas sencillas. Por ejemplo para una cuenta regresiva.

La idea es sencilla, queremos una función que en cada llamada, haga que el numero disminuya, haciendo que cada vez que se llama, retorne el numero restado 1. Pero... **¿Hasta donde?**
En este caso si no ponemos un paro, seguirá restando uno al numero indefinidamente. Por lo tanto, nuestra función se detendrá cuando lleguemos a 0.

Aplicando esto a código obtenemos:
```c++
#include <iostream>

void Countdown(int n) {
  // Caso base: nuestra cuenta llega a 0
  if (n < 0) {
    return;
  }
  // Muestra el numero de la cuenta regresiva
  std::cout << n << std::endl;
  
  /* Vuelve a llamarse a si misma, 
  pasandole el mismo numero, restado 1 */
  
  Countdown(n - 1);
}

int main() {
  int number;
  std::cout << "Ingrese un numero para iniciar la cuenta: ";
  std::cin >> number;

  Countdown(number);

  return 0;
}
```

En conclusión, la recursividad es una técnica clave en programación que permite resolver problemas complejos  al dividirlos en subproblemas más pequeños.

 Aunque puede simplificar el código y facilitar la resolución de ciertos problemas, es importante ser consciente de sus limitaciones en términos de **consumo de memoria y rendimiento**. 
