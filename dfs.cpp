//checks back edges or acyclicity
//prints reversed graph
//topological sort or linearization

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
	int *pre;
	int *post;
	void explore(bool[], int i);
public:
	graph(int);
	void addedge(int, int);
	void dfs();
	void transpose();
};


graph::graph(int v)
{
	this->v = v;
	adj = new list<int>[v];
	revadj = new list<int>[v];
	pre = new int[v];
	post = new int[v];
}


void graph::addedge(int a, int b)
{
	adj[a].push_back(b);
}


void graph::explore(bool visited[], int i)
{
	visited[i] = true;
	cout << "Visited node " << i << endl;
	pre[i] = ::count++;
	list<int>::iterator it;
	for (it = adj[i].begin(); it != adj[i].end(); it++)
	{
		if (!visited[*it])
			explore(visited, *it);
	}
	post[i] = ::count++;
	Stack.push(i);

}


void graph::dfs()
{
	bool *visited = new bool[v];
	int flag = 1;
	for (int i = 0; i < v; i++)
		visited[i] = false;
	for (int i = 0; i < v; i++)
	{
		if (!visited[i])
			explore(visited, i);
	}
	for (int i = 0; i < v; i++)
	{
		cout << "Pre :" << i << " = " << pre[i] << endl;
		cout << "Post :" << i << " = " << post[i] << endl;
	}
	list<int>::iterator it;
	for (int i = 0; i < v; i++)
	{
		for (it = adj[i].begin(); it != adj[i].end(); it++)
		{
			if (post[i] < post[*it])
			{
				cout << "There is a back edge from " << i << " to " << *it << endl;
				flag = 0;
			}
		}
	}
	if (flag)
	{
		cout << "The graph is acyclic.\n\nThe topological sorting of the graph is\n";
		while (!Stack.empty())
		{
			cout << Stack.top() << " ";
			Stack.pop();
		}
		cout << endl;
	}

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
	cout << "The reversed graph is " << endl;
	for (i = 0; i < v; i++)
	{
		for (it = revadj[i].begin(); it != revadj[i].end(); it++)
		{
			cout << i << "--->" << *it << endl;
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
	g.transpose();
	system("pause");
}
