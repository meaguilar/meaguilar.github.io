# Programando con Java FX

En este laboratorio aprenderás a crear una aplicación básica con **JavaFX** aplicando principios de **Programación Orientada a Objetos (POO)**, usando **Gradle** como sistema de compilación.

## ¿Qué es JavaFX?

JavaFX es la librería de Java para crear ventanas, botones, textos y todo tipo de elementos gráficos. A diferencia de Swing, JavaFX usa un “grafo de escena” donde cada **componente** que puede ser un botón, un texto, un panel es un nodo que se agrega a un árbol. Esto facilita pensar tu interfaz como capas de objetos: primero la ventana, luego un contenedor, luego los controles dentro. En el fondo, con JavaFX solo estás describiendo en código cómo dibujar ese árbol de nodos.

## Creación del proyecto
1.  En la pantalla de bienvenida de IntelliJ, elige **New Project**.
   
2. Selecciona **JavaFX** y marca la casilla **Gradle**.
 
 3. Luego seleccionamos **Next**
**![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXdRUiQ7yExGsk6EFaSfZNmUDiefmQ_hZaeNeNGohGeqKbCnxghZ1kZk7VACjsXu-GufQzzZsgIoxTZFVMGBgOTs1w_E-jZRwjDwnTbKr5JGMN7kqKoc4O6BnphKuKwS4_SNpmRV?key=wvcAPdd-0TgW15_xZ62NjQ)** 
Esto lo que hará es crearnos nuestro proyecto usando Gradle y Groovy DSL

4. Cuando pasemos a la siguiente ventana par agregar librerías, no agregaremos ninguna en este caso.

6. Una vez configurado el proyecto, hay que ejecutar el gradle, para esto nos iremos al siguiente apartado en la parte lateral derecha para ejecutar una tarea de Gradle
**![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXcICoH96chkeW8-LO558tWRPC93DCnjg1ITXe7GZRarABb2-hJmoW6VaV8R-B_upLUYRyybIyXOkQhWdbap-yEl6LiNNylVtPyq_tpToY83KTf7Jpww2T0mWJjt_5Su8GoUzYGXxQ?key=wvcAPdd-0TgW15_xZ62NjQ)**
7. Y ejecutaremos el comando `gradlew run`
	**![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXe8sw_hFC38rva7cyO7DJIN4AmGbWogRz06K9N2aeDgVCR2l4irjVTC7PBw7tvBZhkVcp21sz3ysRdp2GKxz4-xL5QqHaBJGfmKDqtCuMCbMPpKQEORKMmaec7lap5HKRT7cUSAcg?key=wvcAPdd-0TgW15_xZ62NjQ)**

Tras compilar y arrancar la aplicación, ya no necesitarás este comando; bastará con el botón **Run** al lado de la clase principal `HelloApplication` 

### ¿Qué es Gradle?
**Gradle** es la herramienta encargada de todo lo que ocurre antes de que tu aplicación se ejecute: descarga las librerías que necesitas como JavaFX, compila tu código Java y finalmente empaqueta el resultado en un JAR o en lo que prefieras. En lugar de hacer esos pasos uno por uno en la consola, Gradle los orquesta automáticamente según le indiques.

Una vez guardas `build.gradle`, IntelliJ detecta automáticamente el cambio y, con un clic en “Refresh”, descarga todo y deja tu proyecto listo para compilar y ejecutar.

## Teoria

### Archivos FXML

FXML es un lenguaje basado en XML que permite describir de forma declarativa la interfaz de usuario de una aplicación JavaFX. En lugar de instanciar y configurar cada nodo (botones, paneles, imágenes…) directamente en el código Java, escribimos su estructura y propiedades en un archivo con extensión `.fxml`, que normalmente se guarda dentro de la carpeta `resources` junto a otros recursos de la aplicación.

Al inicio de tu aplicación, cargas esta definición con una línea como
```Java
FXMLLoader fxmlLoader = new FXMLLoader(HelloApplication.class.getResource("hello-view.fxml"));  
Scene scene = new Scene(fxmlLoader.load(), 1280, 720);
```
De este modo JavaFX construye el árbol de nodos que tú describiste en el XML y lo adapta al tamaño en píxeles que hayas especificado para la ventana.

### Controladores

