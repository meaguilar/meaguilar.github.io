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

# ANEXOS
-   [Catalogo de patrones de diseño (Refactoring Guru)](https://refactoring.guru/design-patterns/catalog) - Explica todos los patrones de diseño de manera grafica.

