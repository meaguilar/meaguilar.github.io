# Fundamentos de programación en Java y buenas prácticas

Esta guía introduce los fundamentos de programación en Java, abordando la estructura básica de un programa, tipos de datos, entrada y salida de información, arreglos y estructuras de control. Además, presenta conceptos esenciales como la creación de métodos, el manejo de excepciones y la modularización del código. Finalmente, se incluyen buenas prácticas de desarrollo, convenciones de estilo y documentación con JavaDoc, con el objetivo de fomentar la escritura de código claro, organizado y mantenible.

---

# Estructura Básica de un Programa Java

Un programa Java se compone de **clases** que contienen métodos. Cada programa debe tener un método `main` que actúa como punto de entrada de nuestra aplicación.

```java
public class Main {
    public static void main(String[] args) {
        System.out.println("¡Hola Mundo!");
    }
}
```

En este ejemplo:

- `Main` es el nombre de la clase.
- Por convención se usa **PascalCase** para nombrar clases.
- El método `main` imprime el mensaje **"¡Hola Mundo!"** en la consola.

---

## Modificadores de acceso

Algunas palabras clave importantes:

- **public**  
  Permite acceso desde cualquier parte del programa.  
  La clase principal `Main` debe ser pública para ejecutarse.

- **private**  
  Restringe el acceso solo a la clase donde se declara.

- **static**  
  Indica que el elemento pertenece a la clase y no a objetos específicos.

> 🔍 **¿Por qué `main` es static?**  
El método `main` debe ser `static` porque se ejecuta sin necesidad de crear un objeto de la clase.

---

# Relación archivo / clase

En Java existe una regla fundamental:

✅ **El nombre del archivo `.java` debe coincidir exactamente con el nombre de la clase pública.**

### Ejemplo

```java
// Archivo: MiPrograma.java

public class MiPrograma {
    // ...
}
```

### Múltiples clases

Si hay varias clases en el archivo:

```java
public class Aplicacion { 
    // ...
}

class Helper {
    // ...
}
```

El archivo debe llamarse:

```
Aplicacion.java
```

porque es la única clase pública.

💡 **Consejo**

- Si una clase es `public`, el archivo **debe llamarse igual**.
- Si no hay clases públicas, el archivo puede tener cualquier nombre.
- Usa siempre **PascalCase** para clases.

---

# Tipos de Datos y Arreglos

## Tipos Primitivos

Java define varios tipos primitivos para almacenar valores básicos.

```java
int age = 25;         // Entero
double price = 19.99; // Decimal
char letter = 'A';    // Carácter
boolean active = true; // Booleano
```

---

# Tipos de la Biblioteca Estándar

## String

La clase `String` representa cadenas de caracteres.

Es **inmutable**, lo que significa que su valor no puede modificarse después de crearse.

```java
String day = "Lunes";
```

### Métodos comunes

```java
String texto = "Laboratorio 1";

int longitud = texto.length();
String mayus = texto.toUpperCase();
String sub = texto.substring(0, 4);
String nuevo = texto.replace("Laboratorio", "Practica");
```

### Concatenación

```java
String nombre = "Josse";

String saludo = "Hola, " + nombre + "!";
String concatenado = nombre.concat(" Castillo");
```

---

## Comparación de Strings

En Java **no se recomienda usar `==` para comparar Strings**.

Se debe usar `equals()`.

```java
String nombre1 = "Ana";
String nombre2 = new String("Ana");

System.out.println(nombre1.equals(nombre2)); 
System.out.println(nombre1 == nombre2);
```

- `equals()` compara **contenido**
- `==` compara **referencias de objeto**

---

# Entrada de Datos con Scanner

La clase `Scanner` permite leer datos del teclado.

```java
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.println("Ingresa tu nombre:");
        String nombre = sc.nextLine();

        System.out.println("Hola, " + nombre);

        sc.close();
    }
}
```

### Leer otros tipos de datos

```java
int edad = sc.nextInt();
double altura = sc.nextDouble();
```

💡 **Nota:**  
Cierra el `Scanner` cuando ya no lo necesites.

---

# Arreglos

Los arreglos almacenan múltiples valores del mismo tipo.

### Inicialización directa

```java
int[] numbers = {1, 2, 3, 4, 5};
```

### Declaración con tamaño fijo

