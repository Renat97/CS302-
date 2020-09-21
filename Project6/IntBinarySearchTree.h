//
/// Created by Renat Norderhaug on 4/23/2018.
//

#ifndef PROJECT6_INTBINARYSEARCHTREE_H
#define PROJECT6_INTBINARYSEARCHTREE_H

#include <iostream>
#include <cstdlib>
#define INT_MAX 200
using namespace std;

    struct IntNode{
        int data;
        IntNode *left, *right, *parent;

        IntNode(){
            left = NULL;
            right = NULL;
            parent = NULL;
        };

    };

    struct IntBinarySearchTree{
        int elements;
        IntNode* root;

        IntBinarySearchTree(){
            elements = 0;
            root = NULL;
        };

        void add(int data){
            elements++;
            if (elements == 1){
                root = new IntNode;
                root->data=data;
                return;
            }
            IntNode* pointer = root;
            while(true){
                if (data == pointer->data) return;
                if (data > pointer->data){
                    if (pointer->right == NULL){
                        pointer->right = new IntNode;
                        pointer->right->data = data;
                        pointer->right->parent = pointer;
                        return;
                    }
                    pointer = pointer->right;
                }
                else{
                    if (pointer->left == NULL){
                        pointer->left = new IntNode;
                        pointer->left->data = data;
                        pointer->left->parent = pointer;
                        return;
                    }
                    pointer = pointer->left;
                }
            }
        };

        IntNode* findNode(int data){
            IntNode* pointer = root;
            while (pointer->data != data && pointer != NULL)
                if (pointer->data > data) pointer = pointer->left;
                else pointer = pointer->right;
            return pointer;
        };

        int FindMin(IntNode *root) {
            if (root == NULL) {
                return INT_MAX; // or undefined.
            }
            if (root->left != NULL) {
                return FindMin(root->left); // left tree is smaller
            }
            return root->data;
        }

        struct IntNode* remove(struct IntNode *root, int data) {
            if (root == NULL) {
                return NULL;
            }
            if (data < root->data) {  // data is in the left sub tree.
                root->left = remove(root->left, data);
            } else if (data > root->data) { // data is in the right sub tree.
                root->right = remove(root->right, data);
            } else {
                // case 1: no children
                if (root->left == NULL && root->right == NULL) {
                    delete(root); // wipe out the memory, in C, use free function
                    root = NULL;
                }
                    // case 2: one child (right)
                else if (root->left == NULL) {
                    struct IntNode *temp = root; // save current node as a backup
                    root = root->right;
                    delete temp;
                }
                    // case 3: one child (left)
                else if (root->right == NULL) {
                    struct IntNode *temp = root; // save current node as a backup
                    root = root->left;
                    delete temp;
                }
                    // case 4: two children
                else {
                    int tempData = FindMin(root->right); // find minimal value of right sub tree
                    root->data = tempData; // duplicate the node
                    root->right = remove(root->right, tempData); // delete the duplicate node
                }
            }
            return root; // parent node can update reference
        }

        void inOrder(IntNode* pointer){
            if (pointer == NULL){
                return;
            }
            inOrder(pointer->left);
            cout << pointer->data << " ";
            inOrder(pointer->right);
        };

        void removeInOrder(IntNode* pointer, IntBinarySearchTree* b){
            if (pointer == NULL){
                return;
            }
            removeInOrder(pointer->left, b);
            b-> remove(b->root, pointer->data);
            removeInOrder(pointer->right, b);
        };

        void removeThisFromOtherTree(IntBinarySearchTree* b){
            IntNode* pointer = root;
            return removeInOrder(root,b);
        };

        void printInOrder(){
            inOrder(root);
        };

        void preOrder(IntNode* pointer){
            if (pointer == NULL){
                return;
            }
            cout << pointer->data << " ";
            preOrder(pointer->left);
            preOrder(pointer->right);
        };

        void printPreOrder(){
            preOrder(root);
        };

        void postOrder(IntNode* pointer){
            if (pointer == NULL){
                return;
            }
            postOrder(pointer->left);
            postOrder(pointer->right);
            cout << pointer->data << " ";
        };

        void printPostOrder(){
            postOrder(root);
        };

        int getHeight(IntNode *subTreePtr) {
            if (subTreePtr == nullptr)
                return 0;
            else
                return 1 + max(getHeight(subTreePtr->left),getHeight(subTreePtr->right));
        }

        int getHeight() {
           return getHeight(root);
        }

        bool isEmpty()
        {
            return(root==NULL);
        }

        void clearTree(IntNode *T) {
            if (T == NULL) return;  // Nothing to clear
            if (T->left != NULL) clearTree(T->left); // Clear left sub-tree
            if (T->right != NULL) clearTree(T->right); // Clear right sub-tree
            delete T;    // Destroy this node
            return;
        }

    };

#endif //PROJECT6_INTBINARYSEARCHTREE_H
