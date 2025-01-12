#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <bitset>
#include <limits>
#include <string>

class BinaryTree {
private:
    struct TreeNode {
        std::string value;
        TreeNode* left;
        TreeNode* right;

        TreeNode(const std::string& val) : value(val), left(nullptr), right(nullptr) {}
    };

    TreeNode* root;

    void inOrderTraversal(TreeNode* node) const;

public:
    BinaryTree();
    ~BinaryTree();
    void addNode(const std::string& value);
    void display() const;
    void clear(TreeNode* node);
};

class Graph {
private:
    std::map<std::string, std::vector<std::pair<std::string, int>>> adjacencyList;

public:
    void addNode(const std::string& city);
    void addEdge(const std::string& city1, const std::string& city2, int weight);
    void breadthFirstSearch(const std::string& startCity) const;
    void dijkstraShortestPath(const std::string& startCity, const std::string& endCity) const;
};

