# Programando Orientado a Objetos

En este laboratorio, exploraremos los conceptos fundamentales de la **Programación Orientada a Objetos (POO)**, que nos permitirá organizar y manipular la información de forma modular y reutilizable en el desarrollo de software.

## ¿Qué es POO?
La **POO** es un paradigma de programación que organiza el código en **clases y objetos** en lugar de funciones y procedimientos. Este enfoque ayuda a estructurar programas grandes en pequeñas unidades de código, cada una con responsabilidades específicas. 

## ¿Qué es una clase?

Una **clase** es un modelo que define las **características** y **funciones** comunes de un objeto de la vida real. Por ejemplo, cuando pensamos en un auto, podemos mencionar diferentes características y funciones del mismo.

<p align="center">
<img src="https://lh7-rt.googleusercontent.com/docsz/AD_4nXdg8xd1vdaLCY7B00Luvd_6fIKD5Ekb55gQk_UePPhz4LrQwXnYyoRP_pqS5tFyT-X0RDnRNX-hglQAGdBG_5kRELskygEGazDn59xBv-eHBXb6QY_DFn7F_eo20j0Wy5dVHsh66Q?key=TWbSt9IEZKXlPl4HjvTS7wsD" width="300"  />
<p/>

Todas las clases en Java pueden contener diferentes propiedades

- Atributos
- Métodos
- Constructor
- Modificador de acceso

Un **atributo** es una característica o propiedad de la clase; es como un dato que describe el objeto. Por ejemplo, en un auto, sus características **comunes** en todos los autos es que pueden estar encendidos, tienen un color, cantidad de puertas, etc. Los atributos, son como tal variables que definimos dentro de la clase.
 ```Java
 String color;
 int puertas;
 boolean encendido; 
```
Un **método**, en cambio, es una acción o comportamiento que puede realizar un objeto de esa clase. Los métodos permiten que el objeto interactúe o realice tareas. En un auto, un método o función **común** podría ser **arrancar** o **encender luces**, el cual describe las acciones que pueden hacer todos los autos.

```Java
 public void encenderLuces() {
     this.encendido = true;
     System.out.println("Las luces de auto estan encendidas");
 }

 public void arrancar() {
     System.out.println("Brmmm");
 }
```

###  Constructores
Un **constructor** es un método especial de una clase que se llama automáticamente cuando se crea un objeto de esa clase. Su función principal es **inicializar los atributos del objeto** y prepararlo para su uso. Los constructores suelen tener el mismo nombre que la clase y no devuelven ningún valor, ni siquiera `void`.

```Java
public Auto(String color, int puertas) {
      this.color = color;
      this.puertas = puertas;
      this.encendido = false; 
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
	Auto(){
		System.out.println("Constructor predeterminado")
	}
	```
**Constructor parametrizado:**
Un constructor que tiene parámetros se conoce como constructor parametrizado. Si queremos inicializar campos de la clase con nuestros propios valores, entonces use un constructor parametrizado.
```Java
public Auto(String color, int puertas) {
      this.color = color;
      this.puertas = puertas;
      this.encendido = false; 
 }
```
> 💡**Nota:** Existe otro tipo de constructor llamado "Constructor copia" sin embargo en Java, no hay tal constructor de copia incorporado disponible como en otros lenguajes de programación como C++, pero se puede implementar.

Los constructores de copia se implementan de la siguiente manera
```Java
public Auto(Auto otroAuto) {
    this.color = otroAuto.color;
    this.puertas = otroAuto.puertas;
    this.encendido = otroAuto.encendido;
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

Para finalizar el tema de clases, crearemos la clase `Auto` que creamos al principio, implementando lo que hemos aprendido.
```Java
public class Auto {
    // Atributos
    String color;
    int puertas;
    boolean encendido;

    // Constructor parametrizado
    public Auto(String color, int puertas, boolean encendido) {
        this.color = color;
        this.puertas = puertas;
        this.encendido = encendido; 
    }
	
	//Metodos
    public void encender() {
        this.encendido = true;
        System.out.println("El auto está encendido.");
    }

    public void apagar() {
        this.encendido = false;
        System.out.println("El auto está apagado.");
    }

