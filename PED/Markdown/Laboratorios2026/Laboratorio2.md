# Estructuras de datos dinámicas lineales: Listas 

## 1. Estructuras de datos lineales y listas enlazadas

Una **estructura de datos lineal** organiza sus elementos en una secuencia: cada elemento tiene un predecesor y un sucesor, excepto los de los extremos. Los arreglos, las pilas, las colas y las listas son ejemplos.


![estructura](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/refs/heads/main/PED/Imagenes/CP2/A.png)

## 2. ¿Qué es una lista dinámica?

Una **lista dinámica** es una estructura de datos lineal cuyo tamaño puede crecer o reducirse en tiempo de ejecución. A diferencia de los arreglos (listas estáticas), **no necesita un tamaño fijo**.

**Características**

- **Uso de punteros:** cada nodo guarda punteros que lo enlazan con otros nodos.
- **Memoria dinámica:** se reserva y libera durante l   a ejecución con `new` y `delete`.
- **Inserción y eliminación eficientes:** solo se ajustan punteros, sin mover el resto de elementos.

![lista](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/refs/heads/main/PED/Imagenes/CP2/listaenlazada.png)

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

### 3.1 Lista simplemente enla  zada

Cada nodo apunta solo al **siguiente**. El último nodo apunta a `nullptr`, lo que marca el final. Solo se recorre hacia adelante. Es la más fácil de implementar.
![listasimple](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/refs/heads/main/PED/Imagenes/CP2/lista.png)

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

![listadoble](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/refs/heads/main/PED/Imagenes/CP2/listadoble.png)

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

![listacircular](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/refs/heads/main/PED/Imagenes/CP2/circular.jpeg)

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

![listacirculardoble](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/refs/heads/main/PED/Imagenes/CP2/circulardoble.jpeg)


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

| Tipo de lista | Ejemplo de aplicación |
| --- | --- |
| Simplemente enlazada | Historial de tareas pendientes |
| Doblemente enlazada | Navegador web o reproductor multimedia |
| Circular simplemente enlazada | Turnos de atención o planificación Round Robin |
| Circular doblemente enlazada | Editor de diapositivas o carrusel de imágenes |

## 5. Buenas prácticas de implementación

- **Separa responsabilidades:** usa funciones independientes para insertar, buscar, recorrer, eliminar y destruir.
- **Mantén los enlaces consistentes:** inicializa los punteros en `nullptr`, actualiza `anterior` y `siguiente` en el orden correcto y conserva las invariantes de la lista.
- **Gestiona la memoria con claridad:** define la propiedad de cada nodo, empareja cada `new` con su `delete` y considera `std::unique_ptr` cuando sea adecuado.
- **Controla los casos límite:** verifica punteros antes de usarlos y prueba listas vacías, de un solo nodo y circulares.
- **Escribe código eficiente:** usa `const` en funciones de solo lectura y evita copias innecesarias.

## Ejemplo
[Ver Ejemplo de Gestión de Playlist](https://github.com/meaguilar/PED-Clases/tree/main/EjerciciosLaboratorios/Laboratorio-2)
## 6. Anexos

- [Visualizador de listas enlazadas](https://dsa-visualizer-delta.vercel.app/visualizer/linked-list): permite observar inserciones, eliminaciones y enlaces.
- [Repositorio de ejemplos de listas (C++)](https://github.com/UCASV/RecursosExtraPED/tree/main/Listas): implementaciones de las cuatro variantes.
- [103. Programación en C++ || Listas || Concepto de Lista Enlazada](https://youtu.be/15urP2LmfqY?si=QpnrlXg95SHIsgwi) (video).
- [Listas circulares](https://conclase.net/c/edd/cap4) (lectura).

---
