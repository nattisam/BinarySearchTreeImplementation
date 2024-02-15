#include "BST.h"
#include <iostream>

BST::BST() : root(nullptr), nCount(0) {}

BST::~BST() {
    clear();
}

// Find the minimum key in a subtree rooted at ptr
KEY_VALUE BST::findMin(Node *ptr) {
    KEY_VALUE minValue;
    while (ptr->left) {
        ptr = ptr->left;
    }
    minValue = ptr->kv;
    return minValue;
}

// Recursively clear the tree rooted at ptr
void BST::clearHelper(Node *ptr) {
    if (!ptr) {
        return;
    }
    clearHelper(ptr->left);
    clearHelper(ptr->right);
    delete ptr;
}

// Recursively insert a node with key-value kv into the tree rooted at ptr
bool BST::insertHelper(Node *&ptr, KEY_VALUE kv) {
    bool inserted = false;
    if (!ptr) {
        ptr = new Node(kv);
        nCount++;
        inserted = true;
    } else if (kv.key < ptr->kv.key) {
        inserted = insertHelper(ptr->left, kv);
    } else if (kv.key > ptr->kv.key) {
        inserted = insertHelper(ptr->right, kv);
    }
    return inserted;
}

// Recursively remove a node with key 'key' from the tree rooted at ptr
bool BST::removeHelper(Node *&ptr, int key) {
    bool removed = false;
    if (!ptr) {
        return false;
    }
    if (key < ptr->kv.key) {
        removed = removeHelper(ptr->left, key);
    } else if (key > ptr->kv.key) {
        removed = removeHelper(ptr->right, key);
    } else {
        if (!ptr->left && !ptr->right) {
            delete ptr;
            ptr = nullptr;
        } else if (!ptr->left) {
            Node *temp = ptr;
            ptr = ptr->right;
            delete temp;
        } else if (!ptr->right) {
            Node *temp = ptr;
            ptr = ptr->left;
            delete temp;
        } else {
            ptr->kv = findMin(ptr->right);
            removed = removeHelper(ptr->right, ptr->kv.key);
        }
        nCount--;
        removed = true;
    }
    return removed;
}

// Recursively search for a node with key 'key' in the tree rooted at ptr
bool BST::getValueHelper(Node *ptr, int key, int &value) const {
    bool found = false;
    while (ptr) {
        if (key < ptr->kv.key) {
            ptr = ptr->left;
        } else if (key > ptr->kv.key) {
            ptr = ptr->right;
        } else {
            value = ptr->kv.value;
            found = true;
            break;
        }
    }
    return found;
}

// Inorder traversal to print the tree contents in sorted order
void BST::printHelper(Node *ptr) const {
    if (ptr) {
        printHelper(ptr->left);
        std::cout << ptr->kv.key << ": " << ptr->kv.value << std::endl;
        printHelper(ptr->right);
    }
}

// Insert a node with key-value kv into the tree
bool BST::insert(KEY_VALUE kv) {
    return insertHelper(root, kv);
}

// Remove a node with key 'key' from the tree
bool BST::remove(int key) {
    return removeHelper(root, key);
}

// Search for a node with key 'key' and update value if found
bool BST::getValue(int key, int &value) const {
    return getValueHelper(root, key, value);
}

// Print the tree contents in sorted order
void BST::printIt() const {
    printHelper(root);
}

// Return the number of nodes in the tree
int BST::count() const {
    return nCount;
}

// Clear the tree
void BST::clear() {
    clearHelper(root);
    root = nullptr;
    nCount = 0;
}
