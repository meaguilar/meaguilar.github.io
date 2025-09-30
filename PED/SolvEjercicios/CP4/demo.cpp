#include <iostream>
#include <string>
using namespace std;

// =======================
//   Modelo del ejercicio
// =======================

struct Prestamo
{
    string titulo;          // (usuario)
    string autor;           // (usuario)
    int dia;       // (usuario)
    int mes;       // (usuario)
    string fechaDevolucion; // (calculado: texto simple)
};

// Función para calcular fecha de devolución (texto)
string CalcularFechaDevolucion(int dia, int mes)
{
    // Simplificado: no considera años bisiestos ni meses con diferente número de días
    dia += 15; // Supongamos que el préstamo es por 15 días
    if (dia > 30)
    {
        dia -= 30;
        mes += 1;
        if (mes > 12)
        {
            mes = 1; // Reiniciar al mes 1 si pasa de 12
        }
    }
    return to_string(dia) + "/" + to_string(mes);
}

// ================================
//   Lista doblemente enlazada base
// ================================

struct NodoDoble
{
    Prestamo dato;        // Cambiamos int -> Prestamo
    NodoDoble *siguiente; // Puntero al siguiente
    NodoDoble *anterior;  // Puntero al anterior
};

// Prototipos
void AgregarPrestamoAlInicio(NodoDoble *&cabeza,
                             const string &titulo,
                             const string &autor,
                             int dia, int mes);

void AgregarPrestamoAlFinal(NodoDoble *&cabeza,
                            const string &titulo,
                            const string &autor,
                            int dia, int mes);

bool EliminarPrestamoPorTitulo(NodoDoble *&cabeza, const string &titulo);
void MostrarListaInicioAFin(NodoDoble *cabeza);
void MostrarListaFinAInicio(NodoDoble *cabeza);
bool BuscarPorTitulo(NodoDoble *cabeza, const string &titulo);
void LimpiarLista(NodoDoble *&cabeza);

// ==================
//   Programa ejemplo
// ==================

int main()
{
    NodoDoble *cabeza = nullptr;

    // Agregamos préstamos al inicio
    AgregarPrestamoAlInicio(cabeza, "El Senor de los Anillos", "J.R.R. Tolkien", 29, 10 );
    AgregarPrestamoAlInicio(cabeza, "Cien Anos de Soledad", "G. Garcia Marquez", 10, 9);
    AgregarPrestamoAlInicio(cabeza, "1984", "George Orwell", 5, 12);

    // Agregamos préstamos al final
    AgregarPrestamoAlFinal(cabeza, "Ficciones", "J. L. Borges", 3, 1);
    AgregarPrestamoAlFinal(cabeza, "La Sombra del Viento", "Carlos Ruiz Zafon", 8, 3);

    cout << "\n=== Lista de inicio a fin ===\n";
    MostrarListaInicioAFin(cabeza);

    cout << "\n=== Lista de fin a inicio ===\n";
    MostrarListaFinAInicio(cabeza);

    // Buscar un título
    string buscado = "1984";
    cout << "\nBuscando \"" << buscado << "\": "
         << (BuscarPorTitulo(cabeza, buscado) ? "Encontrado" : "No encontrado")
         << "\n";

    // Eliminar un préstamo por título
    cout << "\nEliminando \"Cien Anos de Soledad\"...\n";
    EliminarPrestamoPorTitulo(cabeza, "Cien Anos de Soledad");

    cout << "\n=== Lista tras eliminar ===\n";
    MostrarListaInicioAFin(cabeza);

    // Limpiar toda la lista
    LimpiarLista(cabeza);
    cout << "\n=== Lista despues de limpiar ===\n";
    MostrarListaInicioAFin(cabeza);

    return 0;
}

// ===============================
//   Implementación de operaciones
// ===============================

void AgregarPrestamoAlInicio(NodoDoble *&cabeza,
                             const string &titulo,
                             const string &autor,
                             int dia, int mes)
{
    Prestamo p;
    p.titulo = titulo;
    p.autor = autor;
    p.dia = dia;
    p.mes = mes;
    p.fechaDevolucion = CalcularFechaDevolucion(dia, mes);

    NodoDoble *nuevo = new NodoDoble{p, cabeza, nullptr};

    if (cabeza != nullptr)
    {
        cabeza->anterior = nuevo;
    }
    cabeza = nuevo;
}

void AgregarPrestamoAlFinal(NodoDoble *&cabeza,
                            const string &titulo,
                            const string &autor,
                            int dia, int mes)
{
    Prestamo p;
    p.titulo = titulo;
    p.autor = autor;
    p.dia = dia;
    p.mes = mes;
    p.fechaDevolucion = CalcularFechaDevolucion(dia, mes);

    NodoDoble *nuevo = new NodoDoble{p, nullptr, nullptr};

    if (cabeza == nullptr)
    {
        cabeza = nuevo;
        return;
    }

    NodoDoble *actual = cabeza;
    while (actual->siguiente != nullptr)
    {
        actual = actual->siguiente;
    }
    actual->siguiente = nuevo;
    nuevo->anterior = actual;
}

bool EliminarPrestamoPorTitulo(NodoDoble *&cabeza, const string &titulo)
{
    NodoDoble *actual = cabeza;
    while (actual != nullptr && actual->dato.titulo != titulo)
    {
        actual = actual->siguiente;
    }
    if (actual == nullptr)
        return false; // no encontrado

    if (actual->anterior != nullptr)
    {
        actual->anterior->siguiente = actual->siguiente;
    }
    else
    {
        cabeza = actual->siguiente; // era el primero
    }

    if (actual->siguiente != nullptr)
    {
        actual->siguiente->anterior = actual->anterior;
    }

    delete actual;
    return true;
}

void MostrarListaInicioAFin(NodoDoble *cabeza)
{
    NodoDoble *actual = cabeza;
    if (!actual)
    {
        cout << "(vacia)\n";
        return;
    }
    while (actual != nullptr)
    {
        Prestamo d = actual->dato;
        cout << "[Titulo: " << d.titulo
             << " | Autor: " << d.autor
             << " | Dias: " << d.dia
             << " | Mes: " << d.mes
             << " | Devolucion: " << d.fechaDevolucion << "] <-> \n";
        actual = actual->siguiente;
    }
    cout << "nullptr\n";
}

void MostrarListaFinAInicio(NodoDoble *cabeza)
{
    if (cabeza == nullptr)
    {
        cout << "(vacia)\n";
        return;
    }
    // Ir al último
    NodoDoble *actual = cabeza;
    while (actual->siguiente != nullptr)
    {
        actual = actual->siguiente;
    }
    // Recorrer hacia atrás
    while (actual != nullptr)
    {
        Prestamo d = actual->dato;
        cout << "[Titulo: " << d.titulo
             << " | Autor: " << d.autor
             << " | Dias: " << d.dia
             << " | Mes: " << d.mes
             << " | Devolucion: " << d.fechaDevolucion << "] <-> \n";
        actual = actual->anterior;
    }
    cout << "nullptr\n";
}

bool BuscarPorTitulo(NodoDoble *cabeza, const string &titulo)
{
    for (NodoDoble *p = cabeza; p != nullptr; p = p->siguiente)
    {
        if (p->dato.titulo == titulo)
            return true;
    }
    return false;
}

void LimpiarLista(NodoDoble *&cabeza)
{
    while (cabeza != nullptr)
    {
        NodoDoble *actual = cabeza;
        cabeza = cabeza->siguiente;
        delete actual;
    }
}
