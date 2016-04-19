
/*
* This file has declarations for classes used to represent the graph
*/

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
class Node;


//An object of this class represents an edge in the graph.
class Edge
{
private:
	Node *orgNode;//the originating vertex
	Node *dstNode;//the destination vertex
	unsigned cost;//cost of the edge

public:
	Edge(Node *firstNode, Node *secNode, unsigned inCost)
	{
		orgNode = firstNode;
		dstNode = secNode;
		cost = inCost;
	}

	Node* getDstNode()
	{
		return dstNode;
	}

	Node* getOrgNode()
	{
		return orgNode;
	}

	unsigned getCost()
	{
		return cost;
	}
};

//An object of this class holds a vertex of the graph
class Node
{
private:
	string name;
	unsigned value;
	int x,y;
	vector<Edge> adjNodeList;//list of outgoing edges for this vertex
	Node* previous;
	enum Status status;//used in dfs to mark the node visited

public:
Node(string id)
{
	name = id;
	status = NOT_VISITED;
}

//do not del the adj nodes here...they will be deleted by graph destructor
~Node()
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

Node* getPrevious()
{
	return previous;
}

void setPrevious(Node* x)
{
	previous = x;
}


string getName()
{
	return name;
}

void addAdjNode(Node *adj, unsigned cost)
{
//create an edge with 'this' as the originating node and adj as the destination node
	Edge newEdge(this, adj, cost);
	adjNodeList.push_back(newEdge);
}

vector<Edge>& getAdjNodeList()
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
class Graph
{
private:
	vector<Node*> nodeList;//list of verticies
	bool foundCycle;//true if a cycle is found, false otherwise
	int desiredCycSize;

void clearVisited()
{
	for(int i = 0; i < nodeList.size() && !foundCycle ; i++)
	{
		nodeList[i]->setStatus(NOT_VISITED);
	}	
}

void addNewNode(Node *nNode)
{
	nodeList.push_back(nNode);
}

Node* findNodeByName(string name)
{
	for(int i = 0 ; i < nodeList.size() ; i++)
	{
		if(nodeList[i]->getName() == name)
		return nodeList[i];
	}
	return NULL;
}

public:
	Graph()
	{
		foundCycle = false;
	}

~Graph()
{
	//free mem allocated to verticies
	for(int i=0 ; i < nodeList.size() ; i++)
		delete nodeList[i];
	nodeList.clear();
}


void displayGraph()
{
	for(int i=0 ; i < nodeList.size() ; i++)
	{
		nodeList[i]->displayList();
	}
}

list<Node*>::iterator findMin( list<Node*>::iterator first, list<Node*>::iterator last )
{
	if(first== last) return last;
	list<Node*>::iterator smallest = first;

	while (++first != last)
		if ((*first)->getValue() < (*smallest)->getValue())    // or: if (comp(*first,*smallest)) for version (2)
		  smallest = first;
	return smallest;
}


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
		Node *u = findNodeByName(fromCity);
		if(u == NULL)
		{
			u = new Node(fromCity);
			addNewNode(u);
		}

		//find if a vertex for the city already exists, if so get that
		Node *v = findNodeByName(toCity);
		if(v == NULL)
		{
			v = new Node(toCity);
			addNewNode(v);
		}

		u->addAdjNode(v,cost);
		v->addAdjNode(u,cost);
	}
}

list<Node*> oneSourceAllDestination(string src)
{
	list<Node*> unvisited(nodeList.begin(),nodeList.end());
	list<Node*> visited;

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
		list<Node*>::iterator itr = findMin(unvisited.begin(), unvisited.end());
		Node* min = *itr;
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

list<Node*> Destination(string dst,list<Node*> shortestPaths)
{
	stack<Node*> help;
	list<Node*> shortestPath;
	for (list<Node*>::iterator i = shortestPaths.begin(); i != shortestPaths.end(); i++)
	{
		if(dst == (*i)->getName())
		{
			help.push(*i);
			Node* previous = (*i)->getPrevious();
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

};
