#include <iostream>
#include <list>
#include <cmath>
using namespace std;

class graph
{
    int v;
    list<int> *adj;
    public:
    graph(int);
    void addedge(int,int);
    void topo_bfs();
};
graph::graph(int v)
{
    this->v=v;
    adj=new list<int>[v];
}
void graph::addedge(int a,int b)
{
    adj[a].push_back(b);
}
void graph::topo_bfs()
{
    int i,s,indeg[v],lpt[v];
    list<int> q;
    list<int>::iterator it;
    for(i=0;i<v;i++)
        indeg[i]=lpt[i]=0;
    for(i=0;i<v;i++)
    {
        for(it=adj[i].begin();it!=adj[i].end();it++)
            indeg[*it]+=1;
    }
    for(i=0;i<v;i++)
    {
        if(indeg[i]==0)
            q.push_back(i);
    }
    while(!q.empty())
    {
        s=q.front();
        q.pop_front();
        for(it=adj[s].begin();it!=adj[s].end();it++)
        {
            indeg[*it]-=1;
            lpt[*it]=max(lpt[*it],1+lpt[s]);
            if(indeg[*it]==0)
                q.push_back(*it);
        }
    }
    for(i=0;i<v;i++)
        cout<<"Vertex : "<<i<<" LPT : "<<lpt[i]<<endl;
}
int main()
{
	int i,v,e,m,n;
	cin>>v>>e;
	graph g(v);
	for(i=0;i<e;i++)
	{
	    cin>>m>>n;
	    g.addedge(m,n);
	}
	g.topo_bfs();
	return 0;
}
