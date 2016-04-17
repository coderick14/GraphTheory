#include <iostream>
#include <list>
using namespace std;

class graph
{
	int v;
	list<int> *adj;
public:
	graph(int);
	void addedge(int, int);
	void greedyColor();
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
void graph::greedyColor()
{
    int i,j,color[v];
    bool avail[v];                  //checks the colors which have already been assigned to the neighbours of a vertex
    color[0]=0;avail[0]=true;
    for(i=1;i<v;i++)
    {
        color[i]=-1;                //Color not assigned yet
        avail[i]=true;
    }
    list<int>::iterator it;
    for(i=1;i<v;i++)
    {
        for(it=adj[i].begin();it!=adj[i].end();it++)
        {
            if(color[*it]!=-1)
                avail[color[*it]]=false;    
        }
        for(j=0;j<v;j++)
        {
            if(avail[j])
            {
                color[i]=j;         //Assigns the minimum available color to the vertex
                break;
            }
        }
        for(j=0;j<v;j++)
            avail[j]=true;          //resets the value of all available colors to true
    }
    for(int i=0;i<v;i++)
	    cout<<"Vertex "<<i<<" : Color "<<color[i]<<endl;  
        
}
int main()
{
	int v, e, m, n;
	//cout << "Enter no of vertices" << endl;
	cin >> v;
	graph g(v);
	//cout << "Enter no of edges " << endl;
	cin >> e;
	for (int i = 0; i < e; i++)
	{
		//cout << "Enter vertices of edge " << i + 1 << endl;
		cin >> m >> n;
		g.addedge(m, n);
	}
	g.greedyColor();
    return 0;
}
