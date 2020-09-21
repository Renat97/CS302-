//
// Created by Renat Norderhaug on 5/16/18.
//

#ifndef PROJECT8_NODEQUEUE_H
#define PROJECT8_NODEQUEUE_H



#include "GraphNode.h"
#include <string>
class NodeQueue
{
private:
    struct Queue
    {
        Queue *next = NULL;
        int weight;
        GraphNode *node = NULL;
    };
    Queue *root = NULL;
    int SIZE;
public:
    NodeQueue();
    ~NodeQueue();
    bool push(GraphNode*);
    GraphNode* top();
    GraphNode* pop();
    void printQueue();
    bool ifInQueue(std::string vertex);
    int printItems();
    int size();
};


#endif //PROJECT8_NODEQUEUE_H
