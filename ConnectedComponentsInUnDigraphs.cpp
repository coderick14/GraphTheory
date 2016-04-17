//printing connected components in undirected graphs

#include <iostream>
#include <list>
#include <stack>
using namespace std;
int count = 1;
stack<int> Stack;

class graph
{
	int v;
	list<int> *adj;
	void explore(bool[], int i);
public:
	graph(int);
	void addedge(int, int);
	void dfs();
};


graph::graph(int v)
{
	this->v = v;
	adj = new list<int>[v];
}


void graph::addedge(int a, int b)
{
	adj[a].push_back(b);
	adj[b].push_back(a);
}


void graph::explore(bool visited[], int i)
{
	visited[i] = true;
	cout << i << " ";
	list<int>::iterator it;
	for (it = adj[i].begin(); it != adj[i].end(); it++)
	{
		if (!visited[*it])
			explore(visited, *it);
	}
	Stack.push(i);

}

void graph::dfs()
{
	bool *visited = new bool[v];
	for (int i = 0; i < v; i++)
		visited[i] = false;
	cout << "The connected components in the undirected graph are " << endl;
	for (int i = 0; i < v; i++)
	{
		if (!visited[i])
			explore(visited, i);
		cout << endl;
	}
}


void main()
{
	int v, e, m, n;
	cout << "Enter no of vertices" << endl;
	cin >> v;
	graph g(v);
	cout << "Enter no of edges " << endl;
	cin >> e;
	for (int i = 0; i < e; i++)
	{
		cout << "Enter vertices of edge " << i + 1 << endl;
		cin >> m >> n;
		g.addedge(m, n);
	}
	g.dfs();
	system("pause");
}
