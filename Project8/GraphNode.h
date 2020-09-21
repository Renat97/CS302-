//
// Created by Renat Norderhaug on 5/16/18.
//

#ifndef PROJECT8_GRAPHNODE_H
#define PROJECT8_GRAPHNODE_H



#include <iostream>
class GraphNode
{
    /// declares friend classes for Graph and NodeQueue
    friend class Graph;
    friend class NodeQueue;
private:
    GraphNode* next;
    std::string item;
    int weight;

public:
    GraphNode();
    ~GraphNode();
    GraphNode(int i);
};


#endif //PROJECT8_GRAPHNODE_H
