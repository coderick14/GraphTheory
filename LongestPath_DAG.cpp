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
    void longest_path();
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
void graph::longest_path()
{
    int i,s,indeg[v],lpt[v],parent[v];  //parent array to backtrace longest path
    list<int> q;
    list<int>::iterator it;
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
        for(it=adj[s].begin();it!=adj[s].end();it++)
        {
            indeg[*it]-=1;
            if(lpt[s]+1>lpt[*it])
                parent[*it]=s;
            lpt[*it]=max(lpt[*it],1+lpt[s]);
            if(indeg[*it]==0)
                q.push_back(*it);
        }
    }
    for(i=0;i<v;i++)
        cout<<"Vertex : "<<i<<" LPT : "<<lpt[i]<<" Parent : "<<parent[i]<<endl;
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
	g.longest_path();
	return 0;
}
