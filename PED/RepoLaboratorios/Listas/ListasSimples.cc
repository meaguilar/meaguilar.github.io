#include <iostream>

struct Nodo {
    int dato;        // Valor almacenado en el nodo
    Nodo* siguiente; // Puntero al siguiente nodo
};

// Funciones para la lista simplemente enlazada
void AgregarNodoAlInicio(Nodo*& cabeza, int valor);
void AgregarNodoAlFinal(Nodo*& cabeza, int valor);
void EliminarNodo(Nodo*& cabeza, int valor);
void MostrarLista(Nodo* cabeza);
bool BuscarValor(Nodo* cabeza, int valor);
void LimpiarLista(Nodo*& cabeza);

// Función principal
int main(int argc, char* argv[]) {
    Nodo* cabeza = nullptr;

    // Agregar nodos al inicio
    AgregarNodoAlInicio(cabeza, 10);
    AgregarNodoAlInicio(cabeza, 20);
    AgregarNodoAlInicio(cabeza, 30);

    // Agregar nodos al final
    AgregarNodoAlFinal(cabeza, 40);
    AgregarNodoAlFinal(cabeza, 50);

    // Mostrar la lista
    std::cout << "Lista: " << std::endl;
    MostrarLista(cabeza);

    // Buscar un valor en la lista
    int valor_buscado = 20;
    std::cout << "Buscando el valor " << valor_buscado << ": " 
              << (BuscarValor(cabeza, valor_buscado) ? "Encontrado" : "No encontrado") << std::endl;

    // Eliminar un nodo de la lista
    EliminarNodo(cabeza, 30);
    std::cout << "Lista después de eliminar el nodo con valor 30: " << std::endl;
    MostrarLista(cabeza);

    // Limpiar toda la lista
    LimpiarLista(cabeza);
    std::cout << "Lista después de limpiarla: " << std::endl;
    MostrarLista(cabeza);

    return 0;
}

// Agregar un nodo al inicio de la lista
void AgregarNodoAlInicio(Nodo*& cabeza, int valor) {
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->dato = valor;
    nuevo_nodo->siguiente = cabeza;
    cabeza = nuevo_nodo;
}

// Agregar un nodo al final de la lista
void AgregarNodoAlFinal(Nodo*& cabeza, int valor) {
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->dato = valor;
    nuevo_nodo->siguiente = nullptr;

    if (cabeza == nullptr) {
        cabeza = nuevo_nodo;
    } else {
        Nodo* actual = cabeza;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo_nodo;
    }
}

// Eliminar un nodo con un valor específico
void EliminarNodo(Nodo*& cabeza, int valor) {
    Nodo* actual = cabeza;
    Nodo* anterior = nullptr;

    while (actual != nullptr && actual->dato != valor) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == nullptr) return; // Valor no encontrado

    if (anterior == nullptr) {
        cabeza = actual->siguiente; // Eliminar el primer nodo
    } else {
        anterior->siguiente = actual->siguiente;
    }

    delete actual; // Liberar la memoria del nodo eliminado
}

// Mostrar la lista completa
void MostrarLista(Nodo* cabeza) {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        std::cout << actual->dato << " -> ";
        actual = actual->siguiente;
    }
    std::cout << "nullptr" << std::endl;
}

// Buscar un valor en la lista
bool BuscarValor(Nodo* cabeza, int valor) {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        if (actual->dato == valor) {
            return true;  // Valor encontrado
        }
        actual = actual->siguiente;
    }
    return false;  // Valor no encontrado
}

// Limpiar toda la lista (eliminar todos los nodos)
void LimpiarLista(Nodo*& cabeza) {
    while (cabeza != nullptr) {
        Nodo* actual = cabeza;
        cabeza = cabeza->siguiente;
        delete actual;
    }
}
