 #ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <stack>
#include <string>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <limits>
#include <list>

using namespace std;

//enum for the status of a node
enum Status {
    NOT_VISITED,
    VISITED
};

//forward declaration
class node;


//An object of this class represents an edge in the graph.
class edge
{
private:
    node *orgNode;//the originating vertex
    node *dstNode;//the destination vertex
    unsigned cost;//cost of the edge

public:
    edge(node *firstNode, node *secNode, unsigned inCost)
    {
        orgNode = firstNode;
        dstNode = secNode;
        cost = inCost;
    }

    node* getDstNode()
    {
        return dstNode;
    }

    node* getOrgNode()
    {
        return orgNode;
    }

    unsigned getCost()
    {
        return cost;
    }
};

//An object of this class holds a vertex of the graph
class node
{
private:
    string name;
    unsigned value;
    int x,y;
    vector<edge> adjNodeList;//list of outgoing edges for this vertex
    node* previous;
    enum Status status;//used in dfs to mark the node visited

public:
node(string id,int u,int o)
{
    name = id;
    x=u;
    y=o;
    status = NOT_VISITED;
}

//do not del the adj nodes here...they will be deleted by graph destructor
~node()
{
    adjNodeList.clear();
}
int getX()
{
    return x;
}
int getY()
{
    return y;
}
enum Status getStatus()
{
    return status;
}

void setStatus(enum Status st)
{
    status = st;
}


unsigned getValue()
{
    return value;
}

void setValue(unsigned x)
{
    value = x;
}

node* getPrevious()
{
    return previous;
}

void setPrevious(node* x)
{
    previous = x;
}

string getName()
{
    return name;
}

void addAdjnodes(node *adj, unsigned cost)
{
//create an edge with 'this' as the originating node and adj as the destination node
    edge newEdge(this, adj, cost);
    adjNodeList.push_back(newEdge);
}

vector<edge>& getAdjNodeList()
{
    return adjNodeList;
}
//An object of class graph holds a directed graph
class graph
{
private:
    vector<node*> nodeList;//list of verticies
    bool foundCycle;//true if a cycle is found, false otherwise
    int desiredCycSize;

void clearVisited()
{
    for(int i = 0; i < nodeList.size() && !foundCycle ; i++)
    {
        nodeList[i]->setStatus(NOT_VISITED);
    }
}


public:
void addNewNode(node *nNode)
{
    nodeList.push_back(nNode);
}

node* findNodeByName(string name)
{
    for(int i = 0 ; i < nodeList.size() ; i++)
    {
        if(nodeList[i]->getName() == name)
        return nodeList[i];
    }
    return NULL;
}

    graph()
    {
        foundCycle = false;
    }

~graph()
{
    //free mem allocated to verticies
    for(int i=0 ; i < nodeList.size() ; i++)
        delete nodeList[i];
    nodeList.clear();
}

list<node*>::iterator findMin( list<node*>::iterator first, list<node*>::iterator last )
{
    if(first== last) return last;
    list<node*>::iterator smallest = first;

    while (++first != last)
        if ((*first)->getValue() < (*smallest)->getValue())    // or: if (comp(*first,*smallest)) for version (2)
          smallest = first;
    return smallest;
}

list<node*> oneSourceAllDestination(string src)
{
    list<node*> unvisited(nodeList.begin(),nodeList.end());
    list<node*> visited;

    unsigned INF = numeric_limits<unsigned>::max();

    for (int i = 0; i < nodeList.size(); i++)
    {
        if(src == nodeList[i]->getName())
        {
            nodeList[i]->setValue(0);
        }
        else
        {
            nodeList[i]->setValue(INF);
        }
    }
    while (!unvisited.empty())
    {
        list<node*>::iterator itr = findMin(unvisited.begin(), unvisited.end());
        node* min = *itr;
        if (min->getValue() == 0)
        {
            min->setPrevious(NULL);
        }
        for (int i = 0; i < min->getAdjNodeList().size(); i++)
        {
            if (min->getAdjNodeList()[i].getDstNode()->getStatus() == NOT_VISITED)
            {
                // found
                if ((min->getValue() + min->getAdjNodeList()[i].getCost()) < min->getAdjNodeList()[i].getDstNode()->getValue())
                {
                    min->getAdjNodeList()[i].getDstNode()->setValue(min->getValue() + min->getAdjNodeList()[i].getCost());
                    min->getAdjNodeList()[i].getDstNode()->setPrevious(min);
                }
            }

        }
        min->setStatus(VISITED);
        visited.push_front(min);
        unvisited.remove(min);
    }
    return visited;
}

list<node*> Destination(string dst,list<node*> shortestPaths)
{
    stack<node*> help;
    list<node*> shortestPath;
    for (list<node*>::iterator i = shortestPaths.begin(); i != shortestPaths.end(); i++)
    {
        if(dst == (*i)->getName())
        {
            help.push(*i);
            node* previous = (*i)->getPrevious();
            while (previous != NULL)
            {
                help.push(previous);
                previous = previous->getPrevious();
            }
            while (!help.empty())
            {
                shortestPath.push_back(help.top());
                help.pop();
            }
            return shortestPath;
        }
    }
}
vector<node *>getVec()
{
    return nodeList;
}
};
#endif
