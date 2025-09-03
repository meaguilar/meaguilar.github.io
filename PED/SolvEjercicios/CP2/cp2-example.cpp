#include <iostream>
#include <vector>
#include <string>

struct Item {
    std::string campo1;
    std::string campo2;
    int cantidad = 0;
    double precioUnitario = 0.0;
    double total = 0.0;
};

double calcularTotal(int cantidad, double precioUnitario) {
    return cantidad * precioUnitario;
}

std::vector<Item> SolicitarDatos(int cantidadRegistros) {
    std::vector<Item> registros;
    std::cin.ignore(); // limpiar '\n' pendiente antes del primer getline
    for (int i = 0; i < cantidadRegistros; ++i) {
        Item temp;
        std::cout << "\n--- Registro #" << (i + 1) << " ---\n";
        std::cout << "Campo 1: ";
        std::getline(std::cin, temp.campo1);
        std::cout << "Campo 2: ";
        std::getline(std::cin, temp.campo2);
        std::cout << "Cantidad: ";
        std::cin >> temp.cantidad;
        std::cout << "Precio unitario: ";
        std::cin >> temp.precioUnitario;
        std::cin.ignore(); // limpia el '\n' para el siguiente getline
        temp.total = calcularTotal(temp.cantidad, temp.precioUnitario);
        registros.push_back(temp);
    }
    return registros;
}

void Mostrar(const std::vector<Item> registros) {
    std::cout << "\nLISTADO\n";
    for (const auto r : registros) {
        std::cout << "Campo 1: " << r.campo1
                  << " | Campo 2: " << r.campo2
                  << " | Cantidad: " << r.cantidad
                  << " | Precio unitario: $" << r.precioUnitario
                  << " | Total: $" << r.total << "\n";
    }
}

int main() {
    int cantidadRegistros;
    std::cout << "Cantidad de registros: ";
    if (!(std::cin >> cantidadRegistros) || cantidadRegistros <= 0) return 0;

    std::vector<Item> items = SolicitarDatos(cantidadRegistros);
    Mostrar(items);
    return 0;
}
