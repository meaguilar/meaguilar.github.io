# Estructuras de datos dinámicas lineales: Listas 

## 1. Estructuras de datos lineales y listas enlazadas

Una **estructura de datos lineal** organiza sus elementos en una secuencia: cada elemento tiene un predecesor y un sucesor, excepto los de los extremos. Los arreglos, las pilas, las colas y las listas son ejemplos.


![Lista](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/refs/heads/main/PED/Imagenes/CP2/A.png)

## 2. ¿Qué es una lista dinámica?

Una **lista dinámica** es una estructura de datos lineal cuyo tamaño puede crecer o reducirse en tiempo de ejecución. A diferencia de los arreglos (listas estáticas), **no necesita un tamaño fijo**.

**Características**

- **Uso de punteros:** cada nodo guarda punteros que lo enlazan con otros nodos.
- **Memoria dinámica:** se reserva y libera durante la ejecución con `new` y `delete`.
- **Inserción y eliminación eficientes:** solo se ajustan punteros, sin mover el resto de elementos.

### 2.1 Cómo se ve una lista en memoria

Cuando se crea una lista dinámica intervienen dos zonas de memoria:

- **Stack:** aquí vive el **puntero** (`cabeza`). Ocupa un bloque pequeño con su propia dirección (por ejemplo `0x1000`) y su contenido es la dirección del primer nodo (`0x5000`).
- **Heap:** aquí vive el **nodo**, reservado con `new`. Tiene su propia dirección (`0x5000`) y guarda el dato (`25`) y el puntero `siguiente` (`nullptr`).

> Las direcciones son ejemplos: el sistema operativo asigna direcciones reales distintas en cada ejecución.

**🖼️ IMAGEN 1: Diagrama de memoria (stack vs. heap) en 3 paneles**

- **Tipo:** diagrama horizontal dividido en dos columnas (STACK a la izquierda, HEAP a la derecha). Se repite en 3 paneles (A, B, C) para mostrar la evolución.
- **Panel A, "Reserva correcta":**
  - Columna STACK (azul): recuadro `cabeza`, con la etiqueta *"Dirección del puntero: 0x1000"* y dentro *"valor: 0x5000"*.
  - Columna HEAP (naranja): recuadro `Nodo`, con la etiqueta *"Dirección del nodo: 0x5000"* y dentro `dato: 25` y `siguiente: nullptr`.
  - Una flecha gruesa sale del valor `0x5000` del puntero hasta el nodo.
  - Rótulo bajo el nodo: *"bloque reservado con `new`"*. Pie de imagen: `Nodo* cabeza = new Nodo{25, nullptr};`
- **Panel B, "Fuga de memoria" (rojo):**
  - El puntero `cabeza` ahora vale `nullptr` (flecha eliminada, con una X roja) pero el nodo en `0x5000` sigue ocupado en el heap.
  - Etiqueta roja sobre el nodo: *"Fuga de memoria: el espacio queda atrapado sin poder reutilizarse (no se hizo `delete`)"*.
- **Panel C, "Puntero colgante" (rojo → verde):**
  - Se hizo `delete cabeza;` así que el nodo del heap aparece en gris, con borde punteado y la etiqueta *"bloque liberado"*.
  - `cabeza` sigue valiendo `0x5000`, con una flecha roja discontinua hacia el bloque gris. Etiqueta roja: *"Puntero colgante: apunta a una dirección ya liberada"*.
  - A la derecha, una segunda versión (verde) con `cabeza = nullptr;` y una nota: *"Solución: asignar `nullptr` después del `delete`"*.
- **Detalle importante:** en los tres paneles deben verse claramente las **dos direcciones distintas** (la del puntero y la del nodo) con el mismo estilo de etiqueta.

### 2.2 Conceptos clave en la imagen

- **Puntero propietario:** puntero que guarda la dirección de un bloque reservado en el heap y es responsable de liberarlo. `new` pide el espacio y `delete` lo libera.
- **Fuga de memoria:** ocurre cuando se pierde la única referencia a un nodo o el programa termina sin ejecutar `delete`. El bloque queda ocupado y no puede reutilizarse durante la ejecución.
- **Puntero colgante:** puntero que sigue apuntando a una dirección del heap **después** de liberarla con `delete`. Nunca se debe desreferenciar; por eso se asigna `nullptr` tras liberar.
- **`nullptr`:** valor especial que indica que el puntero no apunta a ninguna dirección válida.

