#include<bits/stdc++.h>
using namespace std;

#define     read            freopen("input.txt","r",stdin)
#define     write           freopen("output.txt","w",stdout)
#define     ll              long long int

struct Edge {
    int u, v, weight;
    Edge(int src, int des, int cost)
    {
        u = src;
        v = des;
        weight = cost;
    }
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

struct UnionFindDisjointSet
{
    vector<int> parent, rank;
    UnionFindDisjointSet(int n) {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++) make_set(i);
    }
    void make_set(int v) {
        parent[v] = v;
        rank[v] = 0;
    }
    int find_set(int i) {
        return (parent[i] == i) ? i : (parent[i] = find_set(parent[i]));
    }
    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (rank[a] < rank[b])
                swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }
    }
    bool isSameSet(int i, int j) {
        return find_set(i) == find_set(j);
    }
};

const int MAXN = 1e4 + 7;
const int MAXM = 1e5 + 7;

ll kruskal(vector<Edge> edges)
{
    int totalEdges = edges.size();
    sort(edges.begin(), edges.end());
    ll minCost = 0;
    UnionFindDisjointSet dsu(totalEdges);
    for (Edge e : edges)
    {
        if (!dsu.isSameSet(e.u, e.v))
        {
            minCost += e.weight;
            dsu.union_sets(e.u, e.v);
        }
    }
    return minCost;
}


int main()
{
#ifndef ONLINE_JUDGE
    read;
    write;
#endif
    int N, E;
    cin >> N >> E;
    vector<Edge> edges;
    for(int i = 0;i < E;++i)
    {
        int u, v, weight;
        cin >> u >> v >> weight;
        edges.push_back(Edge(u, v, weight));
    }
    ll minimumCost = kruskal(edges);
    cout << minimumCost << endl;
    return 0;
}

/*
complexity: O(ElogV)
input:
4 5
1 2 7
1 4 6
4 2 9
4 3 8
2 3 6
output:
19
*/