    public void mostrarInfo() {
        System.out.println("Color: " + color);
        System.out.println("Número de puertas: " + puertas);
        System.out.println("¿Está encendido? " + (encendido ? "Sí" : "No"));
    }
}
```
## ¿Qué es un objeto?

Ahora que entendemos qué es una clase, sabemos que agrupa las características **comunes** de un objeto. En el apartado anterior, vimos que **todos** los autos pueden encenderse, tienen una cantidad específica de puertas y un color.

Sin embargo, un **objeto** no representa simplemente un concepto general, sino que es una **instancia** de la clase. Es decir, a partir del molde que proporciona la clase, podemos crear autos **específicos**, definiendo sus propias características particulares. 🚗

Los objetos corresponden a cosas que se encuentran en el mundo real, por ejemplo, sabemos que un auto rojo de 2 puertas, no es lo mismo que un auto amarillo de 4 puertas

### Instanciar una clase
Cuando se crea un objeto de una clase, se dice que la clase es **instanciada**. Todas las instancias comparten los atributos y el comportamiento de la clase. Pero los valores de esos atributos, es decir, el estado son únicos para cada objeto. Una sola clase puede tener cualquier número de instancias.

**![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXfmlIYdVLSMzA8_4t2Tg668To7FxKJvCcSGHPGxqK7dTHBDLsp06avp_o1C6WL8vgOxFjKfgJjvtvssgTZkEF4TZlybjeIDbo2Z3m32jsfg-OEqHiAtRXUjPKf8Yd4F3_Ej62NJzg?key=TWbSt9IEZKXlPl4HjvTS7wsD)**

Cuando declaramos variables en el formato `(tipo nombre;),` estamos informando al compilador que utilizaremos `nombre` para hacer referencia a datos cuyo tipo es `tipo`. En el caso de una variable **primitiva**, esta declaración también reserva la cantidad adecuada de memoria para almacenar su valor. 

Sin embargo, para las **variables de referencia**, el tipo debe ser estrictamente el nombre de una clase concreta.

```Java
Auto tesla
```
Si declaramos una variable de referencia como `tesla`, su valor será **indeterminado** (`null`) hasta que se cree un objeto y se le asigne. Es importante recordar que simplemente declarar una variable de referencia **no** crea un objeto.

### Inicializar un objeto
```Java
public class Auto {  
    // Atributos  
  String color;  
    int puertas;  
    boolean encendido;  
  
    // Constructor parametrizado  
  public Auto(String color, int puertas, boolean encendido) {  
        this.color = color;  
        this.puertas = puertas;  
        this.encendido = false;  
    }  
  
    //Metodos  
  public void encender() {  
        this.encendido = true;  
        System.out.println("El auto está encendido.");  
    }  
  
    public void apagar() {  
        this.encendido = false;  
        System.out.println("El auto está apagado.");  
    }  
  
    public void mostrarInfo() {  
        System.out.println("Color: " + color);  
        System.out.println("Número de puertas: " + puertas);  
        System.out.println("¿Está encendido? " + (encendido ? "Sí" : "No"));  
    }   
}

public class Main {
    public static void main(String[] args) {
        Auto tesla = new Auto("Rojo", 4, false);
        tesla.mostrarInfo();
    }
}
```
**Salida**
```shell
Color: Rojo
Número de puertas: 4
¿Está encendido? No
```
Esta clase contiene un solo constructor. Podemos reconocer a un constructor porque su declaración usa el mismo nombre que la clase y no tiene tipo de retorno. El compilador Java diferencia a los constructores en función del número y el tipo de argumentos.

## ¿Qué es programar orientado a Objetos?
Ahora que ya conocemos que es una clase y que es un objeto y como los declaramos y usamos, podremos entrar a programar orientado a objetos, la ****Programación Orientada a Objetos de Java (POO)**** es un concepto fundamental en Java que todo desarrollador debe entender. Permite a los desarrolladores estructurar el código utilizando ****clases y objetos****, haciéndolo más modular, reutilizable y escalable.

La idea central de ****POO**** es enlazar datos y las funciones que operan en él, evitando el acceso no autorizado desde otras partes del código. Java sigue estrictamente el Principio DRY (Don't Repeat Yourself) o en español "No te repitas a ti mismo" , asegurando que la lógica común se escriba una sola vez  y se reutilice en toda la aplicación. Esto hace que el código sea más fácil de mantener, sea mas organizado y fácil de depurar. 

## Pilares de POO
En POO hay 4 pilares esenciales que nos ayudarán a programar orientado a objetos, los cuales son:

- Herencia
- Polimorfismo
- Encapsulación
- Abstracción

## Herencia

La **herencia** es un principio fundamental en la Programación Orientada a Objetos (POO) que permite que una clase llamada **subclase** o **clase hija** herede atributos y métodos de otra clase que se llama **superclase** o **clase padre**

Con la herencia, podemos reutilizar código, reducir la redundancia y facilitar la escalabilidad del software.

Para aplicar herencia en Java, usamos la palabra clave **`extends`**, que indica que una clase está heredando de otra.

```Java
class Superclase {
    String mensaje = "Soy la clase padre";
    