## 3. Tipos de listas dinámicas

Todas están formadas por **nodos**. Cada nodo tiene un **dato** y uno o más **punteros**. Lo que cambia entre tipos es cuántos punteros tiene cada nodo y cómo terminan los extremos.

### 3.1 Lista simplemente enlazada

Cada nodo apunta solo al **siguiente**. El último nodo apunta a `nullptr`, lo que marca el final. Solo se recorre hacia adelante. Es la más fácil de implementar.

**🖼️ IMAGEN 2: Diagrama de nodos, lista simple**

- **Tipo:** diagrama horizontal de 3 o 4 nodos.
- **Contenido:** cada nodo es un rectángulo dividido en dos partes (`dato` | `siguiente`). Flechas de izquierda a derecha entre nodos.
- **Etiquetas:** un puntero `cabeza` (azul, en el stack) apuntando al primer nodo; el último nodo con `siguiente → nullptr` (símbolo de tierra o "X" y la etiqueta *nullptr = fin de la lista*).

### 3.2 Lista doblemente enlazada

Cada nodo tiene **dos punteros**: `siguiente` y `anterior`. Permite recorrer en ambos sentidos. El `anterior` del primer nodo y el `siguiente` del último apuntan a `nullptr`, y esos son los extremos de la lista.

**🖼️ IMAGEN 3: Diagrama de nodos, lista doble**

- **Tipo:** diagrama horizontal de 3 o 4 nodos, cada uno dividido en tres partes (`anterior` | `dato` | `siguiente`).
- **Contenido:** flechas dobles (o dos flechas de colores distintos: una verde hacia adelante y una azul hacia atrás) entre nodos consecutivos.
- **Etiquetas:** `nullptr` a la izquierda del primer nodo y a la derecha del último; `cabeza` apuntando al primer nodo.

### 3.3 Lista circular simplemente enlazada

Igual que la simple, pero el último nodo **apunta de vuelta al primero**. No existe `nullptr` al final, por lo que se puede recorrer de forma continua. Se detiene el recorrido al volver a la cabeza.

**🖼️ IMAGEN 4: Diagrama de nodos, circular simple**

- **Tipo:** diagrama de nodos con forma de anillo (o rectangular con flecha de retorno curva).
- **Contenido:** 3 o 4 nodos (`dato` | `siguiente`) con flechas hacia adelante; una flecha curva destacada (verde o roja) del último nodo de vuelta al primero.
- **Etiquetas:** `cabeza` apuntando al primer nodo; rótulo *"el último nodo apunta a la cabeza"* junto a la flecha de retorno.

### 3.4 Lista circular doblemente enlazada

Cada nodo tiene `siguiente` y `anterior`, y además los extremos se conectan: el último apunta al primero y el primero al último. Permite recorrido continuo **en ambos sentidos**.

**🖼️ IMAGEN 5: Diagrama de nodos, circular doble**

- **Tipo:** anillo de nodos con `anterior` | `dato` | `siguiente`.
- **Contenido:** flechas dobles entre nodos consecutivos y dos flechas curvas de cierre: `último.siguiente → primero` y `primero.anterior → último`.
- **Etiquetas:** `cabeza` en el primer nodo; resaltar las dos flechas de cierre con un color distinto.

### 3.5 Comparación rápida

| Tipo | Punteros por nodo | ¿Termina en `nullptr`? | Recorrido |
| --- | --- | --- | --- |
| Simple | `siguiente` | Sí | Solo hacia adelante |
| Doble | `siguiente`, `anterior` | Sí (ambos extremos) | Ambos sentidos |
| Circular simple | `siguiente` | No, vuelve a la cabeza | Continuo hacia adelante |
| Circular doble | `siguiente`, `anterior` | No | Continuo en ambos sentidos |

## 4. Ejercicio práctico: lista doblemente enlazada

