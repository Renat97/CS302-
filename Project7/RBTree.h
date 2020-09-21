/// CS 302 Project 7
/// Created by Renat Norderhaug on 5/7/18.
///

#ifndef PROJECT7_RBTREE_H
#define PROJECT7_RBTREE_H
#include <iostream>

using namespace std;

enum Color {RED, BLACK, DOUBLE_BLACK};

struct Node
{
    int data;
    int color;
    Node *left, *right, *parent;
/// typecasting Node
    explicit Node(int);
};
/// RBTree functions declared here
class RBTree
{
private:
    Node *root;
protected:
    void rotateLeft(Node *p);
    void rotateRight(Node *p);
    void fixInsertRBTree(Node *p);
    void fixDeleteRBTree(Node *p);
    void inorderBST(Node *p);
    void preorderBST(Node *p);
    void inorderDelete(Node *p);
    int getColor(Node *p);
    void setColor(Node *p, int);
    Node *minValueNode(Node *p);
    Node *maxValueNode(Node *p);
    Node* insertBST(Node *p, Node *q);
    Node* deleteBST(Node *p, int);
    int getSumInorder(Node *p);
public:
    int height;
    int sum;
    RBTree();
    void insertValue(int);
    void deleteValue(int);
    void deleteTree();
    void inorder();
    void preorder();
    int getHeight();
    int getSum();
};

Node::Node(int data) {
    this->data = data;
/// sets Node to Red first so there is less cases that could be potentially violated
    color = RED;
    left = right = parent = nullptr;
}
/// root is null
RBTree::RBTree() {
    root = nullptr;
}
/// returns color
int RBTree::getColor(Node *node) {
    if (node == nullptr)
        return BLACK;

    return node->color;
}
/// set color of node
void RBTree::setColor(Node *node, int color) {
    if (node == nullptr)
        return;

    node->color = color;
}
/// insert a Node into the RBT following the conventions 
Node* RBTree::insertBST(Node *root, Node *ptr) {
    if (root == nullptr)
        return ptr;

    if (ptr->data < root->data) {
        root->left = insertBST(root->left, ptr);
        root->left->parent = root;
    } else if (ptr->data > root->data) {
        root->right = insertBST(root->right, ptr);
        root->right->parent = root;
    }

    return root;
}
/// insert value of node
void RBTree::insertValue(int n) {
    Node *node = new Node(n);
    root = insertBST(root, node);
    fixInsertRBTree(node);
}
/// rotate left function
void RBTree::rotateLeft(Node *ptr) {
    Node *right_child = ptr->right;
    ptr->right = right_child->left;

    if (ptr->right != nullptr)
        ptr->right->parent = ptr;

    right_child->parent = ptr->parent;

    if (ptr->parent == nullptr)
        root = right_child;
    else if (ptr == ptr->parent->left)
        ptr->parent->left = right_child;
    else
        ptr->parent->right = right_child;

    right_child->left = ptr;
    ptr->parent = right_child;
}
/// rotate right
void RBTree::rotateRight(Node *ptr) {
    Node *left_child = ptr->left;
    ptr->left = left_child->right;

    if (ptr->left != nullptr)
        ptr->left->parent = ptr;

    left_child->parent = ptr->parent;

    if (ptr->parent == nullptr)
        root = left_child;
    else if (ptr == ptr->parent->left)
        ptr->parent->left = left_child;
    else
        ptr->parent->right = left_child;

    left_child->right = ptr;
    ptr->parent = left_child;
}
/// Case's for inserting checking color of uncle, grandparent,
void RBTree::fixInsertRBTree(Node *ptr) {
    Node *parent = nullptr;
    Node *grandparent = nullptr;
    while (ptr != root && getColor(ptr) == RED && getColor(ptr->parent) == RED) {
        parent = ptr->parent;
        grandparent = parent->parent;
        if (parent == grandparent->left) {
            Node *uncle = grandparent->right;
            if (getColor(uncle) == RED) {
                setColor(uncle, BLACK);
                setColor(parent, BLACK);
                setColor(grandparent, RED);
                ptr = grandparent;
            } else {
                if (ptr == parent->right) {
                    rotateLeft(parent);
                    ptr = parent;
                    parent = ptr->parent;
                }
                rotateRight(grandparent);
                swap(parent->color, grandparent->color);
                ptr = parent;
            }
        } else {
            Node *uncle = grandparent->left;
            if (getColor(uncle) == RED) {
                setColor(uncle, BLACK);
                setColor(parent, BLACK);
                setColor(grandparent, RED);
                ptr = grandparent;
            } else {
                if (ptr == parent->left) {
                    rotateRight(parent);
                    ptr = parent;
                    parent = ptr->parent;
                }
                rotateLeft(grandparent);
                swap(parent->color, grandparent->color);
                ptr = parent;
            }
        }
    }
    setColor(root, BLACK);
}

