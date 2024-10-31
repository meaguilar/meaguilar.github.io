# Estructuras de datos dinámicas no lineales grafos

En este laboratorio estudiaremos los **grafos**, una estructura de datos fundamental en la representación de relaciones entre diferentes elementos, utilizada en áreas como redes, optimización, inteligencia artificial, entre otros.

## ¿Qué es un Grafo?

![graph-in-cpp](https://media.geeksforgeeks.org/wp-content/uploads/20240613161501/graph-in-cpp.webp)

Un **grafo** es una estructura de datos que consta de un conjunto de nodos o **vertices** y un conjunto de conexiones llamadas **aristas** que unen ciertos pares de vértices. A diferencia de los árboles, los grafos no tienen una jerarquía específica, lo que permite modelar relaciones más complejas entre los elementos.

Los grafos pueden ser **dirigidos** o **no dirigidos**:

-   En un **grafo dirigido**, las aristas tienen una dirección, lo que significa que la relación entre dos vértices es asimétrica.
-   En un **grafo no dirigido**, las aristas no tienen dirección, lo que implica que la relación es simétrica entre los vértices.

## Características importantes de los grafos

-   **Vértices**: Los puntos en los que se conectan las aristas (también llamados nodos).
-   **Aristas**: Las conexiones entre los vértices.
-   **Grado de un vértice**: El número de aristas conectadas a un vértice.
-   **Camino**: Una secuencia de vértices conectados por aristas.
-   **Ciclo**: Un camino que comienza y termina en el mismo vértice.

## Tipos de grafos
![Types of Graph in Data Structures](https://cdn-images-1.medium.com/max/800/1*dX9TdlR6wD5lkPnWG1h80g.png)

1.  **Grafo Simple**: No tiene bucles ni aristas múltiples (más de una arista entre dos vértices).
2.  **Grafo Dirigido**: Las aristas tienen una dirección (van de un vértice a otro).
3.  **Grafo No Dirigido**: Las aristas no tienen dirección.
4.  **Grafo Conexo**: Existe un camino entre cada par de vértices.
5.  **Grafo Disconexo**: No hay caminos entre algunos vértices.
6.  **Grafo Ponderado**: Las aristas tienen un peso asociado (por ejemplo, costo o distancia).

En este laboratorio nos centraremos en estudiar **grafos dirigidos** y **no dirigidos**.

## Libreria para grafos C++

En este laboratorio usaremos una librería personalizada que permite la creación de grafos dirigidos y no dirigidos, además de realizar operaciones básicas como agregar o eliminar aristas, buscar vértices, y recorrer el grafo.

### Definición de la estructura
Para crear un grafo donde los nodos representen personas, usaremos una estructura `Person` con las propiedades `name` y `age`. Es importante sobrecargar el operador `<` para poder ordenar las personas dentro del grafo:

```c++
struct Person {
  std::string name;
  int age;

  bool operator<(const Person& other) const {
    return name < other.name || (name == other.name && age < other.age);
  }

  bool operator==(const Person& other) const {
    return name == other.name && age == other.age;
  }
};
```
**Operador `==`**: Este operador determina si dos instancias de `Person` son iguales. Si solo el operador `<` estuviera sobrecargado, podríamos ordenar, pero no comparar si dos personas son idénticas

**Operador `<`**: Este operador es necesario para ordenar los nodos en el grafo. Sobrecargar el operador `<` le indica a la estructura cómo comparar dos instancias de `Person` y establecer un orden.

### Creación de un grafo
Luego para definir un grafo, lo haremos de la siguiente manera
```c++
  Graph<Person>  graph;
```
Aquí, `<Person>` indica el tipo de dato que utilizará el grafo, que en este caso es una estructura personalizada, y `graph` es el nombre de nuestra instancia de grafo.

Luego crearemos algunos nodos para nuestro grafo.
```c++
	Person  alice{"Alice",  30};
	Person  bob{"Bob",  25};
	Person  charlie{"Charlie",  35};
```

<p align="center">
  <img src="https://lh7-rt.googleusercontent.com/docsz/AD_4nXeQpnXN_pAI7eNOE8F8hOpHrao7QDRZ7IAJM0xZ8D3txK4IXtkxtDSSbGcocKayuCPSi-Bnu2omBl28hiJEJ9xTgYVNBwI0ansI1YF3xBDiyUyrGH6AS-9uA1_3grPSFTBIqL9TjSqPUlmwe05mYheh1so?key=sVYRByLC0DqYQgEyqSRqUepB" width="400">
</p>


## Operaciones básicas con grafos
La librería  permite realizar varias operaciones clave. A continuación se muestran los ejemplos más importantes.

### Agregar aristas
Una vez que los nodos están creados, procedemos a **agregarlos** al grafo. Para conectar dos nodos, utilizamos la función `add`. El grafo que genera es dirigido, es decir que la conexión se establece desde el nodo de origen hacia el nodo de destino.

```c++
graph.add(alice,  bob);
graph.add(alice,  charlie);
```
<p align="center">
  <img src="https://lh7-rt.googleusercontent.com/docsz/AD_4nXcgGn8f2D3EZdB80vjAnjQp40tGPj2lEjpiOp_re1EBkko_OY5SB5E8spEpCnnf9GRZWDFa09bmp4Xi3uTks85ctpeDeJ3ph5P_vlJbWdQsXNMZDN7qdfrCEaqsKUW_oiX6JunLyUTdgJPGWv0K9yumXqVI?key=sVYRByLC0DqYQgEyqSRqUepB" width="400">
</p>

### Eliminar aristas
Para **eliminar una conexión** entre dos nodos en el grafo, utilizamos la función `remove`

```c++
graph.remove(alice, bob);
```

### Buscar un Nodo
Para **verificar si un nodo existe** en el grafo, empleamos la función `find`. Esta función devolverá `true` si el nodo está presente en el grafo y `false` en caso contrario.

```c++
if (graph.find(bob)) {
    std::cout << "Bob está en el grafo." << std::endl;
}
```

### Recorrido en Profundidad (DFS)
Para **recorrer el grafo en profundidad** desde un nodo de inicio, utilizamos la función `DFS`. Esta función explora todos los nodos alcanzables desde el nodo inicial y aplica una acción en cada uno, que en este caso es definida por la función `imprimirPersona`.

```c++
void imprimirPersona(const Person& person) {
    std::cout << person.name << " (" << person.age << ")" << std::endl;
}

graph.DFS(alice, imprimirPersona);
```

Aquí, `DFS` comienza en el nodo `alice` y, para cada nodo visitado, llama a la función `imprimirPersona`, que imprime el nombre y la edad de cada persona encontrada en el recorrido.


El método `DFS` nos permite personalizar la acción que queremos ejecutar en cada nodo durante el recorrido. Al pasar una función como argumento, podemos definir exactamente qué queremos hacer con cada nodo, permitiéndonos adaptarlo a diversas necesidades según el contexto del grafo.

Por ejemplo, además de imprimir los datos de cada persona, podríamos crear una función personalizada para:

#### **Contar el número de nodos visitados.**
```c++
int contador = 0;

void contarNodo(const Person& person) {
    contador++;
}

graph.DFS(alice, contarNodo);
std::cout << "Número total de nodos visitados: " << contador << std::endl;
```
#### Encontrar a la persona de mayor edad
```c++
Person personaMayorEdad{"", -1}; // Inicializamos con una edad claramente menor

void encontrarMayorEdad(const Person& person) {
    if (person.age > personaMayorEdad.age) {
        personaMayorEdad = person;
    }
}

graph.DFS(alice, encontrarMayorEdad);
std::cout << "Persona de mayor edad: " << personaMayorEdad.name << " (" << personaMayorEdad.age << " años)" << std::endl;
``` 

# Anexos

[Articulo sobre grafos](https://www.freecodecamp.org/espanol/news/explicacion-de-algoritmos-y-estructuras-de-datos-de-grafos-con-ejemplos-en-java-y-c/) para entender como funcionan y como se implementan desde cero en C++ y Java.