**Enunciado.** Implementa una lista doble de enteros que permita **insertar al final**, **recorrer** la lista y **liberar** todos sus nodos. La función principal es `insertarAlFinal`: cada inserción actualiza **dos enlaces**, el `siguiente` del último nodo anterior y el `anterior` del nuevo nodo.

**🖼️ IMAGEN 6: Diagrama antes/después de insertar al final**

- **Tipo:** diagrama de dos filas (ANTES arriba, DESPUÉS abajo).
- **ANTES:** lista `10 ⇄ 20` con `cabeza` apuntando al `10` y un nodo nuevo `30` suelto, con sus dos punteros en `nullptr` (etiqueta *"nuevo"*).
- **DESPUÉS:** `10 ⇄ 20 ⇄ 30`, con las **dos flechas nuevas** en color destacado y numeradas: ① `actual->siguiente = nuevo` y ② `nuevo->anterior = actual`.
- **Etiquetas:** marcar `actual` apuntando al `20` durante la operación.

**📸 CAPTURA 7: Bloque de código de `insertarAlFinal` (anotada)**

- **Qué capturar:** solo la función `insertarAlFinal` completa, desde tu editor (con resaltado de sintaxis y números de línea).
- **Qué señalar sobre la captura** (flechas o círculos de colores con llamadas a un costado), según el bloque de memoria donde vive cada cosa:

| Elemento | Qué es | Dónde vive | Qué guarda |
| --- | --- | --- | --- |
| `cabeza` (parámetro por referencia; en `main` es la variable original) | Puntero al primer nodo | **Stack** (de `main`) | Dirección del primer nodo del heap |
| `nuevo` | Puntero local | **Stack** (de `insertarAlFinal`) | Dirección del nodo recién reservado con `new` |
| `*nuevo` (el nodo creado con `new`) | Nodo con `dato`, `anterior`, `siguiente` | **Heap** | El valor y los dos punteros |
| `actual` | Puntero de recorrido | **Stack** | Dirección del nodo que se está visitando; avanza hasta el último sin modificar `cabeza` |
| `actual->siguiente = nuevo` | Enlace hacia adelante | Dentro del nodo (heap) | Dirección del nuevo nodo |
| `nuevo->anterior = actual` | Enlace hacia atrás | Dentro del nodo (heap) | Dirección del nodo anterior |

- **Código de color:** azul para lo que vive en el stack, naranja para lo que vive en el heap (igual que en la Imagen 1). Se puede añadir a cada llamada una dirección de ejemplo (`0x1000`, `0x5000`, etc.) para reforzar la idea de dirección de memoria.

**📸 CAPTURA 8: Salida del programa**

- **Qué capturar:** la consola ejecutando el programa completo. Salida esperada: `10 <-> 20 <-> 30 <-> nullptr`.

### Lectura de los punteros en la inserción

1. `nuevo` es un puntero local que guarda la dirección del nodo reservado en el heap.
2. `actual` recorre la lista hasta el último nodo sin modificar `cabeza`.
3. `actual->siguiente = nuevo` guarda en el último nodo la dirección del nuevo.
4. `nuevo->anterior = actual` guarda en el nuevo nodo la dirección del anterior.
5. `cabeza` vive en el stack de `main`; cada nodo vive en el heap. Al final, `liberarLista` ejecuta un `delete` por cada `new` y deja `cabeza` en `nullptr`.

### Actividades propuestas

- Agrega una función `buscar` que devuelva el primer nodo cuyo dato coincida con un valor.
- Implementa `eliminar` para borrar el primer nodo encontrado y mantener correctos los enlaces `anterior` y `siguiente`.
- Agrega un recorrido desde el último nodo hasta `cabeza` y comprueba que ningún enlace quede roto.
- Usa un depurador o imprime las direcciones de `cabeza`, `actual` y `nuevo` para relacionar el código con el esquema de memoria.

## 5. Ejemplos de programas que utilizan listas

