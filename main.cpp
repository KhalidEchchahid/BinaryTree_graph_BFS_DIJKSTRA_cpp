#include "BinaryTreeGraph.h"

int main() {
    // Binary Tree Test
    BinaryTree tree;
    tree.addNode("Casablanca");
    tree.addNode("Marrakech");
    tree.addNode("Rabat");
    tree.addNode("Fez");
    tree.addNode("Tangier");
    std::cout << "Binary Tree In-Order Traversal: ";
    tree.display();

    // Graph Test
    Graph graph;
    graph.addEdge("Casablanca", "Marrakech", 240);
    graph.addEdge("Casablanca", "Rabat", 87);
    graph.addEdge("Rabat", "Fez", 207);
    graph.addEdge("Fez", "Tangier", 291);
    graph.addEdge("Marrakech", "Agadir", 235);

    std::cout << "\nBreadth-First Search (BFS): ";
    graph.breadthFirstSearch("Casablanca");

    std::cout << "\nDijkstra's Shortest Path: ";
    graph.dijkstraShortestPath("Casablanca", "Tangier");

    return 0;
}

