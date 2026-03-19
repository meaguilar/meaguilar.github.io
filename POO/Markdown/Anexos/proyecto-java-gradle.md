
# Proyectos con Java - Gradle 

### Importancia de usar Gradle

Diseñar proyectos de **Java con Gradle y el DSL de Groovy** es importante porque permite automatizar y estandarizar el proceso de construcción del software. **Gradle** facilita la gestión de dependencias, la compilación, las pruebas y el empaquetado en un solo flujo eficiente. Por su parte, **Groovy** es el **DSL (Lenguaje Específico de Dominio)** utilizado por Gradle; su sintaxis clara y flexible permite escribir menos código y comprender mejor cómo funciona el proceso de construcción.

## Configurando un proyecto de Java con Gradle 

-   Abrir **IntelliJ IDEA**.
-   Crear un **nuevo proyecto Java**.
-   Asignar un **nombre al proyecto**.
-   Elegir el **directorio de almacenamiento**.
-   Seleccionar la **versión de JDK** requerida.
-   Establecer **Gradle** como herramienta de construcción.
-   Elegir **Groovy** como DSL para Gradle.

![Configurando proyecto Java](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/e1c828c082e2dc8749e097d4d708d6a7bd805383/POO/imagenes/proyectos-java-gradle/1.png)

### Estructura de un proyecto Java  con Gradle 

![Estructura proyecto Java](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/e1c828c082e2dc8749e097d4d708d6a7bd805383/POO/imagenes/proyectos-java-gradle/2.png)

# Configuración del archivo build.gradle


## Configurar la clase principal que lanza la aplicación al iniciar

Al crear un proyecto, es necesario configurar el archivo **build.gradle** para especificar la clase principal que se debe ejecutar. De lo contrario, al compilar, se producirá un error porque el sistema no podrá localizar la clase  que se debe **ejecutar al iniciar la aplicación**.

-   El **`id 'application'`** activa el _plugin de aplicación_ de Gradle, que permite ejecutar, empaquetar y crear archivos ejecutables de tu proyecto Java.
    
-   La propiedad **`mainClass`** indica la **clase principal** con el método `main(String[] args)` que debe ejecutarse al iniciar el programa.

```groovy
id: 'application'

// Si la clase principal NO está en ningún paquete  
application {  
	mainClass = 'Main'  
}  
  
// Si la clase principal SÍ está dentro de un paquete  
application {  
	mainClass = 'com.abc.Main'  
}
```
![Configurando clase principal](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/e1c828c082e2dc8749e097d4d708d6a7bd805383/POO/imagenes/proyectos-java-gradle/3.png)

Una vez realizados los cambios en el **build.gradle**, es necesario **actualizar el proyecto** para que Gradle reconozca las modificaciones. Para ello, haz clic en el botón de **Gradle** que aparece sobre el archivo **build.gradle** y selecciona la opción de **refresh**.

![Actualizando build.gradle](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/e1c828c082e2dc8749e097d4d708d6a7bd805383/POO/imagenes/proyectos-java-gradle/4.png)

## Entrada de datos por consola con Gradle

Para permitir la **entrada de datos por consola** en un proyecto Java con Gradle, es necesario **configurar correctamente el archivo `build.gradle`**.

 - La propiedad **`standardInput`** de una tarea como `run` indica **de dónde tomará la entrada de datos el programa que se ejecuta**
 
Por defecto, cuando ejecutas un programa Java desde **Gradle**, **no se permite ingresar datos por consola**.

```groovy
// Activar la entrada de datos por consola
run {  
  standardInput = System.in  
}
```

![Activar entrada de datos por consola](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/e1c828c082e2dc8749e097d4d708d6a7bd805383/POO/imagenes/proyectos-java-gradle/10.png)

Siempre que se realicen cambios en el **archivo `build.gradle`**, es necesario **actualizar el proyecto** para que Gradle reconozca y aplique correctamente las modificaciones.

## Panel de Gradle 

Este panel ofrece varias opciones, incluyendo la **terminal**, donde puedes ingresar comandos, así como **buscar y seleccionar** el que necesites.

![Panel de gradle ](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/e1c828c082e2dc8749e097d4d708d6a7bd805383/POO/imagenes/proyectos-java-gradle/5.png)

![Terminal de gradle](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/e1c828c082e2dc8749e097d4d708d6a7bd805383/POO/imagenes/proyectos-java-gradle/6.png)

## Comandos Gradle 

### Compilar 

Para compilar el proyecto,  ejecutar el comando **`gradle build`** desde la **ventana de comandos** integrada en **IntelliJ IDEA**.

![Uso de gradle build](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/e1c828c082e2dc8749e097d4d708d6a7bd805383/POO/imagenes/proyectos-java-gradle/7.png)

### Compilar y ejecutar 

Para compilar y ejecutar el proyecto al mismo tiempo, utiliza el comando **`gradle run`** desde la **ventana de comandos** integrada en **IntelliJ IDEA**.

![Uso de gradle run](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/e1c828c082e2dc8749e097d4d708d6a7bd805383/POO/imagenes/proyectos-java-gradle/8.png) 

```

    Recuerda que los comandos de Gradle solo están disponibles dentro 
    del proyecto. Para poder utilizarlos fuera del IDE, es necesario 
    instalar Gradle de forma global en tu computadora.

 ```

##  Proyecto Java compilado y ejecutando con Gradle

![Proyecto compilado y ejecutado](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/e1c828c082e2dc8749e097d4d708d6a7bd805383/POO/imagenes/proyectos-java-gradle/9.png)



