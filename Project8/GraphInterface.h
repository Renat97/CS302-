//
// Created by Renat Norderhaug on 5/16/18.
//

#ifndef _GRAPH_INTERFACE
#define _GRAPH_INTERFACE

template<class LabelType>
class GraphInterface
{
public:

    virtual int getNumVertices() const = 0;


    virtual int getNumEdges() const = 0;


    virtual bool addVertex(LabelType s) = 0;


    virtual void addEdge(LabelType start, LabelType end, int edgeWeight) = 0;


    virtual bool removeEdge(LabelType start, LabelType end) = 0;


    virtual int getEdgeWeight(LabelType start, LabelType end)  = 0;


    virtual void depthFirstTraversal(LabelType start, void visit(LabelType&)) = 0;

    virtual void breathFirstTraversal(LabelType start, void visit(LabelType&)) = 0;
};

#endif //PROJECT8_GRAPHINTERFACE_H
