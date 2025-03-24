# Programando con Java 

En este laboratorio aprenderás los fundamentos de Java, incluyendo sintaxis básica, estructuras de control y buenas prácticas de programación.

## Estructura Básica de un Programa Java
Un programa Java se compone de **clases** que contienen métodos. Cada programa debe tener un método `main` que actúa como punto de entrada de nuestra aplicación.

```Java
public class Main {
    public static void main(String[] args) {
        System.out.println("¡Hola Mundo!");
    }
}
```
En este ejemplo, la clase `Main` es el nombre de la clase. Por convención, se usa PascalCase para nombrar las clases, esta clase  contiene el método `main`, el cual imprime en la consola el mensaje "¡Hola Mundo!".


Una palabra clave que será cubierto en posteriores laboratorios son los modificadores de acceso:

-   `public`: Permite acceso desde cualquier parte del programa por ejemplo, la clase principal `Main` debe ser publica para ejecutarse
    
-   `private` : Restringe el uso solo a la clase donde se declara.
    
-   `static`: Indica que pertenece a la clase, no a objetos específicos.

> 🔍 **¿Por qué  main es `static`?**  
El método `main` debe ser `static` porque se ejecuta sin necesidad de crear un objeto de la clase. Esto se debe a cómo Java inicia la ejecución.

## Relación archivo/clase
En Java, existe una regla fundamental: 
 
✅ **El nombre del archivo  `.java`  debe coincidir exactamente** con el nombre de la clase pública que contiene (incluyendo mayúsculas y minúsculas).

Cuando hay una sola clase `publica`:
```Java
// Archivo: MiPrograma.java

public class MiPrograma {
    // ...
}
```

Si tu archivo tiene múltiples clases, el nombre del archivo debe ser igual al de la clase `publica`

```Java
public class Aplicacion { 
    // ...
}

class Helper {
    // ...
}
```
Como la única clase publica es `Aplicación` el archivo debería llamarse `Aplicacion.java`


> 💡  **Consejo:**
> 
> Si tu clase es  `public`, el archivo  **DEBE**  llamarse igual.  
> 
> Si el archivo no tiene clases públicas, puede tener cualquier nombre.  
>     
> Usa siempre  **PascalCase**  para nombres de clases y archivos.
## Tipos de Datos y Arreglos

### Tipos Primitivos
Java define varios tipos de datos primitivos que se utilizan para almacenar valores básicos
```Java
int age = 25;         // Entero
double price = 19.99; // Decimal
char letter = 'A';      // Carácter
boolean active = true; //booleano
```

### Tipos de la biblioteca estándar de java

#### String
La clase `String` se utiliza para manejar cadenas de caracteres. Es **inmutable** es decir que no puede modificarse después de su creación, lo que implica que cualquier operación sobre un `String` crea uno nuevo.

```Java
String day = "Lunes";
```
Algunos métodos útiles de un String son:

```Java
String texto = "Laboratorio 1";
int longitud = texto.length(); //12
String mayus = texto.toUpperCase(); //LABORATORIO 1
String sub = texto.substring(0, 4); //LABO
String nuevo = texto.replace("Laboratorio", "Practica"); //Practica 1
```
Para concatenar dos cadenas de caracteres, lo hacemos de la siguiente manera:
```Java
String nombre = "Josse";
String saludo = "Hola, " + nombre + "!";  // "Hola, Josse!"
String concatenado = nombre.concat(" Castillo"); // "Josse Castillo"
```
**Comparación de strings**

En Java, **no se suele usar `==`** para comparar Strings. Se usa el método `equals()`:

```java
String nombre1 = "Ana";
String nombre2 = new String("Ana");

System.out.println(nombre1.equals(nombre2));  // true (compara contenido)
System.out.println(nombre1 == nombre2);       // false (compara objetos)
```
En este caso como nombre1 y nombre2 no son el mismo objeto, devuelve false usando el comparador `==`

