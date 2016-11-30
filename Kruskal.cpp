#include <bits/stdc++.h>
using namespace std;

struct Edges {
    int u,v,w;
};

bool comp(Edges a, Edges b) {
    return a.w<b.w;
}

void make_set(vector<int> &id, vector<int> &rank, int n) {
    for(int i=1; i<=n; i++) {
        id[i] = i;
        rank[i] = 1;
    }
}

int find_set(vector<int> &id, int p) {
    int root = p;
    //find the root
    while(root != id[root]) {
        root = id[root];
    }
    //perform path compression
    while(p != root) {
        int newp = id[p];
        id[p] = root;
        p = newp;
    }
    return root;
}

void merge_set(vector<int> &id, vector<int> &rank, int x, int y) {
    x = find_set(id, x);
    y = find_set(id, y);
    if(rank[x] > rank[y])
        id[y] = x;
    else
        id[x] = y;
    if(rank[x] == rank[y])
        rank[y] += 1;
}

void kruskal(vector<Edges> &edges, vector<int> &id, vector<int> &rank, int n) {
    make_set(id, rank, n);
    sort(edges.begin(), edges.end(), comp);
    vector<Edges> MST;
    int i=0, cost = 0, edge_count = 0;
    while(edge_count < n-1) {
        int u = edges[i].u, v = edges[i].v;
        if(find_set(id, u) != find_set(id, v)) {
            MST.push_back(edges[i]);
            edge_count++;
            cost += edges[i].w;
            merge_set(id, rank, u, v);
        }
        i++;
    }
    cout<<"The following edges form an MST\n";
    for(i=0;i<n-1;i++)
        cout<<MST[i].u<<" "<<MST[i].v<<" "<<MST[i].w<<endl;
    cout<<"Total edge weight or cost of MST = "<<cost<<endl;
}

int main()  {
    int n,e,s,u,v,w,i;
    cout<<"Enter number of nodes and edges\n";
    cin>>n>>e;
    vector<Edges> edges(e);
    vector<int> id(n+1), rank(n+1);
    cout<<"Enter edges and weights\n";
    for(i=0; i<e; i++)  {
        cin>>edges[i].u>>edges[i].v>>edges[i].w;
    }
    kruskal(edges, id, rank, n);
    return 0;
}
