#include <bits/stdc++.h>
#define pp pair<int,ll>
using namespace std;

typedef long long ll;

struct node {
    vector< pp > adj;
    ll dist;
};

class Prioritize {
    public:
    int operator() (pp p1, pp p2) {
        return p1.second < p2.second;
    }
};

void djikstra(vector<node> &graph, priority_queue< pp, vector<pp >, Prioritize > &distance, int s, int n) {
    while(!distance.empty()) {
        int u = distance.top().first;
        distance.pop();
        int size = graph[u].adj.size();
        for(int i=0; i<size; i++) {
            int v = graph[u].adj[i].first;
            int w = graph[u].adj[i].second;
            if(graph[v].dist > graph[u].dist + w)   {
                graph[v].dist = graph[u].dist + w;
                distance.push(make_pair(v,graph[v].dist));
            }
        }
        
    }
    int i = 1;
    while(i<=n) {
        if(i==s){
            i++;
            continue;
        }
            
        if(graph[i].dist == INT_MAX)
            cout<<-1<<" ";
        else
            cout<<graph[i].dist<<" ";
        i++;
    }
}

int main() {
    int i,s,t,n,m,u,v,w;
    cin>>t;
    while(t--) {
        cin>>n>>m;
        vector<node> graph(n+1);
        priority_queue< pp, vector<pp >, Prioritize > distance;
        for(i=0;i<m;i++) {
            cin>>u>>v>>w;
            graph[u].adj.push_back(make_pair(v,w));
            graph[v].adj.push_back(make_pair(u,w));
        }
        cin>>s;
        for(i=1;i<=n;i++)
            graph[i].dist = INT_MAX;
        graph[s].dist = 0;
        distance.push(make_pair(s,0));
        djikstra(graph, distance, s, n);
        cout<<"\n";
        graph.clear();
        distance = priority_queue< pp, vector<pp >, Prioritize >();
    }
    return 0;
}