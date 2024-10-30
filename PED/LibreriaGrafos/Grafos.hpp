#ifndef GRAPHLIB_HPP
#define GRAPHLIB_HPP

#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <stack>

template <typename NodeType>
class Graph {
 public:
  Graph(bool isDirected = false) : isDirected(isDirected) {}

  bool add(const NodeType& src, const NodeType& dest) {
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

  void DFS(const NodeType& start,
           std::function<void(const NodeType&)> visit) const {
    if (!find(start)) {
      std::cerr << "[Error]: El nodo de inicio no existe en el grafo."
                << std::endl;
      return;
    }
    std::map<NodeType, bool> visited;
    DFSUtil(start, visited, visit);
  }

 private:
  std::map<NodeType, std::list<NodeType>> adjList;
  bool isDirected;

  void DFSUtil(const NodeType& node, std::map<NodeType, bool>& visited,
               std::function<void(const NodeType&)> visit) const {
    visited[node] = true;
    visit(node);
    for (const NodeType& neighbor : adjList.at(node)) {
      if (!visited[neighbor]) {
        DFSUtil(neighbor, visited, visit);
      }
    }
  }

  bool nodeExists(const NodeType& node) const {
    return adjList.find(node) != adjList.end();
  }
};

#endif  // GRAPHLIB_HPP
