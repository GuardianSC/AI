//#pragma once
//#include <vector>
//#include <stack> // DFS Open List
//#include <queue>
//#include <list>
//#include <iostream>
//#include <set>
//
//struct Vector2
//{
//	float x, y;
//	Vector2() {}
//	Vector2(float x, float y) : x(x), y(y) {}
//};
//
//template<typename T>
//class Graph
//{
//public:
//	// predefine classes
//	struct Node;
//	struct Edge
//	{
//		Node *connection;
//		// default constructor
//		Edge() : connection(NULL) { }
//		// overloaded construct
//		Edge(Node *node) : connection(node) { }
//	};
//	struct Node
//	{
//		T data;
//		unsigned index;
//
//		std::vector< Edge > connections;
//
//		Node(T val, unsigned i) : data(val), index(i) {}
//	};
//	~Graph()
//	{
//		// make sure to delete all nodes added to the graph
//		for (auto iter = m_nodes.begin(); iter != m_nodes.end(); iter++)
//			delete (*iter);
//		m_nodes.clear();
//	}
//	Node *AddNode(int value)
//	{
//		m_nodes.push_back(new Node(value));
//		return m_nodes.back();
//	}
//	void AddConnection(Node *n1, Node *n2)
//	{
//		n1->connections.push_back(Edge(n2));
//		n2->connections.push_back(Edge(n1));
//	}
//private:
//	std::vector< Node * > m_nodes;
//};
//
//inline void printDFS(Graph::Node *startNode)
//{
//	std::list<Graph::Node *> frontier; // open
//	std::set <Graph::Node *> explored; // closed
//
//	frontier.push_front(startNode); // Put node on list (frontier)
//	explored.insert(startNode);
//	while (!frontier.empty()) // While stack is not empty
//	{
//		auto current = frontier.front(); // set current variable to top of the stack (startNode in this case)
//		std::cout << (char)current->value << " "; // Print top node value
//		frontier.pop_front(); // pop startNode from the stack
//		explored.insert(current); // push startNode to set
//
//		for each(Graph::Edge e in current->connections) //for each neighbor, push neighbor to frontier
//		{
//			if (!explored.count(e.connection) ) // if neighbor hasn't been explored
//			{
//				frontier.push_front(e.connection); // push neighbor to frontier
//				explored.insert(e.connection);
//			}
//		}
//	}
//}
//
//inline void printBFS(Graph::Node *startNode)
//{
//	std::queue<Graph::Node *> frontier; // open
//	std::set <Graph::Node *> explored; // closed
//
//	frontier.push(startNode); // 
//	explored.insert(startNode);
//	while (!frontier.empty()) // 
//	{
//		auto current = frontier.front(); // 
//		std::cout << (char)current->value << " "; // 
//		frontier.pop(); // 
//
//		for each(Graph::Edge e in current->connections) //
//		{
//			if (!explored.count(e.connection)) // 
//			{
//				frontier.push(e.connection); // 
//				explored.insert(e.connection);
//			}
//		}
//	}
//}
//
////typedef bool(*CompFunc)(const Graph::Node  *, const Graph::Node  *);
////
////inline bool CompareDFS(const Graph::Node  *a, const Graph::Node *b)
////{
////	return a->dos > b->dos;
////}
////
////inline bool CompareBFS(const Graph::Node *a, const Graph::Node *b)
////{
////	return a->dos < b->dos;
////}
////
////
////inline void PrintByComparison(Graph::Node *startNode, Graph::Node *goalNode, CompFunc comp)
////{
////	std::list <Graph::Node *> frontier;  // Open List
////	std::set  <Graph::Node *> explored;  // Closed List
////
////
////	// Push our starting node into the frontier
////	frontier.push_back(startNode);
////	explored.insert(startNode);
////	// set it's book-keeping data to help us sort the frontier
////	startNode->dos = 0;
////
////	while (!frontier.empty()) // Nodes left to process
////	{
////		frontier.sort(comp);  // order the frontier according to our priorities
////							  // This is a 'priority queue'
////
////		// Process the current node
////		auto current = frontier.front();
////		std::cout << (char)current->value << " ";
////		frontier.pop_front();
////
////		// Add all neighbors to the frontier!
////		for each(Graph::Edge e in current->connections)
////		{
////			if (!explored.count(e.connection)) // add a new node if it isn't explored
////			{
////				e.connection->dos = current->dos + 1;
////				frontier.push_back(e.connection);
////				explored.insert(e.connection);
////			}
////			// If it's already in the frontier, but our new book-keeping data is better
////			// just update the book-keeping data
////			else if (explored.count(e.connection) &&
////				e.connection->dos > current->dos + 1)
////				e.connection->dos = current->dos + 1;
////		}
////	}
////}
//
//// Generate a grid with the given dimensions, it's off for non-square =/
//inline Graph<Vector2> *makeGrid(Vector2 min, Vector2 max, unsigned rows, unsigned cols)
//{
//	Graph<Vector2> *graph = new Graph<Vector2>();
//	auto &r = *graph;
//
//	float xOffset = (max.x - min.x) / float(rows - 1);
//	float yOffset = (max.y - min.y) / float(rows - 1);
//
//	for (unsigned i = 0; i < rows; ++i)
//		for (unsigned j = 0; j < cols; ++j)
//			r.AddNode(Vector2(xOffset*i + min.x, yOffset*j + min.y));
//
//	for (auto it = r.nodes.begin(); it != r.nodes.end(); ++it)
//	{
//
//		auto a = r.FindNode(Vector2((*it)->data.x + xOffset, (*it)->data.y), distance);
//		if (a != *it) r.AddConnection(*it, a, distance(a->data, (*it)->data));
//
//		a = r.FindNode(Vector2((*it)->data.x - xOffset, (*it)->data.y), distance);
//		if (a != *it) r.AddConnection(*it, a, distance(a->data, (*it)->data));
//
//		a = r.FindNode(Vector2((*it)->data.x, (*it)->data.y + yOffset), distance);
//		if (a != *it) r.AddConnection(*it, a, distance(a->data, (*it)->data));
//
//		a = r.FindNode(Vector2((*it)->data.x, (*it)->data.y - yOffset), distance);
//		if (a != *it) r.AddConnection(*it, a, distance(a->data, (*it)->data));
//	}
//	return graph;
//}

