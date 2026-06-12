# JavaFX – Guía de Propiedades

---

## Introducción

JavaFX es un framework para el desarrollo de **interfaces gráficas (GUI)** en Java. Permite crear aplicaciones modernas utilizando una arquitectura que separa la presentación visual de la lógica de negocio.

Para una mejor organización del proyecto, se recomienda utilizar el patrón **MVC (Model-View-Controller)**, que separa las responsabilidades de la aplicación:

* **Model:** contiene la lógica de negocio y los datos.
* **View:**
  * **FXML:** estructura de la interfaz.
  * **CSS:** diseño visual de los componentes.
* **Controller:** conecta la vista con el modelo y gestiona los eventos del usuario.

Esta organización facilita el mantenimiento, la reutilización y el crecimiento de la aplicación.


---
## Propiedades CSS en JavaFX

Permiten modificar la **apariencia visual** de los componentes, como colores, fuentes, bordes y tamaños. JavaFX utiliza archivos CSS para separar el diseño de la lógica de la aplicación.

| Propiedad | Descripción |
|----------|------------|
| `-fx-background-color` | Color de fondo |
| `-fx-background-image` | Imagen de fondo |
| `-fx-background-size` | Tamaño del fondo |
| `-fx-background-position` | Posición del fondo |
| `-fx-background-radius` | Bordes redondeados del fondo |
| `-fx-border-color` | Color del borde |
| `-fx-border-width` | Grosor del borde |
| `-fx-border-radius` | Bordes redondeados del borde |
| `-fx-text-fill` | Color del texto |
| `-fx-font-size` | Tamaño de fuente |
| `-fx-font-family` | Tipo de letra |
| `-fx-font-weight` | Grosor de fuente |
| `-fx-opacity` | Transparencia |
| `-fx-cursor` | Tipo de cursor |


### Ejemplo CSS
```css 
.boton-principal {
    -fx-background-color: #3498db;
    -fx-text-fill: white;
    -fx-font-size: 14px;
    -fx-background-radius: 8;
}
```

## Propiedades FXML

FXML es un **lenguaje basado en XML** que permite definir la estructura visual de una interfaz JavaFX sin escribir código Java para cada componente.

| Propiedad | Descripción |
|----------|------------|
| `fx:id` | Identificador para el Controller |
| `fx:controller` | Clase controladora |
| `xmlns` | Namespace de JavaFX |
| `stylesheets` | Archivo CSS externo |
| `styleClass` | Clase CSS asignada |
| `style` | Estilo inline |

### Ejemplo FXML
```xml
<Button fx:id="btnGuardar" text="Guardar" styleClass="boton-principal"/>
```

En este ejemplo, el botón podrá ser manipulado desde el Controller mediante **btnGuardar** y utilizará los estilos definidos en la **clase CSS boton-principal**.

---

## Eventos en JavaFX

Los eventos permiten responder a las **acciones realizadas por el usuario**.

| Evento | Descripción |
|--------|------------|
| `onAction` | Acción de botón |
| `onMouseClicked` | Click del mouse |
| `onKeyPressed` | Tecla presionada |
| `onKeyReleased` | Tecla liberada |

```xml
<Button text="Aceptar"
        onAction="#guardarDatos"
        styleClass="boton-principal"/>
```

```java
@FXML
private void guardarDatos() {
    System.out.println("Datos guardados");
}
```

Cuando el usuario presione el botón, se ejecutará el método `guardarDatos()` definido en el Controller.

---

## Asociar un archivo CSS desde FXML

También es posible vincular directamente el archivo CSS como una propiedad del contenedor raíz:

```xml
<AnchorPane xmlns:fx="http://javafx.com/fxml"
            fx:controller="com.ejemplo.Controlador"
            stylesheets="@estilos.css">
</AnchorPane>
```

De esta manera, todos los componentes contenidos en el `AnchorPane` podrán utilizar los estilos definidos en el archivo `estilos.css`.

--- 
## Asociar un archivo CSS desde la clase principal

También es posible cargar la hoja de estilos desde la clase principal de la aplicación.

```java
scene.getStylesheets().add(
    getClass().getResource("/css/estilos.css").toExternalForm()
);
```
## Explicación

* `getResource("/css/app.css")` busca el archivo CSS dentro de la carpeta `resources/css`.
* `toExternalForm()` convierte la ubicación del archivo en una URL que JavaFX puede interpretar.
* `getStylesheets().add(...)` agrega la hoja de estilos a la escena actual.

## Ventajas de este método

* Permite aplicar la misma hoja de estilos a múltiples ventanas o escenas.
* Centraliza la configuración visual de la aplicación.
* Facilita el cambio de temas (por ejemplo, modo claro y modo oscuro).
* Evita repetir la referencia al archivo CSS en cada archivo FXML.

## Biblioteca de diseño MaterialFX

MaterialFX es una biblioteca moderna de componentes para JavaFX basada en **Material Design**, un sistema de diseño creado por Google que define reglas visuales para interfaces modernas mediante el uso consistente de colores, sombras y animaciones.

* GitHub: https://github.com/palexdev/MaterialFX
* Wiki: https://github.com/palexdev/MaterialFX/wiki
* Video guía: https://www.youtube.com/watch?v=IPOAwcmbAIk


## Anexos – Recursos de diseño

Para mejorar la interfaz de usuario se utilizan herramientas externas que facilitan el diseño visual y la experiencia de usuario:

- Colores: https://coolors.co  
- Iconos: https://boxicons.com  
- Imágenes: https://unsplash.com/es  

---

## Uso de SVG en JavaFX

JavaFX permite el uso de iconos vectoriales mediante la clase `SVGPath`, lo que permite crear gráficos escalables directamente en la interfaz.

---

### Ejemplo

```java
SVGPath playIcon = new SVGPath();
playIcon.setContent("M10 20 L30 40 L10 60 Z");
playIcon.setStyle("-fx-fill: #000000;");
btnJugar.setGraphic(playIcon);

```