#### Scanner
La clase `Scanner` facilita la entrada de datos por teclado, lo que es fundamental para interactuar con el usuario.
```Java
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Ingresa tu nombre:");
        String nombre = sc.nextLine();
        System.out.println("Hola, " + nombre);
        
		//Cerrando el scanner
		sc.close();
    }
}
```
En el ejemplo anterior leemos una cadena de caracteres, sin embargo, para los demás tipos, Scanner tiene una función diferente

```Java
int edad = sc.nextInt();
double altura = sc.nextDouble();
```

> 💡**Nota**: Cierra el objeto `Scanner` cuando ya no lo necesites, para liberar recursos


### Arreglos

Los arreglos en Java son objetos que permiten almacenar múltiples valores del mismo tipo. Se pueden inicializar directamente o declarar un tamaño fijo
```Java
// Directo
int[] numbers = {1, 2, 3, 4, 5};

// Declaración
String[] names = new String[3];
names[0] = "Ana"; 
names[3] = "Pedro"; // ❌ Error: índice 3 no existe
```
### Estructuras Condicionales
Las estructuras condicionales permiten ejecutar bloques de código basados en evaluaciones lógicas.

#### If-Else
Se utiliza para tomar decisiones según condiciones
```Java
int note = 85;

if(note >= 90) {
    System.out.println("Excelente");
} else if(note >= 70) {
    System.out.println("Aprobado");
} else {
    System.out.println("Reprobado");
}
```

#### Switch
Permite comparar una variable con diferentes casos
```Java
String day = "Lunes";

switch(day) {
    case "Lunes":
        System.out.println("Inicio de semana");
        break;
    default:
        System.out.println("Día no reconocido");
}
```
La sentencia `break` en un `switch`  **detiene la ejecución del bloque** y sale de la estructura. Si no se incluye, el código continuará ejecutando los casos siguientes a eso se le llama **fall-through**, lo que puede llevar a comportamientos inesperados.

La sentencia `default` se ejecutara si ninguno de los casos se cumple.

A partir de Java 14 hay otra manera de escribir un switch
 
```Java
switch(dia) {
    case "Lunes" -> System.out.println("Inicio de semana");
    case "Viernes" -> System.out.println("¡Fin de semana!");
    default -> System.out.println("Día laboral");
}
```
### Estructuras Repetitivas
Las estructuras repetitivas permiten ejecutar repetidamente un bloque de código.

#### For
Ideal para iterar un número conocido de veces:
```Java
for(int i = 0; i < 5; i++) {
    System.out.println("Iteración: " + i);
}
```

#### While
Se utiliza cuando el número de iteraciones no está determinado de antemano

 ```Java
 int counter = 0;
 
while(counter < 3) {
    System.out.println("Contador: " + counter);
    counter++;
}
```

### Funciones
Las funciones (o métodos) son bloques de código reutilizables. Pueden ser definidos sin parámetros o con parámetros, e incluso retornar valores.

#### Ejemplo sin parámetros:
```Java
public static void hello() {
    System.out.println("¡Bienvenido!");
}

public static void main(String[] args) {
    hello(); 
}
```

#### Ejemplo con  parámetros:
```Java
public static int sum(int a, int b) {
    return a + b;
}

public static void main(String[] args) {
    int resultado = sum(5, 3);
    System.out.println("La suma es: " + resultado); 
}
```

### Manejo de Excepciones
El manejo de excepciones es fundamental para escribir programas robustos que puedan manejar errores de ejecución sin detener abruptamente la aplicación.

```Java
try {
   int result = 10 / 0; //ArithmeticException 
   
} catch(ArithmeticException e) {
    System.out.println("Error: División por cero");
} finally {
    System.out.println("Bloque finally ejecutado");
}
```
El bloque **try** coloca el código que puede generar una excepción. mientras que el bloque **catch** captura y maneja la excepción para evitar que el programa se detenga, por ultimo **finally** se ejecuta siempre, independientemente de si se produjo o no la excepción. Es útil para liberar recursos o ejecutar código final de limpieza.

Otro uso para los try-catch son los **Try-with-resources** , esto nos ayudara a que recursos como  `Scanner` que se deben cerrar, se cierren automáticamente cuando se deja de utilizar

 ```Java
 import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.print("Ingrese su edad: ");
            int edad = scanner.nextInt();
            System.out.println("Edad ingresada: " + edad);
        } catch (Exception e) {
            System.out.println("Error: Entrada inválida");
        }
    }
}
 ```