```java
String[] names = new String[3];

names[0] = "Ana";
names[1] = "Luis";
names[2] = "Pedro";
```

---

# Estructuras Condicionales

## If - Else

Permite ejecutar código dependiendo de una condición.

```java
int note = 85;

if(note >= 90) {
    System.out.println("Excelente");
} else if(note >= 70) {
    System.out.println("Aprobado");
} else {
    System.out.println("Reprobado");
}
```

---

## Switch

Permite evaluar múltiples casos.

```java
String day = "Lunes";

switch(day) {
    case "Lunes":
        System.out.println("Inicio de semana");
        break;
    default:
        System.out.println("Día no reconocido");
}
```

### Switch moderno (Java 14+)

```java
switch(dia) {
    case "Lunes" -> System.out.println("Inicio de semana");
    case "Viernes" -> System.out.println("¡Fin de semana!");
    default -> System.out.println("Día laboral");
}
```

---

# Estructuras Repetitivas

## For

Se usa cuando sabemos cuántas veces se repetirá el ciclo.

```java
for(int i = 0; i < 5; i++) {
    System.out.println("Iteración: " + i);
}
```

---

## While

Se usa cuando no sabemos el número exacto de iteraciones.

```java
int counter = 0;

while(counter < 3) {
    System.out.println("Contador: " + counter);
    counter++;
}
```

---

# Funciones (Métodos)

Los métodos son bloques de código reutilizables.

---

## Método sin parámetros

```java
public static void hello() {
    System.out.println("¡Bienvenido!");
}

public static void main(String[] args) {
    hello();
}
```

---

## Método con parámetros

```java
public static int sum(int a, int b) {
    return a + b;
}

public static void main(String[] args) {
    int resultado = sum(5, 3);
    System.out.println("La suma es: " + resultado);
}
```

---

# Manejo de Excepciones

Permite manejar errores sin detener el programa.

```java
try {
   int result = 10 / 0;

} catch(ArithmeticException e) {
    System.out.println("Error: División por cero");

} finally {
    System.out.println("Bloque finally ejecutado");
}
```

---

## Try With Resources

Permite cerrar recursos automáticamente.

```java
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

---

# Buenas Prácticas de Programación

## Documentación

Usa comentarios para explicar el propósito del código.

```java
// Este método calcula la suma de dos números
public static int sum(int a, int b) {
    return a + b;
}
```

### JavaDoc

Permite generar documentación automática.

```java
/**
 * Suma dos números enteros.
 * @param a Primer número
 * @param b Segundo número
 * @return Resultado de la suma
 */
public static int sum(int a, int b) {
    return a + b;
}
```

---

# Modularización

Divide el programa en clases y métodos.

Esto mejora:

- mantenimiento
- reutilización
- organización del código

```java
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

---

# Google Java Style

La **Guía de Estilo de Java de Google** define reglas para mantener un código consistente.

---

## Identación

Se utilizan **2 espacios por nivel**.

```java
public int calcularTotal(int a, int b) {
  return a + b * 2;
}
```

---

## Longitud de línea

Máximo **100 caracteres por línea**.

```java
return "Esta es una cadena muy larga " +
       "que se divide para respetar el límite";
```

---

## Uso de llaves

Las llaves deben colocarse en la misma línea.

```java
if (value > 0) {
  System.out.println("Positivo");
} else {
  System.out.println("Negativo");
}
```

---

## Convenciones de Nombres

### Clases

Formato:

```
UpperCamelCase
```

Ejemplo:

```
DataProcessor
```

---

### Métodos

Formato:

```
lowerCamelCase
```

Ejemplo:

```
processData()
```

---

### Constantes

Formato:

```
UPPER_SNAKE_CASE
```

Ejemplo:

```
MAX_SIZE
```

```java
public class DataProcessor {

  private static final int MAX_SIZE = 100;

  private int processedCount;

  public void processData() {
    processedCount++;
  }

}
```

---

# Anexos

### Documentación oficial de Java

https://docs.oracle.com/javase/tutorial/

### Guía de estilo de Google

https://google.github.io/styleguide/javaguide.html

### Practicar Java online

https://replit.com/languages/java

### Ejercicios de Java

https://exercism.org/tracks/java

### Manejo de excepciones en Java

https://docs.oracle.com/javase/tutorial/essential/exceptions/
