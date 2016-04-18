#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
enum Status{
   NOT_VISITED,
   VISITED
};
class node;
class edge
{
private:
    node *start;
    node *end;
    double cost;
public:
    edge(node *s,node *n,double c)
    {
        start =s;
        end =n;
        cost = c;
    }
    node *getstart()
    {
        return start;
    }
    node *getend()
    {
       return end;
    }
    double getcost()
    {
        return cost;
    }
};
class node
{
    string name;
    int x,y;
    vector<edge> adjnodes;
    enum Status status;
public:
    node(string id,int c,int r)
    {
        name =id;
        x =c;
        y=r;
        status =NOT_VISITED;
    }
    ~node()
    {
        adjnodes.clear();
    }
    enum Status getstatus()
    {
        return status;
    }
    void setstatus(enum Status s)
    {
          status =s;
    }
    string getname()
    {
        return name;
    }
    void addAdjnodes(node *n,double c)
    {
        edge neEd(this,n,c);
        adjnodes.push_back(neEd);
    }
    vector<edge> getAdjnodes()
    {
        return adjnodes;
    }
    int getX()
    {
       return x;
    }
    int getY()
    {
       return y;
    }

};
class graph
{
private:
    vector<node *>nodeList;
public:
    void addNewNode(node *n)
    {
        nodeList.push_back(n);

    }

node* findNodeByName(string name)
{
for(int i = 0 ; i < nodeList.size() ; i++)
{
if(nodeList[i]->getname() == name)
return nodeList[i];
}
return NULL;
}
vector<node *> getVec()
{
    return nodeList;
}
};

#endif // GRAPH_H
