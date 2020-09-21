/*
 * File:   PriorityQueue.h
 * Author: Renat Norderhaug
 *
 * Created on April 7, 2018, 11:45 PM
 */

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "SortedList.h"

template <class ItemType>
class PriorityQueue  {
private:
    SortedList<ItemType> *slistPtr;

public:
    PriorityQueue();

    PriorityQueue(const PriorityQueue &pq);

    ~PriorityQueue();

    bool isEmpty() const;

    bool add(const ItemType &newEntry);

    bool remove();
    ItemType peek() const;
};

template<class ItemType>
PriorityQueue<ItemType>::PriorityQueue() {
    slistPtr = new SortedList<ItemType>();
}

template<class ItemType>
PriorityQueue<ItemType>::~PriorityQueue() {
    while (!isEmpty()) {
        remove();
    }
}

template<class ItemType>
bool PriorityQueue<ItemType>::add(const ItemType &newEntry) {
    slistPtr->insertSorted(newEntry);
    return true;
}

template<class ItemType>
bool PriorityQueue<ItemType>::remove() {
    return slistPtr->remove(1);
}

template<class ItemType>
ItemType PriorityQueue<ItemType>::peek() const {
    return slistPtr->getEntry(1);
}

template<class ItemType>
bool PriorityQueue<ItemType>::isEmpty() const {
    return slistPtr->isEmpty();
}

#endif // PRIORITY_QUEUE_H
