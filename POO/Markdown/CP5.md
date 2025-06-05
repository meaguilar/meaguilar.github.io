# Conectando JavaFX a la Base de Datos

**Nota:** En este laboratorio partiremos de la aplicación desarrollada en el ejercicio anterior, _“Programando con JavaFX”_ (código fuente disponible en GitHub: [https://github.com/JosseJuventino/SpaceApp](https://github.com/JosseJuventino/SpaceApp)). A partir de ahí, incorporaremos la capa de persistencia necesaria para almacenar y recuperar nuestras entidades desde una base de datos SQL Server.

Para comunicarnos con la base de datos emplearemos el driver JDBC oficial de Microsoft. Al tratarse de un proyecto gestionado con Gradle, basta con añadir la dependencia adecuada en el archivo `build.gradle`.

Podemos ver todas las versiones disponibles y las instrucciones de integración en Maven Repository por ejemplo para Gradle o para Maven. Para entornos Java 17, busca la variante `mssql-jdbc` con JRE 17 en este enlace:  
[https://mvnrepository.com/artifact/com.microsoft.sqlserver/mssql-jdbc/12.3.0.jre17-preview](https://mvnrepository.com/artifact/com.microsoft.sqlserver/mssql-jdbc/12.3.0.jre17-preview)

Una vez identificada la  versión correcta, modificaremos el `build.gradle` así:
```Java
dependencies {  
	testImplementation("org.junit.jupiter:junit-jupiter-api:${junitVersion}")  
    testRuntimeOnly("org.junit.jupiter:junit-jupiter-engine:${junitVersion}")  
    implementation 'com.microsoft.sqlserver:mssql-jdbc:12.3.0.jre17-preview'  
}
```
Una vez agregado solo corremos en gradle el comando
```shell
gradlew run
```
## Creando base de datos
Primero comenzaremos creando nuestra base de datos en SQL Server, es decir, definiendo en base a nuestro modelo UML del laboratorio anterior las tablas que necesitaremos, para eso en SQL Server, nos conectaremos primero usando SQL Management Studio.

**![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXdH5Dno5N8C0SVunt78F_RZdr5kFF8gnpbnP79MWWEn5tviiNUQ7LZjAIBy3DRfbdx7UnWMMvW0rcbh4vrLJeIN-K6ixPZCw1m0-Sqh0kwnGDOIor2r_IDqehbG8RUo1YLd-di8lQ?key=jN8y74_RcgslP0y-cCJmzQ)**
Sera importante verificar con que usuario y con que contraseña iniciamos sesión y que nos funcione al iniciar sesion con _SQL Server Authentication_ no con el _Windows Authentication_, esto ya que posteriormente usaremos esas credenciales para conectarnos.
> De no funcionar la conexión por favor avisar a cualquiera de los instructores.

Luego, crearemos nuestra base de datos que la llamaremos en este caso PlanetasDB, esto usando el siguiente query

```SQL
CREATE DATABASE PlanetasDB;
GO
USE PlanetasDB;

CREATE TABLE Planets (
    id INT PRIMARY KEY IDENTITY(1,1),
    name NVARCHAR(100),
    mass FLOAT,
    moonCount INT,
    image NVARCHAR(255)
);

CREATE TABLE Moons (
    id INT PRIMARY KEY IDENTITY(1,1),
    name NVARCHAR(100),
    mass FLOAT,
    parentPlanet NVARCHAR(100),
    image NVARCHAR(255)
);
```
Esto nos creara una tabla para guardar los planetas y las lunas por separado.

## Conectandose desde JavaFX
Una vez tengamos nuestra conexión, desde nuestro proyecto de JavaFX crearemos una carpeta llamada `util` (al mismo nivel donde esta el archivo `HelloApplication` esto para mantener organizado nuestros archivos, y dentro de esa carpeta crearemos un archivo llamado `DBConnection` que contendra lo siguiente

```Java
package com.ejemplo.demo5.util;  
  
import java.sql.Connection;  
import java.sql.DriverManager;  
import java.sql.SQLException;  
  
public class DBConnection {  
    private static final String URL = "jdbc:sqlserver://localhost:1433;databaseName=PlanetasDB;encrypt=true;trustServerCertificate=true";  
    private static final String USER = "sa";  
    private static final String PASSWORD = "123456";  
  
    private DBConnection() {}  
  
    public static Connection getConnection() throws SQLException {  
        return DriverManager.getConnection(URL, USER, PASSWORD);  
    }  
}
```
En este código es importante recalcar que, estamos creando una instancia o una conexión con el Driver que instalamos al principio, para eso hay que definir 3 strings, uno con la URL de conexión o lo que se llama "Cadena de conexión" donde para futuras conexiones, solo hay que cambiar el nombre de la base de datos y el puerto de ser necesario (Ya por defecto deberia ser el 1433)
```Java
private  static  final String URL =  "jdbc:sqlserver://localhost:1433;databaseName=[Base de datos];encrypt=true;trustServerCertificate=true";
```
Y otros dos strings donde se definamos el usuario y la contraseña con el que nos conectaremos a la base de datos
```Java
private static final String USER = "sa";  
private static final String PASSWORD = "123456"; 
```
## Creando Data Access Object

Comencemos por entender qué es un **Data Access Object** (DAO). Básicamente, un DAO es una clase (o un conjunto de clases) cuya única responsabilidad es la interacción con la base de datos para una entidad específica. Al usar esta capa, encapsulamos las operaciones de acceso a datos y mantenemos el código más limpio y organizado.

Por ejemplo, podemos crear una carpeta llamada `DAO` al mismo nivel que las demás que ya tenemos en el proyecto. Dentro de esa carpeta, añadiremos un archivo llamado `MoonDAO.java`, que se encargará de todas las operaciones sobre la tabla `Moons`. El código podría ser así:

```Java  
import com.ejemplo.demo5.model.Moon;  
import com.ejemplo.demo5.util.DBConnection;  
  
import java.sql.Connection;  
import java.sql.PreparedStatement;  
import java.sql.SQLException;  
  
public class MoonDAO {  
    public void insertarMoon(Moon moon) throws SQLException {  
        String sql = "INSERT INTO Moons (name, mass, parentPlanet, image) VALUES (?, ?, ?, ?)";  
        try (Connection conn = DBConnection.getConnection();  
             PreparedStatement stmt = conn.prepareStatement(sql)) {  
  
            stmt.setString(1, moon.getName());  
            stmt.setDouble(2, moon.getMass());  
            stmt.setString(3, moon.getParentPlanet());  
            stmt.setString(4, moon.getImageUrl());  
  
            stmt.executeUpdate();  
        }  
    }  
}
```

Si revisamos este ejemplo, vemos que lo único que hacemos es definir la consulta SQL y, dentro de un bloque `try-with-resources`, preparamos la sentencia. Los signos `?` en la consulta indican los parámetros que vamos a sustituir, en el mismo orden en que los colocamos. En este caso todos son cadenas de texto o valores numéricos sencillos; si alguno fuera de otro tipo (por ejemplo, `Date` o `boolean`), usaríamos el método `set` correspondiente según la columna en la base de datos.

De este modo, cada vez que queramos insertar un nuevo objeto `Moon`, bastará con llamar a `insertarMoon(moon)`, y la lógica de conexión y preparación de la consulta quedará oculta dentro de la clase `MoonDAO`. Así mantenemos el resto del código libre de detalles de SQL y de manejo de conexiones.

Igualmente en la misma carpeta crearemos la clase `PlanetDao`

```Java
import com.ejemplo.demo5.model.Planet;  
import com.ejemplo.demo5.util.DBConnection;  
  
import java.sql.Connection;  
import java.sql.PreparedStatement;  
import java.sql.SQLException;  
  
  
public class PlanetDAO {  
    public void savePlanet(Planet planet) throws SQLException {  
        String sql = "INSERT INTO Planets (name, mass, moonCount, image) VALUES (?, ?, ?, ?)";  
  
        try (Connection conn = DBConnection.getConnection();  
             PreparedStatement stmt = conn.prepareStatement(sql)) {  
  
            stmt.setString(1, planet.getName());  
            stmt.setDouble(2, planet.getMass());  
            stmt.setInt(3, planet.getNumberOfMoons());  
            stmt.setString(4, planet.getImageUrl());  
  
            stmt.executeUpdate();  
        }  
    }  
}
```
## Insertar en la base de datos
Ahora que ya hemos definido el método para insertar un nuevo elemento en la base de datos, solo necesitamos **invocarlo desde el código**. Para ello, modificaremos la clase `AddPlanetController`, específicamente dentro del método `addEntity`. En el bloque `try`, luego de crear el objeto `Planet` o `Moon`, llamaremos al método que realiza la inserción.

```Java
if ("Planeta".equals(tipo)) {  
    int numLunas = Integer.parseInt(moonCountField.getText().trim());  
    Planet planeta = new Planet(nombre, masa, numLunas, imagen);  
    new PlanetDAO().savePlanet(planeta);  //Agrega a la base de datos 
    nuevaEntidad = planeta;  
} else {  
    String planetaPadre = parentPlanetCombo.getValue();  
    Moon luna = new Moon(nombre, masa, planetaPadre, imagen);  
    new MoonDAO().insertarMoon(luna);  //Agrega a la base de datos 
    nuevaEntidad = luna;  
}
```
Por ejemplo, en esta línea: 
```Java
new PlanetDAO().savePlanet(planeta);
```
estamos utilizando el método que implementamos previamente, instanciando la clase `PlanetDAO` y ejecutando su método `savePlanet()` para guardar el planeta en la base de datos.


## Obtener de la base de datos
Para que nuestra aplicación deje de utilizar datos _hardcodeados_ (o _quemados_), realizaremos un mapeo de los registros que ya han sido ingresados en la base de datos.  

Para lograrlo, utilizaremos nuestras clases `PlanetDAO` y `MoonDAO`, y en cada una de ellas agregaremos un nuevo método justo debajo del método `save`, el cual permitirá recuperar todos los registros existentes desde la base de datos.

```Java
public List<Planet> getAllPlanets() throws SQLException {  
    List<Planet> planets = new ArrayList<>();  
    String sql = "SELECT name, mass, moonCount, image FROM Planets";  
  
    try (Connection conn = DBConnection.getConnection();  
         Statement stmt = conn.createStatement();  
         ResultSet rs = stmt.executeQuery(sql)) {  
  
        while (rs.next()) {  
            planets.add(new Planet(  
                    rs.getString("name"),  
                    rs.getDouble("mass"),  
                    rs.getInt("moonCount"),  
                    rs.getString("image")  
            ));  
        }  
    }  
  
    return planets;  
}
```
```Java
public List<Moon> getAllMoons() throws SQLException {  
    List<Moon> moons = new ArrayList<>();  
    String sql = "SELECT name, mass, parentPlanet, image FROM Moons";  
  
    try (Connection conn = DBConnection.getConnection();  
         Statement stmt = conn.createStatement();  
         ResultSet rs = stmt.executeQuery(sql)) {  
  
        while (rs.next()) {  
            moons.add(new Moon(  
                    rs.getString("name"),  
                    rs.getDouble("mass"),  
                    rs.getString("parentPlanet"),  
                    rs.getString("image")  
            ));  
        }  
    }  
  
    return moons;  
}
```
En este caso, la diferencia principal con el método de inserción es que ahora estaremos recuperando los datos existentes. Para ello, consultaremos la base de datos y, si el `ResultSet` contiene resultados, agregaremos cada luna o planeta a una lista correspondiente.  
De esta manera, obtendremos una lista con todas las lunas y otra con todos los planetas almacenados en la base.

Finalmente, solo nos queda utilizar esas listas en la aplicación. Para hacerlo, simplemente debemos modificar el método `initialize` de la clase `HelloController`, reemplazando los datos quemados por los obtenidos desde la base de datos.

```Java
public void initialize() throws Exception {  
    PlanetDAO planetDAO = new PlanetDAO();  
    MoonDAO moonDAO = new MoonDAO();  
  
    entities = FXCollections.observableArrayList();  
    entities.addAll(planetDAO.getAllPlanets());  
    entities.addAll(moonDAO.getAllMoons());  
  
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
```

La única diferencia respecto a la implementación anterior es que, en lugar de definir manualmente los objetos `Planet` y `Moon` directamente en el código como:
```Java
entities = FXCollections.observableArrayList(  
        new Planet("Tierra",  5.97e24,  1, "https://cdn.pixabay.com/photo/2016/06/14/20/38/planet-earth-1457453_1280.png"),  
        new Planet("Marte",   6.39e23,  2, "https://static.vecteezy.com/system/resources/previews/056/369/903/non_2x/the-planet-mars-is-shown-in-this-image-png.png"),  
        new Planet("Júpiter", 1.898e27, 79, "https://d2pn8kiwq2w21t.cloudfront.net/images/Jupiter-800h-v2_02.width-1024.png"),  
        new Moon(  "Luna",    7.35e22, "Tierra",  
                "https://static.vecteezy.com/system/resources/thumbnails/017/785/725/small/full-moon-isolated-on-transparent-background-png.png"),  
        new Moon(  "Fobos",   1.0659e16,"Marte",  
                "https://static.wikia.nocookie.net/hola--srgedfg/images/5/50/441-4410958_mars-and-survey-the-red-planets-two-moons.png/revision/latest/scale-to-width-down/340?cb=20200331152719&path-prefix=es")  
);
```

Ahora creamos una lista observable vacía y le agregamos los datos obtenidos desde la base de datos mediante nuestros DAOs, ya que cada método devuelve una lista de entidades:

```Java
PlanetDAO planetDAO = new PlanetDAO();  
MoonDAO moonDAO = new MoonDAO();  
  
entities = FXCollections.observableArrayList();  
entities.addAll(planetDAO.getAllPlanets());  
entities.addAll(moonDAO.getAllMoons());
```
Con esto, nuestra aplicación deja de depender de datos quemados y se alimenta dinámicamente con la información almacenada en la base de datos.

En general, el flujo de trabajo con la base de datos sigue la misma estructura: consiste en modificar el DAO correspondiente y ajustar la lógica según el tipo de operación que necesitemos realizar, ya sea cargar, agregar, actualizar o leer los elementos utilizados en nuestra aplicación.

Con los cambios hechos, en nuestra aplicación al ver la tabla las veremos llenadas:
**![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXfxfofCdd5RZii1FNbUWKnaferjJOZs-R75hG2PMC5IflT4mQ6cNdYiWAvwrDxYjk5-vlAmTF-hvb82rdaTVXGb0NniIZVx1IcsKcuh1khzldiWaz3paAK4-h23apcxS5WLgMs1?key=jN8y74_RcgslP0y-cCJmzQ)**
**![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXc16AZXzPs635G5MNweuKjfsztSVPYTP1sYzPEHKk5F5Xl1woqCttpL9k9lPw7MvfchXr9hkoimoiMjSeMuzTcV57E6ZQQ48qfL22ZVA3RFv4wMfGJagvmS5XVzNQ92uzv5y4Oybg?key=jN8y74_RcgslP0y-cCJmzQ)**

Y la misma información en nuestra aplicación de las tablas, en la aplicación:

**![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXelMWGdy99VJl8z5BXYdqo2rXYYSrCchpNjCxO7YQWON8xZwn2TuAHlSOyqe9M1Q_pJjHBcNuXWSvRCSQOm91PPfvdm_32iqekSV_dzxm1QnTWOHnxpC6vSueIaRbta1ryZByinaA?key=jN8y74_RcgslP0y-cCJmzQ)**

# Referencias y recursos extra
[Hoja de trucos SQL](https://www.geeksforgeeks.org/sql-cheat-sheet/) - Hoja de trucos con las sentencias básicas de SQL.
