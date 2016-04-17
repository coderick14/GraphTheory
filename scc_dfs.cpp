//prints strongly connected components

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
	list<int> *revadj;
	void explore(bool[], int i);
public:
	graph(int);
	void addedge(int, int);
	void dfs();
	void transpose();
	void printscc(bool[], int i);
};


graph::graph(int v)
{
	this->v = v;
	adj = new list<int>[v];
	revadj = new list<int>[v];
}


void graph::addedge(int a, int b)
{
	adj[a].push_back(b);
}


void graph::explore(bool visited[], int i)
{
	visited[i] = true;
	list<int>::iterator it;
	for (it = adj[i].begin(); it != adj[i].end(); it++)
	{
		if (!visited[*it])
			explore(visited, *it);
	}
	Stack.push(i);

}
void graph::printscc(bool visited[], int i)
{
	visited[i] = true;
	cout << i << " ";
	list<int>::iterator it;
	for (it = revadj[i].begin(); it != revadj[i].end(); it++)
	{
		if (!visited[*it])
			printscc(visited, *it);
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
			explore(visited, i);
	}
	this->transpose();
	for (int i = 0; i < v; i++)
		visited[i] = false;
	cout << "The strongly connected components are " << endl;
	while (!Stack.empty())
	{
		int k = Stack.top();
		if (!visited[k])
		{
			printscc(visited, k);
			cout << endl;
		}
		Stack.pop();
		
	}
	cout << endl;
	

}


void graph::transpose()
{
	int i;
	list<int>::iterator it;
	for (i = 0; i < v; i++)
	{
		for (it = adj[i].begin(); it != adj[i].end(); it++)
		{
			revadj[*it].push_back(i);
		}
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
