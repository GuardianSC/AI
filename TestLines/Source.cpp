#include "sfwl.h"
#include "Graph.h"
#include <iostream>

int main(int argc, char **argv)
{
	Graph *pGraph = new Graph(); // Creates graph
	Graph::Node *a, *b, *c, *d, *e, *f, *g, *h, *i, *j; // Creates nodes in the graph
	a = pGraph->AddNode('a'); b = pGraph->AddNode('b'); // Adds nodes a and b
	c = pGraph->AddNode('c'); d = pGraph->AddNode('d'); // Adds nodes c and d
	e = pGraph->AddNode('e'); f = pGraph->AddNode('f'); // Adds nodes e and f
	g = pGraph->AddNode('g'); h = pGraph->AddNode('h'); // Adds nodes g and h
	i = pGraph->AddNode('i'); j = pGraph->AddNode('j'); // Adds nodes i and j
	pGraph->AddConnection(a, b); pGraph->AddConnection(a, d); // Adds connections(edges) between nodes a and b, a and d
	pGraph->AddConnection(a, e); pGraph->AddConnection(b, c); // Adds connections(edges) between nodes a and e, b and c
	pGraph->AddConnection(d, h); pGraph->AddConnection(e, h); // Adds connections(edges) between nodes d and h, e and h
	pGraph->AddConnection(e, f); pGraph->AddConnection(f, c); // Adds connections(edges) between nodes e and f, f and c
	pGraph->AddConnection(f, j); pGraph->AddConnection(g, c); // Adds connections(edges) between nodes f and j, g and c
	pGraph->AddConnection(g, j); pGraph->AddConnection(i, j); // Adds connections(edges) between nodes g and j, i and j
	pGraph->AddConnection(i, h); // Adds connections(edges) between nodes i and h
	printDFS(a); // Executes Depth First Search funcion in Graph.h
	std::cout << std::endl;
	printBFS(a); // Executes Breadth First Search function in Graph.h
	std::cout << std::endl;
	PrintByComparison(a, CompareDFS);
	std::cout << std::endl;
	PrintByComparison(a, CompareBFS);
	std::cout << std::endl;
	delete pGraph; // Deletes graph
	system("pause");
	return 0;
};