| Tipo de lista | Ejemplo de aplicación | Motivo para utilizarla |
| --- | --- | --- |
| Simplemente enlazada | Historial de tareas pendientes | Se recorre principalmente hacia adelante y se inserta con poco costo. |
| Doblemente enlazada | Navegador web o reproductor multimedia | Permite avanzar y retroceder entre páginas, canciones o registros. |
| Circular simplemente enlazada | Turnos de atención o planificación Round Robin | Al llegar al último elemento se vuelve al primero. |
| Circular doblemente enlazada | Editor de diapositivas o carrusel de imágenes | Permite recorrer cíclicamente en ambos sentidos. |
| Lista de objetos | Agenda de contactos o inventario | Cada nodo puede contener varios campos relacionados. |

*(Opcional visual: un ícono pequeño junto a cada ejemplo: navegador, reproductor, reloj/turnos, carrusel, agenda.)*

## 6. Buenas prácticas de implementación

- **Una responsabilidad por función:** insertar, buscar, recorrer, eliminar y destruir.
- **Inicializa todos los enlaces** (`anterior` y `siguiente`) antes de conectar un nodo a la lista.
- **Conserva las invariantes:** en una lista doble, si `nodo->siguiente` existe, su `anterior` debe apuntar a `nodo`.
- **Define quién es el propietario** de cada nodo y documéntalo en el diseño.
- **Cada `new` debe tener su `delete`:** libera todos los nodos antes de abandonar la lista.
- **Después de `delete`, asigna `nullptr`** al puntero para evitar punteros colgantes.
- **Inicializa los punteros en `nullptr`** y verifica `ptr != nullptr` antes de usarlos.
- **Al insertar:** crea el nodo, ajusta los enlaces y recién entonces conéctalo. **Al eliminar:** cambia primero los enlaces y luego libera la memoria.
- **Revisa los casos límite:** lista vacía y lista de un solo nodo, antes de modificar enlaces.
- **En listas circulares** no recorras con `actual != nullptr`; detén el recorrido al volver a la cabeza.
- **Usa `const`** en funciones de solo lectura y evita copias innecesarias.
- **En código moderno**, considera `std::unique_ptr` cuando el diseño permita expresar claramente la propiedad de los nodos.

## 7. Recursos extras

- [Visualizador de listas enlazadas](https://dsa-visualizer-delta.vercel.app/visualizer/linked-list): permite observar inserciones, eliminaciones y enlaces.
- [Repositorio de ejemplos de listas (C++)](https://github.com/UCASV/RecursosExtraPED/tree/main/Listas): implementaciones de las cuatro variantes.
- [103. Programación en C++ || Listas || Concepto de Lista Enlazada](https://youtu.be/15urP2LmfqY?si=QpnrlXg95SHIsgwi) (video).
- [Listas circulares](https://conclase.net/c/edd/cap4) (lectura).

---

## Anexo (opcional): código del ejercicio para tus capturas

```c++
#include <iostream>

struct NodoDoble {
    int dato;
    NodoDoble* anterior;
    NodoDoble* siguiente;
};

void insertarAlFinal(NodoDoble*& cabeza, int valor) {
    NodoDoble* nuevo = new NodoDoble{valor, nullptr, nullptr};

    if (cabeza == nullptr) {
        cabeza = nuevo;
        return;
    }

    NodoDoble* actual = cabeza;
    while (actual->siguiente != nullptr) {
        actual = actual->siguiente;
    }

    actual->siguiente = nuevo;
    nuevo->anterior = actual;
}

void mostrarDesdeElInicio(const NodoDoble* cabeza) {
    const NodoDoble* actual = cabeza;
    while (actual != nullptr) {
        std::cout << actual->dato << " <-> ";
        actual = actual->siguiente;
    }
    std::cout << "nullptr\n";
}

void liberarLista(NodoDoble*& cabeza) {
    while (cabeza != nullptr) {
        NodoDoble* siguiente = cabeza->siguiente;
        delete cabeza;
        cabeza = siguiente;
    }
}

int main() {
    NodoDoble* cabeza = nullptr;
    insertarAlFinal(cabeza, 10);
    insertarAlFinal(cabeza, 20);
    insertarAlFinal(cabeza, 30);
    mostrarDesdeElInicio(cabeza);
    liberarLista(cabeza);
}
```