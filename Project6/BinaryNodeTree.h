//
/// Created by Renat Norderhaug on 4/17/18.
//
#include "BinaryNode.h"
#include "BinaryTreeInterface.h"
#include <iostream>
#include <fstream>

using namespace std;

template<class ItemType>
class BinaryNodeTree : virtual public BinaryTreeInterface<ItemType> {
private:
    BinaryNode<ItemType> *rootPtr;

protected:
    

    int getHeightHelper(BinaryNode<ItemType> *subTreePtr) const;

    int getNumberOfNodesHelper(BinaryNode<ItemType> *subTreePtr) const;

    /// Recursively deletes all nodes from the tree.
    void destroyTree(BinaryNode<ItemType> *subTreePtr);

    /// Recursively adds a new node to the tree in a left/right fashion to
    /// keep the tree balanced.
    BinaryNode<ItemType> *balancedAdd(BinaryNode<ItemType> *subTreePtr,
                                      BinaryNode<ItemType> *newNodePtr);

    
    BinaryNode<ItemType> *removeValue(BinaryNode<ItemType> *subTreePtr,
                                      const ItemType target,
                                      bool &success);

    /// Copies values up the tree to overwrite value in current node until
    /// a leaf is reached; the leaf is then removed, since its value is
    /// stored in the parent.
    BinaryNode<ItemType> *moveValuesUpTree(BinaryNode<ItemType> *subTreePtr);

    // Recursively searches for target value in the tree by using a
    // preorder traversal.
    
    BinaryNode<ItemType> *findNode(BinaryNode<ItemType> *subTreePtr, ItemType target) const;

    // Copies the tree rooted at treePtr and returns a pointer to
    // the copy.
    BinaryNode<ItemType> *copyTree(const BinaryNode<ItemType> *treePtr) const;

    void preorder(void visit(ItemType &), BinaryNode<ItemType> *treePtr) const;

    void inorder(void visit(ItemType &), BinaryNode<ItemType> *treePtr) const;

    void postorder(void visit(ItemType &), BinaryNode<ItemType> *treePtr) const;

public:
 
    BinaryNodeTree();

    BinaryNodeTree(const ItemType &rootItem);

    BinaryNodeTree(const ItemType &rootItem,
                   const BinaryNodeTree<ItemType> *leftTreePtr,
                   const BinaryNodeTree<ItemType> *rightTreePtr);

    BinaryNodeTree(const BinaryNodeTree<ItemType> &tree);

    virtual ~BinaryNodeTree();

    
    bool isEmpty() const;

    int getHeight() const;

    int getNumberOfNodes() const;

    ItemType getRootData() const;
    void setRootData(const ItemType& newData);

    bool add(const ItemType &newData); // Adds a node
    bool remove(const ItemType &data); // Removes a node
    void clear();
    bool contains(const ItemType &anEntry) const;
    ItemType getEntry(const ItemType& anEntry) const;
    
    void preorderTraverse(void visit(ItemType &)) const;

    void inorderTraverse(void visit(ItemType &)) const;

    void postorderTraverse(void visit(ItemType &)) const;

    
    BinaryNodeTree &operator=(const BinaryNodeTree &rightHandSide);
};

#include "BinaryNode.h"
#include <iostream>

/// proteted ethods
template<class ItemType>
BinaryNode<ItemType> *BinaryNodeTree<ItemType>::balancedAdd(BinaryNode<ItemType> *subTreePtr,
                                                            BinaryNode<ItemType> *newNodePtr) {
    if (subTreePtr == nullptr)
        return newNodePtr;
    else {
        BinaryNode<ItemType> *leftPtr = subTreePtr->getLeftChildPtr();
        BinaryNode<ItemType> *rightPtr = subTreePtr->getRightChildPtr();

        if (getHeightHelper(leftPtr) > getHeightHelper(rightPtr)) {
            rightPtr = balancedAdd(rightPtr, newNodePtr);
            subTreePtr->setRightChildPtr(rightPtr);
        } else {
            leftPtr = balancedAdd(leftPtr, newNodePtr);
            subTreePtr->setLeftChildPtr(leftPtr);
        }  // end if

        return subTreePtr;
    }  // end if
}  // end balancedAdd

template<class ItemType>
BinaryNode<ItemType> *BinaryNodeTree<ItemType>::copyTree(const BinaryNode<ItemType> *treePtr) const {
    BinaryNode<ItemType> *newTreePtr = nullptr;

    // Copy tree nodes during a preorder traversal
    if (treePtr != nullptr) {
        // Copy node
        newTreePtr = new BinaryNode<ItemType>(treePtr->getItem(), nullptr, nullptr);
        newTreePtr->setLeftChildPtr(copyTree(treePtr->getLeftChildPtr()));
        newTreePtr->setRightChildPtr(copyTree(treePtr->getRightChildPtr()));
    }  // end if

    return newTreePtr;
}  // end copyTree

