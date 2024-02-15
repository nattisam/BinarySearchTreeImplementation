#ifndef BST_H
#define BST_H

typedef struct key_value {
    int key;
    int value;
} KEY_VALUE;

class BST {
private:
    struct Node {
        KEY_VALUE kv;
        Node *left, *right;
        Node(KEY_VALUE kv) : kv(kv), left(nullptr), right(nullptr) {}
        friend class BST;
    };

    Node *root;
    int nCount;

    KEY_VALUE findMin(Node *ptr);
    void clearHelper(Node *ptr);
    bool insertHelper(Node *&ptr, KEY_VALUE kv);
    bool removeHelper(Node *&ptr, int key);
    bool getValueHelper(Node *ptr, int key, int &value) const;
    void printHelper(Node *ptr) const;

public:
    BST();
    ~BST();
    bool insert(KEY_VALUE kv);
    bool remove(int key);
    bool getValue(int key, int &value) const;
    void printIt() const;
    int count() const;
    void clear();
};

#endif
