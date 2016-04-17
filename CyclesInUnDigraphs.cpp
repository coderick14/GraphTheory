//checking acyclicity in undirected graphs
//Needs to be modified

#include <iostream>
#include <list>
#include <stack>
using namespace std;

class graph
{
	int v;
	list<int> *adj;
	void explore(bool[], int, int);
public:
	graph(int);
	void addedge(int, int);
	void dfs();
	int count;
};


graph::graph(int v)
{
	this->v = v;
	adj = new list<int>[v];
	count = 0;
}


void graph::addedge(int a, int b)
{
	adj[a].push_back(b);
	adj[b].push_back(a);
}


void graph::explore(bool visited[], int i, int par)
{
	visited[i] = true;
	list<int>::iterator it;
	for (it = adj[i].begin(); it != adj[i].end(); it++)
	{
		if (!visited[*it])
			explore(visited, *it,i);
		else if (*it != par && par!=-1)
			count++;
	}

}

void graph::dfs()
{
	bool *visited = new bool[v];
	for (int i = 0; i < v; i++)
		visited[i] = false;
	for (int i = 0; i < v; i++)
	{
		if (!visited[i])
			explore(visited, i,-1);
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
	if (g.count)
		cout << "The undirected graph has at least one cycle"<<endl;
	else
		cout << "The undirected graph has no cycles"<<endl
		;
	system("pause");
}
