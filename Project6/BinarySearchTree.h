//
// Created by Renat Norderhaug on 4/22/2018.
//

#ifndef PROJECT6_BINARYSEARCHTREE_H
#define PROJECT6_BINARYSEARCHTREE_H

#include "BinaryTreeInterface.h"
#include "BinaryNode.h"
#include "BinaryNodeTree.h"
#include "NotFoundException.h"
#include "PrecondViolatedExcep.h"
#include <memory>

template<class ItemType>
class BinarySearchTree : public BinaryNodeTree<ItemType> {
private:
    BinaryNode<ItemType> *rootPtr;

protected:

    // Recursively finds where the given node should be placed and
    // inserts it in a leaf at that point.
    BinaryNode<ItemType> *placeNode(BinaryNode<ItemType> *subTreePtr,
                                        BinaryNode<ItemType> *newNodePtr);

    // Removes the given target value from the tree while maintaining a
    // binary search tree.
    BinaryNode<ItemType> *removeValue(BinaryNode<ItemType>* subTreePtr,
                                      const ItemType target,
                                      bool& success);

    // Removes a given node from a tree while maintaining a
    // binary search tree.
    BinaryNode<ItemType> *removeNode(BinaryNode<ItemType> *nodePtr);
 /// Removes the leftmost node pointer
    BinaryNode<ItemType> *removeLeftmostNode(BinaryNode<ItemType> *subTreePtr,
                                             ItemType &inorderSuccessor);

    // Returns a pointer to the node containing the given value,
    // or nullptr if not found.
    BinaryNode<ItemType> *findNode(BinaryNode<ItemType> *treePtr,
                                   const ItemType &target) const;

public:

    BinarySearchTree();

    BinarySearchTree<ItemType>(const ItemType &rootItem);

    BinarySearchTree<ItemType>(const BinarySearchTree<ItemType> &tree);

    ~BinarySearchTree();
/// public methods
    bool isEmpty() const;

    int getHeight() const;

    int getNumberOfNodes() const;

    ItemType getRootData() const;

    void setRootData(const ItemType &newData) const;

    bool add(const ItemType &newEntry);

    bool remove(const ItemType &anEntry);

    void clear();

    ItemType getEntry(const ItemType &anEntry) const;

    bool contains(const ItemType &anEntry) const;

    void printTree(BinaryNode<ItemType> *t) const;

    void preorderTraverse(void visit(ItemType &)) const;

    void inorderTraverse(void visit(ItemType &)) const;

    void postorderTraverse(void visit(ItemType &)) const;


    BinarySearchTree<ItemType> &operator=(const BinarySearchTree<ItemType> &rightHandSide);

    bool operator==(
            const BinarySearchTree<ItemType> &other);

}; // end BinarySearchTree



template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::placeNode(BinaryNode<ItemType>* subTreePtr,
                                                                BinaryNode<ItemType>* newNodePtr) {
    if (subTreePtr == NULL)
        return newNodePtr;
    else {
        if (subTreePtr->getItem() > newNodePtr->getItem()){
            subTreePtr->setLeftChildPtr(placeNode(subTreePtr->getLeftChildPtr(), newNodePtr));
        } else {
            subTreePtr->setRightChildPtr(placeNode(subTreePtr->getRightChildPtr(), newNodePtr));
        }
        return subTreePtr;
    }  // end else
}

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeValue(BinaryNode<ItemType>* subTreePtr,
                                                              const ItemType target,
                                                              bool& success)
{
    if (subTreePtr == NULL)
    {
        // Not found here
        success = false;
        return NULL;
    }
    if (subTreePtr->getItem() == target)
    {
        // Item is in the root of some subtree
        subTreePtr = removeNode(subTreePtr);
        success = true;
        return subTreePtr;
    }
    else
    {
        if (subTreePtr->getItem() > target)
            // Search the left subtree
            subTreePtr->setLeftChildPtr(removeValue(subTreePtr->getLeftChildPtr(), target, success));
        else
            // Search the right subtree
            subTreePtr->setRightChildPtr(removeValue(subTreePtr->getRightChildPtr(), target, success));

        return subTreePtr;
    }  // end if
}  // end removeValue