El controlador es la clase Java que aporta la lógica y el comportamiento a los componentes declarados en el FXML. En el propio archivo `.fxml` se vincula dicha clase mediante el atributo `fx:controller="com.ejemplo.demo5.HelloController"`, y dentro del controlador se usan anotaciones `@FXML` para inyectar las referencias a los nodos del XML.

Por ejemplo, si en el FXML defines `<Label fx:id="welcomeText" />`, en el controlador escribirás `@FXML private Label welcomeText;` para que JavaFX te proporcione esa instancia al cargar la vista
```XML
<VBox alignment="CENTER" prefHeight="207.0" prefWidth="300.0" spacing="20.0" xmlns:fx="http://javafx.com/fxml/1" xmlns="http://javafx.com/javafx/17.0.12" fx:controller="com.ejemplo.demo5.HelloController">  
 <padding> <Insets bottom="20.0" left="20.0" right="20.0" top="20.0" />  
 </padding>  
 <Label fx:id="welcomeText" />  
 <Button onAction="#onHelloButtonClick" text="Hello!" />  
</VBox>
```

Para lograr que una acción en la interfaz dispare un comportamiento concreto, se establece en el archivo FXML un identificador de evento que hace referencia al método controlador. Al pulsar el botón, JavaFX busca ese nombre y ejecuta el método correspondiente en la clase controladora. De este modo, la lógica de actualización—por ejemplo, cambiar el texto de una etiqueta—queda encapsulada en ese método, que se invoca de forma automática cada vez que el usuario interactúa con el botón.

```Java
@FXML  
private Label welcomeText;  
  
@FXML  
protected void onHelloButtonClick() {  
    welcomeText.setText("Welcome to JavaFX Application!");  
}
```

## Proyecto a realizar
El proyecto que realizaremos en esta guía será sobre una aplicación del espacio, para eso usaremos el siguiente diagrama UML

**![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXeU7sglEZunLLTSrE8A8CdjecpqJuYPLKh2UX_Upxp9oCRgtt5bAlCkrNnuTI39cnWbRsIyimVnDZ5KlVaZczM9hnxwdcvP_LzWlIp8W7mzDr-qpjOWfMWfuzyFe4T3NxUc4m0viw?key=wvcAPdd-0TgW15_xZ62NjQ)**
Que nos generará la siguiente aplicación

**![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXfWP7GtFNmIoAAfXzV_4yVxwDk0oHqKjjvUZ2B7lwND96aRp2KKpKynoQ3lXY85Hp7uhNqX8LTnQ8O3Lms8Ntj9v1aPcuSgWIoWZsMCL_SFQ0jlYcQcaDUGK7kSxwaegKVZLDH5nA?key=wvcAPdd-0TgW15_xZ62NjQ)**

### Paso 1. Crear el paquete con los modelos
Configura la capa de datos definiendo en un único paquete los modelos del diagrama UML; la interfaz y las clases que representan entidades espaciales. Todos los archivos deben ir dentro del mismo paquete

**SpaceEntity.java**
```Java
	public interface SpaceEntity {
    String getName();
    double getMass();
    String getImageUrl();
}
```

**CelestialBody.java**
```Java
	public abstract class CelestialBody implements SpaceEntity {
    private final String name;
    private final double mass;
    private final String image;

    public CelestialBody(String name, double mass, String image) {
        this.name = name;
        this.mass = mass;
        this.image = image;
    }

    @Override
    public String getName() {
        return name;
    }

    @Override
    public double getMass() {
        return mass;
    }

    @Override
    public String getImageUrl() {
        return image;
    }
    
    protected abstract double getEscapeVelocity();
}
```
**Planet.java**
```Java
public class Planet extends CelestialBody {
    private final int numberOfMoons;

    public Planet(String name, double mass, int numberOfMoons, String image) {
        super(name, mass, image);
        this.numberOfMoons = numberOfMoons;
    }

    public int getNumberOfMoons() {
        return numberOfMoons;
    }

    @Override
    protected double getEscapeVelocity() {
        final double G = 6.67430e-11;
        double radius = 6.371e6;
        return Math.sqrt(2 * G * getMass() / radius);
    }
}
```
**Moon.java**
```Java
public class Moon extends CelestialBody {
    private final String parentPlanet;

    public Moon(String name, double mass, String parentPlanet, String image) {
        super(name, mass, image);
        this.parentPlanet = parentPlanet;
    }

    public String getParentPlanet() {
        return parentPlanet;
    }

    @Override
    protected double getEscapeVelocity() {
        final double G = 6.67430e-11;
        double radius = 1.737e6; // radio medio de la Luna en metros
        return Math.sqrt(2 * G * getMass() / radius);
    }
}
```

