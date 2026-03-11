# Patrones de Diseño en Java

En este laboratorio, exploraremos tres patrones de diseño fundamentales en el desarrollo de software orientado a objetos

-   **Factory Method** (Método de Fábrica)
    
-   **Adapter** (Adaptador)
    
-   **Observer** (Observador)

Estos patrones nos permiten crear soluciones más flexibles, reutilizables y mantenibles al abordar problemas comunes en la programación.

## ¿Qué son los patrones de diseño?

Los **patrones de diseño** son **soluciones reutilizables a problemas comunes** que surgen durante el desarrollo de software. No son fragmentos de código específicos, sino **modelos generales que puedes adaptar** a distintas situaciones para escribir código más claro, flexible y mantenible.

### Tipos de Patrones de Diseño
Los patrones de diseño se dividen generalmente en **tres categorías principales**:

**![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXeRNmh-uYjf6Oy-46Lr3zWr0bt9yustizIl5nac00ioHAKp64uwu-bgylhkEPnSQoQ-qaqXGHpEk5QGLty-MQ0BhuHhx7pPsTxb8iDcldRaMRBhznHE0pp-dU3eoy8asRE0DsZz?key=f7rwYIcXUeGVARv8sk0DWs0G)**
## Factory Method  🔧 

El **Factory Method** es un patrón de diseño creacional que proporciona una interfaz para crear objetos en una superclase, pero permite que las subclases alteren el tipo de objetos que se crearán.

Imagina que estás desarrollando una aplicación de logística que inicialmente solo maneja transporte por camión. Con el tiempo, necesitas agregar transporte marítimo y aéreo. Si el código está fuertemente acoplado a la clase `Camion`, agregar nuevos tipos de transporte requerirá modificar muchas partes del código existente o incluso agregando **código repetido**.

El patrón Factory Method te permite:

-   **Desacoplar** la creación de objetos del código cliente.
    
-   **Extender** fácilmente la aplicación con nuevos tipos de productos sin modificar el código existente.
    
-   **Cumplir** con el principio de abierto/cerrado: el código está abierto para extensión, pero cerrado para modificación.

Por ejemplo:
 ```Java
interface Transporte {
    void entregar();
}

// Definimos las clases concretas
class Camion implements Transporte {
    public void entregar() {
        System.out.println("Entrega por carretera.");
    }
}

class Barco implements Transporte {
    public void entregar() {
        System.out.println("Entrega por mar.");
    }
}

// Clase creadora
abstract class Logistica {
    public abstract Transporte crearTransporte();

    public void planEntrega() {
        Transporte transporte = crearTransporte();
        transporte.entregar();
    }
}

// Creadores concretos
class LogisticaCarretera extends Logistica {
    public Transporte crearTransporte() {
        return new Camion();
    }
}

class LogisticaMaritima extends Logistica {
    public Transporte crearTransporte() {
        return new Barco();
    }
}

 ``` 

##  Adapter🔌

El patrón **Adapter** es un patrón de diseño estructural que permite que objetos con interfaces incompatibles colaboren entre sí. Actúa como un puente entre dos interfaces incompatibles, permitiendo que trabajen juntas sin necesidad de modificar su código fuente.

Imagina que tienes un enchufe de tres patas y una toma de corriente de dos agujeros. Necesitas un adaptador para conectar el enchufe a la toma. De manera similar, el patrón Adapter permite que dos interfaces incompatibles se conecten.

Por ejemplo, supongamos que estamos desarrollando una aplicación que utiliza una interfaz `LectorAudio` para reproducir audio. Sin embargo, tenemos una clase existente `ReproductorMP3` que no implementa esta interfaz. Podemos utilizar el patrón Adapter para que `ReproductorMP3` sea compatible con `LectorAudio`.

Los componentes principales del patrón Adapter son:

1.  **Target (Objetivo)**: La interfaz que el cliente espera utilizar.
    
2.  **Adaptee (Adaptado)**: La clase existente que tiene una interfaz incompatible con la que el cliente espera.
    
3.  **Adapter (Adaptador)**: Una clase que implementa la interfaz Target y traduce las llamadas del cliente a la interfaz del Adaptee.