void RBTree::fixDeleteRBTree(Node *node) {
    if (node == nullptr)
        return;

    if (node == root) {
        root = nullptr;
        return;
    }

    if (getColor(node) == RED || getColor(node->left) == RED || getColor(node->right) == RED) {
        Node *child = node->left != nullptr ? node->left : node->right;

        if (node == node->parent->left) {
            node->parent->left = child;
            if (child != nullptr)
                child->parent = node->parent;
            setColor(child, BLACK);
            delete (node);
        } else {
            node->parent->right = child;
            if (child != nullptr)
                child->parent = node->parent;
            setColor(child, BLACK);
            delete (node);
        }
    } else {
        Node *sibling = nullptr;
        Node *parent = nullptr;
        Node *ptr = node;
        setColor(ptr, DOUBLE_BLACK);
        while (ptr != root && getColor(ptr) == DOUBLE_BLACK) {
            parent = ptr->parent;
            if (ptr == parent->left) {
                sibling = parent->right;
                if (getColor(sibling) == RED) {
                    setColor(sibling, BLACK);
                    setColor(parent, RED);
                    rotateLeft(parent);
                } else {
                    if (getColor(sibling->left) == BLACK && getColor(sibling->right) == BLACK) {
                        setColor(sibling, RED);
                        if(getColor(parent) == RED)
                            setColor(parent, BLACK);
                        else
                            setColor(parent, DOUBLE_BLACK);
                        ptr = parent;
                    } else {
                        if (getColor(sibling->right) == BLACK) {
                            setColor(sibling->left, BLACK);
                            setColor(sibling, RED);
                            rotateRight(sibling);
                            sibling = parent->right;
                        }
                        setColor(sibling, parent->color);
                        setColor(parent, BLACK);
                        setColor(sibling->right, BLACK);
                        rotateLeft(parent);
                        break;
                    }
                }
            } else {
                sibling = parent->left;
                if (getColor(sibling) == RED) {
                    setColor(sibling, BLACK);
                    setColor(parent, RED);
                    rotateRight(parent);
                } else {
                    if (getColor(sibling->left) == BLACK && getColor(sibling->right) == BLACK) {
                        setColor(sibling, RED);
                        if (getColor(parent) == RED)
                            setColor(parent, BLACK);
                        else
                            setColor(parent, DOUBLE_BLACK);
                        ptr = parent;
                    } else {
                        if (getColor(sibling->left) == BLACK) {
                            setColor(sibling->right, BLACK);
                            setColor(sibling, RED);
                            rotateLeft(sibling);
                            sibling = parent->left;
                        }
                        setColor(sibling, parent->color);
                        setColor(parent, BLACK);
                        setColor(sibling->left, BLACK);
                        rotateRight(parent);
                        break;
                    }
                }
            }
        }
        if (node == node->parent->left)
            node->parent->left = nullptr;
        else
            node->parent->right = nullptr;
        delete(node);
        setColor(root, BLACK);
    }
}
/// deleting the tree
Node* RBTree::deleteBST(Node *root, int data) {
    if (root == nullptr)
        return root;

    if (data < root->data)
        return deleteBST(root->left, data);

    if (data > root->data)
        return deleteBST(root->right, data);

    if (root->left == nullptr || root->right == nullptr)
        return root;

    Node *temp = minValueNode(root->right);
    root->data = temp->data;
    return deleteBST(root->right, temp->data);
}
/// delete value in an node
void RBTree::deleteValue(int data) {
    Node *node = deleteBST(root, data);
    fixDeleteRBTree(node);
}
/// deleting inorder from left, root, right
void RBTree::inorderDelete(Node *p) {
    if (p == nullptr)
        return;

    inorderDelete(p->left);
    deleteValue(p->data);
    inorderDelete(p->right);
}
/// in order left, root ,right
void RBTree::inorderBST(Node *ptr) {
    if (ptr == nullptr)
        return;

    inorderBST(ptr->left);
    cout << ptr->data << " " << ptr->color << endl;
    inorderBST(ptr->right);
}

void RBTree::inorder() {
    inorderBST(root);
}

void RBTree::deleteTree() {
    return inorderDelete(root);
}
/// returns height of tree
int RBTree::getHeight() {
    Node *node = root;
    int height = 0;
    while (node != nullptr) {
        height++;
        node = node->left;
    }
    return height;
}
/// sums up the Node's values while traversing in order 
int RBTree::getSumInorder(Node *p) {
    if (p == nullptr)
        return sum;

    getSumInorder(p->left);
    sum = sum +  p->data;
    getSumInorder(p->right);
    return sum;
}
/// returns sum
int RBTree::getSum() {
    return getSumInorder(root);
}
/// pre order root, left , right
void RBTree::preorderBST(Node *ptr) {
    if (ptr == nullptr)
        return;

    cout << ptr->data << " " << ptr->color << endl;
    preorderBST(ptr->left);
    preorderBST(ptr->right);
}

void RBTree::preorder() {
    preorderBST(root);
    cout << "-------" << endl;
}
/// lowest value
Node *RBTree::minValueNode(Node *node) {

    Node *ptr = node;

    while (ptr->left != nullptr)
        ptr = ptr->left;

    return ptr;
}
/// heighest
Node* RBTree::maxValueNode(Node *node) {
    Node *ptr = node;

    while (ptr->right != nullptr)
        ptr = ptr->right;

    return ptr;
}

#endif //PROJECT7_RBTREE_H