### Crear la vista principal
Empezaremos a crear la vista principal de nuestra aplicación, para eso necesitaremos dos componente esenciales
**![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXdMNGS0fkG0M_qQZBiBIgF4wYBXhv36QVqB-kSmDcleC8iHGRaDW1iIKa5vz2hIssc_t6GJuSZdQw7FT8_c4sNzSfM5k7DMsCcSMqSirVYSb7Bf8PqvCCOLeetlDNCoW4Tq7lQ-CA?key=wvcAPdd-0TgW15_xZ62NjQ)**
Un componente donde pueda almacenar el titulo y el botón de agregar y un componente donde pueda almacenar todos los planetas y lunas. Para eso crearemos un archivo llamado `space-view.fxml` dentro de la carpeta `resources`
```Java
<?xml version="1.0" encoding="UTF-8"?>  
<?import javafx.geometry.Insets?>  
<?import javafx.scene.control.Button?>  
<?import javafx.scene.control.Label?>  
<?import javafx.scene.control.ScrollPane?>  
<?import javafx.scene.layout.TilePane?>  
<?import javafx.scene.layout.VBox?>  
  
<?import javafx.scene.layout.HBox?>  
<?import javafx.scene.layout.Region?>  
<VBox xmlns="http://javafx.com/javafx/17"  
  xmlns:fx="http://javafx.com/fxml/1"  
  fx:controller="com.ejemplo.demo5.HelloController"  
  spacing="15">  
  
 <padding> <Insets top="20" right="20" bottom="20" left="20"/>  
 </padding>  
 <HBox alignment="CENTER_LEFT" spacing="15">  
 <Label text="SpaceApp" style="-fx-font-size:25px; -fx-font-weight:bold;"/>  
 <Region fx:id="spacer" HBox.hgrow="ALWAYS"/>  
 <Button text="Agregar Nuevo Planeta" onAction="#openAddPlanetForm"/>  
 </HBox>  
 <ScrollPane fitToWidth="true" fitToHeight="true"  
  hbarPolicy="AS_NEEDED" vbarPolicy="AS_NEEDED" style="-fx-background-color: transparent; -fx-border-color: transparent;">  
	 <content> <TilePane fx:id="tilePane"  
	  hgap="15" vgap="15"  
	  prefColumns="3"  
	  alignment="CENTER"  
	  >  
		 </TilePane> 
	 </content> 
</ScrollPane>
 </VBox>
```
> Nota: Este código dará algunos errores hasta que terminemos la implementación

En el codigo es importante resaltar que:

-   **VBox**: contenedor vertical que apila sus nodos con un espacio fijo (`spacing="15"`) y un espaciado interno definido en `<padding>`.
    
-   **HBox**: en la parte superior, coloca el **Label** y el **Button** en línea. El `spacing="15"` deja 15 px entre elementos, y la **Region** con `HBox.hgrow="ALWAYS"` se expande para empujar el botón hacia la derecha, logrando que el texto y el boton queden separados, uno en cada esquina.
    
-   **ScrollPane**: hace que el contenido sea desplazable si supera el tamaño de la ventana.
    
    -   `fitToWidth="true"` y `fitToHeight="true"` ajustan el contenido para llenar siempre el ancho y alto disponibles.
        
    -   `hbarPolicy` y `vbarPolicy` controlan cuándo aparecen las barras de desplazamiento (`AS_NEEDED`).
        
    -   El estilo transparente elimina bordes o fondos no deseados.
        
-   **content** (dentro de ScrollPane): etiqueta obligatoria para envolver el nodo que realmente será scrollable, en este caso el **TilePane**.
    
-   **TilePane**: organiza dinámicamente sus hijos en una cuadrícula de hasta `prefColumns` columnas, con separaciones `hgap` y `vgap`. El atributo `alignment="CENTER"` centra la cuadrícula dentro del ScrollPane cuando hay espacio sobrante.