```Java
// Target
interface LectorAudio {
    void reproducir(String archivo);
}

// Adaptee
class ReproductorMP3 {
    public void playMP3(String nombreArchivo) {
        System.out.println("Reproduciendo archivo MP3: " + nombreArchivo);
    }
}

// Adapter
class AdaptadorReproductorMP3 implements LectorAudio {
    private ReproductorMP3 reproductor;

    public AdaptadorReproductorMP3(ReproductorMP3 reproductor) {
        this.reproductor = reproductor;
    }

    @Override
    public void reproducir(String archivo) {
        reproductor.playMP3(archivo);
    }
}

// Cliente
public class Cliente {
    public static void main(String[] args) {
        ReproductorMP3 reproductorMP3 = new ReproductorMP3();
        LectorAudio lector = new AdaptadorReproductorMP3(reproductorMP3);
        lector.reproducir("cancion.mp3");
    }
}
```

##  Observer 👀
El patrón **Observer** es un patrón de diseño de comportamiento que permite que un objeto (llamado **Sujeto** o **Publisher**) notifique automáticamente a otros objetos (llamados **Observadores** o **Subscribers**) sobre cambios en su estado. Esto establece una relación de uno a muchos entre objetos, promoviendo un diseño desacoplado y flexible.

Imagina que te suscribes a un periódico. Cada vez que se publica una nueva edición, el periódico (Sujeto) te la envía automáticamente, sin que tengas que verificar constantemente si hay una nueva edición.

Por ejemplo
```Java
// Observer
interface Observer {
    void update(String weather);
}

// Subject
interface Subject {
    void addObserver(Observer o);
    void removeObserver(Observer o);
    void notifyObservers();
}

// ConcreteSubject
class WeatherStation implements Subject {
    private List<Observer> observers = new ArrayList<>();
    private String weather;

    public void setWeather(String weather) {
        this.weather = weather;
        notifyObservers();
    }

    public String getWeather() {
        return this.weather;
    }

    @Override
    public void addObserver(Observer o) {
        observers.add(o);
    }

    @Override
    public void removeObserver(Observer o) {
        observers.remove(o);
    }

    @Override
    public void notifyObservers() {
        for (Observer o : observers) {
            o.update(this.weather);
        }
    }
}

// ConcreteObserver
class MobileDevice implements Observer {
    private String deviceName;

    public MobileDevice(String name) {
        this.deviceName = name;
    }

    @Override
    public void update(String weather) {
        System.out.println(deviceName + " recibió actualización del clima: " + weather);
    }
}

// Cliente
public class Main {
    public static void main(String[] args) {
        WeatherStation station = new WeatherStation();

        MobileDevice device1 = new MobileDevice("Dispositivo A");
        MobileDevice device2 = new MobileDevice("Dispositivo B");

        station.addObserver(device1);
        station.addObserver(device2);

        station.setWeather("Soleado");
        station.setWeather("Lluvioso");
    }
}

```
## Colecciones en Java
Cualquier grupo de objetos individuales representados como una sola unidad se conoce como Colección de Objetos. En Java, se ha definido un marco independiente, denominado __"Marco de Colección",__ que alberga todas las clases e interfaces de la Colección de Java. Y existen muchos tipos de colecciones, por ejemplo

- Listas
- Colas
- Pilas
- Tablas hash

### Listas (ArrayList) 
Los ArrayList son parte de todas estas colecciones y que en Java forma parte del paquete de `java.util`. La principal ventaja de un ArrayList es que, a diferencia de los arrays normales, no es necesario especificar el tamaño al crearlo. Ajusta automáticamente su capacidad a medida que se añaden o eliminan elementos. 
```Java
import  java.util.ArrayList; //Importación

class Main  {
  public  static  void  main  (String[]  args)  {
  
  // Creando un ArrayList
  ArrayList<Integer>  a  =  new  ArrayList<Integer>();
  
  // Añadiendo nuevos elementos
  a.add(1);
  a.add(2);
  a.add(3);

  System.out.println(a);  
  }
}
```
Existen muchas operaciones que podemos hacer con un ArrayList, por ejemplo, con una lista podemos agregar, eliminar, actualizar elementos de esa lista.

