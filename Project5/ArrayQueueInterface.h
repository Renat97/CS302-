/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QueueInterface.h
 * Author: Renat Norderhaug
 *
 * Created on April 5, 2018, 9:17 PM
 */

#ifndef QUEUEINTERFACE_H
#define QUEUEINTERFACE_H
#include <cstdlib>
#include <iostream>
using namespace std;

template <class T>
class QueueInterface {
public:
    // pure virtual function empty
   virtual bool empty() const = 0;
    // pure virtual function push
     virtual void enqueue(const T& newEntry) = 0;
    // pure virtual function pop
     virtual void dequeue() = 0;
    // pure virtual function front
     virtual T front() = 0;
    //display function
     virtual void display() = 0;    
    
};



#endif /* QUEUEINTERFACE_H */

