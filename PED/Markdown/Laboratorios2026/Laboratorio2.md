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

- **Stack:** aquí vive el **puntero** . Ocupa un bloque pequeño con su propia dirección y su contenido es la dirección del primer nodo.
- **Heap:** aquí vive el **nodo**, reservado con `new`. Tiene su propia dirección y guarda el dato y el puntero.
```cpp
	// 1. EL DATO: Lo que queremos almacenar 
struct Cancion { 
	std::string titulo; 
	std::string artista; 
	float duracion; 
}; 
	// 2. EL NODO (Heap): Guarda el dato y las direcciones de memoria 
struct Nodo {
	Cancion cancion; 
	Nodo *siguiente; // Puntero al siguiente nodo 
	Nodo *anterior; // Puntero al nodo anterior 
}; 
	// 3. PUNTEROS DE CONTROL (Stack): Conocen los extremos de la lista 
Nodo *inicio = nullptr; 
Nodo *fin = nullptr;
```

## 3. Tipos de listas dinámicas

Todas están formadas por **nodos**. Cada nodo tiene un **dato** y uno o más **punteros**. Lo que cambia entre tipos es cuántos punteros tiene cada nodo y cómo terminan los extremos.

### 3.1 Lista simplemente enlazada

Cada nodo apunta solo al **siguiente**. El último nodo apunta a `nullptr`, lo que marca el final. Solo se recorre hacia adelante. Es la más fácil de implementar.
**🖼️ IMAGEN 2: Diagrama de nodos, lista simple**

- **Tipo:** diagrama horizontal de 3 o 4 nodos.
- **Contenido:** cada nodo es un rectángulo dividido en dos partes (`dato` | `siguiente`). Flechas de izquierda a derecha entre nodos.
- **Etiquetas:** un puntero `cabeza` (azul, en el stack) apuntando al primer nodo; el último nodo con `siguiente → nullptr` (símbolo de tierra o "X" y la etiqueta *nullptr = fin de la lista*).

**Recorrido hacia adelante (Inicio -> Fin)**
```cpp
Nodo *actual = inicio;

while (actual != nullptr)
{
    std::cout << "Nombre: " << actual->contacto.nombre << "\n";
    actual = actual->siguiente;
}
```

### 3.2 Lista doblemente enlazada

Cada nodo tiene **dos punteros**: `siguiente` y `anterior`. Permite recorrer en ambos sentidos. El `anterior` del primer nodo y el `siguiente` del último apuntan a `nullptr`, y esos son los extremos de la lista.

**🖼️ IMAGEN 3: Diagrama de nodos, lista doble**

 - **Tipo:** diagrama horizontal de 3 o 4 nodos, cada uno dividido en tres partes (`anterior` | `dato` | `siguiente`).
 - **Contenido:** flechas dobles (o dos flechas de colores distintos: una verde hacia adelante y una azul hacia atrás) entre nodos consecutivos.
 - **Etiquetas:** `nullptr` a la izquierda del primer nodo y a la derecha del último; `cabeza` apuntando al primer nodo.

**Recorrido hacia adelante (Inicio -> Fin):**
```cpp
Nodo *actual = inicio; 
while (actual != nullptr) // Se detiene al salir del ultimo nodo
{
    std::cout << "Titulo: " << actual->cancion.titulo << "\n";
    actual = actual->siguiente; // Avanza usando el puntero 'siguiente'
}
```
**Recorrido inverso (Fin -> Inicio):**
```cpp
Nodo *actual = fin;
while (actual != nullptr) // Se detiene al salir del primer nodo
{
    std::cout << "Titulo: " << actual->cancion.titulo << "\n";
    actual = actual->anterior; // Retrocede usando el puntero 'anterior'
}
```

### 3.3 Lista circular simplemente enlazada

Igual que la simple, pero el último nodo **apunta de vuelta al primero**. No existe `nullptr` al final, por lo que se puede recorrer de forma continua. Se detiene el recorrido al volver a la cabeza.

