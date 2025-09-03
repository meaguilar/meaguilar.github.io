#include <iostream>
#include <vector>
#include <string>

struct Persona {
    std::string name;
    int birthday = 0;
    int age = 0;
};

int CalcAge(int date) {
    return 2025-date;
}

std::vector<Persona> SolicitarDatos(int cantidadRegistros) {
    std::vector<Persona> registros;
    std::cin.ignore(); // limpiar '\n' pendiente antes del primer getline
    for (int i = 0; i < cantidadRegistros; ++i) {
        Persona temp;
        std::cout << "\n--- Registro #" << (i + 1) << " ---\n";
        std::cout << "Ingrese su nombre: ";
        std::getline(std::cin, temp.name);
        std::cout << "Ingresar año de nacimiento: ";
        std::cin >> temp.birthday;
        std::cin.ignore(); // limpia el '\n' para el siguiente getline
        temp.age = CalcAge(temp.birthday);
        registros.push_back(temp);
    }
    return registros;
}

void Mostrar(const std::vector<Persona> registros);

int main() {
    int cantidadRegistros;
    std::cout << "Cantidad de registros: ";
    if (!(std::cin >> cantidadRegistros) || cantidadRegistros <= 0) return 0;
    std::vector<Persona> db = SolicitarDatos(cantidadRegistros);
    Mostrar(db);
    return 0;
}

void Mostrar(const std::vector<Persona> registros) {
    std::cout << "\nLISTADO\n";
    for (const auto r : registros) {
        std::cout << "Nombre: " << r.name
                  << " | Año de nacimiento: " << r.birthday
                  << " | Edad: " << r.age << "\n";
    }
}
