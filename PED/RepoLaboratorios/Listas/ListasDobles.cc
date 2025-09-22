#include <iostream>

struct NodoDoble {
    int dato;            // Valor almacenado en el nodo
    NodoDoble* siguiente; // Puntero al siguiente nodo
    NodoDoble* anterior;  // Puntero al nodo anterior
};

// Funciones de la lista doblemente enlazada
void AgregarNodoAlInicio(NodoDoble*& cabeza, int valor);
void AgregarNodoAlFinal(NodoDoble*& cabeza, int valor);
void EliminarNodo(NodoDoble*& cabeza, int valor);
void MostrarListaInicioAFin(NodoDoble* cabeza);
void MostrarListaFinAInicio(NodoDoble* cabeza);
bool BuscarValor(NodoDoble* cabeza, int valor);
void LimpiarLista(NodoDoble*& cabeza);

// Función principal
int main(int argc, char* argv[]) {
    NodoDoble* cabeza = nullptr;

    // Agregar nodos al inicio
    AgregarNodoAlInicio(cabeza, 10);
    AgregarNodoAlInicio(cabeza, 20);
    AgregarNodoAlInicio(cabeza, 30);

    // Agregar nodos al final
    AgregarNodoAlFinal(cabeza, 40);
    AgregarNodoAlFinal(cabeza, 50);

    // Mostrar la lista desde el inicio hasta el final
    std::cout << "Lista de inicio a fin: " << std::endl;
    MostrarListaInicioAFin(cabeza);

    // Mostrar la lista desde el final hasta el inicio
    std::cout << "Lista de fin a inicio: " << std::endl;
    MostrarListaFinAInicio(cabeza);

    // Buscar un valor en la lista
    int valor_buscado = 20;
    std::cout << "Buscando el valor " << valor_buscado << ": " 
              << (BuscarValor(cabeza, valor_buscado) ? "Encontrado" : "No encontrado") << std::endl;

    // Eliminar un nodo de la lista
    EliminarNodo(cabeza, 30);
    std::cout << "Lista después de eliminar el nodo con valor 30: " << std::endl;
    MostrarListaInicioAFin(cabeza);

    // Limpiar toda la lista
    LimpiarLista(cabeza);
    std::cout << "Lista después de limpiarla: " << std::endl;
    MostrarListaInicioAFin(cabeza);

    return 0;
}

// Agregar un nodo al inicio de la lista
void AgregarNodoAlInicio(NodoDoble*& cabeza, int valor) {
    NodoDoble* nuevo_nodo = new NodoDoble();
    nuevo_nodo->dato = valor;
    nuevo_nodo->siguiente = cabeza;
    nuevo_nodo->anterior = nullptr;

    if (cabeza != nullptr) {
        cabeza->anterior = nuevo_nodo;
    }
    cabeza = nuevo_nodo;
}

// Agregar un nodo al final de la lista
void AgregarNodoAlFinal(NodoDoble*& cabeza, int valor) {
    NodoDoble* nuevo_nodo = new NodoDoble();
    nuevo_nodo->dato = valor;
    nuevo_nodo->siguiente = nullptr;

    if (cabeza == nullptr) {
        nuevo_nodo->anterior = nullptr;
        cabeza = nuevo_nodo;
    } else {
        NodoDoble* actual = cabeza;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo_nodo;
        nuevo_nodo->anterior = actual;
    }
}

// Eliminar un nodo con un valor específico
void EliminarNodo(NodoDoble*& cabeza, int valor) {
    NodoDoble* actual = cabeza;

    while (actual != nullptr && actual->dato != valor) {
        actual = actual->siguiente;
    }

    if (actual == nullptr) return; // Valor no encontrado

    if (actual->anterior != nullptr) {
        actual->anterior->siguiente = actual->siguiente;
    } else {
        cabeza = actual->siguiente; // Eliminar el primer nodo
    }

    if (actual->siguiente != nullptr) {
        actual->siguiente->anterior = actual->anterior;
    }

    delete actual; // Liberar la memoria del nodo eliminado
}

// Mostrar la lista desde el inicio hasta el final
void MostrarListaInicioAFin(NodoDoble* cabeza) {
    NodoDoble* actual = cabeza;
    while (actual != nullptr) {
        std::cout << actual->dato << " <-> ";
        actual = actual->siguiente;
    }
    std::cout << "nullptr" << std::endl;
}

// Mostrar la lista desde el final hasta el inicio
void MostrarListaFinAInicio(NodoDoble* cabeza) {
    if (cabeza == nullptr) return;

    NodoDoble* actual = cabeza;
    // Moverse al último nodo
    while (actual->siguiente != nullptr) {
        actual = actual->siguiente;
    }

    // Recorrer desde el último hasta el primero
    while (actual != nullptr) {
        std::cout << actual->dato << " <-> ";
        actual = actual->anterior;
    }
    std::cout << "nullptr" << std::endl;
}

// Buscar un valor en la lista
bool BuscarValor(NodoDoble* cabeza, int valor) {
    NodoDoble* actual = cabeza;
    while (actual != nullptr) {
        if (actual->dato == valor) {
            return true;  // Valor encontrado
        }
        actual = actual->siguiente;
    }
    return false;  // Valor no encontrado
}

// Limpiar toda la lista (eliminar todos los nodos)
void LimpiarLista(NodoDoble*& cabeza) {
    while (cabeza != nullptr) {
        NodoDoble* actual = cabeza;
        cabeza = cabeza->siguiente;
        delete actual;
    }
}
