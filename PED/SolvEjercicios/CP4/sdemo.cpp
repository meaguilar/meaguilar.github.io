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
    int dia;                // (usuario) 1..30
    int mes;                // (usuario) 1..12
    string fechaDevolucion; // (calculado: texto simple)
};

// Función para calcular fecha de devolución (texto)
string CalcularFechaDevolucion(int dia, int mes)
{
    // Simplificado: todos los meses = 30 días
    dia += 15; // préstamo fijo por 15 días
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
    Prestamo dato;
    NodoDoble *siguiente;
    NodoDoble *anterior;
};

// Prototipos base (tuyos)
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

// Prototipos extras (menú, modificar/eliminar último)
void Menu(NodoDoble *&cabeza);
bool ModificarUltimoNodo(NodoDoble *cabeza);
bool EliminarUltimoNodo(NodoDoble *&cabeza);

// Helpers de entrada y utilidades
void Pausa();
void PedirPrestamoInteractivo(string &titulo, string &autor, int &dia, int &mes);
NodoDoble* ObtenerUltimo(NodoDoble* cabeza);

// ==================
//   Programa ejemplo
// ==================

int main()
{
    NodoDoble *cabeza = nullptr;

    // ---- Datos quemados (base de datos inicial) ----
    AgregarPrestamoAlInicio(cabeza, "El Sennor de los Anillos", "J.R.R. Tolkien", 29, 10);
    AgregarPrestamoAlInicio(cabeza, "Cien Annos de Soledad", "G. Garcia Marquez", 10, 9);
    AgregarPrestamoAlInicio(cabeza, "1984", "George Orwell", 5, 12);

    AgregarPrestamoAlFinal(cabeza, "Ficciones", "J. L. Borges", 3, 1);
    AgregarPrestamoAlFinal(cabeza, "La Sombra del Viento", "Carlos Ruiz Zafon", 8, 3);
    // ------------------------------------------------

    // Iniciar menú
    Menu(cabeza);

    // Al salir, limpiar memoria
    LimpiarLista(cabeza);
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
             << " | Dia: " << d.dia
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
             << " | Dia: " << d.dia
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

// ===============================
//   Extras: menú y utilidades
// ===============================

void Menu(NodoDoble *&cabeza)
{
    int opcion = -1;
    do
    {
        cout << "\n========== MENU BIBLIOTECA ==========\n";
        cout << "1) Agregar prestamo al INICIO\n";
        cout << "2) Agregar prestamo al FINAL\n";
        cout << "3) Mostrar lista (inicio -> fin)\n";
        cout << "4) Mostrar lista (fin -> inicio)\n";
        cout << "5) Buscar por titulo\n";
        cout << "6) Eliminar por titulo\n";
        cout << "7) Modificar ULTIMO nodo ingresado\n";
        cout << "8) Eliminar ULTIMO nodo ingresado\n";
        cout << "9) Limpiar lista\n";
        cout << "0) Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (!cin)
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Entrada invalida.\n";
            continue;
        }

        cin.ignore(10000, '\n'); // limpiar fin de linea

        if (opcion == 1)
        {
            string t, a; int d, m;
            PedirPrestamoInteractivo(t, a, d, m);
            AgregarPrestamoAlInicio(cabeza, t, a, d, m);
            cout << "Prestamo agregado al INICIO.\n";
            Pausa();
        }
        else if (opcion == 2)
        {
            string t, a; int d, m;
            PedirPrestamoInteractivo(t, a, d, m);
            AgregarPrestamoAlFinal(cabeza, t, a, d, m);
            cout << "Prestamo agregado al FINAL.\n";
            Pausa();
        }
        else if (opcion == 3)
        {
            MostrarListaInicioAFin(cabeza);
            Pausa();
        }
        else if (opcion == 4)
        {
            MostrarListaFinAInicio(cabeza);
            Pausa();
        }
        else if (opcion == 5)
        {
            string titulo;
            cout << "Ingrese el titulo a buscar: ";
            getline(cin, titulo);
            bool ok = BuscarPorTitulo(cabeza, titulo);
            cout << (ok ? "Encontrado.\n" : "No encontrado.\n");
            Pausa();
        }
        else if (opcion == 6)
        {
            string titulo;
            cout << "Ingrese el titulo a eliminar: ";
            getline(cin, titulo);
            bool ok = EliminarPrestamoPorTitulo(cabeza, titulo);
            cout << (ok ? "Eliminado.\n" : "No se encontro el titulo.\n");
            Pausa();
        }
        else if (opcion == 7)
        {
            bool ok = ModificarUltimoNodo(cabeza);
            cout << (ok ? "Ultimo nodo modificado.\n" : "No hay nodos para modificar.\n");
            Pausa();
        }
        else if (opcion == 8)
        {
            bool ok = EliminarUltimoNodo(cabeza);
            cout << (ok ? "Ultimo nodo eliminado.\n" : "No hay nodos para eliminar.\n");
            Pausa();
        }
        else if (opcion == 9)
        {
            LimpiarLista(cabeza);
            cout << "Lista limpiada.\n";
            Pausa();
        }
        else if (opcion == 0)
        {
            cout << "Saliendo...\n";
        }
        else
        {
            cout << "Opcion no valida.\n";
            Pausa();
        }
    } while (opcion != 0);
}

bool ModificarUltimoNodo(NodoDoble *cabeza)
{
    NodoDoble* ultimo = ObtenerUltimo(cabeza);
    if (!ultimo) return false;

    cout << "Modificando ULTIMO nodo...\n";
    cout << "Actual: [Titulo: " << ultimo->dato.titulo
         << " | Autor: " << ultimo->dato.autor
         << " | Dia: " << ultimo->dato.dia
         << " | Mes: " << ultimo->dato.mes
         << " | Devolucion: " << ultimo->dato.fechaDevolucion << "]\n";

    string t, a; int d, m;
    PedirPrestamoInteractivo(t, a, d, m);

    ultimo->dato.titulo = t;
    ultimo->dato.autor = a;
    ultimo->dato.dia = d;
    ultimo->dato.mes = m;
    ultimo->dato.fechaDevolucion = CalcularFechaDevolucion(d, m);
    return true;
}

bool EliminarUltimoNodo(NodoDoble *&cabeza)
{
    if (!cabeza) return false;
    if (!cabeza->siguiente)
    {
        delete cabeza;
        cabeza = nullptr;
        return true;
    }
    NodoDoble* ult = cabeza;
    while (ult->siguiente) ult = ult->siguiente;
    NodoDoble* prev = ult->anterior;
    prev->siguiente = nullptr;
    delete ult;
    return true;
}

NodoDoble* ObtenerUltimo(NodoDoble* cabeza)
{
    if (!cabeza) return nullptr;
    NodoDoble* p = cabeza;
    while (p->siguiente) p = p->siguiente;
    return p;
}

void PedirPrestamoInteractivo(string &titulo, string &autor, int &dia, int &mes)
{
    cout << "Titulo: ";
    getline(cin, titulo);
    cout << "Autor: ";
    getline(cin, autor);

    cout << "Dia (1-30): ";
    cin >> dia;
    cout << "Mes (1-12): ";
    cin >> mes;
    cin.ignore(10000, '\n'); // limpiar fin de linea

    if (dia < 1) dia = 1;
    if (dia > 30) dia = 30;
    if (mes < 1) mes = 1;
    if (mes > 12) mes = 12;
}

void Pausa()
{
    cout << "Presione ENTER para continuar...";
    cin.ignore(10000, '\n');
}
