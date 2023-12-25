#include "./binaryTree.hpp"

template <class T>
BinaryTree<T>::BinaryTree(){
    root = nullptr;
    size = 0;
}

template <class T>
BinaryTree<T>::~BinaryTree(){
    deleteSubTree(root);
}

template <class T>
bool BinaryTree<T>::lookup(T value){
    return lookupHelper(root, value);
}

template <class T>
bool BinaryTree<T>::lookupHelper(Node* currentNode, T value){
    if(currentNode == nullptr) return false;
    else{
        if(currentNode->data == value) return true;                                         //return if value found
        else if(currentNode->data > value) return lookupHelper(currentNode->left, value);   //check left node if current node > value
        else return lookupHelper(currentNode->right, value);                                //check right node if current node < value
    }
}

template <class T>
bool BinaryTree<T>::add(T value){
    return addHelper(root, value);
}

template <class T>
bool BinaryTree<T>::addHelper(Node*& currentNode, T value){
    if(currentNode == nullptr){
        Node* node = new Node;
        node->data = value;
        node->left = nullptr;
        node->right = nullptr;
        currentNode = node;
        size++;
        return true;
    }
    else{
        if(currentNode->data == value) return false;                                        //data already in tree, no duplicates allowed
        else if (currentNode->data > value) return addHelper(currentNode->left, value);     //if currentNode > value, put value to left node
        else return addHelper(currentNode->right, value);                                   //if currentNode < value, put value to right node
    }
}

template <class T>
void BinaryTree<T>::deleteSubTree(Node* currentNode){
    if(currentNode != nullptr){
        deleteSubTree(currentNode->left);
        deleteSubTree(currentNode->right);
        delete currentNode;
    }
}