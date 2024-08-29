# Funciones recursivas

En este laboratorio aprenderás sobre que son las funciones recursivas, su implementación y aplicaciones prácticas.

### ¿Qué es recursividad?
La recursividad es una técnica de programación donde una función **se llama a sí misma** para resolver un problema. En esencia, una función recursiva aborda un problema dividiéndolo en subproblemas más pequeños y más sencillos de resolver, hasta llegar a una condición base que **detiene la recursión**.

Es crucial establecer una **condición base** o **condición de paro**  que detenga la recursividad, para evitar que la función se llame indefinidamente.

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

![](https://camo.githubusercontent.com/9a6d55ad66f71602c9219b3afdc37a23c5f3fd0050ed0de57f0b3af0fc154d3a/68747470733a2f2f692e70696e696d672e636f6d2f6f726967696e616c732f39612f35662f62662f39613566626661313530666465616239306133666434633339616665646635342e676966)

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

### Tipos de recursividad 
Las funciones recursivas se pueden clasificar en diferentes tipos según cómo se estructuren las llamadas recursivas

#### 1. Recursividad Directa
En la recursividad directa, una función se llama a sí misma directamente. Este es el tipo más común de recursividad y el que hemos visto en los ejemplos anteriores.
```c++
#include <iostream>

int CountCharacters(const char* str) {
  if (str[0] == '\0') {
    return 0;  // Caso base: si alcanzamos el final de la cadena, retornamos 0.
  } else {
    return 1 + CountCharacters(str + 1);  // Llamada recursiva con el siguiente carácter.
  }
}

int main() {
  const char* myString = "Hola, mundo!";

  int count = CountCharacters(myString);

  std::cout << "La cadena '" << myString << "' tiene " << count << " caracteres." << std::endl;

  return 0;
}
```
#### 2. Recursividad Indirecta
En la recursividad indirecta, una función A llama a otra función B, y la función B a su vez llama a la función A.
```c++
#include <iostream>

// Función A: Llama a FunctionB si n es mayor que 0.
void FunctionA(int n) {
  if (n > 0) {
    FunctionB(n - 1);
  }
}

// Función B: Llama a FunctionA si n es mayor que 1.
void FunctionB(int n) {
  if (n > 1) {
    FunctionA(n / 2);
  }
}


int main() {
  int number;

  // Solicita al usuario que ingrese un número.
  std::cout << "Ingrese un numero: ";
  std::cin >> number;

  // Inicia la recursividad llamando a la FunctionA.
  FunctionA(number);

  return 0;
}
```

#
En conclusión, la recursividad es una técnica clave en programación que permite resolver problemas complejos  al dividirlos en subproblemas más pequeños.

 Aunque puede simplificar el código y facilitar la resolución de ciertos problemas, es importante ser consciente de sus limitaciones en términos de **consumo de memoria y rendimiento.**
 

## Anexos

### Uso de SSH para clonar repositorios
Configurar SSH te permite establecer conexiones seguras a servidores y gestionar repositorios remotos en GitHub u otros servicios. Aquí está una guía paso a paso para configurar SSH en Windows

- Asegúrate primero de tener Git instalado en tu computadora
- Luego de eso, hay que generar una llave SSH, para esto podemos ejecutar el siguiente comando en nuestro terminal:
	 ```bash
	 ssh-keygen -t rsa -b 4096 -C "your_email@example.com"
	 ``` 
-   Cuando se te pida, elige una ubicación para guardar la clave. La ubicación predeterminada (`~/.ssh/id_rsa`) es generalmente adecuada,.
-   También se te pedirá una frase de contraseña para proteger la clave. Puedes dejarla en blanco si prefieres no usar una frase de contraseña.
**![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXd7ItOfC65WG7PmOoRLciZzPqD-yxt0lRPPmCJBniuGTvWJ90-01y30PCiH6RAbD85at5DFkZLz_cPva6BFcDQ3Ydmrd_LiHmC3WrrjY3wwCDgYJIlMg4czgmScjrUkGgIw3Yzn9kQNlTj7EYjZxoDRigkt9wWbdhbaWgdsww?key=EhCsE0g7-bE307ibHBtdPA)**
- Luego en tu computador, dirígete a la ubicación donde se creo el SSH publico, que es el que esta marcado en rojo en la fotografía anterior. Si copias y pegas la ruta en tu gestor de archivos, te abrirá un bloc de notas con una serie de caracteres, la cual es nuestra llave publica.
- Copia la llave publica generada
- Luego que la tengas copiada, nos dirigiremos a Github y nos iremos nuestra foto de perfil y seleccionaremos "configuración"
	**![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXd369XKIVQGD58NDnCvGXW7tgcBIAFyp7rJJAwlzu6jWOA8RjNfU3Rp0ue_763RYrsi04SN8o2OXkUr8UcC3ldXZgNzee_FnFjLWx5WUXVnn6gIUm3_e5Eotrn6UTn909JNq3WrESuQaH9flVIRDLCF0grNkiEOCGjp_klRLA?key=EhCsE0g7-bE307ibHBtdPA)**
- En la configuración nos iremos al apartado "SSH keys and GPG keys" y agregaremos una nueva llave SSH
**![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXe12JVCGiS3FmyH-nHGD6_LKxv32tpI5IrmjIENJQV3oUyQ6y2XD0yhTxlYwuy4YpbU348RJNX7W-tTxfSM-Se1tnDcszEhJzI7am5CIYQmv1dYTg0i6SEooKSecEdrBP3Q-gk5fc3osgpcl3k7wC0w42g_7Zgo5-ToO24itg?key=EhCsE0g7-bE307ibHBtdPA)**
Le podemos poner cualquier titulo y dejamos seleccionado el tipo de llave de autenticación y luego en la "key" pegamos la llave publica que estaba en nuestro bloc de notas.
- Una ves realizado este paso, podemos probar clonando un repositorio nuevamente, sin embargo, como ya configuramos nuestro SSH, podemos usar esta nueva URL para clonar el repositorio en ves de con HTTPS.
**![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXes4-RvZ4dZNRhf1J6BChMmTiT_Tv03AYkcfMVNxgAxcxIFy-BcwetDRAXNWjMXwbjnVzIXBqSUmt1MrN2d_y90Jl6ixI12fcMqGgiO_3qf_e0arzhkVoa6H478T5mRjMDuZRGvjtwyaMb3SUj6_pnkvZ8JCeive_rJ7mlC3Q?key=EhCsE0g7-bE307ibHBtdPA)**
- Al clonar un repositorio, nos puede decir lo siguiente, solo le damos a "yes" y si hicimos los pasos correctamente, lo clonará.
**![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXdPeLtifLRnrKNJc6PovR-iJmNq6T31qO3Z5VxnrOuqvz4Ec-r3k-sbiwpSYaTVLrZkA4K9Wx4UqVJJPhySTT3Kaw_OPhR9Mm1BhMZ4GFYUqoziGmiVe-mmZZW7MWWHfcQI-UKur-x7QFnvt7_7opmDMK0nUaJPNQkmCsRR?key=EhCsE0g7-bE307ibHBtdPA)**
- Si tienes dudas o errores, no dudes en consultar con tu instructor.