```Java
import java.util.*;

class Main {
    public static void main(String args[]) {
        // ArrayList de Strings
        ArrayList<String> lenguajes = new ArrayList<>();
      
        // 1. Agregando nuevos elementos

        // Agregando elementos a la lista
        lenguajes.add("Java");
        lenguajes.add("Go");
      
        System.out.println("Lista original: " + lenguajes);
      
        // Añadiendo en un índice específico
        lenguajes.add(1, "JavaScript");
      
        System.out.println("Añadiendo un elemento en la posición 1: " + lenguajes);
      
        // 2. Eliminar elementos usando el índice
        lenguajes.remove(0);
      
        System.out.println("Elemento removido en el índice 0: " + lenguajes);
      
        // Removiendo usando el valor
        lenguajes.remove("JavaScript");
      
        System.out.println("JavaScript eliminado: " + lenguajes);
      
        // 3. Actualizando valores
      
        // Actualizando el valor
        lenguajes.set(0, "Python");
      
        // Imprimiendo todos los lenguajes
        System.out.println("Lista después de la actualización: " + lenguajes);
    }
}
```
Esto nos dará la siguiente salida
```Shell
Lista original : [Java, Go]
Añadiendo un elemento en la posición 1 : [Java, JavaScript, Go]
Elemento removido en el índice 0 : [JavaScript, Go]
JavaScript eliminado : [Go]
Lista después de la actualización del valor : [Java]
```
Esto solo son sus operaciones básicas, sin embargo, existen muchos métodos que podemos usar para una lista, puedes leer más sobre Listas en este enlace [ArrayList in Java](https://www.geeksforgeeks.org/arraylist-in-java/)

### Colas
Las colas también son parte del paquete de `java.util` para recordar un poco de Colas, recordemos que es una estructura dinámica que almacena y procesa los datos en orden FIFO es decir el primero en entrar, es el primero en salir. Es una lista ordenada de objetos, limitada a insertar elementos al final de la lista y eliminar elementos al principio.

Para implementarlo podemos guiarnos del siguiente código:
```Java
import java.util.LinkedList;
import java.util.Queue;

public class QueueExample {
    public static void main(String[] args) {
        Queue<String> languagesQueue = new LinkedList<>();

        // Agregar lenguajes de programación a la cola
        languagesQueue.add("Java");
        languagesQueue.add("Python");
        languagesQueue.add("JavaScript");

        // Imprimir la cola
        System.out.println("Cola de lenguajes: " + languagesQueue);

        // Eliminar el primer elemento de la cola
        String removedLanguage = languagesQueue.remove();
        System.out.println("Lenguaje eliminado: " + removedLanguage);

        // Imprimir la cola actualizada
        System.out.println("Cola después de la eliminación: " + languagesQueue);

        // Agregar otro lenguaje a la cola
        languagesQueue.add("Go");

        // Obtener el primer elemento de la cola sin eliminarlo
        String peekedLanguage = languagesQueue.peek();
        System.out.println("Primer lenguaje en la cola (peek): " + peekedLanguage);

        // Imprimir la cola final
        System.out.println("Cola después de peek: " + languagesQueue);
    }
}
```
La salida seria la siguiente
```Shell
Cola de lenguajes: [Java, Python, JavaScript]  
Lenguaje eliminado: Java  
Cola después de la eliminación: [Python, JavaScript]  
Primer lenguaje en la cola (peek): Python  
Cola después de peek: [Python, JavaScript, Go]  
```

### Pilas

Las pilas también son parte del paquete de `java.util` para recordar un poco de Pilas, recordemos que es una estructura dinámica que siguen el principio LIFO (Last In, First Out), donde el último elemento en entrar es el primero en salir. La clase `Stack` de `java.util` facilita su implementación.

```Java
import java.util.Stack;

public class StackExample {
    public static void main(String[] args) {
        // Creando una pila de lenguajes de programación
        Stack<String> languagesStack = new Stack<>();
        
        // Agregar elementos a la pila
        languagesStack.push("Java");
        languagesStack.push("Python");
        languagesStack.push("JavaScript");
        
        System.out.println("Pila de lenguajes: " + languagesStack);
        
        // Eliminar el elemento superior de la pila
        String removedLanguage = languagesStack.pop();
        System.out.println("Lenguaje eliminado (pop): " + removedLanguage);
        
        // Observar el elemento en la cima sin eliminarlo
        String peekedLanguage = languagesStack.peek();
        System.out.println("Lenguaje en la cima (peek): " + peekedLanguage);
        
        System.out.println("Pila después de pop y peek: " + languagesStack);
    }
}
```
La salida es la siguiente
```
Pila de lenguajes: [Java, Python, JavaScript]
Lenguaje eliminado (pop): JavaScript
Lenguaje en la cima (peek): Python
Pila después de pop y peek: [Java, Python]
```


> Written with [StackEdit](https://stackedit.io/).