#pragma once

#include <vector>
#include <stack>    // DFS Open List
#include <queue>    // BFS Open List
#include <list>     // Closed List
#include <set>      // Alternative Closed List
#include <iostream>

struct Vector2
{
	float x, y;
	Vector2() {}
	Vector2(float x, float y) :x(x), y(y) {}
};

inline float distance(const Vector2 &a, const Vector2 &b)
{
	return sqrtf((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}


template<typename T>
class Graph
{
public:
	// predefine classes
	struct Node;
	struct Edge
	{
		Node *connection;
		float weight;
		// default constructor
		Edge() : connection(NULL) { }
		// overloaded construct
		Edge(Node *node, float weight) : connection(node), weight(weight) { }
	};
	struct Node
	{
		T data;
		unsigned index;

		std::vector< Edge > connections;

		Node(T val, unsigned i) : data(val), index(i) {}
	};
	~Graph()
	{
		// make sure to delete all nodes added to the graph
		for (auto iter = nodes.begin(); iter != nodes.end(); iter++)
			delete (*iter);
		nodes.clear();
	}
	Node *AddNode(T value)
	{
		nodes.push_back(new Node(value, nodes.size()));
		return nodes.back();
	}
	void AddConnection(Node *n1, Node *n2, float weight = 1)
	{
		n1->connections.push_back(Edge(n2, weight));
		//n2->connections.push_back(Edge(n1, weight));
	}


	std::vector<T>     getData() const
	{
		std::vector<T> data;
		for each(auto node in nodes)
			data.push_back(node->data);

		return data;
	}

	std::vector<float> getMatrix()
	{
		std::vector<float> adj_mat(nodes.size()*nodes.size());

		for each(auto node in nodes)
			for each(auto edge in node->connections)
				adj_mat[node->index * nodes.size() +
				edge.connection->index] = edge.weight;

		return adj_mat;
	}

	typedef float(*FindFunc)(const T &, const T &);

	Node  *FindNode(const T &data, FindFunc finder)
	{
		float md = INFINITY;
		Node *r = nullptr;
		for (auto it = nodes.begin(); it != nodes.end(); it++)  // loop through each node
		{                                                       // using an iterator here
			float d = finder((*it)->data, data);  // evaluate distance
			if (d < md)
			{
				md = d;     // if distance is closer,
				r = (*it); // set the retval to the address of our node.
			}
		}
		return r;
	}

	std::vector< Node *> nodes;
};



// Generate a grid with the given dimensions, it's off for non-square =/
inline Graph<Vector2> *makeGrid(Vector2 min, Vector2 max, unsigned rows, unsigned cols)
{
	Graph<Vector2> *graph = new Graph<Vector2>();
	auto &r = *graph;

	float xOffset = (max.x - min.x) / float(rows - 1);
	float yOffset = (max.y - min.y) / float(rows - 1);

	for (unsigned i = 0; i < rows; ++i)
		for (unsigned j = 0; j < cols; ++j)
			r.AddNode(Vector2(xOffset*i + min.x, yOffset*j + min.y));

	for (auto it = r.nodes.begin(); it != r.nodes.end(); ++it)
	{

		auto a = r.FindNode(Vector2((*it)->data.x + xOffset, (*it)->data.y), distance);
		if (a != *it) r.AddConnection(*it, a, distance(a->data, (*it)->data));

		a = r.FindNode(Vector2((*it)->data.x - xOffset, (*it)->data.y), distance);
		if (a != *it) r.AddConnection(*it, a, distance(a->data, (*it)->data));

		a = r.FindNode(Vector2((*it)->data.x, (*it)->data.y + yOffset), distance);
		if (a != *it) r.AddConnection(*it, a, distance(a->data, (*it)->data));

		a = r.FindNode(Vector2((*it)->data.x, (*it)->data.y - yOffset), distance);
		if (a != *it) r.AddConnection(*it, a, distance(a->data, (*it)->data));
	}
	return graph;
}