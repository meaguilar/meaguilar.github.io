# Configuración del entorno de desarrollo para Java

1. Instalar IntelliJ IDEA (Entorno de Desarrollo Integrado).  
2. Configurar el JDK (Java Development Kit)

---

## Requisitos para instalar IntelliJ IDEA
| Requisito            | Mínimo                | Recomendado                                  |
|----------------------|----------------------|----------------------------------------------|
| **RAM**              | 2 GB de RAM          | 8 GB de RAM total del sistema                |
| **Espacio en disco** | 3,5 GB libres        | Unidad SSD con al menos 5 GB de espacio libre |

---

## ![](imagenes/intellij_logo.png) Descarga e Instalación de IntelliJ IDEA

### Paso 1: Descargar el instalador
Accede al sitio oficial de [JetBrains](https://www.jetbrains.com/es-es/idea/download/?section=windows). Una vez descargado, instala el programa según tu sistema operativo.

![Descarga IntelliJ](../imagenes/guia-preparacion/1.png)

---

### Paso 2: Instalar IntelliJ IDEA

#### Windows
Ejecuta el archivo `.exe` y deja todas las opciones por defecto.

#### MacOS
Abre el archivo `.dmg` que descargaste y arrastra IntelliJ IDEA a la carpeta _Applications_.

#### Linux
Extrae el archivo `.tar.gz` en una carpeta de tu preferencia, abre una terminal, navega a dicha carpeta y ejecuta `./idea.sh`.

![Instalación IntelliJ](images/instalacion_intellij.png)

---

### Paso 3: Abrir IntelliJ y crear un nuevo proyecto

1. Abre IntelliJ IDEA desde el acceso directo o menú de aplicaciones.  
2. Si el IDE pregunta si deseas importar configuraciones previas, selecciona _Do not import settings_.  
3. Haz clic en _New Project_ en la pantalla de bienvenida.

![Nuevo Proyecto IntelliJ](images/nuevo_proyecto.png)

---

### Paso 4: Configurar el JDK
El **JDK** (Java Development Kit) es un conjunto de herramientas esenciales para desarrollar y ejecutar aplicaciones Java. Incluye el compilador, la Máquina Virtual de Java (**JVM**) y bibliotecas necesarias. Para este curso, utilizaremos **JDK 17**, estable y moderna.  

Para configurar el JDK en IntelliJ IDEA:
1. Crea un nuevo proyecto, asigna nombre y ubicación.  
2. En el panel izquierdo, selecciona _Java_.  
3. En _Project SDK_, verifica si hay algún JDK instalado.

![Configurar JDK](images/configurar_jdk.png)

Si no está instalado, IntelliJ IDEA puede descargarlo automáticamente. Alternativamente, descarga manualmente desde [Java Archive JDK](https://www.oracle.com/java/technologies/downloads/archive/) (**Java SE 17.0.12**).

![Configurar JDK](images/configurar_jdk.png)

Una vez instalado, regresa a IntelliJ y selecciona **Add SDK from disk**, buscando la carpeta de instalación del JDK (`C:/Program Files/Java/` por defecto).

---

### Paso 5: Finalizar creación de proyecto
Haz clic en _Finish_ para crear el proyecto. Se generará un pequeño programa de prueba. Ejecuta el botón _Run_ para comprobar que todo funciona.

![Ejecutar Programa](images/ejecutar_programa.png)

La consola debería mostrar:
```shell
Hello and welcome!
i = 1
i = 2
i = 3
i = 4
i = 5
