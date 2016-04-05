//#include "sfwl.h"
//#include "Graph.h"
//#include <iostream>
//
//int main(int argc, char **argv)
//{
//	Graph *pGraph = new Graph(); // Creates graph
//	Graph::Node *a, *b, *c, *d, *e, *f, *g, *h, *i, *j; // Creates nodes in the graph
//	a = pGraph->AddNode('a'); b = pGraph->AddNode('b'); // Adds nodes a and b
//	c = pGraph->AddNode('c'); d = pGraph->AddNode('d'); // Adds nodes c and d
//	e = pGraph->AddNode('e'); f = pGraph->AddNode('f'); // Adds nodes e and f
//	g = pGraph->AddNode('g'); h = pGraph->AddNode('h'); // Adds nodes g and h
//	i = pGraph->AddNode('i'); j = pGraph->AddNode('j'); // Adds nodes i and j
//	pGraph->AddConnection(a, b); pGraph->AddConnection(a, d); // Adds connections(edges) between nodes a and b, a and d
//	pGraph->AddConnection(a, e); pGraph->AddConnection(b, c); // Adds connections(edges) between nodes a and e, b and c
//	pGraph->AddConnection(d, h); pGraph->AddConnection(e, h); // Adds connections(edges) between nodes d and h, e and h
//	pGraph->AddConnection(e, f); pGraph->AddConnection(f, c); // Adds connections(edges) between nodes e and f, f and c
//	pGraph->AddConnection(f, j); pGraph->AddConnection(g, c); // Adds connections(edges) between nodes f and j, g and c
//	pGraph->AddConnection(g, j); pGraph->AddConnection(i, j); // Adds connections(edges) between nodes g and j, i and j
//	pGraph->AddConnection(i, h); // Adds connections(edges) between nodes i and h
//	printDFS(a); // Executes Depth First Search funcion in Graph.h
//	std::cout << std::endl;
//	printBFS(a); // Executes Breadth First Search function in Graph.h
//	std::cout << std::endl;
//	PrintByComparison(a, CompareDFS);
//	std::cout << std::endl;
//	PrintByComparison(a, CompareBFS);
//	std::cout << std::endl;
//	delete pGraph; // Deletes graph
//	system("pause");
//	return 0;
//};

#include "sfwl.h"
#include <random>
#include <iostream>
#include <cmath>
#include <random>
#include "Graph.h"
#include "Solver.h"

inline void drawSolver(const Solver<Vector2> &s)
{
	for (unsigned i = 0; i < s.size; ++i)
	{
		unsigned color;
		switch (s.meta_data[i].state)
		{
		case Meta::undiscovered: color = BLUE; break;
		case Meta::frontier:     color = CYAN; break;
		case Meta::explored:     color = 0x888888ff; break;
		}

		switch (s.meta_data[i].path)
		{
		case Meta::start:   color = GREEN;   break;
		case Meta::goal:    color = MAGENTA; break;
		case Meta::route:   color = YELLOW;  break;
		}

		sfwl::drawBox(s.node_data[i].x, s.node_data[i].y, 8, color);
	}

}



inline float Heuristic(const Vector2 &a, const Vector2 &b)
{
	return fabsf(a.x - b.x) + fabsf(a.y - b.y);
}

inline bool  Comparison(const Meta &a, const Meta &b)
{
	return a.DOS > b.DOS;
}


int main(int argc, char **argv)
{
	Graph<Vector2> *pGraph = makeGrid({ 0,0 }, { 800,600 }, 32, 32);

	std::vector<Vector2> dat = pGraph->getData();
	std::vector<float> mat = pGraph->getMatrix();

	delete pGraph;

	Solver<Vector2> st(dat.size(), dat, mat, Comparison, Heuristic);


	sfwl::initContext();


	unsigned start = rand() % st.size;
	unsigned goal = rand() % st.size;
	st.doSearch(start, goal);

	bool solved = false;
	float timer = 0;
	//float delay = .01f;
	do
	{
		timer += sfwl::getDeltaTime();

		if (timer > 0.0f)
		{

			if (st.step() && !solved)
			{
				st.getPath();
				solved = true;
				timer = 0;
			}
			else if (!solved)  timer = 0;

			if (timer > 2.1f)
			{
				solved = false;
				timer = 0;
				start = goal;
				goal = rand() % st.size;
				st.doSearch(start, goal);
			}
		}

		drawSolver(st);
	} while (sfwl::stepContext());

	sfwl::termContext();
	return 0;
};