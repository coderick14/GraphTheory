#include <iostream>
#include <list>
#include <vector>
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
    int i,s,indeg[v];
    list<int> q;
    vector<int> topo_order;
    list<int>::iterator it;
    for(i=0;i<v;i++)
        indeg[i]=0;
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
        topo_order.push_back(s);
        for(it=adj[s].begin();it!=adj[s].end();it++)
        {
            indeg[*it]-=1;
            if(indeg[*it]==0)
                q.push_back(*it);
        }
    }
    if(topo_order.size()!=v)
        cout<<"The given graph is not a dag";
    else
    {
        cout<<"The topological sort is "<<endl;
        for(i=0;i<topo_order.size();i++)
            cout<<topo_order[i]<<" ";
    }
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
