# Programando Orientado a Objetos

En este laboratorio, exploraremos los conceptos fundamentales de la **Programación Orientada a Objetos (POO)**, que nos permitirá organizar y manipular la información de forma modular y reutilizable en el desarrollo de software.

## ¿Qué es POO?
La **POO** es un paradigma de programación que organiza el código en **clases y objetos** en lugar de funciones y procedimientos. Este enfoque ayuda a estructurar programas grandes en pequeñas unidades de código, cada una con responsabilidades específicas. 

## ¿Qué es una clase?

Una **clase** es un modelo que define las **características** y **acciones** comunes de un objeto de la vida real. Por ejemplo, cuando pensamos en una mascota, podemos mencionar diferentes características y acciones del mismo. 

<p align="center">
<img src="https://lh7-rt.googleusercontent.com/docsz/AD_4nXdg8xd1vdaLCY7B00Luvd_6fIKD5Ekb55gQk_UePPhz4LrQwXnYyoRP_pqS5tFyT-X0RDnRNX-hglQAGdBG_5kRELskygEGazDn59xBv-eHBXb6QY_DFn7F_eo20j0Wy5dVHsh66Q?key=TWbSt9IEZKXlPl4HjvTS7wsD" width="300"  />
<p/>

Todas las clases en Java pueden contener diferentes propiedades

- Atributos
- Métodos
- Constructor
- Modificador de acceso

Un **atributo** es una característica o propiedad de la clase; es como un dato que describe el objeto. Por ejemplo, en una mascota, sus características **comunes** en todos las mascotas es que tienen un tipo, un nombre, edad, etc. Los atributos, son como tal variables que definimos dentro de la clase.
 ```Java
String nombre;
int edad;
boolean comiendo;
```
Un **método**, en cambio, es una acción o comportamiento que puede realizar un objeto de esa clase. Los métodos permiten que el objeto interactúe o realice tareas. En una mascota, un método o función **común** podría ser **comer** o **hacer sonido**, el cual describe las acciones que pueden hacer todas las mascotas.

```Java
 public void comer() {
     this.comiendo = true;
     System.out.println("Ñam Ñam Ñam");
 }

 public void hacerSonido() {
     System.out.println("Woof!");
 }
```

###  Constructores
Un **constructor** es un método especial de una clase que se llama automáticamente cuando se crea un objeto de esa clase. Su función principal es **inicializar los atributos del objeto** y prepararlo para su uso. Los constructores suelen tener el mismo nombre que la clase y no devuelven ningún valor, ni siquiera `void`.

```Java
public Mascota(String nombre, int edad) {
      this.nombre = nombre;
      this.edad = edad;
      this.comiendo = false; 
 }
```
> 💡****Nota:**** No es necesario escribir un constructor para una clase. Es porque el compilador java crea un constructor predeterminado (constructor sin argumentos) si su clase no tiene ninguno.

#### Tipos de constructores
Existen tres tipos de constructores, los cuales son
 -   Constructor Predeterminado
-   Constructor Parametrizado

**Constructor predeterminado:**
El constructor predeterminado es el que se menciono anteriormente, es el que el compilador de Java crea automáticamente si no definimos un constructor, el constructor predeterminado se puede crear 

- **Implícito:**  Este constructor no toma ningún parámetro e inicializa el objeto con valores predeterminados, como `0` para números, `null` para objetos.

- **Explicito:** Si definimos un constructor que no toma parámetros, se llama un constructor predeterminado explícito
	```Java
	Mascota(){
		System.out.println("Constructor predeterminado")
	}
	```
**Constructor parametrizado:**
Un constructor que tiene parámetros se conoce como constructor parametrizado. Si queremos inicializar campos de la clase con nuestros propios valores, entonces use un constructor parametrizado.

```Java
public Mascota(String nombre, int edad) {
      this.nombre = nombre;
      this.edad = edad;
      this.comer = false; 
 }
```
> 💡**Nota:** Existe otro tipo de constructor llamado "Constructor copia" sin embargo en Java, no hay tal constructor de copia incorporado disponible como en otros lenguajes de programación como C++, pero se puede implementar.

Los constructores de copia se implementan de la siguiente manera
```Java
public Mascota(Mascota otraMascota) {
    this.nombre = otraMascota.nombre;
    this.edad = otraMascota.edad;
    this.comiendo = otraMascota.comiendo;
}
``` 


### Modificadores de acceso
Los métodos y los miembros de datos pueden encapsularse mediante los siguientes cuatro modificadores de acceso. Los modificadores de acceso se enumeran de acuerdo con su orden de restricción.

- **Publico**: Puede ser accesible por cualquier clase
- **Privado**: Solo es accesible dentro de la clase donde se definió
- **Protegido** : Accesible solo para clases que subclasifican su clase directamente dentro del paquete actual o diferente
- **Predeterminado**: Por defecto, cuando no se especifica modificador, es  _package-private_ es decir es accesible solo dentro del mismo paquete


En general, las clases y las interfaces en sí pueden tener solo dos modificadores de acceso cuando se declaran fuera de cualquier otra clase.
> 💡**Nota**: _Las interfaces y clases anidadas pueden tener todos los modificadores de acceso._  
💡**Nota**: _No podemos declarar clase/interfaz con modificadores de acceso privados o protegidos._

