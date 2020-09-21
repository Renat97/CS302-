//
// Created by Renat Norderhaug on 4/19/18.
//

#ifndef PROJECT6_BINARYTREEINTERFACE_H
#define PROJECT6_BINARYTREEINTERFACE_H

template<class ItemType>
class BinaryTreeInterface {
public:
    /// tests if tree is empty
    virtual bool isEmpty() const = 0;
    /// returns height of tree
    virtual int getHeight() const = 0;
    /// returns number of nodes in tree
    virtual int getNumberOfNodes() const = 0;
    /// returns the data in the root
    virtual ItemType getRootData() const = 0;
    /// defines the data in the root
    virtual void setRootData(const ItemType& newData) = 0;
    /// adds a new node
    virtual bool add(const ItemType& newData) = 0;
    /// remove the data
    virtual bool remove(const ItemType& data) = 0;
    /// clears the tree
    virtual void clear() = 0;
    /// returns an entry
    //virtual ItemType getEntry(const ItemType& anEntry) = 0;

    virtual bool contains(const ItemType& anEntry) const = 0;

    virtual void preorderTraverse(void visit(ItemType&)) const = 0;

    virtual void inorderTraverse(void visit(ItemType&)) const = 0;

    virtual void postorderTraverse(void visit(ItemType&)) const = 0;


};

#endif //PROJECT6_BINARYTREEINTERFACE_H
