//
// Created by Renat Norderhaug on 4/17/18.
//

#ifndef PROJECT6_BINARYNODE_H
#define PROJECT6_BINARYNODE_H

template<class ItemType>
class BinaryNode {
private:
    ItemType item;           /// Data of the node
    BinaryNode<ItemType> *leftChildPtr;   /// Pointer to left child
    BinaryNode<ItemType> *rightChildPtr;  /// Pointer to right child

public:
    BinaryNode();
    BinaryNode(const ItemType &anItem);
    BinaryNode(const ItemType &anItem,
               BinaryNode<ItemType> *leftPtr,
               BinaryNode<ItemType> *rightPtr);

    void setItem(const ItemType &anItem);
    ItemType getItem() const;
    bool isLeaf() const;
    void setLeftChildPtr(BinaryNode<ItemType> *leftPtr);
    void setRightChildPtr(BinaryNode<ItemType> *rightPtr);
    BinaryNode<ItemType> *getLeftChildPtr() const;
    BinaryNode<ItemType> *getRightChildPtr() const;
};

template <class ItemType>
BinaryNode <ItemType> :: BinaryNode()
{
    item = nullptr;
    leftChildPtr = nullptr;
    rightChildPtr = nullptr;
}

/// parameterized constructor
template <class ItemType>
BinaryNode <ItemType> :: BinaryNode(const ItemType& anItem)
{
    item = anItem;
    leftChildPtr = nullptr;
    rightChildPtr = nullptr;
}

template <class ItemType>
BinaryNode <ItemType> :: BinaryNode(const ItemType& anItem,	BinaryNode<ItemType>* leftPtr,
                                    BinaryNode<ItemType>* rightPtr)
{
    item = anItem;
    leftChildPtr = leftPtr;
    rightChildPtr = rightPtr;
}

template <class ItemType>
void BinaryNode <ItemType> :: setItem(const ItemType& anItem)
{
    item = anItem;
}

// getItem method

template <class ItemType>
ItemType BinaryNode <ItemType> :: getItem() const
{
    return item;
}

/// is leaf method to check if item is leaf, or not

template <class ItemType>
bool BinaryNode <ItemType> :: isLeaf() const
{
    return leftChildPtr == nullptr || rightChildPtr == nullptr;
}

template <class ItemType>
void BinaryNode <ItemType> :: setLeftChildPtr(BinaryNode<ItemType>* leftPtr)
{
    leftChildPtr = leftPtr;
}

template <class ItemType>
void BinaryNode <ItemType> :: setRightChildPtr(BinaryNode<ItemType>* rightPtr)
{
    rightChildPtr = rightPtr;
}

template <class ItemType>
BinaryNode<ItemType>* BinaryNode <ItemType> :: getLeftChildPtr() const
{
    return leftChildPtr;
}

template <class ItemType>
BinaryNode<ItemType>* BinaryNode <ItemType> :: getRightChildPtr() const
{
    return rightChildPtr;
}


#endif //PROJECT6_BINARYNODE_H