### Establecer pantalla principal 
Cuando creamos el proyecto, nos creo dos clases dentro de Main, el `HelloController` y el `HelloApplication`. En el `HelloApplication`modificaremos el codigo para que arranque con la vista que acabamos de crear
```Java
  
public class HelloApplication extends Application {  
    @Override  
  public void start(Stage stage) throws IOException {  
        FXMLLoader fxmlLoader = new FXMLLoader(HelloApplication.class.getResource("space-view.fxml"));  
        Scene scene = new Scene(fxmlLoader.load(), 1280, 720);  
        stage.setTitle("Planet's Demo");  
        stage.setScene(scene);  
        stage.show();  
    }  
  
    public static void main(String[] args) {  
        launch();  
    }  
}
```
Con `getResource` le decimos que archivo FXML va a abrir y al crear la escena también que tamaño tendrá en pixeles, así como el titulo de la ventana.
### Cartas de los cuerpos celestes
Ahora antes de continuar, crearemos las cards de cada planeta, es decir las que van dentro del ScrollPane y donde se muestra la información de cada cuerpo celeste.

Para eso crearemos en Resource una vista llamada  `space-cell.fxml` en Resources
```XML
<?xml version="1.0" encoding="UTF-8"?>
<?import javafx.geometry.*?>
<?import javafx.scene.control.*?>
<?import javafx.scene.effect.*?>
<?import javafx.scene.image.*?>
<?import javafx.scene.layout.*?>
<?import javafx.scene.text.*?>

<VBox xmlns="http://javafx.com/javafx/17.0.12"
      xmlns:fx="http://javafx.com/fxml/1"
      fx:controller="com.ejemplo.demo5.SpaceController"
      alignment="CENTER"
      prefWidth="268.0" prefHeight="240"
      spacing="10">
    
    <background>
        <Background>
            <fills>
                <BackgroundFill fill="white">
                    <radii>
                        <CornerRadii topLeft="10" topRight="10"
                                     bottomRight="10" bottomLeft="10"/>
                    </radii>
                    <insets>
                        <Insets top="10" right="10"
                                bottom="10" left="10"/>
                    </insets>
                </BackgroundFill>
            </fills>
        </Background>
    </background>
    
    <effect>
        <DropShadow color="#444444"
                    offsetX="0" offsetY="2"
                    radius="5"/>
    </effect>
    
    <ImageView fx:id="imgEntity"
               fitWidth="100" fitHeight="100"
               preserveRatio="true"/>

    <Label fx:id="lblName" textAlignment="CENTER">
        <font>
            <Font name="System Bold" size="14"/>
        </font>
    </Label>
    
    <Label fx:id="lblMass" textAlignment="CENTER">
        <font>
            <Font size="12"/>
        </font>
    </Label>
</VBox>

```
Es importante resaltar algunas etiquetas relevantes como:
- **`<background>` / `BackgroundFill`**: Rellena el fondo de la tarjeta con color blanco.
	    
	-   `CornerRadii`: bordes redondeados de 10 px en cada esquina.
	    
	-   `Insets`: margen interno para separar contenido del borde.
	
- **`<effect>` / `DropShadow`**: Aplica una sombra sutil debajo de la card para darle profundidad.
	    
	-   `offsetY="2"` desplaza la sombra 2 px hacia abajo.
	
- **`ImageView`**

-   `fitWidth` y `fitHeight`: ajusta la imagen a 100×100 px.
    
-   `preserveRatio="true"`: mantiene la proporción original de la imagen.

### Controlador de la carta.
Una vez teniendo el diseño de la carta, haremos su controlador, el cual se encargará como tal de una función que nos montara los datos, es decir, que recibiremos una entidad de tipo espacio (SpaceEntity) y una url de una imagen. Una vez nuestro controlador reciba eso, lo que haremos será montarla en los labels que definimos en la interfaz. Para eso crearemos un controlador llamado `SpaceController`
```Java
import javafx.fxml.FXML;  
import javafx.scene.control.Label;  
import javafx.scene.image.Image;  
import javafx.scene.image.ImageView;  
  
import java.io.InputStream;  
  
public class SpaceController {  
    @FXML  
  private ImageView imgEntity;  
    @FXML private Label lblName;  
    @FXML private Label lblMass;  
  
    public void setData(SpaceEntity entity, String imagePathOrUrl) {  
        lblName.setText(entity.getName());  
        lblMass.setText(String.format("Masa: %.2e kg", entity.getMass()));  
  
        Image image = null;  
        try {  
            if (imagePathOrUrl.startsWith("http")) {  
                image = new Image(imagePathOrUrl,  
                        100,  
                        100,  
                        true,  
                        true,  
                        false  
  );  
            } else {  
                InputStream is = getClass().getResourceAsStream(imagePathOrUrl);  
                if (is != null) {  
                    image = new Image(is);  
                }  
            }  
  
            // Comprueba si hubo error interno  
  if (image != null && image.isError()) {  
                System.err.println("Error cargando imagen");  
            }  
        } catch (Exception ex) {  
            ex.printStackTrace();  
        }  
  
        if (image != null) {  
            imgEntity.setImage(image);  
        }  
    }  
  
}
```
Acá en este código lo más relevante es el montado de la imagen, ya que recibimos una url, no sabemos si es de internet o si es una url de un archivo local, por lo que, instanciamos del objeto `Image` de JavaFX y hacemos una comprobación de si la imagen comienza con http, es decir que viene de internet y solo rellenamos con la url y le definimos el tamaño 
```Java
image = new Image(imagePathOrUrl,  
        100,  
        100,  
        true,  
        true,  
        false  
);
```
De no ser así se hace otro proceso extrayendo el recurso como un `Stream` 

