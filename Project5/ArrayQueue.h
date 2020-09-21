/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Queue.h
 * Author: renatnorderhaug
 *
 * Created on April 7, 2018, 9:28 PM
 */

#ifndef QUEUE_H
#define QUEUE_H
#include <cstdlib>
#include <iostream>
#include "QueueInterface.h"
using namespace std;

template <class T>
class myQueue : public QueueInterface<T>
{
    int MaxQueue = 100;
    private:
        /// array holding queue data
        T data[100];
        /// front of queue
        int qFront;
        /// back of queue
        int qBack;
        /// counter for the queue
        int counter;
        
        public:
          // constructor
            myQueue() {
                qFront = 0;
                qBack = MaxQueue - 1;
                counter = 0;
  
            }
          // empty queue
            bool empty() const {
                return counter == 0;
            }
            // push for queue
            void enqueue(const T &newEntry) {
                if( counter < MaxQueue) {
                    qBack = (qBack + 1) % MaxQueue;
                    data[qBack] = newEntry;
                    counter++;
                }      
            }
            //pop
            void dequeue() {
                if (!empty()) {
                   qFront = (qFront + 1) % MaxQueue;
                   counter --;
                }
            }
            // front
            T front() {
                if (!empty())
                    return data[qFront];
                
            }
            // display the queue
            void display() {
                T data;
                // creates a new queue
                myQueue* tempQueue = new myQueue();
                while(!this -> empty()) {
                    data = this ->front();
                    this-> pop();
                    //push data into temp queue
                    tempQueue->push(data);
                    // display queue data
                    cout<< data << " ";
                }
                cout << endl;
                
                // temporary queue isnt empty
                while(!tempQueue->empty()) {
                    this->push(tempQueue->front());
                    // delete data in temp queue
                    tempQueue ->pop();
                }
            }
};



#endif /* QUEUE_H */

