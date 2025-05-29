# Buenas practicas para desarrollo

## Google Java Style

La Guía de Estilo de Java de Google es un conjunto de reglas estrictas que definen cómo debe formatearse el código Java para lograr un aspecto homogéneo en proyectos grandes y colaborativos. 

### Identación
Se utiliza una identación de 2 espacios por nivel. Se deben dejar espacios alrededor de operadores y después de comas para mejorar la legibilidad.

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

## Documentación con JavaDoc 

JavaDoc es la herramienta estándar de Java para generar documentación legible en HTML a partir de comentarios especiales incrustados en el código fuente. Una buena práctica de JavaDoc implica no solo describir la funcionalidad, sino también emplear etiquetas adecuadas y seguir convenciones claras para facilitar el uso de bibliotecas y APIs.

### Estructura de un comentario JavaDoc
```Java
/**
 * <Resumen breve en presente>.
 *
 * <Descripción ampliada, si aplica. Puede incluir varias líneas y listas HTML.>
 *
 * @param nombreParámetro Descripción detallada.
 * @return Descripción de lo que retorna el método.
 * @throws TipoExcepción Condición bajo la cual se lanza.
 * @see OtraClase#otroMétodo()
 * @since Versión
 * @deprecated <Razón y alternativa>
 */
public Tipo método(Tipo nombreParámetro) { ... }
```
Cuando documentos con JavaDoc, es necesario poner los delimitadores obligatorios ``/** ... */**`` . La primera linea debe ser un resumen conciso y despues de una linea en blanco, una descripción detallada.
Existen varias etiquetas que podemos poner cuando documentamos.
| Etiqueta        | Uso breve                                                            | Ejemplo                                       |
|-----------------|----------------------------------------------------------------------|-----------------------------------------------|
| `@param`        | Describe cada parámetro del método.                                  | `@param userId Identificador del usuario.`    |
| `@return`       | Explica el valor que devuelve el método.                             | `@return Lista de usuarios.`                  |
| `@throws`       | Documenta las excepciones que puede lanzar el método.               | `@throws IOException Si falla la lectura.`     |
| `@see`          | Enlaza a clases, métodos o URLs relacionados.                       | `@see java.util.List`                         |
| `@since`        | Indica la versión en la que apareció el elemento.                   | `@since 1.2`                                  |
| `@deprecated`   | Marca elementos obsoletos y su alternativa recomendada.             | `@deprecated Usa newMethod() en su lugar.`    |
| `@author`       | Nombre del autor o del equipo que creó el código.                   | `@author Josse Castillo`                      |
| `@version`      | Especifica la versión actual de la clase o API.                     | `@version 2.0`                                |
| `@serial`       | Documenta un campo serializable en una clase que implementa Serializable. | `@serial UID de la instancia.`                |
| `@serialField`  | Describe un campo serializable específico (JDK 1.4+).                | `@serialField nombreUsuario Campo serializado.` |
| `@serialData`   | Documenta el formato de datos adicionales en writeObject/readObject. | `@serialData Formato: <code>key=value;</code>`|
| `@link`         | Inserta un enlace en línea a otro elemento (en texto).              | `{@link UserManager#createUser}`             |
| `@linkplain`    | Inserta un enlace en línea pero con el texto tal cual.              | `{@linkplain java.io.File File}`              |
| `@literal`      | Muestra texto sin interpretar etiquetas HTML o JavaDoc.             | `{@literal <T>}`                              |
| `@code`         | Formatea un fragmento de código en línea.                           | `{@code Map<String, List<User>>}`             |
| `{@inheritDoc}` | Hereda la documentación del elemento padre (override).              | Usado en Javadoc de métodos sobrescritos.     |
| `@apiNote`      | Añade notas de uso o detalles adicionales para el usuario de la API.| `@apiNote Ejecutar tras inicializar el contexto.` |
| `@implSpec`     | Describe requisitos de implementación para implementadores.         | `@implSpec Debe ser thread-safe.`             |
| `@implNote`     | Notas específicas sobre la implementación interna.                  | `@implNote Usa cache LRU interna.`            |

### Convenciones sobre las etiquetas
1.  **Orden de etiquetas**: siempre `@param`, luego `@return`, `@throws`, y al final las de metadatos (`@since`, `@deprecated`, `@see`).
    
2.  **Consistencia en estilo**: mayúsculas, puntuación y estructura similares en todo el proyecto.
    
3.  **Actualización constante**: sincronizar JavaDoc con cambios de firma o comportamiento.
    
4.  **Evitar redundancia**: no repetir el nombre del parámetro en la descripción.