template<class ItemType>
void BinaryNodeTree<ItemType>::destroyTree(BinaryNode<ItemType> *subTreePtr) {
    if (subTreePtr != nullptr) {
        destroyTree(subTreePtr->getLeftChildPtr());
        destroyTree(subTreePtr->getRightChildPtr());
        delete subTreePtr;
    }  // end if
}  // end destroyTree


template<class ItemType>

void BinaryNodeTree<ItemType>::preorder(void visit(ItemType &), BinaryNode<ItemType> *treePtr) const {

    if (treePtr != nullptr) {
        ItemType theItem = treePtr->getItem();
        visit(theItem);
        preorder(visit, treePtr->getLeftChildPtr());
        preorder(visit, treePtr->getRightChildPtr());
    } // end if

} // end preorder

template<class ItemType>

void BinaryNodeTree<ItemType>::inorder(void visit(ItemType &),
                                       BinaryNode<ItemType> *treePtr) const {
    if (treePtr != nullptr) {
        inorder(visit, treePtr->getLeftChildPtr());
        ItemType theItem = treePtr->getItem();
        visit(theItem);
        inorder(visit, treePtr->getRightChildPtr());
    } // end if

} // end inorder

template<class ItemType>

void BinaryNodeTree<ItemType>::postorder(void visit(ItemType &),
                                         BinaryNode<ItemType> *treePtr) const {
    if (treePtr != nullptr) {
        postorder(visit, treePtr->getLeftChildPtr());
        postorder(visit, treePtr->getRightChildPtr());
        ItemType theItem = treePtr->getItem();
        visit(theItem);
    } // end if

} // end postorder


template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree() : rootPtr(nullptr) {
}  // end default constructor

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType &rootItem) {
    rootPtr = new BinaryNode<ItemType>(rootItem, nullptr, nullptr);
}  // end constructor

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType &rootItem,
                                         const BinaryNodeTree<ItemType> *leftTreePtr,
                                         const BinaryNodeTree<ItemType> *rightTreePtr) {
    rootPtr = new BinaryNode<ItemType>(rootItem, copyTree(leftTreePtr->rootPtr),
                                       copyTree(rightTreePtr->rootPtr));
}  // end constructor

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const BinaryNodeTree<ItemType> &treePtr) {
    rootPtr = copyTree(treePtr.rootPtr);
}  // end copy constructor

template<class ItemType>
BinaryNodeTree<ItemType>::~BinaryNodeTree() {
    destroyTree(rootPtr);
}  // end destructor


template<class ItemType>
bool BinaryNodeTree<ItemType>::add(const ItemType &newData) {
    BinaryNode<ItemType> *newNodePtr = new BinaryNode<ItemType>(newData);
    rootPtr = balancedAdd(rootPtr, newNodePtr);
    return true;
}  // end add

template<class ItemType>
bool BinaryNodeTree<ItemType>::isEmpty() const
{
    return rootPtr == nullptr;
} // end isEmpty


template<class ItemType>
int  BinaryNodeTree<ItemType>::getHeight() const {
    return this->getHeightHelper(rootPtr);
}

template<class ItemType>
int  BinaryNodeTree<ItemType>::getNumberOfNodes() const { return this->getNumberOfNodesHelper(rootPtr); }

template<class ItemType>
ItemType BinaryNodeTree<ItemType>::getRootData() const {
    if (isEmpty())
        cout << "getRootData() called with empty tree." << endl;
    //throw PrecondViolatedExcep("getRootData() called with empty tree.");
    return rootPtr->getItem();
};

template<class ItemType>
bool BinaryNodeTree<ItemType>::remove(const ItemType& anEntry) {
    bool isSuccessful = false;
    rootPtr = removeValue(rootPtr, anEntry, isSuccessful);
    return isSuccessful;
};

template<class ItemType>
void BinaryNodeTree<ItemType>::clear() { this->destroyTree(rootPtr); rootPtr = nullptr; }

template<class ItemType>
ItemType BinaryNodeTree<ItemType>::getEntry(const ItemType& anEntry) const{
    BinaryNode<ItemType>* nodeWithEntry = findNode(rootPtr, anEntry);
    if (nodeWithEntry == NULL){
        cout << "Entry not found in tree." << endl;
        //throw NotFoundException("Entry not found in tree.");
    } // else
    return nodeWithEntry->getItem();
};

// Override contains to use our improved findNode:

template<class ItemType>
bool BinaryNodeTree<ItemType>::contains(const ItemType& anEntry) const {

    return findNode(rootPtr, anEntry); // nullptr is same as false

}


template<class ItemType>
void BinaryNodeTree<ItemType>::preorderTraverse(void visit(ItemType&)) const
{
    preorder(visit, rootPtr);
} // end preorderTraverse

template<class ItemType>
void BinaryNodeTree<ItemType>::inorderTraverse(void visit(ItemType&)) const
{
    inorder(visit, rootPtr);
} // end inorderTraverse
template<class ItemType>
void BinaryNodeTree<ItemType>::postorderTraverse(void visit(ItemType&)) const
{
    postorder(visit, rootPtr);
} // end postorderTraverse






