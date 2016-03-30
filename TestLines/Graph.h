#pragma once
#include <vector>
#include <stack> // DFS Open List
#include <queue>
#include <list>
#include <iostream>
#include <set>


class Graph
{
public:
	// predefine classes
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
	std::stack<Graph::Node *> frontier; // open
	std::set <Graph::Node *> explored; // closed

	//Instructions: Put starting node on stack while it isn't empty, print the top node's value, pop node from frontier, push node to explored, for each neighbor, if neighbor hasn't been explored, push neighbor to frontier

	frontier.push(startNode); // Put node on stack
	while (!frontier.empty()) // While stack is not empty
	{
		auto current = frontier.top(); // set current variable to top of the stack (startNode in this case)
		std::cout << current->value << " "; // Print top node value
		frontier.pop(); // pop startNode from the stack
		explored.insert(current); // push startNode to set

		for each(auto e in current->connections) //for each neighbor, push neighbor to frontier
		{
			if (explored.count(e.connection)) // if neighbor hasn't been explored
			{
				frontier.push(e.connection);
			}
		}
	}
	
	
	
	
}