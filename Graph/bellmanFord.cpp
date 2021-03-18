/*
    * Single Source Shortest Path for negative weight edge
    * for complete graph: worst case O(V^3), for others: O(v^2)
    * can deletect negative weight cycle and can print the cycle
    * source: https://cp-algorithms.com/graph/bellman_ford.html
    * source: https://cp-algorithms.com/graph/finding-negative-cycle-in-graph.html
*/

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 107;
const int INF = INT_MAX;

struct Edge
{
    int u, v, cost;
    Edge(int u, int v, int cost)
    {
        this->u = u;
        this->v = v;
        this->cost = cost;
    }
};

vector<Edge> edges;
int dist[MAXN], parent[MAXN];
int N, E;

void init()
{
    for (int i = 0; i < MAXN; i++)
    {
        dist[i] = INF;
        parent[i] = -1;
    }
}

void Bellman_Ford(int src, int target)
{
    dist[src] = 0;
    int x = -1;
    for (int i = 0; i < N; i++)
    {
        x = -1;
        for(Edge e : edges)
        {
            if(dist[e.u] < INF && dist[e.u] + e.cost < dist[e.v])
            {
                dist[e.v] = dist[e.u] + e.cost;
                parent[e.v] = e.u;
                x = e.v;
            }
        }
    }
    if (x == -1) // it means no negative cycle found
    {
        vector<int> path;
        for (int cur = target; cur != -1; cur = parent[cur])
            path.push_back (cur);
        reverse (path.begin(), path.end());
        cout << "Path from " << src << " to " << target << ": ";
        for (int i=0; i<path.size(); ++i)
            cout << path[i] << ' ';
        cout << "\n";
    }
    else
    {
        for (int i = 0; i < N; ++i)
            x = parent[x];
        vector<int> cycle;
        for (int v = x;; v = parent[v]) {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());
        cout << "Negative cycle: ";
        for (int v : cycle)
            cout << v << ' ';
        cout << "\n";
    } 
}

signed main()
{
    init();
    cin >> N >> E;
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }
    Bellman_Ford(1, 8);
}


/*
Input Image: https://media.geeksforgeeks.org/wp-content/uploads/negative_cycle.png

Input:
8 13
1 2 4
1 3 4
3 6 -2
3 5 4
4 1 3
4 3 2
5 4 1
5 7 -2
6 2 3
6 5 -3
7 6 2
7 8 2
8 5 -2

*/