/** removes specfied child pointer
 */
template<class ItemType>
BinaryNode<ItemType>* removeNode(BinaryNode<ItemType>* ChildNodePtr){
    BinaryNode<ItemType>* nodeToConnectPtr = ChildNodePtr->getRightChildPtr();
    delete ChildNodePtr;
    ChildNodePtr = NULL;
    return nodeToConnectPtr;
}


template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeNode(BinaryNode<ItemType>* nodePtr){
    if (nodePtr->isLeaf()){
        delete nodePtr;
        return (nodePtr = NULL);
    }
    else if (nodePtr->getLeftChildPtr() == NULL)  // Has rightChild only
    {
        //return removeChildNode(nodePtr->getRightChildPtr());
        BinaryNode<ItemType>* nodeToConnectPtr = nodePtr->getRightChildPtr();
        delete nodePtr;
        nodePtr = NULL;
        return nodeToConnectPtr; /**/
    }
    else if (nodePtr->getRightChildPtr() == NULL) // Has left child only
    {
        //return removeChildNode(nodePtr->getLeftChildPtr());
        /* */BinaryNode<ItemType>* nodeToConnectPtr = nodePtr->getLeftChildPtr();
        delete nodePtr;
        nodePtr = NULL;
        return nodeToConnectPtr;   /**/
    }
    else                                             // Has two children
    {
        // Traditional way to remove a value in a node with two children
        ItemType newNodeValue;
        nodePtr->setRightChildPtr(removeLeftmostNode(nodePtr->getRightChildPtr(), newNodeValue));
        nodePtr->setItem(newNodeValue);
        return nodePtr;


    }  // end if
}  // end removeNode

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeLeftmostNode(BinaryNode<ItemType>* nodePtr,
                                                                     ItemType& inorderSuccessor)
{
    if (nodePtr->getLeftChildPtr() == NULL)
    {
        inorderSuccessor = nodePtr->getItem();
        return removeNode(nodePtr);
    }
    else
    {
        nodePtr->setLeftChildPtr(removeLeftmostNode(nodePtr->getLeftChildPtr(), inorderSuccessor));
        return nodePtr;
    }  // end if
}  // end removeLeftmostNode



/// Override  the findNode for binary search
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::findNode(BinaryNode<ItemType>* subTreePtr,
                                                           const ItemType& target) const
{
    /// Uses a binary search
    if (subTreePtr == NULL)
        return NULL;                        // Not found
    else if (subTreePtr->getItem() == target)
        return subTreePtr;                     // Found
    else if (subTreePtr->getItem() > target)
        /// Search left subtree
        return findNode(subTreePtr->getLeftChildPtr(), target);
    else
        /// Search right subtree
        return findNode(subTreePtr->getRightChildPtr(), target);
}  // end findNode


template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree() : rootPtr(NULL)
{
}  // end default constructor

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType& rootItem)
{
    rootPtr = new BinaryNode<ItemType>(rootItem, NULL, NULL);
}  // end constructor

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const BinarySearchTree<ItemType>& treePtr)
{
    rootPtr = this->copyTree(treePtr.rootPtr); // Call inherited method
}  // end copy constructor

template<class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree()
{
    this->destroyTree(rootPtr); // Call inherited method
}  // end destructor


template<class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const
{
    return rootPtr == NULL;
}  // end isEmpty

template<class ItemType>
int BinaryNodeTree<ItemType>::getHeightHelper(BinaryNode<ItemType>* subTreePtr) const
{
    if (subTreePtr == nullptr)
        return 0;
    else
        return 1 + max(getHeightHelper(subTreePtr->getLeftChildPtr()),getHeightHelper(subTreePtr->getRightChildPtr()));

} // end getHeightHelper

