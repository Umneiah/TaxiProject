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

//displays all adjacent verticies of this vertex

/*
void displayList()
{
   string edgeOp = " -> " ;
   for(int i=0 ; i < adjNodeList.size() ; i++)
   {
       Edge edg = adjNodeList[i];
       cout << name << " -> " << edg.getDstNode()->getName() << endl ;
   }
}
*/
};

//An object of class graph holds a directed graph
class graph
{
private:
   vector<node*> nodeList;//list of verticies
   list<node*>CarList;
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
void AddCarList(string s)
{
    node* n =findNodeByName(s);
    CarList.push_back(n);
}
list<node*> GetCarList()
{
    return CarList;
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


/*
void displayGraph()
{
   for(int i=0 ; i < nodeList.size() ; i++)
   {
       nodeList[i]->displayList();
   }
}
*/

list<node*>::iterator findMin( list<node*>::iterator first, list<node*>::iterator last )
{
   if(first== last) return last;
   list<node*>::iterator smallest = first;

   while (++first != last)
       if ((*first)->getValue() < (*smallest)->getValue())    // or: if (comp(*first,*smallest)) for version (2)
         smallest = first;
   return smallest;
}

/*
void createGraph()
{
   unsigned numOfCities, numOfFlights;
   //read in number of cities(TODO:in current implementation..not reqd), number of edges
   cin >> numOfCities >> numOfFlights;
   while(numOfFlights--)
   {
       string fromCity, toCity;
       unsigned cost;

       cin >> fromCity >> toCity >> cost;
       //find if a vertex for the city already exists, if so get that
       node *u = findNodeByName(fromCity);
       if(u == NULL)
       {
           u = new node(fromCity);
           addNewNode(u);
       }

       //find if a vertex for the city already exists, if so get that
       node *v = findNodeByName(toCity);
       if(v == NULL)
       {
           v = new node(toCity);
           addNewNode(v);
       }

       u->addAdjNode(v,cost);
       v->addAdjNode(u,cost);
   }
}
*/
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
int GetPathLength(list<node*> req)
{
    list<node*>::iterator i,k;
    vector<edge> edg;
    vector<edge>::iterator kk;
    int total = 0;
    for (i = req.begin();i!=req.end();++i)
    {
        k = i;
        k++;
        edg = (*i)->getAdjNodeList();
        for(kk=edg.begin();kk!=edg.end();++kk)
        {
            if(kk->getDstNode() == *k)
            {
                total += kk->getCost();
                goto opt;
            }
        }
        opt:;
    }
    return total;
}

list<node*> NearestCar(string start)
{
    string name;
    list<node*>::iterator i;
    list<node*>temp;
    string star = (*CarList.begin())->getName();
    int smallest = GetPathLength(Destination((*CarList.begin())->getName(),oneSourceAllDestination(start)));
    for(i=CarList.begin();i!=CarList.end();++i)
    {
        name = (*i)->getName();
        temp = Destination(name,oneSourceAllDestination(start));
        if (smallest > GetPathLength(temp))
        {
            smallest = GetPathLength(temp);
            star = (*i)->getName();
        }
    }
    return Destination(star,oneSourceAllDestination(start));
}

};
