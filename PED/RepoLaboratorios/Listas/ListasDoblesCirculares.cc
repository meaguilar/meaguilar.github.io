#include <iostream>

struct NodoDoble {
    int dato;
    NodoDoble* siguiente;
    NodoDoble* anterior;
};

// Función para agregar un nodo al principio de la lista circular doblemente enlazada
void AgregarNodoAlPrincipio(NodoDoble*& cabeza, int valor) {
    NodoDoble* nuevo_nodo = new NodoDoble();
    nuevo_nodo->dato = valor;

    if (cabeza == nullptr) {
        nuevo_nodo->siguiente = nuevo_nodo;
        nuevo_nodo->anterior = nuevo_nodo;
        cabeza = nuevo_nodo;
    } else {
        NodoDoble* ultimo = cabeza->anterior;
        nuevo_nodo->siguiente = cabeza;
        nuevo_nodo->anterior = ultimo;
        cabeza->anterior = nuevo_nodo;
        ultimo->siguiente = nuevo_nodo;
        cabeza = nuevo_nodo;
    }
}

// Función para agregar un nodo al final de la lista circular doblemente enlazada
void AgregarNodoAlFinal(NodoDoble*& cabeza, int valor) {
    NodoDoble* nuevo_nodo = new NodoDoble();
    nuevo_nodo->dato = valor;

    if (cabeza == nullptr) {
        nuevo_nodo->siguiente = nuevo_nodo;
        nuevo_nodo->anterior = nuevo_nodo;
        cabeza = nuevo_nodo;
    } else {
        NodoDoble* ultimo = cabeza->anterior;
        nuevo_nodo->siguiente = cabeza;
        nuevo_nodo->anterior = ultimo;
        ultimo->siguiente = nuevo_nodo;
        cabeza->anterior = nuevo_nodo;
    }
}

// Función para eliminar un nodo con un valor específico de la lista circular doblemente enlazada
void EliminarNodo(NodoDoble*& cabeza, int valor) {
    if (cabeza == nullptr) return;

    NodoDoble* actual = cabeza;

    do {
        if (actual->dato == valor) {
            NodoDoble* anterior = actual->anterior;
            NodoDoble* siguiente = actual->siguiente;

            if (actual == cabeza && actual->siguiente == cabeza) {
                delete actual;
                cabeza = nullptr;
            } else {
                anterior->siguiente = siguiente;
                siguiente->anterior = anterior;
                if (actual == cabeza) {
                    cabeza = siguiente;
                }
                delete actual;
            }
            return;
        }
        actual = actual->siguiente;
    } while (actual != cabeza);
}

// Función para buscar un valor en la lista circular doblemente enlazada
bool BuscarValor(NodoDoble* cabeza, int valor) {
    if (cabeza == nullptr) return false;

    NodoDoble* actual = cabeza;
    do {
        if (actual->dato == valor) {
            return true;  // Valor encontrado
        }
        actual = actual->siguiente;
    } while (actual != cabeza);

    return false;  // Valor no encontrado
}

// Función para mostrar todos los nodos de la lista circular doblemente enlazada desde el inicio
void MostrarListaInicioAFin(NodoDoble* cabeza) {
    if (cabeza == nullptr) {
        std::cout << "La lista está vacía" << std::endl;
        return;
    }

    NodoDoble* actual = cabeza;
    do {
        std::cout << actual->dato << " <-> ";
        actual = actual->siguiente;
    } while (actual != cabeza);

    std::cout << "(circular)" << std::endl;
}

// Función para mostrar todos los nodos de la lista circular doblemente enlazada desde el final
void MostrarListaFinAInicio(NodoDoble* cabeza) {
    if (cabeza == nullptr) {
        std::cout << "La lista está vacía" << std::endl;
        return;
    }

    NodoDoble* actual = cabeza->anterior;
    do {
        std::cout << actual->dato << " <-> ";
        actual = actual->anterior;
    } while (actual != cabeza->anterior);

    std::cout << "(circular)" << std::endl;
}

// Función principal para demostrar el uso de la lista circular doblemente enlazada
int main(int argc, char* argv[]) {
    NodoDoble* cabeza = nullptr;

    // Agregar nodos al principio
    AgregarNodoAlPrincipio(cabeza, 10);
    AgregarNodoAlPrincipio(cabeza, 20);
    AgregarNodoAlPrincipio(cabeza, 30);

    std::cout << "Lista después de agregar al principio: " << std::endl;
    MostrarListaInicioAFin(cabeza);

    // Agregar nodos al final
    AgregarNodoAlFinal(cabeza, 40);
    AgregarNodoAlFinal(cabeza, 50);

    std::cout << "Lista después de agregar al final: " << std::endl;
    MostrarListaInicioAFin(cabeza);

    // Buscar un valor en la lista
    int valor_buscar = 20;
    if (BuscarValor(cabeza, valor_buscar)) {
        std::cout << "El valor " << valor_buscar << " fue encontrado en la lista." << std::endl;
    } else {
        std::cout << "El valor " << valor_buscar << " no fue encontrado en la lista." << std::endl;
    }

    // Eliminar un nodo
    EliminarNodo(cabeza, 30);
    std::cout << "Lista después de eliminar el nodo con valor 30: " << std::endl;
    MostrarListaInicioAFin(cabeza);

    return 0;
}