### Controlador de la pantalla principal
Ahora, ya que tenemos las cartas y tenemos la pantalla principal, solo nos falta unirlo, eso lo haremos mediante el controlador de la pantalla principal, que en nuestro caso será el controlador que nos deja definido IntelliJ cuando creamos un nuevo proyecto, es decir en el archivo `HelloController` dentro de ese archivo definiremos 

```Java
import javafx.collections.FXCollections;  
import javafx.collections.ObservableList;  
import javafx.fxml.FXML;  
import javafx.fxml.FXMLLoader;  
import javafx.scene.Node;  
import javafx.scene.Scene;  
import javafx.scene.layout.TilePane;  
import javafx.stage.Stage;  
  
import java.io.IOException;  
  
public class HelloController {  
    @FXML private TilePane tilePane;  
  
    private ObservableList<SpaceEntity> entities;  
  
    @FXML  
  public void initialize() throws Exception {  
        entities = FXCollections.observableArrayList(  
                new Planet("Tierra",  5.97e24,  1, "https://cdn.pixabay.com/photo/2016/06/14/20/38/planet-earth-1457453_1280.png"),  
                new Planet("Marte",   6.39e23,  2, "https://static.vecteezy.com/system/resources/previews/056/369/903/non_2x/the-planet-mars-is-shown-in-this-image-png.png"),  
                new Planet("Júpiter", 1.898e27, 79, "https://d2pn8kiwq2w21t.cloudfront.net/images/Jupiter-800h-v2_02.width-1024.png"),  
                new Moon(  "Luna",    7.35e22, "Tierra",  
                        "https://static.vecteezy.com/system/resources/thumbnails/017/785/725/small/full-moon-isolated-on-transparent-background-png.png"),  
                new Moon(  "Fobos",   1.0659e16,"Marte",  
                        "https://static.wikia.nocookie.net/hola--srgedfg/images/5/50/441-4410958_mars-and-survey-the-red-planets-two-moons.png/revision/latest/scale-to-width-down/340?cb=20200331152719&path-prefix=es")  
        );  
  
        for (SpaceEntity entidad : entities) {  
            FXMLLoader loader = new FXMLLoader(getClass().getResource("space-cell.fxml"));  
            Node cell = loader.load();  
            SpaceController ctrl = loader.getController();  
  
            String imageUrl = entidad.getImageUrl() != null  
  ? entidad.getImageUrl()  
                    : "/images/default.png";  
            ctrl.setData(entidad, imageUrl);  
  
            tilePane.getChildren().add(cell);  
        }  
    }  
  
    public ObservableList<SpaceEntity> getEntities() {  
        return entities;  
    }  
}
```
**Funcion initialize**
Dentro de este código la función initialize que se encarga o se carga cuando se muestra la pantalla, lo que hace es que no crea una `ObservableList`  que extiende a `List`, pero con la capacidad de **notificar automáticamente** los cambios como inserciones, borrados,  o movimientos a quien se haya registrado como oyente. Dentro del Initialize le agregaremos un arreglo el cual contendrá datos _hardcodeados_ o "quemados" para lograr visualizar como se ve.

