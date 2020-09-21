/*
 * File:   LinkedQueue.h
 * Author: Renat Norderhaug
 *
 * Created on April 7, 2018, 11:20 PM
 */

#ifndef LINKEDQUEUE_H_INCLUDED
#define LINKEDQUEUE_H_INCLUDED

#include "Node.h"

/*The queue is implemented as a chain of linked nodes that has
two external pointers, a head pointer for front of the queue and
a tail pointer for the back of the queue.*/

template<class ItemType>
class LinkedQueue  {
private:
    Node<ItemType> *backPtr;
    Node<ItemType> *frontPtr;

public:
    LinkedQueue();

    LinkedQueue(const LinkedQueue &aQueue);

    ~LinkedQueue();

    bool isEmpty() const;

    bool enqueue(const ItemType &newEntry);

    bool dequeue();

    ItemType peekFront() const;
};


template<class ItemType>
LinkedQueue<ItemType>::LinkedQueue() : backPtr(nullptr), frontPtr(nullptr) {}

template<class ItemType>
LinkedQueue<ItemType>::~LinkedQueue() {
    while (!isEmpty()) {
        dequeue();
    }
}

template<class ItemType>
bool LinkedQueue<ItemType>::enqueue(const ItemType &newEntry) {
    Node<ItemType> *newNodePtr = new Node<ItemType>(newEntry);

    if (isEmpty())
        frontPtr = newNodePtr;        // Insertion into empty queue
    else
        backPtr->setNext(newNodePtr); // Insertion into nonempty queue

    backPtr = newNodePtr;            // New node is at back

    return true;
}

template<class ItemType>
bool LinkedQueue<ItemType>::dequeue() {
    bool result = false;
    if (!isEmpty()) {
        Node<ItemType> *nodeToDeletePtr = frontPtr;
        if (frontPtr == backPtr) {  // Special case: one node in queue
            frontPtr = nullptr;
            backPtr = nullptr;
        } else
            frontPtr = frontPtr->getNext();

        nodeToDeletePtr->setNext(nullptr);
        delete nodeToDeletePtr;
        nodeToDeletePtr = nullptr;

        result = true;
    }

    return result;
}

template<class ItemType>
bool LinkedQueue<ItemType>::isEmpty() const {
    return frontPtr == nullptr;
}

template<class ItemType>
ItemType LinkedQueue<ItemType>::peekFront() const {
    return frontPtr->getItem();
}

#endif // LINKEDQUEUE_H_INCLUDED
