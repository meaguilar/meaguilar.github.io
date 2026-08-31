# Operadores

## Conceptos de Punteros

**¿Qué es un puntero?** Toda variable se guarda en una dirección de memoria (el lugar físico donde vive el dato). Una variable normal tiene tres características: su valor, su nombre y su dirección de memoria. Un puntero es un tipo especial de variable que también tiene esas tres características, pero su *valor* no es un dato como tal, sino una dirección de memoria que apunta a otro objeto (int, float, char, etc.). Si un puntero no se inicializa bien, puede apuntar a una dirección de memoria no válida.

**Los dos operadores clave:**
- **`&` (referenciar):** obtiene la dirección de memoria de una variable.
- **`*` (desreferenciar):** accede al valor almacenado en la dirección a la que apunta el puntero.

## Paso por valor vs. paso por referencia

![Paso por valor y por referencia](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/refs/heads/main/PED/Imagenes/CP2/CP2-A.gif)

- **Por valor:** la función recibe una *copia* del dato. Los cambios dentro de la función no afectan la variable original.
- **Por referencia (`&`):** la función recibe acceso directo a la variable original mediante su dirección de memoria. Los cambios sí afectan al original.

## Arreglos y punteros

El nombre de un arreglo es en realidad un puntero a su primer elemento — por eso no hace falta usar `&` para obtener esa dirección. Al recorrer un arreglo con un puntero, `*(p + i)` equivale a `arr[i]` (aritmética de punteros).

Cuando se pasa un arreglo a una función, en realidad se pasa un puntero a su primer elemento, así que cualquier modificación dentro de la función se refleja en el arreglo original — se ahorra memoria y tiempo al no copiar los datos.

## ¿Cuándo usar cada uno?

**Referencia (`&`):**
- Cuando siempre debe existir un valor.
- Para pasar parámetros sin copiar.
- Para modificar argumentos de una función.

**Buenas practicas:**

 - Usar `const &` cuando no se necesita modificar el valor (evita copias innecesarias en parámetros grandes: strings, vectores, objetos).
- Usar `&` (sin const) cuando sí se quiere modificar la variable.
- Preferir referencias sobre punteros cuando solo se necesite manipular el contenido de variables en funciones: son más claras y evitan errores como trabajar con direcciones nulas.



**Puntero (`*`):**
- Cuando el valor puede no existir (opcional).
- Para manejar arreglos dinámicos.
- En estructuras de bajo nivel.
- Cuando se necesita cambiar a qué objeto se apunta.

**Buenas practicas:**
- Inicializar siempre los punteros.
- Usarlos cuando se necesite: manipular variables de forma indirecta, gestionar memoria dinámica, o crear estructuras dinámicas (listas enlazadas, árboles, etc.).
- Si se reserva memoria dinámicamente, siempre liberarla.
- Evitar punteros crudos cuando sea posible; en C++ moderno se prefieren **smart pointers** para una gestión más segura. (Un puntero crudo es un puntero tradicional cuya asignación y liberación dependen completamente del programador, sin mecanismos automáticos de seguridad.)

 > 💡 Los punteros tienen su lugar cuando se trabaja con memoria dinámica o estructuras avanzadas.

 ## Resumen visual: Valor vs. Referencia vs. Puntero

![Paso por valor y por referencia](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/refs/heads/main/PED/Imagenes/CP2/CP2-B.png)

En resumen: por valor la función recibe una copia; por referencia recibe acceso directo al dato original; y con un puntero recibe la dirección de memoria donde vive ese dato.

# Anexos