    void mostrarMensaje() {
        System.out.println(mensaje);
    }
}

class Subclase extends Superclase {
    void saludar() {
        System.out.println("Hola desde la clase hija.");
    }
}

public class Main {
    public static void main(String[] args) {
        Subclase obj = new Subclase();
        obj.mostrarMensaje();  // Llama al método heredado de la superclase
        obj.saludar();         // Método propio de la subclase
    }
}
```
En este ejemplo, la clase padre tiene un atributo mensaje, que la subclase no, pero al `extender` de la clase padre, heredo ese atributo y el método `mostrar mensaje` por eso, en el main, podemos usar el método aunque no este definida en la subclase

**![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXcKOEga7__TSUM-8YysGmm6Qzrwpt4-KxJ9rCUDicGTpOrfvDakdIIlUgXk-VixA-L71v1i0ym3KPCWDIGmYdzMBI_YmjFBjoxv5P5HpDP91X3gRqr2Qgsj2yd3VhGDrjmIHXK6IQ?key=TWbSt9IEZKXlPl4HjvTS7wsD)**



#### Sobreescritura de Métodos (`@Override`)
A veces, una subclase necesita **cambiar** el comportamiento de un método que heredó de la superclase. Para esto, usamos la **sobreescritura de métodos**, indicada con `@Override`.

```Java
class Animal {
    void hacerSonido() {
        System.out.println("El animal hace un sonido.");
    }
}

class Perro extends Animal {
    @Override
    void hacerSonido() {
        System.out.println("El perro ladra: ¡Guau guau!");
    }
}

public class Main {
    public static void main(String[] args) {
        Perro miPerro = new Perro();
        miPerro.hacerSonido();  // ¡Guau guau!
    }
}
```
Al hacer `@override` el método que se heredo, se sobrescribió por la que definimos en la hija. Aunque el uso de  `@override` es opcional, es recomendado usarlo.

## Abstracción 
La **abstracción** es un concepto que nos permite enfocarnos en los detalles **importantes** de un objeto, ocultando los aspectos innecesarios. En otras palabras, solo mostramos la información esencial y ocultamos la complejidad interna.

Imagina que estás conduciendo un automóvil. Sabes que al presionar el acelerador, el auto aumenta su velocidad, y que al pisar el freno, se detiene. **Pero no necesitas conocer el funcionamiento interno del motor, los sensores o el sistema de frenos para conducirlo.**

Esto es **abstracción**, ya que solo interactúas con lo necesario (acelerador y frenos), mientras que los detalles técnicos quedan ocultos.

 ```Java
abstract class Vehiculo {
    abstract void acelerar();
    
    // Método concreto (con implementación)
    void frenar() {
        System.out.println("El vehículo se ha detenido.");
    }
}

class Auto extends Vehiculo {
    @Override
    void acelerar() {
        System.out.println("El auto está acelerando...");
    }
}

public class Main {
    public static void main(String[] args) {
        Auto miAuto = new Auto();
        miAuto.acelerar(); // Se llama al método implementado en Auto
        miAuto.frenar();   // Se usa el método de la clase abstracta
    }
}
 ```
 
 ### Clases abstractas
Una **clase abstracta** es una clase que no puede ser instanciada directamente. Su propósito es servir como un **molde** para otras clases, proporcionando una estructura común sin definir completamente su comportamiento.

Para declarar una clase abstracta, usamos la palabra clave **`abstract`**:

 ```Java
 abstract class Vehiculo {
    abstract void acelerar();  // Método abstracto (sin implementación)
    
    void frenar() {  // Método concreto (con implementación)
        System.out.println("El vehículo se ha detenido.");
    }
}

