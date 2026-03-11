# Comandos Avanzados de Git

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

![enter image description here](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/f0f48c6246415b2f22d3c97ec07958d1be4146e4/POO/imagenes/uso-git/1.png)

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
5.  Sigue la convención del mensaje de commit definida por tu equipo. También puedes guiarte por esta guía universal [Commits-Convencionales](https://www.conventionalcommits.org/es/v1.0.0-beta.3/#especificaci%C3%B3n)
    
6.  Usar emojis en los mensajes de commit puede ser una forma efectiva de hacer que el historial de commits sea más visual y fácil de entender. Para hacerlo, se recomienda usar emojis con significado, que ayudan a identificar rápidamente el tipo de cambio realizado. Aquí te mostramos cómo puedes utilizar emojis en tus mensajes de commit de manera efectiva, para ellos puedes usar la pagina de [Gitmoji](https://gitmoji.dev/)

	```bash
	git commit -m ":sparkles: add: Implementar la funcionalidad de búsqueda en la barra lateral"
	```

## GitFlow
GitFlow es una metodología de ramificación (branching) para trabajar con Git que proporciona una estructura clara y bien definida para el desarrollo de software en equipo. Esta metodología fue creada por Vincent Driessen en 2010 y es ampliamente utilizada en proyectos de software empresariales.

GitFlow utiliza dos ramas principales en el repositorio: una rama "main" que representa la versión estable del software y una rama "develop" que representa la versión en desarrollo. Además, utiliza ramas secundarias para el desarrollo de nuevas funciones y correcciones de errores. Estas ramas secundarias pueden ser temporales o permanentes, dependiendo del alcance y duración de la tarea.

El flujo de trabajo de GitFlow se divide en varias fases, que se detallan a continuación:

![enter image description here](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/f0f48c6246415b2f22d3c97ec07958d1be4146e4/POO/imagenes/uso-git/2.png)

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
    git commit -m "Añadida la funcionalidad de cuadrícula del Excel"
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
git push origin main
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

 -   **Git diff**:  permite **visualizar los cambios realizados en los archivos** del proyecto que aún no han sido confirmados (`commit`). Es muy útil para revisar qué modificaciones se hicieron antes de agregarlas al área de preparación (`staging`) o antes de un commit. Comparar cambios en archivos modificados pero no añadidos al staging.

```bash
git diff
```

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


## Anexos

### Uso de Inteligencia Artificial para la generación de mensajes de commit
La Inteligencia Artificial puede ayudar a generar mensajes de commit claros y consistentes.

Esto es útil cuando:
-   Se realizan muchos cambios
-   Se trabaja en equipos grandes
-   Se desea mantener un estándar en los commits
    
**Herramientas comunes**
-   ChatGPT
-   GitHub Copilot
-   extensiones de IA para Git

### Prompt recomendado para generar commits

Puedes usar un prompt como el siguiente:

    Genera un mensaje de commit siguiendo Conventional Commits.
    Cambios realizados:
    - Se agregó validación de correo en el formulario de registro 
    - Se corrigió un error que permitía enviar formularios vacíos 
    El commit debe incluir:
    - Tipo de commit
    - Título claro
    - Descripción breve
   
  ####  Ejemplo generado por IA

```bash
 fix: Mejorar validación en formulario de registro
    Se agregó validación para el campo de correo electrónico y se corrigió 
    un error que permitía enviar formularios con campos vacíos. 
```


#### Uso en Git
  ```bash
     git commit -m ":bug: fix: Mejorar validación en formulario de registro"
     -m "Se agregó validación para el correo electrónico y se corrigió un
     error que permitía enviar formularios vacíos."
```
 