**🖼️ IMAGEN 4: Diagrama de nodos, circular simple**

- **Tipo:** diagrama de nodos con forma de anillo (o rectangular con flecha de retorno curva).
- **Contenido:** 3 o 4 nodos (`dato` | `siguiente`) con flechas hacia adelante; una flecha curva destacada (verde o roja) del último nodo de vuelta al primero.
- **Etiquetas:** `cabeza` apuntando al primer nodo; rótulo *"el último nodo apunta a la cabeza"* junto a la flecha de retorno.

**Conexión del último nodo con el primero**
```cpp
ultimo->siguiente = inicio;
```
**Recorrido circular (Inicio -> ... -> Inicio):**
```cpp
Nodo *actual = inicio;

do
{
    std::cout << "Nombre: " << actual->contacto.nombre << "\n";
    actual = actual->siguiente;
} while (actual != inicio);
```

### 3.4 Lista circular doblemente enlazada

Cada nodo tiene `siguiente` y `anterior`, y además los extremos se conectan: el último apunta al primero y el primero al último. Permite recorrido continuo **en ambos sentidos**.

**🖼️ IMAGEN 5: Diagrama de nodos, circular doble**

- **Tipo:** anillo de nodos con `anterior` | `dato` | `siguiente`.
- **Contenido:** flechas dobles entre nodos consecutivos y dos flechas curvas de cierre: `último.siguiente → primero` y `primero.anterior → último`.
- **Etiquetas:** `cabeza` en el primer nodo; resaltar las dos flechas de cierre con un color distinto.

**Conexión circular de los extremos:**
```cpp
fin->siguiente = inicio;
inicio->anterior = fin;
```
**Recorrido hacia adelante (Inicio -> ... -> Inicio):**
```cpp
Nodo *actual = inicio;

do
{
    std::cout << "Nombre: " << actual->contacto.nombre << "\n";
    actual = actual->siguiente;
} while (actual != inicio);
```
**Recorrido inverso (Fin -> ... ->  Fin)**
```cpp
Nodo *actual = fin;

do
{
    std::cout << "Nombre: " << actual->contacto.nombre << "\n";
    actual = actual->anterior;
} while (actual != fin);
```
## 4. Ejemplos de programas que utilizan listas

| Tipo de lista | Ejemplo de aplicación | Motivo para utilizarla |
| --- | --- | --- |
| Simplemente enlazada | Historial de tareas pendientes | Se recorre principalmente hacia adelante y se inserta con poco costo. |
| Doblemente enlazada | Navegador web o reproductor multimedia | Permite avanzar y retroceder entre páginas, canciones o registros. |
| Circular simplemente enlazada | Turnos de atención o planificación Round Robin | Al llegar al último elemento se vuelve al primero. |
| Circular doblemente enlazada | Editor de diapositivas o carrusel de imágenes | Permite recorrer cíclicamente en ambos sentidos. |
| Lista de objetos | Agenda de contactos o inventario | Cada nodo puede contener varios campos relacionados. |

## 5. Buenas prácticas de implementación

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

## Ejemplo
[Ver Ejemplo de Gestión de Playlist](https://github.com/meaguilar/PED-Clases/tree/main/EjerciciosLaboratorios/Laboratorio-2)
## 6. Anexos

- [Visualizador de listas enlazadas](https://dsa-visualizer-delta.vercel.app/visualizer/linked-list): permite observar inserciones, eliminaciones y enlaces.
- [Repositorio de ejemplos de listas (C++)](https://github.com/UCASV/RecursosExtraPED/tree/main/Listas): implementaciones de las cuatro variantes.
- [103. Programación en C++ || Listas || Concepto de Lista Enlazada](https://youtu.be/15urP2LmfqY?si=QpnrlXg95SHIsgwi) (video).
- [Listas circulares](https://conclase.net/c/edd/cap4) (lectura).

---
