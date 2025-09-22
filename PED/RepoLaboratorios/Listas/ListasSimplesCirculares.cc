#include <iostream>

struct Nodo {
    int dato;
    Nodo* siguiente;
};

// Función para agregar un nodo al principio de la lista circular
void AgregarNodoAlPrincipio(Nodo*& cabeza, int valor) {
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->dato = valor;

    if (cabeza == nullptr) {
        nuevo_nodo->siguiente = nuevo_nodo;
        cabeza = nuevo_nodo;
    } else {
        Nodo* temp = cabeza;
        while (temp->siguiente != cabeza) {
            temp = temp->siguiente;
        }
        nuevo_nodo->siguiente = cabeza;
        temp->siguiente = nuevo_nodo;
        cabeza = nuevo_nodo;
    }
}

// Función para agregar un nodo al final de la lista circular
void AgregarNodoAlFinal(Nodo*& cabeza, int valor) {
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->dato = valor;

    if (cabeza == nullptr) {
        nuevo_nodo->siguiente = nuevo_nodo;
        cabeza = nuevo_nodo;
    } else {
        Nodo* temp = cabeza;
        while (temp->siguiente != cabeza) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevo_nodo;
        nuevo_nodo->siguiente = cabeza;
    }
}

// Función para eliminar un nodo con un valor específico de la lista circular
void EliminarNodo(Nodo*& cabeza, int valor) {
    if (cabeza == nullptr) return;

    Nodo* actual = cabeza;
    Nodo* anterior = nullptr;

    do {
        if (actual->dato == valor) {
            if (anterior == nullptr) {
                Nodo* temp = cabeza;
                while (temp->siguiente != cabeza) {
                    temp = temp->siguiente;
                }
                if (cabeza == cabeza->siguiente) {
                    delete cabeza;
                    cabeza = nullptr;
                } else {
                    temp->siguiente = cabeza->siguiente;
                    delete cabeza;
                    cabeza = temp->siguiente;
                }
            } else {
                anterior->siguiente = actual->siguiente;
                delete actual;
            }
            return;
        }
        anterior = actual;
        actual = actual->siguiente;
    } while (actual != cabeza);
}

// Función para buscar un valor en la lista circular
bool BuscarValor(Nodo* cabeza, int valor) {
    if (cabeza == nullptr) return false;

    Nodo* actual = cabeza;
    do {
        if (actual->dato == valor) {
            return true;  // Valor encontrado
        }
        actual = actual->siguiente;
    } while (actual != cabeza);

    return false;  // Valor no encontrado
}

// Función para mostrar todos los nodos de la lista circular
void MostrarLista(Nodo* cabeza) {
    if (cabeza == nullptr) {
        std::cout << "La lista está vacía" << std::endl;
        return;
    }

    Nodo* actual = cabeza;
    do {
        std::cout << actual->dato << " -> ";
        actual = actual->siguiente;
    } while (actual != cabeza);

    std::cout << "(circular)" << std::endl;
}

// Función principal para demostrar el uso de la lista circular simple
int main(int argc, char* argv[]) {
    Nodo* cabeza = nullptr;

    // Agregar nodos al principio
    AgregarNodoAlPrincipio(cabeza, 10);
    AgregarNodoAlPrincipio(cabeza, 20);
    AgregarNodoAlPrincipio(cabeza, 30);

    std::cout << "Lista después de agregar al principio: " << std::endl;
    MostrarLista(cabeza);

    // Agregar nodos al final
    AgregarNodoAlFinal(cabeza, 40);
    AgregarNodoAlFinal(cabeza, 50);

    std::cout << "Lista después de agregar al final: " << std::endl;
    MostrarLista(cabeza);

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
    MostrarLista(cabeza);

    return 0;
}
