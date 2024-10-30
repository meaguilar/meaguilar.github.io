#ifndef GRAPHLIB_HPP
#define GRAPHLIB_HPP

#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <stack>

/* Plantilla */
template <typename NodeType>

class Graph {
 public:
  Graph(bool isDirected = false) : isDirected(isDirected) {}

  bool add(const NodeType& src, const NodeType& dest) {
    if (src == dest) {
      std::cerr
          << "[Error]: No se puede agregar una arista de un nodo a sí mismo."
          << std::endl;
      return false;
    }
    if (!isDirected &&
        adjList[dest].end() !=
            std::find(adjList[dest].begin(), adjList[dest].end(), src)) {
      std::cerr << "[Error]: La arista ya existe." << std::endl;
      return false;
    }
    adjList[src].push_back(dest);
    if (!isDirected) {
      adjList[dest].push_back(src);
    }
    return true;
  }

  bool remove(const NodeType& src, const NodeType& dest) {
    if (!nodeExists(src) || !nodeExists(dest)) {
      std::cerr << "[Error]: Uno o ambos nodos no existen." << std::endl;
      return false;
    }

    adjList[src].remove(dest);
    if (!isDirected) {
      adjList[dest].remove(src);
    }
    return true;
  }

  bool find(const NodeType& node) const {
    return adjList.find(node) != adjList.end();
  }

  bool DFS(const NodeType& start) const {
    if (!find(start)) {
      std::cerr << "[Error]: El nodo de inicio no existe en el grafo."
                << std::endl;
      return false;
    }
    std::map<NodeType, bool> visited;
    DFSUtil(start, visited);
    std::cout << std::endl;
    return true;
  }

 private:
  std::map<NodeType, std::list<NodeType>> adjList;
  bool isDirected;

  void DFSUtil(const NodeType& node, std::map<NodeType, bool>& visited) const {
    visited[node] = true;
    std::cout << node << " ";
    for (const NodeType& neighbor : adjList.at(node)) {
      if (!visited[neighbor]) {
        DFSUtil(neighbor, visited);
      }
    }
  }

  bool nodeExists(const NodeType& node) const {
    return adjList.find(node) != adjList.end();
  }
};

#endif  // GRAPHLIB_HPP
