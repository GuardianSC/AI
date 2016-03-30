#pragma once
#include <vector>
#include <stack> // DFS Open List
#include <queue>
#include <list>
#include <iostream>
#include <set>

struct Vector2
{
	float x, y;
	Vector2() {}
	Vector2(float x, float y) : x(x), y(y) {}
};

class Graph
{
public:
	// predefine classes                        dos = Degree of Separation
	struct Node;
	struct Edge
	{
		Node *connection;
		// default constructor
		Edge() : connection(NULL) { }
		// overloaded construct
		Edge(Node *node) : connection(node) { }
	};
	struct Node
	{
		int value;
		std::vector< Graph::Edge > connections;
		// default constructor
		Node() : value(0) {}
		// overloaded constructor
		Node(int val) : value(val) {}
	};
	~Graph()
	{
		// make sure to delete all nodes added to the graph
		for (auto iter = m_nodes.begin(); iter != m_nodes.end(); iter++)
			delete (*iter);
		m_nodes.clear();
	}
	Node *AddNode(int value)
	{
		m_nodes.push_back(new Node(value));
		return m_nodes.back();
	}
	void AddConnection(Node *n1, Node *n2)
	{
		n1->connections.push_back(Edge(n2));
		n2->connections.push_back(Edge(n1));
	}
private:
	std::vector< Node * > m_nodes;
};

inline void printDFS(Graph::Node *startNode)
{
	std::list<Graph::Node *> frontier; // open
	std::set <Graph::Node *> explored; // closed

	frontier.push_front(startNode); // Put node on list (frontier)
	explored.insert(startNode);
	while (!frontier.empty()) // While stack is not empty
	{
		auto current = frontier.front(); // set current variable to top of the stack (startNode in this case)
		std::cout << (char)current->value << " "; // Print top node value
		frontier.pop_front(); // pop startNode from the stack
		explored.insert(current); // push startNode to set

		for each(Graph::Edge e in current->connections) //for each neighbor, push neighbor to frontier
		{
			if (!explored.count(e.connection) ) // if neighbor hasn't been explored
			{
				frontier.push_front(e.connection); // push neighbor to frontier
				explored.insert(e.connection);
			}
		}
	}
}

inline void printBFS(Graph::Node *startNode)
{
	std::queue<Graph::Node *> frontier; // open
	std::set <Graph::Node *> explored; // closed

	frontier.push(startNode); // 
	explored.insert(startNode);
	while (!frontier.empty()) // 
	{
		auto current = frontier.front(); // 
		std::cout << (char)current->value << " "; // 
		frontier.pop(); // 

		for each(Graph::Edge e in current->connections) //
		{
			if (!explored.count(e.connection)) // 
			{
				frontier.push(e.connection); // 
				explored.insert(e.connection);
			}
		}
	}
}