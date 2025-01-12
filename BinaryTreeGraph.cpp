#include "BinaryTreeGraph.h"

// Constructor
BinaryTree::BinaryTree() : root(nullptr) {}

// Destructor
BinaryTree::~BinaryTree() {
    clear(root);
}

// Recursive function to clear memory
void BinaryTree::clear(TreeNode* node) {
    if (node) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

// Add node to the binary tree
void BinaryTree::addNode(const std::string& value) {
    if (!root) {
        root = new TreeNode(value);
    }
    else {
        TreeNode* current = root;
        while (true) {
            if (value < current->value) {
                if (!current->left) {
                    current->left = new TreeNode(value);
                    break;
                }
                current = current->left;
            }
            else {
                if (!current->right) {
                    current->right = new TreeNode(value);
                    break;
                }
                current = current->right;
            }
        }
    }
}

// In-order traversal
void BinaryTree::inOrderTraversal(TreeNode* node) const {
    if (node) {
        inOrderTraversal(node->left);
        std::cout << node->value << " ";
        inOrderTraversal(node->right);
    }
}

// Display the tree
void BinaryTree::display() const {
    inOrderTraversal(root);
    std::cout << std::endl;
}


// Add a node to the graph
void Graph::addNode(const std::string& city) {
    if (adjacencyList.find(city) == adjacencyList.end()) {
        adjacencyList[city] = {};
    }
}

// Add an edge between two cities with a weight
void Graph::addEdge(const std::string& city1, const std::string& city2, int weight) {
    addNode(city1);
    addNode(city2);
    adjacencyList[city1].emplace_back(city2, weight);
    adjacencyList[city2].emplace_back(city1, weight);
}

// Breadth-First Search (BFS)
void Graph::breadthFirstSearch(const std::string& startCity) const {
    std::bitset<100> visited; // Bitset for visited nodes (up to 100 nodes)
    std::queue<std::string> q;

    std::map<std::string, int> nodeIndex; // Map city names to indices
    int index = 0;
    for (const auto& pair : adjacencyList) {
        const std::string& city = pair.first;
        nodeIndex[city] = index++;
    }

    q.push(startCity);
    visited[nodeIndex[startCity]] = true;

    std::cout << "BFS starting from " << startCity << ": ";
    while (!q.empty()) {
        std::string currentCity = q.front();
        q.pop();

        std::cout << currentCity << " ";

        for (const auto& pair : adjacencyList.at(currentCity)) {
            const std::string& neighbor = pair.first;
            if (!visited[nodeIndex[neighbor]]) {
                visited[nodeIndex[neighbor]] = true;
                q.push(neighbor);
            }
        }
    }
    std::cout << std::endl;
}

// Dijkstra's Algorithm for shortest path
void Graph::dijkstraShortestPath(const std::string& startCity, const std::string& endCity) const {
    std::map<std::string, int> distances;
    std::map<std::string, std::string> previous;

    // Initialize distances to infinity
    for (const auto& pair : adjacencyList) {
        const std::string& city = pair.first;
        distances[city] = std::numeric_limits<int>::max();
    }

    distances[startCity] = 0;
    std::priority_queue<std::pair<int, std::string>, std::vector<std::pair<int, std::string>>, std::greater<>> pq;
    pq.push({ 0, startCity });

    while (!pq.empty()) {
        int currentDistance = pq.top().first;
        std::string currentCity = pq.top().second;
        pq.pop();

        if (currentCity == endCity) break;

        for (const auto& pair : adjacencyList.at(currentCity)) {
            const std::string& neighbor = pair.first;
            int weight = pair.second;
            int newDistance = currentDistance + weight;

            if (newDistance < distances[neighbor]) {
                distances[neighbor] = newDistance;
                previous[neighbor] = currentCity;
                pq.push({ newDistance, neighbor });
            }
        }
    }

    // Reconstruct path
    std::vector<std::string> path;
    for (std::string at = endCity; !at.empty(); at = previous[at]) {
        path.push_back(at);
    }
    std::reverse(path.begin(), path.end());

    std::cout << "Shortest path from " << startCity << " to " << endCity << " is: ";
    for (const auto& city : path) {
        std::cout << city << " ";
    }
    std::cout << "\nTotal distance: " << distances[endCity] << std::endl;
}


