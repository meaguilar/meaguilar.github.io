
# Programando Orientado a Objetos

En este laboratorio, exploraremos los conceptos fundamentales de la **Programación Orientada a Objetos (POO)**, que nos permitirá organizar y manipular la información de forma modular y reutilizable en el desarrollo de software.

## ¿Qué es POO?
POO organiza el software en **clases y objetos** para mejorar orden, reutilizacion y mantenimiento.

## ¿Qué es una clase?
![Clase](POO/Markdown/Laboratorios%202026/imagenes/Laboratorio_1/1.png)
![Atributos](POO/Markdown/Laboratorios%202026/imagenes/Laboratorio_1/4.png)
![Metodos](POO/Markdown/Laboratorios%202026/imagenes/Laboratorio_1/3.png)

Una clase define:

- Atributos (características)
- Metodos (acciones)
- Constructores
- Modificadores de acceso

```java
public class Mascota {
    String nombre;
    int edad;
    boolean comiendo;
    
    public void comer() {
        this.comiendo = true;
        System.out.println("Ñam Ñam Ñam");
    }

    public void hacerSonido() {
        System.out.println("Woof!");
    }
}
```

## ¿Qué es un objeto?

![¿Qué es un objeto?](POO/Markdown/Laboratorios%202026/imagenes/Laboratorio_1/2.png)

Un objeto es una instancia concreta de una clase.


### Instanciar una clase

![Instanciacion de una clase](POO/Markdown/Laboratorios%202026/imagenes/Laboratorio_1/9.png)

Declarar una referencia no crea el objeto; se crea con `new`.

```java
Mascota perro;
perro = new Mascota("Spike", 3);
```

### Inicializar y usar un objeto

```Java
public class Main {

    public static void main(String[] args) {
        Mascota  perro = new  Mascota("Spike", 3, false);
        perro.mostrarInfo();
    }

}
```

**Salida**
```shell
Nombre:  Spike
Edad:  3
¿Está  comiendo?  No
```

### Abstracción

![Abstracción](POO/Markdown/Laboratorios%202026/imagenes/Laboratorio_1/10.png)

Abstraer es modelar solo lo necesario del problema.

### Constructores

![Constructores](POO/Markdown/Laboratorios%202026/imagenes/Laboratorio_1/5.png)

Un constructor inicializa el objeto al crearlo.

```Java
    //Constructor predeterminado explícito
    Mascota(){
        System.out.println("Constructor predeterminado")
    }
```

```Java
    //Constructor parametrizado
    public Mascota(String nombre, int edad) {
        this.nombre = nombre;
        this.edad = edad;
        this.comiendo = false;
    }
```
```Java
    //Constructor Copia
    public Mascota(Mascota otraMascota) {
        this.nombre = otraMascota.nombre;
        this.edad = otraMascota.edad;
        this.comiendo = otraMascota.comiendo;
    }

```
> 💡****Nota:**** No es necesario escribir un constructor para una clase. Es porque el compilador java crea un constructor predeterminado (constructor sin argumentos) si su clase no tiene ninguno.

### Encapsulamiento

![Encapsulamiento](POO/Markdown/Laboratorios%202026/imagenes/Laboratorio_1/7.png)

Encapsular protege los atributos y controla el acceso mediante metodos.

```java
public class Mascota {
    // Atributos encapsulados
    private String nombre;
    private int edad;
    private  boolean  comiendo;

    // Constructor

    public  Mascota(String  nombre, int  edad, boolean  comiendo) {
        this.nombre = nombre;
        this.edad = edad;
        this.comiendo= comiendo;
    }
    // Métodos de acceso (getters y setters)
    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public int getEdad() {
        return edad;
    }

    public void setEdad(int edad) {
        this.edad = edad;
    }

    public  boolean  isComiendo() {
        return comiendo;
    }

    public  void  setComiendo(boolean  comiendo) {
        this.comiendo= comiendo;
    }
}
```

#### Modificadores de acceso

![Modificadores de acceso](POO/Markdown/Laboratorios%202026/imagenes/Laboratorio_1/6.png)

|Modificador|Clase misma|Paquete|Subclases|Todo proyecto|
|-|-|-|-|-|
|`public`|✅|✅|✅|✅|
| | 
|`private`|✅|✅|✅|❌|
| | 
|(default)|✅|✅|❌|❌|
| |
|private|✅|❌|❌|❌|

  
> 💡**Nota**: _Las interfaces y clases anidadas pueden tener todos los modificadores de acceso._  
💡**Nota**: _No podemos declarar clase/interfaz con modificadores de acceso privados o protegidos._
💡**Nota**: _Los paquetes son carpetas lógicas que mantienen tu código limpio y organizado, como cajones en tu escritorio_ 

### Uso de `this` 

![Uso de this](POO/Markdown/Laboratorios%202026/imagenes/Laboratorio_1/8.png)

- `this`: referencia al objeto actual.
```Java
public  class  Mascota {
    String  nombre;
    int  edad;
    boolean  commiendo;

    public  Mascota(String  nombre, int  edad, boolean  comiendo) {
        this.nombre = nombre; // 'this.nombre' es el atributo de la clase
        this.edad = edad;  // 'edad' es el parámetro del constructor
        this.comiendo= comiendo;
    }

    public  void  hacerSonido() {
        System.out.println("La mascota hace un sonido genérico.");
    }
}
```

## Implementando lo que hemos aprendido
<a  href="POO/Markdown/Laboratorios%202026/Anexos/Ejercicios/Laboratorio1/Mascota.java"  target="_blank"  rel="noopener">Ver clase Mascota.java</a>
## Cierre
POO permite escribir codigo mas claro, reutilizable y facil de mantener mediante clases y objetos.

# Anexos
-   **Documentación oficial de Oracle Java**: Guía completa de la plataforma Java y tutoriales sobre POO.
    
    -   https://docs.oracle.com/en/java/
   -   **Java Cheat Sheet (PDF)**: Resumen rápido de sintaxis y patrones de uso.
    
        -   https://introcs.cs.princeton.edu/java/11cheatsheet/
        
-   **Canal de YouTube "Java Brains"**: Vídeos sobre principios de POO, patrones y buenas prácticas.
    
    -   [https://www.youtube.com/user/koushks](https://www.youtube.com/user/koushks)