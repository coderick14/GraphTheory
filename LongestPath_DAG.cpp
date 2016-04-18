#include <iostream>
#include <list>
#include <cmath>
using namespace std;

class graph
{
    int v;
    list<int> *adj;
    list<int> *edge;
    public:
    graph(int,int);
    void addedge(int,int,int);
    void longest_path();
};
graph::graph(int v,int e)
{
    this->v=v;
    adj=new list<int>[v];
    edge=new list<int>[e];
}
void graph::addedge(int a,int b,int w)
{
    adj[a].push_back(b);
    edge[a].push_back(w);
}
void graph::longest_path()
{
    int i,s,indeg[v],lpt[v],parent[v];  //parent array to backtrace longest path
    list<int> q;
    list<int>::iterator it,et;
    for(i=0;i<v;i++)
    {
        indeg[i]=lpt[i]=0;
        parent[i]=-1;
    }    
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
        for(it=adj[s].begin(),et=edge[s].begin();it!=adj[s].end();it++,et++)
        {
            indeg[*it]-=1;
            if(lpt[s]+(*et)>lpt[*it])
                parent[*it]=s;
            lpt[*it]=max(lpt[*it],(*et)+lpt[s]);
            if(indeg[*it]==0)
                q.push_back(*it);
        }
    }
    for(i=0;i<v;i++)
        cout<<"Vertex : "<<i<<" LPT : "<<lpt[i]<<" Parent : "<<parent[i]<<endl;
}
int main()
{
	int i,v,e,m,n,wt;
	cin>>v>>e;
	graph g(v,e);
	for(i=0;i<e;i++)
	{
	    cin>>m>>n>>wt;
	    g.addedge(m,n,wt);
	}
	g.longest_path();
	return 0;
}