// Subclase que extiende de la clase abstracta
class Auto extends Vehiculo {
    @Override
    void acelerar() {
        System.out.println("El auto está acelerando...");
    }
}

public class Main {
    public static void main(String[] args) {
        Auto miAuto = new Auto();
        miAuto.acelerar();  // Implementación específica en Auto
        miAuto.frenar();    // Método heredado de Vehiculo
    }
}
 ```
 
Como observamos en el código, hemos aprendido dos conceptos importantes:

**Métodos abstractos:** Son aquellos que se declaran, pero no tienen una implementación en la clase padre. Su propósito es definir un comportamiento que las clases hijas **deben** implementar de acuerdo a sus necesidades.

**Métodos concretos:** Son aquellos que **sí tienen** una implementación en la clase padre y pueden ser heredados y utilizados por las clases hijas sin necesidad de redefinirlos (aunque pueden ser sobrescritos si es necesario como vimos en herencia).

### Interfaces
Una **interfaz** en Java es una especie de "contrato" que define un conjunto de métodos que una clase debe implementar. A diferencia de las clases abstractas, una interfaz **no tiene atributos ni métodos con implementación**

```Java
interface Vehiculo {
    void acelerar(); // Método abstracto
    void frenar();   // Método abstracto
}

class Auto implements Vehiculo {
    @Override
    public void acelerar() {
        System.out.println("El auto está acelerando...");
    }

    @Override
    public void frenar() {
        System.out.println("El auto se ha detenido.");
    }
}

public class Main {
    public static void main(String[] args) {
        Auto miAuto = new Auto();
        miAuto.acelerar();  // El auto está acelerando...
        miAuto.frenar();    // El auto se ha detenido.
    }
}
```
En este caso, su funcionamiento es similar al de una clase abstracta, con la diferencia de que una interfaz **solo permite métodos sin implementar** .  Además, en lugar de **extender** una interfaz, las clases la **implementan**, lo que les permite definir su propio comportamiento para los métodos especificados en la interfaz.

## Polimorfismo
El **polimorfismo** es un concepto fundamental de la **Programación Orientada a Objetos (POO)** que permite que los objetos de diferentes clases respondan de manera distinta a un mismo método.

En Java, el polimorfismo permite que un mismo mensaje (llamada a un método) se **manifieste de diferentes formas** según el tipo de objeto que lo reciba. Esto brinda flexibilidad y reutilización del código. 

Imagina que tienes una **clase base llamada `Vehiculo`** y varias subclases como **`Auto`**, **`Moto`** y **`Camion`**. Todos son vehículos, pero cada uno se comporta de manera diferente.

El **polimorfismo** permite que podamos tratar todos estos objetos como `Vehiculo`, pero que **cada uno implemente su propio comportamiento**.

Piensa en un **vehículo genérico**:

-   Un **auto** se conduce con volante y pedales.
    
-   Una **moto** se maneja con manillar y acelerador.
    
-   Un **camión** necesita más potencia y puede transportar carga pesada.

Aunque todos son **vehículos**, cada uno **se comporta diferente** según su tipo. 

```Java
class Vehiculo {
    void conducir() {
        System.out.println("Estoy conduciendo un vehículo genérico.");
    }
}

class Auto extends Vehiculo {
    @Override
    void conducir() {
        System.out.println("Conduciendo un auto con volante y pedales.");
    }
}

class Moto extends Vehiculo {
    @Override
    void conducir() {
        System.out.println("Conduciendo una moto con manillar y acelerador.");
    }
}

class Camion extends Vehiculo {
    @Override
    void conducir() {
        System.out.println("Conduciendo un camión de carga pesada.");
    }
}
```
> 💡**Extra**: Esto puedes aplicarlo usando **abstracción** usando una clase abstracta o una interfaz y así no usar `@override` 

### Tipos de polimorfismo
Existen diferentes tipos de polimorfismo, por ejemplo
#### Polimorfismo en tiempo de compilación (Sobrecarga de métodos)
Cuando un vehículo puede moverse a diferentes velocidades, podemos sobrecargar el método `mover()` según los parámetros.

 La **sobrecarga de métodos** (o _method overloading_) ocurre cuando una clase tiene **múltiples métodos con el mismo nombre**, pero con **diferentes parámetros** (ya sea en el número de parámetros o en el tipo de los parámetros).

Esto le permite a un método realizar **acciones similares**, pero dependiendo de los argumentos que reciba. Es una forma de reutilizar el nombre del método para diferentes propósitos.

```Java
class Vehiculo {
    void mover() {
        System.out.println("El vehículo se está moviendo.");
    }

