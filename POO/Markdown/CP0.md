
# Configuración del Entorno de Desarrollo Java

### **Objetivos**
    
1. Instalar IntelliJ IDEA (el entorno de desarrollo).  
2. Configurar el JDK (Java Development Kit) para poder programar en Java.

## Requisitos para instalar IntelliJ IDE
| Requisito            | Mínimo                | Recomendado                                  |
|----------------------|-----------------------|----------------------------------------------|
| **RAM**              | 2 GB de RAM     | 8 GB de RAM total del sistema                |
| **Espacio en disco** | 3,5 GB libres                | Unidad SSD con al menos 5 GB de espacio libre  |

## **Descarga e Instalación de IntelliJ IDEA**

### Paso 1: Descargar el instalador
Para descargar el instalador, accede al sitio oficial de [JetBrains](https://www.jetbrains.com/es-es/idea/download/?section=windows). Una vez descargado, instala el programa según tu sistema operativo.

**![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXc4LAMiDUqCZDHsVcRAmAZQ7De8M8Uz1G9qOxikiky3Se772D0rvZadpkQyZHbF6-rTBjf7_nNBzlWlQu6iFh17xDS5DeuN0d9ysmYb-rGlpHfPHqOcWbID7BfU42JCc8czvKKsUA?key=UmqXHDTx4TfuBEhIlfOzqhwb)**

### Paso 2: Instalar IntelliJ IDEA

#### Windows
Ejecuta el archivo `.exe` y deja todas las opciones por defecto.

#### MacOS
Abre el archivo `.dmg` que descargaste y arrastra IntelliJ IDEA a la carpeta _Applications_.

#### Linux
Extrae el archivo `.tar.gz` en una carpeta de tu preferencia, abre una terminal, navega a dicha carpeta y ejecuta `./idea.sh`.

### Paso 3: Abrir IntelliJ
1. Abre IntelliJ IDEA desde el acceso directo o el menú de aplicaciones.  
3. En la primera ejecución, si el IDE pregunta si deseas importar configuraciones previas selecciona _Do not import settings_.

A continuación, procederemos a crear un nuevo proyecto.

### Paso 4: Crear un nuevo proyecto

1. **Seleccionar "Nuevo Proyecto":**  
   En la pantalla de bienvenida, haz clic en _New Project_.
   
   **![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXewx2sSgfoQQ9OvUYZxYM-Sz57F9xpUCcB0_KrXbHn5pf4Sv5oQhTN0ZsSZPo2xQiyea0a2FEHlNQaAlh8ukWCwyZgyilf1FQCkhMNmXFi56Ktwpa1Fd4P8g2QPr-0KTG75b5iy2A?key=UmqXHDTx4TfuBEhIlfOzqhwb)**

2. **Configurar el proyecto y el JDK:**  
El **JDK** (Java Development Kit) es un conjunto de herramientas esenciales para desarrollar y ejecutar aplicaciones Java. Incluye el compilador, la Máquina Virtual de Java (**JVM**) y bibliotecas necesarias. Para este curso, utilizaremos **JDK 17**, una versión estable y moderna que ofrece mejoras en rendimiento, seguridad y nuevas características del lenguaje.

	Para configurar el JDK en IntelliJ IDEA, primero debes crear un nuevo proyecto. Asigna un nombre y una ubicación, luego, en el panel izquierdo, selecciona _Java_. En el panel derecho, en el campo _Project SDK_, verifica si hay algún JDK está instalado.
![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXcbn_c5G8SNYv5cdkgmvR2fe2w6-hRB7h1a9hF8VhG_7FNU2tpPmUl2RR-c7ecjc4N_Uq7-P7C4mYz4SMpiZ_Yj4UsVPIn-EUjT3BeAH2yIfnIfSa_uFC33YbKTtme37IQMRLXHDg?key=UmqXHDTx4TfuBEhIlfOzqhwb)
	
	Si no tienes el JDK instalado, IntelliJ IDEA ofrece la opción de descargarlo automáticamente. Selecciona esta opción y el IDE se encargará de la instalación sin necesidad de hacerlo manualmente. Sin embargo, aunque esta alternativa es conveniente, instalar el JDK de forma manual brinda un mayor control y flexibilidad en distintos entornos de desarrollo.

	Para instalarlo manualmente, accede a la página de descargas de [Java Archive JDK](https://www.oracle.com/java/technologies/downloads/archive/) y descarga el instalador correspondiente a tu sistema operativo. En nuestro caso, seleccionaremos la versión **Java SE 17.0.12** para Windows.
![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXcDRlUi4Z_EwNy2oQ7kKlk7QajUTx9QnRfoi5011s7MJPVKiAqi7ZwZEXkAgCjFI41mLpH5hp_K3FDq0v6bOEEI_JMuBLM9BCPFOnlD2mKuMhJzYhkD9iF_cUFUk5dQydWKw8Uv?key=UmqXHDTx4TfuBEhIlfOzqhwb)

	Una vez descargado, ejecuta el instalador y sigue las instrucciones en pantalla para completar la instalación.
	
	**![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXfKRqkUu09y6PyYrsXxxnzfO1UCdKQ5BkXpQpC-9ukhJx6aTRW8WZ7hKogQvp71J-MV0gCZjTKcp2S3ky7feSJf42T1PxImnzK4q0skpYYahdMG8hpZElIfquHm78FSmfQ9a95vgw?key=UmqXHDTx4TfuBEhIlfOzqhwb)**
	Después de instalarlo, regresa a IntelliJ IDEA y selecciona **Add SDK from disk**. Por defecto, el JDK se instala en la carpeta `C:/Program Files/Java/`. Busca la carpeta correspondiente, selecciónala y confirma la versión que utilizarás.

**![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXcRSbgLczqlWUDZlksf3PHVdbLc9m5viq3Njz2ve4eQjdIiaS727v325EBiRUKHdq-n031uZng5PomJibmkNuTkp4H8hzi-GKUMkCLqiNMnShJfIUl7CC9L874F1pornC-f_GQGmw?key=UmqXHDTx4TfuBEhIlfOzqhwb)**

4. **Finalizar la Creación:**  
   Haz clic en _Finish_ para crear el proyecto. Si es la primera vez que creas un proyecto y no tienes instalado ningún JDK, empezará la descarga del mismo.
   
   **![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXfa6-MKuQaVIjKbXcAYsiaKTHiGb1tw1k7RibRUNTgrATHn5DYJcmHKuN5N66MWEGu0xGKKlauLEqn3kEIjt6WfGxULkBgbRIYPQpf1ekLa2ejut5bQNRhAaaHxJE7-ZGQ34w4A6A?key=UmqXHDTx4TfuBEhIlfOzqhwb)

	Al crear el proyecto, se nos creara un pequeño programa con ello, que contiene una pequeña iteración. La ejecutaremos para verificar que hemos instalado correctamente todo, para ello, presionamos el botón de _run_ que se encuentra en la parte superior derecha.
	
	![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXcJIRWz6OC11ux5AXZquE1zWAeLQUL4Ale0zWHnbLJjM8c-C4TOrwXqGZzEvPkxBRR5ri8w3057WfjatWn5rUNvHo58UVykxLtSWHa9hAYv0a-EYpcTT5moUEOrh1M1Godxv6KXZg?key=UmqXHDTx4TfuBEhIlfOzqhwb)

	Se nos abrirá la consola y deberíamos ver la siguiente salida
	 ```shell
		Hello and welcome!i = 1
		i = 2
		i = 3
		i = 4
		i = 5
	```




## Posibles errores y soluciones

1. **Problema al crear el proyecto**
![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXfxGe19ogFmLxbR1Y3hLAwEQKMbhEsFqjMbXaHhP8GUc653K3NFj-DnuQIdM8FVt83CozEH_DyNI1IC4Zi2D7fE4KDZ0Qm6wjwf-ZVjjHCT-k7ehm3eJUDXvWjGztOGfMWrn-WKYg?key=UmqXHDTx4TfuBEhIlfOzqhwb)

	Para solucionar este error, solamente debemos ejecutar IntelliJ IDEA como administrador.
	

## Anexos

[Guia instalación oficial de IntelliJ](https://www.jetbrains.com/help/idea/installation-guide.html#toolbox)
