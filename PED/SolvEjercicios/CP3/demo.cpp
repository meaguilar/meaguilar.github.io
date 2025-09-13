#include <iostream>
using namespace std;

// Muestra el saldo actual
void mostrarSaldo(const double* saldo) {
    cout << "Saldo actual: $" << *saldo << endl;
}

// Deposita una cantidad indicada por referencia al saldo
void depositar(double* saldo, double cantidad) {
    if (cantidad <= 0) {
        cout << "Cantidad inválida para depositar.\n";
        return;
    }
    *saldo += cantidad;
    cout << "Depositados: $" << cantidad << endl;
    mostrarSaldo(saldo);
}

// Retira una cantidad indicada por referencia al saldo, si hay fondos suficientes
void retirar(double* saldo, double cantidad) {
    if (cantidad <= 0) {
        cout << "Cantidad inválida para retirar.\n";
        return;
    }
    if (cantidad > *saldo) {
        cout << "Fondos insuficientes.\n";
        return;
    }
    *saldo -= cantidad;
    cout << "Retirados: $" << cantidad << endl;
    mostrarSaldo(saldo);
}

int main() {
    double saldo = 100.0; // Saldo inicial
    double* ptrSaldo = &saldo; // Puntero al saldo

    int opcion;
    double cantidad;

    do {
        cout << "\n=== Cajero Automático ===\n";
        cout << "1. Consultar saldo\n";
        cout << "2. Depositar\n";
        cout << "3. Retirar\n";
        cout << "4. Salir\n";
        cout << "Selecciona una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                mostrarSaldo(ptrSaldo);
                break;
            case 2:
                cout << "Ingresa monto a depositar: ";
                cin >> cantidad;
                depositar(ptrSaldo, cantidad);
                break;
            case 3:
                cout << "Ingresa monto a retirar: ";
                cin >> cantidad;
                retirar(ptrSaldo, cantidad);
                break;
            case 4:
                cout << "Gracias por usar el cajero. ¡Adiós!\n";
                break;
            default:
                cout << "Opción inválida. Intenta de nuevo.\n";
        }
    } while (opcion != 4);

    return 0;
}
