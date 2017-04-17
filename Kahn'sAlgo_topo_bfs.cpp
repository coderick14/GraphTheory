#include <bits/stdc++.h>
using namespace std;

struct node {
    bool visited;
    vector<int> adj;
};

void topological_sort(vector<node> &graph, int n) {
    int i,j,s,u,v,indeg[n];
    queue<int> q;
    vector<int> topo_order;
    for(i=0;i<n;i++)
        indeg[i]=0;
    for(i=0;i<n;i++) {
        for(j=0; j<graph[i].adj.size(); j++) {
            v = graph[i].adj[j];
            indeg[v]+=1;
         }
    }
    for(i=0;i<n;i++) {
        if(indeg[i]==0)
            q.push(i);
    }
    while(!q.empty()) {
        s=q.front();
        q.pop();
        topo_order.push_back(s);
        for(i=0; i<graph[s].adj.size(); i++) {
            v = graph[s].adj[i];
            indeg[v]-=1;
            if(indeg[v]==0)
                q.push(v);
        }
    }
    if(topo_order.size()!=n)
        cout<<"The given graph is not a dag\n";
    else {
        cout<<"The topological sort is "<<endl;
        for(i=0;i<topo_order.size();i++)
            cout<<topo_order[i]<<" ";
    }
}
int main() {
	int i,n,e,u,v;
	cin>>n>>e;
	vector<node> graph(n);
	for(i=0;i<e;i++) {
	    cin>>u>>v;
	    graph[u].adj.push_back(v);
	}
	topological_sort(graph, n);
	return 0;
}