Luego para cada espacio del arreglo, vamos a cargar un nuevo `space-cell` que es la card que hemos creado, y para cada uno vamos a cargarle el controlador, ya que, como habíamos hecho antes, a la función `setData` le pasaremos el objeto y la imagen 
```Java
ctrl.setData(entidad, imageUrl);
```
Y una vez cargada la card al panel que tenemos, le asignaremos ese nueva card.

**Funcion addEntity**
Esta función funciona igual, con la única excepción que esta función ya no le asignaremos datos quemados, si no que recibiremos la entidad nueva y la asignaremos una sola vez, pero en esencia el montado es igual, solo que **no es iterativo**

**Funcion getEntities**
Esta funcion lo que hará es retornanos las entidades que estén dentro del panel, esto nos sirvira más adelante para saber cuales entidades estan agregadas ya.

### Vista para agregar nuevos planetas
Por ultimo agregaremos una funcionalidad más, el cual será para agregar otro planeta u otra luna y para eso, crearemos una nueva vista que se llame `form-add-planet.fxml`
```XML
<?xml version="1.0" encoding="UTF-8"?>  
<?import javafx.scene.control.*?>  
<?import javafx.scene.layout.*?>  
<?import javafx.geometry.Insets?>  
  
<VBox xmlns="http://javafx.com/javafx/17"  
  xmlns:fx="http://javafx.com/fxml/1"  
  fx:controller="com.ejemplo.demo5.AddPlanetController"  
  spacing="10">  
 <padding> <Insets top="15" right="15" bottom="15" left="15"/>  
 </padding>  
 <Label text="Agregar Nueva Entidad" style="-fx-font-size:16px;-fx-font-weight:bold;"/>  
  
 <ComboBox fx:id="typeComboBox" promptText="Tipo de entidad"/>  
  
 <TextField fx:id="nameField" promptText="Nombre"/>  
 <TextField fx:id="massField" promptText="Masa (kg)"/>  
 <TextField fx:id="imageField" promptText="URL de la Imagen"/>  
  
 <TextField fx:id="moonCountField" promptText="Cantidad de Lunas" visible="false"/>  
  
 <ComboBox fx:id="parentPlanetCombo" promptText="Planeta padre" visible="false"/>  
  
 <Button text="Agregar" onAction="#addEntity"/>  
</VBox>
```
Para esta vista lo unico que hay que resaltar son los campos de texto, el primero es ComboBox el cual es para definir un campo donde puedo seleccionar opciones. Y por ultimo un TextField que es un campo donde puedo ingresar texto.

### Modificación del controlador principal
Antes de continuar con el controlador del formulario, modificaremos el controlador principal `HelloController` el cual le agregaremos una función y es que, cuando en la pantalla principal demos click en el boton de agregar nuevo planeta, debe abrirnos la vista que acabamos de crear, por lo tanto lo haremos con la siguiente función
```Java
@FXML  
private void openAddPlanetForm() throws IOException {  
    FXMLLoader loader = new FXMLLoader(getClass().getResource("form-add-planet.fxml"));  
    Stage stage = new Stage();  
    stage.setScene(new Scene(loader.load()));  
  
    AddPlanetController addCtrl = loader.getController();  
    addCtrl.setMainController(this);  
  
    stage.setTitle("Agregar Nueva Entidad");  
    stage.show();  
}
```
Esto lo agregamos despues del getEntity y lo que hará es que de manera similar cargará la escena obteniendo la vista como un recurso, es importante que si le pusimos otro nombre a la vista de formulario, ponerselo ya que se deja hardcodeado el nombre del archivo a cargar.