**Ejemplo:**
```Java
/**
 * Convierte una cadena de texto a formato Title Case (cada palabra inicia en mayúscula).
 *
 * Recorre las palabras separadas por espacios, capitaliza la primera letra
 * y convierte el resto a minúsculas. Devuelve una cadena nueva sin modificar la original.
 *
 * @author José Castillo
 * @author German Santos
 * @version 1.3
 * @since 2.0
 * @param texto Cadena de entrada; no puede ser nula.
 * @return La misma cadena con cada palabra en Title Case.
 * @throws IllegalArgumentException Si {@code texto} es nulo o vacío.
 * @see String#toUpperCase()
 */
public String toTitleCase(String texto) {
    if (texto == null || texto.isBlank()) {
        throw new IllegalArgumentException("El texto no puede ser nulo o vacío.");
    }
    StringBuilder resultado = new StringBuilder();
    for (String palabra : texto.trim().split("\\s+")) {
        resultado.append(Character.toUpperCase(palabra.charAt(0)))
                 .append(palabra.substring(1).toLowerCase())
                 .append(' ');
    }
    return resultado.toString().trim();
}
``` 
## Guía para escribir buenos commits

### 1. Usa el verbo imperativo (`Añadir`,  `Cambiar`,  `Arreglar`,  `Remover`, …)
Aunque el mensaje puede sonar un poco raro el verbo presente es una forma de expresar la acción que se realiza en el commit. Por ejemplo, `Añadir` significa que se añade un nuevo archivo, `Cambiar` significa que se modifica un archivo existente y `Arreglar` significa que se arregla un bug.

![enter image description here](https://imgs.xkcd.com/comics/git_commit_2x.png)

Sé que muchas veces estamos tentados a escribirlo en pasado  _“Añadido…”_,  _“Arreglado…”_  o  _“Removido…”_  pero  **cada commit hay que entenderlo como una instrucción para cambiar el estado del proyecto**. Dicho de otro modo, el verbo presente nos permite saber qué estado queremos que el proyecto se encuentre en el momento de añadir el commit.

Sólo hay que ver también los mensajes de commit que el propio Git nos añade (al hacer merge de una rama usa  `Merge branch`).

### 2. No uses punto final ni puntos suspensivos en tus mensajes
Usar puntuación, más allá de las comas, es innecesario a la hora de crear un buen mensaje de commit. Cada carácter cuenta a la hora de crear un buen mensaje de commit así que no lo desperdicies con puntos innecesarios.
```shell
git commit -m "Add new search feature." # ❌  
git commit -m "Fix a problem with the topbar..." # ❌  
git commit -m "Change the default system color" # ✅
```
¿Por qué? **El primer mensaje de commit es el título del commit.** Y según las reglas de puntuación para títulos, tanto en castellano como en inglés, estos no llevan puntuación final. Sobre los puntos suspensivos… ¡Nuestros commits no deberían tener ningún suspenso! Deben ser una instrucción clara y concisa.

### 3. Usa como máximo 50 carácteres para tu mensaje de commit
Sé corto y conciso. Si tienes mucho que explicar… seguramente es que tu commit hace demasiadas cosas. ¿Puedes separarlo en diferentes commits? Pues hazlo.

Haz que el mensaje sea claro, directo y que realmente refleje los cambios que lleva.
```Shell
git commit -m "Add new search feature and change typography to improve performance" # ❌  
git commit -m "Add new search feature" # ✅  
git commit -m "Change typography to improve performance" # ✅
```
### 4. Usa un prefijo para tus commits para hacerlos más semánticos
Cuando un proyecto crece, es necesario que existan ciertas reglas para que el historial sea legible. Para ello, puedes añadir un prefijo para darle más significado a los commits que realizas. A esto se le llama  _commits semánticos_  y se haría de la siguiente manera:
```shell
<tipo-de-commit>[scope]: <descripcion>
feat: add new search feature
```
Puedes usar los siguientes prefijos
-   **feat**: Una nueva característica para el usuario.
-   **fix**: Arregla un bug que afecta al usuario.
-   **perf**: Cambios que mejoran el rendimiento del sitio.
-   **build**: Cambios en el sistema de build, tareas de despliegue o instalación.
-   **ci**: Cambios en la integración continua.
-   **docs**: Cambios en la documentación.
-   **refactor**: Refactorización del código como cambios de nombre de variables o funciones.
-   **style**: Cambios de formato, tabulaciones, espacios o puntos y coma, etc; no afectan al usuario.
-   **test**: Añade tests o refactoriza uno existente.

En su defecto tambien puedes usar emojis para indicar el tipo de commit que se esta haciendo, por ejemplo usando la herramienta Gitmoji, donde **cada emoji tiene su propia razon de ser**  es decir, no debemos poner el emoji que mejor nos parezca, si no el que este acorde al commit, puedes revisarlo en la siguiente web.
https://gitmoji.dev/
