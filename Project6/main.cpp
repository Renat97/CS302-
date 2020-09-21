#include <iostream>
#include <ctime>
#include "IntBinarySearchTree.h"
/// main method by Renat Norderhaug, CS 302 project 6
using namespace std;
/// method to display items


int main() {

    int min=0;
    int max=200;

    IntBinarySearchTree b1;
    for (int i = 0; i< 99;i++) {
       b1.add(min + (rand() % static_cast<int>(max - min + 1)));
    }
    cout << "\n Tree 1 Height: ";
    cout << b1.getHeight() << endl;
    cout << "\n Tree 1 Inorder:";
    b1.printInOrder();

    IntBinarySearchTree b2;
    for (int j = 0; j< 99;j++) {
        b2.add(min + (rand() % static_cast<int>(max - min + 1)));
    }

    cout << "\n Tree 2 Preorder: ";
    IntNode* startNode = b2.root;
    b2.preOrder(startNode);
    cout << "\n Tree 2 Inorder: ";
    b2.inOrder(startNode);
    cout << "\n Tree 2 Postorder: ";
    b2.postOrder(startNode);

    cout << "\n Removing all tree 2 nodes from Tree 1: ";
    b2.removeThisFromOtherTree(&b1);

    cout << "\n Tree 1 Inorder after removal:";
    b1.inOrder(b1.root);

    cout << "\n Clearing both trees: ";
    b1.clearTree(b1.root);
    b2.clearTree(b2.root);

    return 0;

}
