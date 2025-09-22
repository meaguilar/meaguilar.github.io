#include <iostream>
using namespace std;

// Depositar usando referencia
void sumarRef(int &saldo, int monto) {
    saldo += monto;
}

// Retirar usando puntero
void restarPtr(int *saldo, int monto) {
    if (*saldo >= monto) {
        *saldo -= monto;
    } else {
        cout << "Fondos insuficientes para retirar." << endl;
    }
}

// Simular operación sin modificar el saldo real
int simularOperacionValor(int saldo, int monto, char op) {
    if (op == 'a' || op == 'A') {
        return saldo + monto;
    } else if (op == 'b' || op == 'B') {
        return (saldo >= monto) ? saldo - monto : saldo; 
    } else {
        cout << "Operacion no valida." << endl;
        return saldo;
    }
}

int main() {
    int saldo = 1000; // saldo inicial
    int monto;
    char opcion;

    do {
        cout << "\n=== Cajero AhorraMas ===" << endl;
        cout << "Saldo actual: $" << saldo << endl;
        cout << "1. Depositar (referencia)" << endl;
        cout << "2. Retirar (puntero)" << endl;
        cout << "3. Simular operacion" << endl;
        cout << "4. Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case '1':
                cout << "Monto a depositar: ";
                cin >> monto;
                sumarRef(saldo, monto);
                break;
            case '2':
                cout << "Monto a retirar: ";
                cin >> monto;
                restarPtr(&saldo, monto);
                break;
            case '3':
                cout << "Monto a simular: ";
                cin >> monto;
                cout << "Operacion (A para deposito, B para retiro): ";
                char op;
                cin >> op;
                cout << "Saldo simulado: $" 
                     << simularOperacionValor(saldo, monto, op) 
                     << " (saldo real: $" << saldo << ")" << endl;
                break;
            case '4':
                cout << "Saliendo del cajero..." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
        }

    } while (opcion != '4');

    return 0;
}
