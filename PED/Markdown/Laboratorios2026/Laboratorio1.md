# Manejo de Punteros y Referencias

## Conceptos de Punteros

![Puntero](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/refs/heads/main/PED/Imagenes/CP2/CP2-A.png)

**Los dos operadores clave:**
- **`&` (referenciar):** obtiene la dirección de memoria de una variable.
- **`*` (desreferenciar):** accede al valor almacenado en la dirección a la que apunta el puntero.
```cpp 
int edad = 20; 
int  *pEdad =  &edad;  // pEdad guarda la direccion de memoria de "edad"
	
// &  obtiene la dirección de memoria de "edad" 
std::cout << "Direccion de memoria de edad: " << &edad << std::endl; 
	
// Un puntero almacena una dirección de memoria 
std::cout <<  "Dirección almacenada en pEdad: "  << pEdad << std::endl;
	
// * desreferencia el puntero: accede al valor almacenado en esa direccion 
std::cout <<  "Valor apuntado por pEdad: "  <<  *pEdad << std::endl;
	

```


![nullptr](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/refs/heads/main/PED/Imagenes/CP2/CP2-B.png)

 ## Paso por Valor vs. Referencia vs. Puntero


![Paso por valor y por referencia](https://raw.githubusercontent.com/meaguilar/meaguilar.github.io/refs/heads/main/PED/Imagenes/CP2/CP2-C.png)

- **Por valor:** la función recibe una *copia* del dato. Los cambios dentro de la función no afectan la variable original.
```cpp 
// Paso por valor 
void ConsultarCarga(int carga) 
{ 
	std::cout << "Carga actual: " << carga << " Wh" <<std::endl; 
} 
```
- **Por referencia (`&`):** la función recibe acceso directo a la variable original mediante su dirección de memoria. Los cambios sí afectan al original.
```cpp 
// Paso por referencia
void CargarBateria(int &carga, int Wh) 
{ 
	carga += Wh;
} 
```

## ¿Cuándo implementar referencia o puntero?

**Referencia (`&`):**
- Cuando siempre debe existir un valor.
- Para pasar parámetros sin copiar.
- Para modificar argumentos de una función.

**Buenas practicas:**

 - Usar `const &` cuando no se necesita modificar el valor (evita copias innecesarias en parámetros grandes: strings, vectores, objetos).
```cpp
// const & : recibe acceso directo al dato original SIN copiarlo, 
// pero el "const" impide modificarlo dentro de la funcion 
void  MostrarEstadoBateria(const  int  &carga) 
{ 
	std::cout <<  "Estado de la bateria: "  << carga <<  " Wh"  << std::endl; 
	// carga += 50; // Error: no se puede modificar, es const 
} 
```
- Usar `&` (sin const) cuando sí se quiere modificar la variable.

```cpp
// & (sin const): recibe acceso directo al dato original 
// y SI permite modificarlo, afectando la variable original 
void  CargarBateria(int  &carga,  int Wh)
{ 
	carga += Wh;
} 
```
> 💡 Preferir referencias sobre punteros cuando solo se necesite manipular el contenido de variables en funciones.

**Puntero (`*`):**
- Cuando el valor puede no existir (opcional).
- Para manejar arreglos dinámicos.
- En estructuras sencillas.
- Cuando se necesita cambiar a qué objeto se apunta.

```cpp 
// Paso por puntero 
void ConsumirEnergia(int *carga, int Wh){ 
	*carga -= Wh;
} 
```


 **Buenas practicas:** 
- Inicializar siempre los punteros. 
- Usarlos cuando se necesite: manipular variables de forma indirecta, gestionar memoria dinámica, o crear estructuras dinámicas (listas enlazadas, árboles, etc.). 
- Si se reserva memoria dinámicamente, siempre liberarla. 

 > 💡 Los punteros tienen su lugar cuando se trabaja con memoria dinámica o estructuras complejas.

## Ejemplo
[Ver Ejemplo de Granja Solar](https://github.com/meaguilar/PED-Clases/tree/main/EjerciciosLaboratorios/Laboratorio-1)

# Anexos

[Guia de Git](https://meaguilar.github.io/PED/Laboratorio0)

#### Buenas prácticas de punteros— enlaces de referencia 
- [C++ Pointers – GeeksforGeeks](https://www.geeksforgeeks.org/cpp/cpp-pointers/) — repaso de inicialización, desreferenciación y punteros colgantes. 
- [Best practices to safely navigate pointers in C/C++ – Embedded.com](https://www.embedded.com/best-practices-to-safely-navigate-pointers-in-c-c/) — prácticas recomendadas desde la perspectiva de sistemas embebidos. 
-  [Cómo evitar errores comunes con punteros en C++ – LabEx](https://labex.io/es/tutorials/cpp-how-to-avoid-common-pointer-mistakes-451086) — guía en español con prácticas y ejemplos.

#### Errores comunes con punteros — enlaces de referencia 
- [Dangling Pointers in C++ – GeeksforGeeks](https://www.geeksforgeeks.org/cpp/dangling-pointers-in-cpp/) — qué son, cómo se producen y cómo evitarlos. 
-  [Null Pointer Dereference – AWS CodeGuru Detector Library](https://docs.aws.amazon.com/codeguru/detector-library/cpp/null-pointer-dereference/) — ejemplo de desreferenciar un puntero nulo y su corrección.
- [Dangling Pointers in C++: A Comprehensive Guide – Medium](https://medium.com/@ryan_forrester_/dangling-pointers-in-c-a-comprehensive-guide-04d55b0feb51) — casos comunes, cómo depurarlos y buenas prácticas de corrección.
