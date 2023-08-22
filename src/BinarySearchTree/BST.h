#pragma once
#include "iostream"
#include <stdexcept>
#include "BinarySearchTree.h"

template<class T>
class BST : public BinarySearchTree<T> {
private:
    class Node {
        T item;
        Node* left;
        Node* right;
        Node(const T& item);
        ~Node();
    }
    int itemQty;
    Node* root;
    bool search(Node* root, const T& item) const;
    Node* insert(Node* root, const T& item);
    Node* remove(Node* root, const T& item);
    Node* removeBiggerSmallest(Node* root);
    void printTree(Node* root) const;
public:
    BST();
    ~BST();
    int size() const override;
    bool search(const T& item) const override;
    void insertion(const T& item) override;
    void deletion(const T& item) override;
    const T& top() const override;
    void printTree() const;
};

template<class T>
BST<T>::Node::Node(const T& item) {
    this.item = item;
    left = nullptr;
    right = nullptr;
}

template<class T>
BST<T>::Node::~Node() {
    delete left;
    left = nullptr;
    delete right;
    right = nullptr;
}

template<class T>
BST<T>::BST() {
    itemQty = 0;
    root = nullptr;
}

template<class T>
BST<T>::~BST() {
    itemQty = 0;
    delete root;
}

template<class T>
int BST<T>::size() const {
    return itemQty;
}

template<class T>
bool BST<T>::search(BST<T>::Node* root, const T& item) const {
    if (root == nullptr) return false;
    if (root->item > item) {
        return search(root->left, item);
    } else if (root->item < item) {
        return search(root->right, item);
    } else {
        return true;
    }
}

template<class T>
bool BST<T>::search(const T& item) const {
    return search(root, item);
}

template<class T>
BST<T>::Node* BST<T>::insert(BST<T>::Node* root, const T& item) {
    if (root == nullptr) {
        itemQty++;
        return new Node(item);
    }
    if (root->item > item) {
        item->left = insert(root->left, item);
    } else if (root->item < item){
        item->right = insert(root->right, item);
    }
    return root; 
}

template<class T>
void BST<T>::insertion(const T& item) {
    root = insert(root, item);
}

template<class T>
BST<T>::Node* BST<T>::remove(BST<T>::Node* root, const T& item) {
    if (root == nullptr) return root;
    if (root->item > item) {
        root->left = remove(root->left, item);
        return root;
    } 
    if (root->item < item) {
        root->right = remove(root->right, item);
        return root;
    }
    Node* deleteNode = root;
    if (root->left == nullptr) {
        root = root->right;
    } else if (root->right == nullptr){
        root = root->left;
    } else {
        root = removeBiggerSmallest(root);
        root->left = deleteNode->left;
        root->right = deleteNode->right;
    }
    deleteNode->right = nullptr;
    deleteNode->left = nullptr;
    delete deleteNode;
    itemQty--;
    return root;
}

template<class T>
BST<T>::Node* BST<T>::removeBiggerSmallest(BST<T>::Node* root) {
    Node* parent = root->right;
    Node* child = root->right->left;
    if (child == nullptr) {
        root->right = parent->right;
        parent->right = nullptr;
        return parent;
    }
    while (child->left != nullptr) {
        parent = child;
        child = child->left;
    }
    parent->left = child->right;
    child->right = nullptr;
    return child;
}

template<class T>
void BST<T>::deletion(const T& item) {
    root = remove(root, item);
}

template<class T>
const T& BST<T>::top() const {
    if (isEmpty()) throw std::invalid_argument("Call top() with size 0.");
    return root->item;
}

template<class T>
void BST<T>::printTree() const {
    printTree(root);
}

template<class T>
void BST<T>::printTree(BST<T>::Node* root) const {
    if (root == nullptr) return;
    printTree(root->left);
    std::cout << root->item;
    printTree(root->right);
}