template<class ItemType>
int BinarySearchTree<ItemType>::getHeight() const
{
    return this->getHeightHelper(rootPtr); // Call inherited method
}  // end getHeight

template<class ItemType>

int BinaryNodeTree<ItemType>::getNumberOfNodesHelper(BinaryNode<ItemType>* subTreePtr) const

{
    if (subTreePtr == nullptr)
        return 0;
    else
        return 1 + getNumberOfNodesHelper(subTreePtr->getLeftChildPtr()) + getNumberOfNodesHelper(subTreePtr->getRightChildPtr());

} // end getNumberOfNodesHelper

template<class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes() const
{
    return this->getNumberOfNodesHelper(rootPtr); // Call inherited method
}  // end getNumberOfNodes

template<class ItemType>
void BinarySearchTree<ItemType>::clear()
{
    this->destroyTree(rootPtr); // Call inherited method
    rootPtr = NULL;
}  // end clear

template<class ItemType>
ItemType BinarySearchTree<ItemType>::getRootData() const
{
    if (isEmpty())
        cout << "getRootData() called with empty tree." << endl;


    return rootPtr->getItem();
}  // end getRootData

// Must override setRootData to disable its affect:
template<class ItemType>
void BinarySearchTree<ItemType>::setRootData(const ItemType& newItem) const
{
    cout << "Cannot change root value in a BST!" << endl;
    //throw PrecondViolatedExcep("Cannot change root value in a BST!");
}  // end setRootData

template<class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType& newData)
{
    BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(newData);
    rootPtr = placeNode(rootPtr, newNodePtr);

    return true;
}  // end add

template<class ItemType>
bool BinarySearchTree<ItemType>::remove(const ItemType& target)
{
    bool isSuccessful = false;
    rootPtr = removeValue(rootPtr, target, isSuccessful);
    return isSuccessful;
}  // end remove

// Override getEntry to use our improved findNode:
template<class ItemType>
ItemType BinarySearchTree<ItemType>::getEntry(const ItemType& anEntry) const  /// throw(NotFoundException)
{
    BinaryNode<ItemType>* nodeWithEntry = findNode(rootPtr, anEntry);
    if (nodeWithEntry == NULL){
        cout << "Entry not found in tree." << endl;
    } // else
    return nodeWithEntry->getItem();
}  // end getEntry

template<class ItemType>
bool BinarySearchTree<ItemType>::contains(const ItemType& anEntry) const
{

    return findNode(rootPtr, anEntry);
}  // end contains

/// prints subtree that is in T order
template <class ItemType>
void BinarySearchTree<ItemType>::printTree( BinaryNode<ItemType> *t ) const
{
    if( t != NULL )
    {
        printTree( t-> getLeftChildPtr() );
        cout << t-> getItem() << endl;
        printTree( t-> getRightChildPtr() );
    }
}

template<class ItemType>
void BinarySearchTree<ItemType>::preorderTraverse(void visit(ItemType&)) const
{
    this->preorder(visit, rootPtr); /// Call inherited method
}  /// end preorderTraverse

template<class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse(void visit(ItemType&)) const
{
    this->inorder(visit, rootPtr); /// Call inherited method
}  /// end inorderTraverse

template<class ItemType>
void BinarySearchTree<ItemType>::postorderTraverse(void visit(ItemType&)) const
{
    this->postorder(visit, rootPtr); // Call inherited method
}  // end postorderTraverse




template<class ItemType>
BinarySearchTree<ItemType>& BinarySearchTree<ItemType>::
operator=(const BinarySearchTree<ItemType>& rightHandSide)
{
    if (!isEmpty())
        clear();
    this = copyTree(&rightHandSide); // Call inherited method

    return *this;
}  /// end operator= overload

#endif //PROJECT6_BINARYSEARCHTREE_H
