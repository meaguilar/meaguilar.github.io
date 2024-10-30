#include <iostream>
#include <string>

#include "GrafosSinClase.hpp"


struct Person {
  std::string name;
  int age;

  bool operator==(const Person& other) const {
    return name == other.name && age == other.age;
  }
};

void printPerson(const Person& person) {
  std::cout << person.name << " (" << person.age << ")" << std::endl;
}

int main() {
  Graph<Person> graph = createGraph<Person>(false);

  Person alice{"Alice", 30};
  Person bob{"Bob", 25};
  Person charlie{"Charlie", 35};

  addEdge(graph, alice, bob);
  addEdge(graph, bob, charlie);

  if (nodeExists(graph, bob)) {
    std::cout << "Bob está en el grafo." << std::endl;
  }

  std::cout << "Recorrido DFS desde Alice:" << std::endl;
  DFS(graph, alice, printPerson);

  return 0;
}