### Controlador de agregar un nuevo planeta
Por ultimo, agregaremos un controlador para la vista de agregar un nuevo planeta, lo llamaremos `AddPlanetController` y definiremos lo siguiente:
```Java
import javafx.collections.FXCollections;  
import javafx.fxml.FXML;  
import javafx.scene.control.ComboBox;  
import javafx.scene.control.TextField;  
  
import java.util.List;  
import java.util.stream.Collectors;  
  
public class AddPlanetController {  
    @FXML private ComboBox<String> typeComboBox;  
    @FXML private TextField nameField;  
    @FXML private TextField massField;  
    @FXML private TextField imageField;  
    @FXML private TextField moonCountField;  
    @FXML private ComboBox<String> parentPlanetCombo;  
  
    private HelloController mainController;  
  
    public void setMainController(HelloController controller) {  
        this.mainController = controller;  
    }  
  
    @FXML  
  private void initialize() {  
        typeComboBox.getItems().addAll("Planeta", "Luna");  
  
        typeComboBox.valueProperty().addListener((obs, old, nuevo) -> {  
            boolean isPlanet = "Planeta".equals(nuevo);  
  
            moonCountField.setVisible(isPlanet);  
            parentPlanetCombo.setVisible(!isPlanet);  
  
            if (!isPlanet) {  
                List<String> planetNames = mainController.getEntities().stream()  
                        .filter(e -> e instanceof Planet)  
                        .map(SpaceEntity::getName)  
                        .collect(Collectors.toList());  
                parentPlanetCombo.setItems(FXCollections.observableArrayList(planetNames));  
            }  
        });  
    }  
  
    @FXML  
  private void addEntity() {  
        String tipo = typeComboBox.getValue();  
        String nombre = nameField.getText().trim();  
        double masa = Double.parseDouble(massField.getText().trim());  
        String imagen = imageField.getText().trim();  
  
        SpaceEntity nuevaEntidad;  
        if ("Planeta".equals(tipo)) {  
            int numLunas = Integer.parseInt(moonCountField.getText().trim());  
            nuevaEntidad = new Planet(nombre, masa, numLunas, imagen);  
        } else {  
            String planetaPadre = parentPlanetCombo.getValue();  
            nuevaEntidad = new Moon(nombre, masa, planetaPadre, imagen);  
        }  
  
        mainController.addEntity(nuevaEntidad);  
  
        clearFields();  
        nameField.getScene().getWindow().hide();  
    }  
  
    private void clearFields() {  
        nameField.clear();  
        massField.clear();  
        imageField.clear();  
        moonCountField.clear();  
        parentPlanetCombo.getSelectionModel().clearSelection();  
        typeComboBox.getSelectionModel().clearSelection();  
    }  
}
```
**Funcion Initialize**
Ahora, es importante definir que hace cada función, la función Initialize o que hace es que al empezar crea las opciones que tendrá el ComboBox que son para crear un planeta o una luna. Luego, cada que cambiemos de opción, esto cargara un Listener o una escucha y esto ya que, cuando cambie, queremos que algunos campos se muestren, por ejemplo, si es un planeta, debe mostrarse la cantidad de lunas y si no es una luna, debe mostrarse el planeta padre. En el segundo caso, de que no sea un planeta, lo que haremos es que vamos a llenar el ComboBox del planeta padre, con todos los planetas que ya hemos agregado mediante este fragmento de código
```Java
List<String> planetNames = mainController.getEntities().stream()  
        .filter(e -> e instanceof Planet)  
        .map(SpaceEntity::getName)  
        .collect(Collectors.toList());
```
**Funcion addEntity**
Esta funcion solamente agregara un nuevo planeta o nueva luna, para eso hara uso del controlador principal que instanciamos al principio del codigo
```Java
private HelloController mainController;  
  
public void setMainController(HelloController controller) {  
    this.mainController = controller;  
}
```
Una vez instanciado, podemos acceder a sus métodos, y haremos uso del addEntity de ese controlador pasándole una entidad de tipo `SpaceEntity` que puede ser un Planeta o una Luna, dependiendo del tipo que este seleccionado en ComboBox
```Java
SpaceEntity nuevaEntidad;  
if ("Planeta".equals(tipo)) {  
    int numLunas = Integer.parseInt(moonCountField.getText().trim());  
    nuevaEntidad = new Planet(nombre, masa, numLunas, imagen);  
} else {  
    String planetaPadre = parentPlanetCombo.getValue();  
    nuevaEntidad = new Moon(nombre, masa, planetaPadre, imagen);  
}  
  
mainController.addEntity(nuevaEntidad);
```
Por ultimo, solo se llama a la funcion clearFields para limpiar todos los campos e igual cerrar la ventana 
```Java
clearFields();  
nameField.getScene().getWindow().hide();
```
## Consideraciones finales

Ten en cuenta que el código se ha ido desarrollando de forma incremental, incorporando funciones a medida que surgían las necesidades. Sin embargo, con fines académicos seguiremos fielmente los pasos de la guía. Durante el proceso es normal que aparezcan errores; al completar todos los ejercicios, deberías recuperar la interfaz original.

Para facilitar el seguimiento y la centralización, todo el proyecto está disponible en GitHub:  
[https://github.com/JosseJuventino/SpaceApp](https://github.com/JosseJuventino/SpaceApp)
