/*
### Task 4 : Moving Smart Pointers

In files `chatlogic.h` / `chatlogic.cpp` and `graphnode.h` / `graphnode.cpp` change the ownership of all instances of `GraphEdge`
in a way such that each instance of `GraphNode` exclusively owns the outgoing `GraphEdges` and holds non-owning references to
incoming `GraphEdges`.
Use appropriate smart pointers and where required, make changes to the code such that data structures and function parameters reflect the changes.
When transferring ownership from class `ChatLogic`, where all instances of `GraphEdge` are created, into instances of `GraphNode`, make sure to use move semantics.

My Summary
GraphNode owns unique_ptr for GraphEdge children (not parents) (parents will be raw pointer).
std::move required for ChatLogic to give edges to nodes.
*/

#ifndef GRAPHEDGE_H_
#define GRAPHEDGE_H_

#include <vector>
#include <string>

class GraphNode; // forward declaration

class GraphEdge
{
private:
    // data handles (not owned)
    GraphNode *_childNode;
    GraphNode *_parentNode;

    // proprietary members
    int _id;
    std::vector<std::string> _keywords; // list of topics associated with this edge
    

public:
    // constructor / desctructor
    GraphEdge(int id);

    // getter / setter
    int GetID() { return _id; }
    void SetChildNode(GraphNode *childNode);
    void SetParentNode(GraphNode *parentNode);
    GraphNode *GetChildNode() { return _childNode; }
    std::vector<std::string> GetKeywords() { return _keywords; }

    // proprietary functions
    void AddToken(std::string token);
};

#endif /* GRAPHEDGE_H_ */