# Comandos Avanzados de Git

En este laboratorio, aprenderás diferentes comandos de Git, metodología de trabajo con Git, para la eficiencia de la gestión de versiones de aplicaciones.

## Git - Comandos básicos
Git es un sistema de control de versiones creado por **Linus Torvalds** en 2005. Su principal propósito es permitir que varios desarrolladores trabajen en un mismo proyecto de manera eficiente y organizada, asegurando que todos los cambios en el código fuente se registren y gestionen adecuadamente.

#### Configuración de Git (Importante)

#### Clonando repositorios
- Repositorio existente
	```bash
	git clone <url-del-repositorio>
	``` 
#### Si estás usando tu computadora personal
Para configurar tu nombre de usuario y correo electrónico a nivel global (para todos los repositorios que clones en tu computadora)

- Establecer credenciales de usuario
	```bash
	git config --global user.name "Tu Nombre"
	git config --global user.email "tuemail@example.com"
	``` 
####  Si estás usando las computadoras del laboratorio

Si estás usando las computadoras del laboratorio y necesitas configurar credenciales específicas para un repositorio:
- Verificar si no hay credenciales asignadas
- Navega al directorio del repositorio en el laboratorio
-  Verificar si no hay credenciales ya asignadas globalmente
	```bash
	git config --global --list
	```
- **De haber credenciales globales**, eliminarlas
	```bash
	git config --global --unset user.name
	git config --global --unset user.email
	```
- Establece tus credenciales para el repositorio
	```bash
	git config user.name "Tu Nombre"
	git config user.email "tuemail@example.com"
	```
- Una vez terminado el laboratorio, elimina tus credenciales
	```bash
	git config --unset user.name
	git config --unset user.email
	```
#### Trabajando con ramas
- Listar ramas locales
	```bash
	git branch
	``` 
- Crear una nueva rama local
	```bash
	git branch <nombre-de-la-rama>
	``` 
- Cambiar a otra rama
	```bash
	git checkout <nombre-de-la-rama>
	``` 
- Eliminar una rama
	```bash
	git branch -d <nombre-de-la-rama>
	``` 
#### Cambios en el repositorio
- Agregar archivos específicos al área de preparación (staging)
	```bash
	git add <nombre-del-archivo>
	``` 
- Para agregar todos los archivos modificados:
	```bash
	git add .
	``` 
- Confirmar los cambios en el repositorio
	```bash
	git commit -m "Mensaje del commit"
	``` 
- Enviar cambios a repositorio remoto
	```bash
	git push <remoto> <rama>
	``` 

### Flujo de trabajo básico en Git

![enter image description here](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/refs/heads/main/PED/Imagenes/CP1/A.png)

- **Working directory:** es el espacio donde trabajas en el proyecto, haciendo cambios en los archivos y carpetas que componen tu código fuente.
- **Staging area:** es un espacio en el repositorio de Git donde preparas los cambios antes de confirmarlos. Es una etapa intermedia entre los cambios realizados en el directorio de trabajo y el historial de commits del repositorio.
- **Git commit** Un commit es una instantánea de los cambios en el proyecto en un momento específico. Un commit incluye todos los cambios que has preparado en el área de preparación junto con un mensaje que describe esos cambios.

### Estructura básica de un commit
```bash
git commit -m "Añadida funcionalidad para el login de usuarios"
```

### ¿Cómo hacer buenos commits?
Hacer buenos commits en Git es una habilidad crucial para mantener un historial de proyecto claro, comprensible y manejable. Un buen commit no solo refleja cambios en el código, sino que también proporciona contexto y facilita la colaboración.

1.  Especifica el tipo de commit:  
    **feat**: La nueva característica que agregas a una aplicación en particular  
    **fix**: Un parche para un error  
    **style**: Características o actualizaciones relacionadas con estilos  
    **refactor**: Refactorizar una sección específica de la base de código  
    **test**: Todo lo relacionado con pruebas  
    **docs**: Todo lo relacionado con documentación  
    **chore**: Mantenimiento de código regular.
    
    Ejemplo:
    ```bash
    git commit -m "fix: Corregir error de cálculo en la función de descuento"
    ```