En este caso. ya no es necesario ejecutar `sc.close();` ya que el bloque `try` lo hace por nosotros.

## Buenas practicas 

### Documentación 
Es muy buena practica usar comentarios para explicar el propósito de bloques de código, especialmente si la lógica es compleja.
```Java
// Este método calcula la suma de dos números
public static int sum(int a, int b) {
    return a + b;
}
```

Igualmente, puedes usar una mejor documentación  para métodos y clases usando JavaDoc, lo cual facilita el mantenimiento y el uso de tus componentes por otros desarrolladores.

```Java
/**
 * Suma dos números enteros.
 * @param a Primer número.
 * @param b Segundo número.
 * @return La suma de a y b.
 */
public static int sum(int a, int b) {
    return a + b;
}
```

## Modularización
Divide el programa en clases y métodos que cumplan funciones específicas, esto también evita la duplicación de lógica mediante la creación de métodos o clases genéricas que puedan utilizarse en diferentes partes del proyecto

```Java
public class Calculadora {
    public static void main(String[] args) {
        int resultado = sum(10, 20);
        System.out.println("Resultado: " + resultado);
    }
    
    public static int sum(int a, int b) {
        return a + b;
    }
}
```

## Google Java Style

La Guía de Estilo de Java de Google es un conjunto de reglas estrictas que definen cómo debe formatearse el código Java para lograr un aspecto homogéneo en proyectos grandes y colaborativos. 

### Identación
Se utiliza una indentación de 2 espacios por nivel. Se deben dejar espacios alrededor de operadores y después de comas para mejorar la legibilidad.
```Java
// Correcto (espacio después de coma y alrededor de operadores)
public int calcularTotal(int a, int b) {
    return a + b * 2;
}
```
### Longitud de la líneas de código 
Las líneas de código deben limitarse a **100 caracteres** como máximo. Si una línea supera este límite, se debe aplicar un ajuste de línea (line-wrapping) en puntos lógicos del código.
```Java
public class LongStringExample {
  public String getMessage() {
    return "Esta es una cadena de texto muy larga que se ha dividido en dos líneas para " +
           "cumplir con el límite de 100 caracteres por línea.";
  }
}
```
### Uso de llaves
Las llaves se colocan en la misma línea que la declaración del bloque (estilo K&R o llaves egipcias). Incluso para bloques de una sola línea, se recomienda usar llaves para mayor claridad.

```Java
public class ConditionExample {
  public void checkValue(int value) {
    if (value > 0) {
      System.out.println("El valor es positivo.");
    } else {
      System.out.println("El valor es cero o negativo.");
    }
  }
}
```
### Convenciones de Nomenclatura

#### Nombres de clases
Los nombres de las clases deben ser escritas en UpperCamelCase y generalmente los nombres son sustantivos

#### Nombres de metodos
Los métodos deben ser escritos usando el formato lowerCamelCase y generalmente los nombres de los métodos son verbos

#### Nombres de constantes 
Las constantes de cualquier tipo primitivo o complejo se usa el formato UPPER_SNAKE_CASE

**Ejemplo**:
```Java
public class DataProcessor {  // UpperCamelCase para clases
  private static final int MAX_SIZE = 100;  // Constante en UPPER_SNAKE_CASE

  private int processedCount;  // lowerCamelCase para variables

  public void processData() {  // lowerCamelCase para métodos
    processedCount++;
    // ...
  }
}
```

## Anexos

- **[Documentación Oficial de Java](https://docs.oracle.com/javase/tutorial/)** - Tutoriales y referencias.

- **[Guía de Estilo de Google](https://google.github.io/styleguide/javaguide.html)** - Estándares de código.

- **[Practicar Java Online](https://replit.com/languages/java)** - Entorno de prueba.

- **[Ejercicios en Exercism](https://exercism.org/tracks/java)** - Desafíos prácticos.

- **[Java Exceptions](https://docs.oracle.com/javase/tutorial/essential/exceptions/)** -  Lesson: Exceptions  
