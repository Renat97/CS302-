/*
 * File:   SortedList.h
 * Author: renatnorderhaug
 *
 * Created on April 4, 2018, 11:35 PM
 */

#ifndef SORTEDLIST_H_INCLUDED
#define SORTEDLIST_H_INCLUDED

#include "Node.h"

template<class ItemType>
class SortedList {
private:
    Node<ItemType> *headPtr;
    int itemCount;

    Node<ItemType> *getNodeBefore(const ItemType &anEntry) const;

    Node<ItemType> *getNodeAt(int position) const;

    Node<ItemType> *copyChain(const Node<ItemType> *origChainPtr);

public:
    SortedList();

    SortedList(const SortedList<ItemType> &aList);

    virtual ~SortedList();

    void insertSorted(const ItemType &newEntry);

    bool removeSorted(const ItemType &anEntry);

    int getPosition(const ItemType &newEntry);

    bool isEmpty() const;

    int getLength() const;

    bool remove(int position);

    void clear();

    ItemType getEntry(int position) const;
};
#include <cassert>

template<class ItemType>
SortedList<ItemType>::SortedList(): headPtr(nullptr), itemCount(0) {}

template<class ItemType>
SortedList<ItemType>::SortedList(const SortedList<ItemType> &aList) {
    headPtr = copyChain(aList.headPtr);
}

template<class ItemType>
void SortedList<ItemType>::insertSorted(const ItemType &newEntry)

{
    Node<ItemType> *newNodePtr = new Node<ItemType>(newEntry);
    Node<ItemType> *prevPtr = getNodeBefore(newEntry);

    if (isEmpty() || (prevPtr == nullptr))
    {
        newNodePtr->setNext(headPtr);
        headPtr = newNodePtr;
    } else
    {
        Node<ItemType> *aftPtr = prevPtr->getNext();
        newNodePtr->setNext(aftPtr);
        prevPtr->setNext(newNodePtr);
    }

    itemCount++;
}


template<class ItemType>
Node<ItemType> *SortedList<ItemType>::copyChain(const Node<ItemType> *origChainPtr) {
    Node<ItemType> *copiedChainPtr;
    if (origChainPtr == nullptr) {
        copiedChainPtr = nullptr;
    } else {
        copiedChainPtr = new Node<ItemType>(origChainPtr->getItem());
        copiedChainPtr->setNext(copyChain(origChainPtr->getNext()));
    }

    return copiedChainPtr;
}

template<class ItemType>
Node<ItemType> *SortedList<ItemType>::getNodeBefore(const ItemType &anEntry) const {
    Node<ItemType> *curPtr = headPtr;
    Node<ItemType> *prevPtr = nullptr;

    while ((curPtr != nullptr) && (anEntry > curPtr->getItem())) {
        prevPtr = curPtr;
        curPtr = curPtr->getNext();
    }

    return prevPtr;
}


template<class ItemType>
SortedList<ItemType>::~ SortedList() {
    clear();
}


template<class ItemType>
bool SortedList<ItemType>::removeSorted(const ItemType &anEntry)
{
    return remove(getPosition(anEntry));
}

template<class ItemType>
int SortedList<ItemType>::getPosition(const ItemType &anEntry)

{
    Node<ItemType> *curr = headPtr;
    int pos = 1;
    while (curr != nullptr && !(anEntry == curr->getItem())) {
        pos++;
        curr = curr->getNext();

    }
    return pos;
}


template<class ItemType>
bool SortedList<ItemType>::isEmpty() const
{
    return headPtr == nullptr;
}

template<class ItemType>
int SortedList<ItemType>::getLength() const
{
    return itemCount;
}

template<class ItemType>
bool SortedList<ItemType>::remove(int position)
{
    Node<ItemType> *prev = getNodeBefore(getEntry(position));
    Node<ItemType> *curr;
    if (prev == nullptr) {
        curr = headPtr;
        headPtr = curr->getNext();
    } else {
        curr = prev->getNext();
        prev->setNext(curr->getNext());
    }
    itemCount--;
    delete curr;
    return true;
}

template<class ItemType>
void SortedList<ItemType>::clear()
{
    while (!isEmpty())
        remove(1);
}

template<class ItemType>
ItemType SortedList<ItemType>::getEntry(int position) const
{
    Node<ItemType> *curr = headPtr;
    while (position > 1) {
        curr = curr->getNext();
        position--;
    }
    return curr->getItem();
}

template<class ItemType>
Node<ItemType> *SortedList<ItemType>::getNodeAt(int position) const {
    Node<ItemType> *curr = headPtr;
    while (position > 1) {
        curr = curr->getNext();
        position--;
    }
    return curr;
}

#endif // SORTEDLIST_H_INCLUDED