    void mover(int velocidad) {
        System.out.println("El vehículo se mueve a " + velocidad + " km/h.");
    }
}

public class Main {
    public static void main(String[] args) {
        Vehiculo v = new Vehiculo();
        v.mover(); // El vehículo se está moviendo.
        v.mover(80); // El vehículo se mueve a 80 km/h.
    }
}
```

#### **Polimorfismo en Tiempo de Ejecución** (Anulación de Métodos)

El **polimorfismo en tiempo de ejecución** ocurre cuando una subclase proporciona su propia implementación de un método que ya está definido en su clase padre. Esto se logra mediante la **anulación de métodos**.

Cuando un método es anulado, el método que se ejecuta se determina en **tiempo de ejecución** según el tipo de objeto real, no el tipo de la referencia.

```Java
class Vehiculo {
    void conducir() {
        System.out.println("Conduciendo un vehículo genérico.");
    }
}

class Auto extends Vehiculo {
    @Override
    void conducir() {
        System.out.println("Conduciendo un auto con volante y pedales.");
    }
}

class Moto extends Vehiculo {
    @Override
    void conducir() {
        System.out.println("Conduciendo una moto con manillar y acelerador.");
    }
}

public class Main {
    public static void main(String[] args) {
        Vehiculo v = new Auto();
        v.conducir();  // Conduciendo un auto con volante y pedales.

        v = new Moto();
        v.conducir();  // Conduciendo una moto con manillar y acelerador.
    }
}
```
> Cuando usas una referencia de tipo `Vehiculo` para apuntar a un objeto `Auto`, Java ejecuta el método `conducir()` de `Auto`, no el de `Vehiculo`. Esto se debe al enlace dinámico, que resuelve en tiempo de ejecución según el objeto real

## Encapsulación
La encapsulación implica restringir el acceso directo a algunos de los componentes de un objeto y permitir que solo se accedan o modifiquen mediante métodos definidos por la clase. En otras palabras, los atributos de un objeto no deben ser accesibles directamente desde fuera de la clase, en su lugar, deben ser modificados o leídos a través de métodos.

La encapsulación se logra principalmente con **modificadores de acceso** y **métodos de acceso**.

-   **Métodos de acceso:**
    
    -   **Getters:** Métodos que permiten obtener el valor de un atributo privado.
        
    -   **Setters:** Métodos que permiten modificar el valor de un atributo privado, con validaciones si es necesario.

```Java
public class Auto {
    // Atributos privados
    private String color; // ✅ Restringe acceso directo
    private int puertas;
    private boolean encendido;

    // Constructor
    public Auto(String color, int puertas, boolean encendido) {
        this.color = color;
        this.puertas = puertas;
        this.encendido = encendido;
    }

    // Métodos públicos para acceder y modificar los atributos (getters y setters)

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public int getPuertas() {
        return puertas;
    }

    public void setPuertas(int puertas) {
        if (puertas > 0) { 
            this.puertas = puertas;
        }
    }

    // Métodos
    public void encender() {
        this.encendido = true;
        System.out.println("El auto está encendido.");
    }

    public void apagar() {
        this.encendido = false;
        System.out.println("El auto está apagado.");
    }

    public void mostrarInfo() {
        System.out.println("Color: " + color);
        System.out.println("Número de puertas: " + puertas);
        System.out.println("¿Está encendido? " + (encendido ? "Sí" : "No"));
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


# Anexos
-   **Documentación oficial de Oracle Java**: Guía completa de la plataforma Java y tutoriales sobre POO.
    
    -   https://docs.oracle.com/en/java/
   -   **Java Cheat Sheet (PDF)**: Resumen rápido de sintaxis y patrones de uso.
    
	    -   https://introcs.cs.princeton.edu/java/11cheatsheet/
        
-   **Canal de YouTube "Java Brains"**: Vídeos sobre principios de POO, patrones y buenas prácticas.
    
    -   [https://www.youtube.com/user/koushks](https://www.youtube.com/user/koushks)
