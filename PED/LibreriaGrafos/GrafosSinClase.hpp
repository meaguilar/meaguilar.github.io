#ifndef GRAPHLIB_HPP
#define GRAPHLIB_HPP

#include <algorithm>
#include <iostream>
#include <vector>

template <typename NodeType>
struct Node {
  NodeType value;
  std::vector<int> neighbors;
};

template <typename NodeType>
struct Graph {
  std::vector<Node<NodeType>> nodes;
  bool isDirected;
};

template <typename NodeType>
Graph<NodeType> createGraph(bool isDirected = false) {
  return Graph<NodeType>{{}, isDirected};
}


template <typename NodeType>
int nodeIndex(const Graph<NodeType>& graph, const NodeType& node) {
  for (size_t i = 0; i < graph.nodes.size(); ++i) {
    if (graph.nodes[i].value == node) return i;
  }
  return -1;
}

template <typename NodeType>
int addNode(Graph<NodeType>& graph, const NodeType& node) {
  int index = nodeIndex(graph, node);
  if (index == -1) {
    graph.nodes.push_back({node, {}});
    index = graph.nodes.size() - 1;
  }
  return index;
}

template <typename NodeType>
bool addEdge(Graph<NodeType>& graph, const NodeType& src,
             const NodeType& dest) {
  int srcIndex = addNode(graph, src);
  int destIndex = addNode(graph, dest);

  if (!graph.isDirected) {
    // Evitar aristas duplicadas en grafos no dirigidos
    for (int neighbor : graph.nodes[destIndex].neighbors) {
      if (neighbor == srcIndex) {
        std::cerr << "[Error]: La arista ya existe." << std::endl;
        return false;
      }
    }
  }

  graph.nodes[srcIndex].neighbors.push_back(destIndex);
  if (!graph.isDirected) {
    graph.nodes[destIndex].neighbors.push_back(srcIndex);
  }
  return true;
}

template <typename NodeType>
bool removeEdge(Graph<NodeType>& graph, const NodeType& src,
                const NodeType& dest) {
  int srcIndex = nodeIndex(graph, src);
  int destIndex = nodeIndex(graph, dest);

  if (srcIndex == -1 || destIndex == -1) {
    std::cerr << "[Error]: Uno o ambos nodos no existen." << std::endl;
    return false;
  }

  auto& srcNeighbors = graph.nodes[srcIndex].neighbors;
  srcNeighbors.erase(
      std::remove(srcNeighbors.begin(), srcNeighbors.end(), destIndex),
      srcNeighbors.end());

  if (!graph.isDirected) {
    auto& destNeighbors = graph.nodes[destIndex].neighbors;
    destNeighbors.erase(
        std::remove(destNeighbors.begin(), destNeighbors.end(), srcIndex),
        destNeighbors.end());
  }
  return true;
}


template <typename NodeType>
bool nodeExists(const Graph<NodeType>& graph, const NodeType& node) {
  return nodeIndex(graph, node) != -1;
}

template <typename NodeType>
void DFSUtil(const Graph<NodeType>& graph, int nodeIndex,
             std::vector<bool>& visited, void (*visit)(const NodeType&)) {
  visited[nodeIndex] = true;
  visit(graph.nodes[nodeIndex].value);

  for (int neighbor : graph.nodes[nodeIndex].neighbors) {
    if (!visited[neighbor]) {
      DFSUtil(graph, neighbor, visited, visit);
    }
  }
}

template <typename NodeType>
void DFS(const Graph<NodeType>& graph, const NodeType& start,
         void (*visit)(const NodeType&)) {
  int startIndex = nodeIndex(graph, start);
  if (startIndex == -1) {
    std::cerr << "[Error]: El nodo de inicio no existe en el grafo."
              << std::endl;
    return;
  }

  std::vector<bool> visited(graph.nodes.size(), false);
  DFSUtil(graph, startIndex, visited, visit);
}

#endif  // GRAPHLIB_HPP