Para finalizar el tema de clases, crearemos la clase `Mascota` que creamos al principio, implementando lo que hemos aprendido.
```Java
public class Mascota {

    // Atributos
    String nombre;
    int edad;
    boolean durmiendo;

    // Constructor parametrizado
    public Mascota(String nombre, int edad, boolean durmiendo) {
        this.nombre = nombre;
        this.edad = edad;
        this.durmiendo = durmiendo;
    }

    // Métodos
    public void dormir() {
        this.durmiendo = true;
        System.out.println("La mascota está durmiendo.");
    }

    public void despertar() {
        this.durmiendo = false;
        System.out.println("La mascota está despierta.");
    }

    public void mostrarInfo() {
        System.out.println("Nombre: " + nombre);
        System.out.println("Edad: " + edad);
        System.out.println("¿Está durmiendo? " + (durmiendo ? "Sí" : "No"));
    }
}
```
## ¿Qué es un objeto?

Ahora que entendemos qué es una clase, sabemos que agrupa las características **comunes** de un objeto. En el apartado anterior, vimos que **todas** las mascotas pueden dormir , tienen una edad y un nombre.

Sin embargo, un **objeto** no representa simplemente un concepto general, sino que es una **instancia** de la clase. Es decir, a partir del molde que proporciona la clase, podemos tener mascotas **específicas**, definiendo sus propias características particulares. 

### Instanciar una clase
Cuando se crea un objeto de una clase, se dice que la clase es **instanciada**. Todas las instancias comparten los atributos y el comportamiento de la clase. Pero los valores de esos atributos, es decir, el estado son únicos para cada objeto. Una sola clase puede tener cualquier número de instancias.

**![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXfmlIYdVLSMzA8_4t2Tg668To7FxKJvCcSGHPGxqK7dTHBDLsp06avp_o1C6WL8vgOxFjKfgJjvtvssgTZkEF4TZlybjeIDbo2Z3m32jsfg-OEqHiAtRXUjPKf8Yd4F3_Ej62NJzg?key=TWbSt9IEZKXlPl4HjvTS7wsD)**

Cuando declaramos variables en el formato `(tipo nombre;),` estamos informando al compilador que utilizaremos `nombre` para hacer referencia a datos cuyo tipo es `tipo`. En el caso de una variable **primitiva**, esta declaración también reserva la cantidad adecuada de memoria para almacenar su valor. 

Sin embargo, para las **variables de referencia**, el tipo debe ser estrictamente el nombre de una clase concreta.

```Java
Mascota perro
```
Si declaramos una variable de referencia como `perro`, su valor será **indeterminado** (`null`) hasta que se cree un objeto y se le asigne. Es importante recordar que simplemente declarar una variable de referencia **no** crea un objeto.

### Inicializar un objeto
```Java
public class Mascota {

    // Atributos
    String nombre;
    int edad;
    boolean durmiendo;

    // Constructor parametrizado
    public Mascota(String nombre, int edad, boolean durmiendo) {
        this.nombre = nombre;
        this.edad = edad;
        this.durmiendo = durmiendo;
    }

    // Métodos
    public void dormir() {
        this.durmiendo = true;
        System.out.println("La mascota está durmiendo.");
    }

    public void despertar() {
        this.durmiendo = false;
        System.out.println("La mascota está despierta.");
    }

    public void mostrarInfo() {
        System.out.println("Nombre: " + nombre);
        System.out.println("Edad: " + edad);
        System.out.println("¿Está durmiendo? " + (durmiendo ? "Sí" : "No"));
    }
}
public class Main {
    public static void main(String[] args) {

        Mascota perro = new Mascota("Spike", 3, false);
        perro.mostrarInfo();

    }
}
```
**Salida**
```shell
Nombre: Spike
Edad: 3
¿Está durmiendo? No
```
Esta clase contiene un solo constructor. Podemos reconocer a un constructor porque su declaración usa el mismo nombre que la clase y no tiene tipo de retorno. El compilador Java diferencia a los constructores en función del número y el tipo de argumentos.

## ¿Qué es programar orientado a Objetos?
Ahora que ya conocemos que es una clase y que es un objeto y como los declaramos y usamos, podremos entrar a programar orientado a objetos, la ****Programación Orientada a Objetos de Java (POO)**** es un concepto fundamental en Java que todo desarrollador debe entender. Permite a los desarrolladores estructurar el código utilizando ****clases y objetos****, haciéndolo más modular, reutilizable y escalable.

La idea central de ****POO**** es enlazar datos y las funciones que operan en él, evitando el acceso no autorizado desde otras partes del código. Java sigue estrictamente el Principio DRY (Don't Repeat Yourself) o en español "No te repitas a ti mismo" , asegurando que la lógica común se escriba una sola vez  y se reutilice en toda la aplicación. Esto hace que el código sea más fácil de mantener, sea mas organizado y fácil de depurar. 

# Anexos
-   **Documentación oficial de Oracle Java**: Guía completa de la plataforma Java y tutoriales sobre POO.
    
    -   https://docs.oracle.com/en/java/
   -   **Java Cheat Sheet (PDF)**: Resumen rápido de sintaxis y patrones de uso.
    
	    -   https://introcs.cs.princeton.edu/java/11cheatsheet/
        
-   **Canal de YouTube "Java Brains"**: Vídeos sobre principios de POO, patrones y buenas prácticas.
    
    -   [https://www.youtube.com/user/koushks](https://www.youtube.com/user/koushks)
