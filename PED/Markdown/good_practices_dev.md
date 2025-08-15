# Buenas practicas para desarrollo

https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines

https://google.github.io/styleguide/cppguide.html

https://pvs-studio.com/en/blog/posts/cpp/0391/

https://rigtorp.se/cpp-best-practices/

https://micro-os-plus.github.io/develop/sutter-101/

https://medium.com/@Code_Analysis/collecting-the-best-c-practices-4b867006849f

https://opentitan.org/book/doc/contributing/style_guides/c_cpp_coding_style.html

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