2.  Quita signos de puntuación innecesarios.
    
3.  Usa mayúsculas al inicio del título y por cada párrafo del cuerpo del mensaje.
    
4.  Usa el cuerpo del mensaje para explicar los cambios: Además del titulo, un commit tiene un cuerpo del mensaje, en el cuál, puedes explicar a los colaboradores del repositorio tus cambios.
	```bash
	git commit -m "fix: Corregir error en la validación del formulario de registro"
	-m "Se corrigió un error que impedía que los usuarios con una contraseña válida pudieran registrarse correctamente. 
	El problema se debía a una falta de validación en el campo de contraseña que permitía caracteres especiales no permitidos."
	```
5.  Sigue la convención del mensaje de commit definida por tu equipo.
    
6.  Usar emojis en los mensajes de commit puede ser una forma efectiva de hacer que el historial de commits sea más visual y fácil de entender. Para hacerlo, se recomienda usar emojis con significado, que ayudan a identificar rápidamente el tipo de cambio realizado. Aquí te mostramos cómo puedes utilizar emojis en tus mensajes de commit de manera efectiva, para ellos puedes usar la pagina de [Gitmoji](https://gitmoji.dev/)

	```bash
	git commit -m ":sparkles: add: Implementar la funcionalidad de búsqueda en la barra lateral"
	```

## GitFlow
GitFlow es una metodología de ramificación (branching) para trabajar con Git que proporciona una estructura clara y bien definida para el desarrollo de software en equipo. Esta metodología fue creada por Vincent Driessen en 2010 y es ampliamente utilizada en proyectos de software empresariales.

GitFlow utiliza dos ramas principales en el repositorio: una rama "main" que representa la versión estable del software y una rama "develop" que representa la versión en desarrollo. Además, utiliza ramas secundarias para el desarrollo de nuevas funciones y correcciones de errores. Estas ramas secundarias pueden ser temporales o permanentes, dependiendo del alcance y duración de la tarea.

El flujo de trabajo de GitFlow se divide en varias fases, que se detallan a continuación:

![enter image description here](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/refs/heads/main/PED/Imagenes/CP1/B.png)

-   **Rama “Main o Master”:** La rama main o principal almacena el historial de publicación oficial, asimismo en esta rama conviene etiquetar todas las confirmaciones de la rama main con un número de versión.
    
-   **Rama "develop":** Esta rama es la base de desarrollo para el proyecto. Todas las nuevas funciones y correcciones de errores se desarrollan en esta rama.
    
-   **Rama "feature":** Cuando se trabaja en una nueva función, se crea una rama "feature" a partir de la rama "develop". Esta rama se utiliza para desarrollar la nueva función y se integra de nuevo en la rama "develop" cuando se completa.
    
-   **Rama "release":** Cuando se ha completado una serie de funciones y se está preparando una nueva versión del software, se crea una rama "release" a partir de la rama "develop". Esta rama se utiliza para realizar pruebas finales y corregir errores antes de integrar la versión en la rama "main".
    
-   **Rama "hotfix":** Cuando se descubre un error en la versión estable del software (rama "master"), se crea una rama "hotfix" a partir de la rama "master". Esta rama se utiliza para corregir el error y se integra en ambas ramas " main " y "develop" una vez completada.
    
El flujo de trabajo de GitFlow se puede visualizar en un diagrama de flujo, que muestra cómo se integran y se ramifican las distintas ramas. Esta metodología es muy útil para proyectos grandes y complejos, ya que ayuda a mantener un flujo de trabajo estructurado y a minimizar los errores y conflictos en el desarrollo del software en equipo.

#### Ejemplo de uso aplicando la metodología GitFlow de forma manual:

Por ejemplo, si se está creando la aplicación de un miniExcel, una aplicación correcta de Git Flow puede ser:

1.  Creación del repositorio: Se crea un nuevo repositorio en Git y se inicializa con una rama **"main"** y una rama **"develop"**.
	 ```bash
	git checkout -b main 
	git checkout -b develop
	 ```
    
2.  Desarrollo de una nueva función: Se decide añadir una nueva función que permita a los usuarios ver la cuadrícula del excel. Para ello, se crea una rama *"feature/matriz-excel"* a partir de la rama **"develop"**. En esta rama, se desarrolla la nueva función y se realizan las pruebas necesarias.
	```bash
	git checkout develop 
	git checkout -b feature/matriz-excel
	 ```
    
3.  Integración de la nueva función: Una vez que se han completado las pruebas y la nueva función funciona correctamente, se integra en la rama **"develop"**. Se verifica que todo el código de la rama *"feature/matriz-excel"* esté integrado en la rama **"develop".**
    ```bash
    git add . 
    git commit -m "Añadida la funcionalidad de 	cuadrícula del Excel"
	git checkout develop 
	git merge feature/matriz-excel
	 ```
4.  Preparación de una nueva versión: Se decide que se ha desarrollado suficiente funcionalidad como para lanzar una nueva versión del software. Se crea una rama **"release/v1.0"** a partir de la rama **"develop"**. En esta rama se realizan las pruebas finales y se corrigen los errores que se encuentren.
	 ```bash
	 git checkout develop 
	 git checkout -b release/v1.0
	 ```
5.  Lanzamiento de la nueva versión: Una vez que se ha completado la rama **"release/v1.0"** y se ha verificado que todo funciona correctamente, se integra en la rama "main". La nueva versión del software está lista para su lanzamiento.
	 ```bash
	git checkout main 
	git merge release/v1.0
	 ```
    
6.  Corrección de errores: Después del lanzamiento de la nueva versión, se descubre un error crítico que afecta a la funcionalidad de la aplicación. Se crea una rama **"hotfix/error-matriz-excel"** a partir de la rama **"main"** para corregir este error. 
	```bash
	git checkout main 
	git checkout -b hotfix/error-matriz-excel
	git add . 
	git commit -m "Corregido error en la funcionalidad de cuadrícula"
	 ```
7. Se realiza la corrección y se integra en ambas ramas **"main”** y **"develop"**.
	```bash
	git checkout main 
	git merge hotfix/error-matriz-excel 
	git checkout develop 
	git merge hotfix/error-matriz-excel
	 ```
8.  Fin del ciclo: Se ha completado el ciclo de desarrollo y se vuelve a la rama "develop" para iniciar el siguiente ciclo. Normalmente en el desarrollo se repite del paso 1 al 3 para cada característica que se desee incluir en la versión a publicar de la aplicación.

### Complemento de Git Flow
El complemento Git Flow proporciona una serie de comandos que automatizan la gestión de ramas y procesos en Git Flow. Esto facilita la implementación de las prácticas recomendadas de Git Flow sin tener que realizar manualmente cada operación de rama y fusión.

####  Instalación del complemento
- En Windows no es necesario instalar Git Flow, ya que ya viene instalado por defecto en la terminal de Git.
- Para instalar en MacOS se instala usando Homebrew 
	```bash
	brew install git-flow
	```
- Para instalar en Debian/Ubuntu se puede instalar usando APT
	```bash
	sudo apt-get install git-flow
	```
#### Ejemplo de uso aplicando la metodología GitFlow a través del complemento:
Para usar el complemento de Git Flow y automatizar trabajar con esta metodología, cuando clonemos un repositorio y queramos trabajar con esta metodología en primer lugar hay que inicializarlo:
```bash
git flow init
```
Se pedirá que configures los nombres de las ramas. Puedes aceptar los valores predeterminados los cuales harán que `master` sea para producción y `develop` para desarrollo. Las ramas de características `feature/`, lanzamientos `release/` y correcciones `hotfix/` también se configurarán.

Una vez configurado, podremos empezar a usarlo, para empezar supongamos que quieres **añadir una nueva funcionalidad** esto lo harás mediante este comando:
```bash
git flow feature start matriz-excel
```
Esto te creará la nueva rama a partir de lo que haya en la rama `develop` y te va a posicionar en ella. Una vez estés ahí puedes usar los comandos anteriormente vistos del flujo normal de Git
```bash
git add . 
git commit -m "Añadida funcionalidad de cuadrícula"
```
Ahora, esa rama que creamos, estará solamente local, por lo tanto, hay que subirla o publicarla en el repositorio remoto de Github
```bash
git flow feature publish matriz-excel
```
Luego, cuando terminemos de hacer el flujo normal y terminemos nuestra característica, vamos a ejecutar este comando, este comando lo que hará es hacer el trabajo que anteriormente hacíamos, de fusionar la rama de la característica con `develop` y nos va a posicionar en ella.
```bash
git flow feature finish matriz-excel
```
Por ultimo, subiremos lo que tenemos en la rama `develop` a nuestro repositorio remoto
```bash
git push origin develop
```

#### Para subir una release

Una vez tenemos una versión estable de nuestro código, se realiza una "release" la cual manejaremos como versiones de nuestro código y estas normalmente incluyen el fusionar la rama `develop` con la rama `main`, para ello, crearemos una rama nueva de versión de lanzamiento `feature/v1.0.0`
```bash
git flow release start v1.0.0
```
En este punto se recomienda que en esta rama nueva se hagan cambios o preparaciones para subir la versión, nuevamente puedes hacerlos con los comandos de `git add` y `git commit`

Cuando finalices las pruebas finales, termina la versión final.
```bash
git flow release finish v1.0.0
```
Esto fusionará `release/1.0` en `master`, etiquetará la versión, y también fusionará los cambios en `develop`. Además, eliminará la rama `release/1.0`.

Luego, para reflejar estos cambios en el repositorio remoto, sigue los siguientes comandos:
```bash
git push origin master
git push origin develop
```

Puedes leer más sobre como usar Git Flow en este recurso:

- [GitFlow: ¿Qué és y cómo aplicarlo sin morir en el intento?](https://gfourmis.co/gitflow-sin-morir-en-el-intento/)

## Comandos Git

 -   **Git log**: este comando mostrará una lista de commits con detalles como el ID del commit, la fecha, el autor y el mensaje del commit. El ID del commit es una cadena alfanumérica que generalmente se muestra al principio de cada entrada.
```bash
	git log
```
 -   **Git checkout (Commit)**: Una vez que tienes el ID del commit, puedes usar el siguiente comando para moverte a ese commit específico:
```bash
	git checkout <commit_id>
```
 -   **Git diff**: La comparación es una función mediante la cual se toman dos conjuntos de datos de entrada y se muestran los cambios entre estos. git diff es un comando multiusos de Git que, cuando se ejecuta, lleva a cabo una función para establecer las diferencias en los orígenes de datos de Git. Dichos orígenes de datos pueden ser confirmaciones, ramas y archivos, entre otras posibilidades
 
La mejor manera de explicar cómo funciona git diff es con un ejemplo. Supongamos que se crea un nuevo proyecto con el nombre de “proyecto_nuevo” y que se añade dos documentos de texto. Estos documentos se denominan color_primero.txt y color_segundo.txt. El contenido de color_primero.txt es la frase “El primer color es azul”. El documento color_segundo.txt solo contiene la frase “El segundo color es el rojo”. Si ahora entras en git diff, al principio no pasará nada, porque el repositorio todavía no contiene ningún cambio que pueda ser comparado, se tendrían que mover los dos documentos al área de staging con el comando git add.

Primero se debe comprobar con el comando git status qué cambios se han realizado y, por tanto, están teóricamente listos para un commit. En este caso se visualizan los dos documentos de texto color_primero.txt y color_segundo.txt.

![enter image description here](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/refs/heads/main/PED/Imagenes/CP1/D.png)

Ahora, se cambia el segundo documento modificando el enunciado “El segundo color es rojo” 	por “El segundo color es amarillo”. Ahora podrás ver este cambio con git diff. El resultado sería el siguiente:

![enter image description here](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/refs/heads/main/PED/Imagenes/CP1/E.png)

-   **Git tag**: En Git, los tags son referencias estáticas a puntos específicos en la historia del repositorio, generalmente se utilizan para marcar versiones importantes o hitos en el desarrollo del proyecto.


	- **Crear un tag:** 
		```bash
		git tag nombre-etiqueta
		```
		
	- **Ver los tags:**
		 ```bash
		git tag
		```

		**Crear un tag con mensaje:** 
		 ```bash
		git tag -a nombre_del_tag -m "Mensaje del tag"
		```

	- **Ver detalles de un tag:** git show nombre_del_tag
		 ```bash
		git show nombre_del_tag
		```

## Indicaciones para el ejercicio evaluado
    
1. **Crea un grupo**: Forma tu equipo máximo 3 personas (Un persona crea el grupo y los demás se unen).
2. **Clona el repositorio**: Utiliza el enlace proporcionado para clonar el repositorio en tu entorno de trabajo.
3.  **Desarrolla el ejercicio**: Sigue las instrucciones del instructor para completar el ejercicio propuesto. Además asegúrate de trabajar con **metodología Git Flow**
4. **Verifica los cambios en GitHub**: Ingresa a tu repositorio en GitHub y asegúrate de que los cambios hayan sido correctamente reflejados.
5. **Elimina credenciales de Windows (si aplica)**: Si utilizaste computadoras del laboratorio, recuerda borrar tus credenciales de Windows para proteger tu información.
6. **Elimina programas y carpetas temporales**: Asegúrate de borrar cualquier programa o carpeta que hayas creado durante la práctica, especialmente en computadoras compartidas.


## Anexos

### Uso de SSH para clonar repositorios
Configurar SSH te permite establecer conexiones seguras a servidores y gestionar repositorios remotos en GitHub u otros servicios. Aquí está una guía paso a paso para configurar SSH en Windows

- Asegúrate primero de tener Git instalado en tu computadora
- Luego de eso, hay que generar una llave SSH, para esto podemos ejecutar el siguiente comando en nuestro terminal:
	 ```bash
	 ssh-keygen -t rsa -b 4096 -C "your_email@example.com"
	 ``` 
-   Cuando se te pida, elige una ubicación para guardar la clave. La ubicación predeterminada (`~/.ssh/id_rsa`) es generalmente adecuada,.
-   También se te pedirá una frase de contraseña para proteger la clave. Puedes dejarla en blanco si prefieres no usar una frase de contraseña.

![enter image description here](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/refs/heads/main/PED/Imagenes/CP1/F.png)

- Luego en tu computador, dirígete a la ubicación donde se creo el SSH publico, que es el que esta marcado en rojo en la fotografía anterior. Si copias y pegas la ruta en tu gestor de archivos, te abrirá un bloc de notas con una serie de caracteres, la cual es nuestra llave publica.
- Copia la llave publica generada.
- Luego que la tengas copiada, nos dirigiremos a Github y nos iremos nuestra foto de perfil y seleccionaremos "configuración"

![enter image description here](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/refs/heads/main/PED/Imagenes/CP1/G.png)
- En la configuración nos iremos al apartado "SSH keys and GPG keys" y agregaremos una nueva llave SSH

![enter image description here](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/refs/heads/main/PED/Imagenes/CP1/H.png)

- Le podemos poner cualquier titulo y dejamos seleccionado el tipo de llave de autenticación y luego en la "key" pegamos la llave publica que estaba en nuestro bloc de notas.

- Una ves realizado este paso, podemos probar clonando un repositorio nuevamente, sin embargo, como ya configuramos nuestro SSH, podemos usar esta nueva URL para clonar el repositorio en ves de con HTTPS.

![enter image description here](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/refs/heads/main/PED/Imagenes/CP1/I.png)

- Al clonar un repositorio, nos puede decir lo siguiente, solo le damos a "yes" y si hicimos los pasos correctamente, lo clonará.

![enter image description here](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/refs/heads/main/PED/Imagenes/CP1/J.png)


- Si tienes dudas o errores, no dudes en consultar con tu instructor.
