#pragma once
#include <cstddef>

//BinaryTree will assume that class T has operator overloads for <, >, and ==
template <class T>
class BinaryTree{
public:
    BinaryTree();
    ~BinaryTree();
    bool lookup(T value);
    bool add(T value);
    T& remove(T value);     //todo
    void balance();         //todo
private:
    //nodes used in binary tree
    struct Node{
        T data;
        Node* right;
        Node* left;
    };

    void deleteSubTree(Node* currentNode);
    bool lookupHelper(Node* currentNode, T value);
    bool addHelper(Node*& currentNode, T value);

    Node* root;
    size_t size;
    
};