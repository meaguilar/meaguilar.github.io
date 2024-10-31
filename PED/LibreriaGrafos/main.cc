#include <iostream>
#include <string>

#include "Grafos.hpp"

struct Person {
  std::string name;
  int age;

  bool operator<(const Person& other) const {
    return name < other.name || (name == other.name && age < other.age);
  }

  bool operator==(const Person& other) const {
    return name == other.name && age == other.age;
  }
};

void imprimirPersona(const Person& person) {
  std::cout << person.name << " (" << person.age << ")" << std::endl;
}

int main() {
  Graph<Person> graph;

  Person alice{"Alice", 30};
  Person bob{"Bob", 25};
  Person charlie{"Charlie", 35};

  graph.add(alice, bob);
  graph.add(alice, charlie);

  if (graph.find(bob)) {
    std::cout << "Bob está en el grafo." << std::endl;
  }

  std::cout << "Recorrido DFS desde Alice:" << std::endl;
  

  graph.DFS(alice, imprimirPersona);
  return 0;
}
